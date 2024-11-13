/**
 * @file runtime_allocator.h
 * @brief Заголовочный файл для функции получения локального
 *        для потока распределителя памяти времени выполнения.
 *
 * Этот файл содержит функцию `ae_runtime_allocator`, которая возвращает указатель
 * на локальный для потока распределитель памяти времени выполнения.
 *
 * Этот распределитель инициализируется с помощью функций стандартной библиотеки,
 * если определена `AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB`.
 */

#ifndef AE_RUNTIME_ALLOCATOR_H
#define AE_RUNTIME_ALLOCATOR_H

#include "memory_allocator.h"

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Возвращает указатель на локальный
 *        для потока распределитель памяти времени выполнения.
 *
 * Эта функция возвращает указатель на глобальную переменную `m_runtime_allocator`,
 * которая представляет собой локальный для потока экземпляр структуры `ae_memory_allocator`.
 * Этот распределитель инициализируется с помощью функций стандартной библиотеки,
 * если определена `AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB`.
 *
 * @return Указатель на локальный
 *         для потока распределитель памяти времени выполнения.
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_allocator_t *
ae_runtime_allocator();

AE_COMPILER(EXTERN_C_END)

#endif // AE_RUNTIME_ALLOCATOR_H
