#include <ae/memory_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>
#include <ae/elif.h>

ae_u8_t *
ae_memory_raw_fill_u8(ae_u8_t *begin, const ae_u8_t *end, ae_u8_t value)
{
    const void *_src_end = ae_ptr_add_offset(&value, AE_U8_T_SIZE);
    return ae_memory_raw_fill_repeat(begin, end, &value, _src_end);
}

ae_u16_t *
ae_memory_raw_fill_u16(ae_u16_t *begin, const ae_u16_t *end, ae_u16_t value)
{
    const void *_src_end = ae_ptr_add_offset(&value, AE_U16_T_SIZE);
    return ae_memory_raw_fill_repeat(begin, end, &value, _src_end);
}

ae_u32_t *
ae_memory_raw_fill_u32(ae_u32_t *begin, const ae_u32_t *end, ae_u32_t value)
{
    const void *_src_end = ae_ptr_add_offset(&value, AE_U32_T_SIZE);
    return ae_memory_raw_fill_repeat(begin, end, &value, _src_end);
}

ae_u64_t *
ae_memory_raw_fill_u64(ae_u64_t *begin, const ae_u64_t *end, ae_u64_t value)
{
    const void *_src_end = ae_ptr_add_offset(&value, AE_U64_T_SIZE);
    return ae_memory_raw_fill_repeat(begin, end, &value, _src_end);
}

void *
ae_memory_raw_set(void *begin, const void *end, ae_u8_t value)
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

