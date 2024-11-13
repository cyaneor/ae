/**
 * @file stringify.h
 * @brief Заголовочный файл для макросов преобразования аргументов в строковые литералы.
 *
 * Этот файл содержит определения макросов,
 * которые позволяют преобразовывать аргументы в строковые литералы.
 *
 * Включает два макроса:
 * - `ae_stringify`: для преобразования одного аргумента в строку.
 * - `ae_stringify_args`: для преобразования переменного числа аргументов в одну строку.
 *
 * Макросы полезны для получения строкового представления переменных,
 * выражений и других идентификаторов, что может быть полезно в отладке
 * или при создании сообщений.
 */

#ifndef AE_STRINGIFY_H
#define AE_STRINGIFY_H

/**
 * @def ae_stringify(x)
 * @brief Преобразует аргумент в строковый литерал.
 *
 * Данный макрос принимает один аргумент и преобразует его в строку.
 * Это полезно, когда необходимо получить строковое представление
 * имени переменной или другого идентификатора.
 *
 * @param x Аргумент, который будет преобразован в строку.
 * @return Строковый литерал, представляющий аргумент.
 */
#define ae_stringify(x) #x

/**
 * @def ae_stringify_args(...)
 * @brief Преобразует переменное число аргументов в строковый литерал.
 *
 * Этот макрос принимает переменное число аргументов и преобразует их в одну строку.
 * Он использует макрос ae_stringify для выполнения фактического преобразования.
 *
 * @param ... Переменное число аргументов, которые будут преобразованы в строку.
 * @return Строковый литерал, представляющий все переданные аргументы.
 *
 * @note Этот макрос особенно полезен, когда нужно преобразовать
 *       в строку несколько аргументов или выражение с запятыми.
 *
 * @see ae_stringify
 */
#define ae_stringify_args(...) ae_stringify(__VA_ARGS__)

#endif // AE_STRINGIFY_H
