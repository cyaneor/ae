#ifndef AE_STR_RAW_H
#define AE_STR_RAW_H

#include "char.h"
#include "size.h"
#include "attribute.h"
#include "array_size.h"

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Ищет символ в строке.
 *
 * Эта функция ищет первое вхождение указанного символа
 * в заданном блоке памяти, представляющем строку.
 *
 * - Если символ найден, функция возвращает указатель на его первое вхождение.
 * - Если символ не найден, возвращается nullptr.
 *
 * @param str Указатель на начало блока памяти,
 *            в которой будет производиться поиск.
 * @param len Длина блока памяти (строки), в которой будет производиться поиск.
 * @param value Символ, который нужно найти в строке.
 *
 * @return Указатель на первое вхождение символа @c value в строке @c str или nullptr,
 *         если символ не найден.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const ae_char_t *
ae_str_raw_find_char(const ae_char_t *str, ae_usize_t len, ae_char_t value);

/**
 * @brief Ищет символ нулевого терминатора в строке.
 *
 * Эта функция ищет первое вхождение символа нулевого терминатора в заданном блоке памяти,
 * представляющем строку. Она использует максимальную длину блока памяти для поиска.
 *
 * - Если нулевой терминатор найден, функция возвращает указатель на его первое вхождение.
 * - Если нулевой терминатор не найден, возвращается nullptr.
 *
 * @param str Указатель на начало блока памяти,
 *            в которой будет производиться поиск.
 *
 * @return Указатель на первое вхождение символа нулевого терминатора
 *         в строке @c str или nullptr, если терминатор не найден.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const ae_char_t *
ae_str_raw_find_of_null_terminator(const ae_char_t *str);

/**
 * @brief Определяет длину строки до нулевого терминатора.
 *
 * Эта функция вычисляет длину строки,
 * путем поиска символа нулевого терминатора.
 *
 * - Если нулевой терминатор найден,
 *   функция возвращает количество символов в строке до него.
 * - Если нулевой терминатор не найден,
 *   генерируется исключение.
 *
 * @param str Указатель на начало блока памяти,
 *            длину которой нужно определить.
 *
 * @return Длина строки в символах
 *         до первого вхождения нулевого терминатора.
 *
 * @throw AE_RUNTIME_ERROR_NO_NULL_TERMINATOR
 *        Если нулевой терминатор не найден в строке.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_str_raw_len(const ae_char_t *str);

/**
 * @brief Устанавливает значение для заданного диапазона в строке.
 *
 * Эта функция заполняет диапазон памяти, представляющий строку, заданным значением
 * для указанной длины. Она используется для инициализации или изменения значений
 * в строке.
 *
 * @param str Указатель на начало блока памяти, которую нужно изменить.
 * @param len Длина диапазона, который необходимо заполнить заданным значением.
 * @param value Значение, которое будет установлено в указанный диапазон.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_str_raw_set_value(ae_char_t *str, ae_usize_t len, ae_char_t value);

/**
 * @brief Копирует данные из одной строки в другую.
 *
 * Эта функция копирует содержимое из исходной строки в целевую строку в заданном диапазоне.
 * Она используется для создания копий строк в указанных пределах.
 *
 * @param str Указатель на начало блока памяти, в который будет скопировано содержимое.
 * @param str_len Длина блока памяти, в который нужно скопировать данные.
 * @param src Указатель на начало блока памяти, представляющего исходную строку.
 * @param src_len Длина исходной строки, которую нужно скопировать.
 *
 * @return Указатель на начало целевой строки (str) после копирования.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
ae_char_t *
ae_str_raw_copy(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len);

/**
 * @brief Перемещает содержимое одной строки в другую.
 *
 * Эта функция перемещает данные из одной строки в другую,
 * начиная с конца каждой строки.
 *
 * @param str Указатель на начало целевой строки,
 *            в которую будут перемещены данные.
 * @param str_len Длина целевой строки.
 * @param src Указатель на начало исходной строки,
 *            откуда будут перемещены данные.
 * @param src_len Длина исходной строки.
 *
 * @return Указатель на целевую строку
 *         после перемещения данных.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
ae_char_t *
ae_str_raw_move(ae_char_t *str, ae_usize_t str_len, const ae_char_t *src, ae_usize_t src_len);

/**
 * @brief Сравнивает две строки по заданной длине.
 *
 * Эта функция сравнивает содержимое двух строк, начиная с указанных адресов
 * и заканчивая заданными длинами. Используется для определения равенства
 * строк или нахождения первого различия между ними.
 *
 * @param str Указатель на начало первой строки,
 *            которую нужно сравнить.
 * @param str_len Длина первой строки для сравнения.
 * @param src Указатель на начало второй строки,
 *            с которой будет производиться сравнение.
 * @param src_len Длина второй строки для сравнения.
 *
 * @return Указатель на первое различие между строками или nullptr,
 *         если строки равны.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const ae_char_t *
ae_str_raw_compare(const ae_char_t *str,
                   ae_usize_t       str_len,
                   const ae_char_t *src,
                   ae_usize_t       src_len);

/**
 * @brief Сравнивает две строки, начиная с конца.
 *
 * Эта функция сравнивает две строки,
 * заданные указателями и их длинами, начиная с конца каждой строки.
 *
 * @param str Указатель на начало первой строки,
 *            которая будет сравнена.
 * @param str_len Длина первой строки.
 * @param src Указатель на начало второй строки,
 *            которая будет сравнена.
 * @param src_len Длина второй строки.
 *
 * @return Указатель на первое различие между строками или nullptr,
 *         если строки равны.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c str или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const ae_char_t *
ae_str_raw_compare_from_end(const ae_char_t *str,
                            ae_usize_t       str_len,
                            const ae_char_t *src,
                            ae_usize_t       src_len);

AE_COMPILER(EXTERN_C_END)

#endif // AE_STR_RAW_H
