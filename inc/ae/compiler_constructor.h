/**
 * @file compiler_constructor.h
 * @brief Определение макроса `ae_compiler_constructor` для различных компиляторов.
 *
 * Этот файл содержит определение макроса `ae_compiler_constructor`,
 * который позволяет объявлять функции-конструкторы,
 * выполняемые перед вызовом функции `main()`.
 *
 * Макрос адаптирован для работы с компиляторами GCC, Clang и MSVC,
 * а также предоставляет пустое определение для неподдерживаемых компиляторов.
 *
 * @details
 * - Для компиляторов GCC и Clang используется атрибут `__attribute__((constructor))`,
 *   который позволяет функции выполняться автоматически перед `main()`.
 * - Для компилятора MSVC используется специальная секция `.CRT$XCU`
 *   для определения функции-конструктора.
 * - Если компилятор не поддерживается, макрос будет определен как пустой,
 *   и будет выдано предупреждение компилятора.
 *
 * @warning Использование макроса `ae_compiler_constructor` с неподдерживаемым компилятором
 *          не даст желаемого эффекта и может привести к предупреждениям компилятора.
 *
 * @pre Данный файл должен быть включен в проект
 *      для использования макроса `ae_compiler_constructor`.
 */

#ifndef AE_COMPILER_CONSTRUCTOR_H
#define AE_COMPILER_CONSTRUCTOR_H

#include "compiler_type.h"

#if (AE_COMPILER_TYPE == AE_COMPILER_TYPE_GCC) || (AE_COMPILER_TYPE == AE_COMPILER_TYPE_CLANG)
/**
 * @def ae_compiler_constructor(f)
 * @brief Определяет атрибут конструктора для компиляторов GCC и Clang.
 * @details Атрибут определяет функцию-конструктор,
 *          которая будет выполняться перед вызовом функции main().
 *          Это характерно для компиляторов GCC и Clang.
 */
#    define ae_compiler_constructor(f) __attribute__((constructor)) static void f(void)

#elif (AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC)
/**
 * @def ae_compiler_constructor(f)
 * @brief Defines a constructor attribute for MSVC compiler.
 * @details Атрибут определяет функцию-конструктор,
 *          которая будет выполняться перед вызовом функции main().
 *          Это специфично для компилятора MSVC.
 */
#    define ae_compiler_constructor(f)                                                             \
        __pragma(section(".CRT$XCU", read)) static void __cdecl f(void);                           \
        __declspec(allocate(".CRT$XCU")) void(__cdecl * f##_)(void) = f;                           \
        static void __cdecl f(void)

#else
/**
 * @def ae_compiler_constructor
 * @brief Определяет пустой конструктор
 *        для неподдерживаемых компиляторов.
 *
 * @details Если компилятор не распознан или не поддерживается,
 *          этот макрос будет определен как пустой и будет выдано сообщение компилятора.
 *
 * @warning Использование этого макроса с неподдерживаемым компилятором
 *          не даст желаемого эффекта и приведет к предупреждению компилятора.
 */
#    define ae_compiler_constructor

#    pragma message("Warning: Compiler does not support constructor function")
#endif

#endif // AE_COMPILER_CONSTRUCTOR_H
