#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>
#include <ae/elif.h>

ae_u8_t *
ae_str_raw_fill_u8(ae_u8_t *ptr, ae_usize_t len, ae_u8_t value)
{
    return ae_memory_raw_fill_u8(ptr, ptr + len, value);
}

ae_u16_t *
ae_str_raw_fill_u16(ae_u16_t *ptr, ae_usize_t len, ae_u16_t value)
{
    return ae_memory_raw_fill_u16(ptr, ptr + len, value);
}

ae_u32_t *
ae_str_raw_fill_u32(ae_u32_t *ptr, ae_usize_t len, ae_u32_t value)
{
    return ae_memory_raw_fill_u32(ptr, ptr + len, value);
}

ae_u64_t *
ae_str_raw_fill_u64(ae_u64_t *ptr, ae_usize_t len, ae_u64_t value)
{
    return ae_memory_raw_fill_u64(ptr, ptr + len, value);
}

void *
ae_str_raw_fill(void *ptr, ae_usize_t len, ae_u8_t value)
{
    if (ae_numeric_has_zero_remainder(len, AE_U64_T_SIZE))
    {
        len /= AE_U64_T_SIZE;
        const ae_u64_t _value = ae_numeric_repeat64(value);
        return ae_str_raw_fill_u64(ptr, len, _value);
    }
    elif (ae_numeric_has_zero_remainder(len, AE_U32_T_SIZE))
    {
        len /= AE_U32_T_SIZE;
        const ae_u32_t _value = ae_numeric_repeat32(value);
        return ae_str_raw_fill_u32(ptr, len, _value);
    }
    elif (ae_numeric_has_zero_remainder(len, AE_U16_T_SIZE))
    {
        len /= AE_U16_T_SIZE;
        const ae_u16_t _value = ae_numeric_repeat16(value);
        return ae_str_raw_fill_u16(ptr, len, _value);
    }
    return ae_str_raw_fill_u8(ptr, len, value);
}

const ae_u8_t *
ae_str_raw_find_value_u8(const ae_u8_t *ptr, ae_usize_t len, ae_u8_t value)
{
    return ae_memory_raw_find_value_u8(ptr, ptr + len, value);
}

const ae_u16_t *
ae_str_raw_find_value_u16(const ae_u16_t *ptr, ae_usize_t len, ae_u16_t value)
{
    return ae_memory_raw_find_value_u16(ptr, ptr + len, value);
}

const ae_u32_t *
ae_str_raw_find_value_u32(const ae_u32_t *ptr, ae_usize_t len, ae_u32_t value)
{
    return ae_memory_raw_find_value_u32(ptr, ptr + len, value);
}

const ae_u64_t *
ae_str_raw_find_value_u64(const ae_u64_t *ptr, ae_usize_t len, ae_u64_t value)
{
    return ae_memory_raw_find_value_u64(ptr, ptr + len, value);
}

