# -------------------------------------------------------------------------------------------- #
# Настройка проекта                                                                            #
# -------------------------------------------------------------------------------------------- #

# Задаем минимально необходимую версию для CMake.
cmake_minimum_required(VERSION 3.12)

# Устанавливаем название, версию, описание и основной язык проекта.
project(ae
        VERSION 1.0.3
        DESCRIPTION "Adaptive Library"
        LANGUAGES C)

# Задаем стандарт который должен использовать компилятор.
set(CMAKE_C_STANDARD 11)

# Без этой опции компилятор может попытаться использовать
# ближайший поддерживаемый стандарт, если запрашиваемый не поддерживается.
set(CMAKE_C_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------------------------------- #
# Глобальные переменные                                                                        #
# -------------------------------------------------------------------------------------------- #

# Путь к текущему каталогу
set(AE_CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Путь к кэш-каталогу, который в данный момент обрабатывается.
set(AE_CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Путь к каталогу модулей для CMake
set(AE_CMAKE_CURRENT_MODULE_DIR ${AE_CMAKE_CURRENT_SOURCE_DIR}/cmake/module)

# -------------------------------------------------------------------------------------------- #
# Модули                                                                                       #
# -------------------------------------------------------------------------------------------- #

# Конфигурация путей исходных и заголовочных файлов.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/environment_paths.cmake)

# Скрипт сбора исходных файлов.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/collect_source_files.cmake)

# Конфигурация и проброс определений для целевой платформы.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/compile_definitions.cmake)

# Скрипт преобразует версию проекта в список компонентов.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/parse_version.cmake)

# Генерация лимитов для целочисленных типов.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/generate_numeric_limits.cmake)

# Конфигурация генерации документации.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/generate_doxygen.cmake)

# Конфигурация опций для сборки и управления параметрами библиотеки.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/toggle_options.cmake)

# Подключает файл collect_cmake_options.cmake для получения всех активированных опций и добавления
# их в список определений компиляции, что позволяет учитывать пользовательские настройки компилятора.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/collect_cmake_options.cmake)

# Подключает файл sync_static_build_option.cmake, который синхронизирует необходимые параметры
# и макросы между проектами для корректной статической сборки, обеспечивая совместимость сборки.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/sync_static_build_option.cmake)

# Подключает файл compile_options.cmake для настройки параметров компиляции,
# таких как флаги оптимизации и поддержки инструкций для различных компиляторов.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/compile_options.cmake)

# Подключает файл collect_compile_options.cmake для сбора всех
# активированных опций компилятора и добавления их в финальный список компиляции.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/collect_compile_options.cmake)

# -------------------------------------------------------------------------------------------- #
# Цели для сборки                                                                              #
# -------------------------------------------------------------------------------------------- #

# Включает конфигурацию для создания библиотеки по умолчанию, основываясь на настройках сборки.
include(${AE_CMAKE_CURRENT_MODULE_DIR}/build_library.cmake)

# -------------------------------------------------------------------------------------------- #
# Добавление каталогов и определений                                                           #
# -------------------------------------------------------------------------------------------- #

# Добавление каталогов заголовков для цели сборки.
target_include_directories(${PROJECT_NAME} PUBLIC ${AE_TARGET_INCLUDE_DIR})

# Добавление определений компиляции для цели сборки.
# - Определения PRIVATE применяются только внутри текущего проекта (не наследуются другими проектами).
# - Определения PUBLIC наследуются в проектах, которые будут ссылаться на этот проект.
target_compile_definitions(${PROJECT_NAME}
        PRIVATE ${AE_TARGET_PRIVATE_COMPILE_DEFINITIONS}
        PUBLIC ${AE_TARGET_PUBLIC_COMPILE_DEFINITIONS})


# Добавление опций компиляции для цели сборки.
# - Опции PRIVATE применяются только внутри текущего проекта.
# - Опции PUBLIC наследуются в проектах, которые будут ссылаться на этот проект.
target_compile_options(${PROJECT_NAME}
        PRIVATE ${AE_TARGET_PRIVATE_COMPILE_OPTIONS}
        PUBLIC ${AE_TARGET_PUBLIC_COMPILE_OPTIONS})
