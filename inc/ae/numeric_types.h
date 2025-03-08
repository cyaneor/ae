/**
 * @file numeric_types.h
 * @brief Определения целочисленных типов данных
 *        с фиксированным размером и знаком в зависимости от платформы.
 *
 * Этот файл содержит определения целочисленных типов,
 * которые используются для обеспечения переносимости кода между разными платформами.
 * Включает знаковые и беззнаковые типы с фиксированной длиной, соответствующей базовым типам C.
 *
 * Типы:
 * - Беззнаковые типы: ae_uchar_t, ae_ushort_t, ae_uint_t, ae_ulong_t, ae_ullong_t
 * - Знаковые типы: ae_schar_t, ae_sshort_t, ae_sint_t, ae_slong_t, ae_sllong_t
 *
 * @note Размеры типов могут различаться в зависимости от архитектуры,
 *       однако указанные типы стремятся к совместимости с платформами C.
 */

#ifndef AE_NUMERIC_TYPES_H
#define AE_NUMERIC_TYPES_H

/**
 * @typedef ae_uchar_t
 * @brief Определение беззнакового однобайтового целого типа.
 */
typedef unsigned char ae_uchar_t;

/**
 * @typedef ae_ushort_t
 * @brief Определение беззнакового двухбайтового целого типа.
 */
typedef unsigned short ae_ushort_t;

/**
 * @typedef ae_uint_t
 * @brief Определение беззнакового четырехбайтового целого типа.
 */
typedef unsigned int ae_uint_t;

/**
 * @typedef ae_ulong_t
 * @brief Определение беззнакового целого типа
 *        с длиной в четыре или восемь байт (в зависимости от платформы).
 */
typedef unsigned long ae_ulong_t;

/**
 * @typedef ae_ullong_t
 * @brief Определение беззнакового целого типа
 *        с длиной в восемь байт.
 */
typedef unsigned long long int ae_ullong_t;

/**
 * @typedef ae_schar_t
 * @brief Определение знакового однобайтового целого типа.
 */
typedef char ae_schar_t;

/**
 * @typedef ae_sshort_t
 * @brief Определение знакового двухбайтового целого типа.
 */
typedef short ae_sshort_t;

/**
 * @typedef ae_sint_t
 * @brief Определение знакового четырехбайтового целого типа.
 */
typedef int ae_sint_t;

/**
 * @typedef ae_slong_t
 * @brief Определение знакового целого типа
 *        с длиной в четыре или восемь байт (в зависимости от платформы).
 */
typedef long ae_slong_t;

/**
 * @typedef ae_sllong_t
 * @brief Определение знакового целого типа
 *        с длиной в восемь байт.
 */
typedef long long ae_sllong_t;

#ifdef AE_INT128_T_SIZE
/**
 * @typedef ae_sint128_t
 * @brief Тип для знакового 128-битного целого числа.
 *
 * Используется для хранения целых чисел со знаком, занимающих 128 бит.
 * Данный тип доступен, если определена макросом `AE_INT128_T_SIZE`.
 *
 * @note Требует поддержки компилятором типа `__int128`.
 */
typedef __int128 ae_sint128_t;

/**
 * @typedef ae_uint128_t
 * @brief Тип для беззнакового 128-битного целого числа.
 *
 * Используется для хранения целых чисел без знака, занимающих 128 бит.
 * Данный тип доступен, если определена макросом `AE_INT128_T_SIZE`.
 *
 * @note Требует поддержки компилятором типа `unsigned __int128`.
 */
typedef unsigned __int128 ae_uint128_t;
#endif // AE_INT128_T_SIZE

#endif // AE_NUMERIC_TYPES_H
