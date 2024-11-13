#include <ae/memory_range.h>
/* Дополнительные модули */
#include <ae/memory_range_initializer.h>
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

void *
ae_memory_range_get_begin(const void *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    return ae_ptr_cast(ae_memory_range_t, self)->lower;
}

void *
ae_memory_range_get_end(const void *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    return ae_ptr_cast(ae_memory_range_t, self)->upper;
}

bool
ae_memory_range_is_null(const void *self)
{
    ae_memory_range_t _t = ae_memory_range_empty_initializer();
    return ae_memory_range_is_equal(self, &_t);
}

bool
ae_memory_range_is_empty(const void *self)
{
    const void *end = ae_memory_range_get_end(self);
    return ae_memory_range_is_begin_equal_to(self, end);
}

bool
ae_memory_range_is_valid(const void *self)
{
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

    return ae_ptr_is_valid_range(begin, end);
}

bool
ae_memory_range_has_ptr(const void *self, const void *ptr)
{
    ae_runtime_assert(ae_memory_range_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, false);

    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

    return ae_ptr_has_range(begin, end, ptr);
}

ae_ptrdiff_t
ae_memory_range_diff(const void *self)
{
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);
    return ae_ptr_diff(end, begin);
}

ae_usize_t
ae_memory_range_size(const void *self)
{
    ae_runtime_assert(ae_memory_range_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, 0);
    return (ae_usize_t)ae_memory_range_diff(self);
}

bool
ae_memory_range_is_multiple_of_size(const void *self, ae_usize_t element_size)
{
    ae_runtime_assert(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, false);
    const ae_usize_t size = ae_memory_range_size(self);
    return ae_numeric_has_zero_remainder(size, element_size);
}

bool
ae_memory_range_is_aligned(const void *self, ae_usize_t alignment_size)
{
    ae_runtime_assert(alignment_size, AE_RUNTIME_ERROR_ZERO_ALIGNMENT_SIZE, false);
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);
    return ae_ptr_range_is_aligned(begin, end, alignment_size);
}

void
ae_memory_range_set_begin(void *self, void *ptr)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER);
    ae_ptr_cast(ae_memory_range_t, self)->lower = ptr;
}

void
ae_memory_range_set_end(void *self, void *ptr)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER);
    ae_ptr_cast(ae_memory_range_t, self)->upper = ptr;
}

void
ae_memory_range_set(void *self, void *begin, void *end)
{
    ae_memory_range_set_begin(self, begin);
    ae_memory_range_set_end(self, end);
}

void
ae_memory_range_assign(void *self, const void *other)
{
    ae_runtime_try
    {
        void *begin = ae_memory_range_get_begin(other);
        void *end   = ae_memory_range_get_end(other);

        ae_memory_range_set(self, begin, end);
        ae_runtime_try_interrupt();
    }
    ae_runtime_raise();
}

void
ae_memory_range_clear(void *self)
{
    const ae_memory_range_t other = ae_memory_range_empty_initializer();
    ae_memory_range_assign(self, &other);
}

void
ae_memory_range_assign_with_validate(void *self, const void *other)
{
    ae_runtime_assert(ae_memory_range_is_valid(other), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE);
    ae_memory_range_assign(self, other);
}

void
ae_memory_range_set_with_validate(void *self, void *begin, void *end)
{
    const ae_memory_range_t other = ae_memory_range_initializer(begin, end);
    ae_memory_range_assign_with_validate(self, &other);
}

void
ae_memory_range_set_with_size(void *self, void *begin, ae_usize_t size)
{
    ae_runtime_assert(begin, AE_RUNTIME_ERROR_INVALID_ARGUMENT);
    ae_memory_range_set_with_validate(self, begin, ae_ptr_add_offset(begin, size));
}

void
ae_memory_range_set_with_fallback(void *self, void *begin, ae_usize_t size)
{
    begin ? ae_memory_range_set_with_size(self, begin, size) : ae_memory_range_clear(self);
}

void
ae_memory_range_swap(void *self, void *other)
{
    ae_memory_range_t _t = ae_memory_range_empty_initializer();
    ae_runtime_try
    {
        ae_memory_range_assign(&_t, self);
        ae_memory_range_assign(self, other);
        ae_memory_range_assign(other, &_t);

        ae_runtime_try_interrupt();
    }
    ae_runtime_raise();
}

void
ae_memory_range_exchange(void *self, void *other)
{
    ae_runtime_try
    {
        ae_memory_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_interrupt();
    }
    ae_runtime_raise();
}

