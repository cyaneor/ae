#include <ae/memory_block.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/memory_range.h>
#include <ae/runtime_try.h>
#include <ae/ptr_util.h>

ae_usize_t
ae_memory_block_get_element_size(const void *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return ae_ptr_cast(ae_memory_block_t, self)->element_size;
}

ae_usize_t
ae_memory_block_size(const void *self)
{
    ae_runtime_try
    {
        const ae_usize_t element_size = ae_memory_block_get_element_size(self);
        ae_runtime_try_interrupt(ae_memory_range_size(self, element_size));
    }
    ae_runtime_raise(0);
}

bool
ae_memory_block_is_empty(const void *self)
{
    return ae_memory_block_size(self) == 0;
}

bool
ae_memory_block_swap(void *self, void *other)
{
    AE_RUNTIME_ASSERT(ae_memory_block_is_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE,
                      false)

    return ae_memory_range_swap(self, other);
}

bool
ae_memory_block_exchange(void *self, void *other)
{
    AE_RUNTIME_ASSERT(ae_memory_block_is_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE,
                      false)

    return ae_memory_range_exchange(self, other);
}

bool
ae_memory_block_has_index(const void *self, ae_usize_t index)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return index < size;
}

bool
ae_memory_block_has_index_range(const void *self, ae_usize_t start_index, ae_usize_t end_index)
{
    return ae_memory_block_has_index(self, start_index) &&
           ae_memory_block_has_index(self, end_index);
}

ae_usize_t
ae_memory_block_get_offset_from_index(const void *self, ae_usize_t index)
{
    AE_RUNTIME_ASSERT(ae_memory_block_has_index(self, index), AE_RUNTIME_ERROR_OUT_OF_RANGE, 0)

    const ae_usize_t element_size = ae_memory_block_get_element_size(self);
    return index * element_size;
}

void *
ae_memory_block_at_from_begin(const void *self, ae_usize_t index)
{
    const ae_usize_t offset = ae_memory_block_get_offset_from_index(self, index);
    return ae_memory_range_at(self, offset);
}

void *
ae_memory_block_at_from_end(const void *self, ae_usize_t index)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return ae_memory_block_at_from_begin(self, size - (index + 1));
}

void *
ae_memory_block_at(const void *self, ae_usize_t index, bool reversed)
{
    return reversed ? ae_memory_block_at_from_end(self, index)
                    : ae_memory_block_at_from_begin(self, index);
}

void *
ae_memory_block_front(const void *self)
{
    return ae_memory_block_at(self, 0, false);
}

void *
ae_memory_block_back(const void *self)
{
    return ae_memory_block_at(self, 0, true);
}

bool
ae_memory_block_is_element_size_equal_to(const void *self, ae_usize_t element_size)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, false)
    return ae_memory_block_get_element_size(self) == element_size;
}

bool
ae_memory_block_is_element_size_equal(const void *self, const void *other)
{
    const ae_usize_t element_size = ae_memory_block_get_element_size(other);
    return ae_memory_block_is_element_size_equal_to(self, element_size);
}

bool
ae_memory_block_is_equal(const void *self, const void *other)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, false)
    return ae_memory_block_is_element_size_equal(self, other) &&
           ae_memory_range_is_equal(self, other);
}