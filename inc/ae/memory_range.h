/**
 * @file memory_range.h
 * @brief Заголовочный файл для работы с диапазонами памяти.
 *
 * Этот файл содержит определения и функции для управления диапазонами памяти,
 * представляемыми структурой `ae_memory_range`. Функции позволяют получать доступ
 * к началу и концу диапазона, вычислять его размер, проверять валидность,
 * а также выполнять различные операции, такие как сброс, обмен,
 * проверка на пустоту и принадлежность указателя диапазону.
 *
 * Этот файл также обеспечивает безопасную работу с диапазоном памяти,
 * учитывая безопасность указателей и обработку ошибок с использованием макросов
 * для генерации исключений при ошибках (например, `AE_RUNTIME_ERROR_NULL_POINTER`).
 */

#ifndef AE_MEMORY_RANGE_H
#define AE_MEMORY_RANGE_H

#include "memory_range_fields.h"
#include "attribute.h"
#include "ptrdiff.h"
#include "size.h"
#include "bool.h"

/**
 * @struct ae_memory_range
 * @brief Структура, представляющая диапазон памяти.
 *
 * Эта структура содержит два указателя, которые определяют начало и конец
 * диапазона памяти. Она используется для работы с массивами и другими
 * структурами данных, представляющими диапазоны.
 */
typedef struct ae_memory_range
{
    AE_MEMORY_RANGE_FIELDS(void);
} ae_memory_range_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает указатель на начало диапазона памяти.
 *
 * Эта функция возвращает указатель на начало диапазона памяти,
 * определенного в структуре `ae_memory_range`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             из которой нужно получить указатель на начало диапазона.
 *
 * @return Указатель на начало диапазона памяти (begin) из структуры,
 *         или `null`, если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_range_begin(ae_memory_range_t *self);

