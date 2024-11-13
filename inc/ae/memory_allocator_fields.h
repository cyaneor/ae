/**
 * @file memory_allocator_fields.h
 * @brief Заголовочный файл для определения полей аллокатора памяти.
 *
 * Этот файл содержит макрос, который определяет поля,
 * необходимые для реализации аллокатора памяти.
 *
 * Поля включают указатели на функции выделения и освобождения памяти,
 * которые могут быть использованы для управления памятью
 * в пользовательских структурах.
 *
 * @note Убедитесь, что функции, на которые указывают указатели,
 *       корректно реализованы и соответствуют прототипам,
 *       определенным в соответствующих типах.
 *
 * @see ae_memory_allocator_alloc_t
 * @see ae_memory_allocator_free_t
 */

#ifndef AE_MEMORY_ALLOCATOR_FIELDS_H
#define AE_MEMORY_ALLOCATOR_FIELDS_H

#include "memory_allocator_alloc.h"
#include "memory_allocator_free.h"
#include "initializer.h"

/**
 * @def AE_MEMORY_ALLOCATOR_FIELDS
 * @brief Макрос для определения полей аллокатора памяти.
 *
 * Этот макрос определяет два поля для структуры аллокатора памяти:
 * - Указатель на функцию выделения памяти (alloc).
 * - Указатель на функцию освобождения памяти (free).
 *
 * Поля должны быть инициализированы соответствующими
 * функциями перед использованием аллокатора.
 */
#define AE_MEMORY_ALLOCATOR_FIELDS                                                                 \
    ae_memory_allocator_alloc_t *alloc;                                                            \
    ae_memory_allocator_free_t  *free

#endif // AE_MEMORY_ALLOCATOR_FIELDS_H
