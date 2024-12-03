/**
 * @file error.h
 * @brief Заголовочный файл для работы с ошибками в системе.
 *
 * Этот файл содержит определения структуры
 * для представления ошибок и функции для работы с ними:
 * - Структура `ae_error_t` включает код ошибки и сообщение об ошибке.
 * - Функции предоставляют возможность получения,
 *   установки и сравнения ошибок, а также проверки их состояния.
 *
 * @note Все функции, работающие со структурой ошибок, предполагают,
 *       что переданные указатели на структуры не равны `nullptr`.
 *
 * @see ae_error_t
 * @see ae_error_code_t
 * @see ae_error_message_t
 */

#ifndef AE_ERROR_H
#define AE_ERROR_H

#include "bool.h"
#include "error_code.h"
#include "error_message.h"
#include "attribute.h"

/**
 * @struct ae_error_t
 * @brief Структура, представляющая ошибку.
 *
 * Эта структура содержит код ошибки и сообщение об ошибке.
 * Она используется для передачи информации об ошибках в системе.
 *
 * @var ae_error_t::code
 * Код ошибки типа @ref ae_error_code_t,
 * который указывает на конкретную ошибку.
 *
 * @var ae_error_t::message
 * Сообщение об ошибке типа @ref ae_error_message_t,
 * которое предоставляет дополнительную информацию о произошедшей ошибке.
 *
 * @see ae_error_code_t
 * @see ae_error_message_t
 */
typedef struct ae_error
{
    ae_error_code_t          code;
    const ae_error_message_t message;
} ae_error_t;

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает код ошибки из структуры ошибки.
 *
 * Эта функция извлекает код ошибки из переданной структуры ошибки.
 * Если указатель на структуру равен `nullptr`, функция вызывает
 * ассерцию, чтобы указать на наличие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @return Код ошибки типа ae_error_code_t.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_code_t
 */
AE_ATTRIBUTE(SYMBOL)
ae_error_code_t
ae_error_get_code(const ae_error_t *self);

/**
 * @brief Получает сообщение об ошибке из структуры ошибки.
 *
 * Эта функция извлекает сообщение об ошибке из переданной структуры ошибки.
 * Если указатель на структуру равен `nullptr`, функция вызывает
 * ассерцию, чтобы указать на наличие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @return Сообщение об ошибке типа ae_error_message_t.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_message_t
 */
AE_ATTRIBUTE(SYMBOL)
const ae_error_message_t
ae_error_get_message(const ae_error_t *self);