const ae_u8_t *
ae_memory_raw_compare_u8(const ae_u8_t *lhs,
                         const ae_u8_t *lhs_end,
                         const ae_u8_t *rhs,
                         const ae_u8_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u8_t *_lhs = lhs;
    const ae_u8_t *_rhs = rhs;
    while (_lhs < lhs_end && _rhs < rhs_end)
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
ae_memory_raw_compare_u16(const ae_u16_t *lhs,
                          const ae_u16_t *lhs_end,
                          const ae_u16_t *rhs,
                          const ae_u16_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u16_t *_lhs = lhs;
    const ae_u16_t *_rhs = rhs;
    while (_lhs < lhs_end && _rhs < rhs_end)
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
ae_memory_raw_compare_u32(const ae_u32_t *lhs,
                          const ae_u32_t *lhs_end,
                          const ae_u32_t *rhs,
                          const ae_u32_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u32_t *_lhs = lhs;
    const ae_u32_t *_rhs = rhs;
    while (_lhs < lhs_end && _rhs < rhs_end)
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
ae_memory_raw_compare_u64(const ae_u64_t *lhs,
                          const ae_u64_t *lhs_end,
                          const ae_u64_t *rhs,
                          const ae_u64_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u64_t *_lhs = lhs;
    const ae_u64_t *_rhs = rhs;
    while (_lhs < lhs_end && _rhs < rhs_end)
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
ae_memory_raw_compare_rev_u8(const ae_u8_t *lhs,
                             const ae_u8_t *lhs_end,
                             const ae_u8_t *rhs,
                             const ae_u8_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u8_t *_lhs = lhs_end;
    const ae_u8_t *_rhs = rhs_end;

    while (_lhs > lhs && _rhs > rhs)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u16_t *
ae_memory_raw_compare_rev_u16(const ae_u16_t *lhs,
                              const ae_u16_t *lhs_end,
                              const ae_u16_t *rhs,
                              const ae_u16_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u16_t *_lhs = lhs_end;
    const ae_u16_t *_rhs = rhs_end;

    while (_lhs > lhs && _rhs > rhs)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u32_t *
ae_memory_raw_compare_rev_u32(const ae_u32_t *lhs,
                              const ae_u32_t *lhs_end,
                              const ae_u32_t *rhs,
                              const ae_u32_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u32_t *_lhs = lhs_end;
    const ae_u32_t *_rhs = rhs_end;

    while (_lhs > lhs && _rhs > rhs)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u64_t *
ae_memory_raw_compare_rev_u64(const ae_u64_t *lhs,
                              const ae_u64_t *lhs_end,
                              const ae_u64_t *rhs,
                              const ae_u64_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u64_t *_lhs = lhs_end;
    const ae_u64_t *_rhs = rhs_end;

    while (_lhs > lhs && _rhs > rhs)
    {
        if (*--_lhs != *--_rhs)
        {
            return _lhs;
        }
    }
    return nullptr;
}

ae_u8_t *
ae_memory_raw_copy_u8(ae_u8_t       *dst,
                      const ae_u8_t *dst_end,
                      const ae_u8_t *src,
                      const ae_u8_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    ae_u8_t       *_dst = dst;
    const ae_u8_t *_src = src;

    while (_dst < dst_end && _src < src_end)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

ae_u16_t *
ae_memory_raw_copy_u16(ae_u16_t       *dst,
                       const ae_u16_t *dst_end,
                       const ae_u16_t *src,
                       const ae_u16_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    ae_u16_t       *_dst = dst;
    const ae_u16_t *_src = src;

    while (_dst < dst_end && _src < src_end)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

ae_u32_t *
ae_memory_raw_copy_u32(ae_u32_t       *dst,
                       const ae_u32_t *dst_end,
                       const ae_u32_t *src,
                       const ae_u32_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    ae_u32_t       *_dst = dst;
    const ae_u32_t *_src = src;

    while (_dst < dst_end && _src < src_end)
    {
        *_dst++ = *_src++;
    }
    return _dst;
}

ae_u64_t *
ae_memory_raw_copy_u64(ae_u64_t       *dst,
                       const ae_u64_t *dst_end,
                       const ae_u64_t *src,
                       const ae_u64_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    ae_u64_t       *_dst = dst;
    const ae_u64_t *_src = src;

    while (_dst < dst_end && _src < src_end)
    {
        *_dst++ = *_src++;
    }
    return _dst;
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

ae_u8_t *
ae_memory_raw_copy_rev_u8(const ae_u8_t *dst,
                          ae_u8_t       *dst_end,
                          const ae_u8_t *src,
                          const ae_u8_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u8_t *_src = src_end;
    ae_u8_t       *_dst = dst_end;

    while (_dst > dst && _src > src)
    {
        *--_dst = *--_src;
    }
    return _dst;
}

ae_u16_t *
ae_memory_raw_copy_rev_u16(const ae_u16_t *dst,
                           ae_u16_t       *dst_end,
                           const ae_u16_t *src,
                           const ae_u16_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u16_t *_src = src_end;
    ae_u16_t       *_dst = dst_end;

    while (_dst > dst && _src > src)
    {
        *--_dst = *--_src;
    }
    return _dst;
}

ae_u32_t *
ae_memory_raw_copy_rev_u32(const ae_u32_t *dst,
                           ae_u32_t       *dst_end,
                           const ae_u32_t *src,
                           const ae_u32_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u32_t *_src = src_end;
    ae_u32_t       *_dst = dst_end;

    while (_dst > dst && _src > src)
    {
        *--_dst = *--_src;
    }
    return _dst;
}

ae_u64_t *
ae_memory_raw_copy_rev_u64(const ae_u64_t *dst,
                           ae_u64_t       *dst_end,
                           const ae_u64_t *src,
                           const ae_u64_t *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u64_t *_src = src_end;
    ae_u64_t       *_dst = dst_end;

    while (_dst > dst && _src > src)
    {
        *--_dst = *--_src;
    }
    return _dst;
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

ae_u8_t *
ae_memory_raw_move_u8(ae_u8_t       *dst,
                      const ae_u8_t *dst_end,
                      const ae_u8_t *src,
                      const ae_u8_t *src_end)
{
    if (ae_ptr_range_is_overlapped(dst, src, src_end))
    {
        ae_u8_t *_end = ae_ptr_cast(ae_u8_t, dst_end);
        ae_u8_t *_ptr = ae_memory_raw_copy_rev_u8(dst, _end, src, src_end);
        return _ptr ? _end - (_ptr - dst) : nullptr;
    }
    return ae_memory_raw_copy_u8(dst, dst_end, src, src_end);
}

ae_u16_t *
ae_memory_raw_move_u16(ae_u16_t       *dst,
                       const ae_u16_t *dst_end,
                       const ae_u16_t *src,
                       const ae_u16_t *src_end)
{
    if (ae_ptr_range_is_overlapped(dst, src, src_end))
    {
        ae_u16_t *_end = ae_ptr_cast(ae_u16_t, dst_end);
        ae_u16_t *_ptr = ae_memory_raw_copy_rev_u16(dst, _end, src, src_end);
        return _ptr ? _end - (_ptr - dst) : nullptr;
    }
    return ae_memory_raw_copy_u16(dst, dst_end, src, src_end);
}

ae_u32_t *
ae_memory_raw_move_u32(ae_u32_t       *dst,
                       const ae_u32_t *dst_end,
                       const ae_u32_t *src,
                       const ae_u32_t *src_end)
{
    if (ae_ptr_range_is_overlapped(dst, src, src_end))
    {
        ae_u32_t *_end = ae_ptr_cast(ae_u32_t, dst_end);
        ae_u32_t *_ptr = ae_memory_raw_copy_rev_u32(dst, _end, src, src_end);
        return _ptr ? _end - (_ptr - dst) : nullptr;
    }
    return ae_memory_raw_copy_u32(dst, dst_end, src, src_end);
}

ae_u64_t *
ae_memory_raw_move_u64(ae_u64_t       *dst,
                       const ae_u64_t *dst_end,
                       const ae_u64_t *src,
                       const ae_u64_t *src_end)
{
    if (ae_ptr_range_is_overlapped(dst, src, src_end))
    {
        ae_u64_t *_end = ae_ptr_cast(ae_u64_t, dst_end);
        ae_u64_t *_ptr = ae_memory_raw_copy_rev_u64(dst, _end, src, src_end);
        return _ptr ? _end - (_ptr - dst) : nullptr;
    }
    return ae_memory_raw_copy_u64(dst, dst_end, src, src_end);
}

void *
ae_memory_raw_move(void *dst, const void *dst_end, const void *src, const void *src_end)
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
ae_memory_raw_fill_repeat(void *dst, const void *dst_end, const void *src, const void *src_end)
{
    ae_runtime_try
    {
        do
        {
            dst = ae_memory_raw_move(dst, dst_end, src, src_end);
        } while (dst < dst_end);
        ae_runtime_try_interrupt(dst);
    }
    ae_runtime_raise(nullptr);
}

const ae_u8_t *
ae_memory_raw_find_u8(const ae_u8_t *lhs,
                      const ae_u8_t *lhs_end,
                      const ae_u8_t *rhs,
                      const ae_u8_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u8_t *_lhs = lhs; _lhs < lhs_end; ++_lhs)
    {
        if (!ae_memory_raw_compare_u8(_lhs, lhs_end, rhs, rhs_end))
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u16_t *
ae_memory_raw_find_u16(const ae_u16_t *lhs,
                       const ae_u16_t *lhs_end,
                       const ae_u16_t *rhs,
                       const ae_u16_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u16_t *_lhs = lhs; _lhs < lhs_end; ++_lhs)
    {
        if (!ae_memory_raw_compare_u16(_lhs, lhs_end, rhs, rhs_end))
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u32_t *
ae_memory_raw_find_u32(const ae_u32_t *lhs,
                       const ae_u32_t *lhs_end,
                       const ae_u32_t *rhs,
                       const ae_u32_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u32_t *_lhs = lhs; _lhs < lhs_end; ++_lhs)
    {
        if (!ae_memory_raw_compare_u32(_lhs, lhs_end, rhs, rhs_end))
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u64_t *
ae_memory_raw_find_u64(const ae_u64_t *lhs,
                       const ae_u64_t *lhs_end,
                       const ae_u64_t *rhs,
                       const ae_u64_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u64_t *_lhs = lhs; _lhs < lhs_end; ++_lhs)
    {
        if (!ae_memory_raw_compare_u64(_lhs, lhs_end, rhs, rhs_end))
        {
            return _lhs;
        }
    }
    return nullptr;
}

const ae_u8_t *
ae_memory_raw_find_rev_u8(const ae_u8_t *lhs,
                          const ae_u8_t *lhs_end,
                          const ae_u8_t *rhs,
                          const ae_u8_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u8_t *_lhs_end = lhs_end; _lhs_end > lhs; --_lhs_end)
    {
        if (!ae_memory_raw_compare_rev_u8(lhs, _lhs_end, rhs, rhs_end))
        {
            return _lhs_end - (rhs_end - rhs);
        }
    }
    return nullptr;
}

const ae_u16_t *
ae_memory_raw_find_rev_u16(const ae_u16_t *lhs,
                           const ae_u16_t *lhs_end,
                           const ae_u16_t *rhs,
                           const ae_u16_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u16_t *_lhs_end = lhs_end; _lhs_end > lhs; --_lhs_end)
    {
        if (!ae_memory_raw_compare_rev_u16(lhs, _lhs_end, rhs, rhs_end))
        {
            return _lhs_end - (rhs_end - rhs);
        }
    }
    return nullptr;
}

const ae_u32_t *
ae_memory_raw_find_rev_u32(const ae_u32_t *lhs,
                           const ae_u32_t *lhs_end,
                           const ae_u32_t *rhs,
                           const ae_u32_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u32_t *_lhs_end = lhs_end; _lhs_end > lhs; --_lhs_end)
    {
        if (!ae_memory_raw_compare_rev_u32(lhs, _lhs_end, rhs, rhs_end))
        {
            return _lhs_end - (rhs_end - rhs);
        }
    }
    return nullptr;
}

const ae_u64_t *
ae_memory_raw_find_rev_u64(const ae_u64_t *lhs,
                           const ae_u64_t *lhs_end,
                           const ae_u64_t *rhs,
                           const ae_u64_t *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    for (const ae_u64_t *_lhs_end = lhs_end; _lhs_end > lhs; --_lhs_end)
    {
        if (!ae_memory_raw_compare_rev_u64(lhs, _lhs_end, rhs, rhs_end))
        {
            return _lhs_end - (rhs_end - rhs);
        }
    }
    return nullptr;
}

const ae_u8_t *
ae_memory_raw_find_value_u8(const ae_u8_t *begin, const ae_u8_t *end, ae_u8_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u8_t));
    return ae_memory_raw_find_u8(begin, end, &value, _rhs_end);
}

const ae_u16_t *
ae_memory_raw_find_value_u16(const ae_u16_t *begin, const ae_u16_t *end, ae_u16_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u16_t));
    return ae_memory_raw_find_u16(begin, end, &value, _rhs_end);
}

const ae_u32_t *
ae_memory_raw_find_value_u32(const ae_u32_t *begin, const ae_u32_t *end, ae_u32_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u32_t));
    return ae_memory_raw_find_u32(begin, end, &value, _rhs_end);
}

const ae_u64_t *
ae_memory_raw_find_value_u64(const ae_u64_t *begin, const ae_u64_t *end, ae_u64_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u64_t));
    return ae_memory_raw_find_u64(begin, end, &value, _rhs_end);
}

const ae_u8_t *
ae_memory_raw_find_value_rev_u8(const ae_u8_t *begin, const ae_u8_t *end, ae_u8_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u8_t));
    return ae_memory_raw_find_rev_u8(begin, end, &value, _rhs_end);
}

