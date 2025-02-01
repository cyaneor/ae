#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

ae_u8_t *
ae_str_raw_fill_u8(ae_u8_t *ptr, ae_usize_t len, ae_u8_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_fill_u8(ptr, ptr + len, value);
}

ae_u16_t *
ae_str_raw_fill_u16(ae_u16_t *ptr, ae_usize_t len, ae_u16_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_fill_u16(ptr, ptr + len, value);
}

ae_u32_t *
ae_str_raw_fill_u32(ae_u32_t *ptr, ae_usize_t len, ae_u32_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_fill_u32(ptr, ptr + len, value);
}

ae_u64_t *
ae_str_raw_fill_u64(ae_u64_t *ptr, ae_usize_t len, ae_u64_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_fill_u64(ptr, ptr + len, value);
}

void *
ae_str_raw_fill(void *ptr, ae_usize_t len, ae_u8_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_fill(ptr, ae_ptr_add_offset(ptr, len), value);
}

const ae_u8_t *
ae_str_raw_find_value_u8(const ae_u8_t *ptr, ae_usize_t len, ae_u8_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_value_u8(ptr, ptr + len, value);
}

const ae_u16_t *
ae_str_raw_find_value_u16(const ae_u16_t *ptr, ae_usize_t len, ae_u16_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_value_u16(ptr, ptr + len, value);
}

const ae_u32_t *
ae_str_raw_find_value_u32(const ae_u32_t *ptr, ae_usize_t len, ae_u32_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_value_u32(ptr, ptr + len, value);
}

const ae_u64_t *
ae_str_raw_find_value_u64(const ae_u64_t *ptr, ae_usize_t len, ae_u64_t value)
{
    ae_runtime_assert(ptr)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_value_u64(ptr, ptr + len, value);
}

const ae_u8_t *
ae_str_raw_compare_u8(const ae_u8_t *lhs,
                      ae_usize_t     lhs_len,
                      const ae_u8_t *rhs,
                      ae_usize_t     rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_u8(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u16_t *
ae_str_raw_compare_u16(const ae_u16_t *lhs,
                       ae_usize_t      lhs_len,
                       const ae_u16_t *rhs,
                       ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_u16(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u32_t *
ae_str_raw_compare_u32(const ae_u32_t *lhs,
                       ae_usize_t      lhs_len,
                       const ae_u32_t *rhs,
                       ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_u32(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u64_t *
ae_str_raw_compare_u64(const ae_u64_t *lhs,
                       ae_usize_t      lhs_len,
                       const ae_u64_t *rhs,
                       ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_u64(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u8_t *
ae_str_raw_compare_rev_u8(const ae_u8_t *lhs,
                          ae_usize_t     lhs_len,
                          const ae_u8_t *rhs,
                          ae_usize_t     rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_rev_u8(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u16_t *
ae_str_raw_compare_rev_u16(const ae_u16_t *lhs,
                           ae_usize_t      lhs_len,
                           const ae_u16_t *rhs,
                           ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_rev_u16(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u32_t *
ae_str_raw_compare_rev_u32(const ae_u32_t *lhs,
                           ae_usize_t      lhs_len,
                           const ae_u32_t *rhs,
                           ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_rev_u32(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u64_t *
ae_str_raw_compare_rev_u64(const ae_u64_t *lhs,
                           ae_usize_t      lhs_len,
                           const ae_u64_t *rhs,
                           ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_compare_rev_u64(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

ae_u8_t *
ae_str_raw_copy_u8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_u8(dst, dst + dst_len, src, src + src_len);
}

ae_u16_t *
ae_str_raw_copy_u16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_u16(dst, dst + dst_len, src, src + src_len);
}

ae_u32_t *
ae_str_raw_copy_u32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_u32(dst, dst + dst_len, src, src + src_len);
}

ae_u64_t *
ae_str_raw_copy_u64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_u64(dst, dst + dst_len, src, src + src_len);
}

void *
ae_str_raw_copy(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy(
        dst, ae_ptr_add_offset(dst, dst_len), src, ae_ptr_add_offset(src, src_len));
}

ae_u8_t *
ae_str_raw_copy_rev_u8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_rev_u8(dst, dst + dst_len, src, src + src_len);
}

ae_u16_t *
ae_str_raw_copy_rev_u16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_rev_u16(dst, dst + dst_len, src, src + src_len);
}

ae_u32_t *
ae_str_raw_copy_rev_u32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_rev_u32(dst, dst + dst_len, src, src + src_len);
}

ae_u64_t *
ae_str_raw_copy_rev_u64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_rev_u64(dst, dst + dst_len, src, src + src_len);
}

void *
ae_str_raw_copy_rev(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_copy_rev(
        dst, ae_ptr_add_offset(dst, dst_len), src, ae_ptr_add_offset(src, src_len));
}

ae_u8_t *
ae_str_raw_move_u8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_move_u8(dst, dst + dst_len, src, src + src_len);
}

ae_u16_t *
ae_str_raw_move_u16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_move_u16(dst, dst + dst_len, src, src + src_len);
}

ae_u32_t *
ae_str_raw_move_u32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_move_u32(dst, dst + dst_len, src, src + src_len);
}

ae_u64_t *
ae_str_raw_move_u64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_move_u64(dst, dst + dst_len, src, src + src_len);
}

void *
ae_str_raw_move(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len)
{
    ae_runtime_assert(dst && src)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_move(
        dst, ae_ptr_add_offset(dst, dst_len), src, ae_ptr_add_offset(src, src_len));
}

const ae_u8_t *
ae_str_raw_find_u8(const ae_u8_t *lhs, ae_usize_t lhs_len, const ae_u8_t *rhs, ae_usize_t rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_u8(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u16_t *
ae_str_raw_find_u16(const ae_u16_t *lhs,
                    ae_usize_t      lhs_len,
                    const ae_u16_t *rhs,
                    ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_u16(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u32_t *
ae_str_raw_find_u32(const ae_u32_t *lhs,
                    ae_usize_t      lhs_len,
                    const ae_u32_t *rhs,
                    ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_u32(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u64_t *
ae_str_raw_find_u64(const ae_u64_t *lhs,
                    ae_usize_t      lhs_len,
                    const ae_u64_t *rhs,
                    ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_u64(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u8_t *
ae_str_raw_find_rev_u8(const ae_u8_t *lhs,
                       ae_usize_t     lhs_len,
                       const ae_u8_t *rhs,
                       ae_usize_t     rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_rev_u8(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u16_t *
ae_str_raw_find_rev_u16(const ae_u16_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u16_t *rhs,
                        ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_rev_u16(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u32_t *
ae_str_raw_find_rev_u32(const ae_u32_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u32_t *rhs,
                        ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_rev_u32(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}

const ae_u64_t *
ae_str_raw_find_rev_u64(const ae_u64_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u64_t *rhs,
                        ae_usize_t      rhs_len)
{
    ae_runtime_assert(lhs && rhs)
    {
        ae_runtime_throw(AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    }
    return ae_memory_raw_find_rev_u64(lhs, lhs + lhs_len, rhs, rhs + rhs_len);
}