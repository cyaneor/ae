/**
 * @file memory_range_initializer.h
 * @brief Заголовочный файл с макросами для инициализации диапазонов памяти.
 *
 * Этот файл содержит макросы для инициализации диапазонов памяти,
 * которые служат основой для более специализированных макросов инициализации.
 * Он предоставляет простой и гибкий способ определения границ памяти с
 * возможностью передачи дополнительных параметров инициализации.
 *
 * Основные макросы, определенные в этом файле:
 * - ae_memory_range_initializer: базовый макрос для инициализации диапазона памяти
 * - ae_memory_range_empty_initializer: макрос для инициализации пустого диапазона памяти
 *
 * Особенности макросов:
 * - Поддержка произвольного количества дополнительных параметров
 * - Гибкость в определении границ диапазона памяти
 * - Возможность инициализации пустого диапазона памяти
 * - Прямая интеграция с базовым макросом ae_initializer
 *
 * @note Этот файл предоставляет базовую функциональность для работы с
 *       диапазонами памяти и служит основой для создания более
 *       специализированных макросов инициализации.
 *
 * @see ae_initializer.h
 */

#ifndef AE_MEMORY_RANGE_INITIALIZER_H
#define AE_MEMORY_RANGE_INITIALIZER_H

#include "range_initializer.h"

/**
 * @def ae_memory_range_initializer
 * @brief Инициализация диапазона памяти с заданными границами.
 *
 * Этот макрос позволяет инициализировать диапазон памяти, задавая начальную точку (`begin`)
 * и конечную точку (`end`), а также произвольное количество дополнительных аргументов
 * для дальнейшей инициализации. Макрос вызывает другой макрос `ae_range_initializer`,
 * чтобы выполнить инициализацию диапазона с этими значениями и дополнительными параметрами.
 *
 * @param begin Начальная точка диапазона памяти (в указателе или адресе).
 * @param end Конечная точка диапазона памяти (в указателе или адресе).
 * @param ... Дополнительные аргументы инициализации,
 *            которые будут переданы в макрос `ae_range_initializer`.
 *
 * @note Убедитесь, что переданные значения `begin` и `end` корректны
 *       и соответствуют ожидаемым типам. Также будьте внимательны при
 *       использовании дополнительных аргументов, так как они передаются
 *       в макрос `ae_range_initializer`.
 *
 * Пример использования:
 * @code
 * ae_memory_range_initializer(0x1000, 0x2000, param1, param2);
 * @endcode
 */
#define ae_memory_range_initializer(begin, end, ...) ae_range_initializer(begin, end, __VA_ARGS__)

/**
 * @def ae_memory_range_empty_initializer
 * @brief Инициализация пустого диапазона памяти.
 *
 * Этот макрос позволяет инициализировать пустой диапазон памяти, устанавливая
 * начальную и конечную точки в `nullptr`. Он также принимает произвольное
 * количество дополнительных аргументов, которые могут быть использованы для
 * настройки объектов или структур, требующих указания диапазона памяти и
 * дополнительных параметров.
 *
 * @param ... Дополнительные аргументы инициализации,
 *            которые будут переданы в макрос ae_initializer.
 *
 * @note Используйте этот макрос, когда необходимо инициализировать
 *       диапазон памяти, но фактические границы не определены (т.е. пусты).
 *       Убедитесь, что дополнительные аргументы соответствуют ожидаемым
 *       типам в контексте использования.
 *
 * Пример использования:
 * @code
 * ae_memory_range_empty_initializer(param1, param2);
 * @endcode
 */
#define ae_memory_range_empty_initializer(...)                                                     \
    ae_memory_range_initializer(nullptr, nullptr, __VA_ARGS__)

#endif // AE_MEMORY_RANGE_INITIALIZER_H
