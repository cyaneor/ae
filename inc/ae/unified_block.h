/**
 * @file unified_block.h
 * @brief Заголовочный файл для работы с унифицированными блоками памяти.
 *
 * Этот файл содержит определения и функции для работы с унифицированными
 * блоками памяти, которые используют выравнивание для оптимизации
 * перераспределения памяти.
 *
 * Он предоставляет функции для очистки и  изменения размера унифицированных блоков,
 * а также определяет тип @ref ae_unified_block_t, который является синонимом для
 * @ref ae_aligned_block_t.
 *
 * Основные функции:
 * - ae_unified_block_clear: Очищает унифицированный блок памяти.
 * - ae_unified_block_resize: Изменяет размер унифицированного блока.
 *
 * @note В зависимости от выравнивания блока, функции могут использовать
 *       разные методы очистки и изменения размера, что позволяет
 *       эффективно управлять памятью.
 */

#ifndef AE_UNIFIED_BLOCK_H
#define AE_UNIFIED_BLOCK_H

#include "aligned_block.h"
#include "attribute.h"

/**
 * @typedef ae_unified_block_t
 * @brief Синоним для типа ae_aligned_block_t.
 *
 * Этот синоним специально создан для двухнаправленной работы перераспределения памяти.
 * Он позволяет автоматически определять и использовать оптимальный метод
 * перераспределения в зависимости от выравнивания.
 */
typedef ae_aligned_block_t ae_unified_block_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Очищает унифицированный блок памяти.
 *
 * Эта функция очищает унифицированный блок памяти, указанный в параметре `self`.
 * Она вызывает функцию изменения размера @ref ae_unified_block_resize с аргументом 0,
 * что приводит к освобождению всех ресурсов, занимаемых блоком.
 *
 * @param self Указатель на структуру @ref ae_unified_block_t,
 *             которую необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @note Данная функция является удобным способом освобождения памяти,
 *       выделенной для унифицированного блока, без необходимости
 *       прямого вызова функции изменения размера с нулевым значением.
 *
 * @see ae_unified_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_unified_block_clear(ae_unified_block_t *self);

/**
 * @brief Изменяет размер унифицированного блока.
 *
 * Эта функция изменяет размер унифицированного блока,
 * переданного в качестве аргумента.
 *
 * - Если выравнивание блока является единичным,
 *   используется функция `ae_aligned_block_resize`.
 * - В противном случае вызывается `ae_allocated_block_resize`
 *   для изменения размера выделенного блока.
 *
 * @param self Указатель на унифицированный блок,
 *             размер которого необходимо изменить.
 *
 * @param number_of_elements Новое количество элементов,
 *                           на которое нужно изменить размер блока.
 *
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `null`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если память не удалось выделить.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *         Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_ARGUMENT
 *        Если указатель `begin` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_aligned_block_resize
 * @see ae_allocated_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_unified_block_resize(ae_unified_block_t *self, ae_usize_t number_of_elements);

AE_COMPILER(EXTERN_C_END)

#endif // AE_UNIFIED_BLOCK_H
