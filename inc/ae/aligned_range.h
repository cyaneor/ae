/**
 * @file aligned_range.h
 * @brief Заголовочный файл для работы с выровненными диапазонами памяти.
 *
 * Данный файл содержит определения структуры `ae_aligned_range` и функции для
 * управления выделением, очисткой, изменением размера и обменом содержимого
 * выровненных диапазонов памяти.
 *
 * Структура `ae_aligned_range` используется для представления диапазона памяти,
 * выровненного по определенной границе. Она предоставляет функционал для
 * эффективного управления выровненной памятью, включая выделение с заданным
 * выравниванием, освобождение ресурсов и изменение размеров выделенных блоков.
 *
 * @note Все функции, работающие с `ae_aligned_range`, требуют осторожного
 *       использования для предотвращения утечек памяти и обеспечения
 *       корректного выравнивания.
 *
 * @warning Перед использованием функций убедитесь, что указатели на
 *          `ae_aligned_range` не равны `null` и размер выравнивания
 *          соответствует требованиям системы.
 *
 * @see ae_aligned_range
 * @see ae_aligned_range_clear
 * @see ae_aligned_range_exchange
 * @see ae_aligned_range_resize
 */

#ifndef AE_ALIGNED_RANGE_H
#define AE_ALIGNED_RANGE_H

#include "allocated_range.h"

/**
 * @typedef ae_aligned_range_t
 * @brief Тип для работы с выровненным диапазоном памяти.
 *
 * Этот тип является псевдонимом для `ae_allocated_range_t` и используется
 * для явного указания, что диапазон памяти был выделен с учетом выравнивания.
 *
 * Структурно идентичен базовым типам `ae_allocated_range_t` и `ae_memory_range_t`,
 * содержит те же поля для хранения указателей на начало и конец диапазона памяти.
 *
 * @note Семантически отличается от `ae_allocated_range_t` тем,
 *       что гарантирует выравнивание выделенной памяти по определенной границе.
 *
 * @see ae_allocated_range_t
 * @see ae_memory_range_t
 * @see ae_memory_range
 */
typedef ae_allocated_range_t ae_aligned_range_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @def ae_aligned_range_clear
 * @brief Освобождает память, выделенную для выровненного диапазона.
 *
 * Эта функция очищает выделенный диапазон памяти,
 * связанный с заданным объектом структуры `ae_aligned_range`.
 *
 * Если память была выделена, она освобождается с использованием аллокатора,
 * поддерживающего выравнивание. После освобождения памяти, состояние
 * диапазона также очищается.
 *
 * @param self Указатель на объект `ae_aligned_range`,
 *             который нужно очистить.
 *
 * @note Если указатель на `self` равен `null`,
 *       функция не выполняет никаких действий.
 *
 * @see ae_memory_range_get_begin
 * @see ae_runtime_allocator_align_free
 * @see ae_memory_range_clear
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_range_clear(ae_aligned_range_t *self);

/**
 * @brief Обменивает содержимое двух выровненных диапазонов.
 *
 * Эта функция очищает текущий выровненный диапазон, связанный
 * с объектом `self`, и затем меняет его содержимое с содержимым
 * другого выровненного диапазона, переданного в качестве параметра `other`.
 *
 * @param self Указатель на объект `ae_aligned_range`,
 *             который будет очищен и обменян с другим диапазоном.
 *
 * @param other Указатель на объект `ae_aligned_range`, содержимое
 *              которого будет обменяно с содержимым объекта `self`.
 *
 * @warning Если в процессе обмена произошла ошибка,
 *          функция `ae_runtime_rethrow` пробросит её,
 *          распространяя любую возникшую ошибку.
 *
 * @see ae_aligned_range_clear
 * @see ae_memory_range_swap
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_range_exchange(ae_aligned_range_t *self, ae_aligned_range_t *other);

/**
 * @brief Изменяет размер выделенного диапазона памяти с учетом выравнивания.
 *
 * Эта функция изменяет размер выделенной памяти, связанной с указанным
 * диапазоном, при этом учитывая заданный размер выравнивания.
 *
 * Если изменение размера не удается (например, из-за нехватки памяти или несоответствия
 * выравниванию), управление передается в блок catch, что позволяет избежать
 * потери данных. В случае неудачи предыдущая память остается нетронутой.
 *
 * @param self Указатель на структуру диапазона памяти,
 *             размер которой необходимо изменить.
 * @param size_in_bytes Новый размер в байтах для выделенной памяти.
 * @param alignment_size Размер выравнивания,
 *                       который необходимо учитывать при выделении памяти.
 *
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `null`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если память не удалось выделить.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_NOT_POWER_OF_TWO
 *        Если параметр alignment_size не является степенью двойки.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_memory_range_set_with_fallback
 * @see ae_runtime_allocator_realloc
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_range_resize(ae_aligned_range_t *self,
                        ae_usize_t          size_in_bytes,
                        ae_usize_t          alignment_size);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALIGNED_RANGE_H
