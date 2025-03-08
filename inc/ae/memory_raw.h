/**
 * @file memory_raw.h
 * @brief Заголовочный файл для работы с низкоуровневыми операциями с памятью.
 *
 * Данный файл содержит объявления функций для копирования,
 * перемещения, сравнения и заполнения блоков памяти.
 *
 * Функции используют оптимизации с помощью SIMD-инструкций (AVX и SSE),
 * если они доступны, для повышения производительности операций.
 *
 * Основные функции включают:
 * - Копирование данных из одного буфера в другой.
 * - Перемещение данных между перекрывающимися областями памяти.
 * - Сравнение двух блоков памяти.
 * - Поиск одного блока памяти внутри другого.
 * - Заполнение области памяти заданным значением.
 *
 * Каждая функция имеет механизмы обработки ошибок
 * и может выбрасывать исключения в случае передачи нулевых указателей.
 *
 * @see ae_memory_raw_copy
 * @see ae_memory_raw_move
 * @see ae_memory_raw_compare
 * @see ae_memory_raw_find
 * @see ae_memory_raw_set
 * @see ae_memory_raw_set_value
 */

#ifndef AE_MEMORY_RAW_H
#define AE_MEMORY_RAW_H

#include "attribute.h"
#include "size.h"
#include "char.h"

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Копирует данные из одного буфера в другой.
 *
 * Функция копирует данные из исходного буфера в целевой буфер от начала до конца.
 * Для ускорения копирования используются оптимизации с использованием инструкций AVX и SSE,
 * если они доступны. Для оставшихся данных выполняется побайтовое копирование.
 *
 * @param dst Указатель на целевой буфер.
 * @param dst_end Указатель на конец целевого буфера.
 * @param src Указатель на исходный буфер.
 * @param src_end Указатель на конец исходного буфера.
 *
 * @return Указатель на новый конец целевого буфера (по достижении конца).
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_copy(void *dst, const void *dst_end, const void *src, const void *src_end);

