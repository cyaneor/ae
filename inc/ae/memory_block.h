/**
 * @file memory_block.h
 * @brief Определение структуры и функций для работы с блоками памяти.
 *
 * Этот файл содержит определение структуры @ref ae_memory_block,
 * которая представляет собой блок памяти, а также набор функций
 * для работы с этой структурой.
 *
 * Структура @ref ae_memory_block позволяет управлять динамической памятью,
 * обеспечивая удобный интерфейс для работы с массивами элементов
 * одинакового размера.
 */

#ifndef AE_MEMORY_BLOCK_H
#define AE_MEMORY_BLOCK_H

#include "memory_block_fields.h"
#include "attribute.h"
#include "bool.h"

/**
 * @struct ae_memory_block
 * @brief Структура, представляющая блок памяти.
 *
 * Эта структура используется для хранения информации о блоке памяти,
 * включая указатели на начало и конец блока, а также информацию
 * о размере одного элемента в этом блоке.
 */
typedef struct ae_memory_block
{
    AE_MEMORY_BLOCK_FIELDS(void);
} ae_memory_block_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Возвращает размер одного элемента в блоке памяти.
 *
 * Эта функция возвращает размер одного элемента, хранимого в блоке памяти,
 * представленном объектом типа @c ae_memory_block_t.
 *
 * @param self Указатель на объект типа @c ae_memory_block_t, представляющий блок памяти.
 * @return Размер одного элемента в блоке памяти, хранимый в @c self->element_size.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_block_get_element_size(const void *self);