/**
 * @brief Устанавливает код ошибки в структуре ошибки.
 *
 * Эта функция задает код ошибки в переданной структуре ошибки.
 * Если указатель на структуру равен `nullptr`, функция вызывает
 * ассерцию, чтобы указать на наличие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param code Код ошибки типа ae_error_code_t,
 *             который необходимо установить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_code_t
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_set_code(ae_error_t *self, ae_error_code_t code);

/**
 * @brief Устанавливает сообщение об ошибке в структуре ошибки.
 *
 * Эта функция задает сообщение об ошибке в переданной структуре ошибки.
 * Если указатель на структуру равен `nullptr`, функция вызывает
 * ассерцию, чтобы указать на наличие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param message Сообщение об ошибке типа ae_error_message_t,
 *                которое необходимо установить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_message_t
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_set_message(ae_error_t *self, const ae_error_message_t message);

/**
 * @brief Устанавливает код и сообщение об ошибке в структуре ошибки.
 *
 * Эта функция задает код и сообщение об ошибке в переданной структуре ошибки.
 * Если указатель на структуру равен `nullptr`, функция вызывает ассерцию,
 * чтобы указать на наличие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param code Код ошибки типа ae_error_code_t,
 *             который необходимо установить.
 * @param message Сообщение об ошибке типа ae_error_message_t,
 *                которое необходимо установить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_code_t
 * @see ae_error_message_t
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_set(ae_error_t *self, ae_error_code_t code, const ae_error_message_t message);

/**
 * @brief Очищает структуру ошибки.
 *
 * Эта функция сбрасывает код и сообщение об ошибке в переданной структуре ошибки.
 * Она вызывает функцию `ae_error_set`, устанавливая код ошибки
 * как `AE_ERROR_CODE_NONE` и сообщение как `nullptr`,
 * что означает отсутствие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t),
 *             которую необходимо очистить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_set
 * @see ae_error_t
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_clear(ae_error_t *self);

/**
 * @brief Копирует код и сообщение об ошибке
 *        из одной структуры ошибки в другую.
 *
 * Эта функция присваивает код и сообщение об ошибке
 * из указанной структуры ошибки (other)
 * в переданную структуру ошибки (self).
 *
 * Если указатель на целевую структуру равен `nullptr`,
 * функция вызывает ассерцию, чтобы указать на наличие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t),
 *             в которую будут скопированы значения.
 * @param other Указатель на структуру ошибки (ae_error_t),
 *              из которой будут скопированы значения.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_get_code
 * @see ae_error_get_message
 * @see ae_error_set
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_error_assign(ae_error_t *self, const ae_error_t *other);

/**
 * @brief Сравнивает код ошибки с заданным кодом.
 *
 * Эта функция проверяет, равен ли код ошибки в переданной структуре
 * ошибки (self) заданному коду (code).
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param code Код ошибки типа ae_error_code_t для сравнения.
 * @return `true` Если код ошибки совпадает с заданным кодом, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_get_code
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_equal_code_to(const ae_error_t *self, ae_error_code_t code);

/**
 * @brief Сравнивает сообщение об ошибке с заданным сообщением.
 *
 * Эта функция проверяет, равно ли сообщение об ошибке
 * в переданной структуре ошибки (self) заданному сообщению (message).
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param message Сообщение об ошибке типа ae_error_message_t для сравнения.
 * @return `true` Если сообщение об ошибке совпадает с заданным сообщением, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_get_message
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_equal_message_to(const ae_error_t *self, const ae_error_message_t message);

/**
 * @brief Сравнивает код и сообщение об ошибке с заданными значениями.
 *
 * Эта функция проверяет, совпадают ли код и сообщение об ошибке в переданной
 * структуре ошибки (self) с заданными кодом (code) и сообщением (message).
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param code Код ошибки типа ae_error_code_t для сравнения.
 * @param message Сообщение об ошибке типа ae_error_message_t для сравнения.
 * @return `true` Если код и сообщение об ошибке совпадают с заданными значениями, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_equal_to(const ae_error_t *self, ae_error_code_t code, const ae_error_message_t message);

/**
 * @brief Сравнивает структуру ошибки с другой структурой ошибки.
 *
 * Эта функция проверяет, совпадают ли код и сообщение об ошибке в структуре
 * ошибки (self) с кодом и сообщением другой структуры ошибки (other).
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @param other Указатель на другую структуру ошибки (ae_error_t) для сравнения.
 * @return `true` Если код и сообщение ошибки совпадают, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_equal(const ae_error_t *self, const ae_error_t *other);

/**
 * @brief Проверяет, является ли ошибка отсутствующей (нет ошибки).
 *
 * Эта функция проверяет, соответствует ли код ошибки в переданной структуре
 * ошибки (self) коду, указывающему на отсутствие ошибки (AE_ERROR_CODE_NONE).
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @return `true` Если код ошибки соответствует отсутствию ошибки, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_equal_code_to
 * @see AE_ERROR_CODE_NONE
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_none(const ae_error_t *self);

/**
 * @brief Проверяет, является ли ошибка не отсутствующей (существует ошибка).
 *
 * Эта функция проверяет, что код ошибки в переданной структуре
 * ошибки (self) не соответствует коду, указывающему на отсутствие ошибки.
 *
 * @param self Указатель на структуру ошибки (ae_error_t).
 * @return `true` Если код ошибки не соответствует отсутствию ошибки, иначе `false`.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_error_t
 * @see ae_error_is_none
 */
AE_ATTRIBUTE(SYMBOL)
bool
ae_error_is_exists(const ae_error_t *self);

AE_COMPILER(EXTERN_C_END)

#endif // AE_ERROR_H
