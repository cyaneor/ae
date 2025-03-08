#include <ae/memory.h>
/* Дополнительные модули */
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_traits.h>

void *
ae_memory_copy(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(void, src, src_len);
    return ae_memory_raw_copy(dst, _dst_end, src, _src_end);
}

void
ae_memory_set_value(void *dst, ae_usize_t len, ae_char_t value)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, len);
    ae_memory_raw_set_value(dst, _dst_end, value);
}

void
ae_memory_set_zero(void *dst, ae_usize_t len)
{
    ae_memory_set_value(dst, len, 0);
}

void *
ae_memory_copy_from_end(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    void       *_dst_end = ae_ptr_add_offset(void, dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(void, src, src_len);
    return ae_memory_raw_copy_from_end(dst, _dst_end, src, _src_end);
}

void *
ae_memory_move(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(void, src, src_len);
    return ae_memory_raw_move(dst, _dst_end, src, _src_end);
}

const void *
ae_memory_compare(const void *lhs, ae_usize_t lhs_len, const void *rhs, ae_usize_t rhs_len)
{
    const void *_lhs_end = ae_ptr_add_offset(void, lhs, lhs_len);
    const void *_rhs_end = ae_ptr_add_offset(void, rhs, rhs_len);
    return ae_memory_raw_compare(lhs, _lhs_end, rhs, _rhs_end);
}

const void *
ae_memory_compare_from_end(const void *lhs, ae_usize_t lhs_len, const void *rhs, ae_usize_t rhs_len)
{
    const void *_lhs_end = ae_ptr_add_offset(void, lhs, lhs_len);
    const void *_rhs_end = ae_ptr_add_offset(void, rhs, rhs_len);
    return ae_memory_raw_compare_from_end(lhs, _lhs_end, rhs, _rhs_end);
}

const void *
ae_memory_find(const void *lhs, ae_usize_t lhs_len, const void *rhs, ae_usize_t rhs_len)
{
    const void *_lhs_end = ae_ptr_add_offset(void, lhs, lhs_len);
    const void *_rhs_end = ae_ptr_add_offset(void, rhs, rhs_len);
    return ae_memory_raw_find(lhs, _lhs_end, rhs, _rhs_end);
}

const void *
ae_memory_find_from_end(const void *lhs, ae_usize_t lhs_len, const void *rhs, ae_usize_t rhs_len)
{
    const void *_lhs_end = ae_ptr_add_offset(void, lhs, lhs_len);
    const void *_rhs_end = ae_ptr_add_offset(void, rhs, rhs_len);
    return ae_memory_raw_find_from_end(lhs, _lhs_end, rhs, _rhs_end);
}

void *
ae_memory_set(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(void, src, src_len);
    return ae_memory_raw_set(dst, _dst_end, src, _src_end);
}

void *
ae_memory_shift_left(void *dst, ae_usize_t len, ae_usize_t shift)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, len);
    return ae_memory_raw_shift_left(dst, _dst_end, shift);
}

void *
ae_memory_shift_right(void *dst, ae_usize_t len, ae_usize_t shift)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, len);
    return ae_memory_raw_shift_right(dst, _dst_end, shift);
}

void *
ae_memory_shift_right_and_fill(void *dst, ae_usize_t len, ae_usize_t shift, ae_char_t value)
{
    const void *_dst_end = ae_ptr_add_offset(void, dst, len);
    return ae_memory_raw_shift_right_and_fill(dst, _dst_end, shift, value);
}