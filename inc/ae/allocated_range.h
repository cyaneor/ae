/**
 * @file allocated_range.h
 * @brief Заголовочный файл для работы с выделенными диапазонами памяти.
 *
 * Данный файл содержит определения структуры `ae_allocated_range`, а также
 * функции для управления выделением, очисткой, изменением размера и обменом
 * содержимого выделенных диапазонов памяти.
 *
 * Структура `ae_allocated_range` используется для представления выделенного
 * диапазона памяти в приложении. Она включает в себя функции, позволяющие
 * эффективно управлять памятью, включая освобождение ресурсов и изменение
 * размеров выделенных блоков.
 *
 * @note Все функции, работающие с `ae_allocated_range`, должны быть
 *       использованы с осторожностью, чтобы избежать утечек памяти и
 *       некорректного доступа к памяти.
 *
 * @warning Убедитесь, что указатели на `ae_allocated_range` не равны `null`
 *          перед их использованием, чтобы избежать ошибок выполнения.
 *
 * @see ae_allocated_range
 * @see ae_allocated_range_clear
 * @see ae_allocated_range_exchange
 * @see ae_allocated_range_resize
 */

#ifndef AE_ALLOCATED_RANGE_H
#define AE_ALLOCATED_RANGE_H

#include "memory_range.h"

/**
 * @typedef ae_allocated_range_t
 * @brief Тип для работы с выделенным диапазоном памяти.
 *
 * Этот тип является псевдонимом для `ae_memory_range_t` и используется
 * для явного указания, что диапазон памяти был динамически выделен.
 *
 * Структурно идентичен `ae_memory_range_t`, содержит те же поля для
 * хранения указателей на начало и конец диапазона памяти.
 *
 * @note Семантически отличается от `ae_memory_range_t` тем, что
 *       предполагает работу только с выделенной памятью.
 *
 * @see ae_memory_range_t
 * @see ae_memory_range
 */
typedef ae_memory_range_t ae_allocated_range_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Освобождает и очищает выделенный диапазон памяти.
 *
 * Эта функция освобождает память, выделенную для диапазона,
 * и очищает структуру `ae_allocated_range`,
 * указанную в параметре `self`.
 *
 * Если указатель на начало диапазона памяти не равен `null`,
 * память будет освобождена с помощью функции `ae_runtime_allocator_free`.
 *
 * @param self Указатель на структуру `ae_allocated_range`,
 *             которую необходимо очистить и освободить.
 *
 * @note Если указатель на `self` равен `null`,
 *       функция не выполняет никаких действий.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 *
 * @see ae_memory_range_get_begin
 * @see ae_runtime_allocator_free
 * @see ae_memory_range_clear
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_range_clear(ae_allocated_range_t *self);

/**
 * @brief Обменивает содержимое двух выделенных диапазонов памяти.
 *
 * Эта функция очищает текущий диапазон памяти, указанный в параметре `self`,
 * и затем обменивает его содержимое с диапазоном, указанным в параметре `other`.
 *
 * @param self Указатель на структуру `ae_allocated_range`,
 *             содержимое которой будет обменено.
 * @param other Указатель на структуру `ae_allocated_range`,
 *              содержимое которой будет обменено с `self`.
 *
 * @warning Если в процессе обмена произошла ошибка,
 *          функция `ae_runtime_rethrow` пробросит её,
 *          распространяя любую возникшую ошибку.
 *
 * @see ae_allocated_range_clear
 * @see ae_memory_range_swap
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_range_exchange(ae_allocated_range_t *self, ae_allocated_range_t *other);

/**
 * @brief Изменяет размер выделенного диапазона памяти.
 *
 * Эта функция изменяет размер выделенной памяти, связанной с указанным
 * диапазоном. Если изменение размера не удается (например, из-за нехватки
 * памяти), то управление передается в блок catch, что позволяет избежать
 * потери данных. В случае неудачи предыдущая память остается нетронутой.
 *
 * @param self Указатель на структуру диапазона памяти,
 *             размер которой необходимо изменить.
 *
 * @param size_in_bytes Новый размер в байтах для выделенной памяти.
 *
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `null`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если память не удалось выделить.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_INVALID_ARGUMENT
 *        Если указатель `begin` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `null`.
 *
 * @see ae_memory_range_set_with_fallback
 * @see ae_runtime_allocator_realloc
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_range_resize(ae_allocated_range_t *self, ae_usize_t size_in_bytes);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALLOCATED_RANGE_H
