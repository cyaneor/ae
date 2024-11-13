/**
 * @file runtime_try.h
 * @brief Макросы для управления состоянием выполнения
 *        с поддержкой сохранения и восстановления фреймов.
 *
 * Этот файл содержит набор макросов, предназначенных
 * для управления состоянием выполнения программы
 * в рамках механизма фреймов.
 *
 * Он поддерживает сохранение состояния выполнения,
 * обработку ошибок и восстановление выполнения
 * в случае возникновения ошибок.
 *
 * Макросы включают в себя:
 * - `ae_runtime_try` - блок попытки выполнения кода с сохранением состояния фрейма.
 * - `ae_runtime_catch` - блок обработки ошибок после блока `ae_runtime_try`.
 * - `ae_runtime_catch_if` - условная обработка ошибок.
 * - `ae_runtime_try_finalize` - корректное завершение блока `try`.
 * - `ae_runtime_try_interrupt` - досрочное завершение блока `try` с возвратом значения.
 *
 * Макросы используют функции сохранения и восстановления состояния фрейма,
 * такие как:
 *
 * - `ae_runtime_frame_state_save` - сохранение текущего состояния фрейма.
 * - `ae_runtime_frame_state_prev` - сдвиг указателя состояния на предыдущее состояние.
 * - Механизмы `setjmp` и `longjmp` для реализации восстановления выполнения.
 *
 * Пример использования:
 * @code
 * ae_runtime_try {
 *     // Выполняемый код
 *     ae_runtime_try_finalize();
 * } ae_runtime_catch {
 *     // Обработка ошибки
 * }
 * @endcode
 *
 * @note Макросы должны использоваться для управления состояниями выполнения программы
 *       в контексте фреймов. Корректное завершение блоков `try` необходимо для
 *       избежания расхождений в указателях состояний.
 */

#ifndef AE_RUNTIME_TRY_H
#define AE_RUNTIME_TRY_H

#include "error_code.h"
#include "runtime_interrupt.h"
#include "runtime_frame_state.h"

/**
 * @brief Макрос для попытки выполнения с сохранением состояния фрейма.
 *
 * Этот макрос сохраняет текущее состояние фрейма выполнения
 * в переменную `stack_frame_state` с помощью функции `ae_runtime_frame_state_save`.
 *
 * - Если сохранение состояния фрейма прошло успешно (ошибка не произошла),
 *   выполнение продолжается.
 * - В случае ошибки выполнение может быть восстановлено
 *   с использованием сохраненного состояния.
 *
 * Макрос определяет две переменные:
 * - `error_code` — переменная для хранения кода ошибки,
 *                  который инициализируется значением `AE_ERROR_CODE_NONE`.
 * - `stack_frame_state` — переменная для хранения текущего состояния фрейма,
 *                         инициализируется пустым значением.
 *
 * Если сохранение состояния фрейма не удается (код ошибки не равен `AE_ERROR_CODE_NONE`),
 * выполнение может быть восстановлено с помощью механизма `longjmp` в других частях программы.
 *
 * Пример использования:
 * @code
 * ae_runtime_try {
 *     // Код, который нужно выполнить в рамках текущего состояния.
 * } else {
 *     // Обработка ошибки или восстановление выполнения.
 * }
 * @endcode
 *
 * @note Этот макрос используется для управления состоянием выполнения программы
 *       в контексте фреймов, поддерживая возможность восстановления состояния
 *       при возникновении ошибок.
 */
#define ae_runtime_try                                                                             \
    ae_error_code_t  error_code        = AE_ERROR_CODE_NONE;                                       \
    ae_jump_buffer_t stack_frame_state = {};                                                       \
    if ((error_code = ae_runtime_frame_state_save(&stack_frame_state)) == 0)

/**
 * @brief Альтернативный блок обработки ошибок для макроса `ae_runtime_try`.
 *
 * Этот макрос используется в сочетании с макросом `ae_runtime_try`
 * для обработки ошибок или восстановления выполнения программы
 * в случае возникновения ошибки.
 *
 * Когда выполнение возвращается в блок `else` после неудачного выполнения внутри
 * макроса `ae_runtime_try`, будет выполнен блок кода, связанный с `ae_runtime_catch`.
 *
 * Макрос `ae_runtime_catch` используется для обработки любых ошибок,
 * которые могут возникнуть при выполнении кода, обернутого в `ae_runtime_try`.
 *
 * Он является частью механизма восстановления состояния выполнения,
 * связанного с использованием `setjmp` и `longjmp`.
 *
 * Пример использования:
 * @code
 * ae_runtime_try {
 *     // Код, который нужно выполнить в рамках текущего состояния.
 * } ae_runtime_catch {
 *     // Обработка ошибок или восстановление выполнения.
 * }
 * @endcode
 *
 * @note Макрос `ae_runtime_catch` следует использовать сразу после `ae_runtime_try` для
 *       обработки ошибок, которые были обнаружены в ходе выполнения блока кода.
 */
