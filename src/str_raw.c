#include <ae/str_raw.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/memory_raw.h>
#include <ae/ptr_util.h>

ae_char_t *
ae_str_raw_copy_to(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len)
{
    ae_u8_t *_str_end = ae_ptr_add_offset(str, str_len);
    return ae_memory_raw_copy(str, _str_end, src, src + src_len);
}

ae_char_t *
ae_str_raw_copy(ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t _str_len = ae_str_raw_len(str);
        const ae_usize_t _src_len = ae_str_raw_len(src);
        ae_runtime_interrupt(ae_str_raw_copy_to(str, _str_len, src, _src_len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_move_to(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len)
{
    ae_u8_t       *_str_end = ae_ptr_add_offset(str, str_len);
    const ae_u8_t *_src_end = ae_ptr_add_offset(src, src_len);
    return ae_memory_raw_move(str, _str_end, src, _src_end);
}

ae_char_t *
ae_str_raw_move(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len)
{
    ae_runtime_try
    {
        const ae_usize_t _str_len = ae_str_raw_len(str);
        const ae_usize_t _src_len = ae_str_raw_len(src);
        ae_runtime_interrupt(ae_str_raw_move_to(str, _str_len, src, _src_len));
    }
    ae_runtime_raise(nullptr);
}

ae_char_t *
ae_str_raw_fill_to(ae_char_t *str, ae_usize_t str_len, ae_char_t value)
{
    const ae_u8_t *_str_end = ae_ptr_add_offset(str, str_len);
    return ae_memory_raw_fill(str, _str_end, value);
}

ae_char_t *
ae_str_raw_fill(ae_char_t *str, ae_char_t value)
{
    ae_runtime_try
    {
        const ae_usize_t _str_len = ae_str_raw_len(str);
        ae_runtime_interrupt(ae_str_raw_fill_to(str, _str_len, value));
    }
    ae_runtime_raise(nullptr);
}

const ae_char_t *
ae_str_raw_find_value_to(const ae_char_t *str, ae_usize_t str_len, ae_char_t value)
{
    const ae_u8_t *_str     = ae_ptr_cast(ae_u8_t, str);
    const ae_u8_t *_str_end = ae_ptr_add_offset(str, str_len);
    const ae_u8_t  _value   = ae_static_cast(ae_u8_t, value);
    return (const ae_char_t *)ae_memory_raw_find_value_u8(_str, _str_end, _value);
}

const ae_char_t *
ae_str_raw_find_value(const ae_char_t *str, ae_char_t value)
{
    ae_runtime_try
    {
        const ae_usize_t _str_len = ae_str_raw_len(str);
        ae_runtime_interrupt(ae_str_raw_find_value_to(str, _str_len, value));
    }
    ae_runtime_raise(nullptr);
}

const ae_char_t *
ae_str_raw_compare_to(const ae_char_t *str,
                      ae_usize_t       str_len,
                      const ae_char_t *src,
                      ae_usize_t       src_len)
{
    const ae_u8_t *_str     = ae_ptr_cast(ae_u8_t, str);
    const ae_u8_t *_str_end = ae_ptr_add_offset(str, str_len);
    const ae_u8_t *_src     = ae_ptr_cast(ae_u8_t, src);
    const ae_u8_t *_src_end = ae_ptr_add_offset(src, src_len);
    return (const ae_char_t *)ae_memory_raw_compare_u8(_str, _str_end, _src, _src_end);
}

const ae_char_t *
ae_str_raw_compare(const ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t _str_len = ae_str_raw_len(str);
        const ae_usize_t _src_len = ae_str_raw_len(src);
        ae_runtime_interrupt(ae_str_raw_compare_to(str, _str_len, src, _src_len));
    }
    ae_runtime_raise(nullptr);
}

const ae_char_t *
ae_str_raw_find_to(const ae_char_t *str,
                   ae_usize_t       str_len,
                   const ae_char_t *src,
                   ae_usize_t       src_len)
{
    const ae_u8_t *_str     = ae_ptr_cast(ae_u8_t, str);
    const ae_u8_t *_str_end = ae_ptr_add_offset(str, str_len);
    const ae_u8_t *_src     = ae_ptr_cast(ae_u8_t, src);
    const ae_u8_t *_src_end = ae_ptr_add_offset(src, src_len);
    return (const ae_char_t *)ae_memory_raw_find_u8(_str, _str_end, _src, _src_end);
}

const ae_char_t *
ae_str_raw_find(const ae_char_t *str, const ae_char_t *src)
{
    ae_runtime_try
    {
        const ae_usize_t _str_len = ae_str_raw_len(str);
        const ae_usize_t _src_len = ae_str_raw_len(src);
        ae_runtime_interrupt(ae_str_raw_find_to(str, _str_len, src, _src_len));
    }
    ae_runtime_raise(nullptr);
}

ae_usize_t
ae_str_raw_len_to(const ae_char_t *str, ae_usize_t str_len)
{
    const void *_ptr = ae_str_raw_find_value_to(str, str_len, AE_STR_RAW_NULL_TERMINATOR);
    AE_RUNTIME_ASSERT(_ptr, AE_RUNTIME_ERROR_NO_NULL_TERMINATOR, 0);
    return ae_ptr_diff(_ptr, str);
}

ae_usize_t
ae_str_raw_len(const ae_char_t *str)
{
    const ae_usize_t _len = AE_UINTPTR_T_MAX - ae_ptr_to_addr(str);
    return ae_str_raw_len_to(str, _len);
}

ae_char_t *
ae_str_raw_cat_from(ae_char_t *str,
                    ae_usize_t       str_len,
                    const ae_char_t *src,
                    ae_usize_t       src_len)
{
    ae_char_t *_str = ae_ptr_add_offset(str, str_len);
    return ae_str_raw_copy_to(_str, src_len, src, src_len);
}