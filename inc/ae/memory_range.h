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
 * Она служит оберткой для функции ae_memory_range_begin,
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
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_range_cbegin(const ae_memory_range_t *self);

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
 * Она служит оберткой для функции ae_memory_range_end,
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
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_range_cend(const ae_memory_range_t *self);

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
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
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
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
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
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
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
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_contain_ptr(const ae_memory_range_t *self, const void *ptr, bool inclusive);

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
 * @brief Создает диапазон памяти.
 *
 * Эта функция инициализирует и возвращает структуру диапазона памяти
 * на основе указателей начала и конца.
 *
 * @param begin Указатель на начало диапазона памяти.
 * @param end Указатель на конец диапазона памяти.
 * @return Структура диапазона памяти,
 *         инициализированная с заданными указателями.
 *
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_range_t
ae_memory_range_make(void *begin, void *end);

/**
 * @brief Создает пустой диапазон памяти.
 *
 * Функция возвращает диапазон памяти с нулевыми указателями начала и конца,
 * что представляет собой пустой или недействительный диапазон.
 *
 * @return Пустая структура диапазона памяти с указателями,
 *         установленными в nullptr.
 *
 * @note Пустой диапазон памяти может использоваться как маркер
 *       отсутствия или инициализации диапазона.
 *
 * @warning Операции с пустым диапазоном памяти могут привести к ошибкам,
 *          если не будет выполнена дополнительная проверка.
 *
 * @see ae_memory_range
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_range_t
ae_memory_range_make_empty();

/**
 * @brief Создает диапазон памяти с валидацией указателей.
 *
 * Эта функция проверяет, что указатели `begin` и `end` образуют допустимый
 * диапазон памяти, используя макрос `ae_ptr_range_validate`.
 *
 * - Если диапазон действителен, функция инициализирует
 *   и возвращает структуру диапазона памяти с заданными указателями.
 * - В противном случае возвращается пустой диапазон памяти.
 *
 * @param begin Указатель на начало диапазона памяти.
 * @param end Указатель на конец диапазона памяти.
 * @return Структура диапазона памяти, инициализированная с заданными
 *         указателями, или пустая структура, если диапазон недействителен.
 *
 * @note Используйте эту функцию для безопасного создания диапазона памяти,
 *       чтобы избежать ошибок, связанных с недопустимыми указателями.
 *
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если создаваемый диапазон памяти невалиден.
 *
 * @see ae_memory_range_make
 * @see ae_memory_range_make_empty
 * @see ae_ptr_range_validate
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_range_t
ae_memory_range_make_with_validate(void *begin, void *end);

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
 * @brief Выполняет поверхностное копирование диапазона памяти.
 *
 * Функция создает новую структуру диапазона памяти с теми же
 * указателями начала и конца, что и исходный диапазон.
 *
 * @param self Указатель на исходную структуру диапазона памяти.
 * @return Новый диапазон памяти с идентичными указателями начала и конца.
 *
 * @note Создается точная копия структуры диапазона без копирования
 *       содержимого памяти. Указатели на начало и конец остаются
 *       прежними, что означает ссылку на те же области памяти.
 *
 * @warning Не создает глубокой копии данных,
 *          а только копирует указатели.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range_make
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_range_t
ae_memory_range_shallow_copy(ae_memory_range_t *self);

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
 *
 * @see ae_memory_range
 * @see ae_memory_range_check
 * @see ae_memory_range_contain_ptr
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_memory_range_contain_range(const ae_memory_range_t *self,
                              const void              *begin,
                              const void              *end,
                              bool                     inclusive);

/**
 * @brief Получает указатель на элемент диапазона памяти по заданному индексу.
 *
 * Эта функция возвращает указатель на элемент диапазона памяти,
 * определенного в структуре `ae_memory_range`, по указанному индексу.
 *
 * Функция не проверяет, находится ли индекс в допустимых пределах,
 * поэтому использование недопустимого индекса может привести
 * к неопределенному поведению.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             из которой нужно получить указатель на элемент.
 *
 * @param index Индекс элемента,
 *              для которого нужно получить указатель.
 *
 * @return Указатель на элемент диапазона памяти, находящийся по заданному индексу,
 *         или `null`, если указатель на `self` равен `null`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_range
 * @see ae_memory_range_begin
 * @see ae_ptr_add
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_range_at_unsafe(const ae_memory_range_t *self, ae_usize_t index);

/**
 * @brief Получает указатель на элемент диапазона памяти
 *        по заданному индексу с проверкой границ.
 *
 * Эта функция возвращает указатель на элемент диапазона памяти,
 * определенного в структуре `ae_memory_range`,
 * по указанному индексу.
 *
 * В отличие от `ae_memory_range_at_unsafe`, эта функция проверяет,
 * находится ли полученный указатель в пределах диапазона памяти.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             из которой нужно получить указатель на элемент.
 *
 * @param index Индекс элемента,
 *              для которого нужно получить указатель.
 *
 * @return Указатель на элемент диапазона памяти,
 *         находящийся по заданному индексу,
 *         если индекс находится в допустимых пределах.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если полученный указатель находится за пределами диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти, указанный в `self`, невалиден.
 *
 * @see ae_memory_range
 * @see ae_memory_range_at_unsafe
 * @see ae_memory_range_contain_ptr
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_range_at(const ae_memory_range_t *self, ae_usize_t index);

/**
 * @brief Вставляет значение в указанный индекс диапазона памяти.
 *
 * Данная функция вставляет значение `value` в диапазон памяти,
 * начиная с индекса `index`. Если индекс выходит за пределы диапазона,
 * будет вызвано исключение.
 *
 * @param self Указатель на объект типа ae_memory_range_t,
 *             представляющий диапазон памяти, в который нужно вставить значение.
 * @param index Индекс, по которому будет вставлено значение.
 *              Должен быть в пределах допустимого диапазона.
 * @param value Значение, которое будет вставлено в диапазон памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если полученный указатель находится за пределами диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти, указанный в `self`, невалиден.
 *
 * @see ae_memory_range_at
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_insert(ae_memory_range_t *self, ae_usize_t index, ae_u8_t value);

/**
 * @brief Вставляет диапазон памяти в заданную позицию.
 *
 * Эта функция вставляет указанный диапазон памяти, определяемый
 * указателями `begin` и `end`, в диапазон памяти, представленный
 * структурой `ae_memory_range`, начиная с указанной позиции.
 *
 * Функция проверяет, что указатель `begin` не является нулевым,
 * а затем копирует данные из указанного диапазона в целевой диапазон
 * памяти, начиная с позиции `position`.
 *
 * @param self Указатель на структуру `ae_memory_range`,
 *             в которую нужно вставить диапазон памяти.
 *
 * @param position Позиция, с которой необходимо начать вставку.
 *                 Индекс должен быть в пределах существующего диапазона.
 *
 * @param begin Указатель на начало диапазона памяти,
 *              который будет вставлен.
 *
 * @param end Указатель на конец диапазона памяти,
 *            который будет вставлен.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `begin` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указанная позиция находится за пределами диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если диапазон памяти, указанный в `self`, невалиден.
 *
 * @see ae_memory_range
 * @see ae_memory_raw_copy
 * @see ae_memory_range_at
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_insert_range(ae_memory_range_t *self,
                             ae_usize_t         position,
                             const void        *begin,
                             const void        *end);

/**
 * @brief Вставляет содержимое одного диапазона памяти в другой.
 *
 * Эта функция вставляет содержимое диапазона памяти `other` в диапазон
 * памяти `self`, начиная с указанной позиции. Функция использует
 * `ae_memory_range_insert_range` для выполнения фактической операции вставки.
 *
 * @param self Указатель на целевую структуру `ae_memory_range`,
 *             в которую будет производиться вставка.
 *
 * @param position Позиция в целевом диапазоне, с которой
 *                начнется вставка. Должна быть в пределах
 *                существующего диапазона.
 *
 * @param other Указатель на структуру `ae_memory_range`,
 *              содержимое которой будет вставлено.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `other` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указанная позиция находится за пределами целевого диапазона.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если какой-либо из диапазонов памяти невалиден.
 *
 * @see ae_memory_range
 * @see ae_memory_range_insert_range
 * @see ae_memory_range_begin
 * @see ae_memory_range_end
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_insert_other(ae_memory_range_t       *self,
                             ae_usize_t               position,
                             const ae_memory_range_t *other);

/**
 * @brief Вставляет содержимое одного диапазона памяти в другой с предварительной валидацией.
 *
 * Эта функция работает аналогично `ae_memory_range_insert_other`, но перед вставкой
 * выполняет проверку корректности входного диапазона памяти `other`. Если диапазон
 * памяти невалиден, генерируется исключение.
 *
 * @param self Указатель на целевую структуру `ae_memory_range`,
 *             в которую будет производиться вставка.
 *
 * @param position Позиция в целевом диапазоне, с которой
 *                начнется вставка. Должна быть в пределах
 *                существующего диапазона.
 *
 * @param other Указатель на структуру `ae_memory_range`,
 *              содержимое которой будет вставлено.
 *              Диапазон должен быть валидным.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `other` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если указанная позиция находится за пределами целевого диапазона.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если какой-либо из диапазонов памяти невалиден.
 *
 * @see ae_memory_range
 * @see ae_memory_range_insert_other
 * @see ae_memory_range_check
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_range_insert_other_with_validate(ae_memory_range_t       *self,
                                           ae_usize_t               position,
                                           const ae_memory_range_t *other);

/**
 * @brief Создает поддиапазон памяти из существующего диапазона.
 *
 * Эта функция создает новый диапазон памяти, который является поддиапазоном
 * указанного диапазона `self`. Перед созданием поддиапазона выполняется
 * проверка, что указанный диапазон (от `begin` до `end`) содержится в
 * диапазоне `self`. Если проверка не проходит, генерируется ошибка
 * времени выполнения, и возвращается пустой диапазон памяти.
 *
 * @param self Указатель на существующий диапазон памяти,
 *             из которого будет создан поддиапазон.
 * @param begin Указатель на начало поддиапазона.
 * @param end Указатель на конец поддиапазона.
 * @param inclusive Флаг, указывающий, включать ли указатели `begin` и
 *                  `end` в поддиапазон (true - включить, false - исключить).
 *
 * @return Структура диапазона памяти, представляющая поддиапазон,
 *         или пустая структура, если диапазон недействителен.
 *
 * @note Убедитесь, что указатели `begin` и `end` находятся
 *       в пределах диапазона `self`, чтобы избежать ошибок.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_OUT_OF_RANGE
 *        Если полученный указатель находится за пределами диапазона памяти.
 * @throw AE_RUNTIME_ERROR_INVALID_MEMORY_RANGE
 *        Если создаваемый диапазон памяти невалиден.
 *
 * @see ae_memory_range
 * @see ae_memory_range_make_with_validate
 * @see ae_memory_range_contain_range
 * @see ae_memory_range_make_empty
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_range_t
ae_memory_range_make_sub_range(const ae_memory_range_t *self,
                               void                    *begin,
                               void                    *end,
                               bool                     inclusive);

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
 * @see ae_memory_range_begin
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
 * @see ae_memory_range_end
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
