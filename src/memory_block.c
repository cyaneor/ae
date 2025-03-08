#include <ae/memory_block.h>
/* Дополнительные модули */
#include <ae/memory_block_initializer.h>
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/memory_range.h>
#include <ae/runtime_try.h>
#include <ae/ptr_traits.h>
#include <ae/nullptr.h>

ae_usize_t
ae_memory_block_get_element_size(const void *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, 0);
    return ae_ptr_cast(ae_memory_block_t, self)->element_size;
}

bool
ae_memory_block_is_valid(const void *self)
{
    const ae_usize_t element_size = ae_memory_block_get_element_size(self);
    return ae_memory_range_is_multiple_of_size(self, element_size);
}

ae_usize_t
ae_memory_block_size(const void *self)
{
    ae_runtime_assert(ae_memory_block_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK, 0);

    const ae_usize_t size         = ae_memory_range_size(self);
    const ae_usize_t element_size = ae_memory_block_get_element_size(self);

    return size / element_size;
}

bool
ae_memory_block_is_empty(const void *self)
{
    return ae_memory_block_size(self) == 0;
}

void
ae_memory_block_swap(void *self, void *other)
{
    ae_runtime_assert(ae_memory_block_is_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE);

    ae_memory_range_swap(self, other);
}

void
ae_memory_block_exchange(void *self, void *other)
{
    ae_runtime_assert(ae_memory_block_is_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE);
    ae_memory_range_exchange(self, other);
}

bool
ae_memory_block_has_index(const void *self, ae_usize_t index)
{
    const ae_usize_t size = ae_memory_block_size(self);
    return index < size;
}

ae_uoffset_t
ae_memory_block_element_offset(const void *self, ae_usize_t index)
{
    ae_runtime_assert(ae_memory_block_has_index(self, index), AE_RUNTIME_ERROR_INVALID_INDEX, 0);
    const ae_usize_t element_size = ae_memory_block_get_element_size(self);
    return index * element_size;
}

void *
ae_memory_block_at_from_begin(const void *self, ae_usize_t index)
{
    ae_runtime_try
    {
        const ae_uoffset_t offset = ae_memory_block_element_offset(self, index);
        ae_runtime_try_return(ae_memory_range_at(self, offset, false));
    }
    ae_runtime_raise(nullptr);
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
    return ae_memory_block_is_element_size_equal(self, other) &&
           ae_memory_range_is_equal(self, other);
}

ae_memory_block_t
ae_memory_block_make_empty(ae_usize_t element_size)
{
    return (ae_memory_block_t)ae_memory_block_empty_initializer(element_size);
}

ae_memory_block_t
ae_memory_block_make(void *begin, void *end, ae_usize_t element_size)
{
    ae_memory_block_t _t = ae_memory_block_initializer(begin, end, element_size);
    ae_runtime_assert(ae_memory_block_is_valid(&_t),
                      AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK,
                      ae_memory_block_make_empty(element_size));
    return _t;
}

ae_memory_block_t
ae_memory_block_slice(void *self, ae_usize_t index, ae_usize_t length)
{
    const ae_usize_t element_size = ae_memory_block_get_element_size(self);
    ae_runtime_try
    {
        void *begin = ae_memory_block_at(self, index, false);
        void *end   = ae_memory_block_at(self, index + length, false);
        ae_runtime_try_return(
            (ae_memory_block_t)ae_memory_block_initializer(begin, end, element_size));
    }
    ae_runtime_raise(ae_memory_block_make_empty(element_size));
}
