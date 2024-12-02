#include <ae/runtime_error.h>

/**
 * @brief Переменная для хранения кода ошибки времени выполнения.
 *
 * Эта переменная используется для отслеживания ошибок,
 * которые могут возникнуть в процессе выполнения программы.
 *
 * Она объявлена с использованием атрибута THREAD_LOCAL,
 * что означает, что у каждой нити будет своя собственная копия этой переменной.
 *
 * @see ae_error_code_t
 * @see AE_RUNTIME_ERROR_OK
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_error_code_t m_runtime_error_code = AE_RUNTIME_ERROR_OK;

ae_error_code_t
ae_runtime_error_code()
{
    return m_runtime_error_code;
}

ae_error_code_t
ae_runtime_error_reset_code(ae_error_code_t error_code)
{
    const ae_error_code_t prev = m_runtime_error_code;
    m_runtime_error_code = error_code;
    return prev;
}

ae_error_code_t
ae_runtime_error_clear_code()
{
    return ae_runtime_error_reset_code(AE_RUNTIME_ERROR_OK);
}