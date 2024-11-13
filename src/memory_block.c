#include <ae/memory_block_downcast.h>
#include <ae/runtime_assert.h>
#include <ae/memory_block.h>
#include <ae/memory_range.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

ae_usize_t
ae_memory_block_element_size(const ae_memory_block_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->element_size;
}

ae_usize_t
ae_memory_block_size(const ae_memory_block_t *self)
{
    ae_runtime_try
    {
        const ae_usize_t element_size = ae_memory_block_element_size(self);
        ae_runtime_try_interrupt(
            ae_memory_range_size(ae_memory_block_downcast(self, const), element_size));
    }
    ae_runtime_rethrow(0);
}

bool
ae_memory_block_empty(const ae_memory_block_t *self)
{
    return ae_memory_block_size(self) == 0;
}

bool
ae_memory_block_element_size_equal_to(const struct ae_memory_block *self, ae_usize_t element_size)
{
    return ae_memory_block_element_size(self) == element_size;
}

bool
ae_memory_block_element_size_equal(const struct ae_memory_block *self,
                                   const struct ae_memory_block *other)
{
    const ae_usize_t element_size = ae_memory_block_element_size(other);
    return ae_memory_block_element_size_equal_to(self, element_size);
}

void
ae_memory_block_swap(struct ae_memory_block *self, struct ae_memory_block *other)
{
    AE_RUNTIME_ASSERT(ae_memory_block_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE)

    ae_memory_range_swap(ae_memory_block_downcast(self), ae_memory_block_downcast(other));
}

void
ae_memory_block_clear(ae_memory_block_t *self)
{
    ae_memory_range_clear(ae_memory_block_downcast(self));
}

void
ae_memory_block_exchange(ae_memory_block_t *self, ae_memory_block_t *other)
{
    AE_RUNTIME_ASSERT(ae_memory_block_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE)

    ae_memory_range_exchange(ae_memory_block_downcast(self), ae_memory_block_downcast(other));
}

void *
ae_memory_block_element_base_address(const struct ae_memory_block *self, const void *ptr)
{
    // Проверяем, что указатель ptr находится в допустимом диапазоне памяти
    AE_RUNTIME_ASSERT(ae_memory_range_contain_ptr(ae_memory_block_downcast(self, const), ptr, true),
                      AE_RUNTIME_ERROR_OUT_OF_RANGE, // Код ошибки, если указатель вне диапазона
                      nullptr)

    // Получаем размер элемента в блоке памяти
    const ae_usize_t element_size = ae_memory_block_element_size(self);

    // Проверяем, что размер элемента не равен нулю
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, nullptr)

    // Получаем указатель на начало блока памяти
    const void *begin = ae_memory_range_cbegin(ae_memory_block_downcast(self, const));

    // Вычисляем смещение указателя ptr относительно начала блока
    const ae_ptrdiff_t offset = ae_ptr_diff(ptr, begin);

    // Вычисляем смещение элемента, округляя вниз до ближайшего элемента
    const ae_usize_t element_offset = (offset / element_size) * element_size;

    // Возвращаем указатель на начало соответствующего элемента
    return ae_ptr_add(begin, element_offset);
}

bool
ae_memory_block_check_index(const ae_memory_block_t *self, ae_usize_t index)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return index < size;
}

ae_usize_t
ae_memory_block_element_offset(const ae_memory_block_t *self, ae_usize_t index)
{
    // Проверяем индекс элемента
    AE_RUNTIME_ASSERT(ae_memory_block_check_index(self, index), AE_RUNTIME_ERROR_OUT_OF_RANGE, 0)

    // Получаем размер элемента в блоке памяти
    const ae_usize_t element_size = ae_memory_block_element_size(self);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, 0)

    return index * element_size;
}

void *
ae_memory_block_at_from_begin(const ae_memory_block_t *self, ae_usize_t index)
{
    ae_runtime_try
    {
        const ae_usize_t position = ae_memory_block_element_offset(self, index);
        ae_runtime_try_interrupt(
            ae_memory_range_at(ae_memory_block_downcast(self, const), position));
    }
    ae_runtime_rethrow(nullptr);
}

void *
ae_memory_block_at_from_end(const ae_memory_block_t *self, ae_usize_t index)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return ae_memory_block_at_from_begin(self, size - (index + 1));
}

void *
ae_memory_block_at(const ae_memory_block_t *self, ae_usize_t index, bool reversed)
{
    return reversed ? ae_memory_block_at_from_end(self, index)
                    : ae_memory_block_at_from_begin(self, index);
}

void *
ae_memory_block_front(const ae_memory_block_t *self)
{
    return ae_memory_block_at(self, 0, false);
}

void *
ae_memory_block_back(const ae_memory_block_t *self)
{
    return ae_memory_block_at(self, 0, true);
}