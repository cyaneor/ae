#ifndef DYNAMIC_BLOCK_H
#define DYNAMIC_BLOCK_H

#include "dynamic_block_fields.h"
#include "attribute.h"
#include "bool.h"

/**
 * @struct ae_dynamic_block
 * @brief Структура для представления динамического блока памяти.
 *
 * Эта структура содержит поля, определенные с помощью макроса
 * AE_DYNAMIC_BLOCK_FIELDS, которые позволяют управлять
 * динамическим выделением памяти для заданного типа данных.
 *
 * Структура включает в себя:
 * - Поля, определенные в AE_ALIGNED_BLOCK_FIELDS(T)
 * - Поле number_of_elements, указывающее количество элементов в блоке
 *
 * Пример использования:
 * @code{.c}
 * ae_dynamic_block_t int_block;
 * int_block.number_of_elements = 10; // Устанавливаем количество элементов
 * @endcode
 *
 * @note Структура предназначена для использования в ситуациях,
 *       когда необходимо управлять динамическими массивами.
 */
typedef struct ae_dynamic_block
{
    AE_DYNAMIC_BLOCK_FIELDS(void);
} ae_dynamic_block_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает текущее количество элементов в динамическом блоке памяти.
 *
 * Эта функция возвращает количество элементов, которые в настоящее время
 * хранятся в динамическом блоке памяти. Если указатель на блок памяти
 * равен `nullptr`, функция вызывает ошибку времени выполнения.
 *
 * @param self Указатель на динамический блок памяти,
 *             для которого необходимо получить количество элементов.
 *
 * @return Текущее количество элементов
 *         в динамическом блоке памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_dynamic_block
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_dynamic_block_size(const ae_dynamic_block_t *self);