const ae_u8_t *
ae_str_raw_compare_u8(const ae_u8_t *lhs,
                      ae_usize_t     lhs_len,
                      const ae_u8_t *rhs,
                      ae_usize_t     rhs_len)
{
    return ae_memory_raw_compare_u8(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u16_t *
ae_str_raw_compare_u16(const ae_u16_t *lhs,
                       ae_usize_t      lhs_len,
                       const ae_u16_t *rhs,
                       ae_usize_t      rhs_len)
{
    return ae_memory_raw_compare_u16(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u32_t *
ae_str_raw_compare_u32(const ae_u32_t *lhs,
                       ae_usize_t      lhs_len,
                       const ae_u32_t *rhs,
                       ae_usize_t      rhs_len)
{
    return ae_memory_raw_compare_u32(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u64_t *
ae_str_raw_compare_u64(const ae_u64_t *lhs,
                       ae_usize_t      lhs_len,
                       const ae_u64_t *rhs,
                       ae_usize_t      rhs_len)
{
    return ae_memory_raw_compare_u64(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u8_t *
ae_str_raw_compare_rev_u8(const ae_u8_t *lhs,
                          ae_usize_t     lhs_len,
                          const ae_u8_t *rhs,
                          ae_usize_t     rhs_len)
{
    return ae_memory_raw_compare_rev_u8(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u16_t *
ae_str_raw_compare_rev_u16(const ae_u16_t *lhs,
                           ae_usize_t      lhs_len,
                           const ae_u16_t *rhs,
                           ae_usize_t      rhs_len)
{
    return ae_memory_raw_compare_rev_u16(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u32_t *
ae_str_raw_compare_rev_u32(const ae_u32_t *lhs,
                           ae_usize_t      lhs_len,
                           const ae_u32_t *rhs,
                           ae_usize_t      rhs_len)
{
    return ae_memory_raw_compare_rev_u32(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u64_t *
ae_str_raw_compare_rev_u64(const ae_u64_t *lhs,
                           ae_usize_t      lhs_len,
                           const ae_u64_t *rhs,
                           ae_usize_t      rhs_len)
{
    return ae_memory_raw_compare_rev_u64(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

ae_u8_t *
ae_str_raw_copy_u8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_u8(dst, dst + dst_len, src, src + src_len);
}

ae_u16_t *
ae_str_raw_copy_u16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_u16(dst, dst + dst_len, src, src + src_len);
}

ae_u32_t *
ae_str_raw_copy_u32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_u32(dst, dst + dst_len, src, src + src_len);
}

ae_u64_t *
ae_str_raw_copy_u64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_u64(dst, dst + dst_len, src, src + src_len);
}

void *
ae_str_raw_copy(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    if (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U64_T_SIZE))
    {
        dst_len /= AE_U64_T_SIZE;
        src_len /= AE_U64_T_SIZE;

        return ae_str_raw_copy_u64(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U32_T_SIZE))
    {
        dst_len /= AE_U32_T_SIZE;
        src_len /= AE_U32_T_SIZE;

        return ae_str_raw_copy_u32(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U16_T_SIZE))
    {
        dst_len /= AE_U16_T_SIZE;
        src_len /= AE_U16_T_SIZE;

        return ae_str_raw_copy_u16(dst, dst_len, src, src_len);
    }
    return ae_str_raw_copy_u8(dst, dst_len, src, src_len);
}

ae_u8_t *
ae_str_raw_copy_rev_u8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_rev_u8(dst, dst + dst_len, src, src + src_len);
}

ae_u16_t *
ae_str_raw_copy_rev_u16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_rev_u16(dst, dst + dst_len, src, src + src_len);
}

ae_u32_t *
ae_str_raw_copy_rev_u32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_rev_u32(dst, dst + dst_len, src, src + src_len);
}

ae_u64_t *
ae_str_raw_copy_rev_u64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_copy_rev_u64(dst, dst + dst_len, src, src + src_len);
}

void *
ae_str_raw_copy_rev(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    if (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U64_T_SIZE))
    {
        dst_len /= AE_U64_T_SIZE;
        src_len /= AE_U64_T_SIZE;

        return ae_str_raw_copy_rev_u64(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U32_T_SIZE))
    {
        dst_len /= AE_U32_T_SIZE;
        src_len /= AE_U32_T_SIZE;

        return ae_str_raw_copy_rev_u32(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U16_T_SIZE))
    {
        dst_len /= AE_U16_T_SIZE;
        src_len /= AE_U16_T_SIZE;

        return ae_str_raw_copy_rev_u16(dst, dst_len, src, src_len);
    }
    return ae_str_raw_copy_rev_u8(dst, dst_len, src, src_len);
}

ae_u8_t *
ae_str_raw_move_u8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_move_u8(dst, dst + dst_len, src, src + src_len);
}

ae_u16_t *
ae_str_raw_move_u16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_move_u16(dst, dst + dst_len, src, src + src_len);
}

ae_u32_t *
ae_str_raw_move_u32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_move_u32(dst, dst + dst_len, src, src + src_len);
}

ae_u64_t *
ae_str_raw_move_u64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    return ae_memory_raw_move_u64(dst, dst + dst_len, src, src + src_len);
}

void *
ae_str_raw_move(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    if (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U64_T_SIZE))
    {
        dst_len /= AE_U64_T_SIZE;
        src_len /= AE_U64_T_SIZE;

        return ae_str_raw_move_u64(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U32_T_SIZE))
    {
        dst_len /= AE_U32_T_SIZE;
        src_len /= AE_U32_T_SIZE;

        return ae_str_raw_move_u32(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U16_T_SIZE))
    {
        dst_len /= AE_U16_T_SIZE;
        src_len /= AE_U16_T_SIZE;

        return ae_str_raw_move_u16(dst, dst_len, src, src_len);
    }
    return ae_str_raw_move_u8(dst, dst_len, src, src_len);
}
