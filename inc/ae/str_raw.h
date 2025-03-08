#ifndef AE_STR_RAW_H
#define AE_STR_RAW_H

#include "char.h"
#include "size.h"
#include "attribute.h"
#include "array_size.h"

/**
 * @def ae_str_raw_t
 * @brief Тип для представления строки, состоящей из символов.
 *
 * Этот макрос определяет тип @ref ae_str_raw_t как указатель на тип @ref ae_char_t,
 * который представляет собой символ (8-битное знаковое или беззнаковое целое число
 * в зависимости от флага компиляции @c AE_CHAR_UNSIGNED).
 *
 * Используется для представления строк
 * в виде указателя на последовательность символов.
 *
 * Пример использования:
 * @code
 * ae_str_raw_t myString = "Hello, world!";
 * @endcode
 */
#define ae_str_raw_t ae_char_t *

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

AE_ATTRIBUTE(SYMBOL)
const ae_str_raw_t
ae_str_raw_find_char(const ae_str_raw_t str, ae_usize_t len, ae_char_t value);

AE_ATTRIBUTE(SYMBOL)
const ae_str_raw_t
ae_str_raw_find_of_null_terminator(const ae_str_raw_t str);

AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_str_raw_len(const ae_str_raw_t str);

AE_ATTRIBUTE(SYMBOL)
const ae_str_raw_t
ae_str_raw_compare(const ae_str_raw_t str,
                   ae_usize_t         str_len,
                   const ae_str_raw_t src,
                   ae_usize_t         src_len);

AE_ATTRIBUTE(SYMBOL)
const ae_str_raw_t
ae_str_raw_compare_from_end(const ae_str_raw_t str,
                            ae_usize_t         str_len,
                            const ae_str_raw_t src,
                            ae_usize_t         src_len);

AE_COMPILER(EXTERN_C_END)

#endif // AE_STR_RAW_H
