#include <ae/dynamic_block.h>
/* Дополнительные модули */
#include <ae/allocated_block.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_expect.h>
#include <ae/unified_block.h>
#include <ae/memory_block.h>
#include <ae/memory_range.h>
#include <ae/runtime_try.h>
#include <ae/ptr_cast.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>

ae_usize_t
ae_dynamic_block_size(const ae_dynamic_block_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->number_of_elements;
}

void
ae_dynamic_block_clear(ae_dynamic_block_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)
    self->number_of_elements = 0;
}

void
ae_dynamic_block_delete(ae_dynamic_block_t *self)
{
    ae_dynamic_block_clear(self);
    ae_dynamic_block_shrink(self);
}

bool
ae_dynamic_block_empty(const ae_dynamic_block_t *self)
{
    return ae_dynamic_block_size(self) == 0;
}

ae_usize_t
ae_dynamic_block_total_size(const ae_dynamic_block_t *self)
{
    const ae_usize_t size = ae_dynamic_block_size(self);
    const ae_usize_t element_size =
        ae_memory_block_element_size(ae_ptr_cast(const ae_memory_block_t, self));

    return size * element_size;
}

ae_usize_t
ae_dynamic_block_available_size(const ae_dynamic_block_t *self)
{
    const ae_usize_t max_size =
        ae_allocated_block_max_size(ae_ptr_cast(const ae_allocated_block_t, self));
    const ae_usize_t total_size = ae_dynamic_block_total_size(self);

    return max_size - total_size;
}

void *
ae_dynamic_block_end(ae_dynamic_block_t *self)
{
    void *begin = ae_memory_range_begin(ae_ptr_cast(ae_memory_range_t, self));
    AE_RUNTIME_EXPECT(begin, nullptr)

    const ae_usize_t total_size = ae_dynamic_block_total_size(self);
    return ae_ptr_add(begin, total_size);
}

const void *
ae_dynamic_block_end_const(const ae_dynamic_block_t *self)
{
    return ae_dynamic_block_end(ae_ptr_cast(ae_dynamic_block_t, self));
}

ae_usize_t
ae_dynamic_block_capacity(const ae_dynamic_block_t *self)
{
    return ae_memory_block_size(ae_ptr_cast(ae_memory_block_t, self));
}

void
ae_dynamic_block_shrink(ae_dynamic_block_t *self)
{
    const ae_usize_t capacity = ae_dynamic_block_capacity(self);
    const ae_usize_t size     = ae_dynamic_block_size(self);

    if (size < capacity)
    {
        ae_unified_block_resize(ae_ptr_cast(ae_unified_block_t, self), size);
    }
}

void
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
                (capacity == 0) ? reserve_size : (capacity * AE_MEMORY_GROWTH_FACTOR);

            // Увеличиваем ёмкость до нужного размера
            // Убедимся, что новый размер не меньше необходимого
            ae_unified_block_resize(ae_ptr_cast(ae_unified_block_t, self),
                                    new_capacity > reserve_size ? new_capacity : reserve_size);
        }

        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

void
ae_dynamic_block_resize(ae_dynamic_block_t *self, ae_usize_t number_of_elements)
{
    ae_runtime_try
    {
        const ae_usize_t capacity = ae_dynamic_block_capacity(self);
        if (capacity < number_of_elements)
        {
            ae_unified_block_resize(ae_ptr_cast(ae_unified_block_t, self), number_of_elements);
        }
        self->number_of_elements = number_of_elements;
        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

bool
ae_dynamic_block_size_equal_to(const ae_dynamic_block_t *self, ae_usize_t size)
{
    return ae_dynamic_block_size(self) == size;
}

bool
ae_dynamic_block_size_equal(const ae_dynamic_block_t *self, const ae_dynamic_block_t *other)
{
    const ae_usize_t size = ae_dynamic_block_size(other);
    return ae_dynamic_block_size_equal_to(self, size);
}

bool
ae_dynamic_block_equal(const ae_dynamic_block_t *self, const ae_dynamic_block_t *other)
{
    return ae_dynamic_block_size_equal(self, other) &&
           ae_aligned_block_equal(ae_ptr_cast(const ae_aligned_block_t, self),
                                  ae_ptr_cast(const ae_aligned_block_t, self));
}