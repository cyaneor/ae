/**
 * @file error.h
 * @brief Определение структуры и функций для работы с ошибками.
 *
 * Этот файл содержит определение структуры `ae_error_t`,
 * которая используется для хранения информации об ошибках в программе.
 *
 * Также предоставляются функции для манипуляций с ошибками,
 * такие как извлечение кода ошибки, сообщения об ошибке,
 * сброс состояния ошибки и проверка на равенство между ошибками.
 *
 * @note Файл включает в себя функции для работы с кодами и сообщениями об ошибках,
 *       а также механизмы для их логирования и диагностики.
 *
 * @see ae_error_t
 * @see ae_error_code_t
 * @see ae_error_message_t
 */

#ifndef AE_ERROR_H
#define AE_ERROR_H

#include "bool.h"
#include "attribute.h"
#include "error_code.h"
#include "error_message.h"

/**
 * @struct ae_error
 * @brief Структура для хранения информации об ошибке.
 *
 * Эта структура используется для представления ошибки в программе.
 * Она содержит код ошибки и сопутствующее сообщение,
 * что позволяет удобно и понятно обрабатывать ошибки в коде.
 *
 * Структура может быть использована для передачи информации
 * о произошедшей ошибке между различными частями программы,
 * а также для логирования и диагностики.
 *
 * @see ae_error_code_t
 * @see ae_error_message_t
 */
typedef struct ae_error
{
    /**
     * @var ae_error::code
     * @brief Код ошибки.
     *
     * Это поле хранит код ошибки, который указывает на тип проблемы.
     * Тип данных `ae_error_code_t` определяет возможные значения кода ошибки.
     */
    ae_error_code_t code;

    /**
     * @var ae_error::message
     * @brief Сообщение об ошибке.
     *
     * Это поле хранит строку с описанием ошибки,
     * предоставляя более подробную информацию о проблеме.
     * Тип данных `ae_error_message_t` является псевдонимом для `const char *`.
     */
    ae_error_message_t message;
} ae_error_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает код ошибки из структуры `ae_error_t`.
 *
 * Эта функция извлекает код ошибки
 * из переданной структуры типа `ae_error_t`.
 *
 * Если указатель на структуру равен `nullptr`,
 * будет вызван макрос `AE_RUNTIME_ASSERT` для обработки ошибки.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             из которой необходимо получить код ошибки.
 *
 * @return Код ошибки типа `ae_error_code_t`,
 *         содержащийся в структуре `ae_error_t`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_error_code_t
ae_error_get_code(const ae_error_t *self);

