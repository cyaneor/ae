/**
 * @file addr.h
 * @brief Определения типов адресов для различных разрядностей систем.
 *
 * Этот файл содержит определения типов для представления адресов в зависимости от
 * разрядности системы (8, 16, 32 или 64 бита). Он включает в себя макросы для
 * минимальных и максимальных значений, а также для размера типов адресов.
 *
 * В зависимости от значения `AE_PTR_T_SIZE`,
 * определяются два типа:
 *
 * - `ae_uaddr_t`: для представления беззнаковых адресов.
 * - `ae_saddr_t`: для представления знаковых адресов.
 *
 * Каждый из этих типов является синонимом для соответствующего типа целого числа
 * (например, `ae_u64_t` для 64-битных систем) и предоставляет удобный способ
 * работы с адресами, обеспечивая ясность и читаемость кода.
 *
 * @note Все операции, применимые к базовым типам целых чисел,
 *       также применимы к типам `ae_uaddr_t` и `ae_saddr_t`.
 *
 * @warning Убедитесь, что `AE_PTR_T_SIZE` определен и имеет допустимое значение
 *          (1, 2, 4 или 8). В противном случае будет сгенерирована ошибка компиляции.
 */

#ifndef AE_ADDR_H
#define AE_ADDR_H

#include "ptr.h"
#include "numeric_fixed.h"

#ifdef AE_PTR_T_SIZE
#    if AE_PTR_T_SIZE == 8

/**
 * @def AE_UADDR_T_MIN
 * @brief Минимальное значение для типа `ae_uaddr_t`.
 *
 * Этот макрос определяет минимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U64_T_MIN`, которое представляет минимальное значение для 64-битного целого числа.
 * Это значение используется для обозначения наименьшего возможного значения адреса.
 */
#        define AE_UADDR_T_MIN AE_U64_T_MIN

/**
 * @def AE_UADDR_T_MAX
 * @brief Максимальное значение для типа `ae_uaddr_t`.
 *
 * Этот макрос определяет максимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U64_T_MAX`, которое представляет максимальное значение для 64-битного целого числа.
 * Это значение используется для обозначения наибольшего возможного значения адреса.
 */
#        define AE_UADDR_T_MAX AE_U64_T_MAX

/**
 * @def AE_UADDR_T_SIZE
 * @brief Размер типа `ae_uaddr_t` в байтах.
 *
 * Этот макрос определяет размер типа `ae_uaddr_t`, используя значение `AE_U64_T_SIZE`,
 * которое представляет размер 64-битного целого числа в байтах.
 * Это значение указывает, сколько байт занимает тип `ae_uaddr_t`.
 */
#        define AE_UADDR_T_SIZE AE_U64_T_SIZE

/**
 * @typedef ae_uaddr_t
 * @brief Тип для представления адресов.
 *
 * Этот тип `ae_uaddr_t` является синонимом для типа `ae_u64_t`,
 * который представляет собой 64-битное целое число.
 *
 * Он используется для хранения адресов, и его размер определяется как 64 бита,
 * что делает его подходящим для работы с адресами в 64-битных системах.
 *
 * Тип `ae_uaddr_t` применяется для обозначения переменных и параметров,
 * которые содержат адреса, обеспечивая ясность и читаемость кода.
 *
 * @note Поскольку `ae_uaddr_t` эквивалентен типу `ae_u64_t`, все операции,
 *       применимые к `ae_u64_t`, также применимы и к `ae_uaddr_t`.
 */
typedef ae_u64_t ae_uaddr_t;

/**
 * @def AE_SADDR_T_MIN
 * @brief Минимальное значение для типа `ae_saddr_t`.
 *
 * Этот макрос определяет минимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S64_T_MIN`, которое представляет минимальное значение для 64-битного знакового целого числа.
 * Это значение используется для обозначения наименьшего возможного значения знакового адреса.
 */
#        define AE_SADDR_T_MIN AE_S64_T_MIN

/**
 * @def AE_SADDR_T_MAX
 * @brief Максимальное значение для типа `ae_saddr_t`.
 *
 * Этот макрос определяет максимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S64_T_MAX`, которое представляет максимальное значение для 64-битного знакового целого числа.
 * Это значение используется для обозначения наибольшего возможного значения знакового адреса.
 */
#        define AE_SADDR_T_MAX AE_S64_T_MAX

/**
 * @def AE_SADDR_T_SIZE
 * @brief Размер типа `ae_saddr_t` в байтах.
 *
 * Этот макрос определяет размер типа `ae_saddr_t`, используя значение `AE_S64_T_SIZE`,
 * которое представляет размер 64-битного знакового целого числа в байтах.
 * Это значение указывает, сколько байт занимает тип `ae_saddr_t`.
 */
#        define AE_SADDR_T_SIZE AE_S64_T_SIZE

