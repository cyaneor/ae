# -------------------------------------------------------------------------------------- #
# Конфигурация типа библиотеки для сборки                                                #
#                                                                                        #
# Этот скрипт выбирает тип библиотеки, которую необходимо создать, в зависимости         #
# от значения переменной AE_LIBRARY_OPTION_STATIC_BUILD. Если переменная установлена        #
# в TRUE (или ON), создаётся статическая библиотека. В противном случае — динамическая. #
# -------------------------------------------------------------------------------------- #

# Проверяем значение переменной AE_LIBRARY_OPTION_STATIC_BUILD
if (AE_LIBRARY_OPTION_STATIC_BUILD)
    # Если переменная AE_LIBRARY_OPTION_STATIC_BUILD установлена,
    # создаём статическую библиотеку с использованием исходных файлов AE_TARGET_SOURCE_FILES
    add_library(${PROJECT_NAME} STATIC ${AE_TARGET_SOURCE_FILES})
elseif (AE_LIBRARY_OPTION_SHARED_BUILD)
    # Если переменная AE_LIBRARY_OPTION_SHARED_BUILD установлена,
    # создаём динамическую библиотеку с использованием исходных файлов AE_TARGET_SOURCE_FILES
    add_library(${PROJECT_NAME} SHARED ${AE_TARGET_SOURCE_FILES})
else ()
    # Если ни одна из предыдущих переменных не установлена, создаём исполняемый файл
    add_executable(${PROJECT_NAME} ${AE_TARGET_SOURCE_FILES})
endif ()
