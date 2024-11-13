/**
 * @file byte_order.h
 * @brief Определение порядка байтов.
 *
 * Этот файл содержит макросы для определения порядка байтов,
 * используемого в текущей системе. Он определяет, является ли
 * порядок байтов "слева направо" (big-endian) или "справа налево" (little-endian).
 *
 * @note Используйте макрос AE_BYTE_ORDER для проверки порядка байтов.
 */

#ifndef AE_BYTE_ORDER_H
#define AE_BYTE_ORDER_H

/**
 * @def AE_BYTE_ORDER_BIG_ENDIAN
 * @brief Значение, указывающее, что порядок байтов "слева направо".
 *
 * В этом порядке байты хранятся от старшего к младшему, что
 * означает, что наименьший значащий байт (LSB) находится в конце.
 * Пример: число 0x12345678 будет храниться как 12 34 56 78.
 */
#define AE_BYTE_ORDER_BIG_ENDIAN 1

/**
 * @def AE_BYTE_ORDER_LITTLE_ENDIAN
 * @brief Значение, указывающее, что порядок байтов "справа налево".
 *
 * В этом порядке байты хранятся от младшего к старшему, что
 * означает, что наименьший значащий байт (LSB) находится в начале.
 * Пример: число 0x12345678 будет храниться как 78 56 34 12.
 */
#define AE_BYTE_ORDER_LITTLE_ENDIAN 0

/**
 * @def AE_BYTE_ORDER
 * @brief Макрос, определяющий порядок байтов в системе.
 *
 * В зависимости от платформы и компилятора, этот макрос
 * будет равен либо AE_BYTE_ORDER_BIG_ENDIAN, либо
 * AE_BYTE_ORDER_LITTLE_ENDIAN.
 *
 * @note Для использования в коде, проверяйте значение
 * AE_BYTE_ORDER для определения порядка байтов.
 */
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#    define AE_BYTE_ORDER AE_BYTE_ORDER_BIG_ENDIAN
#else
#    define AE_BYTE_ORDER AE_BYTE_ORDER_LITTLE_ENDIAN
#endif

#endif // AE_BYTE_ORDER_H