const ae_u16_t *
ae_memory_raw_find_value_rev_u16(const ae_u16_t *begin, const ae_u16_t *end, ae_u16_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u16_t));
    return ae_memory_raw_find_rev_u16(begin, end, &value, _rhs_end);
}

const ae_u32_t *
ae_memory_raw_find_value_rev_u32(const ae_u32_t *begin, const ae_u32_t *end, ae_u32_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u32_t));
    return ae_memory_raw_find_rev_u32(begin, end, &value, _rhs_end);
}

const ae_u64_t *
ae_memory_raw_find_value_rev_u64(const ae_u64_t *begin, const ae_u64_t *end, ae_u64_t value)
{
    const void *_rhs_end = ae_ptr_add_offset(&value, sizeof(ae_u64_t));
    return ae_memory_raw_find_rev_u64(begin, end, &value, _rhs_end);
}

void
ae_memory_raw_swap_u8(ae_u8_t *lhs, ae_u8_t *rhs)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER);
    ae_memory_raw_swap(*lhs, *rhs);
}

void
ae_memory_raw_swap_u16(ae_u16_t *lhs, ae_u16_t *rhs)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER);
    ae_memory_raw_swap(*lhs, *rhs);
}

void
ae_memory_raw_swap_u32(ae_u32_t *lhs, ae_u32_t *rhs)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER);
    ae_memory_raw_swap(*lhs, *rhs);
}

void
ae_memory_raw_swap_u64(ae_u64_t *lhs, ae_u64_t *rhs)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER);
    ae_memory_raw_swap(*lhs, *rhs);
}