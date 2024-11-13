# -------------------------------------------------------------------------------------------- #
# Настройка проекта                                                                            #
# -------------------------------------------------------------------------------------------- #

# Задаем минимально необходимую версию для CMake.
cmake_minimum_required(VERSION 3.12)

# Устанавливаем название, версию, описание и основной язык проекта.
project(ae
        VERSION 1.0.0
        DESCRIPTION "adaptive engine"
        LANGUAGES C)

# Задаем стандарт который должен использовать компилятор.
set(CMAKE_C_STANDARD 11)

# Без этой опции компилятор может попытаться использовать ближайший поддерживаемый стандарт,
# если запрашиваемый не поддерживается.
set(CMAKE_C_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------------------------------- #
# Глобальные переменные                                                                        #
# -------------------------------------------------------------------------------------------- #

# Путь к текущему каталогу
set(AE_CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Путь к кэш-каталогу, который в данный момент обрабатывается.
set(AE_CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Путь к каталогу модулей для CMake
set(AE_CMAKE_INCLUDE_DIRECTORY ${AE_CMAKE_CURRENT_SOURCE_DIR}/cmake-include)

# -------------------------------------------------------------------------------------------- #
# Модули                                                                                       #
# -------------------------------------------------------------------------------------------- #

# Конфигурация и проброс определений для целевой платформы.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/compile_definitions.cmake)

# Конфигурация путей исходных и заголовочных файлов.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/environment_paths.cmake)

# Скрипт сбора исходных файлов.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/collect_source_files.cmake)

# Генерация лимитов для целочисленных типов.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/generate_numeric_limits.cmake)

# Конфигурация опций для сборки и управления параметрами библиотеки.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/toggle_options.cmake)

# Получает все активированные опции и добавляет их в список определений компиляции.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/collect_options_to_compiler_definitions.cmake)

# Скрипт преобразует версию проекта в список компонентов.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/parse_version.cmake)

# Конфигурация генерации документации.
include(${AE_CMAKE_INCLUDE_DIRECTORY}/generate_doxygen.cmake)

# -------------------------------------------------------------------------------------------- #
# Сборка библиотеки                                                                            #
# -------------------------------------------------------------------------------------------- #

# Условие для создания динамической или статической библиотеки.
if (AE_OPTION_BUILD_TYPE_SHARED)
    add_library(${PROJECT_NAME} SHARED ${AE_TARGET_SOURCE_FILES})
else ()
    add_library(${PROJECT_NAME} STATIC ${AE_TARGET_SOURCE_FILES})
endif ()

# Добавление каталогов заголовков для цели сборки.
target_include_directories(${PROJECT_NAME} PUBLIC ${AE_TARGET_INCLUDE_DIRECTORIES})

# Добавление определений компиляции для цели сборки.
target_compile_definitions(${PROJECT_NAME} PUBLIC ${AE_TARGET_COMPILE_DEFINITIONS})