/**
 * @file numeric_util.h
 * @brief Множество макросов для работы с числовыми операциями.
 *
 * Этот файл предоставляет макросы, которые упрощают операции с числами,
 * такие как проверка кратности чисел и создание чисел с заполнением через побитовые сдвиги.
 * Макросы используют операции побитовых сдвигов и делений для выполнения математических операций
 * и обеспечивают оптимизацию производительности для аппаратных операций.
 */

#ifndef AE_NUMERIC_UTIL_H
#define AE_NUMERIC_UTIL_H

/**
 * @def ae_numeric_has_zero_remainder
 * @brief Проверяет, является ли число кратным заданному делителю.
 *
 * Этот макрос принимает значение и делитель, и возвращает
 * логическое значение, указывающее, является ли `value`
 * кратным `divisor`.
 *
 * @param value Число, которое необходимо проверить.
 * @param divisor Делитель, на который проверяется кратность.
 *
 * @return `true`, если `value` кратно `divisor`;
 *         `false` в противном случае.
 *
 * @note Делитель не должен быть равен нулю,
 *       так как это приведет к неопределенному поведению.
 */
#define ae_numeric_has_zero_remainder(value, divisor) ((value % divisor) == 0)

/**
 * @def ae_numeric_has_zero_remainder_both
 * @brief Проверяет, являются ли оба числа кратными заданному делителю.
 *
 * Этот макрос принимает два значения и делитель, и возвращает
 * логическое значение, указывающее, являются ли оба числа
 * кратными заданному делителю.
 *
 * Макрос вызывает макрос `ae_numeric_has_zero_remainder`
 * для каждого числа (левого и правого операндов) и проверяет,
 * что оба числа кратны указанному делителю.
 *
 * @param lvalue Первое число, которое необходимо проверить.
 * @param rvalue Второе число, которое необходимо проверить.
 * @param divisor Делитель, на который проверяется кратность обоих чисел.
 *
 * @return `true`, если оба числа кратны `divisor`;
 *         `false`, если хотя бы одно число не кратно `divisor`.
 *
 * @note Делитель не должен быть равен нулю, так как это приведет
 *       к неопределенному поведению.
 */
#define ae_numeric_has_zero_remainder_both(lvalue, rvalue, divisor)                                \
    (ae_numeric_has_zero_remainder(lvalue, divisor) &&                                             \
     ae_numeric_has_zero_remainder(rvalue, divisor))

/**
 * @def ae_numeric_repeat64_of
 * @brief Заполняет 64-битное значение для типа T с использованием смещения битов.
 *
 * Этот макрос используется для создания 64-битного значения из указанного значения `value`,
 * повторяя его несколько раз с побитовым сдвигом для получения заполнения на всех 64 битах.
 * Результат будет зависеть от типа `T`, в который приводится значение.
 *
 * @param T Тип, к которому приводится значение.
 *          Обычно это целочисленный тип, например, `uint64_t`.
 * @param value Значение, которое будет использоваться для заполнения.
 *
 * @return Заполненное 64-битное значение типа `T`,
 *         полученное в результате применения побитовых операций.
 *
 * @note Это может быть полезно для создания уникальных значений для битовых операций или
 *       специфичных для аппаратных операций, где необходимо повторное использование значения.
 */
#define ae_numeric_repeat64_of(T, value)                                                           \
    ((T)(value) | ((T)(value) << 8) | ((T)(value) << 16) | ((T)(value) << 24) |                    \
     ((T)(value) << 32) | ((T)(value) << 40) | ((T)(value) << 48) | ((T)(value) << 56))

/**
 * @brief Заполняет 64-битное значение типа `ae_u64_t`,
 *        используя побитовые сдвиги.
 *
 * Этот макрос является оберткой для `ae_numeric_repeat64_of`,
 * который выполняет операцию заполнения 64-битного значения для типа `ae_u64_t`.
 *
 * Он принимает значение и применяет побитовый сдвиг на все 64 бита,
 * заполняя их одинаковыми значениями.
 *
 * @param value Значение, которое будет использоваться для заполнения.
 *
 * @return Заполненное 64-битное значение типа `ae_u64_t`,
 *         полученное с использованием побитовых операций.
 *
 * @note Этот макрос полезен, если необходимо заполнить
 *       все 64 бита одинаковым значением для типа `ae_u64_t`.
 */
