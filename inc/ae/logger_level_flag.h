/**
 * @file logger_level_flag.h
 * @brief Заголовочный файл, определяющий флаги для уровней логирования.
 *
 * Этот файл содержит определение перечисления, которое используется для задания флагов,
 * соответствующих различным уровням логирования. Каждый флаг представляет собой побитовую
 * маску, которая может быть использована для комбинирования нескольких уровней логирования
 * в одном значении.
 *
 * Перечисление @ref ae_logger_level_flag_t позволяет легко управлять несколькими уровнями
 * логирования одновременно, используя побитовые операции. Эти флаги могут быть полезны
 * для фильтрации логов или для настройки обработчиков логирования, которые учитывают
 * несколько уровней важности.
 *
 * В этом файле также подключается заголовочный файл "logger_level.h",
 * который содержит определения уровней логирования, таких как DEBUG, INFO, ERROR и других.
 */

#ifndef AE_LOGGER_LEVEL_FLAG_H
#define AE_LOGGER_LEVEL_FLAG_H

#include "logger_level.h"

/**
 * @brief Флаги для уровней логирования.
 *
 * Этот тип перечисления используется для определения флагов,
 * соответствующих различным уровням логирования.
 *
 * Каждый флаг представляет собой побитовую маску, которая может быть использована
 * для комбинирования нескольких уровней логирования в одном значении.
 */
typedef enum ae_logger_level_flag
{
    /** Нет активных флагов уровня логирования. */
    AE_LOGGER_LEVEL_FLAG_NONE = 0,

    /** Флаг для уровня отладки. Активирует логирование уровня DEBUG. */
    AE_LOGGER_LEVEL_FLAG_DEBUG = 1 << AE_LOGGER_LEVEL_DEBUG,

    /** Флаг для информационного уровня. Активирует логирование уровня INFO. */
    AE_LOGGER_LEVEL_FLAG_INFO = 1 << AE_LOGGER_LEVEL_INFO,

    /** Флаг для уровня уведомлений. Активирует логирование уровня NOTICE. */
    AE_LOGGER_LEVEL_FLAG_NOTICE = 1 << AE_LOGGER_LEVEL_NOTICE,

    /** Флаг для уровня предупреждения. Активирует логирование уровня WARNING. */
    AE_LOGGER_LEVEL_FLAG_WARNING = 1 << AE_LOGGER_LEVEL_WARNING,

    /** Флаг для уровня ошибки. Активирует логирование уровня ERROR. */
    AE_LOGGER_LEVEL_FLAG_ERROR = 1 << AE_LOGGER_LEVEL_ERROR,

    /** Флаг для критического уровня. Активирует логирование уровня CRITICAL. */
    AE_LOGGER_LEVEL_FLAG_CRITICAL = 1 << AE_LOGGER_LEVEL_CRITICAL,

    /** Флаг для уровня тревоги. Активирует логирование уровня ALERT. */
    AE_LOGGER_LEVEL_FLAG_ALERT = 1 << AE_LOGGER_LEVEL_ALERT,

    /** Флаг для уровня чрезвычайной ситуации. Активирует логирование уровня EMERGENCY. */
    AE_LOGGER_LEVEL_FLAG_EMERGENCY = 1 << AE_LOGGER_LEVEL_EMERGENCY,

    /** Флаг для всех уровней логирования. Комбинирует все флаги логирования. */
    AE_LOGGER_LEVEL_FLAG_ALL = AE_LOGGER_LEVEL_FLAG_DEBUG | AE_LOGGER_LEVEL_FLAG_INFO |
                               AE_LOGGER_LEVEL_FLAG_NOTICE | AE_LOGGER_LEVEL_FLAG_WARNING |
                               AE_LOGGER_LEVEL_FLAG_ERROR | AE_LOGGER_LEVEL_FLAG_CRITICAL |
                               AE_LOGGER_LEVEL_FLAG_ALERT | AE_LOGGER_LEVEL_FLAG_EMERGENCY
} ae_logger_level_flag_t;

#endif // AE_LOGGER_LEVEL_FLAG_H
