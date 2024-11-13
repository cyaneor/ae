/**
 * @file interval_initializer.h
 * @brief Заголовочный файл, содержащий макрос
 *        для инициализации интервала с нижней и верхней границей.
 *
 * Этот файл предоставляет макрос @ref ae_interval_initializer, который используется
 * для инициализации интервала с двумя значениями: нижней границей и верхней границей.
 *
 * Макрос вызывает другой макрос, @ref ae_initializer,
 * для выполнения инициализации интервала с этими значениями.
 *
 * Макрос @ref ae_interval_initializer полезен для удобного создания интервалов,
 * особенно когда требуется быстро инициализировать объекты интервалов с различными границами.
 */

#ifndef AE_INTERVAL_INITIALIZER_H
#define AE_INTERVAL_INITIALIZER_H

#include "initializer.h"

/**
 * @def ae_interval_initializer(lower, upper)
 * @brief Макрос для инициализации интервала с нижней и верхней границей.
 *
 * Этот макрос используется для инициализации интервала с двумя значениями:
 * нижней границей `lower` и верхней границей `upper`.
 *
 * Он позволяет гибко инициализировать интервал, при этом возможно добавление дополнительных
 * аргументов, передаваемых через переменную длину (`...`), что позволяет работать с более
 * сложными структурами или объектами.
 *
 * @param lower Значение для нижней границы интервала.
 * @param upper Значение для верхней границы интервала.
 * @param ... Дополнительные аргументы, которые могут быть переданы макросу
 *            `ae_initializer`, если требуется более сложная инициализация.
 *
 * @note Данный макрос зависит от макроса @ref ae_initializer,
 *       который выполняет инициализацию объектов с аргументами переменной длины.
 *       Убедитесь, что переданные аргументы соответствуют ожидаемым типам и количеству.
 *
 * Пример использования:
 * @code
 * ae_interval_type(IntInterval, int);
 * IntInterval interval = ae_interval_initializer(0, 10);
 * @endcode
 */
#define ae_interval_initializer(lower, upper, ...) ae_initializer(lower, upper, __VA_ARGS__)

#endif // AE_INTERVAL_INITIALIZER_H
