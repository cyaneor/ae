/**
 * @file runtime_throw_error.h
 * @brief Заголовочный файл, предоставляющий макросы для обработки ошибок.
 *
 * Этот файл содержит макросы для обработки ошибок в программе,
 * включая установку кода ошибки и сообщения, а также прерывание выполнения программы.
 * Макросы позволяют быстро и эффективно завершить выполнение функции с ошибкой,
 * обеспечивая возвращение управления в точку вызова с соответствующими значениями.
 */

#ifndef AE_RUNTIME_THROW_ERROR_H
#define AE_RUNTIME_THROW_ERROR_H

#include "nullptr.h"
#include "runtime_error.h"
#include "runtime_interrupt.h"

/**
 * @def ae_runtime_throw_error
 * @brief Прерывает выполнение функции с установкой ошибки.
 *
 * Этот макрос используется для установки ошибки с заданным кодом и сообщением,
 * а затем прерывает выполнение функции, вызывая макрос `ae_runtime_interrupt`
 * с указанными параметрами.
 *
 * Он применяется для обработки ошибок, когда необходимо немедленно
 * завершить выполнение функции и возвратить контроль с ошибкой.
 *
 * @param error_code Код ошибки типа `ae_error_code_t`,
 *                   который будет передан в функцию `ae_error_set`.
 * @param error_desc Сообщение об ошибке типа `ae_error_desc_t`,
 *                   которое будет передано в функцию `ae_error_set`.
 * @param ... Дополнительные параметры, которые будут переданы в макрос
 *            `ae_runtime_interrupt` для немедленного выхода
 *            из функции с заданными значениями.
 *
 * @see ae_error_set
 * @see ae_runtime_interrupt
 */
#define ae_runtime_throw_error(error_code, error_desc, ...)                                        \
    ae_error_set(ae_runtime_error(), error_code, error_desc);                                      \
    ae_runtime_interrupt(__VA_ARGS__)

/**
 * @def ae_runtime_throw_error_code
 * @brief Прерывает выполнение функции с установкой ошибки по коду.
 *
 * Этот макрос используется для установки ошибки с заданным кодом ошибки,
 * но без описания сообщения об ошибке (передается `nullptr` в качестве сообщения).
 *
 * После установки ошибки он прерывает выполнение функции с помощью макроса
 * `ae_runtime_throw_error` и передает дополнительные параметры
 * в макрос `ae_runtime_interrupt` для немедленного выхода.
 *
 * @param error_code Код ошибки типа `ae_error_code_t`,
 *                   который будет передан в функцию `ae_error_set`.
 * @param ... Дополнительные параметры, которые будут переданы в
 *            макрос `ae_runtime_interrupt` для немедленного выхода
 *            из функции с заданными значениями.
 *
 * @see ae_runtime_throw_error
 * @see ae_runtime_interrupt
 */
#define ae_runtime_throw_error_code(error_code, ...)                                               \
    ae_runtime_throw_error(error_code, nullptr, __VA_ARGS__)

#endif // AE_RUNTIME_THROW_ERROR_H
