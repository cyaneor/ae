#include <ae/runtime_allocator.h>
/* Дополнительные модули */
#include <ae/memory_allocator_initializer.h>

/**
 * @brief Определяет локальный для потока распределитель памяти времени выполнения,
 *        при необходимости инициализируемый с помощью функций стандартной библиотеки.
 *
 * Этот код определяет глобальную переменную `m_runtime_allocator`
 * как локальный для потока экземпляр структуры `ae_memory_allocator`.
 *
 * Инициализация распределителя зависит от того,
 * определена ли `AE_LIBRARY_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB`:
 *
 * - Если `AE_LIBRARY_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB` определена,
 *   распределитель инициализируется с использованием функции `malloc`
 *   стандартной библиотеки для выделения памяти и `free` для освобождения памяти.
 *
 * - Если `AE_LIBRARY_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB` не определена,
 *   функции выделения и освобождения памяти инициализируются значением `nullptr`.
 *
 * Это обеспечивает гибкость в конфигурации распределителя времени выполнения,
 * поддерживая как стандартные, так и пользовательские стратегии управления памятью.
 *
 * @note Распределитель помечен как `THREAD_LOCAL`, это означает,
 *        что каждый поток будет иметь свой собственный экземпляр
 *        `m_runtime_allocator`.
 */
#ifdef AE_LIBRARY_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB
#    include <stdlib.h>

AE_ATTRIBUTE(THREAD_LOCAL)
ae_memory_allocator_t m_runtime_allocator = ae_memory_allocator_initializer(malloc, free);
#else
AE_ATTRIBUTE(THREAD_LOCAL)
ae_memory_allocator_t m_runtime_allocator = ae_memory_allocator_empty_initializer();
#endif // AE_LIBRARY_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB

ae_memory_allocator_t *
ae_runtime_allocator()
{
    return &m_runtime_allocator;
}