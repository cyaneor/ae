#include <ae/memory_allocator.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/bit_util.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>
#include "ae/memory.h"

ae_memory_allocator_alloc_fn *
ae_memory_allocator_get_alloc_fn(const ae_memory_allocator_t *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    return self->alloc_fn;
}

ae_memory_allocator_dealloc_fn *
ae_memory_allocator_get_dealloc_fn(const ae_memory_allocator_t *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    return self->dealloc_fn;
}

void *
ae_memory_allocator_alloc(const ae_memory_allocator_t *self, ae_usize_t size)
{
    // Проверяем запрашиваемый размер. Если равен 0 выбрасываем исключение.
    ae_runtime_assert(size, AE_RUNTIME_ERROR_ZERO_MEMORY_SIZE, nullptr);

    // Получаем указатель на функцию распределения.
    ae_memory_allocator_alloc_fn *alloc_fn = ae_memory_allocator_get_alloc_fn(self);

    // Проверяем инициализирован ли указатель на функцию распределения памяти.
    ae_runtime_assert(alloc_fn, AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED, nullptr);

    // Запрашиваем выделение памяти размером size у аллокатора
    void *ptr = alloc_fn(size);

    // Проверяем, успешно ли выделена память. Если нет, генерируем ошибку.
    ae_runtime_assert(ptr, AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED, nullptr);

#if AE_OPTION_FILL_ZERO_AFTER_MEMORY_ALLOCATE
    // Если включена опция заполнения нулями после выделения памяти,
    // заполняем выделенную память нулями от указателя ptr до конца выделенной области
    ae_memory_set_zero(ptr, size);
#endif

    // Возвращаем указатель на выделенную память
    return ptr;
}

void
ae_memory_allocator_free(const ae_memory_allocator_t *self, void *ptr)
{
    // Если указатель пустой, выходим без генерации ошибки
    ae_runtime_expect(ptr);

    ae_memory_allocator_dealloc_fn *dealloc_fn = ae_memory_allocator_get_dealloc_fn(self);
    ae_runtime_assert(dealloc_fn, AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED);

    dealloc_fn(ptr);
}

void *
ae_memory_allocator_realloc(const ae_memory_allocator_t *self,
                            void                        *old_ptr,
                            ae_usize_t                   old_size,
                            ae_usize_t                   new_size)
{
    // Проверяем, если old_ptr равен нулю, выделяем новую память
    ae_runtime_expect(old_ptr, ae_memory_allocator_alloc(self, new_size));

    // Если размеры совпадают, возвращаем существующий указатель
    ae_runtime_expect_if(old_size == new_size, old_ptr);

    // Если новый размер равен 0, освобождаем память и возвращаем nullptr
    if (new_size == 0)
    {
        ae_memory_allocator_free(self, old_ptr);
        return nullptr;
    }

    ae_runtime_try
    {
        // Выделяем новую область памяти размером new_size
        void *new_ptr = ae_memory_allocator_alloc(self, new_size);

        // Копируем данные из старой области памяти в новую
        ae_memory_copy_ex(new_ptr, new_size, old_ptr, old_size);

        // Освобождаем старую область памяти
        ae_memory_allocator_free(self, old_ptr);

        // Прерываем работу try блока и возвращаем новый указатель
        ae_runtime_try_interrupt(new_ptr);
    }
    // В случае ошибки повторно выбрасываем исключение
    ae_runtime_raise(nullptr);
}

void *
ae_memory_allocator_align_alloc(const ae_memory_allocator_t *self,
                                ae_usize_t                   size,
                                ae_usize_t                   alignment_size)
{
    // Проверка, является ли alignment_size степенью двойки.
    ae_runtime_assert(ae_bit_is_single(alignment_size), AE_RUNTIME_ERROR_NOT_POWER_OF_TWO, nullptr);

    // Вычисление смещения для выравнивания.
    ae_usize_t alignment_offset = sizeof(void *) + alignment_size - 1;

    ae_runtime_try
    {
        // Выделение памяти с учетом смещения.
        void *unaligned_ptr = ae_memory_allocator_alloc(self, size + alignment_offset);

        // Вычисление выровненного адреса.
        ae_uintptr_t aligned_address = (ae_uintptr_t)unaligned_ptr + alignment_offset;
        aligned_address -= aligned_address % alignment_size;

        // Приведение адреса к типу void*.
        void *aligned_ptr = (void *)aligned_address;

        // Сохранение указателя на невыравненную память перед выровненным указателем.
        ((void **)aligned_ptr)[-1] = unaligned_ptr;

        // Возврат указателя на выровненный адрес.
        ae_runtime_try_interrupt(aligned_ptr);
    }
    ae_runtime_raise(nullptr);
}

void
ae_memory_allocator_align_free(const ae_memory_allocator_t *self, void *ptr)
{
    // Проверка, что указатель не равен nullptr.
    ae_runtime_expect(ptr);

    // Извлечение указателя на невыравненную память.
    void *unaligned_ptr = ((void **)ptr)[-1];

    // Освобождение невыравненной памяти.
    ae_memory_allocator_free(self, unaligned_ptr);
}

void *
ae_memory_allocator_align_realloc(const ae_memory_allocator_t *self,
                                  void                        *old_ptr,
                                  ae_usize_t                   old_size,
                                  ae_usize_t                   new_size,
                                  ae_usize_t                   alignment_size)
{
    // Проверка, является ли alignment_size степенью двойки.
    ae_runtime_assert(ae_bit_is_single(alignment_size), AE_RUNTIME_ERROR_NOT_POWER_OF_TWO, nullptr);

    // Если old_ptr равен нулю, выделяем новую память с выравниванием.
    ae_runtime_expect(old_ptr, ae_memory_allocator_align_alloc(self, new_size, alignment_size));

    // Если размеры совпадают, возвращаем существующий указатель.
    ae_runtime_expect_if(old_size == new_size, old_ptr);

    // Если новый размер равен 0, освобождаем память и возвращаем nullptr.
    if (new_size == 0)
    {
        ae_memory_allocator_align_free(self, old_ptr);
        return nullptr;
    }

    ae_runtime_try
    {
        // Выделяем новую область памяти с учетом выравнивания.
        void *new_ptr = ae_memory_allocator_align_alloc(self, new_size, alignment_size);

        // Копируем данные из старой области памяти в новую
        ae_memory_copy_ex(new_ptr, new_size, old_ptr, old_size);

        // Освобождаем старую область памяти.
        ae_memory_allocator_align_free(self, old_ptr);

        // Прерываем работу try блока и возвращаем новый указатель
        ae_runtime_try_interrupt(new_ptr);
    }

    // В случае ошибки повторно выбрасываем исключение
    ae_runtime_raise(nullptr);
}