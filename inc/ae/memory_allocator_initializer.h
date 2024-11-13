/**
 * @file memory_allocator_initializer.h
 * @brief Заголовочный файл для инициализации аллокатора памяти.
 *
 * Этот файл содержит макросы для инициализации структуры аллокатора памяти,
 * устанавливая указатели на функции выделения и освобождения памяти.
 *
 * @see ae_memory_allocator_initializer
 * @see ae_memory_allocator_empty_initializer
 */

#ifndef AE_MEMORY_ALLOCATOR_INITIALIZER_H
#define AE_MEMORY_ALLOCATOR_INITIALIZER_H

#include "nullptr.h"
#include "initializer.h"

/**
 * @def ae_memory_allocator_initializer
 * @brief Инициализирует структуру аллокатора памяти.
 *
 * Этот макрос создает и инициализирует экземпляр структуры аллокатора памяти,
 * устанавливая указатели на функции выделения и освобождения памяти.
 *
 * @param alloc_fn Указатель на функцию выделения памяти.
 * @param free_fn Указатель на функцию освобождения памяти.
 *
 * @return Инициализированная структура аллокатора памяти.
 *
 * @note Убедитесь, что указанные функции выделения и освобождения памяти
 *       корректно реализованы и совместимы с используемым аллокатором.
 */
#define ae_memory_allocator_initializer(alloc_fn, free_fn)                                         \
    ae_initializer((ae_memory_allocator_alloc_fn *)alloc_fn,                                       \
                   (ae_memory_allocator_dealloc_fn *)free_fn)

/**
 * @def ae_memory_allocator_empty_initializer
 * @brief Инициализирует пустой аллокатор памяти.
 *
 * Этот макрос создает и инициализирует экземпляр структуры аллокатора памяти,
 * устанавливая указатели на функции выделения и освобождения памяти в `nullptr`.
 *
 * @return Инициализированная структура пустого аллокатора памяти.
 *
 * @note Этот аллокатор не может быть использован для выделения памяти,
 *       поскольку функции выделения и освобождения памяти не определены.
 */
#define ae_memory_allocator_empty_initializer() ae_memory_allocator_initializer(nullptr, nullptr)

#endif // AE_MEMORY_ALLOCATOR_INITIALIZER_H
