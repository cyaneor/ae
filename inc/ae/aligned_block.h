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
 * @struct ae_aligned_block
 * @brief Структура, представляющая выровненный блок памяти.
 *
 * Эта структура используется для хранения информации о выровненном блоке памяти,
 * который включает указатели на начало и конец блока, а также информацию о размере
 * элементов и выравнивании.
 */
typedef struct ae_aligned_block
{
    AE_ALIGNED_BLOCK_FIELDS(void);
} ae_aligned_block_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Возвращает размер выравнивания блока памяти.
 *
 * Эта функция возвращает размер выравнивания для блока памяти,
 * представленного объектом типа @c ae_aligned_block_t.
 *
 * Функция проверяет, что указатель на объект не равен NULL.
 * В случае, если указатель равен NULL, генерируется ошибка времени выполнения.
 *
 * @param self Указатель на объект типа @c ae_aligned_block_t,
 *             представляющий выровненный блок памяти.
 * @return Размер выравнивания блока памяти, хранимый в @c self->alignment_size.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `NULL`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_aligned_block_get_alignment_size(const void *self);

/**
 * @brief Обменивает содержимое двух выделенных блоков памяти.
 *
 * Эта функция обменивает содержимое двух выделенных блоков памяти,
 * представленных указателями на структуры типа ae_allocated_block_t.
 *
 * @param[in,out] self Указатель на структуру типа ae_allocated_block_t,
 *                     представляющую первый выделенный блок памяти.
 * @param[in,out] other Указатель на структуру типа ae_allocated_block_t,
 *                      представляющую второй выделенный блок памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_block_exchange(void *self, void *other);

/**
 * @brief Изменяет размер выровненного блока памяти.
 *
 * Эта функция изменяет размер выровненного блока памяти, представленного
 * структурой `ae_aligned_block_t`, на заданное количество элементов.
 *
 * Новый размер определяется умножением `number_of_elements` на размер элемента в блоке памяти.
 * Функция сначала проверяет, не превышает ли новый размер максимально допустимый размер блока,
 * и если проверка проходит, вызывает функцию `ae_aligned_range_resize` для изменения размера блока.
 *
 * - Проверяется, что новый размер не превышает максимально допустимый размер блока памяти.
 * - При успешном изменении размера блока памяти вызывается функция для изменения размера
 *   выровненного диапазона.
 *
 * @param self Указатель на структуру `ae_aligned_block_t`,
 *             представляющую выровненный блок памяти,
 *             который необходимо изменить.
 * @param number_of_elements Новое количество элементов в блоке памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на объект `self` равен `null`.
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
 * @note Эта функция изменяет размер блока памяти,
 *       учитывая размер каждого элемента и выравнивание.
 *
 *       После успешного выполнения размер блока изменится,
 *       и его содержимое будет перераспределено.
 *
 * @see ae_aligned_range_resize
 * @see ae_allocated_block_is_max_size_exceeds
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_aligned_block_resize(void *self, ae_usize_t number_of_elements);

/**
 * @brief Проверяет, равен ли размер выравнивания блока указанному значению.
 *
 * Функция сравнивает размер выравнивания блока с переданным значением.
 * В случае, если указатель на объект равен NULL,
 * генерируется ошибка с кодом AE_RUNTIME_ERROR_NULL_POINTER.
 *
 * @param self Указатель на объект типа ae_aligned_block_t,
 *             который содержит размер выравнивания.
 * @param alignment_size Размер выравнивания,
 *                       с которым будет сравниваться текущий размер выравнивания блока.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на объект `self` равен `null`.
 *
 * @return `true`, если размер выравнивания блока равен переданному значению,
 *         иначе `false`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_aligned_block_is_alignment_size_equal_to(const void *self, ae_usize_t alignment_size);

/**
 * @brief Проверяет, равны ли размеры выравнивания двух блоков.
 *
 * Функция сравнивает размер выравнивания текущего блока
 * с размером выравнивания другого блока.
 *
 * В случае, если указатель на объект `other` равен NULL,
 * генерируется ошибка с кодом AE_RUNTIME_ERROR_NULL_POINTER.
 *
 * @param self Указатель на объект типа ae_aligned_block_t,
 *             чей размер выравнивания будет сравниваться.
 * @param other Указатель на объект типа ae_aligned_block_t,
 *              размер выравнивания которого будет использоваться для сравнения.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на объект `self` равен `null`.
 *
 * @return `true`, если размеры выравнивания двух блоков равны,
 *         иначе `false`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_aligned_block_is_alignment_size_equal(const void *self, const void *other);

/**
 * @brief Проверяет, равны ли два блока.
 *
 * Функция сравнивает два блока, проверяя два условия:
 * равен ли их размер выравнивания и равны ли сами блоки памяти.
 * Для этого вызываются функции проверки выравнивания и сравнения памяти.
 *
 * @param self Указатель на объект типа ae_aligned_block_t,
 *             который представляет первый блок для сравнения.
 * @param other Указатель на объект типа ae_aligned_block_t,
 *              который представляет второй блок для сравнения.
 *
 * @return `true`, если оба блока равны (равны размеры выравнивания и данные блока памяти),
 *         иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на объект `self` равен `null`.
 *
 * @note Функция использует внутренние функции `ae_aligned_block_is_alignment_size_equal`
 *       для проверки выравнивания и `ae_memory_block_is_equal` для сравнения данных памяти.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_aligned_block_is_equal(const void *self, const void *other);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ALIGNED_BLOCK_H