bool
ae_memory_range_has_range(const void *self, const void *begin, const void *end)
{
    const ae_memory_range_t _t = ae_memory_range_initializer((void *)begin, (void *)end);
    return ae_memory_range_is_valid(&_t) && ae_memory_range_has_ptr(self, begin) &&
           ae_memory_range_has_ptr(self, end);
}

bool
ae_memory_range_has_offset(const void *self, ae_uoffset_t offset)
{
    return offset < ae_memory_range_size(self);
}

void *
ae_memory_range_at_from_begin(const void *self, ae_uoffset_t offset)
{
    ae_runtime_assert(
        ae_memory_range_has_offset(self, offset), AE_RUNTIME_ERROR_OUT_OF_RANGE, nullptr);

    void *begin = ae_memory_range_get_begin(self);
    return ae_ptr_add_offset(begin, offset);
}

void *
ae_memory_range_at_from_end(const void *self, ae_uoffset_t offset)
{
    const ae_usize_t size = ae_memory_range_size(self);
    return ae_memory_range_at_from_begin(self, size - (offset + 1));
}

void *
ae_memory_range_at(const void *self, ae_uoffset_t offset, bool reversed)
{
    return reversed ? ae_memory_range_at_from_end(self, offset)
                    : ae_memory_range_at_from_begin(self, offset);
}

void *
ae_memory_range_front(const void *self)
{
    return ae_memory_range_at(self, 0, false);
}

void *
ae_memory_range_back(const void *self)
{
    return ae_memory_range_at(self, 0, true);
}

bool
ae_memory_range_is_begin_equal_to(const void *self, const void *ptr)
{
    return ae_memory_range_get_begin(self) == ptr;
}

bool
ae_memory_range_is_end_equal_to(const void *self, const void *ptr)
{
    return ae_memory_range_get_end(self) == ptr;
}

bool
ae_memory_range_is_begin_equal(const void *self, const void *other)
{
    return ae_memory_range_is_begin_equal_to(self, ae_memory_range_get_begin(other));
}

bool
ae_memory_range_is_end_equal(const void *self, const void *other)
{
    return ae_memory_range_is_end_equal_to(self, ae_memory_range_get_end(other));
}

bool
ae_memory_range_is_equal(const void *self, const void *other)
{
    return ae_memory_range_is_begin_equal(self, other) && ae_memory_range_is_end_equal(self, other);
}

ae_memory_range_t
ae_memory_range_make_empty()
{
    return (ae_memory_range_t)ae_memory_range_empty_initializer();
}

ae_memory_range_t
ae_memory_range_make(void *begin, void *end)
{
    ae_memory_range_t t = ae_memory_range_initializer(begin, end);
    ae_runtime_assert(ae_memory_range_is_valid(&t),
                      AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE,
                      ae_memory_range_make_empty());
    return t;
}

ae_memory_range_t
ae_memory_range_make_subrange(void *self, void *begin, void *end)
{
    ae_runtime_assert(ae_memory_range_has_range(self, begin, end),
                      AE_RUNTIME_ERROR_OUT_OF_RANGE,
                      ae_memory_range_make_empty());
    return (ae_memory_range_t)ae_memory_range_initializer(begin, end);
}

ae_memory_range_t
ae_memory_range_slice(void *self, ae_uoffset_t index, ae_usize_t size)
{
    ae_runtime_try
    {
        void *begin = ae_memory_range_at(self, index, false);
        void *end   = ae_memory_range_at(self, index + size, false);
        ae_runtime_try_interrupt(ae_memory_range_make_subrange(self, begin, end));
    }
    ae_runtime_raise(ae_memory_range_make_empty());
}

void *
ae_memory_range_insert_value(void *self, ae_uoffset_t offset, ae_u8_t value)
{
    ae_runtime_try
    {
        ae_u8_t *ptr = ae_memory_range_at(self, offset, false);
        *ptr         = value;

        ae_runtime_try_interrupt(ptr);
    }
    ae_runtime_raise(nullptr);
}

void *
ae_memory_range_insert_values(void        *self,
                              ae_uoffset_t offset,
                              ae_usize_t   size,
                              void        *begin,
                              void        *end)
{
    ae_runtime_try
    {
        void *_begin = ae_memory_range_at(self, offset, false);
        void *_end   = ae_memory_range_at(self, offset + size, false);
        ae_runtime_try_interrupt(ae_memory_raw_move(_begin, _end, begin, end));
    }
    ae_runtime_raise(nullptr);
}
