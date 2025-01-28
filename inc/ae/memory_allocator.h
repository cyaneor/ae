/**
 * @file memory_allocator.h
 * @brief Заголовочный файл, содержащий определения структуры
 *        аллокатора памяти и соответствующие функции.
 *
 * Этот файл предоставляет интерфейс для работы с аллокаторами памяти,
 * включая функции для выделения, освобождения и изменения размера памяти.
 * Также поддерживаются функции для работы с выровненной памятью.
 *
 * @note Все функции могут выбрасывать исключения в случае ошибок
 *       (например, если указатель равен `null` или если память не может быть выделена).
 *       Ожидается, что вызывающий код будет обрабатывать эти исключения.
 *
 * @see ae_memory_allocator_t
 */

#ifndef AE_MEMORY_ALLOCATOR_H
#define AE_MEMORY_ALLOCATOR_H

#include "memory_allocator_alloc_fn.h"
#include "memory_allocator_dealloc_fn.h"
#include "attribute.h"

/**
 * @struct ae_memory_allocator
 * @brief Структура, представляющая аллокатор памяти.
 *
 * Эта структура используется для управления выделением и освобождением памяти.
 * Она включает в себя указатели на функции для выделения и освобождения памяти.
 */
typedef struct ae_memory_allocator
{
    /**
     * @brief Функция для выделения памяти.
     *
     * Указатель на функцию, которая выполняет выделение памяти.
     * Эта функция должна быть реализована пользователем.
     */
    ae_memory_allocator_alloc_fn *alloc_fn;

    /**
     * @brief Функция для освобождения памяти.
     *
     * Указатель на функцию, которая выполняет освобождение памяти.
     * Эта функция должна быть реализована пользователем.
     */
    ae_memory_allocator_dealloc_fn *dealloc_fn;
} ae_memory_allocator_t;

// ------------------------------------------ Методы ------------------------------------------ //

AE_COMPILER(EXTERN_C_BEGIN)

/**
 * @brief Получает указатель на функцию выделения памяти из аллокатора.
 *
 * Эта функция возвращает указатель на функцию выделения памяти,
 * которая была инициализирована в структуре аллокатора.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             из которой нужно получить функцию выделения памяти.
 *
 * @return Указатель на функцию выделения памяти (alloc) из аллокатора,
 *         или `null`, если аллокатор не инициализирован.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_allocator_alloc_t
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_allocator_alloc_fn *
ae_memory_allocator_get_alloc_fn(const ae_memory_allocator_t *self);

/**
 * @brief Получает указатель на функцию освобождения памяти из аллокатора.
 *
 * Эта функция возвращает указатель на функцию освобождения памяти,
 * которая была инициализирована в структуре аллокатора.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             из которой нужно получить функцию освобождения памяти.
 *
 * @return Указатель на функцию освобождения памяти (dealloc) из аллокатора,
 *         или `null`, если аллокатор не инициализирован.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 *
 * @see ae_memory_allocator_free_t
 */
AE_ATTRIBUTE(SYMBOL)
ae_memory_allocator_dealloc_fn *
ae_memory_allocator_get_dealloc_fn(const ae_memory_allocator_t *self);

