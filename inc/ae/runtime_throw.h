/**
 * @file runtime_throw.h
 * @brief Заголовочный файл с макросами
 *        для генерации и повторной генерации исключений.
 *
 * Этот файл предоставляет два макроса для обработки исключений в контексте
 * выполнения с сохранением и восстановлением состояния фрейма:
 * - `ae_runtime_throw` для генерации исключений.
 * - `ae_runtime_raise` для повторной генерации исключений.
 *
 * Макросы используются в блоках `try`/`catch` для обработки ошибок
 * и позволяют возвращать значения при возникновении исключений.
 *
 * @details Макросы `ae_runtime_throw` и `ae_runtime_raise` применяются для генерации
 *          и перегенерации исключений в контексте фреймовой модели выполнения.
 *          Они работают следующим образом:
 *
 *          - Если выполнение находится в начале состояния фрейма,
 *            код ошибки сохраняется, и выполнение возвращается с указанными значениями.
 *          - В противном случае вызывается функция `ae_runtime_frame_state_load`
 *            для восстановления контекста выполнения.
 *
 * @note Эти макросы предполагают использование с механизмом `try`/`catch`,
 *       где возможна обработка ошибок и повторное выполнение.
 */

#ifndef AE_RUNTIME_THROW_H
#define AE_RUNTIME_THROW_H

#include "runtime_throw_error.h"
#include "runtime_frame_state.h"

/**
 * @def ae_runtime_throw
 * @brief Прерывает выполнение с установкой ошибки
 *        и загрузкой состояния фрейма.
 *
 * Этот макрос используется для проверки,
 * находится ли выполнение в начале состояния фрейма
 * с помощью функции `ae_runtime_frame_state_is_begin`.
 *
 * Если это так, то он вызывает макрос `ae_runtime_throw_error_code`
 * для установки ошибки с указанным кодом и дополнительными параметрами.
 *
 * Затем он загружает предыдущее состояние фрейма выполнения,
 * вызывая макрос `ae_runtime_frame_state_load` с переданным значением ошибки.
 *
 * Макрос полезен для обработки ошибок на различных этапах выполнения программы,
 * особенно при необходимости возврата из текущего состояния выполнения,
 * если ошибка обнаружена в начале фрейма.
 *
 * @param error_code Код ошибки типа `ae_error_code_t`,
 *                   который будет передан в макрос `ae_runtime_throw_error_code`.
 * @param ... Дополнительные параметры, которые будут переданы в макрос
 *            `ae_runtime_throw_error_code` для установки ошибки.
 *
 * @see ae_runtime_frame_state_is_begin
 * @see ae_runtime_throw_error_code
 * @see ae_runtime_frame_state_load
 */
#define ae_runtime_throw(error_code, ...)                                                          \
    do                                                                                             \
    {                                                                                              \
        if (!ae_runtime_frame_state_is_begin())                                                    \
        {                                                                                          \
            ae_runtime_frame_state_load(error_code);                                               \
        }                                                                                          \
        ae_runtime_throw_error_code(error_code, __VA_ARGS__);                                      \
    } while (0)

/**
 * @def ae_runtime_rethrow
 * @brief Повторно вызывает обработку ошибки с установкой нового кода ошибки.
 *
 * Этот макрос использует макрос `ae_runtime_throw` для повторного вызова
 * обработки ошибки, устанавливая новый код ошибки с переданными параметрами.
 *
 * Он предназначен для случаев, когда необходимо повторно прервать
 * выполнение с установкой новой ошибки или измененным состоянием,
 * но с сохранением функциональности, обеспечиваемой `ae_runtime_throw`.
 *
 * По сути, макрос `ae_runtime_rethrow` является синонимом для `ae_runtime_throw`,
 * но может использоваться в ситуациях, когда требуется уточнение контекста ошибки.
 *
 * @param error_code Новый код ошибки типа `ae_error_code_t`,
 *                   который будет передан в макрос `ae_runtime_throw`.
 * @param ... Дополнительные параметры, которые будут переданы
 *            в макрос `ae_runtime_throw` для обработки ошибки.
 *
 * @see ae_runtime_throw
 */
#define ae_runtime_rethrow(error_code, ...) ae_runtime_throw(error_code, __VA_ARGS__)

/**
 * @def ae_runtime_raise
 * @brief Повторно вызывает обработку ошибки через `ae_runtime_rethrow`.
 *
 * Этот макрос использует макрос `ae_runtime_rethrow` для повторного вызова
 * обработки ошибки, передавая код ошибки и дополнительные параметры.
 * Он служит для повторной генерации ошибки с теми же параметрами,
 * но с возможностью уточнения контекста.
 *
 * По сути, макрос `ae_runtime_raise` является синонимом для `ae_runtime_rethrow`,
 * но может быть использован для улучшения читаемости или для уточнения намерений
 * в конкретных частях программы, где требуется инициировать обработку ошибки.
 *
 * @param ... Параметры, которые передаются в макрос `ae_runtime_rethrow`
 *            для обработки ошибки, включая код ошибки.
 *
 * @see ae_runtime_rethrow
 */
#define ae_runtime_raise(...) ae_runtime_rethrow(error_code, __VA_ARGS__)

#endif // AE_RUNTIME_THROW_H
