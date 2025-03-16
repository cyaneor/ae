# -------------------------------------------------------------------------------------- #
# Конфигурация опций компилятора для различных инструментов сборки                       #
#                                                                                        #
# Этот скрипт задает и добавляет специфические параметры компиляции в зависимости        #
# от используемого компилятора (GCC, Clang, MSVC). Для каждого параметра компиляции,     #
# заданного через CMake, добавляются соответствующие флаги для выбранного компилятора.   #
# -------------------------------------------------------------------------------------- #

# Получаем список всех переменных (опций) в текущем каталоге CMake
get_property(CMAKE_OPTIONS DIRECTORY PROPERTY VARIABLES)

message(STATUS "Listing all enabled compile options:")
foreach (CMAKE_OPTION IN ITEMS ${CMAKE_OPTIONS})
    if (CMAKE_OPTION MATCHES "^AE_COMPILE_OPTION_.*" AND NOT ${CMAKE_OPTION} STREQUAL "OFF")
        # Печатаем ключ и значение опции с дополнительным форматированием
        message(STATUS ":: ${CMAKE_OPTION}")

        # Для GCC, Clang или MSVC
        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_OPTIMIZATION")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -O3)
            elseif (MSVC)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /O2)  # MSVC аналог -O3
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_SSE3")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -msse3)
            elseif (MSVC)
                # Для MSVC флаг /arch:SSE2 включает поддержку SSE3,
                # так как SSE3 является частью SSE2 и не требует отдельного флага.
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:SSE2)  # Вместо /arch:SSE3
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_LTO")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -flto)
            elseif (MSVC)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GL)  # MSVC аналог LTO
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_UNROLL_LOOPS")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -funroll-loops)
            elseif (MSVC)
                # MSVC не поддерживает /unroll.
                # Однако компилятор сам обычно развертывает циклы, если оптимизация включена.
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_NO_STACK_PROTECTOR")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-stack-protector)
            elseif (MSVC)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GS-)  # MSVC аналог -fno-stack-protector
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_PIC")
            if (${AE_OPTION_STATIC_BUILD})
                message(FATAL_ERROR "PIC (Position Independent Code) cannot be used in a static build.")
            endif ()

            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fPIC)
            elseif (MSVC)
                # MSVC не поддерживает флаг PIC, код всегда компилируется с позиционно независимым адресом
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_RTTI")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-rtti)
            elseif (MSVC)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GR-)  # MSVC аналог -fno-rtti
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_EXCEPTIONS")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-exceptions)
            elseif (MSVC)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /EHsc-)  # MSVC аналог -fno-exceptions
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_THREAD_SAFETY")
            if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -pthread)
            elseif (MSVC)
                # MSVC использует другие механизмы для потокобезопасности, не требуется параметр
            endif ()
            continue()
        endif ()

    endif ()
endforeach ()