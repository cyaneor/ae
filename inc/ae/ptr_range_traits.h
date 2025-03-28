/**
 * @file ptr_range_traits.h
 * @brief Макросы для работы с диапазонами указателей.
 *
 * Этот файл содержит макросы для работы с диапазонами указателей,
 * включая проверку их выравнивания, пересечения, а также определения
 * размера диапазонов в терминах количества элементов заданного типа.
 *
 * Макросы в этом файле позволяют проверять:
 * - лежит ли указатель в пределах интервала;
 * - выровнены ли указатели или диапазоны по заданному выравниванию;
 * - перекрываются ли два диапазона;
 * - является ли указатель действительным в пределах интервала.
 */

#ifndef AE_PTR_RANGE_TRAITS_H
#define AE_PTR_RANGE_TRAITS_H

#include "ptr_traits.h"

/**
 * @def ae_ptr_range_has
 * @brief Проверяет, находится ли указатель в пределах заданного интервала.
 *
 * Этот макрос проверяет, находится ли значение указателя `ptr`
 * в пределах интервала, определяемого значениями `begin` и `end`.
 *
 * Для выполнения проверки используется макрос `ae_interval_has_closed`,
 * который проверяет, что указатель лежит внутри интервала
 * с замкнутыми границами (включая обе границы).
 *
 * @param begin Начало интервала.
 * @param end Конец интервала.
 * @param ptr Указатель, значение которого проверяется на принадлежность интервалу.
 *
 * @return Возвращает значение выражения `ae_interval_has_closed(begin, end, ptr)`,
 *         что истинно, если указатель `ptr` лежит в интервале [begin, end], включая границы.
 *
 * @see ae_interval_has_closed
 */
#define ae_ptr_range_has(begin, end, ptr) ae_interval_has_closed(begin, end, ptr)

/**
 * @def ae_ptr_range_is_aligned
 * @brief Проверяет, выровнены ли оба указателя по заданному выравниванию.
 *
 * Этот макрос принимает два указателя и значение выравнивания,
 * а затем проверяет, выровнены ли адреса, на которые указывают
 * оба указателя, по указанному значению выравнивания.
 *
 * @param ptr1 Первый указатель, адрес которого необходимо проверить.
 * @param ptr2 Второй указатель, адрес которого необходимо проверить.
 * @param align Значение выравнивания, с которым нужно сравнить адреса.
 *
 * @return `true`, если оба адреса, на которые указывают `ptr1` и
 *         `ptr2`, выровнены по `align`; `false` в противном случае.
 *
 * @note Делитель (выравнивание) не должен быть равен нулю,
 *       так как это приведет к неопределенному поведению.
 */
#define ae_ptr_range_is_aligned(ptr1, ptr2, align)                                                 \
    (ae_ptr_is_aligned(ptr1, align) && ae_ptr_is_aligned(ptr2, align))

/**
 * @def ae_ptr_range_is_aligned_both
 * @brief Проверяет, выровнены ли два диапазона указателей по заданному выравниванию.
 *
 * Этот макрос проверяет, выровнены ли оба диапазона указателей по указанному значению выравнивания.
 * Он использует два других макроса: `ae_ptr_range_is_aligned`, чтобы убедиться,
 * что оба диапазона указателей (`lhs` и `rhs`) выровнены по заданному выравниванию.
 *
 * @param lhs Начало первого диапазона указателей.
 * @param lhs_end Конец первого диапазона указателей.
 * @param rhs Начало второго диапазона указателей.
 * @param rhs_end Конец второго диапазона указателей.
 * @param align Значение выравнивания, с которым нужно сравнить адреса.
 *
 * @return `true`, если оба диапазона указателей выровнены по значению `align`;
 *         `false`, если хотя бы один из диапазонов не выровнен.
 *
 * @note Делитель (выравнивание) не должен быть равен нулю,
 *       так как это приведет к неопределенному поведению.
 */
#define ae_ptr_range_is_aligned_both(lhs, lhs_end, rhs, rhs_end, align)                            \
    (ae_ptr_range_is_aligned(lhs, lhs_end, align) && ae_ptr_range_is_aligned(rhs, rhs_end, align))

/**
 * @def ae_ptr_range_is_not_overlapped
 * @brief Проверяет, не перекрываются ли два диапазона.
 *
 * Этот макрос проверяет, не перекрываются ли два диапазона, определяемых
 * указателями. Он использует два диапазона: первый начинается с указателя
 * `lhs_begin`, а второй — с указателя `rhs_begin` и заканчивается на `rhs_end`.
 * Макрос возвращает истинное значение, если диапазоны не пересекаются, и
 * ложное, если они пересекаются.
 *
 * @param lhs_begin Указатель на начало первого диапазона.
 * @param rhs_begin Указатель на начало второго диапазона.
 * @param rhs_end Указатель на конец второго диапазона.
 *
 * @return Возвращает `true`, если диапазоны не перекрываются, иначе — `false`.
 *
 * @note Диапазоны считаются неперекрывающимися, если первый диапазон полностью
 *       идет до второго, либо второй диапазон не пересекается с первым.
 */
#define ae_ptr_range_is_not_overlapped(lhs_begin, rhs_begin, rhs_end)                              \
    ((lhs_begin <= rhs_begin) || (rhs_end <= lhs_begin))