/**
 * @brief Получает сообщение об ошибке из структуры `ae_error_t`.
 *
 * Эта функция извлекает сообщение об ошибке
 * из переданной структуры типа `ae_error_t`.
 *
 * Если указатель на структуру равен `nullptr`,
 * будет вызван макрос `AE_RUNTIME_ASSERT` для обработки ошибки.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             из которой необходимо получить сообщение об ошибке.
 *
 * @return Сообщение об ошибке типа `ae_error_message_t`,
 *         содержащееся в структуре `ae_error_t`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_error_message_t
ae_error_get_message(const ae_error_t *self);

/**
 * @brief Сбрасывает состояние ошибки в структуре `ae_error_t`.
 *
 * Эта функция устанавливает код ошибки и сообщение об ошибке
 * в переданной структуре типа `ae_error_t`.
 *
 * Если указатель на структуру равен `nullptr`,
 * будет вызван макрос `AE_RUNTIME_ASSERT` для обработки ошибки.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             которую необходимо сбросить.
 * @param code Код ошибки типа `ae_error_code_t`,
 *             который будет установлен в структуре.
 * @param message Сообщение об ошибке типа `ae_error_message_t`,
 *                которое будет установлено в структуре.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_set(ae_error_t *self, ae_error_code_t code, ae_error_message_t message);

/**
 * @brief Сбрасывает код ошибки в структуре `ae_error_t`.
 *
 * Эта функция устанавливает код ошибки в переданной структуре
 * типа `ae_error_t`, сбрасывая сообщение об ошибке на `nullptr`.
 * Функция вызывает `ae_error_set` для выполнения сброса.
 *
 * Если указатель на структуру равен `nullptr`, будет вызван
 * макрос `AE_RUNTIME_ASSERT` в функции `ae_error_set`.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             в которой необходимо сбросить код ошибки.
 * @param code Код ошибки типа `ae_error_code_t`,
 *             который будет установлен в структуре.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_set_code(ae_error_t *self, ae_error_code_t code);

/**
 * @brief Копирует состояние ошибки из одной структуры `ae_error_t` в другую.
 *
 * Эта функция присваивает код ошибки и сообщение об ошибке
 * из структуры `other` в структуру `self`.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             в которую будет скопировано состояние ошибки.
 * @param other Указатель на структуру `ae_error_t`,
 *              из которой будет скопировано состояние ошибки.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` или `other` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_assign(ae_error_t *self, const ae_error_t *other);

/**
 * @brief Обменивает состояние ошибки между двумя структурами `ae_error_t`.
 *
 * Эта функция временно сохраняет состояние ошибки из структуры `self`,
 * затем копирует состояние ошибки из структуры `other` в `self`,
 * и, наконец, копирует временно сохраненное состояние обратно в `other`.
 * Это позволяет обменять состояния ошибок между двумя структурами.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             состояние которой будет заменено.
 * @param other Указатель на структуру `ae_error_t`,
 *              состояние которой будет скопировано в `self`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` или `other` равен `nullptr`.
 *
 * @note Эта функция использует механизм обработки исключений для
 *       обеспечения безопасности при обмене состояний ошибок.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_swap(ae_error_t *self, ae_error_t *other);

/**
 * @brief Очищает состояние ошибки,
 *        восстанавливая его до состояния "нет ошибки".
 *
 * Эта функция сбрасывает состояние ошибки в структуре `ae_error_t`
 * с помощью инициализации объекта ошибки, который указывает на отсутствие ошибок.
 *
 * Она использует макрос `ae_error_empty_initializer` для создания
 * объекта ошибки с кодом `AE_ERROR_CODE_NONE` и пустым сообщением.
 *
 * Функция также возвращает предыдущее состояние кода ошибки перед его
 * сбросом, что позволяет пользователю сохранить информацию о предыдущей
 * ошибке, если это необходимо.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             состояние которой будет очищено.
 *
 * @return Код ошибки типа `ae_error_code_t`,
 *         который был установлен в структуре до вызова этой функции.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_clear(ae_error_t *self);

/**
 * @brief Очищает состояние ошибки и обменивает его с другой структурой `ae_error_t`.
 *
 * Эта функция сначала очищает состояние ошибки в структуре `self`,
 * восстанавливая его до состояния "нет ошибки", а затем выполняет
 * обмен состояния ошибки с другой структурой `other` с помощью
 * функции `ae_error_swap`.
 *
 * Это позволяет сначала сбросить текущее состояние ошибки, а затем
 * установить новое состояние ошибки из другой структуры.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             состояние которой будет очищено и заменено.
 * @param other Указатель на структуру `ae_error_t`,
 *              состояние которой будет скопировано в `self`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` или `other` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_exchange(ae_error_t *self, ae_error_t *other);

/**
 * @brief Получает код ошибки и очищает состояние ошибки.
 *
 * Эта функция извлекает код ошибки из структуры `ae_error_t`,
 * а затем очищает состояние ошибки, восстанавливая его до состояния
 * "нет ошибки". Это позволяет получить информацию о текущей ошибке
 * и одновременно сбросить ее состояние.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             из которой будет получен код ошибки.
 *
 * @return Код ошибки типа `ae_error_code_t`,
 *         который был установлен в структуре до вызова этой функции.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_error_code_t
ae_error_get_code_and_clear(ae_error_t *self);

/**
 * @brief Проверяет, равен ли код ошибки заданному коду.
 *
 * Эта функция сравнивает код ошибки в структуре `ae_error_t`
 * с переданным кодом `code`. Возвращает `true`, если коды равны,
 * и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             код ошибки которой будет проверен.
 * @param code Код ошибки типа `ae_error_code_t`,
 *             с которым будет произведено сравнение.
 *
 * @return `true`, если код ошибки в структуре `self` равен
 *         переданному коду `code`; `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_equal_code_to(const ae_error_t *self, ae_error_code_t code);

/**
 * @brief Проверяет, равны ли коды ошибок двух объектов `ae_error_t`.
 *
 * Эта функция сравнивает код ошибки в структуре `self` с кодом ошибки
 * в другой структуре `other`. Возвращает `true`, если коды равны,
 * и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             код ошибки которой будет проверен.
 * @param other Указатель на структуру `ae_error_t`,
 *              код ошибки которой будет использован для сравнения.
 *
 * @return `true`, если код ошибки в структуре `self` равен коду ошибки
 *         в структуре `other`; `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` или `other` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_equal_code(const ae_error_t *self, const ae_error_t *other);

/**
 * @brief Проверяет, равны ли сообщения об ошибках.
 *
 * Эта функция сравнивает сообщение об ошибке в структуре `self`
 * с переданным сообщением `message`. Возвращает `true`,
 * если сообщения равны, и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             сообщение об ошибке которой будет проверено.
 * @param message Сообщение об ошибке типа `ae_error_message_t`,
 *                с которым будет произведено сравнение.
 *
 * @return `true`, если сообщение об ошибке в структуре `self` равно
 *         переданному сообщению `message`; `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_equal_message_to(const ae_error_t *self, ae_error_message_t message);

/**
 * @brief Проверяет, равны ли сообщения об ошибках двух объектов `ae_error_t`.
 *
 * Эта функция сравнивает сообщение об ошибке в структуре `self` с сообщением
 * об ошибке в другой структуре `other`. Возвращает `true`, если сообщения равны,
 * и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             сообщение об ошибке которой будет проверено.
 * @param other Указатель на структуру `ae_error_t`,
 *              сообщение об ошибке которой будет использовано для сравнения.
 *
 * @return `true`, если сообщение об ошибке в структуре `self` равно сообщению
 *         об ошибке в структуре `other`; `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` или `other` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_equal_message(const ae_error_t *self, const ae_error_t *other);

/**
 * @brief Проверяет, равны ли два объекта `ae_error_t`.
 *
 * Эта функция сравнивает два объекта `ae_error_t` на равенство, проверяя
 * как коды ошибок, так и сообщения об ошибках. Возвращает `true`, если оба
 * объекта равны, и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             которая будет проверена.
 * @param other Указатель на структуру `ae_error_t`,
 *              с которой будет произведено сравнение.
 *
 * @return `true`, если оба объекта `ae_error_t` равны (код и сообщение
 *         об ошибке совпадают); `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` или `other` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_equal(const ae_error_t *self, const ae_error_t *other);

/**
 * @brief Проверяет, является ли ошибка отсутствующей.
 *
 * Эта функция определяет, является ли объект `ae_error_t` "пустым" или
 * "отсутствующим" (т.е. не содержит ошибок). Возвращает `true`, если код
 * ошибки равен `AE_ERROR_CODE_NONE`, и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             которую необходимо проверить.
 *
 * @return `true`, если код ошибки в структуре `self` равен `AE_ERROR_CODE_NONE`;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_none(const ae_error_t *self);

/**
 * @brief Проверяет, содержит ли объект `ae_error_t` ошибку.
 *
 * Эта функция определяет, содержит ли объект `ae_error_t` ошибку, проверяя,
 * не является ли он "пустым" или "отсутствующим". Возвращает `true`, если
 * код ошибки не равен `AE_ERROR_CODE_NONE`, и `false` в противном случае.
 *
 * @param self Указатель на структуру `ae_error_t`,
 *             которую необходимо проверить.
 *
 * @return `true`, если код ошибки в структуре `self` не равен `AE_ERROR_CODE_NONE`;
 *         `false` в противном случае.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель `self` равен `nullptr`.
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_some(const ae_error_t *self);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ERROR_H
