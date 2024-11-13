/**
 * @file allocated_block_cast.h
 * @brief Макрос для приведения указателя к типу `ae_memory_block_t*`
 *        с использованием `ae_memory_block_cast`.
 *
 * Данный файл содержит макрос `ae_allocated_block_cast`,
 * который является оберткой над макросом `ae_memory_block_cast`.
 *
 * Он предназначен для безопасного приведения указателей к типу `ae_memory_block_t*`,
 * когда указатель указывает на объект соответствующего типа.
 */

#ifndef AE_ALLOCATED_BLOCK_CAST_H
#define AE_ALLOCATED_BLOCK_CAST_H

#include "memory_block_cast.h"

/**
 * @def ae_allocated_block_cast(ptr, ...)
 * @brief Приводит указатель к типу `ae_memory_block_t*`
 *        с использованием `ae_memory_block_cast`.
 *
 * Этот макрос выполняет приведение типа указателя `ptr` к типу `ae_memory_block_t*`
 * с помощью макроса `ae_memory_block_cast`. Он может использоваться для безопасного
 * приведения указателей, когда вы уверены, что указатель указывает на объект
 * соответствующего типа.
 *
 * @param ptr Указатель, который необходимо привести к типу `ae_memory_block_t*`.
 * @param ... Опциональный квалификатор `const`, если требуется,
 *            для приведения к `const ae_memory_block_t*`.
 *
 * @return Приведенный указатель типа `ae_memory_block_t*`.
 *
 * @note Убедитесь, что указатель `ptr` действительно указывает
 *       на объект типа `ae_memory_block_t` или его производного типа,
 *       чтобы избежать неопределенного поведения.
 *
 * @warning Использование этого макроса с некорректным
 *          указателем может привести к ошибкам выполнения.
 */
#define ae_allocated_block_cast(ptr, ...) ae_memory_block_cast(ptr, __VA_ARGS__)

#endif // AE_ALLOCATED_BLOCK_CAST_H