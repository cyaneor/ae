/**
 * @file attribute_thread_local.h
 * @brief Определение атрибута для локальных потоковых переменных.
 *
 * Этот файл содержит определения макроса для указания, что переменные
 * являются локальными для потока. В зависимости от конфигурации,
 * атрибут может быть определен с использованием компиляторского
 * атрибута или оставаться пустым.
 *
 * Если включена опция AE_LIBRARY_OPTION_THREAD_LOCAL_VARIABLES,
 * макрос AE_ATTRIBUTE_THREAD_LOCAL будет определен как атрибут компилятора,
 * указывающий на то, что переменные локальны для потока. В противном случае,
 * этот макрос остается пустым, что означает отсутствие специального атрибута
 * для локальности в потоке.
 */

#ifndef AE_ATTRIBUTE_THREAD_LOCAL_H
#define AE_ATTRIBUTE_THREAD_LOCAL_H

#include "compiler.h"

#ifdef AE_LIBRARY_OPTION_THREAD_LOCAL_VARIABLES
/**
 * @def AE_ATTRIBUTE_THREAD_LOCAL
 * @brief Атрибут для локальных потоковых переменных.
 *
 * Если включена опция AE_LIBRARY_OPTION_THREAD_LOCAL_VARIABLES,
 * этот макрос будет определен как атрибут компилятора,
 * указывающий на то, что переменная является локальной для потока.
 */
#    define AE_ATTRIBUTE_THREAD_LOCAL AE_COMPILER_ATTRIBUTE_THREAD_LOCAL
#else
/**
 * @def AE_ATTRIBUTE_THREAD_LOCAL
 * @brief Пустой макрос для локальных потоковых переменных.
 *
 * Если опция AE_LIBRARY_OPTION_THREAD_LOCAL_VARIABLES
 * не включена, этот макрос остается пустым, что означает, что
 * переменные не имеют специального атрибута для локальности в потоке.
 */
#    define AE_ATTRIBUTE_THREAD_LOCAL
#endif

#endif // AE_ATTRIBUTE_THREAD_LOCAL_H
