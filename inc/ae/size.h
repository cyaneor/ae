/**
 * @file size.h
 * @brief Определяет типы ae_ssize_t и ae_usize_t с их минимальными и максимальными значениями,
 *        зависящими от архитектуры и размера типа ae_size_t.
 *
 * Этот заголовочный файл предоставляет типы со знаковыми и беззнаковыми размерами,
 * а также их предельные значения для поддержки различий в архитектуре и конфигурациях компиляции.
 * Файл использует макросы для управления различиями между сегментированной и линейной
 * архитектурами.
 */

#ifndef AE_SIZE_H
#define AE_SIZE_H

#include "intptr.h"

#ifdef AE_LIBRARY_OPTION_SEGMENTED_ARCH
/**
 * @def AE_LIBRARY_OPTION_SEGMENTED_ARCH
 * @brief Включает поддержку сегментированной архитектуры.
 *
 * Если определено, настройки зависят
 * от конкретного размера типа ae_size_t.
 */

#    ifdef AE_SIZE_T_SIZE
/**
 * @def AE_SIZE_T_SIZE
 * @brief Определяет размер типа ae_size_t для выбора подходящего типа данных.
 *
 * Должно быть установлено в одно из значений: 8, 4 или 2,
 * чтобы указать на соответствующий размер ae_size_t в байтах.
 */

#        if AE_SIZE_T_SIZE == 8

/** @brief Минимальное значение для знакового размера (8 байт). */
#            define AE_SSIZE_T_MIN AE_S64_MIN
/** @brief Максимальное значение для знакового размера (8 байт). */
#            define AE_SSIZE_T_MAX AE_S64_MAX
/** @brief Минимальное значение для беззнакового размера (8 байт). */
#            define AE_USIZE_T_MIN AE_U64_MIN
/** @brief Максимальное значение для беззнакового размера (8 байт). */
#            define AE_USIZE_T_MAX AE_U64_MAX

/**
 * @typedef ae_usize_t
 * @brief Беззнаковый тип для хранения размера данных,
 *        определенного для 64-битных архитектур.
 */
typedef u64_t ae_usize_t;

/**
 * @typedef ae_ssize_t
 * @brief Знаковый тип для хранения размера данных,
 *        определенного для 64-битных архитектур.
 */
typedef s64_t ae_ssize_t;

#        elif AE_SIZE_T_SIZE == 4

/** @brief Минимальное значение для знакового размера (4 байта). */
#            define AE_SSIZE_T_MIN AE_S32_MIN
/** @brief Максимальное значение для знакового размера (4 байта). */
#            define AE_SSIZE_T_MAX AE_S32_T_MAX
/** @brief Минимальное значение для беззнакового размера (4 байта). */
#            define AE_USIZE_T_MIN AE_U32_T_MIN
/** @brief Максимальное значение для беззнакового размера (4 байта). */
#            define AE_USIZE_T_MAX AE_U32_T_MAX

/**
 * @typedef ae_usize_t
 * @brief Беззнаковый тип для хранения размера данных,
 *        определенного для 32-битных архитектур.
 */
typedef u32_t ae_usize_t;

/** @typedef ae_ssize_t
 *  @brief Знаковый тип для хранения размера данных,
 *         определенного для 32-битных архитектур.
 */
typedef s32_t ae_ssize_t;

#        elif AE_SIZE_T_SIZE == 2

/** @brief Минимальное значение для знакового размера (2 байта). */
#            define AE_SSIZE_T_MIN AE_S16_T_MIN
/** @brief Максимальное значение для знакового размера (2 байта). */
#            define AE_SSIZE_T_MAX AE_S16_T_MAX
/** @brief Минимальное значение для беззнакового размера (2 байта). */
#            define AE_USIZE_T_MIN AE_U16_T_MIN
/** @brief Максимальное значение для беззнакового размера (2 байта). */
#            define AE_USIZE_T_MAX AE_U16_T_MAX

/** @typedef ae_usize_t
 *  @brief Беззнаковый тип для хранения размера данных,
 *         определенного для 16-битных архитектур.
 */
typedef u16_t ae_usize_t;

/** @typedef ae_ssize_t
 *  @brief Знаковый тип для хранения размера данных,
 *         определенного для 16-битных архитектур.
 */
typedef s16_t ae_ssize_t;

#        else
/** @brief Ошибка компиляции при недопустимом значении AE_SIZE_T_SIZE. */
#            error "AE_SIZE_T_SIZE must be set to 8, 4, or 2"
#        endif

#    else
/** @brief Ошибка компиляции при отсутствии определения AE_SIZE_T_SIZE. */
#        error "AE_SIZE_T_SIZE is not defined"
#    endif

#else // AE_LIBRARY_OPTION_SEGMENTED_ARCH

/**
 * @def AE_SIZE_T_SIZE
 * @brief Размер типа ae_size_t совпадает с размером типа ae_intptr_t.
 */
#    define AE_SIZE_T_SIZE AE_INTPTR_T_SIZE

/** @brief Минимальное значение для знакового размера типа ae_intptr_t. */
#    define AE_SSIZE_T_MIN AE_SINTPTR_T_MIN

/** @brief Максимальное значение для знакового размера типа ae_intptr_t. */
#    define AE_SSIZE_T_MAX AE_SINTPTR_T_MAX

/** @brief Минимальное значение для беззнакового размера типа uintptr_t. */
#    define AE_USIZE_T_MIN AE_UINTPTR_T_MIN

/** @brief Максимальное значение для беззнакового размера типа uintptr_t. */
#    define AE_USIZE_T_MAX AE_UINTPTR_T_MAX

/** @typedef ae_usize_t
 *  @brief Беззнаковый тип для хранения размера данных,
 *         совпадающего с размером указателя.
 */
typedef ae_uintptr_t ae_usize_t;

/** @typedef ae_ssize_t
 *  @brief Знаковый тип для хранения размера данных,
 *         совпадающего с размером указателя.
 */
typedef ae_sintptr_t ae_ssize_t;

#endif // AE_LIBRARY_OPTION_SEGMENTED_ARCH

#endif // AE_SIZE_H
