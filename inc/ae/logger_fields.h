/**
 * @file logger_fields.h
 * @brief Заголовочный файл, определяющий макрос для полей логгера.
 *
 * Этот файл содержит определение макроса `AE_LOGGER_FIELDS`,
 * который используется для добавления полей, связанных с логированием, в структуру.
 *
 * Макрос включает два поля:
 * указатель на функцию логирования (`log_fn`) и флаг уровня логирования (`log_flag`).
 *
 * Макрос позволяет удобно и быстро добавлять стандартные поля в структуру,
 * без необходимости повторно описывать эти поля в различных структурах.
 *
 * @note Этот файл полезен для проектов, где требуется централизованная настройка
 *       параметров логирования для различных компонентов системы.
 */

#ifndef AE_LOGGER_FIELDS_H
#define AE_LOGGER_FIELDS_H

#include "logger_level_flag.h"
#include "logger_log_fn.h"

/**
 * @def AE_LOGGER_FIELDS
 * @brief Макрос, определяющий поля для структуры логгера.
 *
 * Этот макрос используется для определения полей в структуре логгера. Он включает в себя:
 * - Указатель на функцию логирования (`log_fn`),
 *   которая будет использоваться для записи сообщений в журнал.
 * - Флаг уровня логирования (`log_flag`),
 *   который определяет минимальный уровень важности сообщений, которые будут записываться.
 *
 * Поля, определенные этим макросом, предоставляют гибкость в настройке поведения логирования
 * в зависимости от уровня важности сообщений и выбора функции логирования.
 *
 * Пример использования:
 * @code
 * typedef struct {
 *     AE_LOGGER_FIELDS;
 * } ae_logger_t;
 * @endcode
 *
 * @note Макрос часто используется в контексте структур, которые описывают объекты логирования,
 *       и помогает избежать повторного написания однотипных полей.
 */
#define AE_LOGGER_FIELDS                                                                           \
    ae_logger_log_fn      *log_fn;                                                                 \
    ae_logger_level_flag_t log_flag

#endif // AE_LOGGER_FIELDS_H