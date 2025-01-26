#include <ae/memory_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

#define AE_MEMORY_RAW_FILL_IMPL(N, T)                                                              \
    ae_memory_raw_fill_def(N, T)                                                                   \
    {                                                                                              \
        AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)                           \
        T *ptr = begin;                                                                            \
        while (ptr < end)                                                                          \
        {                                                                                          \
            *ptr++ = value;                                                                        \
        }                                                                                          \
        return ptr;                                                                                \
    }

#define AE_MEMORY_RAW_FIND_VALUE_IMPL(N, T)                                                        \
    ae_memory_raw_find_value_def(N, T)                                                             \
    {                                                                                              \
        AE_RUNTIME_ASSERT(begin, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)                           \
                                                                                                   \
        const T *ptr = begin;                                                                      \
        while (ptr < end)                                                                          \
        {                                                                                          \
            if (*ptr == value)                                                                     \
            {                                                                                      \
                return ptr;                                                                        \
            }                                                                                      \
            ptr++;                                                                                 \
        }                                                                                          \
        return nullptr;                                                                            \
    }

#define AE_MEMORY_RAW_COMPARE_IMPL(N, T)                                                           \
    ae_memory_raw_compare_def(N, T)                                                                \
    {                                                                                              \
        AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)                      \
                                                                                                   \
        const T *_lhs = lhs;                                                                       \
        const T *_rhs = rhs;                                                                       \
                                                                                                   \
        while (_lhs < lhs_end && _rhs < rhs_end)                                                   \
        {                                                                                          \
            if (*_lhs != *_rhs)                                                                    \
            {                                                                                      \
                return _lhs;                                                                       \
            }                                                                                      \
            _lhs++;                                                                                \
            _rhs++;                                                                                \
        }                                                                                          \
        return nullptr;                                                                            \
    }

#define AE_MEMORY_RAW_COMPARE_REV_IMPL(N, T)                                                       \
    ae_memory_raw_compare_rev_def(N, T)                                                            \
    {                                                                                              \
        AE_RUNTIME_ASSERT(lhs && rhs, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)                      \
                                                                                                   \
        const T *_lhs = lhs_end;                                                                   \
        const T *_rhs = rhs_end;                                                                   \
                                                                                                   \
        while (_lhs > lhs && _rhs > rhs)                                                           \
        {                                                                                          \
            if (*--_lhs != *--_rhs)                                                                \
            {                                                                                      \
                return _lhs;                                                                       \
            }                                                                                      \
        }                                                                                          \
        return nullptr;                                                                            \
    }

#define AE_MEMORY_RAW_COPY_IMPL(N, T)                                                              \
    ae_memory_raw_copy_def(N, T)                                                                   \
    {                                                                                              \
        AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)                      \
                                                                                                   \
        T       *_dst = dst;                                                                       \
        const T *_src = src;                                                                       \
                                                                                                   \
        while (_dst < dst_end && _src < src_end)                                                   \
        {                                                                                          \
            *_dst++ = *_src++;                                                                     \
        }                                                                                          \
                                                                                                   \
        return _dst;                                                                               \
    }

#define AE_MEMORY_RAW_COPY_REV_IMPL(N, T)                                                          \
    ae_memory_raw_copy_rev_def(N, T)                                                               \
    {                                                                                              \
        AE_RUNTIME_ASSERT(dst && src, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)                      \
                                                                                                   \
        const T *_src = src_end;                                                                   \
        T       *_dst = dst_end;                                                                   \
                                                                                                   \
        while (_dst > dst && _src > src)                                                           \
        {                                                                                          \
            *--_dst = *--_src;                                                                     \
        }                                                                                          \
                                                                                                   \
        return _dst;                                                                               \
    }

#define AE_MEMORY_RAW_MOVE_IMPL(N, T)                                                              \
    ae_memory_raw_move_def(N, T)                                                                   \
    {                                                                                              \
        if (ae_ptr_range_is_overlapped(dst, dst_end, src, src_end))                                \
        {                                                                                          \
            T *_ptr = ae_memory_raw_copy_rev_##N(dst, dst_end, src, src_end);                      \
            return _ptr ? ae_ptr_diff_from_end(dst, dst_end, _ptr) : nullptr;                      \
        }                                                                                          \
        return ae_memory_raw_copy_##N(dst, dst_end, src, src_end);                                 \
    }

AE_MEMORY_RAW_FILL_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_FILL_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_FILL_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_FILL_IMPL(u64, ae_u64_t)

AE_MEMORY_RAW_FIND_VALUE_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_FIND_VALUE_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_FIND_VALUE_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_FIND_VALUE_IMPL(u64, ae_u64_t)

AE_MEMORY_RAW_COMPARE_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_COMPARE_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_COMPARE_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_COMPARE_IMPL(u64, ae_u64_t)

AE_MEMORY_RAW_COMPARE_REV_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_COMPARE_REV_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_COMPARE_REV_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_COMPARE_REV_IMPL(u64, ae_u64_t)

AE_MEMORY_RAW_COPY_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_COPY_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_COPY_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_COPY_IMPL(u64, ae_u64_t)

AE_MEMORY_RAW_COPY_REV_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_COPY_REV_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_COPY_REV_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_COPY_REV_IMPL(u64, ae_u64_t)

AE_MEMORY_RAW_MOVE_IMPL(u8, ae_u8_t)
AE_MEMORY_RAW_MOVE_IMPL(u16, ae_u16_t)
AE_MEMORY_RAW_MOVE_IMPL(u32, ae_u32_t)
AE_MEMORY_RAW_MOVE_IMPL(u64, ae_u64_t)