#include <ae/memory_raw.h>

#include <ae/runtime_error_code.h>
#include <ae/runtime_return_if.h>
#include <ae/ptr_range_traits.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>
#include <ae/nullptr.h>

#if defined(AE_COMPILE_OPTION_AVX) || defined(AE_COMPILE_OPTION_AVX2)
#    include <immintrin.h> // Для AVX
#endif                     // AE_COMPILE_OPTION_AVX

#ifdef AE_COMPILE_OPTION_SSE
#    include <xmmintrin.h> // Для SSE
#endif                     // AE_COMPILE_OPTION_SSE

#ifdef AE_COMPILE_OPTION_SSE2
#    include <emmintrin.h> // Для SSE2
#endif                     // AE_COMPILE_OPTION_SSE2

#ifdef AE_COMPILE_OPTION_SSE3
#    include <pmmintrin.h> // Для SSE3
#endif                     // AE_COMPILE_OPTION_SSE3

#ifdef AE_COMPILE_OPTION_SSE41
#    include <smmintrin.h> // Для SSE4.1
#endif                     // AE_COMPILE_OPTION_SSE41
                           // AE_COMPILE_OPTION_SSE41

void *
ae_memory_raw_copy(void *dst, const void *dst_end, const void *src, const void *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    ae_u8_t       *_dst     = ae_ptr_cast(ae_u8_t, dst);
    const ae_u8_t *_dst_end = ae_ptr_cast(const ae_u8_t, dst_end);
    const ae_u8_t *_src     = ae_ptr_cast(const ae_u8_t, src);
    const ae_u8_t *_src_end = ae_ptr_cast(const ae_u8_t, src_end);

    while (_dst < _dst_end && _src < _src_end)
    {
        const ae_usize_t dst_len = ae_ptr_diff(_dst_end, _dst);
        const ae_usize_t src_len = ae_ptr_diff(_src_end, _src);

#if defined(AE_COMPILE_OPTION_AVX512)
        if (dst_len >= 64 && src_len >= 64)
        {
            __m512i zmm0 = _mm512_loadu_si512(ae_ptr_cast(const __m512i, _src));
            _mm512_storeu_si512(ae_ptr_cast(__m512i, _dst), zmm0);
            _dst += 64;
            _src += 64;
            continue;
        }
#endif

#if defined(AE_COMPILE_OPTION_AVX) || defined(AE_COMPILE_OPTION_AVX2)
        if (dst_len >= 32 && src_len >= 32)
        {
            __m256i ymm0 = _mm256_loadu_si256(ae_ptr_cast(const __m256i, _src));
            _mm256_storeu_si256(ae_ptr_cast(__m256i, _dst), ymm0);
            _dst += 32;
            _src += 32;
            continue;
        }
#endif

#ifdef AE_COMPILE_OPTION_SSE
        if (dst_len >= 16 && src_len >= 16)
        {
            __m128i xmm0 = _mm_loadu_si128(ae_ptr_cast(const __m128i, _src));
            _mm_storeu_si128(ae_ptr_cast(__m128i, _dst), xmm0);
            _dst += 16;
            _src += 16;
            continue;
        }
#endif

        *_dst++ = *_src++;
    }
    return _dst;
}

