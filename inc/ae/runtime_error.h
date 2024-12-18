/**
 * @file runtime_error.h
 * @brief Определение функций для работы с ошибками во время выполнения.
 *
 * Этот файл содержит определение функций для работы с ошибками,
 * которые могут возникнуть во время выполнения программы.
 * Он предоставляет доступ к переменной `m_runtime_error`,
 * которая используется для хранения информации об ошибке.
 *
 * @see ae_error_t
 * @see m_runtime_error
 */

#ifndef AE_RUNTIME_ERROR_H
#define AE_RUNTIME_ERROR_H

#include "error.h"
#include "attribute.h"

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Возвращает указатель на переменную
 *        для хранения информации об ошибке во время выполнения.
 *
 * Эта функция возвращает указатель на переменную `m_runtime_error`,
 * которая используется для хранения информации об ошибке,
 * которая может возникнуть во время выполнения программы.
 *
 * @return Указатель на переменную `m_runtime_error` типа `ae_error_t *`.
 */
AE_ATTRIBUTE(SYMBOL)
ae_error_t *
ae_runtime_error();

AE_COMPILER(EXTERN_C_END)

#endif // AE_RUNTIME_ERROR_H
