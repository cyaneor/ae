#include <ae/memory.h>
/* Дополнительные модули */
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>
#include <ae/elif.h>

void *
ae_memory_raw_fill(void *begin, const void *end, ae_u8_t value)
{
    if (ae_ptr_range_is_aligned(begin, end, AE_U64_T_SIZE))
    {
        const ae_u64_t _value = ae_numeric_repeat64(value);
        return ae_memory_raw_fill_u64(begin, end, _value);
    }
    elif (ae_ptr_range_is_aligned(begin, end, AE_U32_T_SIZE))
    {
        const ae_u32_t _value = ae_numeric_repeat32(value);
        return ae_memory_raw_fill_u32(begin, end, _value);
    }
    elif (ae_ptr_range_is_aligned(begin, end, AE_U16_T_SIZE))
    {
        const ae_u16_t _value = ae_numeric_repeat16(value);
        return ae_memory_raw_fill_u16(begin, end, _value);
    }
    return ae_memory_raw_fill_u8(begin, end, value);
}

void *
ae_memory_raw_copy_rev(const void *dst, void *dst_end, const void *src, const void *src_end)
{
    if (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_copy_rev_u64(dst, dst_end, src, src_end);
    }
    elif (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_copy_rev_u32(dst, dst_end, src, src_end);
    }
    elif (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_copy_rev_u16(dst, dst_end, src, src_end);
    }
    return ae_memory_raw_copy_rev_u8(dst, dst_end, src, src_end);
}

void *
ae_memory_raw_copy(void *dst, const void *dst_end, const void *src, const void *src_end)
{
    if (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_copy_u64(dst, dst_end, src, src_end);
    }
    elif (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_copy_u32(dst, dst_end, src, src_end);
    }
    elif (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_copy_u16(dst, dst_end, src, src_end);
    }
    return ae_memory_raw_copy_u8(dst, dst_end, src, src_end);
}

void *
ae_memory_raw_move(void *dst, void *dst_end, const void *src, const void *src_end)
{
    if (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_move_u64(dst, dst_end, src, src_end);
    }
    elif (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_move_u32(dst, dst_end, src, src_end);
    }
    elif (ae_ptr_range_is_aligned_both(dst, dst_end, src, src_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_move_u16(dst, dst_end, src, src_end);
    }
    return ae_memory_raw_move_u8(dst, dst_end, src, src_end);
}

void *
ae_memory_raw_shift_left(void *dst, void *dst_end, ae_usize_t shift)
{
    void *_ptr = ae_ptr_add_offset(dst, shift);
    return ae_memory_raw_move(dst, dst_end, _ptr, dst_end);
}

void *
ae_memory_raw_shift_right(void *dst, void *dst_end, ae_usize_t shift)
{
    void *_ptr = ae_ptr_add_offset(dst, shift);
    void *_end = ae_ptr_sub_offset(dst_end, shift);
    return ae_memory_raw_move(_ptr, dst_end, dst, _end);
}