#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ascii_map.h>
#include <ae/ptr_util.h>
#include <ae/memory.h>

/**
 * @brief Массив символов,
 *        которые считаются пробельными и будут удалены с начала строки.
 *
 * Этот массив содержит набор символов, которые будут удалены с начала строки в функциях,
 * выполняющих обрезку. Включает стандартные пробельные символы, такие как пробел,
 * символы новой строки, возврата каретки, табуляции и вертикальной табуляции,
 * а также символ нулевого терминатора, который будет использоваться
 * для завершения строки.
 *
 * Массив включает следующие символы:
 * - Пробел (`AE_ASCII_MAP_SPACE`)
 * - Новая строка (`AE_ASCII_MAP_NEWLINE`)
 * - Возврат каретки (`AE_ASCII_MAP_CARRIAGE_RETURN`)
 * - Табуляция (`AE_ASCII_MAP_TAB`)
 * - Вертикальная табуляция (`AE_ASCII_MAP_VERTICAL_TAB`)
 * - Нулевой терминатор строки (`AE_ASCII_MAP_NULL_TERMINATOR`)
 */
static const ae_char_t m_trim_ascii_chars[] = {AE_ASCII_MAP_SPACE,
                                               AE_ASCII_MAP_NEWLINE,
                                               AE_ASCII_MAP_CARRIAGE_RETURN,
                                               AE_ASCII_MAP_TAB,
                                               AE_ASCII_MAP_VERTICAL_TAB,
                                               AE_ASCII_MAP_NULL_TERMINATOR};

const ae_char_t *
ae_str_raw_find_value_ex(const ae_char_t *str, ae_usize_t len, ae_char_t value)
{
    const ae_u8_t *_str     = ae_ptr_cast(ae_u8_t, str);
    const ae_u8_t *_str_end = ae_ptr_add_offset(_str, len);
    return ae_ptr_cast(const ae_char_t, ae_memory_raw_find_value_u8(_str, _str_end, value));
}

const ae_char_t *
ae_str_raw_find_value(const ae_char_t *str, ae_char_t value)
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_find_value_ex(str, len, value));
    }
    ae_runtime_raise(nullptr);
}

const ae_char_t *
ae_str_raw_find_null_terminator(const ae_char_t *str)
{
    const ae_usize_t _len = AE_UINTPTR_T_MAX - ae_ptr_to_addr(str);
    return ae_str_raw_find_value_ex(str, _len, AE_ASCII_MAP_NULL_TERMINATOR);
}

ae_usize_t
ae_str_raw_len(const ae_char_t *str)
{
    const ae_char_t *_ptr = ae_str_raw_find_null_terminator(str);
    ae_runtime_assert(_ptr, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_addr_diff(_ptr, str);
}

ae_char_t *
ae_str_raw_copy_ex(ae_char_t *str, const ae_char_t *src, ae_usize_t len)
{
    return ae_memory_copy(str, src, len);
}

ae_char_t *
ae_str_raw_copy(ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(src);
        ae_runtime_try_interrupt(ae_str_raw_copy_ex(str, src, len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_move_ex(ae_char_t *str, const ae_char_t *src, ae_usize_t len)
{
    return ae_memory_move(str, src, len);
}

ae_char_t *
ae_str_raw_move(ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_move_ex(str, src, len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_concat_ex(ae_char_t *str, const ae_char_t *src, ae_usize_t src_len)
{
    ae_runtime_try
    {
        const ae_usize_t dst_len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_memory_append_ex(str, dst_len, src, src_len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_concat(ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(src);
        ae_runtime_try_interrupt(ae_str_raw_concat_ex(str, src, len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_clear(ae_char_t *str)
{
    ae_runtime_assert(str, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    str[0] = AE_ASCII_MAP_NULL_TERMINATOR;
    return str;
}

ae_char_t *
ae_str_raw_shift_left_ex(ae_char_t *str, ae_usize_t len, ae_usize_t shift)
{
    if (shift >= len)
    {
        ae_str_raw_clear(str);
    }
    else
    {
        ae_char_t *_end = ae_memory_shift_left(str, len, shift);
        *_end           = AE_ASCII_MAP_NULL_TERMINATOR;
    }
    return str;
}

ae_char_t *
ae_str_raw_shift_left(ae_char_t *str, ae_usize_t shift)
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_shift_left_ex(str, len, shift));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_shift_right_ex(ae_char_t *str, ae_usize_t len, ae_usize_t shift, ae_char_t value)
{
    if (shift)
    {
        if (shift >= len)
        {
            ae_str_raw_clear(str);
        }
        else
        {
            ae_char_t *_end = ae_memory_shift_right_and_fill(str, len, shift, value);
            *_end           = AE_ASCII_MAP_NULL_TERMINATOR;
        }
    }
    return str;
}

ae_char_t *
ae_str_raw_shift_right_with(ae_char_t *str, ae_usize_t shift, ae_char_t value)
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_shift_right_ex(str, len, shift, value));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_shift_right_with_space(ae_char_t *str, ae_usize_t shift)
{
    return ae_str_raw_shift_right_with(str, shift, AE_ASCII_MAP_SPACE);
}

ae_char_t *
ae_str_raw_shift_right(ae_char_t *str, ae_usize_t shift)
{
    return ae_str_raw_shift_right_with_space(str, shift);
}

ae_char_t *
ae_str_raw_trim_left_with(ae_char_t *str, ae_usize_t len, const ae_char_t characters[])
{
    ae_usize_t shift = 0;
    for (; shift < len; ++shift)
    {
        if (ae_str_raw_find_value(characters, str[shift]) == nullptr)
        {
            break;
        }
    }
    return ae_str_raw_shift_left_ex(str, len, shift);
}

ae_char_t *
ae_str_raw_trim_left_ex(ae_char_t *str, const ae_char_t characters[])
{
    ae_runtime_try
    {
        const ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_trim_left_with(str, len, characters));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_trim_left(ae_char_t *str)
{
    return ae_str_raw_trim_left_ex(str, m_trim_ascii_chars);
}

ae_char_t *
ae_str_raw_trim_right_with(ae_char_t *str, ae_usize_t len, const ae_char_t characters[])
{
    ae_runtime_assert(str, AE_RUNTIME_ERROR_NULL_POINTER, nullptr);
    if (len)
    {
        ae_usize_t shift = 0;
        for (; shift < len; ++shift)
        {
            const ae_usize_t index = len - shift - 1;
            if (ae_str_raw_find_value(characters, str[index]) == nullptr)
            {
                break;
            }
        }
        str[len - shift] = AE_ASCII_MAP_NULL_TERMINATOR;
    }
    return str;
}

ae_char_t *
ae_str_raw_trim_right_ex(ae_char_t *str, const ae_char_t characters[])
{
    ae_runtime_try
    {
        ae_usize_t len = ae_str_raw_len(str);
        ae_runtime_try_interrupt(ae_str_raw_trim_right_with(str, len, characters));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_trim_right(ae_char_t *str)
{
    return ae_str_raw_trim_right_ex(str, " \n\r\t\v\x00");
}

ae_char_t *
ae_str_raw_trim_ex(ae_char_t *str, const ae_char_t characters[])
{
    ae_runtime_try
    {
        ae_str_raw_trim_left_ex(str, characters);
        ae_runtime_try_interrupt(ae_str_raw_trim_right_ex(str, characters));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_trim(ae_char_t *str)
{
    return ae_str_raw_trim_ex(str, m_trim_ascii_chars);
}