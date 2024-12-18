#include <ae/memory_range.h>
/* Дополнительные модули */
#include <ae/memory_range_initializer.h>
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_try.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

void *
ae_memory_range_get_begin(const ae_memory_range_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return self->begin;
}

void *
ae_memory_range_get_end(const ae_memory_range_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return self->end;
}

bool
ae_memory_range_is_empty(const ae_memory_range_t *self)
{
    const void *end = ae_memory_range_get_end(self);
    return ae_memory_range_is_begin_equal_to(self, end);
}

ae_ptrdiff_t
ae_memory_range_diff(const ae_memory_range_t *self)
{
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);
    return ae_ptr_diff(end, begin);
}

bool
ae_memory_range_is_valid(const ae_memory_range_t *self)
{
    // Если диапазон пуст, это считается валидным состоянием
    AE_RUNTIME_EXPECT_IF(ae_memory_range_is_empty(self), true)

    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

    return ae_ptr_is_valid_range(begin, end);
}

bool
ae_memory_range_has_ptr(const ae_memory_range_t *self, const void *ptr, bool inclusive)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, false)

    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

    return inclusive ? (ptr >= begin) && (ptr <= end) : (ptr >= begin) && (ptr < end);
}

ae_usize_t
ae_memory_range_total_size(const ae_memory_range_t *self)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, 0)
    return (ae_usize_t)ae_memory_range_diff(self);
}

bool
ae_memory_range_is_multiple_of_total_size(const ae_memory_range_t *self, ae_usize_t element_size)
{
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_DIVISION_BY_ZERO, false)
    const ae_usize_t total_size = ae_memory_range_total_size(self);
    return ae_numeric_multiple_of(total_size, element_size);
}

bool
ae_memory_range_is_aligned(const ae_memory_range_t *self, ae_usize_t alignment_size)
{
    AE_RUNTIME_ASSERT(alignment_size, AE_RUNTIME_ERROR_DIVISION_BY_ZERO, false)

    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

    return ae_ptr_range_is_aligned(begin, end, alignment_size);
}

ae_usize_t
ae_memory_range_size(const ae_memory_range_t *self, ae_usize_t element_size)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_multiple_of_total_size(self, element_size),
                      AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE,
                      0)

    const ae_usize_t total_size = ae_memory_range_total_size(self);
    return total_size / element_size;
}

void
ae_memory_range_set(ae_memory_range_t *self, void *begin, void *end)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)
    self->begin = begin;
    self->end   = end;
}

void
ae_memory_range_assign(ae_memory_range_t *self, ae_memory_range_t *other)
{
    void *begin = ae_memory_range_get_begin(other);
    void *end   = ae_memory_range_get_end(other);
    ae_memory_range_set(self, begin, end);
}

void
ae_memory_range_assign_with_validate(ae_memory_range_t *self, ae_memory_range_t *other)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_valid(other), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE)
    ae_memory_range_assign(self, other);
}

void
ae_memory_range_set_with_validate(ae_memory_range_t *self, void *begin, void *end)
{
    ae_memory_range_t other = ae_memory_range_initializer(begin, end);
    ae_memory_range_assign_with_validate(self, &other);
}

void
ae_memory_range_set_with_size(ae_memory_range_t *self, void *begin, ae_usize_t size_in_bytes)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_INVALID_ARGUMENT)
    ae_memory_range_set_with_validate(self, begin, ae_ptr_add_offset(begin, size_in_bytes));
}

void
ae_memory_range_set_with_fallback(ae_memory_range_t *self, void *begin, ae_usize_t size_in_bytes)
{
    begin ? ae_memory_range_set_with_size(self, begin, size_in_bytes) : ae_memory_range_clear(self);
}

void
ae_memory_range_clear(ae_memory_range_t *self)
{
    ae_memory_range_set(self, nullptr, nullptr);
}

void
ae_memory_range_swap(ae_memory_range_t *self, ae_memory_range_t *other)
{
    ae_memory_range_t _t = ae_memory_range_empty_initializer();
    ae_runtime_try
    {
        ae_memory_range_assign(&_t, self);
        ae_memory_range_assign(self, other);
        ae_memory_range_assign(other, &_t);

        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

void
ae_memory_range_exchange(ae_memory_range_t *self, ae_memory_range_t *other)
{
    ae_runtime_try
    {
        ae_memory_range_clear(self);
        ae_memory_range_swap(self, other);

        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

bool
ae_memory_range_has_range(const ae_memory_range_t *self,
                          const void              *begin,
                          const void              *end,
                          bool                     inclusive)
{
    return ae_memory_range_has_ptr(self, begin, inclusive) &&
           ae_memory_range_has_ptr(self, end, inclusive);
}

void *
ae_memory_range_at_unsafe(ae_memory_range_t *self, ae_usize_t offset)
{
    void *begin = ae_memory_range_get_begin(self);
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN, nullptr)
    return ae_ptr_add_offset(begin, offset);
}

void *
ae_memory_range_at(ae_memory_range_t *self, ae_usize_t offset)
{
    void *ptr = ae_memory_range_at_unsafe(self, offset);
    AE_RUNTIME_ASSERT(
        ae_memory_range_has_ptr(self, ptr, false), AE_RUNTIME_ERROR_OUT_OF_RANGE, nullptr)
    return ptr;
}

bool
ae_memory_range_is_begin_equal_to(const ae_memory_range_t *self, const void *ptr)
{
    return ae_memory_range_get_begin(self) == ptr;
}

bool
ae_memory_range_is_end_equal_to(const ae_memory_range_t *self, const void *ptr)
{
    return ae_memory_range_get_end(self) == ptr;
}

bool
ae_memory_range_is_begin_equal(const ae_memory_range_t *self, const ae_memory_range_t *other)
{
    return ae_memory_range_is_begin_equal_to(self, ae_memory_range_get_begin(other));
}

bool
ae_memory_range_is_end_equal(const ae_memory_range_t *self, const ae_memory_range_t *other)
{
    return ae_memory_range_is_end_equal_to(self, ae_memory_range_get_end(other));
}

bool
ae_memory_range_is_equal(const ae_memory_range_t *self, const ae_memory_range_t *other)
{
    return ae_memory_range_is_begin_equal(self, other) && ae_memory_range_is_end_equal(self, other);
}