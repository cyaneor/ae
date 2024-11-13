#include <ae/runtime_error.h>
/* Дополнительные модули */
#include <ae/error_initializer.h>

/**
 * @var m_error
 * @brief Потокобезопасная переменная для хранения текущей ошибки.
 *
 * Эта переменная используется для хранения информации об ошибке,
 * связанной с текущим потоком выполнения. Она объявлена с использованием
 * макроса `THREAD_LOCAL`, который обеспечивает уникальное значение переменной для каждого потока.
 *
 * Переменная инициализируется с помощью макроса `ae_error_empty_initializer`,
 * что задает начальное состояние ошибки (отсутствие ошибки).
 *
 * Пример использования:
 * @code
 * // Установить ошибку
 * m_error.code = AE_ERROR_CODE_INVALID_ARGUMENT;
 * m_error.desc = "Неверный аргумент функции";
 *
 * // Проверить ошибку
 * if (m_error.code != AE_ERROR_CODE_NONE) {
 *     printf("Ошибка: %s\n", m_error.desc);
 * }
 * @endcode
 *
 * @note Поскольку переменная `m_error` потокобезопасна, ее можно безопасно
 *       использовать в многопоточных приложениях без дополнительной синхронизации.
 *
 * @see ae_error_empty_initializer
 * @see ae_error_t
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_error_t m_error = ae_error_empty_initializer();

ae_error_t *
ae_runtime_error()
{
    return &m_error;
}