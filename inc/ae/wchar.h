/**
 * @file wchar.h
 * @brief Заголовочный файл для определения типов данных широких символов.
 *
 * Этот файл содержит определения типов данных для широких символов,
 * которые могут быть как знаковыми, так и беззнаковыми,
 * в зависимости от настроек компилятора.
 */

#ifndef AE_WCHAR_H
#define AE_WCHAR_H

#include "numeric.h"

/**
 * @def AE_SCHAR16_T_MIN
 * @brief Минимальное значение для типа AE_SCHAR16_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_SCHAR16_T.
 * Он эквивалентен значению макроса AE_S16_T_MIN.
 */
#define AE_SCHAR16_T_MIN AE_S16_T_MIN

/**
 * @def AE_SCHAR16_T_MAX
 * @brief Максимальное значение для типа AE_SCHAR16_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_SCHAR16_T.
 * Он эквивалентен значению макроса AE_S16_T_MAX.
 */
#define AE_SCHAR16_T_MAX AE_S16_T_MAX

/**
 * @def AE_SCHAR16_T_SIZE
 * @brief Размер типа AE_SCHAR16_T в байтах.
 *
 * Этот макрос возвращает размер типа данных AE_SCHAR16_T в байтах.
 * Он эквивалентен значению макроса AE_S16_T_SIZE.
 */
#define AE_SCHAR16_T_SIZE AE_S16_T_SIZE

/**
 * @typedef ae_schar16_t
 * @brief Тип данных для 16-битных знаковых целых чисел.
 *
 * Этот тип является синонимом для типа данных @ref ae_s16_t,
 * который представляет собой 16-битное знаковое целое число.
 */
typedef ae_s16_t ae_schar16_t;

/**
 * @def AE_UCHAR16_T_MIN
 * @brief Минимальное значение для типа AE_UCHAR16_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_UCHAR16_T.
 * Он эквивалентен значению макроса AE_U16_T_MIN.
 */
#define AE_UCHAR16_T_MIN AE_U16_T_MIN

/**
 * @def AE_UCHAR16_T_MAX
 * @brief Максимальное значение для типа AE_UCHAR16_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_UCHAR16_T.
 * Он эквивалентен значению макроса AE_U16_T_MAX.
 */
#define AE_UCHAR16_T_MAX AE_U16_T_MAX

/**
 * @def AE_UCHAR16_T_SIZE
 * @brief Размер типа AE_UCHAR16_T в байтах.
 *
 * Этот макрос возвращает размер типа данных AE_UCHAR16_T в байтах.
 * Он эквивалентен значению макроса AE_U16_T_SIZE.
 */
#define AE_UCHAR16_T_SIZE AE_U16_T_SIZE

/**
 * @typedef ae_uchar16_t
 * @brief Тип данных для 16-битных беззнаковых целых чисел.
 *
 * Этот тип является синонимом для типа данных @ref ae_u16_t,
 * который представляет собой 16-битное беззнаковое целое число.
 */
typedef ae_u16_t ae_uchar16_t;

/**
 * @def AE_SCHAR32_T_MIN
 * @brief Минимальное значение для типа AE_SCHAR32_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_SCHAR32_T.
 * Он эквивалентен значению макроса AE_S32_T_MIN.
 */
#define AE_SCHAR32_T_MIN AE_S32_T_MIN

/**
 * @def AE_SCHAR32_T_MAX
 * @brief Максимальное значение для типа AE_SCHAR32_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_SCHAR32_T.
 * Он эквивалентен значению макроса AE_S32_T_MAX.
 */
#define AE_SCHAR32_T_MAX AE_S32_T_MAX

/**
 * @def AE_SCHAR32_T_SIZE
 * @brief Размер типа AE_SCHAR32_T в байтах.
 *
 * Этот макрос возвращает размер типа данных AE_SCHAR32_T в байтах.
 * Он эквивалентен значению макроса AE_S32_T_SIZE.
 */
#define AE_SCHAR32_T_SIZE AE_S32_T_SIZE

/**
 * @typedef ae_schar32_t
 * @brief Тип данных для 32-битных знаковых целых чисел.
 *
 * Этот тип является синонимом для типа данных @ref ae_s32_t,
 * который представляет собой 32-битное знаковое целое число.
 */
typedef ae_s32_t ae_schar32_t;

/**
 * @def AE_UCHAR32_T_MIN
 * @brief Минимальное значение для типа AE_UCHAR32_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_UCHAR32_T.
 * Он эквивалентен значению макроса AE_U32_T_MIN.
 */
#define AE_UCHAR32_T_MIN AE_U32_T_MIN

/**
 * @def AE_UCHAR32_T_MAX
 * @brief Максимальное значение для типа AE_UCHAR32_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_UCHAR32_T.
 * Он эквивалентен значению макроса AE_U32_T_MAX.
 */
#define AE_UCHAR32_T_MAX AE_U32_T_MAX

/**
 * @def AE_UCHAR32_T_SIZE
 * @brief Размер типа AE_UCHAR32_T в байтах.
 *
 * Этот макрос возвращает размер типа данных AE_UCHAR32_T в байтах.
 * Он эквивалентен значению макроса AE_U32_T_SIZE.
 */
#define AE_UCHAR32_T_SIZE AE_U32_T_SIZE

/**
 * @typedef ae_uchar32_t
 * @brief Тип данных для 32-битных беззнаковых целых чисел.
 *
 * Этот тип является синонимом для типа данных @ref ae_u32_t,
 * который представляет собой 32-битное беззнаковое целое число.
 */
