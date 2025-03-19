/**
 * @file numeric_limits.h
 * @brief Определяет макросы для числовых ограничений различных типов данных.
 * @details Этот файл создается автоматически, не пытайтесь редактировать его вручную.
 *
 * Этот заголовочный файл содержит макросы для определения минимальных
 * и максимальных значений как для знаковых, так и для беззнаковых числовых типов данных.
 */

#ifndef AE_NUMERIC_LIMITS_H
#define AE_NUMERIC_LIMITS_H

#include "numeric_limit.h"
#include "numeric_types.h"

/**
 * @def AE_UCHAR_T_MIN
 * @brief Определяет минимальное значение для `ae_uchar_t`.
 */
#ifndef AE_UCHAR_T_MIN
#    define AE_UCHAR_T_MIN AE_NUMERIC_LIMIT_UINT_MIN(ae_uchar_t)
#endif // AE_UCHAR_T_MIN

/**
 * @def AE_UCHAR_T_MAX
 * @brief Определяет максимальное значение для `ae_uchar_t`.
 */
#ifndef AE_UCHAR_T_MAX
#    define AE_UCHAR_T_MAX AE_NUMERIC_LIMIT_UINT_MAX(ae_uchar_t)
#endif // AE_UCHAR_T_MAX

/**
 * @def AE_USHORT_T_MIN
 * @brief Определяет минимальное значение для `ae_ushort_t`.
 */
#ifndef AE_USHORT_T_MIN
#    define AE_USHORT_T_MIN AE_NUMERIC_LIMIT_UINT_MIN(ae_ushort_t)
#endif // AE_USHORT_T_MIN

/**
 * @def AE_USHORT_T_MAX
 * @brief Определяет максимальное значение для `ae_ushort_t`.
 */
#ifndef AE_USHORT_T_MAX
#    define AE_USHORT_T_MAX AE_NUMERIC_LIMIT_UINT_MAX(ae_ushort_t)
#endif // AE_USHORT_T_MAX

/**
 * @def AE_UINT_T_MIN
 * @brief Определяет минимальное значение для `ae_uint_t`.
 */
#ifndef AE_UINT_T_MIN
#    define AE_UINT_T_MIN AE_NUMERIC_LIMIT_UINT_MIN(ae_uint_t)
#endif // AE_UINT_T_MIN

/**
 * @def AE_UINT_T_MAX
 * @brief Определяет максимальное значение для `ae_uint_t`.
 */
#ifndef AE_UINT_T_MAX
#    define AE_UINT_T_MAX AE_NUMERIC_LIMIT_UINT_MAX(ae_uint_t)
#endif // AE_UINT_T_MAX

/**
 * @def AE_ULONG_T_MIN
 * @brief Определяет минимальное значение для `ae_ulong_t`.
 */
#ifndef AE_ULONG_T_MIN
#    define AE_ULONG_T_MIN AE_NUMERIC_LIMIT_UINT_MIN(ae_ulong_t)
#endif // AE_ULONG_T_MIN

/**
 * @def AE_ULONG_T_MAX
 * @brief Определяет максимальное значение для `ae_ulong_t`.
 */
#ifndef AE_ULONG_T_MAX
#    define AE_ULONG_T_MAX AE_NUMERIC_LIMIT_UINT_MAX(ae_ulong_t)
#endif // AE_ULONG_T_MAX

/**
 * @def AE_ULLONG_T_MIN
 * @brief Определяет минимальное значение для `ae_ullong_t`.
 */
#ifndef AE_ULLONG_T_MIN
#    define AE_ULLONG_T_MIN AE_NUMERIC_LIMIT_UINT_MIN(ae_ullong_t)
#endif // AE_ULLONG_T_MIN

/**
 * @def AE_ULLONG_T_MAX
 * @brief Определяет максимальное значение для `ae_ullong_t`.
 */
#ifndef AE_ULLONG_T_MAX
#    define AE_ULLONG_T_MAX AE_NUMERIC_LIMIT_UINT_MAX(ae_ullong_t)
#endif // AE_ULLONG_T_MAX

/**
 * @def AE_SCHAR_T_MIN
 * @brief Определяет минимальное значение для `ae_schar_t`.
 */
#ifndef AE_SCHAR_T_MIN
#    define AE_SCHAR_T_MIN AE_NUMERIC_LIMIT_SINT_MIN(ae_schar_t)
#endif // AE_SCHAR_T_MIN

/**
 * @def AE_SCHAR_T_MAX
 * @brief Определяет максимальное значение для `ae_schar_t`.
 */
#ifndef AE_SCHAR_T_MAX
#    define AE_SCHAR_T_MAX AE_NUMERIC_LIMIT_SINT_MAX(ae_schar_t)
#endif // AE_SCHAR_T_MAX

/**
 * @def AE_SSHORT_T_MIN
 * @brief Определяет минимальное значение для `ae_sshort_t`.
 */
