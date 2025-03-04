#ifndef AE_WSTR_RAW_H
#define AE_WSTR_RAW_H

#include "memory.h"
#include "wchar.h"

#define ae_wstr_raw_fill(dst, src, size) ae_memory_fill(dst, src, size, AE_WCHAR_T_SIZE)
#define ae_wstr_raw_copy(dst, src, size) ae_memory_copy(dst, src, size, AE_WCHAR_T_SIZE)
#define ae_wstr_raw_move(dst, src, size) ae_memory_move(dst, src, size, AE_WCHAR_T_SIZE)

#endif // AE_WSTR_RAW_H