typedef ae_u32_t ae_uchar32_t;

/**
 * @def AE_WCHAR_T_SIZE
 * @brief Флаг компиляции, определяющий размер @ref ae_wchar_t.
 *
 * - Если флаг @ref AE_WCHAR_T_SIZE равен 4,
 *   то @ref ae_wchar_t будет 32-битным.
 * - Если флаг @ref AE_WCHAR_T_SIZE равен 2,
 *   то @ref ae_wchar_t будет 16-битным.
 */
#if AE_WCHAR_T_SIZE == 4
#    ifdef AE_CHAR_UNSIGNED
/**
 * @def AE_WCHAR_T_MIN
 * @brief Минимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_UCHAR32_T_MIN.
 */
#        define AE_WCHAR_T_MIN AE_UCHAR32_T_MIN

/**
 * @def AE_WCHAR_T_MAX
 * @brief Максимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_UCHAR32_T_MAX.
 */
#        define AE_WCHAR_T_MAX AE_UCHAR32_T_MAX

/**
 * @typedef ae_wchar_t
 * @brief Тип данных для широкого символа (32-битный).
 *
 * Тип @ref ae_wchar_t представляет собой 32-битный широкий символ, который может быть либо
 * знаковым, либо беззнаковым в зависимости от флага компиляции @ref AE_CHAR_UNSIGNED.
 *
 * - Если флаг @ref AE_CHAR_UNSIGNED определён, то @ref ae_wchar_t является синонимом
 *   для типа @ref ae_uchar32_t, который представляет собой 32-битное беззнаковое целое число.
 *
 * @note Этот тип используется для представления широких символов с размером 32 бита.
 */
typedef ae_uchar32_t ae_wchar_t;
#    else
/**
 * @def AE_WCHAR_T_MIN
 * @brief Минимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_SCHAR32_T_MIN.
 */
#        define AE_WCHAR_T_MIN AE_SCHAR32_T_MIN

/**
 * @def AE_WCHAR_T_MAX
 * @brief Максимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_SCHAR32_T_MAX.
 */
#        define AE_WCHAR_T_MAX AE_SCHAR32_T_MAX

/**
 * @typedef ae_wchar_t
 * @brief Тип данных для широкого символа (32-битный).
 *
 * Тип @ref ae_wchar_t представляет собой 32-битный широкий символ, который может быть либо
 * знаковым, либо беззнаковым в зависимости от флага компиляции @ref AE_CHAR_UNSIGNED.
 *
 * - Если флаг @ref AE_CHAR_UNSIGNED не определён, то @ref ae_wchar_t является синонимом
 *   для типа @ref ae_schar32_t, который представляет собой 32-битное знаковое целое число.
 *
 * @note Этот тип используется для представления широких символов с размером 32 бита.
 */
typedef ae_schar32_t ae_wchar_t;
#    endif // AE_CHAR_UNSIGNED
#elif AE_WCHAR_T_SIZE == 2
#    ifdef AE_CHAR_UNSIGNED
/**
 * @def AE_WCHAR_T_MIN
 * @brief Минимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_UCHAR16_T_MIN.
 */
#        define AE_WCHAR_T_MIN AE_UCHAR16_T_MIN

/**
 * @def AE_WCHAR_T_MAX
 * @brief Максимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_UCHAR16_T_MAX.
 */
#        define AE_WCHAR_T_MAX AE_UCHAR16_T_MAX

/**
 * @typedef ae_wchar_t
 * @brief Тип данных для широкого символа (16-битный).
 *
 * Тип @ref ae_wchar_t представляет собой 16-битный широкий символ, который может быть либо
 * знаковым, либо беззнаковым в зависимости от флага компиляции @ref AE_CHAR_UNSIGNED.
 *
 * - Если флаг @ref AE_CHAR_UNSIGNED определён, то @ref ae_wchar_t является синонимом
 *   для типа @ref ae_uchar16_t, который представляет собой 16-битное беззнаковое целое число.
 *
 * @note Этот тип используется для представления широких символов с размером 16 бита.
 */
typedef ae_uchar16_t ae_wchar_t;
#    else
/**
 * @def AE_WCHAR_T_MIN
 * @brief Минимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает минимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_SCHAR16_T_MIN.
 */
#        define AE_WCHAR_T_MIN AE_SCHAR16_T_MIN

/**
 * @def AE_WCHAR_T_MAX
 * @brief Максимальное значение для типа AE_WCHAR_T.
 *
 * Этот макрос задает максимальное значение для типа данных AE_WCHAR_T.
 * Он эквивалентен значению макроса AE_SCHAR16_T_MAX.
 */
#        define AE_WCHAR_T_MAX AE_SCHAR16_T_MAX

/**
 * @typedef ae_wchar_t
 * @brief Тип данных для широкого символа (16-битный).
 *
 * Тип @ref ae_wchar_t представляет собой 16-битный широкий символ,
 * который может быть либо знаковым, либо беззнаковым в зависимости
 * от флага компиляции @c AE_CHAR_UNSIGNED.
 *
 * - Если флаг @c AE_CHAR_UNSIGNED не определён, то @ref ae_wchar_t является синонимом
 *   для типа @ref ae_schar16_t, который представляет собой 16-битное знаковое целое число.
 *
 * @note Этот тип используется для представления широких символов с размером 16 бит.
 */
typedef ae_schar16_t ae_wchar_t;
#    endif // AE_CHAR_UNSIGNED
#else
#    error "Unknown size for AE_WCHAR_T_SIZE"
#endif // AE_WCHAR_T_SIZE

#endif // AE_WCHAR_H