/**
 * @brief Получает указатель на начало области памяти.
 *
 * Эта функция возвращает указатель на начало области памяти,
 * представленной структурой ae_memory_range_t.
 *
 * Она служит оберткой для функции ae_memory_range_begin_const,
 * обеспечивая безопасный доступ к началу области памяти
 * для константного указателя.
 *
 * @param self Указатель на структуру ae_memory_range_t,
 *             представляющую область памяти.
 *
 * @return Указатель на начало области памяти, или NULL,
 *         если область памяти пуста.
 *
 * @note Эта функция предназначена для использования с
 *       константными объектами ae_memory_range_t.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin_const
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_range_begin_const(const ae_memory_range_t *self);

/**
 * @brief Получает указатель на конец диапазона памяти.
 *
 * Эта функция возвращает указатель на конец диапазона памяти,
 * определенного в структуре `ae_memory_range`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             из которой нужно получить указатель на конец диапазона.
 *
 * @return Указатель на конец диапазона памяти (end) из структуры,
 *         или `null`, если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_range_end(ae_memory_range_t *self);

/**
 * @brief Получает указатель на конец области памяти.
 *
 * Эта функция возвращает указатель на конец области памяти,
 * представленной структурой ae_memory_range_t.
 *
 * Она служит оберткой для функции ae_memory_range_end_const,
 * обеспечивая безопасный доступ к концу области памяти
 * для константного указателя.
 *
 * @param self Указатель на структуру ae_memory_range_t,
 *             представляющую область памяти.
 *
 * @return Указатель на конец области памяти, или NULL,
 *         если область памяти пуста.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @note Эта функция предназначена для использования с
 *       константными объектами ae_memory_range_t.
 *
 * @see ae_memory_range
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_range_end_const(const ae_memory_range_t *self);

/**
 * @brief Проверяет, является ли диапазон памяти пустым.
 *
 * Эта функция определяет, пуст ли диапазон памяти, представленный
 * структурой `ae_memory_range`. Диапазон считается пустым, если
 * указатели на начало и конец диапазона равны.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которую необходимо проверить на пустоту.
 *
 * @return `true`, если диапазон памяти пустой (начало равно концу);
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_is_null
 * @see ae_memory_range_begin_const
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_empty(const ae_memory_range_t *self);

/**
 * @brief Вычисляет разницу между началом и концом диапазона памяти.
 *
 * Эта функция возвращает разницу (в байтах) между указателями на начало
 * и конец диапазона памяти, представленного структурой `ae_memory_range`.
 * Если диапазон пуст, функция вернет 0.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             для которой необходимо вычислить разницу.
 *
 * @return Разница в байтах между концом и началом диапазона.
 *         Если диапазон пуст, возвращается 0.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin_const
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
ae_ptrdiff_t
ae_memory_range_diff(const ae_memory_range_t *self);

/**
 * @brief Проверяет корректность диапазона памяти.
 *
 * Функция выполняет валидацию диапазона памяти.
 * - Для пустого диапазона возвращается `true`.
 * - Для непустого диапазона проверяется, что начальный
 *   указатель находится внутри допустимого диапазона памяти.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которую необходимо проверить.
 *
 * @return `true`, если диапазон памяти корректен:
 *         - диапазон пуст, либо
 *         - начальный указатель находится в пределах диапазона;
 *         `false` в противном случае.
 *
 * @note Пустой диапазон всегда считается валидным.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range_empty
 * @see ae_memory_range_begin_const
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_check(const ae_memory_range_t *self);

/**
 * @brief Проверяет, содержится ли указатель в диапазоне памяти.
 *
 * Эта функция проверяет, находится ли указатель `ptr` внутри диапазона памяти,
 * определенного в структуре `ae_memory_range`. При этом можно указать,
 * включать ли конец диапазона в проверку.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которая определяет диапазон памяти.
 *
 * @param ptr Указатель, который необходимо проверить на принадлежность диапазону.
 * @param inclusive Флаг, указывающий, нужно ли включать конец диапазона в проверку.
 *                  Если `true`, то проверяется, что `ptr` меньше или равен
 *                  концу диапазона. Если `false`, то проверяется, что `ptr`
 *                  меньше конца диапазона.
 *
 * @return `true`, если указатель `ptr` находится в диапазоне памяти,
 *         иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 *
 * @see ae_memory_range
 * @see ae_memory_range_check
 * @see ae_memory_range_begin_const
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_has_ptr(const ae_memory_range_t *self, const void *ptr, bool inclusive);

/**
 * @brief Вычисляет общий размер диапазона памяти.
 *
 * Эта функция возвращает общий размер (в байтах) диапазона памяти,
 * представленного структурой `ae_memory_range`.
 *
 * Перед вызовом функции проверяется валидность диапазона памяти.
 * Если диапазон не валиден, вызывается ошибка времени выполнения.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             для которой необходимо вычислить общий размер.
 *
 * @return Общий размер диапазона памяти в байтах.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_check
 * @see ae_memory_range_diff
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_range_total_size(const ae_memory_range_t *self);

/**
 * @brief Проверяет, является ли общий размер диапазона памяти
 *        кратным заданному размеру элемента.
 *
 * Эта функция вычисляет общий размер диапазона памяти, представленного
 * структурой `ae_memory_range`, и проверяет, является ли он кратным
 * заданному размеру элемента. Если размер элемента равен нулю,
 * вызывается ошибка времени выполнения.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             для которой необходимо проверить кратность.
 * @param element_size Размер элемента, на кратность которого
 *                    проверяется общий размер диапазона.
 *
 * @return true, если общий размер диапазона памяти кратен
 *         заданному размеру элемента; иначе - false.
 *
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_total_size
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_total_size_multiple_of(const ae_memory_range_t *self, ae_usize_t element_size);

/**
 * @brief Проверяет выравнивание начала и конца диапазона памяти.
 *
 * Эта функция проверяет, выровнены ли начало и конец диапазона памяти,
 * представленного в структуре `ae_memory_range`, по заданному размеру выравнивания.
 *
 * @param self Указатель на структуру `ae_memory_range`, для которой
 *             необходимо проверить выравнивание.
 * @param alignment_size Требуемый размер выравнивания в байтах.
 *
 * @return `true`, если как начало, так и конец диапазона выровнены
 *         по указанному размеру; `false` в противном случае.
 *
 * @note Если указатель на `self` равен `null`, функция вернет `false`.
 *       Значение `alignment_size` должно быть степенью двойки, иначе
 *       результат может быть некорректным.
 *
 * @throw AE_RUNTIME_ERROR_DIVISION_BY_ZERO
 *        Если `element_size` равен нулю.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range_cbegin
 * @see ae_memory_range_cend
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_align_of(const ae_memory_range_t *self, ae_usize_t alignment_size);

/**
 * @brief Вычисляет количество элементов в диапазоне памяти.
 *
 * Эта функция возвращает количество элементов в диапазоне памяти,
 * представленного структурой `ae_memory_range`, исходя из заданного
 * размера элемента. Перед вычислением количества элементов проверяется,
 * является ли общий размер диапазона кратным размеру элемента. Если
 * это не так, вызывается ошибка времени выполнения.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             для которой необходимо вычислить количество элементов.
 * @param element_size Размер элемента, на основе которого
 *                    вычисляется количество элементов в диапазоне.
 *
 * @return Количество элементов в диапазоне памяти.
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
 * @see ae_memory_range
 * @see ae_memory_range_total_size
 * @see ae_memory_range_total_size_multiple_of
 */
