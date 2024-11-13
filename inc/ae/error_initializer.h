/**
 * @file error_initializer.h
 * @brief Заголовочный файл, содержащий макросы для инициализации объектов ошибок.
 *
 * Этот файл определяет макросы, которые упрощают процесс создания и
 * инициализации объектов ошибок в программе. Макросы позволяют разработчикам
 * удобно задавать код ошибки и соответствующее сообщение, что улучшает
 * читаемость и поддержку кода.
 *
 * В файле определены следующие макросы:
 * - `ae_error_initializer`: Инициализирует объект ошибки с заданным кодом
 *   и сообщением.
 * - `ae_error_empty_initializer`: Инициализирует объект ошибки с предопределенным
 *   кодом успеха и пустым сообщением, указывая на отсутствие ошибок.
 *
 * @note Убедитесь, что используемые коды ошибок и сообщения соответствуют
 *       ожидаемым значениям в вашей программе. Неправильные значения могут
 *       привести к неопределенному поведению.
 *
 * Примеры использования макросов:
 * @code
 * struct ae_error {
 *     ae_error_code_t code;
 *     const ae_error_message_t message;
 * };
 *
 * struct ae_error my_error = ae_error_initializer(404, "Not Found");
 * struct ae_error success_error = ae_error_empty_initializer();
 * @endcode
 */

#ifndef AE_ERROR_INITIALIZER_H
#define AE_ERROR_INITIALIZER_H

#include "nullptr.h"
#include "error_code.h"
#include "initializer.h"

/**
 * @def ae_error_initializer
 * @brief Инициализация объекта ошибки с кодом и сообщением.
 *
 * Этот макрос позволяет инициализировать объект ошибки, предоставляя
 * код ошибки и соответствующее сообщение. Он используется для упрощения
 * процесса создания объектов ошибок и улучшения читаемости кода.
 *
 * @param code Код ошибки, который будет присвоен объекту ошибки.
 * @param message Сообщение, которое будет присвоено объекту ошибки.
 *
 * Пример использования:
 * @code
 * struct ae_error {
 *     ae_error_code_t code;
 *     const ae_error_message_t message;
 * };
 *
 * struct ae_error my_error = ae_error_initializer(404, "Not Found");
 * @endcode
 */
#define ae_error_initializer(code, message) ae_initializer(code, message)

/**
 * @def ae_error_empty_initializer
 * @brief Инициализация объекта ошибки с кодом успеха и пустым сообщением.
 *
 * Этот макрос позволяет инициализировать объект ошибки с предопределенным
 * кодом ошибки `AE_ERROR_CODE_NONE` и пустым сообщением (`nullptr`).
 *
 * Он используется для создания объекта ошибки, который указывает на отсутствие
 * ошибок, что может быть полезно в ситуациях, когда требуется явно указать,
 * что ошибки не произошло.
 *
 * @note Убедитесь, что код ошибки и сообщение соответствуют ожидаемым
 *       значениям в вашей программе. Этот макрос особенно полезен для
 *       обработки случаев, когда функция завершилась успешно
 *       и не требует дополнительной информации об ошибках.
 *
 * Пример использования:
 * @code
 * struct ae_error {
 *     ae_error_code_t code;
 *     const ae_error_message_t message;
 * };
 *
 * struct ae_error my_error = ae_error_empty_initializer();
 * // my_error будет инициализирован с кодом AE_ERROR_CODE_NONE и пустым сообщением
 * @endcode
 */
#define ae_error_empty_initializer() ae_error_initializer(AE_ERROR_CODE_NONE, nullptr)

#endif // AE_ERROR_INITIALIZER_H
