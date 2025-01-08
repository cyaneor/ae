#include <ae/memory_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>
#include <ae/elif.h>

ae_u8_t *
ae_memory_raw_fill8(ae_u8_t *ptr, ae_usize_t len, ae_u8_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t *_p = ptr;
    while (len--)
    {
        *_p++ = value;
    }
    return _p;
}

ae_u16_t *
ae_memory_raw_fill16(ae_u16_t *ptr, ae_usize_t len, ae_u16_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t *_p = ptr;
    while (len--)
    {
        *_p++ = value;
    }
    return _p;
}

ae_u32_t *
ae_memory_raw_fill32(ae_u32_t *ptr, ae_usize_t len, ae_u32_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t *_p = ptr;
    while (len--)
    {
        *_p++ = value;
    }
    return _p;
}

ae_u64_t *
ae_memory_raw_fill64(ae_u64_t *ptr, ae_usize_t len, ae_u64_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t *_p = ptr;
    while (len--)
    {
        *_p++ = value;
    }
    return _p;
}

void *
ae_memory_raw_fill(void *ptr, ae_usize_t len, ae_u8_t value)
{
    if (ae_numeric_has_zero_remainder(len, AE_U64_T_SIZE))
    {
        len /= AE_U64_T_SIZE;
        return ae_memory_raw_fill64(ptr, len, value);
    }
    elif (ae_numeric_has_zero_remainder(len, AE_U32_T_SIZE))
    {
        len /= AE_U32_T_SIZE;
        return ae_memory_raw_fill32(ptr, len, value);
    }
    elif (ae_numeric_has_zero_remainder(len, AE_U16_T_SIZE))
    {
        len /= AE_U16_T_SIZE;
        return ae_memory_raw_fill16(ptr, len, value);
    }
    return ae_memory_raw_fill8(ptr, len, value);
}

ae_u8_t *
ae_memory_raw_find8_val(ae_u8_t *ptr, ae_usize_t len, ae_u8_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t *_p = ptr;
    while (len--)
    {
        if (*_p == value)
        {
            return _p;
        }
        _p++;
    }
    return nullptr;
}

ae_u16_t *
ae_memory_raw_find16_val(ae_u16_t *ptr, ae_usize_t len, ae_u16_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t *_p = ptr;
    while (len--)
    {
        if (*_p == value)
        {
            return _p;
        }
        _p++;
    }
    return nullptr;
}

ae_u32_t *
ae_memory_raw_find32_val(ae_u32_t *ptr, ae_usize_t len, ae_u32_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t *_p = ptr;
    while (len--)
    {
        if (*_p == value)
        {
            return _p;
        }
        _p++;
    }
    return nullptr;
}

