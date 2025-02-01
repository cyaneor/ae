/**
 * @file unified_block.h
 * @brief Заголовочный файл для работы с унифицированными блоками памяти,
 *        учитывающими выравнивание.
 *
 * Этот файл определяет тип `ae_unified_block_t`,
 * который является синонимом для типа `ae_aligned_block_t`.
 *
 * Он предоставляет интерфейсы для работы с памятью с учётом выравнивания,
 * включая функции для очистки, обмена содержимого и изменения размера
 * блока памяти в зависимости от выравнивания.
 *
 * Для операций с памятью используются
 * две основные категории блоков:
 * - Выровненные блоки памяти.
 * - Не выровненные (обычные) блоки памяти.
 *
 * В зависимости от выравнивания блоков,
 * соответствующие функции автоматически выбирают оптимальные методы работы с памятью.
 *
 * @see ae_aligned_block_t
 * @see ae_aligned_block_clear
 * @see ae_aligned_block_exchange
 * @see ae_aligned_block_resize
 */

#ifndef AE_UNIFIED_BLOCK_H
#define AE_UNIFIED_BLOCK_H

#include "aligned_block.h"

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
 * @brief Очищает блок памяти, в зависимости от его выравнивания.
 *
 * Эта функция очищает и освобождает память, выделенную для блока памяти.
 * В зависимости от выравнивания блока, функция вызывает одну из двух
 * функций для очистки: `ae_aligned_range_clear` для выровненных блоков
 * памяти и `ae_allocated_range_clear` для обычных выделенных блоков памяти.
 *
 * - Если блок выровнен, вызывается функция `ae_aligned_range_clear`.
 * - Если блок не выровнен, вызывается функция `ae_allocated_range_clear`.
 *
 * Функция сначала проверяет выравнивание блока с помощью функции
 * `ae_aligned_block_get_alignment_size`, а затем решает,
 * какую функцию очистки вызвать.
 *
 * @param self Указатель на блок памяти,
 *             который необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_ALIGNMENT
 *        Если выравнивание блока памяти некорректно.
 *
 * @see ae_aligned_range_clear
 * @see ae_allocated_range_clear
 * @see ae_aligned_block_get_alignment_size
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_unified_block_clear(void *self);

/**
 * @brief Обменивает содержимое двух блоков памяти, в зависимости от их выравнивания.
 *
 * Эта функция обменивает содержимое двух блоков памяти. В зависимости от выравнивания
 * блоков, функция вызывает одну из двух функций обмена: `ae_aligned_block_exchange`
 * для выровненных блоков памяти и `ae_allocated_block_exchange`
 * для обычных выделенных блоков памяти.
 *
 * Функция сначала проверяет выравнивание первого блока с помощью функции
 * `ae_aligned_block_get_alignment_size`. Если блок выровнен, вызывается функция обмена
 * для выровненных блоков. Если блок не выровнен, вызывается функция обмена для обычных блоков.
 *
 * @param[in,out] self Указатель на первый блок памяти, который необходимо обменять.
 *                     Тип блока определяется через выравнивание.
 * @param[in,out] other Указатель на второй блок памяти, с которым будет произведен обмен.
 *                      Тип блока также определяется через выравнивание.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `null`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @see ae_aligned_block_exchange
 * @see ae_allocated_block_exchange
 * @see ae_aligned_block_get_alignment_size
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_unified_block_exchange(void *self, void *other);

/**
 * @brief Изменяет размер блока памяти в зависимости от его выравнивания.
 *
 * Эта функция изменяет размер блока памяти,
 * представленного указателем `self`, в зависимости от выравнивания.
 *
 * - Если блок памяти выровнен, используется функция
 *   `ae_aligned_block_resize` для изменения размера выровненного блока.
 * - Если блок не выровнен, вызывается функция
 *   `ae_allocated_block_resize` для изменения размера выделенного блока памяти.
 *
 * Функция сначала проверяет выравнивание блока с помощью `ae_aligned_block_get_alignment_size`.
 * После этого она передает управление соответствующей функции изменения размера блока
 * в зависимости от выравнивания.
 *
 * @param[in,out] self Указатель на блок памяти, размер которого нужно изменить.
 *                     Тип блока определяется через выравнивание.
 * @param[in] number_of_elements Новое количество элементов в блоке памяти.
 *                               Это значение используется для расчета нового размера блока.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_EXCEEDS_MAX_SIZE
 *        Если новый размер блока превышает максимально допустимый размер.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить новую память.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @see ae_aligned_block_resize
 * @see ae_allocated_block_resize
 * @see ae_aligned_block_get_alignment_size
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_unified_block_resize(void *self, ae_usize_t number_of_elements);

AE_COMPILER(EXTERN_C_END)

#endif // AE_UNIFIED_BLOCK_H
