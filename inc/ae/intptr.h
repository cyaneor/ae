/**
 * @file intptr.h
 * @brief Определения и типы для работы с указателями.
 *
 * Этот файл содержит определения макросов и типов, которые используются
 * для работы с указателями как для знаковых, так и для беззнаковых типов.
 * Типы и макросы зависят от разрядности системы.
 *
 * Основные компоненты:
 * - Макросы для минимальных, максимальных значений и размера типов.
 * - Типы `ae_uintptr_t` и `ae_sintptr_t`, которые являются синонимами
 *   для типов `ae_uaddr_t` и `ae_saddr_t` соответственно.
 */

#ifndef AE_INTPTR_H
#define AE_INTPTR_H

#include "addr.h"

/**
 * @def AE_UINTPTR_T_MIN
 * @brief Минимальное значение для типа `ae_uintptr_t`.
 *
 * Этот макрос определяет минимальное значение для типа `ae_uintptr_t`,
 * эквивалентного `ae_uaddr_t`. Значение берется из макроса `AE_UADDR_T_MIN`.
 */
#define AE_UINTPTR_T_MIN AE_UADDR_T_MIN

/**
 * @def AE_UINTPTR_T_MAX
 * @brief Максимальное значение для типа `ae_uintptr_t`.
 *
 * Этот макрос определяет максимальное значение для типа `ae_uintptr_t`,
 * эквивалентного `ae_uaddr_t`. Значение берется из макроса `AE_UADDR_T_MAX`.
 */
#define AE_UINTPTR_T_MAX AE_UADDR_T_MAX

/**
 * @def AE_UINTPTR_T_SIZE
 * @brief Размер типа `ae_uintptr_t` в байтах.
 *
 * Этот макрос определяет размер типа `ae_uintptr_t`,
 * эквивалентного `ae_uaddr_t`, с использованием макроса `AE_UADDR_T_SIZE`.
 */
#define AE_UINTPTR_T_SIZE AE_UADDR_T_SIZE

/**
 * @typedef ae_uintptr_t
 * @brief Тип для представления беззнаковых указателей.
 *
 * Этот тип является синонимом для типа `ae_uaddr_t` и используется для работы
 * с беззнаковыми указателями. Размер типа определяется разрядностью системы.
 */
typedef ae_uaddr_t ae_uintptr_t;

/**
 * @def AE_SINTPTR_T_MIN
 * @brief Минимальное значение для типа `ae_sintptr_t`.
 *
 * Этот макрос определяет минимальное значение для типа `ae_sintptr_t`,
 * эквивалентного `ae_saddr_t`. Значение берется из макроса `AE_SADDR_T_MIN`.
 */
#define AE_SINTPTR_T_MIN AE_SADDR_T_MIN

/**
 * @def AE_SINTPTR_T_MAX
 * @brief Максимальное значение для типа `ae_sintptr_t`.
 *
 * Этот макрос определяет максимальное значение для типа `ae_sintptr_t`,
 * эквивалентного `ae_saddr_t`. Значение берется из макроса `AE_SADDR_T_MAX`.
 */
#define AE_SINTPTR_T_MAX AE_SADDR_T_MAX

/**
 * @def AE_SINTPTR_T_SIZE
 * @brief Размер типа `ae_sintptr_t` в байтах.
 *
 * Этот макрос определяет размер типа `ae_sintptr_t`,
 * эквивалентного `ae_saddr_t`, с использованием макроса `AE_SADDR_T_SIZE`.
 */
#define AE_SINTPTR_T_SIZE AE_SADDR_T_SIZE

/**
 * @typedef ae_sintptr_t
 * @brief Тип для представления знаковых указателей.
 *
 * Этот тип является синонимом для типа `ae_saddr_t` и используется для работы
 * с знаковыми указателями. Размер типа определяется разрядностью системы.
 */
typedef ae_saddr_t ae_sintptr_t;

#endif // AE_INTPTR_H