ae_u64_t *
ae_memory_raw_find64_val(ae_u64_t *ptr, ae_usize_t len, ae_u64_t value)
{
    AE_RUNTIME_ASSERT(ptr, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t *_p = ptr;
    while (len--)
    {
        if (*_p == value)
        {
            return _p;
        }
        _p++;
    }
    return nullptr;
}

const ae_u8_t *
ae_memory_raw_compare8(const ae_u8_t *lhs,
                       ae_usize_t     lhs_len,
                       const ae_u8_t *rhs,
                       ae_usize_t     rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u8_t *_lhs = lhs;
    const ae_u8_t *_rhs = rhs;

    while (lhs_len-- && rhs_len--)
    {
        if (*_lhs != *_rhs)
        {
            return _lhs;
        }

        _lhs++;
        _rhs++;
    }
    return nullptr;
}

const ae_u16_t *
ae_memory_raw_compare16(const ae_u16_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u16_t *rhs,
                        ae_usize_t      rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u16_t *_lhs = lhs;
    const ae_u16_t *_rhs = rhs;

    while (lhs_len-- && rhs_len--)
    {
        if (*_lhs != *_rhs)
        {
            return _lhs;
        }

        _lhs++;
        _rhs++;
    }
    return nullptr;
}

const ae_u32_t *
ae_memory_raw_compare32(const ae_u32_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u32_t *rhs,
                        ae_usize_t      rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u32_t *_lhs = lhs;
    const ae_u32_t *_rhs = rhs;

    while (lhs_len-- && rhs_len--)
    {
        if (*_lhs != *_rhs)
        {
            return _lhs;
        }

        _lhs++;
        _rhs++;
    }
    return nullptr;
}

const ae_u64_t *
ae_memory_raw_compare64(const ae_u64_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u64_t *rhs,
                        ae_usize_t      rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u64_t *_lhs = lhs;
    const ae_u64_t *_rhs = rhs;

    while (lhs_len-- && rhs_len--)
    {
        if (*_lhs != *_rhs)
        {
            return _lhs;
        }

        _lhs++;
        _rhs++;
    }
    return nullptr;
}

const ae_u8_t *
ae_memory_raw_compare8_rev(const ae_u8_t *lhs,
                           ae_usize_t     lhs_len,
                           const ae_u8_t *rhs,
                           ae_usize_t     rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u8_t *_lhs = lhs + lhs_len;
    const ae_u8_t *_rhs = rhs + rhs_len;

    while (lhs_len-- && rhs_len--)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u16_t *
ae_memory_raw_compare16_rev(const ae_u16_t *lhs,
                            ae_usize_t      lhs_len,
                            const ae_u16_t *rhs,
                            ae_usize_t      rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u16_t *_lhs = lhs + lhs_len;
    const ae_u16_t *_rhs = rhs + rhs_len;

    while (lhs_len-- && rhs_len--)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u32_t *
ae_memory_raw_compare32_rev(const ae_u32_t *lhs,
                            ae_usize_t      lhs_len,
                            const ae_u32_t *rhs,
                            ae_usize_t      rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u32_t *_lhs = lhs + lhs_len;
    const ae_u32_t *_rhs = rhs + rhs_len;

    while (lhs_len-- && rhs_len--)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u64_t *
ae_memory_raw_compare64_rev(const ae_u64_t *lhs,
                            ae_usize_t      lhs_len,
                            const ae_u64_t *rhs,
                            ae_usize_t      rhs_len)
{
    AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u64_t *_lhs = lhs + lhs_len;
    const ae_u64_t *_rhs = rhs + rhs_len;

    while (lhs_len-- && rhs_len--)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

ae_u8_t *
ae_memory_raw_copy8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t       *_dst = dst;
    const ae_u8_t *_src = src;

    while (dst_len-- && src_len--)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

ae_u16_t *
ae_memory_raw_copy16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t       *_dst = dst;
    const ae_u16_t *_src = src;

    while (dst_len-- && src_len--)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

ae_u32_t *
ae_memory_raw_copy32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t       *_dst = dst;
    const ae_u32_t *_src = src;

    while (dst_len-- && src_len--)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

ae_u64_t *
ae_memory_raw_copy64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t       *_dst = dst;
    const ae_u64_t *_src = src;

    while (dst_len-- && src_len--)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

void *
ae_memory_raw_copy(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    if (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U64_T_SIZE))
    {
        dst_len /= AE_U64_T_SIZE;
        src_len /= AE_U64_T_SIZE;

        return ae_memory_raw_copy64(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U32_T_SIZE))
    {
        dst_len /= AE_U32_T_SIZE;
        src_len /= AE_U32_T_SIZE;

        return ae_memory_raw_copy32(dst, dst_len, src, src_len);
    }
    elif (ae_numeric_has_zero_remainder_both(dst_len, src_len, AE_U16_T_SIZE))
    {
        dst_len /= AE_U16_T_SIZE;
        src_len /= AE_U16_T_SIZE;

        return ae_memory_raw_copy16(dst, dst_len, src, src_len);
    }
    return ae_memory_raw_copy8(dst, dst_len, src, src_len);
}

ae_u8_t *
ae_memory_raw_copy8_rev(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u8_t *_src = src + src_len;
    ae_u8_t       *_dst = dst + dst_len;
    ae_u8_t       *_end = dst + (src_len > dst_len ? dst_len : src_len);

    while (dst_len-- && src_len--)
    {
        *--_dst = *--_src;
    }
    return _end;
}

ae_u16_t *
ae_memory_raw_copy16_rev(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u16_t *_src = src + src_len;
    ae_u16_t       *_dst = dst + dst_len;
    ae_u16_t       *_end = dst + (src_len > dst_len ? dst_len : src_len);

    while (dst_len-- && src_len--)
    {
        *--_dst = *--_src;
    }
    return _end;
}

ae_u32_t *
ae_memory_raw_copy32_rev(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u32_t *_src = src + src_len;
    ae_u32_t       *_dst = dst + dst_len;
    ae_u32_t       *_end = dst + (src_len > dst_len ? dst_len : src_len);

    while (dst_len-- && src_len--)
    {
        *--_dst = *--_src;
    }
    return _end;
}

ae_u64_t *
ae_memory_raw_copy64_rev(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    const ae_u64_t *_src = src + src_len;
    ae_u64_t       *_dst = dst + dst_len;
    ae_u64_t       *_end = dst + (src_len > dst_len ? dst_len : src_len);

    while (dst_len-- && src_len--)
    {
        *--_dst = *--_src;
    }
    return _end;
}

ae_u8_t *
ae_memory_raw_move8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    return ae_ptr_range_is_overlapped(dst, dst + dst_len, src, src + src_len)
               ? ae_memory_raw_copy8_rev(dst, dst_len, src, src_len)
               : ae_memory_raw_copy8(dst, dst_len, src, src_len);
}

ae_u16_t *
ae_memory_raw_move16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    return ae_ptr_range_is_overlapped(dst, dst + dst_len, src, src + src_len)
               ? ae_memory_raw_copy16_rev(dst, dst_len, src, src_len)
               : ae_memory_raw_copy16(dst, dst_len, src, src_len);
}

ae_u32_t *
ae_memory_raw_move32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    return ae_ptr_range_is_overlapped(dst, dst + dst_len, src, src + src_len)
               ? ae_memory_raw_copy32_rev(dst, dst_len, src, src_len)
               : ae_memory_raw_copy32(dst, dst_len, src, src_len);
}

ae_u64_t *
ae_memory_raw_move64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    return ae_ptr_range_is_overlapped(dst, dst + dst_len, src, src + src_len)
               ? ae_memory_raw_copy64_rev(dst, dst_len, src, src_len)
               : ae_memory_raw_copy64(dst, dst_len, src, src_len);
}