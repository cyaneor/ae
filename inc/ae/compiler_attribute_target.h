/**
 * @file compiler_attribute_target.h
 * @brief Заголовочный файл, который определяет макрос для атрибутов компилятора,
 *        указывающих целевую архитектуру или платформу в зависимости от типа компилятора.
 *
 * Этот файл содержит макрос `AE_COMPILER_ATTRIBUTE_TARGET(x)`, который адаптируется
 * под различные компиляторы, такие как GCC, Clang и MSVC, и используется для указания
 * целевой архитектуры или платформы, на которой должен быть выполнен код.
 *
 * Для компиляторов GCC и Clang используется атрибут `__attribute__((target(x)))`,
 * для MSVC макрос не определяет атрибут, а для других компиляторов выводится
 * предупреждающее сообщение с использованием директивы `#pragma message`.
 */

#ifndef AE_COMPILER_ATTRIBUTE_TARGET_H
#define AE_COMPILER_ATTRIBUTE_TARGET_H

#include "compiler_type.h"

/**
 * @def AE_COMPILER_ATTRIBUTE_TARGET(x)
 * @brief Определяет атрибут компилятора, который указывает целевую
 *        архитектуру или платформу, для компиляторов GCC и Clang.
 *
 * Если компилятор является GCC или Clang, макрос определяет атрибут `__attribute__((target(x)))`,
 * где `x` — это строковое значение, представляющее целевую архитектуру или платформу, например,
 * "x86_64" или "armv7". Этот атрибут позволяет компилятору оптимизировать код для указанной
 * архитектуры.
 *
 * Пример использования:
 * @code
 * __attribute__((target("x86_64"))) void func() { ... }
 * @endcode
 *
 * @param x Целевая архитектура или платформа, на которой должен быть выполнен код.
 * @note Этот макрос поддерживается только для компиляторов GCC и Clang.
 */
#if (AE_COMPILER_TYPE == AE_COMPILER_TYPE_GCC) || (AE_COMPILER_TYPE == AE_COMPILER_TYPE_CLANG)
#    define AE_COMPILER_ATTRIBUTE_TARGET(x) __attribute__((target(x)))

/**
 * @def AE_COMPILER_ATTRIBUTE_TARGET(x)
 * @brief Для компилятора MSVC данный макрос не определяет никакого атрибута.
 *        Это делается для того, чтобы предотвратить использование атрибута `target` в MSVC,
 *        который не поддерживает такой синтаксис.
 *
 * Пример:
 * @code
 * // Нет атрибута target для MSVC
 * AE_COMPILER_ATTRIBUTE_TARGET("x86_64");
 * @endcode
 *
 * @param x Параметр, указанный для компилятора MSVC, игнорируется.
 * @note MSVC не поддерживает атрибуты `__attribute__((target))`.
 */
#elif (AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC)
#    define AE_COMPILER_ATTRIBUTE_TARGET(x)

/**
 * @def AE_COMPILER_ATTRIBUTE_TARGET(x)
 * @brief Для остальных компиляторов, которые не поддерживают атрибуты `target`,
 *        используется директива `#pragma message`,
 *        которая выводит сообщение в процессе компиляции.
 *
 *        Сообщение будет содержать информацию о том,
 *        что атрибут `target` не поддерживается данным компилятором.
 *
 * Пример:
 * @code
 * #pragma message("This compiler does not support target attribute")
 * @endcode
 *
 * @param x Параметр, указанный для компилятора, который не поддерживает `target`.
 *          Этот параметр не используется, но выводит сообщение с текстом, который передан.
 *
 * @note Это поведение применяется для компиляторов,
 *       отличных от GCC, Clang и MSVC.
 */
#else
#    define AE_COMPILER_ATTRIBUTE_TARGET(x)

#    pragma message("Warning: This compiler does not support target attribute")
#endif

#endif // AE_COMPILER_ATTRIBUTE_TARGET_H
