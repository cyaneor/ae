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
 * @note Семантически отличается от `ae_memory_range_t` тем,
 *       что предполагает работу только с выделенной памятью.
 *
 * @see ae_memory_range_t
 * @see ae_memory_range
 */
typedef ae_memory_range_t ae_allocated_range_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Очищает выделенный диапазон памяти.
 *
 * Эта функция освобождает память, выделенную для диапазона, и очищает сам диапазон.
 * Перед вызовом функции выполняется проверка на нулевой указатель.
 *
 * @param[in] self Указатель на структуру типа ae_allocated_range_t,
 *                 представляющую выделенный диапазон памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_range_clear(void *self);

/**
 * @brief Обменивает содержимое двух выделенных диапазонов памяти.
 *
 * Эта функция очищает текущий диапазон памяти, связанный с указателем `self`,
 * и затем обменивает его содержимое с диапазоном, связанным с указателем `other`.
 *
 * @param[in,out] self Указатель на структуру типа ae_allocated_range_t,
 *                     представляющую первый выделенный диапазон памяти.
 * @param[in,out] other Указатель на структуру типа ae_allocated_range_t,
 *                      представляющую второй выделенный диапазон памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_range_exchange(void *self, void *other);

/**
 * @brief Изменяет размер выделенного диапазона памяти.
 *
 * Эта функция изменяет размер памяти, выделенной для диапазона, на указанный
 * размер в байтах. Если выделение новой памяти не удается (например, из-за
 * нехватки памяти), функция выбрасывает исключение, и предыдущий диапазон
 * памяти остается нетронутым, что предотвращает потерю данных.
 *
 * @param[in] self Указатель на структуру типа ae_allocated_range_t,
 *                 представляющую выделенный диапазон памяти.
 * @param[in] size Новый размер диапазона в байтах.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить новую память.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note Функция использует механизм обработки исключений для обеспечения
 *       безопасности операций с памятью. В случае неудачи при выделении
 *       новой памяти, предыдущая память остается нетронутой, что защищает
 *       от потери данных.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_allocated_range_resize(void *self, ae_usize_t size);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALLOCATED_RANGE_H
