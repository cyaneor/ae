#include <ae/wstr_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/ptr_range_traits.h>
#include <ae/runtime_assert.h>
#include <ae/wstr_traits.h>
#include <ae/ascii_map.h>
#include <ae/memory.h>

const ae_wstr_raw_t
ae_wstr_raw_find_char(const ae_wstr_raw_t str, ae_usize_t len, ae_wchar_t value)
{
    const ae_wstr_raw_t ptr = ae_memory_find(str, len * AE_WCHAR_T_SIZE, &value, AE_WCHAR_T_SIZE);
    return ae_ptr_align_up(ae_wchar_t, ptr, str, AE_WCHAR_T_SIZE);
}

const ae_wstr_raw_t
ae_wstr_raw_find_of_null_terminator(const ae_wstr_raw_t str)
{
    const ae_usize_t len = AE_UINTPTR_T_MAX - ae_ptr_to_addr(str);
    return ae_wstr_raw_find_char(
        str, len * AE_WCHAR_T_SIZE, ae_wstr_args(AE_ASCII_MAP_NULL_TERMINATOR));
}

ae_usize_t
ae_wstr_raw_len(const ae_wstr_raw_t str)
{
    const ae_wstr_raw_t ptr = ae_wstr_raw_find_of_null_terminator(str);
    ae_runtime_assert(ptr, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_ptr_range_size(str, ptr, AE_WCHAR_T_SIZE);
}