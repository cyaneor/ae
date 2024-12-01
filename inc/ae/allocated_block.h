/**
 * @file allocated_block.h
 * @brief Заголовочный файл для работы с блоками выделенной памяти.
 *
 * Данный файл содержит определение структуры `ae_allocated_block`
 * и функции для управления блоками динамически выделенной памяти.
 *
 * Основной функционал включает в себя:
 * - Хранение информации о выделенном блоке памяти
 * - Управление размером блока памяти
 * - Отслеживание размера отдельных элементов в блоке
 *
 * @note Все операции с блоками памяти должны выполняться с учетом
 *       размера элементов и общего количества элементов в блоке.
 *
 * @warning При работе с функциями необходимо убедиться, что размер
 *          элемента не равен нулю и указатели корректны, чтобы
 *          избежать ошибок времени выполнения.
 *
 * @see ae_allocated_block
 * @see ae_allocated_block_resize
 */

#ifndef AE_ALLOCATED_BLOCK_H
#define AE_ALLOCATED_BLOCK_H

#include "memory_block.h"

/**
 * @typedef ae_allocated_block_t
 * @brief Тип для работы с выделенным блоком памяти.
 *
 * Этот тип является псевдонимом для `ae_memory_block_t` и используется
 * для явного указания, что блок памяти был динамически выделен.
 *
 * Структурно идентичен `ae_memory_block_t`, содержит те же поля для
 * хранения указателей на начало и конец блока памяти, а также размер элемента.
 *
 * @note Семантически отличается от `ae_memory_block_t` тем,
 *       что предполагает работу только с выделенной памятью.
 *
 * @see ae_memory_block_t
 * @see ae_memory_block
 */
typedef ae_memory_block_t ae_allocated_block_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает максимальный размер блока памяти,
 *        который может быть выделен.
 *
 * Эта функция вычисляет максимальный размер, который может быть
 * выделен в блоке памяти, основываясь на размере элемента,
 * хранящегося в указанном блоке памяти.
 *
 * @param self Указатель на структуру @ref ae_allocated_block_t,
 *             из которой необходимо получить максимальный размер блока.
 *
 * @return Максимальный размер блока в байтах.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если размер элемента равен нулю.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_allocated_block_max_size(const ae_allocated_block_t *self);

/**
 * @brief Изменяет размер блока выделенной памяти.
 *
 * Эта функция изменяет размер блока выделенной памяти,
 * указанного в параметре `self`, на указанное количество элементов.
 * Если размер элемента равен нулю, будет вызвано исключение времени выполнения.
 *
 * @param self Указатель на структуру @ref ae_allocated_block_t,
 *             размер которой необходимо изменить.
 *
 * @param number_of_elements Новое количество элементов,
 *                           для которых нужно изменить размер блока памяти.
 *
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `null`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если память не удалось выделить.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_ARGUMENT
 *        Если указатель `begin` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_memory_block_element_size
 * @see ae_allocated_range_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_block_resize(ae_allocated_block_t *self, ae_usize_t number_of_elements);

/**
 * @brief Очищает блок выделенной памяти.
 *
 * Эта функция устанавливает размер блока выделенной памяти,
 * указанного в параметре `self`, в ноль, эффективно освобождая выделенную память.
 * После вызова этой функции блок больше не будет содержать никаких элементов.
 *
 * @param self Указатель на структуру @ref ae_allocated_block_t,
 *             который необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_allocated_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_block_clear(ae_allocated_block_t *self);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALLOCATED_BLOCK_H
