/**
 * @file range_fields.h
 * @brief Заголовочный файл, содержащий макрос для создания полей диапазона с заданным типом.
 *
 * Этот файл предоставляет макрос @ref AE_RANGE_FIELDS, который используется для создания полей
 * диапазона, представляющего интервал с двумя границами: нижней (`lower`) и верхней (`upper`).
 * Оба поля имеют тип `T`, который может быть любым типом данных, таким как `int`, `float`,
 * или другой.
 *
 * Диапазон представляет собой **закрытый интервал**, что означает, что обе границы интервала
 * включаются в диапазон. Например, интервал [a, b] включает как `a`, так и `b`.
 *
 * Макрос @ref AE_RANGE_FIELDS является оберткой для макроса @ref AE_INTERVAL_FIELDS,
 * что позволяет использовать этот макрос для создания структуры с полями для диапазона.
 */

#ifndef AE_RANGE_FIELDS_H
#define AE_RANGE_FIELDS_H

#include "interval_fields.h"

/**
 * @def AE_RANGE_FIELDS(T)
 * @brief Макрос для создания полей диапазона с заданным типом.
 *
 * Этот макрос генерирует два поля для представления диапазона:
 * одно для нижней границы интервала (`lower`) и другое для верхней границы интервала (`upper`).
 * Оба поля имеют тип `T`, который может быть любым типом данных, таким как `int`, `float`,
 * или другой.
 *
 * Диапазон представляет собой закрытый интервал, что означает, что обе границы интервала
 * включаются в диапазон. Например, интервал [a, b] включает как `a`, так и `b`. При этом
 * не следует использовать перечисление, представляющее различные типы закрытия интервала,
 * таких как `ae_interval_closure`.
 *
 * @param T Тип данных для границ интервала.
 *          Например, `int`, `float`, `double` и другие.
 *
 * @note Диапазон представляет собой закрытый интервал, поэтому обе границы включены.
 *       Не используйте перечисление `ae_interval_closure` для типов интервалов.
 *
 * Пример использования макроса:
 * @code
 * typedef struct {
 *     AE_RANGE_FIELDS(int)
 * } IntRange;
 *
 * IntRange range;
 * range.lower = 0;
 * range.upper = 10;
 * @endcode
 */
#define AE_RANGE_FIELDS(T) AE_INTERVAL_FIELDS(T)

#endif // AE_RANGE_FIELDS_H
