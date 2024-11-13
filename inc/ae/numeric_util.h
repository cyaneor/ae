#ifndef AE_NUMERIC_UTIL_H
#define AE_NUMERIC_UTIL_H

/**
 * @def ae_numeric_multiple_of
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
#define ae_numeric_multiple_of(value, divisor) ((value % divisor) == 0)

#endif // AE_NUMERIC_UTIL_H
