#ifndef AE_ADDR_TRAITS_H
#define AE_ADDR_TRAITS_H

#include "addr.h"
#include "numeric_traits.h"
#include "reinterpret_cast.h"

/**
 * @def ae_addr_to_ptr
 * @brief Преобразует адрес в указатель заданного типа.
 *
 * Этот макрос принимает адрес и возвращает указатель на значение
 * заданного типа. Он позволяет безопасно преобразовывать адреса
 * в соответствующие указатели.
 *
 * @param T Тип, к которому следует привести адрес.
 * @param addr Адрес, который необходимо преобразовать в указатель.
 *
 * @return Указатель на значение типа `T`,
 *         соответствующее указанному адресу.
 */
#define ae_addr_to_ptr(T, addr) ae_reinterpret_cast(T *, addr)

/**
 * @def ae_addr_from_ptr
 * @brief Преобразует указатель в адрес.
 *
 * Этот макрос принимает указатель и возвращает его значение
 * в виде целого числа (адреса) типа `ae_uaddr_t`.
 * Он позволяет легко работать с адресами в виде целых чисел.
 *
 * @param ptr Указатель, который необходимо преобразовать в адрес.
 * @return Адрес, соответствующий указанному указателю в виде
 *         значения типа `ae_uaddr_t`.
 */
#define ae_addr_from_ptr(ptr) ae_reinterpret_cast(ae_uaddr_t, ptr)

/**
 * @def ae_addr_diff
 * @brief Вычисляет разницу между двумя адресами.
 *
 * Этот макрос используется для вычисления разницы между двумя указателями.
 * Он возвращает разницу между значениями указателей `addr1` и `addr2`,
 * что соответствует числу байт, которое нужно пройти, чтобы перейти
 * от одного адреса к другому.
 *
 * @param addr1 Первый указатель.
 * @param addr2 Второй указатель.
 *
 * @return Разница между адресами (тип зависит от архитектуры и компилятора).
 */
#define ae_addr_diff(addr1, addr2) (addr1 - addr2)

/**
 * @def ae_addr_is_aligned
 * @brief Проверяет, выровнен ли адрес по заданному выравниванию.
 *
 * Этот макрос проверяет, является ли заданный адрес выровненным
 * относительно указанного выравнивания, используя проверку на кратность.
 *
 * @param addr Адрес, который необходимо проверить.
 * @param align Выравнивание, которому должен соответствовать адрес.
 *
 * @return `true`, если `addr` выровнен по границе `align`;
 *         `false` в противном случае.
 *
 * @note Выравнивание должно быть степенью двойки, чтобы корректно работать.
 */
#define ae_addr_is_aligned(addr, align) ae_numeric_has_zero_remainder(addr, align)

#endif // AE_ADDR_TRAITS_H
