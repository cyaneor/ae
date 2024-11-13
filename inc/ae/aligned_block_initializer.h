/**
 * @file aligned_block_initializer.h
 * @brief Заголовочный файл с макросами для инициализации выровненных блоков памяти.
 *
 * Этот файл содержит макросы для инициализации и работы с выровненными блоками
 * памяти. Он предоставляет специализированные обертки над базовыми макросами
 * инициализации блоков памяти, адаптированные для работы с выровненной памятью.
 *
 * Основные макросы, определенные в этом файле:
 * - ae_aligned_block_initializer: для инициализации выровненного блока памяти
 * - ae_aligned_block_empty_initializer: для инициализации пустого выровненного блока
 *
 * Особенности макросов:
 * - Поддержка настраиваемого выравнивания памяти
 * - Типобезопасная инициализация блоков с учетом размера элемента
 * - Возможность создания как заполненных, так и пустых блоков
 *
 * Типичное использование:
 * @code{.c}
 * // Инициализация выровненного блока
 * void* aligned_memory = aligned_alloc(16, 1024);
 * struct AlignedBlock block =
 *     ae_aligned_block_initializer(aligned_memory,
 *                                 (char*)aligned_memory + 1024,
 *                                 sizeof(double),
 *                                 16);
 *
 * // Создание пустого выровненного блока
 * struct AlignedBlock empty_block =
 *     ae_aligned_block_empty_initializer(sizeof(double), 16);
 * @endcode
 *
 * @note Этот файл предназначен для использования в проектах, где требуется
 *       работа с выровненной памятью, например, для оптимизации SIMD-операций
 *       или соответствия аппаратным требованиям.
 *
 * @see memory_block_initializer.h
 * @see allocated_block_initializer.h
 */

#ifndef AE_AE_ALIGNED_BLOCK_INITIALIZER_H
#define AE_AE_ALIGNED_BLOCK_INITIALIZER_H

#include "allocated_block_initializer.h"

/**
 * @def ae_aligned_block_initializer
 * @brief Инициализация выровненного блока памяти.
 *
 * Этот макрос используется для создания и инициализации структуры,
 * представляющей выровненный блок памяти. Он является оберткой над макросом
 * ae_memory_block_initializer, специально предназначенной для работы с выровненными блоками памяти.
 *
 * @param begin Указатель на начало блока памяти.
 * @param end Указатель на конец блока памяти.
 * @param element_size Размер одного элемента в блоке памяти.
 * @param alignment_size Размер выравнивания для блока памяти.
 * @param ... Дополнительные аргументы, которые будут переданы в ae_memory_block_initializer.
 *
 * @note Выравнивание памяти может быть важно для оптимизации производительности
 *       или для соответствия требованиям определенных аппаратных архитектур.
 *
 * Пример использования:
 * @code{.c}
 * void* memory_start = ...;
 * void* memory_end = ...;
 * struct AlignedBlock block
 *     = ae_aligned_block_initializer(memory_start, memory_end, sizeof(double), 16);
 * @endcode
 *
 * @see ae_memory_block_initializer
 * @see ae_aligned_block_empty_initializer
 */
#define ae_aligned_block_initializer(begin, end, element_size, alignment_size, ...)                \
    ae_memory_block_initializer(begin, end, element_size, alignment_size, __VA_ARGS__)

/**
 * @def ae_aligned_block_empty_initializer
 * @brief Макрос для инициализации пустого выровненного блока памяти.
 *
 * Этот макрос создает инициализатор для структуры `ae_aligned_block`,
 * устанавливая начальный и конечный указатели в nullptr, и задавая
 * размер элемента и размер выравнивания.
 *
 * @param element_size Размер одного элемента в блоке памяти.
 * @param alignment_size Размер выравнивания для блока памяти.
 *
 * @return Возвращает инициализатор для структуры `ae_aligned_block`.
 *
 * @note Этот макрос использует `ae_aligned_block_initializer`
 *       для фактической инициализации структуры.
 *
 * @see ae_aligned_block
 * @see ae_aligned_block_initializer
 */
#define ae_aligned_block_empty_initializer(element_size, alignment_size)                           \
    ae_aligned_block_initializer(nullptr, nullptr, element_size, alignment_size)

#endif // AE_AE_ALIGNED_BLOCK_INITIALIZER_H
