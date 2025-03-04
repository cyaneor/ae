#ifndef AE_STR_RAW_H
#define AE_STR_RAW_H

#include "memory.h"
#include "char.h"

#define ae_str_raw_fill(dst, src, size) ae_memory_fill(dst, src, size, AE_CHAR_T_SIZE)
#define ae_str_raw_copy(dst, src, size) ae_memory_copy(dst, src, size, AE_CHAR_T_SIZE)
#define ae_str_raw_move(dst, src, size) ae_memory_move(dst, src, size, AE_CHAR_T_SIZE)

#endif // AE_STR_RAW_H