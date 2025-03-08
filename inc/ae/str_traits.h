/**
 * @file str_traits.h
 * @brief Утилиты для работы со строками и символами в C.
 *
 * Этот файл содержит набор макросов для манипуляций со строками и символами,
 * включая преобразование аргументов в строковые литералы, вычисление размеров строк
 * и преобразование символов в различные типы данных. Макросы предназначены для упрощения
 * работы с текстовыми данными в проектах на C, обеспечивая удобные и безопасные средства
 * для обработки строковых литералов и символов.
 */

#ifndef AE_STR_TRAITS_H
#define AE_STR_TRAITS_H

#include "array_size.h"

/**
 * @def ae_str_to(x)
 * @brief Преобразует аргумент в строковый литерал.
 *
 * Данный макрос принимает один аргумент и преобразует его в строку.
 * Это полезно, когда необходимо получить строковое представление
 * имени переменной или другого идентификатора.
 *
 * @param x Аргумент, который будет преобразован в строку.
 * @return Строковый литерал, представляющий аргумент.
 */
#define ae_str_to(x) #x

/**
 * @def ae_str_args(...)
 * @brief Преобразует переменное число аргументов в строковый литерал.
 *
 * Этот макрос принимает переменное число аргументов и преобразует их в одну строку.
 * Он использует макрос `ae_str_to` для выполнения фактического преобразования.
 *
 * @param ... Переменное число аргументов, которые будут преобразованы в строку.
 * @return Строковый литерал, представляющий все переданные аргументы.
 *
 * @note Этот макрос особенно полезен, когда нужно преобразовать
 *       в строку несколько аргументов или выражение с запятыми.
 *
 * @see ae_str_to
 */
#define ae_str_args(...) ae_str_to(__VA_ARGS__)

/**
 * @def ae_str_size
 * @brief Вычисляет размер строки, определённой макросом,
 *        без учёта нулевого символа.
 *
 * Этот макрос вычисляет размер строки, используя другой макрос `ae_array_size`,
 * и вычитает 1, чтобы исключить нулевой символ конца строки.
 *
 * @param str Строка, для которой вычисляется размер.
 * @return Размер строки без учёта нулевого символа.
 */
#define ae_str_size(str) (ae_array_size(str) - 1)

/**
 * @def ae_str_ord_to
 * @brief Преобразует символ в указанный тип.
 *
 * Этот макрос выполняет преобразование символа в указанный тип данных.
 * Он позволяет безопасно преобразовывать значение типа `char` в другой тип,
 * указанный пользователем.
 *
 * @param T Тип, в который нужно преобразовать символ.
 * @param c Символ, который необходимо преобразовать.
 *
 * @return Преобразованное значение типа T.
 */
#define ae_str_ord_to(T, c) ((T)(c))

/**
 * @def ae_str_ord
 * @brief Преобразует символ в целое число типа ae_sint_t.
 *
 * Этот макрос преобразует символ в целое число с типом `ae_sint_t`
 * с использованием макроса `ae_str_ord_to`.
 *
 * Он обеспечивает преобразование символа
 * в целочисленное значение типа `ae_sint_t`.
 *
 * @param c Символ, который необходимо преобразовать.
 * @return Преобразованное значение типа `ae_sint_t`.
 */
#define ae_str_ord(c) ae_str_ord_to(ae_sint_t, c)

#endif // AE_STR_TRAITS_H
