#include <ae/runtime_logger.h>
/* Дополнительные модули */
#include <ae/logger_initializer.h>

/**
 * @var m_runtime_logger
 * @brief Глобальный объект рантайм логгера с поддержкой привязки к локальному потоку.
 *
 * Этот объект представляет собой экземпляр логгера, который инициализируется
 * с использованием `ae_logger_empty_initializer()` и может быть использован
 * для логирования сообщений. Атрибут `THREAD_LOCAL` гарантирует, что каждая нить
 * (thread) будет иметь собственный экземпляр данного объекта.
 *
 * @note Атрибут `THREAD_LOCAL` обеспечивает потокобезопасность, так как каждая нить
 *       использует отдельный экземпляр логгера, изолированный от других потоков.
 *
 * Пример использования:
 * @code
 * m_runtime_logger = ae_logger_create(...);
 * ae_logger_log_info(&m_runtime_logger, "Сообщение для данного потока");
 * @endcode
 *
 * @attribute THREAD_LOCAL
 * Указывает, что переменная привязана к конкретному потоку исполнения.
 *
 * @see ae_logger_empty_initializer
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_logger_t m_runtime_logger = ae_logger_empty_initializer();

ae_logger_t *
ae_runtime_logger()
{
    return &m_runtime_logger;
}