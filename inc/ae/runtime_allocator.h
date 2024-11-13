/**
 * @file runtime_allocator.h
 * @brief Заголовочный файл, предоставляющий функции
 *        для работы с аллокатором памяти времени выполнения.
 *
 * Этот файл содержит определения функций для работы
 * с глобальным аллокатором памяти времени выполнения.
 *
 * Аллокатор используется для выделения, освобождения и перераспределения памяти.
 * Эти функции учитывают выравнивание памяти и обеспечивают поддержку различных ошибок и исключений.
 *
 * Аллокатор работает с потоками, обеспечивая локальную память для каждого потока.
 * Определены функции для работы с обычными и выровненными блоками памяти.
 *
 * @note Включает поддержку опций и возможностей, таких как заполнение памяти нулями
 *       и инициализация с использованием стандартных функций библиотеки.
 */

#ifndef AE_RUNTIME_ALLOCATOR_H
#define AE_RUNTIME_ALLOCATOR_H

#include "memory_allocator.h"

/**
 * @def ae_runtime_allocator_realloc
 * @brief Перераспределяет память с использованием аллокатора времени выполнения.
 *
 * Этот макрос вызывает функцию `ae_memory_allocator_realloc`, передавая ей
 * аллокатор времени выполнения, получаемый через `ae_runtime_allocator()`,
 * а также все дополнительные параметры, переданные в макрос.
 *
 * - Если указатель `old_ptr` равен `null`,
 *   функция выделяет новую память размером `new_size`.
 * - Если старый и новый размеры совпадают,
 *   возвращается указатель на существующий блок памяти.
 * - Если новый размер равен 0,
 *   память освобождается и возвращается `null`.
 *
 * @param ... Переменное количество параметров, передаваемых в макрос.
 *            Эти параметры будут переданы в функцию `ae_memory_allocator_realloc`.
 *
 * @return Указатель на новый блок памяти, или `null`, если новый размер равен 0.
 *
 * @note Макрос вызывает функцию перераспределения памяти с использованием
 *       выделителя памяти времени выполнения, получаемого через
 *       `ae_runtime_allocator()`.
 *
 * @see ae_runtime_allocator
 * @see ae_memory_allocator_realloc
 */
#define ae_runtime_allocator_realloc(...)                                                          \
    ae_memory_allocator_realloc(ae_runtime_allocator(), __VA_ARGS__)

/**
 * @brief Освобождает ранее выделенную память
 *        с использованием аллокатора времени выполнения.
 *
 * Этот макрос вызывает функцию `ae_memory_allocator_free`, передавая ей
 * аллокатор времени выполнения, получаемый через `ae_runtime_allocator()`,
 * а также все дополнительные параметры, переданные в макрос.
 *
 * @param ... Переменное количество параметров, передаваемых в макрос.
 *            Эти параметры будут переданы в функцию `ae_memory_allocator_free`.
 *
 * @note Макрос упрощает вызов функции освобождения памяти, автоматически
 *       используя выделитель памяти времени выполнения, получаемый через
 *       `ae_runtime_allocator()`.
 *
 * @see ae_runtime_allocator
 * @see ae_memory_allocator_free
 */
#define ae_runtime_allocator_free(...) ae_memory_allocator_free(ae_runtime_allocator(), __VA_ARGS__)

/**
 * @brief Перераспределяет выровненную память
 *        с использованием аллокатора времени выполнения.
 *
 * Этот макрос вызывает функцию `ae_memory_allocator_align_realloc`, передавая ей
 * аллокатор времени выполнения, получаемый через `ae_runtime_allocator()`,
 * а также все дополнительные параметры, переданные в макрос.
 *
 * - Если указатель `old_ptr` равен `null`, функция выделяет новую память с заданным выравниванием.
 * - Если старый и новый размеры совпадают, возвращается указатель на существующий блок памяти.
 * - Если новый размер равен 0, память освобождается и возвращается `null`.
 *
 * @param ... Переменное количество параметров, передаваемых в макрос.
 *            Эти параметры будут переданы в функцию `ae_memory_allocator_align_realloc`.
 *
 * @return Указатель на новый выровненный блок памяти,
 *         или `null`, если новый размер равен 0.
 *
 * @note Макрос упрощает вызов функции перераспределения выровненной памяти
 *       с использованием выделителя памяти времени выполнения.
 *
 * @see ae_runtime_allocator
 * @see ae_memory_allocator_align_realloc
 */
#define ae_runtime_allocator_align_realloc(...)                                                    \
    ae_memory_allocator_align_realloc(ae_runtime_allocator(), __VA_ARGS__)

/**
 * @brief Освобождает ранее выделенную выровненную память
 *        с использованием аллокатора времени выполнения.
 *
 * Этот макрос вызывает функцию `ae_memory_allocator_align_free`, передавая ей
 * аллокатор времени выполнения, получаемый через `ae_runtime_allocator()`,
 * а также все дополнительные параметры, переданные в макрос.
 *
 * @param ... Переменное количество параметров, передаваемых в макрос.
 *            Эти параметры будут переданы в функцию `ae_memory_allocator_align_free`.
 *
 * @note Макрос упрощает вызов функции освобождения выровненной памяти,
 *       автоматически используя выделитель памяти времени выполнения.
 *
 * @see ae_runtime_allocator
 * @see ae_memory_allocator_align_free
 */
#define ae_runtime_allocator_align_free(...)                                                       \
    ae_memory_allocator_align_free(ae_runtime_allocator(), __VA_ARGS__)

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Возвращает указатель на локальный
 *        для потока распределитель памяти времени выполнения.
 *
 * Эта функция возвращает указатель на глобальную переменную `m_runtime_allocator`,
 * которая представляет собой локальный для потока экземпляр структуры `ae_memory_allocator`.
 * Этот распределитель инициализируется с помощью функций стандартной библиотеки,
 * если определена `AE_OPTION_RUNTIME_ALLOCATOR_INIT_STDLIB`.
 *
 * @return Указатель на локальный
 *         для потока распределитель памяти времени выполнения.
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_allocator_t *
ae_runtime_allocator();

AE_COMPILER(EXTERN_C_END)

#endif // AE_RUNTIME_ALLOCATOR_H