/**
 * @brief Выделяет память заданного размера с использованием аллокатора.
 *
 * Эта функция запрашивает выделение памяти
 * размером `size` у указанного аллокатора:
 *
 * - Если размер равен 0 или если аллокатор не инициализирован,
 *   будет выброшено исключение.
 * - В случае успешного выделения памяти,
 *   функция возвращает указатель на выделенный блок.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             которая будет использоваться для выделения памяти.
 * @param size Размер памяти в байтах, который необходимо выделить.
 *
 * @return Указатель на выделенный блок памяти, или `null`,
 *         если выделение памяти не удалось.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_ZERO_MEMORY_SIZE
 *        Если `size` равен 0.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если память не была успешно выделена.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 *
 * @note Если включена опция `AE_OPTION_FILL_ZERO_AFTER_MEMORY_ALLOCATE`,
 *       выделенная память будет заполнена нулями.
 *
 * @see ae_memory_allocator_get_alloc_fn
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_allocator_alloc(const ae_memory_allocator_t *self, ae_usize_t size);

/**
 * @brief Освобождает ранее выделенный блок памяти.
 *
 * Эта функция освобождает память,
 * выделенную ранее с помощью аллокатора:
 *
 * - Если указатель на память равен `null`,
 *   функция завершает выполнение без генерации ошибки.
 * - Если функция освобождения памяти не инициализирована,
 *   будет выброшено исключение.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             которая будет использоваться для освобождения памяти.
 * @param ptr Указатель на блок памяти,
 *            который необходимо освободить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note Если указатель `ptr` равен `null`,
 *       функция завершает выполнение без каких-либо действий.
 *
 * @see ae_memory_allocator_get_dealloc_fn
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_allocator_free(const ae_memory_allocator_t *self, void *ptr);

/**
 * @brief Изменяет размер ранее выделенного блока памяти.
 *
 * Эта функция изменяет размер блока памяти,
 * выделенного ранее с помощью аллокатора:
 *
 * - Если указатель `old_ptr` равен `null`,
 *   функция выделяет новую память размером `new_size`.
 * - Если размеры старого и нового блоков совпадают,
 *   возвращается указатель на существующий блок.
 * - Если новый размер равен 0, память освобождается,
 *   и возвращается `null`.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             которая будет использоваться для изменения размера памяти.
 * @param old_ptr Указатель на ранее выделенный блок памяти, который
 *                необходимо изменить.
 * @param old_size Размер ранее выделенного блока памяти в байтах.
 * @param new_size Новый размер блока памяти в байтах.
 *
 * @return Указатель на новый блок памяти,
 *         или `null`, если новый размер равен 0.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить новую память.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note Если `old_ptr` равен `null`, будет выделена новая память.
 *       Если `new_size` равен 0, память будет освобождена.
 *
 * @see ae_memory_allocator_alloc
 * @see ae_memory_allocator_free
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_allocator_realloc(const ae_memory_allocator_t *self,
                            void                        *old_ptr,
                            ae_usize_t                   old_size,
                            ae_usize_t                   new_size);

/**
 * @brief Выделяет память с заданным выравниванием.
 *
 * Эта функция выделяет блок памяти размером `size`,
 * выровненный по границе, заданной `alignment_size`:
 *
 * - Выравнивание должно быть степенью двойки.
 * - Функция возвращает указатель на выровненный адрес.
 * - Если выделение памяти не удалось, будет выброшено исключение.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             которая будет использоваться для выделения памяти.
 * @param size Размер памяти в байтах, который необходимо выделить.
 * @param alignment_size Размер выравнивания в байтах,
 *                       который должен быть степенью двойки.
 *
 * @return Указатель на выровненный блок памяти,
 *         или `null`, если выделение памяти не удалось.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_NOT_POWER_OF_TWO
 *        Если `alignment_size` не является степенью двойки.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить память.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 *
 * @note Указатель на невыравненную память сохраняется перед выровненным
 *       указателем для последующего освобождения.
 *
 * @see ae_memory_allocator_alloc
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_allocator_align_alloc(const ae_memory_allocator_t *self,
                                ae_usize_t                   size,
                                ae_usize_t                   alignment_size);

/**
 * @brief Освобождает ранее выделенный выровненный блок памяти.
 *
 * Эта функция освобождает память, выделенную ранее с помощью
 * функции `ae_memory_allocator_align_alloc`:
 *
 * - Указатель `ptr` должен указывать на выровненный блок памяти.
 * - Функция извлекает указатель на невыравненную память и освобождает его.
 * - Если указатель `ptr` равен `null`, функция завершает выполнение без каких-либо действий.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             которая будет использоваться для освобождения памяти.
 * @param ptr Указатель на выровненный блок памяти,
 *            который необходимо освободить.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note Если указатель `ptr` равен `null`,
 *       функция завершает выполнение без каких-либо действий.
 *
 * @see ae_memory_allocator_align_alloc
 * @see ae_memory_allocator_free
 */
AE_ATTRIBUTE(SYMBOL)
void
ae_memory_allocator_align_free(const ae_memory_allocator_t *self, void *ptr);

/**
 * @brief Изменяет размер ранее выделенного выровненного блока памяти.
 *
 * Эта функция изменяет размер блока памяти,
 * выделенного ранее с помощью функции `ae_memory_allocator_align_alloc`:
 *
 * - Если указатель `old_ptr` равен `null`,
 *   функция выделяет новую память с заданным выравниванием.
 * - Если размеры старого и нового блоков совпадают,
 *   возвращается указатель на существующий блок.
 * - Если новый размер равен 0, память освобождается,
 *   и возвращается `null`.
 *
 * @param self Указатель на структуру аллокатора памяти,
 *             которая будет использоваться для изменения размера памяти.
 * @param old_ptr Указатель на ранее выделенный выровненный блок памяти,
 *                который необходимо изменить.
 * @param old_size Размер ранее выделенного блока памяти в байтах.
 * @param new_size Новый размер блока памяти в байтах.
 * @param alignment_size Размер выравнивания в байтах,
 *                       который должен быть степенью двойки.
 *
 * @return Указатель на новый выровненный блок памяти,
 *         или `null`, если новый размер равен 0.
 *
 * @throw AE_RUNTIME_ERROR_NULL_POINTER
 *        Если указатель на `self` равен `null`.
 * @throw AE_RUNTIME_ERROR_NOT_POWER_OF_TWO
 *        Если `alignment_size` не является степенью двойки.
 * @throw AE_RUNTIME_ERROR_MEMORY_NOT_ALLOCATED
 *        Если не удалось выделить новую память.
 * @throw AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция выделения памяти не инициализирована.
 * @throw AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED
 *        Если функция освобождения памяти не инициализирована.
 *
 * @note Указатель на невыравненную память сохраняется перед выровненным
 *       указателем для последующего освобождения.
 *
 * @see ae_memory_allocator_align_alloc
 * @see ae_memory_allocator_align_free
 */
AE_ATTRIBUTE(SYMBOL)
void *
ae_memory_allocator_align_realloc(const ae_memory_allocator_t *self,
                                  void                        *old_ptr,
                                  ae_usize_t                   old_size,
                                  ae_usize_t                   new_size,
                                  ae_usize_t                   alignment_size);

AE_COMPILER(EXTERN_C_END)

#endif // AE_MEMORY_ALLOCATOR_H
