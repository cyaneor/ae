#include <ae/dynamic_block.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/allocated_block.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_return_if.h>
#include <ae/unified_block.h>
#include <ae/runtime_throw.h>
#include <ae/memory_range.h>
#include <ae/runtime_try.h>
#include <ae/ptr_traits.h>
#include <ae/nullptr.h>

void *
ae_dynamic_block_get_begin(const ae_dynamic_block_t *self)
{
    return ae_memory_range_get_begin(self);
}

ae_usize_t
ae_dynamic_block_size(const ae_dynamic_block_t *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, 0);
    return self->number_of_elements;
}

void
ae_dynamic_block_clear(ae_dynamic_block_t *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER);
    self->number_of_elements = 0;
}

bool
ae_dynamic_block_is_empty(const ae_dynamic_block_t *self)
{
    return ae_dynamic_block_size(self) == 0;
}

ae_usize_t
ae_dynamic_block_total_size(const ae_dynamic_block_t *self)
{
    const ae_usize_t element_size = ae_memory_block_get_element_size(self);
    ae_runtime_assert(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, 0);

    const ae_usize_t size = ae_dynamic_block_size(self);
    return size * element_size;
}

ae_usize_t
ae_dynamic_block_available_size(const ae_dynamic_block_t *self)
{
    const ae_usize_t max_size   = ae_allocated_block_max_size(self);
    const ae_usize_t total_size = ae_dynamic_block_total_size(self);
    return max_size - total_size;
}

void *
ae_dynamic_block_get_end(const ae_dynamic_block_t *self)
{
    const void *begin = ae_dynamic_block_get_begin(self);
    ae_runtime_return_if_not(begin, nullptr);

    const ae_usize_t total_size = ae_dynamic_block_total_size(self);
    return ae_ptr_add_offset(void, begin, total_size);
}

ae_usize_t
ae_dynamic_block_capacity(const ae_dynamic_block_t *self)
{
    return ae_memory_block_size(self);
}

void
ae_dynamic_block_shrink(ae_dynamic_block_t *self)
{
    const ae_usize_t capacity = ae_dynamic_block_capacity(self);
    const ae_usize_t size     = ae_dynamic_block_size(self);

    if (size < capacity)
    {
        ae_unified_block_resize(self, size);
    }
}

void
ae_dynamic_block_delete(ae_dynamic_block_t *self)
{
    ae_dynamic_block_clear(self);
    ae_dynamic_block_shrink(self);
}

bool
ae_dynamic_block_reserve(ae_dynamic_block_t *self, ae_usize_t number_of_elements)
{
    ae_runtime_try
    {
        const ae_usize_t capacity = ae_dynamic_block_capacity(self);
        const ae_usize_t size     = ae_dynamic_block_size(self);

        // Рассчитываем необходимую ёмкость (текущий размер + количество новых элементов)
        const ae_usize_t reserve_size = size + number_of_elements;

        // Если текущая ёмкость меньше требуемой, увеличиваем её
        if (capacity < reserve_size)
        {
            // Вычисляем новый размер ёмкости с учетом коэффициента роста
            const ae_usize_t new_capacity =
                capacity == 0 ? reserve_size : (capacity * AE_DYNAMIC_BLOCK_GROWTH_FACTOR) / 1000;

            // Увеличиваем ёмкость до нужного размера
            // Убедимся, что новый размер не меньше необходимого
            ae_unified_block_resize(self,
                                    new_capacity > reserve_size ? new_capacity : reserve_size);
        }

        ae_runtime_try_return(true);
    }
    ae_runtime_raise(false);
}

bool
ae_dynamic_block_resize(ae_dynamic_block_t *self, ae_usize_t number_of_elements)
{
    ae_runtime_try
    {
        const ae_usize_t capacity = ae_dynamic_block_capacity(self);
        if (capacity < number_of_elements)
        {
            ae_unified_block_resize(self, number_of_elements);
        }
        self->number_of_elements = number_of_elements;
        ae_runtime_try_return(true);
    }
    ae_runtime_raise(false);
}

bool
ae_dynamic_block_is_size_equal_to(const ae_dynamic_block_t *self, ae_usize_t size)
{
    return ae_dynamic_block_size(self) == size;
}

bool
ae_dynamic_block_is_size_equal(const ae_dynamic_block_t *self, const ae_dynamic_block_t *other)
{
    const ae_usize_t size = ae_dynamic_block_size(other);
    return ae_dynamic_block_is_size_equal_to(self, size);
}

bool
ae_dynamic_block_is_equal(const ae_dynamic_block_t *self, const ae_dynamic_block_t *other)
{
    return ae_dynamic_block_is_size_equal(self, other) && ae_aligned_block_is_equal(self, other);
}