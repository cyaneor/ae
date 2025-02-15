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
 * @brief Тип, представляющий выровненный диапазон памяти.
 *
 * Этот тип является псевдонимом для `ae_allocated_range_t` и используется
 * для явного указания, что диапазон памяти был динамически выделен
 * и выровнен по определенному размеру.
 *
 * Структурно идентичен `ae_allocated_range_t`, содержит те же поля
 * для хранения указателей на начало и конец диапазона памяти.
 *
 * @note Семантически отличается от `ae_allocated_range_t` тем,
 *       что предполагает работу только с выровненной памятью.
 *
 * @see ae_allocated_range_t
 * @see ae_memory_range_t
 */
typedef ae_allocated_range_t ae_aligned_range_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Освобождает ресурсы, связанные с выровненным диапазоном.
 *
 * Эта функция очищает и освобождает память, выделенную для
 * выровненного диапазона, представленного структурой `ae_aligned_range_t`.
 *
 * - Если указатель `self` равен `nullptr`, будет возвращено `false`.
 * - Функция сначала освобождает память, выделенную для начала диапазона,
 *   а затем очищает сам диапазон.
 *
 * @param self Указатель на структуру `ae_aligned_range_t`,
 *             представляющую выровненный диапазон, который необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note После вызова этой функции структура `self` может стать недействительной,
 *       и её использование без повторной инициализации приведет к неопределённому поведению.
 *
 * @see ae_memory_range_clear
 * @see ae_runtime_allocator_align_free
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_range_clear(void *self);

/**
 * @brief Обменивает содержимое двух выровненных диапазонов.
 *
 * Эта функция очищает текущий выровненный диапазон `self` и затем
 * обменивает его содержимое с другим выровненным диапазоном `other`.
 *
 * - Если указатель `self` или `other` равен `nullptr`, функция вернет `false`.
 * - Функция использует механизм обработки исключений для обеспечения
 *   безопасности при обмене содержимым.
 *
 * @param self Указатель на структуру `ae_aligned_range_t`,
 *             представляющую выровненный диапазон, который будет очищен и обменен.
 * @param other Указатель на структуру `ae_aligned_range_t`,
 *              представляющую выровненный диапазон, с которым будет произведен обмен.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note После успешного выполнения этой функции оба диапазона будут
 *       содержать данные, которые ранее находились в другом диапазоне.
 *
 * @see ae_aligned_range_clear
 * @see ae_memory_range_swap
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_range_exchange(void *self, void *other);

/**
 * @brief Изменяет размер выровненного диапазона.
 *
 * Эта функция изменяет размер выровненного диапазона `self`
 * на заданное количество байт с учетом выравнивания, указанного в `alignment_size`.
 *
 * Функция выполняет следующие шаги:
 * - Проверяет указатель `self` на `nullptr` и выбрасывает исключение, если он равен `null`.
 * - Сохраняет старый размер диапазона.
 * - Пытается перераспределить память с помощью `ae_runtime_allocator_align_realloc`.
 * - Если перераспределение не удается, выбрасывается исключение, и диапазон памяти не меняется.
 *
 * @param[in] self Указатель на структуру `ae_aligned_range_t`,
 *                 представляющую выровненный диапазон,
 *                 который необходимо изменить.
 * @param[in] size Новый размер диапазона в байтах.
 * @param[in] alignment_size Размер выравнивания в байтах,
 *                           который должен быть степенью двойки.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_NOT_POWER_OF_TWO
 *        Если `alignment_size` не является степенью двойки.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить новую память.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note После успешного выполнения этой функции диапазон будет
 *       иметь новый размер, выровненный по заданному размеру выравнивания.
 *
 * @see ae_memory_range_total_size
 * @see ae_runtime_allocator_align_realloc
 * @see ae_memory_range_set_with_fallback
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_range_resize(void *self, ae_usize_t size, ae_usize_t alignment_size);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALIGNED_RANGE_H
