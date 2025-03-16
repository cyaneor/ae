# Проверяем, что текущий тип сборки не равен "Debug"
if (NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    # Если тип сборки не "Debug", выходим из скрипта
    return()
endif ()