/**
 * @brief Вычисляет количество элементов в блоке памяти.
 *
 * Эта функция определяет, сколько элементов заданного размера помещается в блоке памяти.
 * Если общий размер блока памяти не кратен размеру элемента,
 * функция вызывает ошибку времени выполнения.
 *
 * @param self Указатель на структуру #ae_memory_block_t,
 *             представляющую блок памяти.
 * @return Количество элементов в блоке памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_block_size(const void *self);

/**
 * @brief Проверяет, является ли блок памяти пустым.
 *
 * Эта функция определяет, содержит ли блок памяти элементы.
 * Блок считается пустым, если количество элементов в нем равно нулю.
 *
 * @param self Указатель на структуру #ae_memory_block_t, представляющую блок памяти.
 * @return true, если блок памяти пустой; false в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_is_empty(const void *self);

/**
 * @brief Обменивает содержимое двух блоков памяти.
 *
 * Эта функция меняет местами содержимое двух блоков памяти,
 * представленных структурами `self` и `other`.
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую первый блок памяти.
 * @param other Указатель на структуру #ae_memory_block,
 *              представляющую второй блок памяти.
 *
 * @return `true`, если обмен содержимым блоков памяти был успешным;
 *         `false`, если один из указателей (`self` или `other`) равен `nullptr`,
 *                  или если размеры элементов в блоках памяти различаются.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если один из диапазонов памяти недопустим.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках памяти различаются.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_swap(void *self, void *other);

/**
 * @brief Обменивает содержимое двух блоков памяти.
 *
 * Эта функция сначала очищает блок памяти, представленный структурой `self`,
 * а затем меняет местами содержимое этого блока с содержимым блока,
 * представленным структурой `other`.
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую первый блок памяти.
 * @param other Указатель на структуру #ae_memory_block,
 *              представляющую второй блок памяти.
 *
 * @return `true`, если обмен содержимым блоков памяти был успешным;
 *         `false`, если один из указателей (`self` или `other`) равен `nullptr`,
 *                  или если размеры элементов в блоках памяти различаются.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если один из диапазонов памяти недопустим.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках памяти различаются.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_exchange(void *self, void *other);

/**
 * @brief Проверяет, находится ли индекс в пределах блока памяти.
 *
 * Эта функция определяет,
 * находится ли заданный индекс в пределах блока памяти.
 *
 * @param self Указатель на структуру #ae_memory_block, представляющую блок памяти.
 * @param index Индекс, который необходимо проверить.
 * @return `true`, если индекс находится в пределах блока памяти;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_has_index(const void *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент в блоке памяти по индексу, начиная с начала.
 *
 * Эта функция возвращает указатель на элемент в блоке памяти, соответствующий
 * заданному индексу, начиная с начала блока. Функция обрабатывает возможные
 * ошибки, возникающие при доступе к элементу.
 *
 * @param self Указатель на структуру #ae_memory_block, представляющую блок памяти.
 * @param index Индекс элемента, для которого необходимо получить указатель.
 * @return Указатель на элемент в блоке памяти, соответствующий заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указанный индекс находится вне допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_at_from_begin(const void *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент в блоке памяти по индексу, начиная с конца.
 *
 * Эта функция возвращает указатель на элемент в блоке памяти, соответствующий
 * заданному индексу, начиная с конца блока. Индекс 0 соответствует последнему
 * элементу, индекс 1 — предпоследнему и так далее.
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую блок памяти.
 * @param index Индекс элемента, для которого необходимо получить указатель,
 *              начиная с конца блока.
 * @return Указатель на элемент в блоке памяти,
 *         соответствующий заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указанный индекс находится вне допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_at_from_end(const void *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент в блоке памяти по индексу.
 *
 * Эта функция возвращает указатель на элемент в блоке памяти, соответствующий
 * заданному индексу. Параметр `reversed` указывает, следует ли получать элемент
 * начиная с конца блока (если true) или с начала (если false).
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую блок памяти.
 * @param index Индекс элемента,
 *              для которого необходимо получить указатель.
 * @param reversed Флаг, указывающий, следует ли получать элемент с конца (true)
 *                 или с начала (false).
 * @return Указатель на элемент в блоке памяти,
 *         соответствующий заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указанный индекс находится вне допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_at(const void *self, ae_usize_t index, bool reversed);

/**
 * @brief Получает указатель на первый элемент в блоке памяти.
 *
 * Эта функция возвращает указатель на первый элемент в блоке памяти.
 * Если блок памяти пустой, поведение функции может быть неопределенным.
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую блок памяти.
 * @return Указатель на первый элемент в блоке памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если блок памяти пустой.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_front(const void *self);

/**
 * @brief Получает указатель на последний элемент в блоке памяти.
 *
 * Эта функция возвращает указатель на последний элемент в блоке памяти.
 * Если блок памяти пустой, поведение функции может быть неопределенным.
 *
 * @param self Указатель на структуру #ae_memory_block, представляющую блок памяти.
 * @return Указатель на последний элемент в блоке памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если блок памяти пустой.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_back(const void *self);

/**
 * @brief Проверяет, находится ли диапазон индексов в пределах блока памяти.
 *
 * Эта функция определяет,
 * находятся ли заданные начальный и конечный индексы в пределах блока памяти.
 *
 * @param self Указатель на структуру #ae_memory_block, представляющую блок памяти.
 * @param start_index Начальный индекс диапазона, который необходимо проверить.
 * @param end_index Конечный индекс диапазона, который необходимо проверить.
 *
 * @return `true`, если оба индекса находятся в пределах блока памяти;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер блока памяти не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_has_index_range(const void *self, ae_usize_t start_index, ae_usize_t end_index);

/**
 * @brief Проверяет, равен ли размер элемента заданному значению.
 *
 * Эта функция сравнивает размер элемента в блоке памяти с заданным значением.
 * Если указатель на блок памяти равен `nullptr`, будет вызвана ошибка времени выполнения.
 *
 * @param self Указатель на структуру #ae_memory_block, представляющую блок памяти.
 * @param element_size Размер элемента, с которым необходимо сравнить.
 * @return `true`, если размер элемента в блоке памяти равен заданному значению;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_is_element_size_equal_to(const void *self, ae_usize_t element_size);

/**
 * @brief Проверяет, равны ли размеры элементов двух блоков памяти.
 *
 * Эта функция сравнивает размер элемента в одном блоке памяти с размером элемента
 * в другом блоке памяти. Если указатель на другой блок памяти равен `nullptr`,
 * будет вызвана ошибка времени выполнения.
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую первый блок памяти.
 * @param other Указатель на структуру #ae_memory_block,
 *              представляющую второй блок памяти.
 * @return `true`, если размеры элементов в обоих блоках памяти равны;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `other` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_is_element_size_equal(const void *self, const void *other);

/**
 * @brief Проверяет, равны ли два блока памяти.
 *
 * Эта функция сравнивает два блока памяти на равенство. Она проверяет,
 * равны ли размеры элементов в обоих блоках, а также содержимое самих блоков.
 * Если указатель на один из блоков равен `nullptr`, будет вызвана ошибка времени выполнения.
 *
 * @param self Указатель на структуру #ae_memory_block,
 *             представляющую первый блок памяти.
 * @param other Указатель на структуру #ae_memory_block,
 *              представляющую второй блок памяти.
 *
 * @return `true`, если оба блока памяти равны;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_is_equal(const void *self, const void *other);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_BLOCK_H
