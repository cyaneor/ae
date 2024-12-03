#include <ae/runtime_error.h>

/**
 * @brief Переменная для хранения кода ошибки выполнения.
 *
 * Эта переменная хранит код последней ошибки выполнения.
 * Она объявлена как потокобезопасная (THREAD_LOCAL),
 * что позволяет каждому потоку иметь свою собственную копию этой переменной.
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
    m_runtime_error_code       = error_code;
    return prev;
}

ae_error_code_t
ae_runtime_error_clear_code()
{
    return ae_runtime_error_reset_code(AE_RUNTIME_ERROR_OK);
}