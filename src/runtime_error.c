#include <ae/runtime_error.h>
#include <ae/error_initializer.h>

/**
 * @var m_runtime_error
 * @brief Переменная для хранения информации об ошибке во время выполнения.
 *
 * Эта переменная используется для хранения информации об ошибке,
 * которая может возникнуть во время выполнения программы.
 * Она инициализируется с помощью макроса `ae_error_empty_initializer`,
 * который устанавливает код ошибки в `AE_ERROR_CODE_NONE` и сообщение об ошибке в `nullptr`.
 *
 * @see ae_error_empty_initializer
 * @see AE_ERROR_CODE_NONE
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_error_t m_runtime_error = ae_error_empty_initializer();

ae_error_t *
ae_runtime_error()
{
    return &m_runtime_error;
}