#define ae_numeric_repeat64(value) ae_numeric_repeat64_of(ae_u64_t, value)

/**
 * @def ae_numeric_repeat32_of
 * @brief Заполняет 32-битное значение для типа T с использованием смещения битов.
 *
 * Этот макрос используется для создания 32-битного значения из указанного значения `value`,
 * повторяя его несколько раз с побитовым сдвигом для получения заполнения на всех 32 битах.
 * Результат будет зависеть от типа `T`, в который приводится значение.
 *
 * @param T Тип, к которому приводится значение.
 *          Обычно это целочисленный тип, например, `uint32_t`.
 * @param value Значение, которое будет использоваться для заполнения.
 *
 * @return Заполненное 32-битное значение типа `T`,
 *         полученное в результате применения побитовых операций.
 *
 * @note Это может быть полезно для создания уникальных значений для битовых операций или
 *       специфичных для аппаратных операций, где необходимо повторное использование значения.
 */
#define ae_numeric_repeat32_of(T, value)                                                           \
    ((T)(value) | ((T)(value) << 8) | ((T)(value) << 16) | ((T)(value) << 24))

/**
 * @def ae_numeric_repeat32
 * @brief Заполняет 32-битное значение типа `ae_u32_t`,
 *        используя побитовые сдвиги.
 *
 * Этот макрос является оберткой для `ae_numeric_repeat32_of`,
 * который выполняет операцию заполнения 32-битного значения для типа `ae_u32_t`.
 *
 * Он принимает значение и применяет побитовый сдвиг на все 32 бита,
 * заполняя их одинаковыми значениями.
 *
 * @param value Значение, которое будет использоваться для заполнения.
 *
 * @return Заполненное 32-битное значение типа `ae_u32_t`,
 *         полученное с использованием побитовых операций.
 *
 * @note Этот макрос полезен, если необходимо заполнить
 *       все 32 бита одинаковым значением для типа `ae_u32_t`.
 */
#define ae_numeric_repeat32(value) ae_numeric_repeat32_of(ae_u32_t, value)

/**
 * @def ae_numeric_repeat16_of
 * @brief Заполняет 16-битное значение для типа T с использованием смещения битов.
 *
 * Этот макрос используется для создания 16-битного значения из указанного значения `value`,
 * повторяя его несколько раз с побитовым сдвигом для получения заполнения на всех 16 битах.
 * Результат будет зависеть от типа `T`, в который приводится значение.
 *
 * @param T Тип, к которому приводится значение.
 *          Обычно это целочисленный тип, например, `uint16_t`.
 * @param value Значение, которое будет использоваться для заполнения.
 *
 * @return Заполненное 16-битное значение типа `T`,
 *         полученное в результате применения побитовых операций.
 *
 * @note Это может быть полезно для создания уникальных значений для битовых операций или
 *       специфичных для аппаратных операций, где необходимо повторное использование значения.
 */
#define ae_numeric_repeat16_of(T, value) ((T)(value) | ((T)(value) << 8))

/**
 * @def ae_numeric_repeat16
 * @brief Заполняет 16-битное значение типа `ae_u16_t`, используя побитовые сдвиги.
 *
 * Этот макрос является оберткой для `ae_numeric_repeat16_of`,
 * который выполняет операцию заполнения 16-битного значения для типа `ae_u16_t`.
 *
 * Он принимает значение и применяет побитовый сдвиг на все 16 битов,
 * заполняя их одинаковыми значениями.
 *
 * @param value Значение, которое будет использоваться для заполнения.
 *
 * @return Заполненное 16-битное значение типа `ae_u16_t`,
 *         полученное с использованием побитовых операций.
 *
 * @note Этот макрос полезен, если необходимо заполнить
 *       все 16 битов одинаковым значением для типа `ae_u16_t`.
 */
#define ae_numeric_repeat16(value) ae_numeric_repeat16_of(ae_u16_t, value)

#endif // AE_NUMERIC_UTIL_H
