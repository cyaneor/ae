# -------------------------------------------------------------------------------------------------- #
# Генерация числовых ограничений для типов данных библиотеки                                         #
#                                                                                                    #
# Этот файл конфигурации CMake автоматически генерирует файл `numeric_limits.h` с определениями      #
# макросов, представляющих числовые ограничения для различных пользовательских типов VM библиотеки.  #
# Сначала создается временный C-файл с кодом, определяющим ограничения для всех целочисленных типов. #
# Затем этот файл компилируется и запускается для генерации окончательного заголовочного файла.      #
#                                                                                                    #
# В результате создается `numeric_limits.h` с макросами, определяющими минимальные                   #
# и максимальные значения, а также размеры различных знаковых и беззнаковых типов данных.            #
# -------------------------------------------------------------------------------------------------- #

# Этот файл генерирует ограничения в виде макросов для собственных типов VM библиотеки.
include(CheckCSourceRuns)

# Создаем переменную с путем, по которому будут генерироваться ограничения.
set(AE_NUMERIC_LIMITS_OUTPUT_FILE "${AE_TARGET_INCLUDE_DIR}/${PROJECT_NAME}/numeric_limits.h")

# Создание исходного кода в переменную.
set(AE_NUMERIC_LIMITS_SOURCE_CODE "
#include <stdio.h>
#include <errno.h>
#include <wchar.h>
#include \"${AE_TARGET_INCLUDE_DIR}/${PROJECT_NAME}/numeric_types.h\"
#include \"${AE_TARGET_INCLUDE_DIR}/${PROJECT_NAME}/numeric_limit.h\"
#include \"${AE_TARGET_INCLUDE_DIR}/${PROJECT_NAME}/compiler.h\"

int main() {
    FILE *file = fopen(\"${AE_NUMERIC_LIMITS_OUTPUT_FILE}\", \"w+\");
    if (!file) {
        return errno;
    }

    /* ---------------------------------------- Header ---------------------------------------- */

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @file numeric_limits.h\\n\");
    fprintf(file, \" * @brief Определяет макросы для числовых ограничений различных типов данных.\\n\");
    fprintf(file, \" * @details Этот файл создается автоматически, не пытайтесь редактировать его вручную.\\n\");
    fprintf(file, \" * \\n\");
    fprintf(file, \" * Этот заголовочный файл содержит макросы для определения минимальных\\n\");
    fprintf(file, \" * и максимальных значений как для знаковых, так и для беззнаковых числовых типов данных.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"#ifndef AE_NUMERIC_LIMITS_H\\n\");
    fprintf(file, \"#define AE_NUMERIC_LIMITS_H\\n\");
    fprintf(file, \"\\n\");

    /* ----------------------------------------- Size ----------------------------------------- */

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_CHAR_T_SIZE\\n\");
    fprintf(file, \" * @brief Размер знакового или беззнакового `char` в байтах.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_CHAR_T_SIZE\\n\");
    fprintf(file, \"#define AE_CHAR_T_SIZE %zu\\n\", sizeof(ae_uchar_t));
    fprintf(file, \"#endif // AE_CHAR_T_SIZE\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_WCHAR_T_SIZE\\n\");
    fprintf(file, \" * @brief Размер типа `wchar_t`, который используется для представления широких символов.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_WCHAR_T_SIZE\\n\");
    fprintf(file, \"#define AE_WCHAR_T_SIZE %zu\\n\", sizeof(wchar_t));
    fprintf(file, \"#endif // AE_WCHAR_T_SIZE\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SHORT_T_SIZE\\n\");
    fprintf(file, \" * @brief Размер знакового или беззнакового `short` в байтах.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SHORT_T_SIZE\\n\");
    fprintf(file, \"#define AE_SHORT_T_SIZE %zu\\n\", sizeof(ae_ushort_t));
    fprintf(file, \"#endif // AE_SHORT_T_SIZE\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_INT_T_SIZE\\n\");
    fprintf(file, \" * @brief Размер знакового или беззнакового `int` в байтах.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_INT_T_SIZE\\n\");
    fprintf(file, \"#define AE_INT_T_SIZE %zu\\n\", sizeof(ae_uint_t));
    fprintf(file, \"#endif // AE_INT_T_SIZE\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_LONG_T_SIZE\\n\");
    fprintf(file, \" * @brief Размер знакового или беззнакового `long` в байтах.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_LONG_T_SIZE\\n\");
    fprintf(file, \"#define AE_LONG_T_SIZE %zu\\n\", sizeof(ae_ulong_t));
    fprintf(file, \"#endif // AE_LONG_T_SIZE\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_LLONG_T_SIZE\\n\");
    fprintf(file, \" * @brief Размер знакового или беззнакового `long long` в байтах.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_LLONG_T_SIZE\\n\");
    fprintf(file, \"#define AE_LLONG_T_SIZE %zu\\n\", sizeof(ae_ullong_t));
    fprintf(file, \"#endif // AE_LLONG_T_SIZE\\n\");
    fprintf(file, \"\\n\");

    /* --------------------------------------- Unsigned --------------------------------------- */

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_UCHAR_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_uchar_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_UCHAR_T_MIN\\n\");
    fprintf(file, \"#define AE_UCHAR_T_MIN %huU\\n\", AE_NUMERIC_LIMIT_UINT_MIN(ae_uchar_t));
    fprintf(file, \"#endif // AE_UCHAR_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_UCHAR_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_uchar_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_UCHAR_T_MAX\\n\");
    fprintf(file, \"#define AE_UCHAR_T_MAX %huU\\n\", AE_NUMERIC_LIMIT_UINT_MAX(ae_uchar_t));
    fprintf(file, \"#endif // AE_UCHAR_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_USHORT_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_ushort_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_USHORT_T_MIN\\n\");
    fprintf(file, \"#define AE_USHORT_T_MIN %huU\\n\", AE_NUMERIC_LIMIT_UINT_MIN(ae_ushort_t));
    fprintf(file, \"#endif // AE_USHORT_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_USHORT_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_ushort_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_USHORT_T_MAX\\n\");
    fprintf(file, \"#define AE_USHORT_T_MAX %huU\\n\", AE_NUMERIC_LIMIT_UINT_MAX(ae_ushort_t));
    fprintf(file, \"#endif // AE_USHORT_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_UINT_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_uint_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_UINT_T_MIN\\n\");
    fprintf(file, \"#define AE_UINT_T_MIN %uU\\n\", AE_NUMERIC_LIMIT_UINT_MIN(ae_uint_t));
    fprintf(file, \"#endif // AE_UINT_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_UINT_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_uint_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_UINT_T_MAX\\n\");
    fprintf(file, \"#define AE_UINT_T_MAX %uU\\n\", AE_NUMERIC_LIMIT_UINT_MAX(ae_uint_t));
    fprintf(file, \"#endif // AE_UINT_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_ULONG_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_ulong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_ULONG_T_MIN\\n\");
    fprintf(file, \"#define AE_ULONG_T_MIN %luUL\\n\", AE_NUMERIC_LIMIT_UINT_MIN(ae_ulong_t));
    fprintf(file, \"#endif // AE_ULONG_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_ULONG_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_ulong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_ULONG_T_MAX\\n\");
    fprintf(file, \"#define AE_ULONG_T_MAX %luUL\\n\", AE_NUMERIC_LIMIT_UINT_MAX(ae_ulong_t));
    fprintf(file, \"#endif // AE_ULONG_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_ULLONG_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_ullong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_ULLONG_T_MIN\\n\");
    fprintf(file, \"#define AE_ULLONG_T_MIN %lluULL\\n\", AE_NUMERIC_LIMIT_UINT_MIN(ae_ullong_t));
    fprintf(file, \"#endif // AE_ULLONG_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_ULLONG_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_ullong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_ULLONG_T_MAX\\n\");
    fprintf(file, \"#define AE_ULLONG_T_MAX %lluULL\\n\", AE_NUMERIC_LIMIT_UINT_MAX(ae_ullong_t));
    fprintf(file, \"#endif // AE_ULLONG_T_MAX\\n\");
    fprintf(file, \"\\n\");

    /* ---------------------------------------- Signed ---------------------------------------- */

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SCHAR_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_schar_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SCHAR_T_MIN\\n\");
    fprintf(file, \"#define AE_SCHAR_T_MIN (%d)\\n\", AE_NUMERIC_LIMIT_SINT_MIN(ae_schar_t));
    fprintf(file, \"#endif // AE_SCHAR_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SCHAR_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_schar_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SCHAR_T_MAX\\n\");
    fprintf(file, \"#define AE_SCHAR_T_MAX %d\\n\", AE_NUMERIC_LIMIT_SINT_MAX(ae_schar_t));
    fprintf(file, \"#endif // AE_SCHAR_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SSHORT_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_sshort_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SSHORT_T_MIN\\n\");
    fprintf(file, \"#define AE_SSHORT_T_MIN (%d)\\n\", AE_NUMERIC_LIMIT_SINT_MIN(ae_sshort_t));
    fprintf(file, \"#endif // AE_SSHORT_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SSHORT_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_sshort_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SSHORT_T_MAX\\n\");
    fprintf(file, \"#define AE_SSHORT_T_MAX %d\\n\", AE_NUMERIC_LIMIT_SINT_MAX(ae_sshort_t));
    fprintf(file, \"#endif // AE_SSHORT_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SINT_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_sint_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SINT_T_MIN\\n\");

    #if AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
        fprintf(file, \"#define AE_SINT_T_MIN (%di32 - 1)\\n\", -(AE_NUMERIC_LIMIT_SINT_MIN(ae_sint_t) - 1));
    #else
        fprintf(file, \"#define AE_SINT_T_MIN (%d - 1)\\n\", -(AE_NUMERIC_LIMIT_SINT_MIN(ae_sint_t) - 1));
    #endif

    fprintf(file, \"#endif // AE_SINT_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SINT_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_sint_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SINT_T_MAX\\n\");
    fprintf(file, \"#define AE_SINT_T_MAX %d\\n\", AE_NUMERIC_LIMIT_SINT_MAX(ae_sint_t));
    fprintf(file, \"#endif // AE_SINT_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SLONG_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_slong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SLONG_T_MIN\\n\");

    #if AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
        fprintf(file, \"#define AE_SLONG_T_MIN (%ldL - 1)\\n\", -(AE_NUMERIC_LIMIT_SINT_MIN(ae_slong_t) - 1));
    #else
        fprintf(file, \"#define AE_SLONG_T_MIN (%ldL - 1)\\n\", -(AE_NUMERIC_LIMIT_SINT_MIN(ae_slong_t) - 1));
    #endif

    fprintf(file, \"#endif // AE_SLONG_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SLONG_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_slong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SLONG_T_MAX\\n\");
    fprintf(file, \"#define AE_SLONG_T_MAX %ldL\\n\", AE_NUMERIC_LIMIT_SINT_MAX(ae_slong_t));
    fprintf(file, \"#endif // AE_SLONG_T_MAX\\n\");
    fprintf(file, \"\\n\");

    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SLLONG_T_MIN\\n\");
    fprintf(file, \" * @brief Определяет минимальное значение для `ae_sllong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SLLONG_T_MIN\\n\");

    #if AE_COMPILER_TYPE == AE_COMPILER_TYPE_MSVC
        fprintf(file, \"#define AE_SLLONG_T_MIN (%lldi64 - 1)\\n\", -(AE_NUMERIC_LIMIT_SINT_MIN(ae_sllong_t) - 1));
    #else
        fprintf(file, \"#define AE_SLLONG_T_MIN (%lldLL - 1)\\n\", -(AE_NUMERIC_LIMIT_SINT_MIN(ae_sllong_t) - 1));
    #endif

    fprintf(file, \"#endif // AE_SLLONG_T_MIN\\n\");
    fprintf(file, \"\\n\");
    fprintf(file, \"/**\\n\");
    fprintf(file, \" * @def AE_SLLONG_T_MAX\\n\");
    fprintf(file, \" * @brief Определяет максимальное значение для `ae_sllong_t`.\\n\");
    fprintf(file, \" */\\n\");
    fprintf(file, \"#ifndef AE_SLLONG_T_MAX\\n\");
    fprintf(file, \"#define AE_SLLONG_T_MAX %lldLL\\n\", AE_NUMERIC_LIMIT_SINT_MAX(ae_sllong_t));
    fprintf(file, \"#endif // AE_SLLONG_T_MAX\\n\");
    fprintf(file, \"\\n\");

    /* ---------------------------------------- Footer ---------------------------------------- */

    fprintf(file, \"\#endif // AE_NUMERIC_LIMITS_H\");
    return fclose(file);
}
")

# Записываем сгенерированный исходный код в файл.
file(WRITE "${AE_CMAKE_CURRENT_BINARY_DIR}/generate_numeric_limits.c" "${AE_NUMERIC_LIMITS_SOURCE_CODE}")

# Компилируем сгенерированный исходный код,
# чтобы проверить наличие синтаксических ошибок и потенциальных проблем.
try_compile(AE_COMPILE_RESULT
        ${AE_CMAKE_CURRENT_BINARY_DIR}
        ${AE_CMAKE_CURRENT_BINARY_DIR}/generate_numeric_limits.c)

# Запускаем ранее созданный файл.
try_run(AE_RUN_RESULT AE_COMPILE_RESULT
        ${AE_CMAKE_CURRENT_BINARY_DIR}/run_result
        ${AE_CMAKE_CURRENT_BINARY_DIR}/generate_numeric_limits.c
)

# Удаляем ранее созданный временный файл.
file(REMOVE "${AE_CMAKE_CURRENT_BINARY_DIR}/generate_numeric_limits.c")

# Проверяем переменные с результатами компиляции и запуска.
if (AE_COMPILE_RESULT AND AE_RUN_RESULT EQUAL 0)
    message(STATUS "Limits of standard AE library types have been successfully generated")
else ()
    message(FATAL_ERROR "Error when generating limits for standard AE library types")
endif ()

# Очистка переменных, как если бы они никогда не создавались.
unset(AE_RUN_RESULT)
unset(AE_COMPILE_RESULT)
unset(AE_NUMERIC_LIMITS_SOURCE_CODE)
unset(AE_NUMERIC_LIMITS_OUTPUT_FILE)