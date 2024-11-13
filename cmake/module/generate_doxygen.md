# Генерация документации

Этот CMake файл конфигурирует генерацию документации с использованием Doxygen. Скрипт находит Doxygen, настраивает его
конфигурационный файл и создает цель для автоматической сборки документации проекта.

## Описание:

1. **Поиск пакета Doxygen**:
    - Команда `find_package(Doxygen)` используется для поиска пакета Doxygen, который необходим для генерации
      документации.

2. **Проверка наличия Doxygen**:
    - Если Doxygen найден, продолжается настройка конфигурации документации.

3. **Настройка путей конфигурации**:
    - Устанавливаются пути к файлам конфигурации:
        - `DOXYGEN_IN`: входной файл конфигурации Doxygen (обычно `.doxyfile.in`).
        - `DOXYGEN_OUT`: выходной файл конфигурации, который будет сгенерирован.

4. **Конфигурация Doxygen**:
    - С помощью команды `configure_file` заменяются переменные в входном файле и создается выходной файл конфигурации
      для Doxygen.

5. **Создание цели для генерации документации**:
    - Создается пользовательская цель `add_custom_target(${PROJECT_NAME}_docs ALL)`, которая будет запускать Doxygen с
      использованием сгенерированного конфигурационного файла.
    - Команда для генерации документации выполняется с комментариями, а также задаются рабочая директория и
      флаг `VERBATIM`.

## Пример:

```cmake
find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${AE_CMAKE_CURRENT_SOURCE_DIR}/.doxyfile.in)
    set(DOXYGEN_OUT ${AE_CMAKE_CURRENT_BINARY_DIR}/doxygen)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(${PROJECT_NAME}_docs ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${AE_CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating documentation with Doxygen"
            VERBATIM)
endif ()
```

Этот скрипт позволяет автоматически генерировать документацию проекта с использованием Doxygen, интегрируя процесс с
системой сборки CMake.