#include <ae/memory_block.h>
/* Дополнительные модули */
#include <ae/runtime_assert.h>
#include <ae/runtime_errors.h>
#include <ae/memory_range.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_cast.h>
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
            ae_memory_range_size(ae_ptr_cast(const ae_memory_range_t, self), element_size));
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

    ae_memory_range_swap(ae_ptr_cast(ae_memory_range_t, self),
                         ae_ptr_cast(ae_memory_range_t, other));
}

void
ae_memory_block_clear(ae_memory_block_t *self)
{
    ae_memory_range_clear(ae_ptr_cast(ae_memory_range_t, self));
}

void
ae_memory_block_exchange(ae_memory_block_t *self, ae_memory_block_t *other)
{
    AE_RUNTIME_ASSERT(ae_memory_block_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE)

    ae_memory_range_exchange(ae_ptr_cast(ae_memory_range_t, self),
                             ae_ptr_cast(ae_memory_range_t, other));
}

void *
ae_memory_block_element_base_address(const struct ae_memory_block *self, const void *ptr)
{
    // Проверяем, что указатель ptr находится в допустимом диапазоне памяти
    AE_RUNTIME_ASSERT(
        ae_memory_range_has_ptr(ae_ptr_cast(const ae_memory_range_t, self), ptr, true),
        AE_RUNTIME_ERROR_OUT_OF_RANGE, // Код ошибки, если указатель вне диапазона
        nullptr)

    // Получаем размер элемента в блоке памяти
    const ae_usize_t element_size = ae_memory_block_element_size(self);

    // Проверяем, что размер элемента не равен нулю
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, nullptr)

    // Получаем указатель на начало блока памяти
    const void *begin = ae_memory_range_begin_const(ae_ptr_cast(const ae_memory_range_t, self));

    // Вычисляем смещение указателя ptr относительно начала блока
    const ae_ptrdiff_t offset = ae_ptr_diff(ptr, begin);

    // Вычисляем смещение элемента, округляя вниз до ближайшего элемента
    const ae_usize_t element_offset = (offset / element_size) * element_size;

    // Возвращаем указатель на начало соответствующего элемента
    return ae_ptr_add(begin, element_offset);
}

bool
ae_memory_block_has_index(const ae_memory_block_t *self, ae_usize_t index, bool inclusive)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return inclusive ? index <= size : index < size;
}

bool
ae_memory_block_has_index_range(const ae_memory_block_t *self,
                                ae_usize_t               start_index,
                                ae_usize_t               end_index,
                                bool                     inclusive)
{
    return ae_memory_block_has_index(self, start_index, inclusive) &&
           ae_memory_block_has_index(self, end_index, inclusive);
}

ae_usize_t
ae_memory_block_element_offset(const ae_memory_block_t *self, ae_usize_t index)
{
    // Проверяем индекс элемента
    AE_RUNTIME_ASSERT(
        ae_memory_block_has_index(self, index, false), AE_RUNTIME_ERROR_OUT_OF_RANGE, 0)

    // Получаем размер элемента в блоке памяти
    const ae_usize_t element_size = ae_memory_block_element_size(self);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, 0)

    return index * element_size;
}

void *
ae_memory_block_at_from_begin(ae_memory_block_t *self, ae_usize_t index)
{
    ae_runtime_try
    {
        const ae_usize_t offset = ae_memory_block_element_offset(self, index);
        ae_runtime_try_interrupt(ae_memory_range_at(ae_ptr_cast(ae_memory_range_t, self), offset));
    }
    ae_runtime_rethrow(nullptr);
}

const void *
ae_memory_block_at_from_begin_const(const ae_memory_block_t *self, ae_usize_t index)
{
    return ae_memory_block_at_from_begin(ae_ptr_cast(ae_memory_block_t, self), index);
}

void *
ae_memory_block_at_from_end(ae_memory_block_t *self, ae_usize_t index)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return ae_memory_block_at_from_begin(self, size - (index + 1));
}

const void *
ae_memory_block_at_from_end_const(const ae_memory_block_t *self, ae_usize_t index)
{
    return ae_memory_block_at_from_end(ae_ptr_cast(ae_memory_block_t, self), index);
}

void *
ae_memory_block_at(ae_memory_block_t *self, ae_usize_t index, bool reversed)
{
    return reversed ? ae_memory_block_at_from_end(self, index)
                    : ae_memory_block_at_from_begin(self, index);
}

const void *
ae_memory_block_at_const(const ae_memory_block_t *self, ae_usize_t index, bool reversed)
{
    return ae_memory_block_at(ae_ptr_cast(ae_memory_block_t, self), index, reversed);
}

void *
ae_memory_block_front(ae_memory_block_t *self)
{
    return ae_memory_block_at(self, 0, false);
}

const void *
ae_memory_block_front_const(const ae_memory_block_t *self)
{
    return ae_memory_block_front(ae_ptr_cast(ae_memory_block_t, self));
}

void *
ae_memory_block_back(ae_memory_block_t *self)
{
    return ae_memory_block_at(self, 0, true);
}

const void *
ae_memory_block_back_const(const ae_memory_block_t *self)
{
    return ae_memory_block_back(ae_ptr_cast(ae_memory_block_t, self));
}

bool
ae_memory_block_equal(const ae_memory_block_t *self, const ae_memory_block_t *other)
{
    return ae_memory_block_element_size_equal(self, other) &&
           ae_memory_range_equal(ae_ptr_cast(const ae_memory_range_t, self),
                                 ae_ptr_cast(const ae_memory_range_t, other));
}