void *
ae_memory_raw_copy_from_end(const void *dst, void *dst_end, const void *src, const void *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    ae_u8_t       *_dst     = ae_ptr_cast(ae_u8_t, dst_end);
    const ae_u8_t *_src     = ae_ptr_cast(const ae_u8_t, src_end);
    const ae_u8_t *_dst_end = ae_ptr_cast(const ae_u8_t, dst);
    const ae_u8_t *_src_end = ae_ptr_cast(const ae_u8_t, src);

    while (_dst > _dst_end && _src > _src_end)
    {
        const ae_usize_t dst_len = ae_ptr_diff(_dst, _dst_end);
        const ae_usize_t src_len = ae_ptr_diff(_src, _src_end);

#if defined(AE_COMPILE_OPTION_AVX512)
        if (dst_len >= 64 && src_len >= 64)
        {
            __m512i zmm0 = _mm512_loadu_si512(ae_ptr_cast(const __m512i, _src - 1));
            _mm512_storeu_si512(ae_ptr_cast(__m512i, _dst - 1), zmm0);
            _dst -= 64;
            _src -= 64;
            continue;
        }
#endif

#if defined(AE_COMPILE_OPTION_AVX) || defined(AE_COMPILE_OPTION_AVX2)
        if (dst_len >= 32 && src_len >= 32)
        {
            __m256i ymm0 = _mm256_loadu_si256(ae_ptr_cast(const __m256i, _src - 1));
            _mm256_storeu_si256(ae_ptr_cast(__m256i, _dst - 1), ymm0);
            _dst -= 32;
            _src -= 32;
            continue;
        }
#endif

#ifdef AE_COMPILE_OPTION_SSE
        if (dst_len >= 16 && src_len >= 16)
        {
            __m128i xmm0 = _mm_loadu_si128(ae_ptr_cast(const __m128i, _src - 1));
            _mm_storeu_si128(ae_ptr_cast(__m128i, _dst - 1), xmm0);
            _dst -= 16;
            _src -= 16;
            continue;
        }
#endif

        *--_dst = *--_src;
    }
    return _dst;
}

