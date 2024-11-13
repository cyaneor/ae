/**
 * @file optional_param_error.h
 * @brief Заголовочный файл, содержащий макрос
 *        для создания необязательных параметров типа ошибки.
 *
 * Этот файл включает в себя макрос `ae_optional_param_error`,
 * который позволяет легко работать с необязательными параметрами типа ошибки.
 *
 * Макрос использует `ae_optional_param` для создания параметра
 * с инициализацией по умолчанию, равной `ae_error_empty_initializer()`.
 *
 * Включает:
 * - Макрос для работы с необязательными параметрами типа ошибки.
 * - Пример использования макроса для упрощения кода,
 *   когда параметр ошибки может быть необязательным.
 *
 * Включаемые файлы:
 * - `error.h`: Определение типа `ae_error_t`.
 * - `optional_param.h`: Макрос для работы с необязательными параметрами.
 * - `error_initializer.h`: Инициализатор ошибок по умолчанию.
 *
 * @note Этот файл является частью системы обработки ошибок
 *       и используется для упрощения работы с необязательными параметрами ошибок в функциях.
 */

#ifndef AE_OPTIONAL_PARAM_ERROR_H
#define AE_OPTIONAL_PARAM_ERROR_H

#include "error.h"
#include "optional_param.h"
#include "error_initializer.h"

/**
 * @def ae_optional_param_error
 * @brief Макрос для создания необязательного параметра
 *        типа ошибки с заданным значением по умолчанию.
 *
 * Этот макрос использует `ae_optional_param`
 * для создания необязательного параметра типа `ae_error_t`
 * с инициализацией по умолчанию, равной `ae_error_empty_initializer()`.
 *
 * @param param_name Имя параметра.
 *
 * @note Используйте этот макрос для упрощения обработки
 *       необязательных параметров типа ошибки в функциях.
 *
 * Пример использования макроса:
 * @code
 * void example_function(ae_error_t* error) {
 *     ae_optional_param_error(error);
 *     // Теперь error указывает на значение по умолчанию,
 *     // если был передан nullptr.
 * }
 * @endcode
 */
#define ae_optional_param_error(param_name)                                                        \
    ae_optional_param(ae_error_t, param_name, ae_error_empty_initializer())

#endif // AE_OPTIONAL_PARAM_ERROR_H
