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
#include "offset.h"
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
 * @brief Проверяет, является ли блок памяти действительным.
 *
 * Эта функция проверяет, является ли блок памяти, представленный в параметре `self`,
 * действительным, то есть соответствует ли его размер размеру элемента.
 *
 * @param self Указатель на блок памяти,
 *             который необходимо проверить.
 *
 * @return `true`, если блок памяти действителен и его размер кратен размеру элемента;
 *         `false`, если блок памяти недействителен.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти недопустим
 *        (если `self` не является валидным диапазоном).
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_is_valid(const void *self);

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
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
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
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
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
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если один из диапазонов памяти недопустим.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках памяти различаются.
 */
AE_ATTRIBUTE(SYMBOL)
void
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
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если один из диапазонов памяти недопустим.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках памяти различаются.
 */
AE_ATTRIBUTE(SYMBOL)
void
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
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_has_index(const void *self, ae_usize_t index);

/**
 * @brief Вычисляет смещение элемента в блоке памяти по индексу.
 *
 * Эта функция вычисляет смещение в байтах элемента в блоке памяти, используя указанный индекс.
 * Она проверяет, что индекс находится в допустимом диапазоне, а затем умножает индекс на
 * размер одного элемента для получения смещения.
 *
 * @param self Указатель на блок памяти.
 * @param index Индекс элемента в блоке памяти.
 *
 * @return Смещение элемента в блоке памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_INDEX
 *        Если индекс выходит за допустимые границы блока памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
ae_uoffset_t
ae_memory_block_element_offset(const void *self, ae_usize_t index);

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
 * @throw AE_RUNTIME_ERROR_INVALID_INDEX
 *        Если индекс выходит за допустимые границы блока памяти.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
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
 * @throw AE_RUNTIME_ERROR_INVALID_INDEX
 *        Если индекс выходит за допустимые границы блока памяти.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
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
 * @throw AE_RUNTIME_ERROR_INVALID_INDEX
 *        Если индекс выходит за допустимые границы блока памяти.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
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
 * @throw AE_RUNTIME_ERROR_INVALID_INDEX
 *        Если индекс выходит за допустимые границы блока памяти.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
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
 * @throw AE_RUNTIME_ERROR_INVALID_INDEX
 *        Если индекс выходит за допустимые границы блока памяти.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если доступ к элементу не удался из-за недопустимого диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_back(const void *self);

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

/**
 * @brief Создаёт и возвращает пустой блок памяти.
 *
 * Эта функция создаёт и возвращает пустой блок памяти с заданным размером элемента.
 * Блок памяти инициализируется как пустой, что означает, что его диапазон не охватывает
 * фактические данные, но предоставляет память с указанным размером элемента.
 *
 * @param element_size Размер элемента в блоке памяти,
 *                     который будет создан.
 *
 * @return Возвращает инициализированный пустой блок памяти.
 *
 * @note Пустой блок памяти может быть использован для дальнейшей инициализации или для случаев,
 *       когда нужно создать блок памяти с определённым размером, но без фактических данных.
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_block_t
ae_memory_block_make_empty(ae_usize_t element_size);

/**
 * @brief Создаёт и инициализирует блок памяти.
 *
 * Эта функция создаёт и инициализирует блок памяти, задавая его начало, конец и размер элемента.
 * Функция выполняет проверку валидности блока памяти, и если блок памяти недействителен,
 * генерирует ошибку времени выполнения с помощью макроса `AE_RUNTIME_ASSERT`.
 *
 * @param begin Указатель на начало области памяти, которая будет использоваться в блоке.
 * @param end Указатель на конец области памяти.
 * @param element_size Размер элемента в блоке памяти.
 *
 * @return Возвращает инициализированный блок памяти типа `ae_memory_block_t`,
 *         если блок памяти валиден. В противном случае вызывает ошибку времени выполнения.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти недопустим
 *        (если `self` не является валидным диапазоном).
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 *
 * @see ae_memory_block_make_empty
 * @see ae_memory_block_is_valid
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_block_t
ae_memory_block_make(void *begin, void *end, ae_usize_t element_size);

/**
 * @brief Создаёт срез блока памяти.
 *
 * Эта функция создаёт новый блок памяти, который является срезом исходного блока памяти,
 * начиная с указанного индекса и длины. Новый блок памяти создаётся с использованием
 * того же размера элемента, что и у исходного блока памяти.
 *
 * Функция использует функцию `ae_memory_block_at` для вычисления начала
 * и конца среза и вызывает `ae_memory_block_make_with_clone_element_size`
 * для создания нового блока.
 *
 * @param self Указатель на исходный блок памяти,
 *             из которого будет извлечён срез.
 * @param index Индекс в исходном блоке,
 *              с которого начинается срез.
 * @param length Длина среза, т.е. количество элементов,
 *               которое должен включать новый блок памяти.
 *
 * @return Возвращает новый блок памяти типа `ae_memory_block_t`,
 *         который является срезом исходного блока памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если указанный диапазон (от `index` до `index + length`)
 *        выходит за пределы исходного блока памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если размер исходного блока памяти не кратен размеру элемента.
 *
 * @see ae_memory_block_at
 * @see ae_memory_block_make_with_clone_element_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_block_t
ae_memory_block_slice(void *self, ae_usize_t index, ae_usize_t length);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_BLOCK_H