#define ae_runtime_catch else

/**
 * @def ae_runtime_catch_if
 * @brief Условная обработка ошибок после блока `ae_runtime_try`.
 *
 * Макрос `ae_runtime_catch_if` используется в сочетании с макросом `ae_runtime_try`
 * для определения блока кода, который будет выполняться в случае возникновения
 * ошибки в предыдущем блоке, при этом добавляя условие для обработки ошибок.
 * Этот макрос позволяет более гибко управлять обработкой ошибок, проверяя
 * определенные условия перед выполнением блока обработки.
 *
 * Пример использования:
 * @code
 * ae_runtime_try {
 *     // Код, который может вызвать ошибку
 *     ...
 * } ae_runtime_catch_if (error_code != AE_ERROR_CODE_NONE) {
 *     // Обработка ошибки, если код ошибки не равен AE_ERROR_CODE_NONE
 *     ...
 * }
 * @endcode
 *
 * @note Убедитесь, что условие в `ae_runtime_catch_if` корректно отражает
 *       логику обработки ошибок, и что код внутри блока обрабатывает
 *       возможные ошибки должным образом.
 */
#define ae_runtime_catch_if ae_runtime_catch if

/**
 * @brief Завершает блок `try` путем восстановления указателя состояния фрейма.
 *
 * Макрос `ae_runtime_try_finalize` используется
 * для корректного завершения блока `try`.
 *
 * Если выполнение блока `try` прошло успешно (ошибка не произошла),
 * указатель состояния фрейма необходимо сдвинуть обратно на предыдущую позицию,
 * чтобы избежать расхождений в управлении состояниями фрейма выполнения.
 *
 * Макрос вызывает функцию `ae_runtime_frame_state_prev`,
 * которая сдвигает указатель на предыдущее состояние фрейма.
 *
 * Пример использования:
 * @code
 * ae_runtime_try {
 *     // Код, выполняемый в блоке try.
 *      ae_runtime_try_finalize();
 * } ae_runtime_catch {
 *     // Обработка ошибки.
 * }
 * @endcode
 *
 * @note Использование `ae_runtime_try_finalize` обязательно в блоках `try`,
 *       чтобы состояние фрейма корректно возвращалось, если ошибка не произошла.
 */
#define ae_runtime_try_finalize ae_runtime_frame_state_prev

/**
 * @def ae_runtime_try_interrupt
 * @brief Прерывает выполнение блока `try` с возвратом значения.
 *
 * Макрос `ae_runtime_try_interrupt` завершает текущий блок `try`, вызывая
 * `ae_runtime_try_finalize` для корректного восстановления состояния фрейма,
 * а затем выполняет `return` с переданными аргументами `__VA_ARGS__`.
 *
 * Этот макрос используется для досрочного выхода из блока `try`, например, в случае
 * необходимости немедленного завершения выполнения с возвращением определенного
 * значения. Он гарантирует, что состояние фрейма будет правильно восстановлено
 * перед завершением выполнения блока.
 *
 * @param ... Аргументы, которые будут переданы
 *            в оператор `return` для возврата значения.
 *
 * Пример использования:
 * @code
 * ae_runtime_try {
 *     if (some_condition) {
 *         // Завершает try с возвратом `nullptr`
 *         ae_runtime_try_interrupt(nullptr);
 *     }
 *     // Остальной код, который не выполнится при срабатывании прерывания
 * } ae_runtime_catch {
 *     // Обработка ошибки
 * }
 * @endcode
 *
 * @note Этот макрос должен использоваться внутри блока `ae_runtime_try`, чтобы
 *       гарантировать корректное завершение работы и восстановление состояния фрейма.
 *       Без вызова `ae_runtime_try_finalize` возможны расхождения в управлении состояниями.
 */
#define ae_runtime_try_interrupt(...)                                                              \
    ae_runtime_try_finalize();                                                                     \
    ae_runtime_interrupt(__VA_ARGS__)

#endif // AE_RUNTIME_TRY_H
