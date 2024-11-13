/**
 * @file memory_allocator_initializer.h
 * @brief Заголовочный файл для инициализации аллокатора памяти.
 *
 * Этот файл содержит макрос для инициализации структуры аллокатора памяти,
 * который позволяет задавать пользовательские функции для выделения и освобождения памяти.
 *
 * @note Убедитесь, что указанные функции выделения и освобождения памяти
 *       корректно реализованы и совместимы с используемым аллокатором.
 */

#ifndef AE_MEMORY_ALLOCATOR_INITIALIZER_H
#define AE_MEMORY_ALLOCATOR_INITIALIZER_H

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
    ae_initializer((ae_memory_allocator_alloc_t *)alloc_fn, (ae_memory_allocator_free_t *)free_fn)

#endif // AE_MEMORY_ALLOCATOR_INITIALIZER_H
