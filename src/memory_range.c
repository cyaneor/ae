#include <ae/memory_range.h>
/* Дополнительные модули */
#include <ae/memory_range_initializer.h>
#include <ae/runtime_error_code.h>
#include <ae/memory_range_type.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

void *
ae_memory_range_get_begin(const void *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return ae_ptr_cast(ae_memory_range_t, self)->begin;
}

void *
ae_memory_range_get_end(const void *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return ae_ptr_cast(ae_memory_range_t, self)->end;
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
    AE_RUNTIME_EXPECT_IF(ae_memory_range_is_empty(self), true);
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

#if (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_CLOSED)
    return ae_ptr_is_valid_closed_range(begin, end); // [begin, end]
#elif (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_LEFT_OPENED)
    return ae_ptr_is_valid_left_open_range(begin, end); // (begin, end]
#elif (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_RIGHT_OPENED)
    return ae_ptr_is_valid_right_open_range(begin, end); // [begin, end)
#elif (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_OPENED)
    return ae_ptr_is_valid_open_range(begin, end); // (begin, end)
#endif
}

bool
ae_memory_range_has_ptr(const void *self, const void *ptr)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, false);
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);

#if (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_CLOSED)
    return ae_ptr_has_closed_range(begin, end, ptr); // [begin, end]
#elif (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_LEFT_OPENED)
    return ae_ptr_has_left_open_range(begin, end, ptr); // (begin, end]
#elif (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_RIGHT_OPENED)
    return ae_ptr_has_right_open_range(begin, end, ptr); // [begin, end)
#elif (AE_MEMORY_RANGE_TYPE == AE_MEMORY_RANGE_TYPE_OPENED)
    return ae_ptr_has_open_range(begin, end, ptr); // (begin, end)
#endif
}

ae_ptrdiff_t
ae_memory_range_diff(const void *self)
{
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);
    return ae_ptr_diff(end, begin);
}

ae_usize_t
ae_memory_range_total_size(const void *self)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_valid(self), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, 0)
    return (ae_usize_t)ae_memory_range_diff(self);
}

bool
ae_memory_range_is_multiple_of_total_size(const void *self, ae_usize_t element_size)
{
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, false)
    const ae_usize_t total_size = ae_memory_range_total_size(self);
    return ae_numeric_multiple_of(total_size, element_size);
}

bool
ae_memory_range_is_aligned(const void *self, ae_usize_t alignment)
{
    AE_RUNTIME_ASSERT(alignment, AE_RUNTIME_ERROR_ZERO_ALIGNMENT_SIZE, false)
    const void *begin = ae_memory_range_get_begin(self);
    const void *end   = ae_memory_range_get_end(self);
    return ae_ptr_range_is_aligned(begin, end, alignment);
}

ae_usize_t
ae_memory_range_size(const void *self, ae_usize_t element_size)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_multiple_of_total_size(self, element_size),
                      AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE,
                      0)

    const ae_usize_t total_size = ae_memory_range_total_size(self);
    return total_size / element_size;
}

void
ae_memory_range_set_begin(void *self, void *ptr)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)
    ae_ptr_cast(ae_memory_range_t, self)->begin = ptr;
}

void
ae_memory_range_set_end(void *self, void *ptr)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)
    ae_ptr_cast(ae_memory_range_t, self)->end = ptr;
}

bool
ae_memory_range_set(void *self, void *begin, void *end)
{
    ae_runtime_try
    {
        ae_memory_range_set_begin(self, begin);
        ae_memory_range_set_end(self, end);
        ae_runtime_try_interrupt(true);
    }
    ae_runtime_raise(false);
}

bool
ae_memory_range_assign(void *self, const void *other)
{
    ae_runtime_try
    {
        void *begin = ae_memory_range_get_begin(other);
        void *end   = ae_memory_range_get_end(other);
        ae_runtime_try_interrupt(ae_memory_range_set(self, begin, end));
    }
    ae_runtime_raise(false);
}

bool
ae_memory_range_clear(void *self)
{
    const ae_memory_range_t other = ae_memory_range_empty_initializer();
    return ae_memory_range_assign(self, &other);
}

bool
ae_memory_range_assign_with_validate(void *self, const void *other)
{
    AE_RUNTIME_ASSERT(ae_memory_range_is_valid(other), AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE, false)
    return ae_memory_range_assign(self, other);
}

bool
ae_memory_range_set_with_validate(void *self, void *begin, void *end)
{
    const ae_memory_range_t other = ae_memory_range_initializer(begin, end);
    return ae_memory_range_assign_with_validate(self, &other);
}

bool
ae_memory_range_set_with_size(void *self, void *begin, ae_usize_t size_in_bytes)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_INVALID_ARGUMENT, false)
    return ae_memory_range_set_with_validate(self, begin, ae_ptr_add_offset(begin, size_in_bytes));
}

bool
ae_memory_range_set_with_fallback(void *self, void *begin, ae_usize_t size_in_bytes)
{
    return begin ? ae_memory_range_set_with_size(self, begin, size_in_bytes)
                 : ae_memory_range_clear(self);
}

bool
ae_memory_range_swap(void *self, void *other)
{
    ae_memory_range_t _t = ae_memory_range_empty_initializer();
    return ae_memory_range_assign(&_t, self) && ae_memory_range_assign(self, other) &&
           ae_memory_range_assign(other, &_t);
}

bool
ae_memory_range_exchange(void *self, void *other)
{
    return ae_memory_range_clear(self) && ae_memory_range_swap(self, other);
}

bool
ae_memory_range_has_range(const void *self, const void *begin, const void *end)
{
    ae_memory_range_t _t = ae_memory_range_initializer((void *)begin, (void *)end);
    return ae_memory_range_is_valid(&_t) && ae_memory_range_has_ptr(self, begin) &&
           ae_memory_range_has_ptr(self, end);
}

void *
ae_memory_range_at_unsafe(const void *self, ae_usize_t offset)
{
    void *begin = ae_memory_range_get_begin(self);
    return ae_ptr_add_offset(begin, offset);
}

void *
ae_memory_range_at(const void *self, ae_usize_t offset)
{
    void *ptr = ae_memory_range_at_unsafe(self, offset);
    AE_RUNTIME_ASSERT(ae_memory_range_has_ptr(self, ptr), AE_RUNTIME_ERROR_OUT_OF_RANGE, nullptr)
    return ptr;
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