# Определения компилятора

Этот CMake файл конфигурирует и передает необходимые определения компилятора для адаптации библиотеки под целевую
платформу.

## Описание:

1. **Определение операционной системы**:
    - В скрипте используется переменная `CMAKE_SYSTEM_NAME`, которая содержит имя операционной системы (например,
      Windows, Linux или Darwin).
    - Это определение помогает адаптировать сборку под различные ОС.

2. **Определение размера указателя**:
    - Переменная `CMAKE_SIZEOF_VOID_P` указывает размер указателя (`void*`) на текущей платформе.
    - Это значение используется для учета архитектурных особенностей, таких как 32-битные или 64-битные системы.

3. **Определение архитектуры процессора**:
    - Переменная `CMAKE_SYSTEM_PROCESSOR` содержит информацию о процессоре системы, например, `x86_64`, `armv7`.
    - Это позволяет адаптировать библиотеку под различные архитектуры.

4. **Максимальное количество состояний кадров стека**:
    - Параметр `AE_STACK_FRAME_STATES_MAX` определяет максимальное количество сохраненных состояний кадров стека в
      библиотеке. В данном случае это значение установлено на 255.

5. **Коэффициент роста памяти**:
    - `AE_MEMORY_GROWTH_FACTOR` определяет коэффициент увеличения размера памяти при перераспределении в динамических
      структурах, что помогает оптимизировать использование памяти и уменьшить количество перераспределений.

## Пример:

```cmake
list(APPEND AE_TARGET_COMPILE_DEFINITIONS
        AE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}
        AE_INTPTR_T_SIZE=${CMAKE_SIZEOF_VOID_P}
        AE_SYSTEM_PROCESSOR="${CMAKE_SYSTEM_PROCESSOR}"
        AE_STACK_FRAME_STATES_MAX=255
        AE_MEMORY_GROWTH_FACTOR=2
)
```

Этот скрипт обеспечивает точную настройку сборки в зависимости от особенностей целевой платформы, что позволяет
создавать более универсальные и эффективные библиотеки.