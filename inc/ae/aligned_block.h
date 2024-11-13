/**
 * @file aligned_block.h
 * @brief Заголовочный файл для работы с выровненными блоками памяти.
 *
 * Данный файл содержит определение структуры `ae_aligned_block` и функции
 * для управления выровненными блоками памяти. Структура обеспечивает механизм
 * для работы с блоками памяти, выровненными по определенной границе, и
 * содержащими элементы фиксированного размера.
 *
 * Основной функционал включает в себя:
 * - Управление выровненными блоками памяти
 * - Получение информации о размере выравнивания
 * - Изменение размера блока с сохранением выравнивания
 * - Контроль размера элементов в блоке
 *
 * @note При работе с выровненными блоками важно учитывать как размер
 *       элементов, так и требования к выравниванию памяти.
 *
 * @warning Перед использованием функций необходимо проверить корректность
 *          размера элементов и выравнивания во избежание ошибок времени
 *          выполнения.
 *
 * @see ae_aligned_block
 * @see ae_aligned_block_alignment_size
 * @see ae_aligned_block_resize
 */

#ifndef AE_ALIGNED_BLOCK_H
#define AE_ALIGNED_BLOCK_H

#include "aligned_block_fields.h"
#include "attribute.h"
#include "bool.h"

/**
 * @struct ae_aligned_block_t
 * @brief Структура для представления выровненного блока памяти.
 *
 * Эта структура содержит информацию о выровненном блоке памяти,
 * включая указатели на начало и конец блока, размер элемента
 * и размер выравнивания.
 */
typedef struct ae_aligned_block
{
    AE_ALIGNED_BLOCK_FIELDS(void);
} ae_aligned_block_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает размер выравнивания блока памяти.
 *
 * Эта функция возвращает размер выравнивания для блока памяти,
 * определенного в структуре `ae_aligned_block`.
 *
 * @param self Указатель на структуру `ae_aligned_block`,
 *             из которой нужно получить размер выравнивания.
 *
 * @return Размер выравнивания блока памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_aligned_block
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_aligned_block_alignment_size(const ae_aligned_block_t *self);

/**
 * @brief Изменяет размер выровненного блока памяти.
 *
 * Эта функция изменяет размер блока памяти, связанного с объектом `self`,
 * на заданное количество элементов. Если размер элемента равен нулю,
 * будет сгенерировано исключение.
 *
 * @param self Указатель на объект `ae_aligned_block`,
 *             который нужно изменить.
 *
 * @param number_of_elements Новое количество элементов,
 *                           для которых необходимо выделить память.
 *
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `null`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если память не удалось выделить.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NOT_POWER_OF_TWO
 *        Если параметр alignment_size не является степенью двойки.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_aligned_block_alignment_size
 * @see ae_memory_block_element_size
 * @see ae_aligned_range_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_block_resize(ae_aligned_block_t *self, ae_usize_t number_of_elements);

/**
 * @brief Очищает выровненный блок выделенной памяти.
 *
 * Эта функция устанавливает размер выровненного блока выделенной памяти,
 * указанного в параметре `self`, в ноль, эффективно освобождая выделенную память.
 * После вызова этой функции блок больше не будет содержать никаких элементов.
 *
 * @param self Указатель на структуру @ref ae_aligned_block_t,
 *             который необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_aligned_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_block_clear(ae_aligned_block_t *self);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALIGNED_BLOCK_H
