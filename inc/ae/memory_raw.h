#ifndef AE_MEMORY_RAW_H
#define AE_MEMORY_RAW_H

#include "attribute.h"
#include "size.h"

AE_COMPILER(EXTERN_C_BEGIN)

AE_ATTRIBUTE(SYMBOL)
ae_u8_t *
ae_memory_raw_fill8(ae_u8_t *ptr, ae_usize_t len, ae_u8_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u16_t *
ae_memory_raw_fill16(ae_u16_t *ptr, ae_usize_t len, ae_u16_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u32_t *
ae_memory_raw_fill32(ae_u32_t *ptr, ae_usize_t len, ae_u32_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u64_t *
ae_memory_raw_fill64(ae_u64_t *ptr, ae_usize_t len, ae_u64_t value);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_fill(void *ptr, ae_usize_t len, ae_u8_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u8_t *
ae_memory_raw_find8_val(ae_u8_t *ptr, ae_usize_t len, ae_u8_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u16_t *
ae_memory_raw_find16_val(ae_u16_t *ptr, ae_usize_t len, ae_u16_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u32_t *
ae_memory_raw_find32_val(ae_u32_t *ptr, ae_usize_t len, ae_u32_t value);

AE_ATTRIBUTE(SYMBOL)
ae_u64_t *
ae_memory_raw_find64_val(ae_u64_t *ptr, ae_usize_t len, ae_u64_t value);

AE_ATTRIBUTE(SYMBOL)
const ae_u8_t *
ae_memory_raw_compare8(const ae_u8_t *lhs,
                       ae_usize_t     lhs_len,
                       const ae_u8_t *rhs,
                       ae_usize_t     rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u16_t *
ae_memory_raw_compare16(const ae_u16_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u16_t *rhs,
                        ae_usize_t      rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u32_t *
ae_memory_raw_compare32(const ae_u32_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u32_t *rhs,
                        ae_usize_t      rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u64_t *
ae_memory_raw_compare64(const ae_u64_t *lhs,
                        ae_usize_t      lhs_len,
                        const ae_u64_t *rhs,
                        ae_usize_t      rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u8_t *
ae_memory_raw_compare8_rev(const ae_u8_t *lhs,
                           ae_usize_t     lhs_len,
                           const ae_u8_t *rhs,
                           ae_usize_t     rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u16_t *
ae_memory_raw_compare16_rev(const ae_u16_t *lhs,
                            ae_usize_t      lhs_len,
                            const ae_u16_t *rhs,
                            ae_usize_t      rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u32_t *
ae_memory_raw_compare32_rev(const ae_u32_t *lhs,
                            ae_usize_t      lhs_len,
                            const ae_u32_t *rhs,
                            ae_usize_t      rhs_len);

AE_ATTRIBUTE(SYMBOL)
const ae_u64_t *
ae_memory_raw_compare64_rev(const ae_u64_t *lhs,
                            ae_usize_t      lhs_len,
                            const ae_u64_t *rhs,
                            ae_usize_t      rhs_len);

AE_ATTRIBUTE(SYMBOL)
ae_u8_t *
ae_memory_raw_copy8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u16_t *
ae_memory_raw_copy16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u32_t *
ae_memory_raw_copy32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u64_t *
ae_memory_raw_copy64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_copy(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u8_t *
ae_memory_raw_copy8_rev(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u16_t *
ae_memory_raw_copy16_rev(ae_u16_t       *dst,
                         ae_usize_t      dst_len,
                         const ae_u16_t *src,
                         ae_usize_t      src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u32_t *
ae_memory_raw_copy32_rev(ae_u32_t       *dst,
                         ae_usize_t      dst_len,
                         const ae_u32_t *src,
                         ae_usize_t      src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u64_t *
ae_memory_raw_copy64_rev(ae_u64_t       *dst,
                         ae_usize_t      dst_len,
                         const ae_u64_t *src,
                         ae_usize_t      src_len);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_copy_rev(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u8_t *
ae_memory_raw_move8(ae_u8_t *dst, ae_usize_t dst_len, const ae_u8_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u16_t *
ae_memory_raw_move16(ae_u16_t *dst, ae_usize_t dst_len, const ae_u16_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u32_t *
ae_memory_raw_move32(ae_u32_t *dst, ae_usize_t dst_len, const ae_u32_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
ae_u64_t *
ae_memory_raw_move64(ae_u64_t *dst, ae_usize_t dst_len, const ae_u64_t *src, ae_usize_t src_len);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_move(void *dst, ae_usize_t dst_len, const void *src, ae_usize_t src_len);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_RAW_H