/**
 * @typedef ae_saddr_t
 * @brief Тип для представления знаковых адресов.
 *
 * Этот тип `ae_saddr_t` является синонимом для типа `ae_s64_t`,
 * который представляет собой 64-битное знаковое целое число.
 *
 * Он используется для хранения знаковых адресов,
 * которые могут принимать как положительные,
 * так и отрицательные значения.
 *
 * Тип `ae_saddr_t` применяется в случаях, когда требуется работа с адресами,
 * которые могут быть представлены как знаковые целые числа, например,
 * для указателей, которые могут быть связаны с адресами, требующими учета знака.
 *
 * @note Поскольку `ae_saddr_t` эквивалентен типу `ae_s64_t`, все операции,
 *       применимые к `ae_s64_t`, также применимы и к `ae_saddr_t`.
 */
typedef ae_s64_t ae_saddr_t;

#    elif AE_PTR_T_SIZE == 4

/**
 * @def AE_UADDR_T_MIN
 * @brief Минимальное значение для типа `ae_uaddr_t` на 32-битных системах.
 *
 * Этот макрос определяет минимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U32_T_MIN`, которое представляет минимальное значение для 32-битного беззнакового
 * целого числа.
 */
#        define AE_UADDR_T_MIN AE_U32_T_MIN

/**
 * @def AE_UADDR_T_MAX
 * @brief Максимальное значение для типа `ae_uaddr_t` на 32-битных системах.
 *
 * Этот макрос определяет максимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U32_T_MAX`, которое представляет максимальное значение для 32-битного беззнакового
 * целого числа.
 */
#        define AE_UADDR_T_MAX AE_U32_T_MAX

/**
 * @def AE_UADDR_T_SIZE
 * @brief Размер типа `ae_uaddr_t` в байтах на 32-битных системах.
 *
 * Этот макрос определяет размер типа `ae_uaddr_t`, используя значение
 * `AE_U32_T_SIZE`, которое представляет размер 32-битного беззнакового целого числа в байтах.
 */
#        define AE_UADDR_T_SIZE AE_U32_T_SIZE

/**
 * @typedef ae_uaddr_t
 * @brief Тип для представления беззнаковых адресов на 32-битных системах.
 *
 * Этот тип `ae_uaddr_t` является синонимом для типа `ae_u32_t`, который представляет
 * собой 32-битное беззнаковое целое число, и используется для хранения беззнаковых
 * адресов.
 */
typedef ae_u32_t ae_uaddr_t;

/**
 * @def AE_SADDR_T_MIN
 * @brief Минимальное значение для типа `ae_saddr_t` на 32-битных системах.
 *
 * Этот макрос определяет минимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S32_T_MIN`, которое представляет минимальное значение для 32-битного знакового целого числа.
 */
#        define AE_SADDR_T_MIN AE_S32_T_MIN

/**
 * @def AE_SADDR_T_MAX
 * @brief Максимальное значение для типа `ae_saddr_t` на 32-битных системах.
 *
 * Этот макрос определяет максимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S32_T_MAX`, которое представляет максимальное значение для 32-битного знакового целого числа.
 */
#        define AE_SADDR_T_MAX AE_S32_T_MAX

/**
 * @def AE_SADDR_T_SIZE
 * @brief Размер типа `ae_saddr_t` в байтах на 32-битных системах.
 *
 * Этот макрос определяет размер типа `ae_saddr_t`, используя значение
 * `AE_S32_T_SIZE`, которое представляет размер 32-битного знакового целого числа в байтах.
 */
#        define AE_SADDR_T_SIZE AE_S32_T_SIZE

/**
 * @typedef ae_saddr_t
 * @brief Тип для представления знаковых адресов на 32-битных системах.
 *
 * Этот тип `ae_saddr_t` является синонимом для типа `ae_s32_t`, который представляет собой
 * 32-битное знаковое целое число и используется для хранения знаковых адресов.
 */
typedef ae_s32_t ae_saddr_t;

#    elif AE_PTR_T_SIZE == 2

/**
 * @def AE_UADDR_T_MIN
 * @brief Минимальное значение для типа `ae_uaddr_t` на 16-битных системах.
 *
 * Этот макрос определяет минимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U16_T_MIN`, которое представляет минимальное значение для 16-битного беззнакового целого
 * числа.
 */
#        define AE_UADDR_T_MIN AE_U16_T_MIN

/**
 * @def AE_UADDR_T_MAX
 * @brief Максимальное значение для типа `ae_uaddr_t` на 16-битных системах.
 *
 * Этот макрос определяет максимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U16_T_MAX`, которое представляет максимальное значение для 16-битного беззнакового целого
 * числа.
 */
#        define AE_UADDR_T_MAX AE_U16_T_MAX

/**
 * @def AE_UADDR_T_SIZE
 * @brief Размер типа `ae_uaddr_t` в байтах на 16-битных системах.
 *
 * Этот макрос определяет размер типа `ae_uaddr_t`, используя значение
 * `AE_U16_T_SIZE`, которое представляет размер 16-битного беззнакового целого числа в байтах.
 */
#        define AE_UADDR_T_SIZE AE_U16_T_SIZE

/**
 * @typedef ae_uaddr_t
 * @brief Тип для представления беззнаковых адресов на 16-битных системах.
 *
 * Этот тип `ae_uaddr_t` является синонимом для типа `ae_u16_t`, который представляет собой
 * 16-битное беззнаковое целое число и используется для хранения беззнаковых адресов.
 */
