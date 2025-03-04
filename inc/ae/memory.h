#ifndef AE_MEMORY_H
#define AE_MEMORY_H

#include "attribute.h"
#include "size.h"

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_fill(void *dst, const void *src, ae_usize_t size, ae_usize_t type_size);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_copy(void *dst, const void *src, ae_usize_t size, ae_usize_t type_size);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_move(void *dst, const void *src, ae_usize_t size, ae_usize_t type_size);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_H