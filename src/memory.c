#include <ae/memory.h>
/* Дополнительные модули */
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>

void *
ae_memory_copy_ex(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    const void *_dst_end = ae_ptr_add_offset(dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(src, src_len);
    return ae_memory_raw_copy(dst, _dst_end, src, _src_end);
}

void *
ae_memory_copy(void *dst, const void *src, ae_usize_t len)
{
    return ae_memory_copy_ex(dst, len, src, len);
}

void *
ae_memory_set(void *dst, ae_usize_t len, ae_u8_t value)
{
    const void *_dst_end = ae_ptr_add_offset(dst, len);
    return ae_memory_raw_set(dst, _dst_end, value);
}

void *
ae_memory_set_zero(void *dst, ae_usize_t len)
{
    return ae_memory_set(dst, len, 0);
}

void *
ae_memory_copy_rev_ex(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    void       *_dst_end = ae_ptr_add_offset(dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(src, src_len);
    return ae_memory_raw_copy_rev(dst, _dst_end, src, _src_end);
}

void *
ae_memory_copy_rev(void *dst, const void *src, ae_usize_t len)
{
    return ae_memory_copy_rev_ex(dst, len, src, len);
}

void *
ae_memory_move_ex(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    const void *_dst_end = ae_ptr_add_offset(dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(src, src_len);
    return ae_memory_raw_move(dst, _dst_end, src, _src_end);
}

void *
ae_memory_move(void *dst, const void *src, ae_usize_t len)
{
    return ae_memory_move_ex(dst, len, src, len);
}

void *
ae_memory_append_ex(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    void *_dst_end = ae_ptr_add_offset(dst, dst_len);
    return ae_memory_move_ex(_dst_end, src_len, src, src_len);
}

void *
ae_memory_fill_repeat(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    const void *_dst_end = ae_ptr_add_offset(dst, dst_len);
    const void *_src_end = ae_ptr_add_offset(src, src_len);
    return ae_memory_raw_fill_repeat(dst, _dst_end, src, _src_end);
}

void *
ae_memory_shift_left_ex(void *dst, const void *dst_end, ae_usize_t shift)
{
    const void *_ptr = ae_ptr_add_offset(dst, shift);
    return ae_memory_raw_move(dst, dst_end, _ptr, dst_end);
}

void *
ae_memory_shift_right_ex(void *dst, const void *dst_end, ae_usize_t shift)
{
    void       *_ptr     = ae_ptr_add_offset(dst, shift);
    const void *_src_end = ae_ptr_sub_offset(dst_end, shift);
    return ae_memory_raw_move(_ptr, dst_end, dst, _src_end);
}

void *
ae_memory_shift_left(void *dst, ae_usize_t len, ae_usize_t shift)
{
    const void *_dst_end = ae_ptr_add_offset(dst, len);
    return ae_memory_shift_left_ex(dst, _dst_end, shift);
}

void *
ae_memory_shift_right(void *dst, ae_usize_t len, ae_usize_t shift)
{
    const void *_dst_end = ae_ptr_add_offset(dst, len);
    return ae_memory_shift_right_ex(dst, _dst_end, shift);
}

void *
ae_memory_shift_right_and_fill_ex(void *dst, const void *dst_end, ae_usize_t shift, ae_u8_t value)
{
    ae_runtime_try
    {
        void *_ptr = ae_memory_shift_right_ex(dst, dst_end, shift);
        ae_memory_set(dst, shift, value);
        ae_runtime_try_interrupt(_ptr);
    }
    ae_runtime_raise(nullptr);
}

void *
ae_memory_shift_right_and_fill(void *dst, ae_usize_t len, ae_usize_t shift, ae_u8_t value)
{
    const void *_dst_end = ae_ptr_add_offset(dst, len);
    return ae_memory_shift_right_and_fill_ex(dst, _dst_end, shift, value);
}