#ifndef AE_SSHORT_T_MIN
#    define AE_SSHORT_T_MIN AE_NUMERIC_LIMIT_SINT_MIN(ae_sshort_t)
#endif // AE_SSHORT_T_MIN

/**
 * @def AE_SSHORT_T_MAX
 * @brief Определяет максимальное значение для `ae_sshort_t`.
 */
#ifndef AE_SSHORT_T_MAX
#    define AE_SSHORT_T_MAX AE_NUMERIC_LIMIT_SINT_MAX(ae_sshort_t)
#endif // AE_SSHORT_T_MAX

/**
 * @def AE_SINT_T_MIN
 * @brief Определяет минимальное значение для `ae_sint_t`.
 */
#ifndef AE_SINT_T_MIN
#    define AE_SINT_T_MIN AE_NUMERIC_LIMIT_SINT_MIN(ae_sint_t)
#endif // AE_SINT_T_MIN

/**
 * @def AE_SINT_T_MAX
 * @brief Определяет максимальное значение для `ae_sint_t`.
 */
#ifndef AE_SINT_T_MAX
#    define AE_SINT_T_MAX AE_NUMERIC_LIMIT_SINT_MAX(ae_sint_t)
#endif // AE_SINT_T_MAX

/**
 * @def AE_SLONG_T_MIN
 * @brief Определяет минимальное значение для `ae_slong_t`.
 */
#ifndef AE_SLONG_T_MIN
#    define AE_SLONG_T_MIN AE_NUMERIC_LIMIT_SINT_MIN(ae_slong_t)
#endif // AE_SLONG_T_MIN

/**
 * @def AE_SLONG_T_MAX
 * @brief Определяет максимальное значение для `ae_slong_t`.
 */
#ifndef AE_SLONG_T_MAX
#    define AE_SLONG_T_MAX AE_NUMERIC_LIMIT_SINT_MAX(ae_slong_t)
#endif // AE_SLONG_T_MAX

/**
 * @def AE_SLLONG_T_MIN
 * @brief Определяет минимальное значение для `ae_sllong_t`.
 */
#ifndef AE_SLLONG_T_MIN
#    define AE_SLLONG_T_MIN AE_NUMERIC_LIMIT_SINT_MIN(ae_sllong_t)
#endif // AE_SLLONG_T_MIN

/**
 * @def AE_SLLONG_T_MAX
 * @brief Определяет максимальное значение для `ae_sllong_t`.
 */
#ifndef AE_SLLONG_T_MAX
#    define AE_SLLONG_T_MAX AE_NUMERIC_LIMIT_SINT_MAX(ae_sllong_t)
#endif // AE_SLLONG_T_MAX

#ifdef AE_INT128_T_SIZE
/**
 * @def AE_UINT128_T_MIN
 * @brief Минимальное значение для беззнакового 128-битного целого числа.
 *
 * Определяется через макрос `AE_NUMERIC_LIMIT_UINT_MIN` для типа `ae_uint128_t`.
 * Этот макрос предоставляет минимальное возможное значение для переменной типа `ae_uint128_t`.
 * Доступен, если определена макросом `AE_INT128_T_SIZE`.
 */
#    define AE_UINT128_T_MIN AE_NUMERIC_LIMIT_UINT_MIN(ae_uint128_t)

/**
 * @def AE_UINT128_T_MAX
 * @brief Максимальное значение для беззнакового 128-битного целого числа.
 *
 * Определяется через макрос `AE_NUMERIC_LIMIT_UINT_MAX` для типа `ae_uint128_t`.
 * Этот макрос предоставляет максимальное возможное значение для переменной типа `ae_uint128_t`.
 * Доступен, если определена макросом `AE_INT128_T_SIZE`.
 */
#    define AE_UINT128_T_MAX AE_NUMERIC_LIMIT_UINT_MAX(ae_uint128_t)

/**
 * @def AE_SINT128_T_MIN
 * @brief Минимальное значение для знакового 128-битного целого числа.
 *
 * Определяется через макрос `AE_NUMERIC_LIMIT_SINT_MIN` для типа `ae_sint128_t`.
 * Этот макрос предоставляет минимальное возможное значение для переменной типа `ae_sint128_t`.
 * Доступен, если определена макросом `AE_INT128_T_SIZE`.
 */
#    define AE_SINT128_T_MIN AE_NUMERIC_LIMIT_SINT_MIN(ae_sint128_t)

/**
 * @def AE_SINT128_T_MAX
 * @brief Максимальное значение для знакового 128-битного целого числа.
 *
 * Определяется через макрос `AE_NUMERIC_LIMIT_SINT_MAX` для типа `ae_sint128_t`.
 * Этот макрос предоставляет максимальное возможное значение для переменной типа `ae_sint128_t`.
 * Доступен, если определена макросом `AE_INT128_T_SIZE`.
 */
#    define AE_SINT128_T_MAX AE_NUMERIC_LIMIT_SINT_MAX(ae_sint128_t)
#endif // AE_INT128_T_SIZE

#endif // AE_NUMERIC_LIMITS_H