/**
 * @brief Очищает динамический блок.
 *
 * Эта функция сбрасывает количество элементов в динамическом блоке до нуля.
 * При этом емкость (capacity) динамического блока остается неизменной.
 *
 * @param self Указатель на динамический блок,
 *             который необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_dynamic_block_clear(ae_dynamic_block_t *self);

/**
 * @brief Удаляет динамический блок.
 *
 * Эта функция очищает динамический блок, сбрасывая количество элементов до нуля,
 * а затем уменьшает емкость блока до текущего размера элементов.
 *
 * @param self Указатель на динамический блок,
 *             который необходимо удалить.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_dynamic_block_clear
 * @see ae_dynamic_block_shrink
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_dynamic_block_delete(ae_dynamic_block_t *self);

/**
 * @brief Проверяет, является ли динамический блок пустым.
 *
 * Эта функция проверяет, содержит ли указанный динамический блок элементы.
 * Если размер блока равен нулю, то блок считается пустым.
 *
 * @param self Указатель на динамический блок,
 *             который нужно проверить.
 *
 * @return `true`, если динамический блок пустой (размер равен 0);
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @note Функция использует `ae_dynamic_block_size`
 *       для получения размера блока.
 *
 * @see ae_dynamic_block
 * @see ae_dynamic_block_size
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_dynamic_block_is_empty(const ae_dynamic_block_t *self);

/**
 * @brief Вычисляет общий размер динамического блока памяти.
 *
 * Эта функция возвращает общий размер памяти, занимаемой элементами
 * в динамическом блоке. Общий размер вычисляется как произведение
 * текущего количества элементов и размера одного элемента.
 *
 * @param self Указатель на динамический блок памяти,
 *             для которого необходимо определить общий размер.
 *
 * @return Общий размер блока памяти в байтах.
 *         Если количество элементов равно 0, возвращает 0.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_dynamic_block
 * @see ae_dynamic_block_size
 * @see ae_memory_block_get_element_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_dynamic_block_total_size(const ae_dynamic_block_t *self);

/**
 * @brief Вычисляет доступный размер блока памяти.
 *
 * Эта функция возвращает количество доступного размера в блоке памяти,
 * который может быть использован для выделения дополнительных элементов.
 * Доступный размер вычисляется как разница между максимальным размером
 * блока памяти и текущим общим размером блока.
 *
 * @param self Указатель на динамический блок памяти,
 *             для которого необходимо определить доступный размер.
 *
 * @return Доступный размер блока памяти в элементах.
 *         Если доступный размер не может быть определен, возвращает 0.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_block
 * @see ae_memory_block_max_size
 * @see ae_dynamic_block_total_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_dynamic_block_available_size(const ae_dynamic_block_t *self);

/**
 * @brief Получает указатель на конец динамического блока памяти.
 *
 * Эта функция вычисляет адрес конца динамического блока памяти,
 * добавляя общий размер блока к началу диапазона памяти.
 *
 * @param self Указатель на динамический блок памяти,
 *             для которого необходимо получить адрес конца.
 *
 * @return Указатель на конец динамического блока памяти.
 *         Если блок памяти пуст, возвращает указатель,
 *         указывающий на конец блока.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_dynamic_block_total_size
 * @see ae_memory_range_get_begin
 * @see ae_dynamic_block
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_dynamic_block_get_end(const ae_dynamic_block_t *self);

/**
 * @brief Получает емкость динамического блока памяти.
 *
 * Эта функция возвращает емкость динамического блока памяти,
 * которая определяется как размер памяти, выделенной для хранения
 * элементов в блоке. Емкость указывает на максимальное количество
 * элементов, которые могут быть сохранены в блоке без необходимости
 * перераспределения памяти.
 *
 * @param self Указатель на динамический блок памяти,
 *             для которого необходимо определить емкость.
 *
 * @return Емкость динамического блока памяти в байтах.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_block
 * @see ae_memory_block_size
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_dynamic_block_capacity(const ae_dynamic_block_t *self);

/**
 * @brief Уменьшает размер динамического блока
 *        до текущего размера элементов.
 *
 * Эта функция уменьшает ёмкость динамического блока,
 * если текущий размер блока меньше его ёмкости.
 *
 * В этом случае, ёмкость блока изменяется так,
 * чтобы она соответствовала текущему количеству элементов.
 *
 * @param self Указатель на динамический блок,
 *             который необходимо уменьшить.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_BLOCK
 *        Если блок памяти не является действительным,
 *        например, если его размер не кратен размеру элемента.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_dynamic_block_capacity
 * @see ae_dynamic_block_size
 * @see ae_unified_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_dynamic_block_shrink(ae_dynamic_block_t *self);

/**
 * @brief Резервирует место для заданного количества элементов в динамическом блоке.
 *
 * Эта функция увеличивает размер динамического блока, если текущая ёмкость блока
 * недостаточна для размещения указанного количества элементов. При необходимости,
 * ёмкость блока увеличивается с учетом коэффициента роста, чтобы обеспечить
 * достаточное пространство для новых элементов.
 *
 * @param self Указатель на динамический блок, в котором необходимо зарезервировать место.
 * @param number_of_elements Количество элементов, для которых нужно зарезервировать место.
 *
 * @return `true`, если место для элементов было успешно зарезервировано;
 *         `false`, если указатель `self` равен `nullptr`,
 *                  или если произошла ошибка при выделении памяти.
 *
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель `begin` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить достаточно памяти для нового блока.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти недействителен.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 *
 * @see ae_dynamic_block_capacity
 * @see ae_dynamic_block_size
 * @see ae_unified_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_dynamic_block_reserve(ae_dynamic_block_t *self, ae_usize_t number_of_elements);

/**
 * @brief Изменяет количество элементов в динамическом блоке.
 *
 * Эта функция изменяет количество элементов в динамическом блоке.
 * Если текущая ёмкость блока недостаточна для указанного количества элементов,
 * блок автоматически изменяет свой размер с использованием функции `ae_unified_block_resize`.
 *
 * @param self Указатель на динамический блок, в котором необходимо изменить количество элементов.
 * @param size Новое количество элементов, которое должно быть в блоке.
 *
 * @return `true`, если размер блока был успешно изменен;
 *         `false`, если указатель на `self` равен `nullptr`
 *                  или если возникли ошибки в процессе изменения размера.
 *
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если указатель на функцию выделения памяти равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель `begin` равен `nullptr`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить достаточно памяти для блока.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти недействителен.
 * @throw AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE
 *        Если размер элемента равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 *
 * @see ae_dynamic_block_capacity
 * @see ae_unified_block_resize
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_dynamic_block_resize(ae_dynamic_block_t *self, ae_usize_t size);

/**
 * @brief Сравнивает количество элементов
 *        в динамическом блоке памяти с заданным размером.
 *
 * Эта функция проверяет, равно ли текущее количество элементов в динамическом
 * блоке памяти заданному значению размера. Если указатель на блок памяти равен
 * `nullptr`, функция вызывает ошибку времени выполнения.
 *
 * @param self Указатель на динамический блок памяти,
 *             который необходимо проверить.
 * @param size Размер, с которым будет производиться сравнение.
 *
 * @return true Если текущее количество элементов в динамическом блоке
 *              памяти равно заданному размеру.
 * @return false Если текущее количество элементов в динамическом блоке
 *               памяти не равно заданному размеру.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_dynamic_block_size
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_dynamic_block_is_size_equal_to(const ae_dynamic_block_t *self, ae_usize_t size);

/**
 * @brief Сравнивает количество элементов в двух динамических блоках памяти.
 *
 * Эта функция проверяет, равно ли количество элементов в одном динамическом
 * блоке памяти количеству элементов в другом динамическом блоке памяти. Если
 * любой из указателей на блоки памяти равен `nullptr`, функция вызывает ошибку
 * времени выполнения.
 *
 * @param self Указатель на первый динамический блок памяти,
 *             который необходимо проверить.
 * @param other Указатель на второй динамический блок памяти,
 *              размер которого будет использоваться для сравнения.
 *
 * @return true Если количество элементов в первом динамическом блоке
 *              памяти равно количеству элементов во втором блоке.
 * @return false Если количество элементов в первом динамическом блоке
 *               памяти не равно количеству элементов во втором блоке.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `null`.
 *
 * @see ae_dynamic_block_size
 * @see ae_dynamic_block_is_size_equal_to
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_dynamic_block_is_size_equal(const ae_dynamic_block_t *self, const ae_dynamic_block_t *other);

/**
 * @brief Сравнивает количество элементов в двух динамических блоках памяти.
 *
 * Эта функция проверяет, равно ли количество элементов в одном динамическом
 * блоке памяти количеству элементов в другом динамическом блоке памяти. Если
 * любой из указателей на блоки памяти равен `nullptr`, функция вызывает ошибку
 * времени выполнения.
 *
 * @param self Указатель на первый динамический блок памяти,
 *             который необходимо проверить.
 * @param other Указатель на второй динамический блок памяти,
 *              размер которого будет использоваться для сравнения.
 *
 * @return `true` Если количество элементов в первом динамическом блоке
 *                памяти равно количеству элементов во втором блоке.
 * @return `false` Если количество элементов в первом динамическом блоке
 *                 памяти не равно количеству элементов во втором блоке.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `null`.
 *
 * @see ae_dynamic_block_size
 * @see ae_dynamic_block_is_size_equal_to
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_dynamic_block_is_equal(const ae_dynamic_block_t *self, const ae_dynamic_block_t *other);

AE_COMPILER(EXTERN_C_END)

#endif // DYNAMIC_BLOCK_H
