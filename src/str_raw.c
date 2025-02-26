#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>

const ae_char_t *
ae_str_raw_find_value_with(const ae_char_t *str, ae_usize_t len, ae_char_t value)
{
    ae_u8_t *_str = ae_ptr_cast(ae_u8_t, str);
    ae_u8_t  _val = ae_static_cast(ae_u8_t, value);
    ae_u8_t *_end = ae_ptr_add_offset(_str, len);
    return ae_ptr_cast(ae_char_t, ae_memory_raw_find_value_u8(_str, _end, _val));
}

const ae_char_t *
ae_str_raw_find_value(const ae_char_t *str, ae_char_t value)
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_find_value_with(str, len, value));
    }
    ae_runtime_raise(nullptr);
}

const ae_char_t *
ae_str_raw_find_value_rev_with(const ae_char_t *str, ae_usize_t len, ae_char_t value)
{
    ae_u8_t *_str = ae_ptr_cast(ae_u8_t, str);
    ae_u8_t  _val = ae_static_cast(ae_u8_t, value);
    ae_u8_t *_end = ae_ptr_add_offset(_str, len);
    return ae_ptr_cast(ae_char_t, ae_memory_raw_find_value_rev_u8(_str, _end, _val));
}

const ae_char_t *
ae_str_raw_find_value_rev(const ae_char_t *str, ae_char_t value)
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_find_value_rev_with(str, len, value));
    }
    ae_runtime_raise(nullptr);
}

const ae_char_t *
ae_str_raw_find_null_terminator_with(const ae_char_t *str, ae_usize_t len)
{
    return ae_str_raw_find_value_with(str, len, AE_ASCII_MAP_NULL_TERMINATOR);
}

const ae_char_t *
ae_str_raw_find_null_terminator(const ae_char_t *str)
{
    const ae_usize_t str_max = AE_UINTPTR_T_MAX - ae_ptr_to_addr(str);
    return ae_str_raw_find_null_terminator_with(str, str_max);
}

ae_usize_t
ae_str_raw_len_with(const ae_char_t *str, ae_usize_t len)
{
    const ae_char_t *cur =
        len ? ae_str_raw_find_null_terminator_with(str, len) : ae_str_raw_find_null_terminator(str);

    AE_RUNTIME_ASSERT(cur, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_addr_diff(cur, str);
}

ae_usize_t
ae_str_raw_len(const ae_char_t *str)
{
    return ae_str_raw_len_with(str, 0);
}

ae_char_t *
ae_str_raw_copy_from(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len)
{
    ae_u8_t *_str     = ae_ptr_cast(ae_u8_t, str);
    ae_u8_t *_str_end = ae_ptr_add_offset(_str, str_len);
    ae_u8_t *_src     = ae_ptr_cast(ae_u8_t, src);
    ae_u8_t *_src_end = ae_ptr_add_offset(_src, src_len);

    return ae_memory_raw_move(_str, _str_end, _src, _src_end);
}

ae_char_t *
ae_str_raw_copy_with(ae_char_t *str, const ae_char_t *src, ae_usize_t len)
{
    return ae_str_raw_copy_from(str, len, src, len);
}

ae_char_t *
ae_str_raw_copy(ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t src_len = ae_str_raw_len(src);
        ae_runtime_try_interrupt(ae_str_raw_copy_with(str, src, src_len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_fill_with(ae_char_t *str, ae_usize_t len, ae_char_t value)
{
    const ae_u8_t *_str_end = ae_ptr_add_offset(str, len);
    return ae_memory_raw_fill(str, _str_end, value);
}

ae_char_t *
ae_str_raw_fill(ae_char_t *str, ae_char_t value)
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_fill_with(str, len, value));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_cat_from(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len)
{
    ae_char_t *_str = ae_ptr_add_offset(str, str_len);
    return ae_str_raw_copy_with(_str, src, src_len);
}

ae_char_t *
ae_str_raw_cat_with(ae_char_t *str, const ae_char_t *src, ae_usize_t len)
{
    ae_runtime_try
    {
        ae_usize_t _str_len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_cat_from(str, _str_len, src, len));
    }
    ae_runtime_try_interrupt(nullptr);
}

ae_char_t *
ae_str_raw_cat(ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        ae_usize_t _src_len = ae_str_raw_len(src);
        ae_runtime_try_interrupt(ae_str_raw_cat_with(str, src, _src_len));
    }
    ae_runtime_try_interrupt(nullptr);
}

ae_char_t *
ae_str_raw_shift_left_with(ae_char_t *str, ae_usize_t len, ae_usize_t shift)
{
    if (shift)
    {
        if (shift >= len)
        {
            str[0] = AE_ASCII_MAP_NULL_TERMINATOR;
        }
        else
        {
            ae_str_raw_copy_with(str, str + shift, len - shift);
            str[len - shift] = AE_ASCII_MAP_NULL_TERMINATOR;
        }
    }
    return str;
}

ae_char_t *
ae_str_raw_shift_left(ae_char_t *str, ae_usize_t shift)
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_shift_left_with(str, len, shift));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_shift_right_fill_with(ae_char_t *str, ae_usize_t len, ae_usize_t shift, ae_char_t value)
{
    if (shift)
    {
        if (shift >= len)
        {
            str[0] = AE_ASCII_MAP_NULL_TERMINATOR;
        }
        else
        {
            ae_str_raw_copy_with(str + shift, str, len - shift);
            ae_str_raw_fill_with(str, shift, value);
            str[len] = AE_ASCII_MAP_NULL_TERMINATOR;
        }
    }
    return str;
}

ae_char_t *
ae_str_raw_shift_right_fill_space(ae_char_t *str, ae_usize_t len, ae_usize_t shift)
{
    return ae_str_raw_shift_right_fill_with(str, len, shift, AE_ASCII_MAP_SPACE_SYMBOL);
}

ae_char_t *
ae_str_raw_shift_right(ae_char_t *str, ae_usize_t shift)
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_shift_right_fill_space(str, len, shift));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_trim_left_for(ae_char_t *str, ae_usize_t len, const char characters[])
{
    ae_usize_t shift = 0;
    while (shift < len && ae_str_raw_find_value(characters, str[shift]) != NULL)
    {
        shift++;
    }

    return ae_str_raw_shift_left_with(str, len, shift);
}

ae_char_t *
ae_str_raw_trim_left_with(ae_char_t *str, const char characters[])
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_trim_left_for(str, len, characters));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_trim_left(ae_char_t *str)
{
    return ae_str_raw_trim_left_with(str, " \n\r\t\v\x00");
}

ae_char_t *
ae_str_raw_trim_right_for(ae_char_t *str, ae_usize_t len, const char characters[])
{
    ae_usize_t shift = 0;
    while (shift < len && ae_str_raw_find_value(characters, str[len - shift - 1]) != NULL)
    {
        shift++;
    }

    str[len - shift] = AE_ASCII_MAP_NULL_TERMINATOR;
    return str;
}

ae_char_t *
ae_str_raw_trim_right_with(ae_char_t *str, const char characters[])
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_trim_right_for(str, len, characters));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_trim_right(ae_char_t *str)
{
    return ae_str_raw_trim_right_with(str, " \n\r\t\v\x00");
}
