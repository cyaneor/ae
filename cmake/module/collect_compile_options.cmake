# -------------------------------------------------------------------------------------- #
# Конфигурация опций компилятора для различных инструментов сборки                       #
#                                                                                        #
# Этот скрипт задает и добавляет специфические параметры компиляции в зависимости        #
# от используемого компилятора (GCC, Clang, MSVC). Для каждого параметра компиляции,     #
# заданного через CMake, добавляются соответствующие флаги для выбранного компилятора.   #
# -------------------------------------------------------------------------------------- #

# Получаем список всех переменных (опций) в текущем каталоге CMake
get_property(CMAKE_OPTIONS DIRECTORY PROPERTY VARIABLES)
foreach (CMAKE_OPTION IN ITEMS ${CMAKE_OPTIONS})
    if (CMAKE_OPTION MATCHES "^AE_COMPILE_OPTION_.*")
        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_OPTIMIZATION")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -O3)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -O3)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /O2)  # MSVC аналог -O3
                endif ()
            else ()
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -O0)  # Для GCC отключение оптимизаций
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -O0)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /Od)
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_DEBUG")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -g)  # Для GCC включение флага отладки
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -g)  # Для Clang включение флага отладки
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /Zi)  # Для MSVC включение флага отладки
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_SSE")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -msse)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -msse)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    if (MSVC_VERSION LESS 1900)
                        list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:SSE)
                    else ()  # MSVC 2015 и новее
                        list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:SSE2)
                    endif ()
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_AVX")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -mavx)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -mavx)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:AVX)
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_AVX2")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -mavx2)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -mavx2)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:AVX2)
                endif ()
            endif ()
            continue()
        endif ()

        if (AE_COMPILE_OPTION_AVX512)
            if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -mavx512f)
            elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -mavx512f)
            elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:AVX512)
            endif ()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_LTO")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -flto)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -flto)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GL)  # MSVC аналог LTO
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_UNROLL_LOOPS")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -funroll-loops)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -funroll-loops)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    # MSVC не поддерживает /unroll.
                    # Однако компилятор сам обычно развертывает циклы, если оптимизация включена.
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_NO_STACK_PROTECTOR")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-stack-protector)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-stack-protector)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GS-)  # MSVC аналог -fno-stack-protector
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_PIC")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (${AE_LIBRARY_OPTION_STATIC_BUILD})
                    message(FATAL_ERROR "PIC (Position Independent Code) cannot be used in a static build.")
                endif ()

                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fPIC)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fPIC)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    # MSVC не поддерживает флаг PIC, код всегда компилируется с позиционно независимым адресом
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_RTTI")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-rtti)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-rtti)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GR-)  # MSVC аналог -fno-rtti
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_EXCEPTIONS")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-exceptions)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-exceptions)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /EHsc-)  # MSVC аналог -fno-exceptions
                endif ()
            endif ()
            continue()
        endif ()

        if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_THREAD_SAFETY")
            if (${CMAKE_OPTION} STREQUAL "ON")
                if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -pthread)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
                    list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -pthread)
                elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
                    # MSVC использует другие механизмы для потокобезопасности, не требуется параметр
                endif ()
            endif ()
            continue()
        endif ()

    endif ()
endforeach ()


# Этот блок кода выводит все включенные опции компиляции, которые начинаются с "AE_COMPILE_OPTION_"
# и не равны значению "OFF". Эти опции добавляются в список AE_TARGET_PUBLIC_COMPILE_DEFINITIONS.
message(STATUS "Listing all enabled compile options:")
foreach (CMAKE_OPTION IN ITEMS ${CMAKE_OPTIONS})
    if (CMAKE_OPTION MATCHES "^AE_COMPILE_OPTION_.*" AND NOT ${CMAKE_OPTION} STREQUAL "OFF")
        message(STATUS ":: ${CMAKE_OPTION}")
        list(APPEND AE_TARGET_PUBLIC_COMPILE_DEFINITIONS ${CMAKE_OPTION})
    endif ()
endforeach ()