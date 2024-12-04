#include <ae/memory_raw.h>
/* Дополнительные модули */
#include <ae/runtime_assert.h>
#include <ae/runtime_errors.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

ae_u64_t *
ae_memory_raw_fill64(ae_u64_t *begin, const ae_u64_t *end, ae_u64_t value)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t *_begin = begin;
    while (_begin < end)
    {
        *_begin++ = value;
    }
    return _begin;
}

ae_u32_t *
ae_memory_raw_fill32(ae_u32_t *begin, const ae_u32_t *end, ae_u32_t value)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t *_begin = begin;
    while (_begin < end)
    {
        *_begin++ = value;
    }
    return _begin;
}

ae_u16_t *
ae_memory_raw_fill16(ae_u16_t *begin, const ae_u16_t *end, ae_u16_t value)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t *_begin = begin;
    while (_begin < end)
    {
        *_begin++ = value;
    }
    return _begin;
}

ae_u8_t *
ae_memory_raw_fill8(ae_u8_t *begin, const ae_u8_t *end, ae_u8_t value)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t *_begin = begin;
    while (_begin < end)
    {
        *_begin++ = value;
    }
    return _begin;
}

void *
ae_memory_raw_fill(void *begin, const void *end, ae_u8_t value)
{
    if (ae_ptr_range_align_of(begin, end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_fill64(begin, end, value);
    }
    else if (ae_ptr_range_align_of(begin, end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_fill32(begin, end, value);
    }
    else if (ae_ptr_range_align_of(begin, end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_fill16(begin, end, value);
    }
    return ae_memory_raw_fill8(begin, end, value);
}

void *
ae_memory_raw_fill_zero(void *begin, const void *end)
{
    return ae_memory_raw_fill(begin, end, 0);
}

ae_u64_t *
ae_memory_raw_copy64(ae_u64_t       *dest_begin,
                     const ae_u64_t *dest_end,
                     const ae_u64_t *src_begin,
                     const ae_u64_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t       *_dst_begin = dest_begin;
    const ae_u64_t *_src_begin = src_begin;

    while (_dst_begin < dest_end && _src_begin < src_end)
    {
        *_dst_begin++ = *_src_begin++;
    }
    return _dst_begin;
}

ae_u32_t *
ae_memory_raw_copy32(ae_u32_t       *dest_begin,
                     const ae_u32_t *dest_end,
                     const ae_u32_t *src_begin,
                     const ae_u32_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t       *_dst_begin = dest_begin;
    const ae_u32_t *_src_begin = src_begin;

    while (_dst_begin < dest_end && _src_begin < src_end)
    {
        *_dst_begin++ = *_src_begin++;
    }
    return _dst_begin;
}

ae_u16_t *
ae_memory_raw_copy16(ae_u16_t       *dest_begin,
                     const ae_u16_t *dest_end,
                     const ae_u16_t *src_begin,
                     const ae_u16_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t       *_dst_begin = dest_begin;
    const ae_u16_t *_src_begin = src_begin;

    while (_dst_begin < dest_end && _src_begin < src_end)
    {
        *_dst_begin++ = *_src_begin++;
    }
    return _dst_begin;
}

ae_u8_t *
ae_memory_raw_copy8(ae_u8_t       *dest_begin,
                    const ae_u8_t *dest_end,
                    const ae_u8_t *src_begin,
                    const ae_u8_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t       *_dst_begin = dest_begin;
    const ae_u8_t *_src_begin = src_begin;

    while (_dst_begin < dest_end && _src_begin < src_end)
    {
        *_dst_begin++ = *_src_begin++;
    }
    return _dst_begin;
}

void *
ae_memory_raw_copy(void       *dest_begin,
                   const void *dest_end,
                   const void *src_begin,
                   const void *src_end)
{
    if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U64_T_SIZE) &&
        ae_ptr_range_align_of(src_begin, src_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_copy64(dest_begin, dest_end, src_begin, src_end);
    }
    else if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U32_T_SIZE) &&
             ae_ptr_range_align_of(src_begin, src_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_copy32(dest_begin, dest_end, src_begin, src_end);
    }
    else if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U16_T_SIZE) &&
             ae_ptr_range_align_of(src_begin, src_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_copy16(dest_begin, dest_end, src_begin, src_end);
    }
    return ae_memory_raw_copy8(dest_begin, dest_end, src_begin, src_end);
}

ae_u64_t *
ae_memory_raw_copy64_reverse(const ae_u64_t *dest_begin,
                             ae_u64_t       *dest_end,
                             const ae_u64_t *src_begin,
                             const ae_u64_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t       *_dst_end = dest_end;
    const ae_u64_t *_src_end = src_end;

    while (_dst_end > dest_begin && _src_end > src_begin)
    {
        *--_dst_end = *--_src_end;
    }
    return _dst_end;
}

