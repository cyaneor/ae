/**
 * @file interval_type.h
 * @brief Заголовочный файл, содержащий макрос
 *        для создания типа интервала с заданным именем и типом данных.
 *
 * Этот файл предоставляет макрос @ref ae_interval_type, который используется
 * для создания нового типа интервала с указанным именем и типом данных для границ интервала.
 *
 * Макрос создает тип с именем `N_t`, который является псевдонимом для структуры,
 * определенной с помощью макроса @ref ae_interval_struct(N, T).
 *
 * Структура интервала содержит два поля: одно для нижней границы интервала (`lower`)
 * и другое для верхней границы интервала (`upper`). Тип этих полей задается параметром `T`,
 * который может быть любым типом данных, например, `int`, `float`, `double` и другие.
 *
 * Макрос @ref ae_interval_type упрощает создание типов интервалов
 * с удобными именами и типами данных, что улучшает читаемость и поддержку кода.
 */

#ifndef AE_INTERVAL_TYPE_H
#define AE_INTERVAL_TYPE_H

#include "interval_struct.h"

/**
 * @def ae_interval_type(N, T)
 * @brief Макрос для создания типа интервала с заданным именем и типом данных.
 *
 * Этот макрос создает тип с именем `N_t`, который является псевдонимом для структуры,
 * созданной с помощью макроса @ref ae_interval_struct(N, T).
 *
 * Структура содержит два поля, представляющие интервал:
 * одно для нижней границы (`lower`) и другое для верхней границы (`upper`).
 *
 * @param N Имя типа, который будет использоваться для создания нового типа с суффиксом `_t`.
 * @param T Тип данных для границ интервала. Например, `int`, `float`, `double` и другие.
 *
 * @note Макрос позволяет создавать типы интервалов с удобными именами и типами данных,
 *       что улучшает читаемость и поддержку кода.
 *
 * Пример использования макроса:
 * @code
 * ae_interval_type(IntInterval, int);
 *
 * IntInterval_t interval;
 * interval.lower = 0;
 * interval.upper = 10;
 * @endcode
 */
#define ae_interval_type(N, T) typedef ae_interval_struct(N, T) N##_t

#endif // AE_INTERVAL_TYPE_H
