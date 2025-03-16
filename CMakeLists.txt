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

set(AE_CMAKE_CURRENT_DIR ${AE_CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(AE_CMAKE_CURRENT_OPTIONS_DIR ${AE_CMAKE_CURRENT_DIR}/options)
set(AE_CMAKE_CURRENT_MODULES_DIR ${AE_CMAKE_CURRENT_DIR}/module)

# -------------------------------------------------------------------------------------------- #
# Модули                                                                                       #
# -------------------------------------------------------------------------------------------- #

# Конфигурация путей исходных и заголовочных файлов.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/environment_paths.cmake)

# Скрипт сбора исходных файлов.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/collect_source_files.cmake)

# Конфигурация и проброс определений для целевой платформы.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/compile_definitions.cmake)

# Скрипт преобразует версию проекта в список компонентов.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/parse_version.cmake)

# Генерация лимитов для целочисленных типов.
# Этот файл генерирует минимальные и максимальные значения для целочисленных типов данных.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/generate_numeric_limits.cmake)

# Конфигурация генерации документации.
# Этот файл настраивает процесс генерации документации с помощью Doxygen.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/generate_doxygen.cmake)

# Подключение файла с общими параметрами для компиляции.
# Этот файл добавляет необходимые флаги компилятора, используемые в проекте.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/include_compile_options.cmake)

# Подключает файл collect_library_options.cmake для получения всех активированных
# опций библиотеки и добавления их в список определений компиляции,
# что позволяет учитывать пользовательские настройки компилятора.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/collect_library_options.cmake)

# Подключает файл collect_compile_options.cmake для сбора всех
# активированных опций компилятора и добавления их в финальный список компиляции.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/collect_compile_options.cmake)

# Подключает файл sync_static_build_option.cmake, который синхронизирует необходимые параметры
# и макросы между проектами для корректной статической сборки, обеспечивая совместимость сборки.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/sync_static_build_option.cmake)

# -------------------------------------------------------------------------------------------- #
# Цели для сборки                                                                              #
# -------------------------------------------------------------------------------------------- #

# Включает конфигурацию для создания библиотеки по умолчанию, основываясь на настройках сборки.
include(${AE_CMAKE_CURRENT_MODULES_DIR}/build_library.cmake)

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
