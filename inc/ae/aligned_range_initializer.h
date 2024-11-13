/**
 * @file aligned_range_initializer.h
 * @brief Заголовочный файл с макросами для инициализации выровненных диапазонов памяти.
 *
 * Этот файл содержит макросы для инициализации и работы с выровненными диапазонами памяти.
 * Он предоставляет обертки над макросами инициализации выделенных диапазонов памяти,
 * специально адаптированные для работы с выровненной памятью.
 *
 * Основные макросы, определенные в этом файле:
 * - ae_aligned_range_initializer: для инициализации выровненного диапазона памяти
 * - ae_aligned_range_empty_initializer: для инициализации пустого выровненного диапазона памяти
 *
 * Эти макросы обеспечивают семантическую ясность при работе с выровненными диапазонами памяти,
 * что помогает улучшить читаемость кода и подчеркнуть намерение использовать выровненную память.
 *
 * @note Этот файл должен быть включен в проекты, которые работают с выровненными
 *       диапазонами памяти и требуют их инициализации. Фактическое выравнивание
 *       должно быть обеспечено при выделении памяти.
 *
 * @see ae_allocated_range_initializer.h
 * @see ae_memory_range_initializer.h
 */

#ifndef AE_ALIGNED_RANGE_INITIALIZER_H
#define AE_ALIGNED_RANGE_INITIALIZER_H

#include "allocated_range_initializer.h"

/**
 * @def ae_aligned_range_initializer
 * @brief Инициализация выровненного диапазона памяти.
 *
 * Этот макрос является оберткой для ae_allocated_range_initializer
 * и предназначен для инициализации диапазонов памяти
 * с учетом выравнивания.
 *
 * @param begin Указатель на начало диапазона. Используйте nullptr, если граница
 *              неизвестна.
 * @param end Указатель на конец диапазона. Используйте nullptr, если граница
 *            неизвестна.
 * @param ... Дополнительные аргументы инициализации,
 *            которые будут переданы в макрос ae_allocated_range_initializer.
 *
 * @note Семантически этот макрос указывает на то, что инициализируемый
 *       диапазон памяти должен учитывать требования выравнивания. Фактическое
 *       выравнивание должно быть обеспечено при последующем выделении памяти.
 *
 * Пример использования:
 * @code{.c}
 * ae_aligned_range_initializer(nullptr, nullptr, param1, param2);
 * @endcode
 *
 * @see ae_allocated_range_initializer
 */
#define ae_aligned_range_initializer(begin, end, ...)                                              \
    ae_allocated_range_initializer(begin, end, __VA_ARGS__)

/**
 * @def ae_aligned_range_empty_initializer
 * @brief Инициализация пустого выровненного диапазона памяти.
 *
 * Этот макрос является сокращенной формой вызова @ref ae_aligned_range_initializer
 * с нулевыми указателями (nullptr) для начала и конца диапазона. Используется
 * для инициализации пустого выровненного диапазона памяти или когда границы
 * диапазона неизвестны на момент инициализации.
 *
 * @param ... Дополнительные аргументы инициализации, которые будут переданы
 *            в макрос ae_aligned_range_initializer после нулевых указателей.
 *
 * @note Семантически этот макрос указывает на то, что инициализируемый
 *       диапазон памяти должен учитывать требования выравнивания. Фактическое
 *       выравнивание должно быть обеспечено при последующем выделении памяти.
 *
 * Макрос разворачивается в вызов:
 * @code{.c}
 * ae_aligned_range_initializer(nullptr, nullptr, ...)
 * @endcode
 *
 * Пример использования:
 * @code{.c}
 * ae_aligned_range_empty_initializer(param1, param2);
 * @endcode
 *
 * @see ae_aligned_range_initializer
 * @see ae_allocated_range_initializer
 */
#define ae_aligned_range_empty_initializer(...)                                                    \
    ae_aligned_range_initializer(nullptr, nullptr, __VA_ARGS__)

#endif // AE_ALIGNED_RANGE_INITIALIZER_H
