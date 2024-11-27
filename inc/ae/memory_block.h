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
 * Эта структура используется для описания блока памяти,
 * который содержит указатели на начало и конец блока,
 * а также размер элемента.
 */
typedef struct ae_memory_block
{
    AE_MEMORY_BLOCK_FIELDS(void);
} ae_memory_block_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает размер элемента в блоке памяти.
 *
 * Эта функция возвращает размер одного элемента,
 * который может храниться в указанном блоке памяти.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             из которой необходимо получить размер элемента.
 *
 * @return Размер элемента в байтах.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_block_element_size(const ae_memory_block_t *self);

/**
 * @brief Получает общий размер блока памяти.
 *
 * Эта функция вычисляет общий размер блока памяти, основываясь на
 * размере элемента и размере самого блока. Она использует функцию
 * @ref ae_memory_block_element_size для получения размера элемента
 * и функцию @ref ae_memory_range_size для вычисления размера блока.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             для которой необходимо вычислить общий размер.
 *
 * @return Общий размер блока памяти в байтах.
 *
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер диапазона памяти не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_block_element_size
 * @see ae_memory_range_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_block_size(const ae_memory_block_t *self);

/**
 * @brief Определяет максимальный размер блока памяти для хранения элементов.
 *
 * Эта функция вычисляет максимальное количество элементов, которые могут быть
 * размещены в блоке памяти, не превышая максимально возможного размера объекта
 * типа `ae_usize_t`. Максимальный размер определяется как результат деления
 * максимально возможного значения `ae_usize_t` на размер одного элемента.
 * Если размер элемента равен нулю, возникает ошибка.
 *
 * @param self Указатель на блок памяти,
 *             для которого необходимо вычислить максимальный размер.
 *
 * @return Максимальное количество элементов,
 *         которые могут быть размещены в блоке.
 *
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если размер элемента равен нулю.
 *
 * @see ae_memory_block_element_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_block_max_size(const ae_memory_block_t *self);

/**
 * @brief Проверяет, является ли блок памяти пустым.
 *
 * Эта функция определяет, пуст ли блок памяти, проверяя, равен ли его общий
 * размер нулю. Используется функция @ref ae_memory_block_size для получения
 * общего размера блока памяти.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             которую необходимо проверить на пустоту.
 *
 * @return Возвращает `true`, если блок памяти пуст (размер равен 0),
 *         и `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_SIZE_IS_NOT_MULTIPLE_OF_ELEMENT_SIZE
 *        Если общий размер диапазона памяти не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_block_size
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_empty(const ae_memory_block_t *self);

/**
 * @brief Проверяет, равен ли размер элемента в блоке памяти заданному значению.
 *
 * Эта функция сравнивает размер элемента
 * в указанном блоке памяти с заданным размером элемента.
 *
 * @param self Указатель на структуру блока памяти, который нужно проверить.
 * @param element_size Размер элемента для сравнения.
 *
 * @return `true` Если размер элемента в блоке памяти равен заданному размеру.
 * @return `false` Если размер элемента в блоке памяти не равен заданному размеру.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_block_element_size
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_element_size_equal_to(const struct ae_memory_block *self, ae_usize_t element_size);

/**
 * @brief Сравнивает размеры элементов двух блоков памяти.
 *
 * Эта функция проверяет, совпадают ли размеры элементов в двух указанных блоках памяти.
 * Она использует функцию @ref ae_memory_block_element_size_equal_to для сравнения.
 *
 * @param self Указатель на первый блок памяти для сравнения.
 * @param other Указатель на второй блок памяти для сравнения.
 *
 * @return `true` Если размеры элементов в обоих блоках памяти равны.
 * @return `false` Если размеры элементов в блоках памяти различаются.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_block_element_size_equal_to
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_element_size_equal(const struct ae_memory_block *self,
                                   const struct ae_memory_block *other);

/**
 * @brief Обменивает содержимое двух блоков памяти.
 *
 * Эта функция выполняет обмен содержимого между двумя блоками памяти.
 * Перед обменом проверяется, что размеры элементов в обоих блоках совпадают.
 * Если размеры элементов различаются, генерируется ошибка выполнения.
 *
 * @param self Указатель на первый блок памяти для обмена.
 * @param other Указатель на второй блок памяти для обмена.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках различаются.
 *
 * @note Функция использует ae_memory_range_swap
 *       для выполнения фактического обмена данных.
 *
 * @see ae_memory_range_swap
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_block_swap(struct ae_memory_block *self, struct ae_memory_block *other);

/**
 * @brief Очищает содержимое блока памяти.
 *
 * Эта функция очищает (обнуляет) все данные в указанном блоке памяти.
 * Она использует функцию ae_memory_range_clear для выполнения операции очистки.
 *
 * @param self Указатель на блок памяти, который нужно очистить.
 *
 * @note Функция не изменяет размер блока памяти или его другие атрибуты,
 *       она только обнуляет его содержимое.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках различаются.
 *
 * @see ae_memory_range_clear
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_block_clear(ae_memory_block_t *self);

/**
 * @brief Обменивает содержимое двух блоков памяти,
 *        предварительно очищая первый блок.
 *
 * Эта функция выполняет следующие операции:
 * 1. Очищает содержимое первого блока памяти (self).
 * 2. Обменивает содержимое между первым (self) и вторым (other) блоками памяти.
 *
 * @param self Указатель на первый блок памяти, который будет очищен и обменен.
 * @param other Указатель на второй блок памяти для обмена.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE
 *        Если размеры элементов в блоках различаются.
 *
 * @see ae_memory_block_clear
 * @see ae_memory_block_swap
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_block_exchange(ae_memory_block_t *self, ae_memory_block_t *other);

/**
 * @brief Определяет начало элемента блока памяти,
 *        содержащего указанный адрес.
 *
 * Функция находит начальный адрес элемента блока памяти,
 * в границах которого находится переданный указатель.
 *
 * Выполняет проверки корректности входных данных
 * и возвращает указатель на начало соответствующего элемента.
 *
 * @param self Указатель на блок памяти.
 * @param ptr Указатель, для которого нужно определить содержащий его элемент.
 *
 * @return Указатель на начало элемента,
 *         содержащего ptr, или nullptr в случае ошибки.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если `ptr` находится вне допустимого диапазона блока памяти.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента в блоке равен нулю.
 *
 * @note Функция выполняет выравнивание указателя на границу элемента,
 *       округляя вниз до начала элемента, содержащего указанный адрес.
 *
 * Алгоритм работы:
 * 1. Проверяет, находится ли указатель в допустимом диапазоне блока памяти
 * 2. Получает размер элемента блока
 * 3. Проверяет корректность размера элемента
 * 4. Вычисляет смещение от начала блока до указанного адреса
 * 5. Определяет начало элемента, выравнивая по размеру элемента
 *
 * @see ae_memory_range_begin
 * @see ae_memory_range_contain_ptr
 * @see ae_memory_block_element_size
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_element_base_address(const struct ae_memory_block *self, const void *ptr);

/**
 * @brief Проверяет, находится ли указанный индекс в пределах блока памяти.
 *
 * Данная функция определяет, находится ли индекс в пределах размера блока памяти.
 * Если параметр `inclusive` равен true, то индекс считается допустимым, если он равен
 * или меньше размера блока. Если `inclusive` равен false, то индекс считается допустимым,
 * только если он меньше размера блока.
 *
 * @param self Указатель на блок памяти, который проверяется.
 * @param index Индекс, который необходимо проверить.
 * @param inclusive Флаг, указывающий, следует ли учитывать верхнюю границу.
 *                  Если true, то индекс должен быть меньше или равен размеру блока.
 *                  Если false, то индекс должен быть строго меньше размера блока.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @return true, если индекс находится в пределах блока памяти (включительно или нет,
 *         в зависимости от параметра inclusive); false в противном случае.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_has_index(const ae_memory_block_t *self, ae_usize_t index, bool inclusive);

/**
 * @brief Проверяет, находятся ли указанные индексы в пределах блока памяти.
 *
 * Данная функция определяет, находятся ли начальный и конечный индексы в пределах
 * размера блока памяти. Если параметр `inclusive` равен true, то индексы считаются
 * допустимыми, если они равны или меньше размера блока. Если `inclusive` равен false,
 * то индексы считаются допустимыми только если они меньше размера блока.
 *
 * @param self Указатель на блок памяти, который проверяется.
 * @param start_index Начальный индекс, который необходимо проверить.
 * @param end_index Конечный индекс, который необходимо проверить.
 * @param inclusive Флаг, указывающий, следует ли учитывать верхнюю границу.
 *                  Если true, то индексы должны быть меньше или равны размеру блока.
 *                  Если false, то индексы должны быть строго меньше размера блока.
 *
 * @return true, если оба индекса находятся в пределах блока памяти
 *         (включительно или нет, в зависимости от параметра inclusive);
 *         false в противном случае.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_has_index_range(const ae_memory_block_t *self,
                                ae_usize_t               start_index,
                                ae_usize_t               end_index,
                                bool                     inclusive);

/**
 * @brief Вычисляет смещение для заданного индекса в блоке памяти.
 *
 * Эта функция возвращает смещение в байтах для указанного индекса
 * в блоке памяти. Смещение вычисляется на основе размера элемента,
 * который хранится в блоке памяти.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             в которой необходимо вычислить смещение.
 * @param index Индекс элемента, для которого необходимо вычислить
 *              смещение в блоке памяти.
 *
 * @return Смещение в байтах относительно начала блока памяти для
 *         указанного индекса.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 *
 * @see ae_memory_block_check_index
 * @see ae_memory_block_element_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_block_element_offset(const ae_memory_block_t *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент блока памяти по индексу,
 *        отсчитываемому от начала блока.
 *
 * Эта функция вычисляет позицию элемента, умножая индекс на размер элемента,
 * и возвращает указатель на элемент в этой позиции. Перед доступом к памяти
 * выполняется проверка валидности индекса.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             из которой нужно получить элемент.
 * @param index Индекс элемента в блоке памяти.
 *
 * @return Указатель на элемент блока памяти по заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_element_offset
 * @see ae_memory_range_at
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_at_from_begin(ae_memory_block_t *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент блока памяти по индексу,
 *        отсчитываемому от начала блока, для константного блока памяти.
 *
 * Эта функция является оберткой для функции @ref ae_memory_block_at_from_begin,
 * которая позволяет получать элементы из блока памяти, не изменяя его содержимое.
 * Она принимает указатель на константный блок памяти и возвращает указатель на
 * элемент, находящийся по заданному индексу. Перед доступом к памяти
 * выполняется проверка валидности индекса.
 *
 * @param self Указатель на константную структуру @ref ae_memory_block,
 *             из которой нужно получить элемент.
 * @param index Индекс элемента в блоке памяти.
 *
 * @return Указатель на элемент блока памяти по заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_at_from_begin
 * @see ae_memory_block_element_offset
 * @see ae_memory_range_at
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_block_at_from_begin_const(const ae_memory_block_t *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент блока памяти по индексу,
 *        отсчитываемому от конца блока.
 *
 * Эта функция преобразует индекс, отсчитываемый от конца блока,
 * в индекс от начала блока и использует @ref ae_memory_block_at_from_begin
 * для получения указателя на элемент. Индекс 0 соответствует последнему
 * элементу блока.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             из которой нужно получить элемент.
 * @param index Индекс элемента от конца блока памяти
 *              (0 соответствует последнему элементу).
 *
 * @return Указатель на элемент блока памяти по заданному индексу от конца.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_at_from_begin
 * @see ae_memory_block_size
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_at_from_end(ae_memory_block_t *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент блока памяти по индексу,
 *        отсчитываемому от конца блока, для константного блока памяти.
 *
 * Эта функция является оберткой для функции @ref ae_memory_block_at_from_end,
 * которая позволяет получать элементы из блока памяти, не изменяя его содержимое.
 * Она принимает указатель на константный блок памяти и возвращает указатель на
 * элемент, находящийся по заданному индексу, отсчитываемому от конца блока.
 * Индекс 0 соответствует последнему элементу блока.
 *
 * @param self Указатель на константную структуру @ref ae_memory_block,
 *             из которой нужно получить элемент.
 * @param index Индекс элемента от конца блока памяти
 *              (0 соответствует последнему элементу).
 *
 * @return Указатель на элемент блока памяти по заданному индексу от конца.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_at_from_end
 * @see ae_memory_block_size
 * @see ae_memory_block_at_from_begin
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_block_at_from_end_const(const ae_memory_block_t *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент блока памяти по индексу,
 *        с возможностью выбора направления отсчета (от начала или конца).
 *
 * Эта функция определяет, откуда следует отсчитывать индекс (от начала или конца блока)
 * и вызывает соответствующую функцию для получения указателя на элемент.
 *
 * @param self Указатель на структуру @ref ae_memory_block,
 *             из которой нужно получить элемент.
 * @param index Индекс элемента в блоке памяти.
 * @param reversed Флаг, указывающий, следует ли отсчитывать индекс от конца блока.
 *
 * @return Указатель на элемент блока памяти по заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_at_from_begin
 * @see ae_memory_block_at_from_end
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_at(ae_memory_block_t *self, ae_usize_t index, bool reversed);

/**
 * @brief Получает указатель на элемент блока памяти по индексу,
 *        с возможностью выбора направления отсчета (от начала или конца),
 *        для константного блока памяти.
 *
 * Эта функция является оберткой для функции @ref ae_memory_block_at,
 * которая позволяет получать указатель на элемент в блоке памяти,
 * не изменяя его содержимое. Она принимает указатель на константный блок
 * памяти и возвращает указатель на элемент, находящийся по заданному индексу,
 * с учетом направления отсчета.
 *
 * @param self Указатель на константную структуру @ref ae_memory_block,
 *             из которой нужно получить элемент.
 * @param index Индекс элемента в блоке памяти.
 * @param reversed Флаг, указывающий, следует ли отсчитывать индекс от конца блока.
 *
 * @return Указатель на элемент блока памяти по заданному индексу.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_at
 * @see ae_memory_block_at_from_begin
 * @see ae_memory_block_at_from_end
 * @see ae_memory_block
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_block_at_const(const ae_memory_block_t *self, ae_usize_t index, bool reversed);

/**
 * @brief Получает указатель на первый элемент в блоке памяти.
 *
 * Эта функция возвращает указатель на первый элемент в блоке памяти,
 * что эквивалентно вызову функции `ae_memory_block_at_from_begin` с индексом 0.
 *
 * @param self Указатель на структуру `ae_memory_block`,
 *             из которой необходимо получить указатель на первый элемент.
 *
 * @return Указатель на первый элемент в блоке памяти,
 *         или `null`, если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block
 * @see ae_memory_block_at
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_front(ae_memory_block_t *self);

/**
 * @brief Получает указатель на первый элемент в блоке памяти,
 *        для константного блока памяти.
 *
 * Эта функция является оберткой для функции @ref ae_memory_block_front,
 * которая позволяет получать указатель на первый элемент в блоке памяти,
 * не изменяя его содержимое. Функция эквивалентна вызову
 * `ae_memory_block_at_from_begin` с индексом 0.
 *
 * @param self Указатель на константную структуру @ref ae_memory_block,
 *             из которой необходимо получить указатель на первый элемент.
 *
 * @return Указатель на первый элемент в блоке памяти,
 *         или `null`, если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_front
 * @see ae_memory_block_at
 * @see ae_memory_block
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_block_front_const(const ae_memory_block_t *self);

/**
 * @brief Получает указатель на последний элемент в блоке памяти.
 *
 * Эта функция возвращает указатель на последний элемент в блоке памяти,
 * что эквивалентно вызову функции `ae_memory_block_at_from_end` с индексом 0.
 *
 * @param self Указатель на структуру `ae_memory_block`,
 *             из которой необходимо получить указатель на последний элемент.
 *
 * @return Указатель на последний элемент в блоке памяти,
 *         или `null`, если указатель на `self` равен `null` или блок пуст.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block
 * @see ae_memory_block_at
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_block_back(ae_memory_block_t *self);

/**
 * @brief Получает указатель на последний элемент в блоке памяти,
 *        для константного блока памяти.
 *
 * Эта функция является оберткой для функции @ref ae_memory_block_back,
 * которая позволяет получать указатель на последний элемент в блоке памяти,
 * не изменяя его содержимое. Она возвращает указатель на элемент,
 * находящийся в конце блока памяти.
 *
 * @param self Указатель на константную структуру @ref ae_memory_block,
 *             из которой необходимо получить указатель на последний элемент.
 *
 * @return Указатель на последний элемент в блоке памяти,
 *         или `null`, если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель self равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если индекс выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_block_back
 * @see ae_memory_block_at
 * @see ae_memory_block
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_block_back_const(const ae_memory_block_t *self);

/**
 * @brief Сравнивает два блока памяти на равенство.
 *
 * Эта функция проверяет, равны ли размеры элементов
 * и диапазоны памяти двух указанных блоков.
 *
 * @param self Указатель на первый блок памяти для сравнения.
 * @param other Указатель на второй блок памяти для сравнения.
 *
 * @return `true` Если размеры элементов и диапазоны памяти в обоих
 *         блоках равны.
 * @return `false` Если размеры элементов или диапазоны памяти
 *         различаются.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `null`.
 *
 * @see ae_memory_block_element_size_equal
 * @see ae_memory_range_equal
 * @see ae_memory_block
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_block_equal(const ae_memory_block_t *self, const ae_memory_block_t *other);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_BLOCK_H
