# -------------------------------------------------------------------------------------- #
# Конфигурация опций компилятора для различных инструментов сборки                       #
#                                                                                        #
# Этот скрипт задает и добавляет специфические параметры компиляции в зависимости        #
# от используемого компилятора (GCC, Clang, MSVC). Для каждого параметра компиляции,     #
# заданного через CMake, добавляются соответствующие флаги для выбранного компилятора.   #
# -------------------------------------------------------------------------------------- #

message(STATUS "Listing all enabled compile options:")
foreach (CMAKE_OPTION IN ITEMS ${CMAKE_OPTIONS})
    if (CMAKE_OPTION MATCHES "^AE_COMPILE_OPTION_.*" AND NOT ${CMAKE_OPTION} STREQUAL "OFF")
        # Печатаем ключ и значение опции с дополнительным форматированием
        message(STATUS ":: ${CMAKE_OPTION}")

        if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
            # Для GCC или Clang
            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_OPTIMIZATION")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -O3)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_SSE3")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -msse3)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_LTO")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -flto)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_UNROLL_LOOPS")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -funroll-loops)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_NO_STACK_PROTECTOR")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-stack-protector)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_PIC")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fPIC)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_RTTI")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-rtti)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_EXCEPTIONS")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -fno-exceptions)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_THREAD_SAFETY")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS -pthread)
                continue()
            endif ()

        elseif (MSVC)
            # Для MSVC
            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_OPTIMIZATION")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /O2)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_SSE3")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /arch:SSE3)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_LTO")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GL)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_NO_STACK_PROTECTOR")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GS-)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_PIC")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /DYNAMICBASE)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_RTTI")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /GR-)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_FNO_EXCEPTIONS")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /EHsc-)
                continue()
            endif ()

            if (CMAKE_OPTION STREQUAL "AE_COMPILE_OPTION_THREAD_SAFETY")
                list(APPEND AE_TARGET_PRIVATE_COMPILE_OPTIONS /MT)
                continue()
            endif ()

        endif ()
    endif ()
endforeach ()