/**
 * @file memory_block_fields.h
 * @brief Заголовочный файл для определения и инициализации блоков памяти.
 *
 * Этот файл содержит определения макросов `ae_memory_block_initializer`
 * и `AE_MEMORY_BLOCK_FIELDS`, которые используются для работы с блоками памяти.
 *
 * Макросы обеспечивают удобный способ инициализации
 * и определения структур данных, представляющих такие блоки.
 */

#ifndef AE_MEMORY_BLOCK_FIELDS_H
#define AE_MEMORY_BLOCK_FIELDS_H

#include "memory_range_fields.h"
#include "size.h"

/**
 * @def AE_MEMORY_BLOCK_FIELDS(T)
 * @brief Макрос для определения полей блока памяти.
 *
 * Этот макрос расширяет структуру, добавляя поля диапазона памяти и размер элемента.
 * Он используется для определения структуры, которая содержит информацию о блоке памяти
 * для типа данных T.
 *
 * @param T Тип данных, для которого создаются поля блока памяти.
 *
 * Макрос включает в себя:
 * - Поля, определенные в AE_MEMORY_RANGE_FIELDS(T)
 * - Дополнительное поле element_size для хранения размера одного элемента
 *
 * Пример использования:
 * @code
 * struct IntMemoryBlock {
 *     AE_MEMORY_BLOCK_FIELDS(int);
 * };
 * @endcode
 *
 * В этом примере создается структура IntMemoryBlock,
 * которая включает в себя поля диапазона памяти
 * и размер элемента для типа int.
 *
 * @see AE_MEMORY_RANGE_FIELDS
 */
#define AE_MEMORY_BLOCK_FIELDS(T)                                                                  \
    AE_MEMORY_RANGE_FIELDS(T);                                                                     \
    ae_usize_t element_size

#endif // AE_MEMORY_BLOCK_FIELDS_H