typedef ae_u16_t ae_uaddr_t;

/**
 * @def AE_SADDR_T_MIN
 * @brief Минимальное значение для типа `ae_saddr_t` на 16-битных системах.
 *
 * Этот макрос определяет минимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S16_T_MIN`, которое представляет минимальное значение для 16-битного знакового целого числа.
 */
#        define AE_SADDR_T_MIN AE_S16_T_MIN

/**
 * @def AE_SADDR_T_MAX
 * @brief Максимальное значение для типа `ae_saddr_t` на 16-битных системах.
 *
 * Этот макрос определяет максимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S16_T_MAX`, которое представляет максимальное значение для 16-битного знакового целого числа.
 */
#        define AE_SADDR_T_MAX AE_S16_T_MAX

/**
 * @def AE_SADDR_T_SIZE
 * @brief Размер типа `ae_saddr_t` в байтах на 16-битных системах.
 *
 * Этот макрос определяет размер типа `ae_saddr_t`, используя значение
 * `AE_S16_T_SIZE`, которое представляет размер 16-битного знакового целого числа в байтах.
 */
#        define AE_SADDR_T_SIZE AE_S16_T_SIZE

/**
 * @typedef ae_saddr_t
 * @brief Тип для представления знаковых адресов на 16-битных системах.
 *
 * Этот тип `ae_saddr_t` является синонимом для типа `ae_s16_t`, который представляет собой
 * 16-битное знаковое целое число и используется для хранения знаковых адресов.
 */
typedef ae_s16_t ae_saddr_t;

#    elif AE_PTR_T_SIZE == 1

/**
 * @def AE_UADDR_T_MIN
 * @brief Минимальное значение для типа `ae_uaddr_t` на 8-битных системах.
 *
 * Этот макрос определяет минимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U8_T_MIN`, которое представляет минимальное значение для 8-битного беззнакового целого числа.
 */
#        define AE_UADDR_T_MIN AE_U8_T_MIN

/**
 * @def AE_UADDR_T_MAX
 * @brief Максимальное значение для типа `ae_uaddr_t` на 8-битных системах.
 *
 * Этот макрос определяет максимальное значение для типа `ae_uaddr_t`, используя значение
 * `AE_U8_T_MAX`, которое представляет максимальное значение для 8-битного беззнакового целого
 * числа.
 */
#        define AE_UADDR_T_MAX AE_U8_T_MAX

/**
 * @def AE_UADDR_T_SIZE
 * @brief Размер типа `ae_uaddr_t` в байтах на 8-битных системах.
 *
 * Этот макрос определяет размер типа `ae_uaddr_t`, используя значение
 * `AE_U8_T_SIZE`, которое представляет размер 8-битного беззнакового целого числа в байтах.
 */
#        define AE_UADDR_T_SIZE AE_U8_T_SIZE

/**
 * @typedef ae_uaddr_t
 * @brief Тип для представления беззнаковых адресов на 8-битных системах.
 *
 * Этот тип `ae_uaddr_t` является синонимом для типа `ae_u8_t`, который представляет собой
 * 8-битное беззнаковое целое число и используется для хранения беззнаковых адресов.
 */
typedef ae_u8_t ae_uaddr_t;

/**
 * @def AE_SADDR_T_MIN
 * @brief Минимальное значение для типа `ae_saddr_t` на 8-битных системах.
 *
 * Этот макрос определяет минимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S8_T_MIN`, которое представляет минимальное значение для 8-битного знакового целого числа.
 */
#        define AE_SADDR_T_MIN AE_S8_T_MIN

/**
 * @def AE_SADDR_T_MAX
 * @brief Максимальное значение для типа `ae_saddr_t` на 8-битных системах.
 *
 * Этот макрос определяет максимальное значение для типа `ae_saddr_t`, используя значение
 * `AE_S8_T_MAX`, которое представляет максимальное значение для 8-битного знакового целого числа.
 */
#        define AE_SADDR_T_MAX AE_S8_T_MAX

/**
 * @def AE_SADDR_T_SIZE
 * @brief Размер типа `ae_saddr_t` в байтах на 8-битных системах.
 *
 * Этот макрос определяет размер типа `ae_saddr_t`, используя значение
 * `AE_S8_T_SIZE`, которое представляет размер 8-битного знакового целого числа в байтах.
 */
#        define AE_SADDR_T_SIZE AE_S8_T_SIZE

/**
 * @typedef ae_saddr_t
 * @brief Тип для представления знаковых адресов на 8-битных системах.
 *
 * Этот тип `ae_saddr_t` является синонимом для типа `ae_s8_t`, который представляет собой
 * 8-битное знаковое целое число и используется для хранения знаковых адресов.
 */
typedef ae_s8_t ae_saddr_t;

#    else
#        error "Unsupported pointer size defined"
#    endif
#else
#    error "AE_PTR_T_SIZE is not defined"
#endif

#endif // AE_ADDR_H
