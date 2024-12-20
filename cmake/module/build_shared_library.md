# Создание разделяемой библиотеки

Этот CMake скрипт нацелен на создание разделяемой (динамической) библиотеки из исходных файлов проекта. Он выполняет
несколько ключевых задач, описанных ниже.

## Описание

1. **Создание динамической библиотеки**:
   Скрипт создает разделяемую библиотеку с именем, основанным на названии проекта, добавляя суффикс "_shared". Для
   сборки библиотеки используются исходные файлы, указанные в переменной `${AE_TARGET_SOURCE_FILES}`.

2. **Возможность использования в других программах**:
   Созданная динамическая библиотека может быть загружена в память другими приложениями на этапе исполнения. Это
   позволяет делиться кодом между различными программами.

3. **Преимущества использования динамических библиотек**:
    - Упрощает обновления: библиотеку можно обновить, не перекомпилируя все программы, которые её используют.
    - Снижает избыточность кода: несколько приложений могут использовать одну и ту же библиотеку, экономя память и
      ресурсы.

## Пример команды для создания библиотеки

```cmake
add_library(${PROJECT_NAME}_shared SHARED ${AE_TARGET_SOURCE_FILES})
```

Этот CMake командой создается динамическая библиотека с уникальным именем, основанным на названии проекта.

## Заключение

Этот CMake скрипт упрощает процесс создания и использования разделяемых библиотек, обеспечивая гибкость и удобство при
работе с проектами, использующими общие компоненты.