/**
 * @def ae_ptr_range_is_overlapped
 * @brief Проверяет, перекрываются ли два диапазона.
 *
 * Этот макрос проверяет, перекрываются ли два диапазона, определяемых указателями.
 * Он использует два диапазона: первый начинается с указателя `lhs_begin`,
 * а второй — с указателя `rhs_begin` и заканчивается на `rhs_end`.
 *
 * Макрос возвращает истинное значение, если диапазоны перекрываются, и ложное, если они не
 * перекрываются. Макрос использует другой макрос `ae_ptr_range_is_not_overlapped`,
 * который проверяет, что диапазоны не перекрываются.
 *
 * Если результат этого макроса ложный, значит, диапазоны перекрываются,
 * и макрос `ae_ptr_range_is_overlapped` возвращает `true`.
 *
 * @param lhs_begin Указатель на начало первого диапазона.
 * @param rhs_begin Указатель на начало второго диапазона.
 * @param rhs_end Указатель на конец второго диапазона.
 *
 * @return Возвращает `true`, если диапазоны перекрываются,
 *         иначе — `false`.
 */
#define ae_ptr_range_is_overlapped(lhs_begin, rhs_begin, rhs_end)                                  \
    (!ae_ptr_range_is_not_overlapped(lhs_begin, rhs_begin, rhs_end))

/**
 * @def ae_ptr_range_size(end, begin, type_size)
 * @brief Вычисляет количество элементов заданного типа между двумя указателями.
 *
 * Этот макрос рассчитывает размер диапазона между двумя указателями (`end` и `begin`)
 * в терминах количества элементов заданного типа, определяемого параметром `type_size`.
 * Он использует разницу адресов, полученную через `ae_ptr_to_addr_diff`,
 * и делит её на размер типа в байтах.
 *
 * @param begin Указатель на начало диапазона (включая первый элемент).
 * @param end Указатель на конец диапазона (не включая сам элемент).
 * @param type_size Размер типа данных в байтах (например, sizeof(int)).
 * @return Количество элементов типа `type_size`, помещающихся между `begin` и `end`.
 *
 * @note Предполагается, что `ae_ptr_to_addr_diff` определён где-то в проекте и возвращает
 *       разницу между адресами в байтах (например, как `(uintptr_t)(end) - (uintptr_t)(begin)`).
 * @note Указатели должны быть выровнены и находиться в одном непрерывном блоке памяти,
 *       иначе результат может быть некорректным.
 *
 * Пример использования:
 * @code
 * int arr[] = {1, 2, 3, 4};
 * size_t size = ae_ptr_range_size(arr, arr + 4, sizeof(int)); // вернёт 4
 * @endcode
 */
#define ae_ptr_range_size(begin, end, type_size) (ae_ptr_to_addr_diff(end, begin) / (type_size))

/**
 * @def ae_ptr_range_is_valid
 * @brief Проверяет, является ли указатель действительным в пределах заданного интервала.
 *
 * Этот макрос проверяет два условия:
 * 1. Указатель `begin` не является NULL.
 * 2. Интервал, определяемый значениями `begin` и `end`, является валидным,
 *    что проверяется с помощью макроса `ae_interval_is_valid_closed`.
 *
 * Таким образом, данный макрос используется для проверки, что указатель
 * не равен NULL и что интервал, в который он попадает, является валидным.
 *
 * @param begin Начало интервала.
 * @param end Конец интервала.
 *
 * @return Возвращает значение выражения `begin && ae_interval_is_valid_closed(begin, end)`,
 *         что истинно, если указатель `begin` не равен NULL и интервал
 *         с замкнутыми границами валиден.
 *
 * @see ae_interval_is_valid_closed
 */
#define ae_ptr_range_is_valid(begin, end) (begin && ae_interval_is_valid_closed(begin, end))

/**
 * @def ae_ptr_ranges_is_valid
 * @brief Проверяет, что два диапазона указателей являются замкнутыми.
 *
 * Этот макрос использует два диапазона указателей и проверяет,
 * что оба диапазона являются замкнутыми.
 *
 * Это достигается путем проверки того, что оба диапазона являются действительными
 * замкнутыми диапазонами, с помощью макроса `ae_ptr_range_is_valid`.
 *
 * Каждый из диапазонов должен быть замкнутым, что означает,
 * что указатели не равны нулю и что указатель `begin` не больше указателя `end`.
 *
 * @param r1_begin Указатель на начало первого диапазона.
 * @param r1_end Указатель на конец первого диапазона.
 * @param r2_begin Указатель на начало второго диапазона.
 * @param r2_end Указатель на конец второго диапазона.
 *
 * @return Возвращает 1 (истина), если оба диапазона являются замкнутыми
 *         (проверяются с помощью макроса `ae_ptr_is_valid_closed_range`), иначе 0 (ложь).
 */
#define ae_ptr_ranges_is_valid(r1_begin, r1_end, r2_begin, r2_end)                                 \
    (ae_ptr_range_is_valid(r1_begin, r1_end) && ae_ptr_range_is_valid(r2_begin, r2_end))

#endif // AE_PTR_RANGE_TRAITS_H
