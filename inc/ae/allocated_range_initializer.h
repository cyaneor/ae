/**
 * @file allocated_range_initializer.h
 * @brief Заголовочный файл с макросами для инициализации выделенных диапазонов памяти.
 *
 * Этот файл содержит макросы для инициализации и работы с выделенными диапазонами памяти.
 * Он предоставляет удобные обертки над базовыми макросами инициализации диапазонов памяти,
 * специально адаптированные для работы с динамически выделенной памятью.
 *
 * Основные макросы, определенные в этом файле:
 * - ae_allocated_range_initializer: для инициализации выделенного диапазона памяти
 * - ae_allocated_range_empty_initializer: для инициализации пустого диапазона памяти
 *
 * Эти макросы обеспечивают типобезопасность и семантическую ясность при работе
 * с выделенными диапазонами памяти, что помогает предотвратить ошибки и улучшить
 * читаемость кода.
 *
 * @note Этот файл должен быть включен в проекты, которые работают с динамически
 *       выделенными диапазонами памяти и требуют их инициализации.
 *
 * @see ae_memory_range_initializer.h
 */

#ifndef AE_ALLOCATED_RANGE_INITIALIZER_H
#define AE_ALLOCATED_RANGE_INITIALIZER_H

#include "memory_range_initializer.h"
#include "nullptr.h"

/**
 * @def ae_allocated_range_initializer
 * @brief Инициализация выделенного диапазона памяти.
 *
 * Этот макрос является оберткой над `ae_memory_range_initializer` и используется
 * для инициализации выделенного диапазона памяти. Он позволяет задать начальную
 * и конечную точки диапазона, а также передать дополнительные аргументы инициализации.
 *
 * @param begin Начальная точка выделенного диапазона памяти.
 * @param end Конечная точка выделенного диапазона памяти.
 * @param ... Дополнительные аргументы инициализации,
 *            которые будут переданы в макрос ae_memory_range_initializer.
 *
 * @note Этот макрос предназначен для использования с выделенными диапазонами памяти.
 *       Убедитесь, что переданные значения begin и end корректны и соответствуют
 *       границам выделенной памяти.
 *
 * @see ae_memory_range_initializer
 *
 * Пример использования:
 * @code
 * ae_allocated_range_initializer(allocated_memory, allocated_memory + size, param1, param2);
 * @endcode
 */
#define ae_allocated_range_initializer(begin, end, ...)                                            \
    ae_memory_range_initializer(begin, end, __VA_ARGS__)

/**
 * @def ae_allocated_range_empty_initializer
 * @brief Инициализация пустого диапазона памяти с использованием нулевых указателей.
 *
 * Этот макрос является сокращенной формой вызова @ref ae_allocated_range_initializer
 * с нулевыми указателями (nullptr) для начала и конца диапазона. Он используется
 * для инициализации пустого диапазона памяти или когда границы диапазона
 * неизвестны на момент инициализации.
 *
 * Макрос разворачивается в вызов:
 * @code{.c}
 * ae_allocated_range_initializer(nullptr, nullptr)
 * @endcode
 *
 * @note Этот макрос полезен в ситуациях, когда нужно инициализировать пустой
 *       диапазон памяти или когда границы диапазона будут установлены позже.
 *
 * Пример использования:
 * @code{.c}
 * some_function(ae_allocated_range_empty_initializer);
 * @endcode
 *
 * @see ae_allocated_range_initializer
 * @see ae_memory_range_initializer
 */
#define ae_allocated_range_empty_initializer(...)                                                  \
    ae_allocated_range_initializer(nullptr, nullptr, __VA_ARGS__)

#endif // AE_ALLOCATED_RANGE_INITIALIZER_H
