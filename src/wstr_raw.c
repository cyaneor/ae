#include <ae/wstr_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/ptr_range_traits.h>
#include <ae/runtime_assert.h>
#include <ae/wstr_traits.h>
#include <ae/ascii_map.h>
#include <ae/memory_raw.h>

const ae_wstr_raw_t
ae_wstr_raw_find_char(const ae_wstr_raw_t str, ae_usize_t len, ae_wchar_t value)
{
    const void *_str_end = ae_ptr_add(void, str, len *AE_WCHAR_T_SIZE);
    const void *_val_end = ae_ptr_add_unsafe(void, &value, AE_WCHAR_T_SIZE);

    const ae_wstr_raw_t ptr = ae_memory_raw_find(str, _str_end, &value, _val_end);
    return ae_ptr_align_up(ae_wchar_t, ptr, str, AE_WCHAR_T_SIZE);
}

const ae_wstr_raw_t
ae_wstr_raw_find_of_null_terminator(const ae_wstr_raw_t str)
{
    const ae_usize_t len = AE_UINTPTR_T_MAX - ae_ptr_to_addr(str);
    return ae_wstr_raw_find_char(str, len, ae_wstr_args(AE_ASCII_MAP_NULL_TERMINATOR));
}

ae_usize_t
ae_wstr_raw_len(const ae_wstr_raw_t str)
{
    const ae_wstr_raw_t ptr = ae_wstr_raw_find_of_null_terminator(str);
    ae_runtime_assert(ptr, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_ptr_range_size(str, ptr, AE_WCHAR_T_SIZE);
}

void
ae_wstr_raw_set_value(ae_wstr_raw_t str, ae_usize_t len, ae_wchar_t value)
{
    const void *_str_end = ae_ptr_add_offset(const void, str, len *AE_WCHAR_T_SIZE);
    const void *_val_end = ae_ptr_add_offset_unsafe(const void, &value, AE_WCHAR_T_SIZE);
    ae_memory_raw_set(str, _str_end, &value, _val_end);
}

ae_wstr_raw_t
ae_wstr_raw_copy(ae_wstr_raw_t str, ae_usize_t str_len, const ae_wstr_raw_t src, ae_usize_t src_len)
{
    const void *_str_end = ae_ptr_add_offset(void, str, str_len *AE_WCHAR_T_SIZE);
    const void *_src_end = ae_ptr_add_offset(void, src, src_len *AE_WCHAR_T_SIZE);

    ae_wstr_raw_t ptr = ae_memory_raw_copy(str, _str_end, src, _src_end);
    return ae_ptr_align_up(ae_wchar_t, ptr, str, AE_WCHAR_T_SIZE);
}

const ae_wstr_raw_t
ae_wstr_raw_compare(const ae_wstr_raw_t str,
                    ae_usize_t          str_len,
                    const ae_wstr_raw_t src,
                    ae_usize_t          src_len)
{
    const void *_str_end = ae_ptr_add_offset(void, str, str_len *AE_WCHAR_T_SIZE);
    const void *_src_end = ae_ptr_add_offset(void, src, src_len *AE_WCHAR_T_SIZE);

    const ae_wstr_raw_t ptr = ae_memory_raw_compare(str, _str_end, src, _src_end);
    return ae_ptr_align_up(const ae_wchar_t, ptr, str, AE_WCHAR_T_SIZE);
}