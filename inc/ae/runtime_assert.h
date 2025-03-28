/**
 * @file runtime_assert.h
 * @brief Определяет макросы для выполнения утверждений
 *        и обработки ошибок во время выполнения.
 *
 * Этот файл предоставляет набор макросов для проверки условий
 * во время выполнения и генерации ошибок, когда условия не выполняются.
 *
 * Эти макросы используются для обеспечения валидации предпосылок,
 * допущений и критических условий во время выполнения программы.
 *
 * Макросы обеспечивают структурированную обработку ошибок, генерируя ошибки
 * с использованием `ae_runtime_throw()`, когда условия не выполняются,
 * и при необходимости возвращая указанные значения,
 * если ошибка возникает в начале фрейма стека.
 *
 * Основные предоставляемые макросы:
 * - `ae_runtime_assert_if`:
 *    Утверждает условие и генерирует ошибку, если оно истинно.
 * - `ae_runtime_assert_if_not`:
 *    Утверждает, что условие ложно, и генерирует ошибку, если это не так.
 * - `ae_runtime_assert`:
 *    Обеспечивает истинность условия и генерирует ошибку, если оно ложно.
 *
 * Эти макросы полезны для валидации условий во время выполнения,
 * обеспечения корректности программы и обработки ошибок
 * через структурированный механизм.
 */

#ifndef AE_RUNTIME_ASSERT_H
#define AE_RUNTIME_ASSERT_H

#include "runtime_throw.h"

/**
 * @def ae_runtime_assert_if
 * @brief Утверждает условие
 *        и генерирует ошибку, если условие истинно.
 *
 * Этот макрос оценивает предоставленное выражение (`expr`) и,
 * если выражение истинно, генерирует указанную
 * ошибку с помощью `ae_runtime_throw()`.
 *
 * Он предоставляет простой способ проверки условий
 * и обработки ошибок на основе этих условий.
 *
 * Если условие (`expr`) выполняется, макрос генерирует ошибку с указанным `error_code`
 * и при необходимости возвращает указанные значения (`__VA_ARGS__`)
 * если фрейм кадра находится в начале.
 *
 * @param expr Выражение для оценки.
 *             Если истинно, будет сгенерирована ошибка.
 *
 * @param error_code Код ошибки, который передается
 *                   в `ae_runtime_throw()`, если выражение истинно.
 *
 * @param ... Значение(я), которые нужно вернуть, если фрейм стека
 *            находится в начале, когда ошибка генерируется.
 *
 * @note Этот макрос полезен для валидации предпосылок
 *       или проверки ошибок во время выполнения, которые необходимо
 *       обрабатывать с помощью структурированного восстановления ошибок.
 *
 * @see ae_runtime_throw
 */
#define ae_runtime_assert_if(expr, error_code, ...)                                                \
    if (expr)                                                                                      \
    ae_runtime_throw(error_code, __VA_ARGS__)

/**
 * @def ae_runtime_assert_if_not
 * @brief Утверждает условие и генерирует ошибку, если условие ложно.
 *
 * Этот макрос является инвертированной версией макроса `AE_RUNTIME_ASSERT_IF`.
 * Он оценивает предоставленное выражение (`expr`) и, если выражение ложно,
 * генерирует указанную ошибку с помощью `ae_runtime_throw()`.
 *
 * Он предоставляет простой способ проверки условий
 * и обработки ошибок на основе этих условий.
 *
 * Если условие (`expr`) не выполняется, макрос генерирует ошибку с указанным `error_code`
 * и при необходимости возвращает указанные значения (`__VA_ARGS__`),
 * если фрейм кадра находится в начале.
 *
 * @param expr Выражение для оценки.
 *             Если ложно, будет сгенерирована ошибка.
 *
 * @param ... Значение(я), которые нужно вернуть, если фрейм стека
 *            находится в начале, когда ошибка генерируется.
 *
 * @note Этот макрос полезен для валидации предпосылок
 *       или проверки ошибок во время выполнения, которые необходимо
 *       обрабатывать с помощью структурированного восстановления ошибок.
 *
 * @see ae_runtime_throw
 * @see ae_runtime_assert_if
 */
#define ae_runtime_assert_if_not(expr, ...) ae_runtime_assert_if(!(expr), __VA_ARGS__)

/**
 * @def ae_runtime_assert
 * @brief Утверждает условие и генерирует ошибку, если условие ложно.
 *
 * Этот макрос является более общим и удобным вариантом использования
 * макроса `ae_runtime_assert_if_not`. Он оценивает переданные выражения
 * и, если условие ложно, генерирует ошибку с помощью `ae_runtime_throw()`.
 *
 * Он предоставляет простой способ проверки условий
 * и обработки ошибок на основе этих условий.
 *
 * Этот макрос эквивалентен вызову `ae_runtime_assert_if_not`
 * с переданными аргументами.
 *
 * @param ... Выражение для оценки и параметры, передаваемые для генерации ошибки.
 *            Если выражение ложно, будет сгенерирована ошибка.
 *
 * @note Макрос полезен для валидации предпосылок
 *       или проверки ошибок во время выполнения.
 *
 * @see ae_runtime_assert_if_not
 */
#define ae_runtime_assert(...) ae_runtime_assert_if_not(__VA_ARGS__)

#endif // AE_RUNTIME_ASSERT_H
