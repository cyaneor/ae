/**
 * @file jump_buffer.h
 * @brief Определение типа данных
 *        для использования буфера возврата в setjmp/longjmp.
 *
 * Этот файл содержит определение типа `ae_jump_buffer_t`,
 * который является псевдонимом для стандартного типа `jmp_buf`,
 * используемого для сохранения состояния программы при работе
 * с функциями setjmp и longjmp.
 */

#ifndef AE_JUMP_BUFFER_H
#define AE_JUMP_BUFFER_H

#include <setjmp.h>

/**
 * @typedef ae_jump_buffer_t
 * @brief Тип, используемый для хранения состояния выполнения программы.
 *
 * Тип `ae_jump_buffer_t` представляет собой псевдоним для типа `jmp_buf`,
 * который используется для сохранения и восстановления состояния
 * выполнения программы при работе с функциями setjmp() и longjmp().
 */
typedef jmp_buf ae_jump_buffer_t;

#endif // AE_JUMP_BUFFER_H