ae_u32_t *
ae_memory_raw_copy32_reverse(const ae_u32_t *dest_begin,
                             ae_u32_t       *dest_end,
                             const ae_u32_t *src_begin,
                             const ae_u32_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t       *_dst_end = dest_end;
    const ae_u32_t *_src_end = src_end;

    while (_dst_end > dest_begin && _src_end > src_begin)
    {
        *--_dst_end = *--_src_end;
    }
    return _dst_end;
}

ae_u16_t *
ae_memory_raw_copy16_reverse(const ae_u16_t *dest_begin,
                             ae_u16_t       *dest_end,
                             const ae_u16_t *src_begin,
                             const ae_u16_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t       *_dst_end = dest_end;
    const ae_u16_t *_src_end = src_end;

    while (_dst_end > dest_begin && _src_end > src_begin)
    {
        *--_dst_end = *--_src_end;
    }
    return _dst_end;
}

ae_u8_t *
ae_memory_raw_copy8_reverse(const ae_u8_t *dest_begin,
                            ae_u8_t       *dest_end,
                            const ae_u8_t *src_begin,
                            const ae_u8_t *src_end)
{
    AE_RUNTIME_ASSERT(dest_begin && src_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t       *_dst_end = dest_end;
    const ae_u8_t *_src_end = src_end;

    while (_dst_end > dest_begin && _src_end > src_begin)
    {
        *--_dst_end = *--_src_end;
    }
    return _dst_end;
}

void *
ae_memory_raw_copy_reverse(const void *dest_begin,
                           void       *dest_end,
                           const void *src_begin,
                           const void *src_end)
{
    if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U64_T_SIZE) &&
        ae_ptr_range_align_of(src_begin, src_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_copy64_reverse(dest_begin, dest_end, src_begin, src_end);
    }
    else if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U32_T_SIZE) &&
             ae_ptr_range_align_of(src_begin, src_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_copy32_reverse(dest_begin, dest_end, src_begin, src_end);
    }
    else if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U16_T_SIZE) &&
             ae_ptr_range_align_of(src_begin, src_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_copy16_reverse(dest_begin, dest_end, src_begin, src_end);
    }
    return ae_memory_raw_copy8_reverse(dest_begin, dest_end, src_begin, src_end);
}

ae_u64_t *
ae_memory_raw_move64(ae_u64_t       *dest_begin,
                     ae_u64_t       *dest_end,
                     const ae_u64_t *src_begin,
                     const ae_u64_t *src_end)
{
    return ae_ptr_range_overlap(dest_begin, dest_end, src_begin, src_end)
               ? ae_memory_raw_copy64_reverse(dest_begin, dest_end, src_begin, src_end)
               : ae_memory_raw_copy64(dest_begin, dest_end, src_begin, src_end);
}

ae_u32_t *
ae_memory_raw_move32(ae_u32_t       *dest_begin,
                     ae_u32_t       *dest_end,
                     const ae_u32_t *src_begin,
                     const ae_u32_t *src_end)
{
    return ae_ptr_range_overlap(dest_begin, dest_end, src_begin, src_end)
               ? ae_memory_raw_copy32_reverse(dest_begin, dest_end, src_begin, src_end)
               : ae_memory_raw_copy32(dest_begin, dest_end, src_begin, src_end);
}

ae_u16_t *
ae_memory_raw_move16(ae_u16_t       *dest_begin,
                     ae_u16_t       *dest_end,
                     const ae_u16_t *src_begin,
                     const ae_u16_t *src_end)
{
    return ae_ptr_range_overlap(dest_begin, dest_end, src_begin, src_end)
               ? ae_memory_raw_copy16_reverse(dest_begin, dest_end, src_begin, src_end)
               : ae_memory_raw_copy16(dest_begin, dest_end, src_begin, src_end);
}

ae_u8_t *
ae_memory_raw_move8(ae_u8_t       *dest_begin,
                    ae_u8_t       *dest_end,
                    const ae_u8_t *src_begin,
                    const ae_u8_t *src_end)
{
    return ae_ptr_range_overlap(dest_begin, dest_end, src_begin, src_end)
               ? ae_memory_raw_copy8_reverse(dest_begin, dest_end, src_begin, src_end)
               : ae_memory_raw_copy8(dest_begin, dest_end, src_begin, src_end);
}

void *
ae_memory_raw_move(void *dest_begin, void *dest_end, const void *src_begin, const void *src_end)
{
    if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U64_T_SIZE) &&
        ae_ptr_range_align_of(src_begin, src_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_move64(dest_begin, dest_end, src_begin, src_end);
    }
    else if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U32_T_SIZE) &&
             ae_ptr_range_align_of(src_begin, src_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_move32(dest_begin, dest_end, src_begin, src_end);
    }
    else if (ae_ptr_range_align_of(dest_begin, dest_end, AE_U16_T_SIZE) &&
             ae_ptr_range_align_of(src_begin, src_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_move16(dest_begin, dest_end, src_begin, src_end);
    }
    return ae_memory_raw_move8(dest_begin, dest_end, src_begin, src_end);
}

