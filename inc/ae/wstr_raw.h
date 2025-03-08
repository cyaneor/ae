#ifndef AE_WSTR_RAW_H
#define AE_WSTR_RAW_H

#include "attribute.h"
#include "wchar.h"
#include "size.h"

/**
 * @def ae_wstr_raw_t
 * @brief Синоним для указателя на широкий символ.
 *
 * Этот макрос определяет тип данных `ae_wstr_raw_t` как указатель на @ref ae_wchar_t.
 * Он используется для работы с строками широких символов,
 * обеспечивая удобный способ указания на массив широких символов.
 *
 * @note Указатель на широкий символ может использоваться для представления
 *       строк, содержащих символы, которые могут быть как знаковыми,
 *       так и беззнаковыми, в зависимости от конфигурации компилятора.
 */
#define ae_wstr_raw_t ae_wchar_t *

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Находит первый экземпляр заданного широкого символа в строке.
 *
 * Эта функция ищет указанный широкий символ в строке,
 * представленном указателем на широкий символ.
 *
 * @param str Указатель на строку широких символов,
 *            в которой будет выполняться поиск.
 * @param len Длина строки `str`.
 * @param value Значение широкого символа,
 *              который необходимо найти в строке.
 *
 * @return Указатель на первый найденный экземпляр символа в строке или `NULL`,
 *         если символ не найден.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const ae_wstr_raw_t
ae_wstr_raw_find_char(const ae_wstr_raw_t str, ae_usize_t len, ae_wchar_t value);

/**
 * @brief Находит позицию нулевого терминатора в строке широких символов.
 *
 * Эта функция ищет первый экземпляр нулевого терминатора в строке,
 * представленном указателем на широкий символ.
 *
 * @param str Указатель на строку широких символов,
 *            в которой будет выполняться поиск.
 *
 * @return Указатель на позицию нулевого терминатора в строке или `NULL`,
 *         если терминатор не найден.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const ae_wstr_raw_t
ae_wstr_raw_find_of_null_terminator(const ae_wstr_raw_t str);

/**
 * @brief Вычисляет длину строки широких символов.
 *
 * Эта функция определяет длину строки,
 * представленную указателем на широкий символ, путем поиска нулевого терминатора.
 *
 * @param str Указатель на строку широких символов, длину которой необходимо вычислить.
 * @return Длина строки в символах (не включая нулевой терминатор).
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 * @throw AE_RUNTIME_ERROR_NO_NULL_TERMINATOR
 *        Если нулевой терминатор не найден в строке.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_wstr_raw_len(const ae_wstr_raw_t str);

AE_COMPILER(EXTERN_C_END)

#endif // AE_WSTR_RAW_H
