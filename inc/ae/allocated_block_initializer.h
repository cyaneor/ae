/**
 * @file allocated_block_initializer.h
 * @brief Заголовочный файл с макросами для инициализации выделяемых блоков памяти.
 *
 * Этот файл содержит макросы для инициализации и работы с выделяемыми блоками памяти.
 * Он предоставляет специализированные обертки над базовыми макросами инициализации
 * блоков памяти, адаптированные для работы с динамически выделяемой памятью.
 *
 * Основные макросы, определенные в этом файле:
 * - ae_allocated_block_initializer: для инициализации выделяемого блока памяти
 * - ae_allocated_block_empty_initializer: для инициализации пустого выделяемого блока
 *
 * Макросы обеспечивают:
 * - Семантическую ясность при работе с выделяемыми блоками памяти
 * - Типобезопасную инициализацию блоков с учетом размера элемента
 * - Возможность создания как заполненных, так и пустых блоков
 *
 * @note Этот файл предназначен для использования в проектах, где требуется
 *       явное управление выделяемыми блоками памяти и необходима четкая
 *       семантическая разница между различными типами блоков памяти.
 *
 * @see ae_memory_block_initializer.h
 */

#ifndef AE_ALLOCATED_BLOCK_INITIALIZER_H
#define AE_ALLOCATED_BLOCK_INITIALIZER_H

#include "memory_block_initializer.h"

/**
 * @def ae_allocated_block_initializer
 * @brief Инициализация выделяемого блока памяти.
 *
 * Этот макрос является алиасом для ae_memory_block_initializer и используется
 * для инициализации структуры, представляющей выделяемый блок памяти.
 * Создаёт блок с заданными началом, концом и размером элемента.
 *
 * @param begin Указатель на начало блока памяти.
 * @param end Указатель на конец блока памяти.
 * @param element_size Размер одного элемента в блоке памяти.
 *
 * @note Семантически этот макрос предназначен
 *       для работы с динамически выделяемыми блоками памяти.
 *
 * Пример использования:
 * @code{.c}
 * struct AllocatedBlock block = ae_allocated_block_init(ptr, ptr + size, sizeof(int));
 * @endcode
 *
 * @see ae_memory_block_initializer
 */
#define ae_allocated_block_initializer(begin, end, element_size, ...)                              \
    ae_memory_block_initializer(begin, end, element_size, __VA_ARGS__)

/**
 * @def ae_allocated_block_empty_initializer
 * @brief Макрос для инициализации пустого выделяемого блока памяти.
 *
 * Этот макрос создает инициализатор для структуры, представляющей
 * выделяемый блок памяти, устанавливая начальный и конечный указатели
 * в nullptr и задавая размер элемента. Он является специализированной
 * версией ae_allocated_block_initializer для создания пустых блоков.
 *
 * @param element_size Размер одного элемента в блоке памяти.
 * @param ... Дополнительные аргументы (если есть),
 *            которые будут переданы в `ae_memory_block_initializer`.
 *
 * @return Возвращает инициализатор для структуры,
 *         представляющей выделяемый блок памяти.
 *
 * @note Этот макрос использует ae_memory_block_initializer
 *       для фактической инициализации структуры.
 *
 * @see ae_allocated_block_initializer
 * @see ae_memory_block_initializer
 */
#define ae_allocated_block_empty_initializer(element_size, ...)                                    \
    ae_allocated_block_initializer(nullptr, nullptr, element_size, __VA_ARGS__)

#endif // AE_ALLOCATED_BLOCK_INITIALIZER_H
