/**
 * @file version.h
 * @brief Заголовочный файл для работы с версией библиотеки.
 *
 * Этот файл содержит функции для получения информации о версии библиотеки,
 * включая мажорную, минорную и патч-версии.
 *
 * Версия формируется из предопределенных макросов AE_VERSION_MAJOR, AE_VERSION_MINOR
 * и AE_VERSION_PATCH, которые пробрасываются через CMake в процессе конфигурации.
 *
 * Функции предоставляют возможность получить версию
 * в виде строки формата "MAJOR.MINOR.PATCH"
 * и отдельные компоненты версии.
 *
 * @see ae_version
 * @see ae_version_major
 * @see ae_version_minor
 * @see ae_version_patch
 */
#ifndef AE_VERSION_H
#define AE_VERSION_H

#include "numeric.h"
#include "attribute.h"

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Возвращает строку с версией библиотеки.
 *
 * Эта функция возвращает текущую версию библиотеки в формате "MAJOR.MINOR.PATCH".
 * Версия формируется из предопределенных макросов AE_VERSION_MAJOR, AE_VERSION_MINOR
 * и AE_VERSION_PATCH с использованием макроса ae_stringify_args.
 *
 * @return Константный указатель на строку (const char*),
 *         содержащую версию библиотеки.
 *
 * @note Возвращаемая строка имеет формат "X.Y.Z", где:
 *       - X - мажорная версия (AE_VERSION_MAJOR)
 *       - Y - минорная версия (AE_VERSION_MINOR)
 *       - Z - патч-версия (AE_VERSION_PATCH)
 *
 * @see ae_stringify_args
 * @see AE_VERSION_MAJOR
 * @see AE_VERSION_MINOR
 * @see AE_VERSION_PATCH
 */
AE_ATTRIBUTE(SYMBOL)
const char *
ae_version();

/**
 * @brief Возвращает мажорную версию библиотеки.
 *
 * Эта функция возвращает мажорную (основную) версию библиотеки,
 * которая определена макросом AE_VERSION_MAJOR.
 *
 * @return ae_uint_t Мажорная версия библиотеки.
 *
 * @note Мажорная версия обычно увеличивается
 *       при внесении несовместимых изменений в API библиотеки.
 *
 * @see AE_VERSION_MAJOR
 * @see ae_version
 */
AE_ATTRIBUTE(SYMBOL)
ae_uint_t
ae_version_major();

/**
 * @brief Возвращает минорную версию библиотеки.
 *
 * Эта функция возвращает минорную (дополнительную) версию библиотеки,
 * которая определена макросом AE_VERSION_MINOR.
 *
 * @return ae_uint_t Минорная версия библиотеки.
 *
 * @note Минорная версия обычно увеличивается при добавлении новой
 *       функциональности с сохранением обратной совместимости.
 *
 * @see AE_VERSION_MINOR
 * @see ae_version
 * @see ae_version_major
 */
AE_ATTRIBUTE(SYMBOL)
ae_uint_t
ae_version_minor();

/**
 * @brief Возвращает патч-версию библиотеки.
 *
 * Эта функция возвращает патч-версию библиотеки,
 * которая определена макросом AE_VERSION_PATCH.
 *
 * @return ae_uint_t Патч-версия библиотеки.
 *
 * @note Патч-версия обычно увеличивается при внесении исправлений
 *       ошибок и незначительных изменений, которые не влияют на
 *       совместимость с предыдущими версиями.
 *
 * @see AE_VERSION_PATCH
 * @see ae_version
 * @see ae_version_major
 * @see ae_version_minor
 */
AE_ATTRIBUTE(SYMBOL)
ae_uint_t
ae_version_patch();

AE_COMPILER(EXTERN_C_END)

#endif // AE_VERSION_H