void *
ae_memory_raw_move(void *dst, const void *dst_end, const void *src, const void *src_end)
{
    ae_runtime_assert(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    if (ae_ptr_range_is_overlapped(dst, src, src_end))
    {
        void *_dst_end = ae_ptr_cast(void, dst_end);
        void *_ptr     = ae_memory_raw_copy_from_end(dst, _dst_end, src, src_end);
        return ae_ptr_sub_offset(void, _dst_end, ae_ptr_to_addr_diff(_ptr, dst));
    }
    return ae_memory_raw_copy(dst, dst_end, src, src_end);
}

const void *
ae_memory_raw_compare(const void *lhs, const void *lhs_end, const void *rhs, const void *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    ae_runtime_return_if(lhs == rhs, nullptr);

    const ae_u8_t *_lhs     = ae_ptr_cast(const ae_u8_t, lhs);
    const ae_u8_t *_lhs_end = ae_ptr_cast(const ae_u8_t, lhs_end);
    const ae_u8_t *_rhs     = ae_ptr_cast(const ae_u8_t, rhs);
    const ae_u8_t *_rhs_end = ae_ptr_cast(const ae_u8_t, rhs_end);

    while (_lhs < _lhs_end && _rhs < _rhs_end)
    {
        const ae_usize_t lhs_len = ae_ptr_diff(_lhs_end, _lhs);
        const ae_usize_t rhs_len = ae_ptr_diff(_rhs_end, _rhs);

#if defined(AE_COMPILE_OPTION_AVX512)
        if (lhs_len >= 64 && rhs_len >= 64)
        {
            __m512i   zmm_lhs = _mm512_loadu_si512(ae_ptr_cast(const __m512i, _lhs));
            __m512i   zmm_rhs = _mm512_loadu_si512(ae_ptr_cast(const __m512i, _rhs));
            __mmask64 mask    = _mm512_cmpeq_epi8_mask(zmm_lhs, zmm_rhs);
            if (mask != 0xFFFFFFFFFFFFFFFF)
            {
                ae_sint_t index = _tzcnt_u64(~mask);
                return _lhs + index;
            }
            _lhs += 64;
            _rhs += 64;
            continue;
        }
#endif

#ifdef AE_COMPILE_OPTION_AVX2
        if (lhs_len >= 32 && rhs_len >= 32)
        {
            __m256i   ymm_lhs       = _mm256_loadu_si256(ae_ptr_cast(const __m256i, _lhs));
            __m256i   ymm_rhs       = _mm256_loadu_si256(ae_ptr_cast(const __m256i, _rhs));
            __m256i   cmp           = _mm256_cmpeq_epi8(ymm_lhs, ymm_rhs);
            ae_sint_t mask          = _mm256_movemask_epi8(cmp);
            ae_uint_t inverted_mask = ~mask;

            if (inverted_mask != 0)
            {
#    if (AE_COMPILER_TYPE == AE_COMPILER_TYPE_GCC || AE_COMPILER_TYPE == AE_COMPILER_TYPE_CLANG)
                ae_sint_t index = __builtin_ctz(inverted_mask);
#    elif AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
                ae_ulong_t index;
                _BitScanForward(&index, inverted_mask);
#    endif
                return _lhs + index;
            }
            _lhs += 32;
            _rhs += 32;
            continue;
        }
#elif defined(AE_COMPILE_OPTION_AVX) || defined(AE_COMPILE_OPTION_SSE)
        if (lhs_len >= 16 && rhs_len >= 16)
        {
            __m128i   xmm_lhs       = _mm_loadu_si128(ae_ptr_cast(const __m128i, _lhs));
            __m128i   xmm_rhs       = _mm_loadu_si128(ae_ptr_cast(const __m128i, _rhs));
            __m128i   cmp           = _mm_cmpeq_epi8(xmm_lhs, xmm_rhs);
            ae_sint_t mask          = _mm_movemask_epi8(cmp);
            ae_uint_t inverted_mask = ~mask & 0xFFFF;

            if (inverted_mask != 0)
            {
#    if (AE_COMPILER_TYPE == AE_COMPILER_TYPE_GCC || AE_COMPILER_TYPE == AE_COMPILER_TYPE_CLANG)
                ae_sint_t index = __builtin_ctz(inverted_mask);
#    elif AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
                ae_ulong_t index;
                _BitScanForward(&index, inverted_mask);
#    else
#        error "Unsupported compiler for memory raw function compare"
#    endif
                return _lhs + index;
            }
            _lhs += 16;
            _rhs += 16;
            continue;
        }
#endif
        if (*_lhs != *_rhs)
        {
            return _lhs;
        }
        _lhs++;
        _rhs++;
    }

    return nullptr;
}

const void *
ae_memory_raw_compare_from_end(const void *lhs,
                               const void *lhs_end,
                               const void *rhs,
                               const void *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u8_t *_lhs = ae_ptr_cast(const ae_u8_t, lhs_end - 1);
    const ae_u8_t *_rhs = ae_ptr_cast(const ae_u8_t, rhs_end - 1);

    ae_usize_t lhs_len = ae_ptr_diff(lhs_end, lhs);
    ae_usize_t rhs_len = ae_ptr_diff(rhs_end, rhs);
    ae_usize_t min_len = (lhs_len < rhs_len) ? lhs_len : rhs_len;

#if defined(AE_COMPILE_OPTION_AVX512)
    while (min_len >= 64)
    {
        const ae_u8_t *_lhs_chunk_start = _lhs - 63;
        const ae_u8_t *_rhs_chunk_start = _rhs - 63;

        __m512i   zmm_lhs = _mm512_loadu_si512(ae_ptr_cast(const __m512i, _lhs_chunk_start));
        __m512i   zmm_rhs = _mm512_loadu_si512(ae_ptr_cast(const __m512i, _rhs_chunk_start));
        __mmask64 mask    = _mm512_cmpeq_epi8_mask(zmm_lhs, zmm_rhs);
        if (mask != 0xFFFFFFFFFFFFFFFF)
        {
            ae_sint_t index = 63 - _lzcnt_u64(~mask);
            return _lhs_chunk_start + index;
        }
        _lhs = _lhs_chunk_start - 1;
        _rhs = _rhs_chunk_start - 1;
        min_len -= 64;
    }
#endif

#ifdef AE_COMPILE_OPTION_AVX2
    while (min_len >= 32)
    {
        const ae_u8_t *_lhs_chunk_start = _lhs - 31;
        const ae_u8_t *_rhs_chunk_start = _rhs - 31;

        __m256i   ymm_lhs       = _mm256_loadu_si256((const __m256i *)_lhs_chunk_start);
        __m256i   ymm_rhs       = _mm256_loadu_si256((const __m256i *)_rhs_chunk_start);
        __m256i   cmp           = _mm256_cmpeq_epi8(ymm_lhs, ymm_rhs);
        ae_sint_t mask          = _mm256_movemask_epi8(cmp);
        ae_uint_t inverted_mask = ~mask;

        if (inverted_mask != 0)
        {
#    if (AE_COMPILER_TYPE == AE_COMPILER_TYPE_GCC || AE_COMPILER_TYPE == AE_COMPILER_TYPE_CLANG)
            ae_sint_t index = 31 - __builtin_clz(inverted_mask);
#    elif AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
            ae_ulong_t index;
            _BitScanReverse(&index, inverted_mask);
#    endif
            return _lhs_chunk_start + index;
        }
        _lhs = _lhs_chunk_start - 1;
        _rhs = _rhs_chunk_start - 1;
        min_len -= 32;
    }
#endif

#if defined(AE_COMPILE_OPTION_AVX) || defined(AE_COMPILE_OPTION_SSE)
    while (min_len >= 16)
    {
        const ae_u8_t *_lhs_chunk_start = _lhs - 15;
        const ae_u8_t *_rhs_chunk_start = _rhs - 15;

        __m128i   xmm_lhs       = _mm_loadu_si128(ae_ptr_cast(const __m128i, _lhs_chunk_start));
        __m128i   xmm_rhs       = _mm_loadu_si128(ae_ptr_cast(const __m128i, _rhs_chunk_start));
        __m128i   cmp           = _mm_cmpeq_epi8(xmm_lhs, xmm_rhs);
        ae_sint_t mask          = _mm_movemask_epi8(cmp);
        ae_uint_t inverted_mask = ~mask & 0xFFFF;

        if (inverted_mask != 0)
        {
#    if (AE_COMPILER_TYPE == AE_COMPILER_TYPE_GCC || AE_COMPILER_TYPE == AE_COMPILER_TYPE_CLANG)
            ae_sint_t index = 15 - __builtin_clz(inverted_mask);
#    elif AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
            ae_ulong_t index;
            _BitScanReverse(&index, inverted_mask);
#    else
#        error "Unsupported compiler for memory raw function compare from end"
#    endif
            return _lhs_chunk_start + index;
        }
        _lhs = _lhs_chunk_start - 1;
        _rhs = _rhs_chunk_start - 1;
        min_len -= 16;
    }
#endif

    for (ae_usize_t i = 0; i < min_len; ++i)
    {
        if (*_lhs != *_rhs)
        {
            return _lhs;
        }
        --_lhs;
        --_rhs;
    }

    return nullptr;
}

const void *
ae_memory_raw_find(const void *lhs, const void *lhs_end, const void *rhs, const void *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u8_t *_lhs_end = ae_ptr_cast(ae_u8_t, lhs_end);
    for (const ae_u8_t *_lhs = lhs; _lhs < _lhs_end; ++_lhs)
    {
        if (!ae_memory_raw_compare(_lhs, lhs_end, rhs, rhs_end))
        {
            return _lhs;
        }
    }
    return nullptr;
}

const void *
ae_memory_raw_find_from_end(const void *lhs,
                            const void *lhs_end,
                            const void *rhs,
                            const void *rhs_end)
{
    ae_runtime_assert(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);

    const ae_u8_t *_lhs = ae_ptr_cast(ae_u8_t, lhs);
    for (const ae_u8_t *_lhs_end = lhs_end; _lhs_end > _lhs; --_lhs_end)
    {
        if (!ae_memory_raw_compare_from_end(lhs, _lhs_end, rhs, rhs_end))
        {
            return ae_ptr_sub_offset_unsafe(void, _lhs_end, ae_ptr_to_addr_diff(rhs_end, rhs));
        }
    }
    return nullptr;
}

void *
ae_memory_raw_set(void *dst, const void *dst_end, const void *src, const void *src_end)
{
    ae_runtime_try
    {
        do
        {
            dst = ae_memory_raw_move(dst, dst_end, src, src_end);
        } while (dst < dst_end);
        ae_runtime_try_return(dst);
    }
    ae_runtime_raise(nullptr);
}