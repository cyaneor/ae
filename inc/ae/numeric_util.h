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

#endif // AE_NUMERIC_UTIL_H