AE_ATTRIBUTE(SYMBOL)
ae_usize_t
ae_memory_range_size(const ae_memory_range_t *self, ae_usize_t element_size);

/**
 * @brief Сбрасывает начало и конец диапазона памяти.
 *
 * Эта функция устанавливает новые значения начала и конца диапазона памяти
 * для структуры `ae_memory_range`. Функция последовательно вызывает
 * `ae_memory_range_reset_begin` и `ae_memory_range_reset_end`
 * для установки новых значений.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             для которой необходимо сбросить диапазон.
 * @param begin Указатель на новое значение начала диапазона памяти.
 * @param end Указатель на новое значение конца диапазона памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_reset(ae_memory_range_t *self, void *begin, void *end);

/**
 * @brief Присваивает диапазон памяти из другой структуры.
 *
 * Эта функция копирует границы диапазона памяти из структуры `other`
 * в структуру `self`. Она использует функции для получения начала
 * и конца диапазона из `other`, а затем сбрасывает `self`
 * с новыми значениями.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             в которую необходимо присвоить диапазон.
 * @param other Указатель на структуру `ae_memory_range`,
 *              из которой будет скопирован диапазон.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
 * @see ae_memory_range_reset
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_assign(ae_memory_range_t *self, ae_memory_range_t *other);

/**
 * @brief Присваивает диапазон памяти из другой структуры с валидацией.
 *
 * Эта функция сначала проверяет, является ли диапазон памяти в структуре `other`
 * корректным с помощью функции `ae_memory_range_check`. Если диапазон
 * невалиден, вызывается ошибка времени выполнения. Если диапазон валиден,
 * функция копирует границы диапазона из `other` в `self`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             в которую необходимо присвоить диапазон.
 * @param other Указатель на структуру `ae_memory_range`,
 *              из которой будет скопирован диапазон.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти в `other` невалиден.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` или `other` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_check
 * @see ae_memory_range_assign
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_assign_with_validate(ae_memory_range_t *self, ae_memory_range_t *other);

/**
 * @brief Сбрасывает диапазон памяти с валидацией.
 *
 * Эта функция инициализирует временную структуру `ae_memory_range`
 * с заданными границами `begin` и `end`, а затем вызывает функцию
 * `ae_memory_range_assign_with_validate` для присвоения этого
 * диапазона памяти в структуру `self`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которую необходимо сбросить с новым диапазоном.
 * @param begin Указатель на начало нового диапазона памяти.
 * @param end Указатель на конец нового диапазона памяти.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если создаваемый диапазон памяти невалиден.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_assign_with_validate
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_reset_with_validate(ae_memory_range_t *self, void *begin, void *end);

/**
 * @brief Сбрасывает диапазон памяти с заданным размером.
 *
 * Эта функция устанавливает диапазон памяти в структуре `self`, используя
 * указатель на начало диапазона `begin` и размер `size_in_bytes`.
 * Сначала проверяется, что указатель `begin` не равен `null`.
 *
 * Затем вычисляется конечный адрес диапазона,
 * который получается путем добавления размера `size_in_bytes` к `begin`.
 * После этого вызывается функция `ae_memory_range_reset_with_validate`
 * для сброса диапазона с валидацией.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которую необходимо сбросить с новым диапазоном.
 * @param begin Указатель на начало нового диапазона памяти.
 * @param size_in_bytes Размер диапазона в байтах.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_ARGUMENT
 *        Если указатель `begin` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_reset_with_validate
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_reset_with_size(ae_memory_range_t *self, void *begin, ae_usize_t size_in_bytes);

/**
 * @brief Сбрасывает диапазон памяти в зависимости
 *        от предоставленного указателя и размера.
 *
 * Эта функция проверяет, является ли указатель `begin` действительным (не нулевым).
 * Если он действителен, диапазон памяти сбрасывается с использованием указанного размера.
 * Если указатель `begin` равен нулю, то диапазон памяти очищается.
 *
 * @param self Указатель на структуру диапазона памяти, которую необходимо изменить.
 * @param begin Указатель на начало диапазона памяти.
 *              Если этот указатель равен нулю, диапазон памяти будет очищен.
 * @param size_in_bytes Размер диапазона памяти в байтах для сброса.
 *                      Этот параметр игнорируется, если `begin` равен нулю.
 *
 * @note Эта функция проверяет, что указатель `self` не равен нулю.
 *
 * @warning Убедитесь, что `size_in_bytes` является допустимым и не превышает
 *          выделенный диапазон памяти, чтобы избежать неопределенного поведения.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range_reset_with_size
 * @see ae_memory_range_clear
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_reset_with_fallback(ae_memory_range_t *self, void *begin, ae_usize_t size_in_bytes);

/**
 * @brief Очищает диапазон памяти.
 *
 * Эта функция сбрасывает диапазон памяти в структуре `self`, устанавливая
 * его границы в `nullptr`. Это может использоваться для освобождения
 * или инициализации диапазона памяти в структуре.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которую необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `nullptr`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_reset
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_clear(ae_memory_range_t *self);

/**
 * @brief Меняет местами два диапазона памяти.
 *
 * Эта функция меняет местами содержимое двух структур `ae_memory_range`,
 * указанных в параметрах `self` и `other`. Для этого создается временная
 * структура `interim`, которая используется для хранения данных во время
 * обмена.
 *
 * @param self Указатель на первую структуру `ae_memory_range`,
 *             которую необходимо обменять.
 * @param other Указатель на вторую структуру `ae_memory_range`,
 *              с которой будет произведен обмен.
 *
 * @warning Если какое-либо из назначений внутри процесса обмена завершается неудачно,
 *          исключение распространяется с помощью `ae_runtime_rethrow`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_assign
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_swap(ae_memory_range_t *self, ae_memory_range_t *other);

/**
 * @brief Очищает и меняет местами два диапазона памяти.
 *
 * Эта функция сначала очищает содержимое структуры `self`,
 * а затем меняет местами содержимое двух структур `ae_memory_range`,
 * указанных в параметрах `self` и `other`.
 *
 * @param self Указатель на первую структуру `ae_memory_range`,
 *             которую необходимо очистить и обменять.
 * @param other Указатель на вторую структуру `ae_memory_range`,
 *              с которой будет произведен обмен.
 *
 * @warning Если операция очистки или обмена завершается неудачно,
 *          исключение распространяется с помощью `ae_runtime_rethrow`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_clear
 * @see ae_memory_range_swap
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_exchange(ae_memory_range_t *self, ae_memory_range_t *other);

/**
 * @brief Проверяет, содержится ли диапазон памяти внутри другого диапазона.
 *
 * Эта функция проверяет, находится ли указанный диапазон памяти,
 * определяемый указателями `begin` и `end`, внутри диапазона памяти,
 * определенного в структуре `ae_memory_range`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которая определяет основной диапазон памяти.
 * @param begin Указатель на начало проверяемого диапазона памяти.
 * @param end Указатель на конец проверяемого диапазона памяти.
 * @param inclusive Флаг, указывающий, нужно ли включать конец проверяемого
 *                  диапазона в проверку. Если `true`, то проверяется, что
 *                  `end` находится внутри основного диапазона; если `false`,
 *                  то проверяется, что `end` меньше конца основного диапазона.
 *
 * @return `true`, если проверяемый диапазон памяти находится внутри
 *         основного диапазона, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти не валиден.
 *
 * @see ae_memory_range
 * @see ae_memory_range_check
 * @see ae_memory_range_has_ptr
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_has_ptr_range(const ae_memory_range_t *self,
                              const void              *begin,
                              const void              *end,
                              bool                     inclusive);

/**
 * @brief Получает указатель на элемент в диапазоне памяти по смещению.
 *
 * Эта функция возвращает указатель на элемент в диапазоне памяти,
 * вычисляемый по заданному смещению от начала диапазона.
 * Функция не проверяет границы диапазона, поэтому использование
 * некорректного смещения может привести к неопределенному поведению.
 *
 * @param self Указатель на структуру @ref ae_memory_range,
 *             из которой необходимо получить элемент.
 * @param offset Смещение от начала диапазона
 *               для получения указателя на элемент.
 *
 * @return Указатель на элемент в диапазоне памяти,
 *         вычисленный по смещению.
 *
 * @warning Использование этой функции с некорректным смещением
 *          может привести к ошибкам выполнения и неопределенному поведению.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_range_begin
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_range_at_unsafe(ae_memory_range_t *self, ae_usize_t offset);

/**
 * @brief Получает указатель на элемент
 *        в диапазоне памяти по смещению с проверкой границ.
 *
 * Эта функция возвращает указатель на элемент в диапазоне памяти,
 * вычисляемый по заданному смещению от начала диапазона.
 *
 * В отличие от функции @ref ae_memory_range_at_unsafe, эта функция
 * проверяет, находится ли полученный указатель в пределах допустимого диапазона.
 * Если указатель выходит за пределы диапазона, выбрасывается ошибка.
 *
 * @param self Указатель на структуру @ref ae_memory_range,
 *             из которой необходимо получить элемент.
 * @param offset Смещение от начала диапазона для получения указателя на элемент.
 *
 * @return Указатель на элемент в диапазоне памяти,
 *         вычисленный по смещению.
 *
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указатель выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_range_at_unsafe
 * @see ae_memory_range
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_range_at(ae_memory_range_t *self, ae_usize_t offset);

/**
 * @brief Получает указатель на элемент в диапазоне памяти
 *        по смещению для константного диапазона.
 *
 * Эта функция возвращает указатель на элемент в диапазоне памяти,
 * вычисляемый по заданному смещению от начала диапазона, для константного
 * диапазона памяти. Она использует функцию @ref ae_memory_range_at для
 * получения указателя и гарантирует, что диапазон не будет изменен.
 *
 * @param self Указатель на константную структуру @ref ae_memory_range,
 *             из которой необходимо получить элемент.
 * @param offset Смещение от начала диапазона
 *               для получения указателя на элемент.
 *
 * @return Указатель на элемент в диапазоне памяти,
 *         вычисленный по смещению.
 *
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указатель выходит за пределы допустимого диапазона.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_NULL_POINTER_AT_RANGE_BEGIN
 *        Если указатель на начало участка памяти равен `null`.
 *
 * @see ae_memory_range_at
 * @see ae_memory_range
 * @see ae_memory_range_begin_const
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_range_at_const(const ae_memory_range_t *self, ae_usize_t offset);

/**
 * @brief Сравнивает указатель на начало диапазона памяти с заданным указателем.
 *
 * Эта функция проверяет, равен ли указатель на начало диапазона памяти,
 * определенного в структуре `ae_memory_range`, заданному указателю.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которая содержит диапазон памяти.
 * @param ptr Указатель на область памяти,
 *            с которой нужно сравнить начало диапазона.
 *
 * @return Возвращает `true`, если указатель на начало диапазона памяти
 *         равен заданному указателю `begin`, иначе возвращает `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin_const
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_begin_equal_to(const ae_memory_range_t *self, const void *ptr);

/**
 * @brief Сравнивает указатель на конец диапазона памяти с заданным указателем.
 *
 * Эта функция проверяет, равен ли указатель на конец диапазона памяти,
 * определенного в структуре `ae_memory_range`, заданному указателю.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которая содержит диапазон памяти.
 * @param ptr Указатель на область памяти,
 *            с которой нужно сравнить конец диапазона.
 *
 * @return Возвращает `true`, если указатель на конец диапазона памяти
 *         равен заданному указателю `end`, иначе возвращает `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_end_const
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_end_equal_to(const ae_memory_range_t *self, const void *ptr);

/**
 * @brief Сравнивает указатель на начало диапазона памяти с началом другого диапазона.
 *
 * Эта функция проверяет, равен ли указатель на начало диапазона памяти,
 * определенного в структуре `ae_memory_range`, началу диапазона,
 * определенного в другой структуре `ae_memory_range`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которая содержит диапазон памяти для сравнения.
 * @param other Указатель на структуру `ae_memory_range`,
 *              с началом которой нужно сравнить начало первого диапазона.
 *
 * @return Возвращает `true`, если указатель на начало диапазона памяти
 *         из `self` равен началу диапазона памяти из `other`, иначе
 *         возвращает `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin_equal_to
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_begin_equal(const ae_memory_range_t *self, const ae_memory_range_t *other);

/**
 * @brief Сравнивает указатель на конец диапазона памяти с концом другого диапазона.
 *
 * Эта функция проверяет, равен ли указатель на конец диапазона памяти,
 * определенного в структуре `ae_memory_range`, концу диапазона,
 * определенного в другой структуре `ae_memory_range`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             которая содержит диапазон памяти для сравнения.
 * @param other Указатель на структуру `ae_memory_range`,
 *              с концом которой нужно сравнить конец первого диапазона.
 *
 * @return Возвращает `true`, если указатель на конец диапазона памяти
 *         из `self` равен концу диапазона памяти из `other`, иначе
 *         возвращает `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_end_equal_to
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_end_equal(const ae_memory_range_t *self, const ae_memory_range_t *other);

/**
 * @brief Сравнивает два диапазона памяти на равенство.
 *
 * Эта функция проверяет, равны ли начало и конец диапазонов памяти,
 * определенных в структурах `ae_memory_range`. Она возвращает `true`,
 * если оба диапазона равны, и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             представляющую первый диапазон памяти.
 * @param other Указатель на структуру `ae_memory_range`,
 *              представляющую второй диапазон памяти для сравнения.
 *
 * @return Возвращает `true`, если диапазоны памяти из `self` и `other`
 *         равны (то есть их начало и конец совпадают), иначе
 *         возвращает `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin_equal
 * @see ae_memory_range_end_equal
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_equal(const ae_memory_range_t *self, const ae_memory_range_t *other);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_RANGE_H
