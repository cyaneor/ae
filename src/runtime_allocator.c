#include <ae/memory_allocator_initializer.h>
#include <ae/runtime_allocator.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>
#include <ae/bit_util.h>
#include <ae/nullptr.h>

/**
 * @brief Определяет локальный для потока распределитель памяти времени выполнения,
 *        при необходимости инициализируемый с помощью функций стандартной библиотеки.
 *
 * Этот код определяет глобальную переменную `m_runtime_allocator`
 * как локальный для потока экземпляр структуры `ae_memory_allocator`.
 *
 * Инициализация распределителя зависит от того,
 * определена ли `AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB`:
 *
 * - Если `AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB` определена,
 *   распределитель инициализируется с использованием функции `malloc`
 *   стандартной библиотеки для выделения памяти и `free` для освобождения памяти.
 *
 * - Если `AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB` не определена,
 *   функции выделения и освобождения памяти инициализируются значением `nullptr`.
 *
 * Это обеспечивает гибкость в конфигурации распределителя времени выполнения,
 * поддерживая как стандартные, так и пользовательские стратегии управления памятью.
 *
 * @note Распределитель помечен как `THREAD_LOCAL`, это означает,
 *        что каждый поток будет иметь свой собственный экземпляр
 *        `m_runtime_allocator`.
 */
#ifdef AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB
#    include <stdlib.h>

AE_ATTRIBUTE(THREAD_LOCAL)
ae_memory_allocator_t m_runtime_allocator = ae_memory_allocator_initializer(malloc, free);
#else
AE_ATTRIBUTE(THREAD_LOCAL)
ae_memory_allocator_t m_runtime_allocator = ae_memory_allocator_initializer(nullptr, nullptr);
#endif // AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB

ae_memory_allocator_t *
ae_runtime_allocator()
{
    return &m_runtime_allocator;
}

void *
ae_runtime_allocator_alloc(ae_usize_t size_in_bytes)
{
    // Проверяем запрашиваемый размер. Если равен 0 выбрасываем исключение.
    AE_RUNTIME_ASSERT(size_in_bytes, AE_RUNTIME_ERROR_ZERO_MEMORY_SIZE, nullptr)

    // Получаем указатель на текущий аллокатор памяти
    ae_memory_allocator_t *self = ae_runtime_allocator();

    // Запрашиваем выделение памяти размером size_in_bytes у аллокатора
    void *ptr = ae_memory_allocator_alloc(self, size_in_bytes);

    // Проверяем, успешно ли выделена память. Если нет, генерируем ошибку.
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED, nullptr)

#if AE_OPTION_FILL_ZERO_AFTER_MEMORY_ALLOCATE
    // Если включена опция заполнения нулями после выделения памяти,
    // заполняем выделенную память нулями от указателя ptr до конца выделенной области
    ae_memory_raw_fill_zero(ptr, ae_ptr_add(ptr, size_in_bytes));
#endif

    // Возвращаем указатель на выделенную память
    return ptr;
}

void
ae_runtime_allocator_free(void *ptr)
{
    ae_memory_allocator_t *self = ae_runtime_allocator();
    ae_memory_allocator_free(self, ptr);
}

void *
ae_runtime_allocator_realloc(void      *old_ptr,
                             ae_usize_t old_size_in_bytes,
                             ae_usize_t new_size_in_bytes)
{
    // Проверяем, если old_ptr равен нулю, выделяем новую память
    AE_RUNTIME_EXPECT(old_ptr, ae_runtime_allocator_alloc(new_size_in_bytes))

    // Если размеры совпадают, возвращаем существующий указатель
    AE_RUNTIME_EXPECT_IF(old_size_in_bytes == new_size_in_bytes, old_ptr)

    // Если новый размер равен 0, освобождаем память и возвращаем nullptr
    if (new_size_in_bytes == 0)
    {
        ae_runtime_allocator_free(old_ptr);
        return nullptr;
    }

    ae_runtime_try
    {
        // Выделяем новую область памяти размером new_size_in_bytes
        void *new_ptr = ae_runtime_allocator_alloc(new_size_in_bytes);

        // Копируем данные из старой области памяти в новую
        ae_memory_raw_copy(new_ptr,
                           ae_ptr_add(new_ptr, new_size_in_bytes),
                           old_ptr,
                           ae_ptr_add(old_ptr, old_size_in_bytes));

        // Освобождаем старую область памяти
        ae_runtime_allocator_free(old_ptr);

        // Прерываем работу try блока и возвращаем новый указатель
        ae_runtime_try_interrupt(new_ptr);
    }
    // В случае ошибки повторно выбрасываем исключение
    ae_runtime_rethrow(nullptr);
}

void *
ae_runtime_allocator_align_alloc(ae_usize_t size_in_bytes, ae_usize_t alignment_size)
{
    // Проверка, является ли alignment_size степенью двойки.
    AE_RUNTIME_ASSERT(ae_bit_is_single(alignment_size), AE_RUNTIME_ERROR_NOT_POWER_OF_TWO, nullptr)

    // Вычисление смещения для выравнивания.
    ae_usize_t alignment_offset = sizeof(void *) + alignment_size - 1;

    ae_runtime_try
    {
        // Выделение памяти с учетом смещения.
        void *unaligned_ptr = ae_runtime_allocator_alloc(size_in_bytes + alignment_offset);

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
    ae_runtime_rethrow(nullptr);
}

void
ae_runtime_allocator_align_free(void *ptr)
{
    // Проверка, что указатель не равен nullptr.
    AE_RUNTIME_EXPECT(ptr)

    // Извлечение указателя на невыравненную память.
    void *unaligned_ptr = ((void **)ptr)[-1];

    // Освобождение невыравненной памяти.
    ae_runtime_allocator_free(unaligned_ptr);
}

void *
ae_runtime_allocator_align_realloc(void      *old_ptr,
                                   ae_usize_t old_size_in_bytes,
                                   ae_usize_t new_size_in_bytes,
                                   ae_usize_t alignment_size)
{
    // Проверка, является ли alignment_size степенью двойки.
    AE_RUNTIME_ASSERT(ae_bit_is_single(alignment_size), AE_RUNTIME_ERROR_NOT_POWER_OF_TWO, nullptr)

    // Если old_ptr равен нулю, выделяем новую память с выравниванием.
    AE_RUNTIME_EXPECT(old_ptr, ae_runtime_allocator_align_alloc(new_size_in_bytes, alignment_size))

    // Если размеры совпадают, возвращаем существующий указатель.
    AE_RUNTIME_EXPECT_IF(old_size_in_bytes == new_size_in_bytes, old_ptr)

    // Если новый размер равен 0, освобождаем память и возвращаем nullptr.
    if (new_size_in_bytes == 0)
    {
        ae_runtime_allocator_align_free(old_ptr);
        return nullptr;
    }

    ae_runtime_try
    {
        // Выделяем новую область памяти с учетом выравнивания.
        void *new_ptr = ae_runtime_allocator_align_alloc(new_size_in_bytes, alignment_size);

        // Копируем данные из старой области памяти в новую.
        ae_memory_raw_copy(new_ptr,
                           ae_ptr_add(new_ptr, new_size_in_bytes),
                           old_ptr,
                           ae_ptr_add(old_ptr, old_size_in_bytes));

        // Освобождаем старую область памяти.
        ae_runtime_allocator_align_free(old_ptr);

        // Прерываем работу try блока и возвращаем новый указатель
        ae_runtime_try_interrupt(new_ptr);
    }

    // В случае ошибки повторно выбрасываем исключение
    ae_runtime_rethrow(nullptr);
}