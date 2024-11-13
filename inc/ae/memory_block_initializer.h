/**
 * @file memory_block_initializer.h
 * @brief Заголовочный файл с макросами для инициализации блоков памяти.
 *
 * Этот файл содержит макросы для инициализации структур, представляющих
 * блоки памяти. Он предоставляет удобный способ создания и инициализации
 * блоков памяти с дополнительной семантической информацией.
 *
 * Основные макросы, определенные в этом файле:
 * - ae_memory_block_initializer: для инициализации блока памяти.
 * - ae_memory_block_empty_initializer: для инициализации пустого блока памяти.
 *
 * Особенности макросов:
 * - ae_memory_block_initializer:
 *   обертка над ae_memory_range_initializer с добавленной семантикой блока памяти.
 * - ae_memory_block_empty_initializer:
 *   позволяет инициализировать блок памяти без использования реальной памяти.
 * - Поддержка указания размера элемента в блоке.
 * - Возможность передачи дополнительных параметров инициализации.
 *
 * Типичное использование:
 * @code{.c}
 * int* data = malloc(100 * sizeof(int));
 * struct MemoryBlock block = ae_memory_block_initializer(data, data + 100, sizeof(int));
 * struct MemoryBlock empty_block = ae_memory_block_empty_initializer(sizeof(int));
 * @endcode
 *
 * @note Этот файл является частью системы управления памятью и тесно
 *       связан с другими компонентами, такими как ae_memory_range_initializer.
 *
 * @see ae_memory_range_initializer.h
 */

#ifndef AE_MEMORY_BLOCK_INITIALIZER_H
#define AE_MEMORY_BLOCK_INITIALIZER_H

#include "memory_range_initializer.h"

/**
 * @def ae_memory_block_initializer
 * @brief Инициализация блока памяти.
 *
 * Этот макрос используется для создания и инициализации структуры,
 * представляющей блок памяти.
 *
 * Он является оберткой над макросом ae_memory_range_initializer,
 * добавляя семантику блока памяти.
 *
 * @param begin Указатель на начало блока памяти.
 * @param end Указатель на конец блока памяти (за последним элементом).
 * @param element_size Размер одного элемента в блоке памяти.
 * @param ... Дополнительные аргументы, которые будут переданы в ae_memory_range_initializer.
 *
 * @note Этот макрос позволяет инициализировать блок памяти с дополнительными
 *       параметрами, которые могут быть определены в ae_memory_range_initializer.
 *
 * Пример использования:
 * @code
 * int* data = malloc(100 * sizeof(int));
 * struct MemoryBlock block = ae_memory_block_initializer(data, data + 100, sizeof(int));
 * @endcode
 *
 * @see ae_memory_range_initializer
 */
#define ae_memory_block_initializer(begin, end, element_size, ...)                                 \
    ae_memory_range_initializer(begin, end, element_size, __VA_ARGS__)

/**
 * @def ae_memory_block_empty_initializer
 * @brief Инициализация пустого блока памяти.
 *
 * Этот макрос используется для создания и инициализации структуры,
 * представляющей пустой блок памяти.
 *
 * Он является оберткой над макросом ae_memory_block_initializer,
 * устанавливая указатели на начало и конец блока памяти в NULL.
 *
 * @param element_size Размер одного элемента в блоке памяти.
 * @param ... Дополнительные аргументы, которые будут переданы в ae_memory_block_initializer.
 *
 * @note Использование этого макроса позволяет
 *       инициализировать блок памяти без указания реальной памяти,
 *       что может быть полезно для создания пустых или неинициализированных блоков.
 *
 * Пример использования:
 * @code
 * struct MemoryBlock empty_block = ae_memory_block_empty_initializer(sizeof(int));
 * @endcode
 *
 * @see ae_memory_block_initializer
 */
#define ae_memory_block_empty_initializer(element_size, ...)                                       \
    ae_memory_block_initializer(nullptr, nullptr, element_size, __VA_ARGS__)

#endif // AE_MEMORY_BLOCK_INITIALIZER_H