/**
 * @brief Копирует данные из одного буфера в другой в обратном направлении.
 *
 * Функция копирует данные из исходного буфера в целевой буфер, начиная с конца и двигаясь к началу.
 * Она использует оптимизации для обработки данных с помощью инструкций AVX и SSE,
 * если они доступны, и копирует оставшиеся байты по одному,
 * если данные не соответствуют размеру для SIMD-инструкций.
 *
 * @param dst Указатель на целевой буфер.
 * @param dst_end Указатель на начало целевого буфера (аналогично указателю на конец).
 * @param src Указатель на исходный буфер.
 * @param src_end Указатель на начало исходного буфера (аналогично указателю на конец).
 *
 * @return Указатель на новый конец целевого буфера.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_copy_from_end(const void *dst, void *dst_end, const void *src, const void *src_end);

/**
 * @brief Перемещает блок памяти из одной области в другую.
 *
 * Эта функция копирует данные из области памяти, указанной параметром `src`,
 * в область памяти, указанную параметром `dst`. Если области перекрываются,
 * данные копируются в обратном порядке, чтобы избежать потери информации.
 * В противном случае данные копируются в прямом порядке.
 *
 * @param dst Указатель на целевую область памяти, куда будут скопированы данные.
 * @param dst_end Указатель на конец целевой области памяти.
 * @param src Указатель на исходную область памяти, откуда будут скопированы данные.
 * @param src_end Указатель на конец исходной области памяти.
 *
 * @return Указатель на конец перемещенных данных в целевой области памяти.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_move(void *dst, const void *dst_end, const void *src, const void *src_end);

/**
 * @brief Сравнивает два блока памяти.
 *
 * Эта функция сравнивает два указанных блока памяти, начиная с адресов,
 * указанных в параметрах `lhs` и `rhs`, и заканчивая адресами,
 * указанными в `lhs_end` и `rhs_end`.
 *
 * Функция использует SIMD инструкции (AVX или SSE) для оптимизации сравнения, если это возможно.
 * Возвращает указатель на первое различие, если блоки не равны, или nullptr, если блоки равны.
 *
 * @param lhs Указатель на начало первого блока памяти.
 * @param lhs_end Указатель на конец первого блока памяти.
 * @param rhs Указатель на начало второго блока памяти.
 * @param rhs_end Указатель на конец второго блока памяти.
 *
 * @return Указатель на первое различие между блоками памяти или nullptr,
 *         если блоки равны.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_raw_compare(const void *lhs, const void *lhs_end, const void *rhs, const void *rhs_end);

/**
 * @brief Сравнивает два блока памяти, начиная с конца.
 *
 * Эта функция сравнивает два указанных блока памяти, начиная с адресов,
 * указанных в параметрах `lhs_end` и `rhs_end`, и заканчивая адресами,
 * указанными в `lhs` и `rhs`.
 *
 * Функция использует SIMD инструкции (AVX или SSE) для оптимизации сравнения, если это возможно.
 * Возвращает указатель на первое различие, если блоки не равны, или nullptr, если блоки равны.
 *
 * @param lhs Указатель на начало первого блока памяти.
 * @param lhs_end Указатель на конец первого блока памяти.
 * @param rhs Указатель на начало второго блока памяти.
 * @param rhs_end Указатель на конец второго блока памяти.
 *
 * @return Указатель на первое различие между блоками памяти или nullptr,
 *         если блоки равны.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_raw_compare_from_end(const void *lhs,
                               const void *lhs_end,
                               const void *rhs,
                               const void *rhs_end);

/**
 * @brief Ищет блок памяти в другом блоке памяти.
 *
 * - Если блок `rhs` найден в блоке `lhs`,
 *   функция возвращает указатель на первое вхождение.
 * - Если блок не найден, возвращается nullptr.
 *
 * @param lhs Указатель на начало первого блока памяти, в котором будет производиться поиск.
 * @param lhs_end Указатель на конец первого блока памяти.
 * @param rhs Указатель на начало второго блока памяти, который нужно найти.
 * @param rhs_end Указатель на конец второго блока памяти.
 *
 * @return Указатель на первое вхождение блока `rhs` в блоке `lhs` или nullptr,
 *         если блок не найден.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_raw_find(const void *lhs, const void *lhs_end, const void *rhs, const void *rhs_end);

/**
 * @brief Ищет блок памяти в другом блоке памяти, начиная с конца.
 *
 * - Если блок `rhs` найден в блоке `lhs`,
 *   функция возвращает указатель на первое вхождение.
 * - Если блок не найден, возвращается nullptr.
 *
 * @param lhs Указатель на начало первого блока памяти, в котором будет производиться поиск.
 * @param lhs_end Указатель на конец первого блока памяти.
 * @param rhs Указатель на начало второго блока памяти, который нужно найти.
 * @param rhs_end Указатель на конец второго блока памяти.
 *
 * @return Указатель на первое вхождение блока `rhs` в блоке `lhs`,
 *         начиная с конца, или nullptr, если блок не найден.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
const void *
ae_memory_raw_find_from_end(const void *lhs,
                            const void *lhs_end,
                            const void *rhs,
                            const void *rhs_end);

/**
 * @brief Заполняет данными из одного блока памяти в другой.
 *
 * Эта функция копирует данные из источника `src` в назначение `dst`,
 * пока не будет достигнут конец блока `dst_end`.
 *
 * @param dst Указатель на начало блока памяти назначения,
 *            в который будут дублироваться данные.
 * @param dst_end Указатель на конец блока памяти назначения.
 * @param src Указатель на начало блока памяти источника,
 *            откуда будут дублироваться данные.
 * @param src_end Указатель на конец блока памяти источника.
 *
 * @return Указатель на конец дублированных данных в блоке назначения,
 *         или вызывает исключение в случае ошибки.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_set(void *dst, const void *dst_end, const void *src, const void *src_end);

/**
 * @brief Заполняет участок памяти заданным значением.
 *
 * Эта функция заполняет память от указателя `begin` до указателя `end` значением `value`.
 * Для оптимизации используются инструкции SIMD (AVX и SSE), если они доступны.
 *
 * @param begin Указатель на начало области памяти,
 *              которую нужно заполнить.
 * @param end Указатель на конец области памяти.
 *            Заполнение происходит до, но не включая, этот адрес.
 * @param value Значение, которым будет заполнена память.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если @c dst или @c src является NULL.
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_raw_set_value(void *begin, const void *end, ae_char_t value);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_shift_left(void *dst, const void *dst_end, ae_usize_t shift);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_shift_right(void *dst, const void *dst_end, ae_usize_t shift);

AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_raw_shift_right_and_fill(void       *dst,
                                   const void *dst_end,
                                   ae_usize_t  shift,
                                   ae_char_t   value);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_RAW_H
