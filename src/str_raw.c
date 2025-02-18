#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>

const ae_char_t *
ae_str_raw_find_value_with(const ae_char_t *str, ae_usize_t str_len, ae_char_t value)
{
    ae_u8_t *_str = ae_ptr_cast(ae_u8_t, str);
    ae_u8_t  _val = ae_static_cast(ae_u8_t, value);
    return ae_ptr_cast(ae_char_t, ae_memory_raw_find_value_u8(_str, _str + str_len, _val));
}

const ae_char_t *
ae_str_raw_find_null_terminator_with(const ae_char_t *str, ae_usize_t str_len)
{
    return ae_str_raw_find_value_with(str, str_len, AE_STR_RAW_NULL_TERMINATOR);
}

const ae_char_t *
ae_str_raw_find_null_terminator(const ae_char_t *str)
{
    const ae_usize_t str_max = AE_UINT_T_MAX - ae_ptr_to_addr(str);
    return ae_str_raw_find_null_terminator_with(str, str_max);
}

ae_usize_t
ae_str_raw_len_with(const ae_char_t *str, ae_usize_t str_len)
{
    const ae_char_t *cur = str_len ? ae_str_raw_find_null_terminator_with(str, str_len)
                                   : ae_str_raw_find_null_terminator(str);

    AE_RUNTIME_ASSERT(cur, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_addr_diff(cur, str);
}

ae_usize_t
ae_str_raw_len(const ae_char_t *str)
{
    return ae_str_raw_len_with(str, 0);
}