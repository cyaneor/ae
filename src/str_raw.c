#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_return_if.h>
#include <ae/runtime_try.h>
#include <ae/ptr_traits.h>
#include <ae/memory_raw.h>
#include <ae/ascii_map.h>
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

const ae_str_raw_t
ae_str_raw_find_char(const ae_str_raw_t str, ae_usize_t len, ae_char_t value)
{
    return ae_memory_find(str, len, &value, AE_CHAR_T_SIZE);
}

const ae_str_raw_t
ae_str_raw_find_of_null_terminator(const ae_str_raw_t str)
{
    const ae_usize_t _len = AE_UINTPTR_T_MAX - ae_ptr_to_addr(str);
    return ae_str_raw_find_char(str, _len, AE_ASCII_MAP_NULL_TERMINATOR);
}

ae_usize_t
ae_str_raw_len(const ae_str_raw_t str)
{
    const ae_str_raw_t ptr = ae_str_raw_find_of_null_terminator(str);
    ae_runtime_assert(ptr, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_ptr_diff(ptr, str);
}

const ae_str_raw_t
ae_str_raw_compare(const ae_str_raw_t str,
                   ae_usize_t         str_len,
                   const ae_str_raw_t src,
                   ae_usize_t         src_len)
{
    return ae_memory_compare(str, str_len, src, src_len);
}

const ae_str_raw_t
ae_str_raw_compare_from_end(const ae_str_raw_t str,
                            ae_usize_t         str_len,
                            const ae_str_raw_t src,
                            ae_usize_t         src_len)
{
    return ae_memory_compare(str, str_len, src, src_len);
}

// ---------------------------------------------------------------------------------------------- //

const ae_str_raw_t
ae_str_raw_starts_with(const ae_str_raw_t str, const ae_str_raw_t src)
{
    ae_runtime_try
    {
        ae_usize_t str_len = ae_str_raw_len(str);
        ae_usize_t src_len = ae_str_raw_len(src);
        ae_runtime_try_return(ae_str_raw_compare(str, str_len, src, src_len));
    }
    ae_runtime_raise(nullptr);
}

const ae_str_raw_t
ae_str_raw_ends_with(const ae_str_raw_t str, const ae_str_raw_t src)
{
    ae_runtime_try
    {
        ae_usize_t str_len = ae_str_raw_len(str);
        ae_usize_t src_len = ae_str_raw_len(src);
        ae_runtime_try_return(ae_str_raw_compare_from_end(str, str_len, src, src_len));
    }
    ae_runtime_raise(nullptr);
}