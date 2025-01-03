/**
 * @file memory_range_type.h
 * @brief Определение типов диапазонов памяти.
 *
 * Данный файл содержит определения макросов, представляющих различные типы диапазонов памяти,
 * которые могут быть использованы в контексте управления памятью, обработки данных и алгоритмов.
 *
 * Каждый тип диапазона определяет,
 * как границы диапазона включаются или исключаются при работе с памятью.
 *
 * Это может быть полезно при реализации функций, которые требуют точного определения диапазонов,
 * например, при выделении памяти, проверке границ или выполнении операций с массивами.
 */

#ifndef AE_MEMORY_RANGE_TYPE_H
#define AE_MEMORY_RANGE_TYPE_H

/**
 * @def AE_MEMORY_RANGE_TYPE_CLOSED
 * @brief Закрытый диапазон памяти [a, b].
 *
 * Включает оба конца диапазона.
 * Используется, когда необходимо учитывать как начальное, так и конечное значение.
 */
#define AE_MEMORY_RANGE_TYPE_CLOSED 0

/**
 * @def AE_MEMORY_RANGE_TYPE_LEFT_OPENED
 * @brief Левый полуоткрытый диапазон памяти [a, b).
 *
 * Включает начальное значение a, но исключает конечное значение b.
 * Применяется, когда важно учитывать начальную границу,
 * но конечная граница не должна быть включена.
 */
#define AE_MEMORY_RANGE_TYPE_LEFT_OPENED 1

/**
 * @def AE_MEMORY_RANGE_TYPE_RIGHT_OPENED
 * @brief Правый полуоткрытый диапазон памяти (a, b].
 *
 * Исключает начальное значение a, но включает конечное значение b.
 * Используется в случаях, когда начальная граница не должна учитываться,
 * но конечная граница важна.
 */
#define AE_MEMORY_RANGE_TYPE_RIGHT_OPENED 2

/**
 * @def AE_MEMORY_RANGE_TYPE_OPENED
 * @brief Открытый диапазон памяти (a, b).
 *
 * Исключает оба конца диапазона.
 * Применяется в ситуациях, когда ни начальное,
 * ни конечное значение не должны быть включены в диапазон.
 */
#define AE_MEMORY_RANGE_TYPE_OPENED 3

#endif // AE_MEMORY_RANGE_TYPE_H