ae_u64_t *
ae_memory_raw_compare64(const ae_u64_t *lhs_begin,
                        const ae_u64_t *lhs_end,
                        const ae_u64_t *rhs_begin,
                        const ae_u64_t *rhs_end)
{
    AE_RUNTIME_ASSERT(lhs_begin && rhs_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u64_t *_lhs_begin = (ae_u64_t *)lhs_begin;
    ae_u64_t *_rhs_begin = (ae_u64_t *)rhs_begin;

    for (; _lhs_begin < lhs_end && _rhs_begin < rhs_end; ++_lhs_begin, ++_rhs_begin)
    {
        if (*_lhs_begin != *_rhs_begin)
        {
            return _lhs_begin;
        }
    }
    return nullptr;
}

ae_u32_t *
ae_memory_raw_compare32(const ae_u32_t *lhs_begin,
                        const ae_u32_t *lhs_end,
                        const ae_u32_t *rhs_begin,
                        const ae_u32_t *rhs_end)
{
    AE_RUNTIME_ASSERT(lhs_begin && rhs_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u32_t *_lhs_begin = (ae_u32_t *)lhs_begin;
    ae_u32_t *_rhs_begin = (ae_u32_t *)rhs_begin;

    for (; _lhs_begin < lhs_end && _rhs_begin < rhs_end; ++_lhs_begin, ++_rhs_begin)
    {
        if (*_lhs_begin != *_rhs_begin)
        {
            return _lhs_begin;
        }
    }
    return nullptr;
}

ae_u16_t *
ae_memory_raw_compare16(const ae_u16_t *lhs_begin,
                        const ae_u16_t *lhs_end,
                        const ae_u16_t *rhs_begin,
                        const ae_u16_t *rhs_end)
{
    AE_RUNTIME_ASSERT(lhs_begin && rhs_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u16_t *_lhs_begin = (ae_u16_t *)lhs_begin;
    ae_u16_t *_rhs_begin = (ae_u16_t *)rhs_begin;

    for (; _lhs_begin < lhs_end && _rhs_begin < rhs_end; ++_lhs_begin, ++_rhs_begin)
    {
        if (*_lhs_begin != *_rhs_begin)
        {
            return _lhs_begin;
        }
    }
    return nullptr;
}

ae_u8_t *
ae_memory_raw_compare8(const ae_u8_t *lhs_begin,
                       const ae_u8_t *lhs_end,
                       const ae_u8_t *rhs_begin,
                       const ae_u8_t *rhs_end)
{
    AE_RUNTIME_ASSERT(lhs_begin && rhs_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    ae_u8_t *_lhs_begin = (ae_u8_t *)lhs_begin;
    ae_u8_t *_rhs_begin = (ae_u8_t *)rhs_begin;

    for (; _lhs_begin < lhs_end && _rhs_begin < rhs_end; ++_lhs_begin, ++_rhs_begin)
    {
        if (*_lhs_begin != *_rhs_begin)
        {
            return _lhs_begin;
        }
    }
    return nullptr;
}

void *
ae_memory_raw_compare(const void *lhs_begin,
                      const void *lhs_end,
                      const void *rhs_begin,
                      const void *rhs_end)
{
    if (ae_ptr_range_align_of(lhs_begin, lhs_end, AE_U64_T_SIZE) &&
        ae_ptr_range_align_of(rhs_begin, rhs_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_compare64(lhs_begin, lhs_end, rhs_begin, rhs_end);
    }
    else if (ae_ptr_range_align_of(lhs_begin, lhs_end, AE_U32_T_SIZE) &&
             ae_ptr_range_align_of(rhs_begin, rhs_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_compare32(lhs_begin, lhs_end, rhs_begin, rhs_end);
    }
    else if (ae_ptr_range_align_of(lhs_begin, lhs_end, AE_U16_T_SIZE) &&
             ae_ptr_range_align_of(rhs_begin, rhs_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_compare16(lhs_begin, lhs_end, rhs_begin, rhs_end);
    }
    return ae_memory_raw_compare8(lhs_begin, lhs_end, rhs_begin, rhs_end);
}

ae_u64_t *
ae_memory_raw_find64(const ae_u64_t *haystack_begin,
                     const ae_u64_t *haystack_end,
                     const ae_u64_t *needle_begin,
                     const ae_u64_t *needle_end)
{
    AE_RUNTIME_ASSERT(haystack_begin && needle_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (; haystack_begin < haystack_end; ++haystack_begin)
    {
        if (!ae_memory_raw_compare64(haystack_begin, haystack_end, needle_begin, needle_end))
        {
            return (ae_u64_t *)haystack_begin;
        }
    }
    return nullptr;
}

ae_u32_t *
ae_memory_raw_find32(const ae_u32_t *haystack_begin,
                     const ae_u32_t *haystack_end,
                     const ae_u32_t *needle_begin,
                     const ae_u32_t *needle_end)
{
    AE_RUNTIME_ASSERT(haystack_begin && needle_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (; haystack_begin < haystack_end; ++haystack_begin)
    {
        if (!ae_memory_raw_compare32(haystack_begin, haystack_end, needle_begin, needle_end))
        {
            return (ae_u32_t *)haystack_begin;
        }
    }
    return nullptr;
}

ae_u16_t *
ae_memory_raw_find16(const ae_u16_t *haystack_begin,
                     const ae_u16_t *haystack_end,
                     const ae_u16_t *needle_begin,
                     const ae_u16_t *needle_end)
{
    AE_RUNTIME_ASSERT(haystack_begin && needle_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (; haystack_begin < haystack_end; ++haystack_begin)
    {
        if (!ae_memory_raw_compare16(haystack_begin, haystack_end, needle_begin, needle_end))
        {
            return (ae_u16_t *)haystack_begin;
        }
    }
    return nullptr;
}

ae_u8_t *
ae_memory_raw_find8(const ae_u8_t *haystack_begin,
                    const ae_u8_t *haystack_end,
                    const ae_u8_t *needle_begin,
                    const ae_u8_t *needle_end)
{
    AE_RUNTIME_ASSERT(haystack_begin && needle_begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (; haystack_begin < haystack_end; ++haystack_begin)
    {
        if (!ae_memory_raw_compare8(haystack_begin, haystack_end, needle_begin, needle_end))
        {
            return (ae_u8_t *)haystack_begin;
        }
    }
    return nullptr;
}

void *
ae_memory_raw_find(const void *haystack_begin,
                   const void *haystack_end,
                   const void *needle_begin,
                   const void *needle_end)
{
    if (ae_ptr_range_align_of(haystack_begin, haystack_end, AE_U64_T_SIZE) &&
        ae_ptr_range_align_of(needle_begin, needle_end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_find64(haystack_begin, haystack_end, needle_begin, needle_end);
    }
    else if (ae_ptr_range_align_of(haystack_begin, haystack_end, AE_U32_T_SIZE) &&
             ae_ptr_range_align_of(needle_begin, needle_end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_find32(haystack_begin, haystack_end, needle_begin, needle_end);
    }
    else if (ae_ptr_range_align_of(haystack_begin, haystack_end, AE_U16_T_SIZE) &&
             ae_ptr_range_align_of(needle_begin, needle_end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_find16(haystack_begin, haystack_end, needle_begin, needle_end);
    }
    return ae_memory_raw_find8(haystack_begin, haystack_end, needle_begin, needle_end);
}

ae_u64_t *
ae_memory_raw_empty64(const ae_u64_t *begin, const ae_u64_t *end)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (const ae_u64_t *ptr = begin; ptr < end; ptr++)
    {
        if (*ptr != 0)
        {
            return (ae_u64_t *)ptr;
        }
    }
    return nullptr;
}

ae_u32_t *
ae_memory_raw_empty32(const ae_u32_t *begin, const ae_u32_t *end)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (const ae_u32_t *ptr = begin; ptr < end; ptr++)
    {
        if (*ptr != 0)
        {
            return (ae_u32_t *)ptr;
        }
    }
    return nullptr;
}

ae_u16_t *
ae_memory_raw_empty16(const ae_u16_t *begin, const ae_u16_t *end)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (const ae_u16_t *ptr = begin; ptr < end; ptr++)
    {
        if (*ptr != 0)
        {
            return (ae_u16_t *)ptr;
        }
    }
    return nullptr;
}

ae_u8_t *
ae_memory_raw_empty8(const ae_u8_t *begin, const ae_u8_t *end)
{
    AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)

    for (const ae_u8_t *ptr = begin; ptr < end; ptr++)
    {
        if (*ptr != 0)
        {
            return (ae_u8_t *)ptr;
        }
    }
    return nullptr;
}

void *
ae_memory_raw_empty(const void *begin, const void *end)
{
    if (ae_ptr_range_align_of(begin, end, AE_U64_T_SIZE))
    {
        return ae_memory_raw_empty64(begin, end);
    }
    else if (ae_ptr_range_align_of(begin, end, AE_U32_T_SIZE))
    {
        return ae_memory_raw_empty32(begin, end);
    }
    else if (ae_ptr_range_align_of(begin, end, AE_U16_T_SIZE))
    {
        return ae_memory_raw_empty16(begin, end);
    }
    return ae_memory_raw_empty8(begin, end);
}