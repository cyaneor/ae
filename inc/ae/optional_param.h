/**
 * @file optional_param.h
 * @brief Заголовочный файл, содержащий макрос
 *        для обработки необязательных параметров.
 *
 * Этот файл определяет макрос `ae_optional_param`,
 * который позволяет легко создавать необязательные
 * параметры с заданным значением по умолчанию в функциях.
 */

#ifndef AE_OPTIONAL_PARAM_H
#define AE_OPTIONAL_PARAM_H

/**
 * @brief Макрос для создания необязательного параметра
 *        с заданным значением по умолчанию.
 *
 * Данный макрос инициализирует локальную переменную с заданным значением по умолчанию
 * и устанавливает указатель на эту переменную, если переданный параметр равен nullptr.
 *
 * @param param_type Тип параметра.
 * @param param_name Имя параметра.
 * @param ... Значение по умолчанию для параметра.
 *
 * @note Используйте этот макрос
 *       для упрощения обработки необязательных параметров в функциях.
 *
 * Пример использования макроса:
 * @code
 * void example_function(int* value) {
 *     ae_optional_param(int, value, 42);
 *     // Теперь value указывает на значение 42, если был передан nullptr.
 *     printf("Value: %d\n", *value);
 * }
 * @endcode
 */
#define ae_optional_param(param_type, param_name, ...)                                             \
    param_type _##param_name = __VA_ARGS__;                                                        \
    if (param_name == nullptr)                                                                     \
    param_name = &_##param_name

#endif // AE_OPTIONAL_PARAM_H
