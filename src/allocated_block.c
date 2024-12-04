#include <ae/memory_block.h>
/* Дополнительные модули */
#include <ae/allocated_block.h>
#include <ae/allocated_range.h>
#include <ae/runtime_errors.h>
#include <ae/runtime_assert.h>

ae_usize_t
ae_allocated_block_max_size(const ae_allocated_block_t *self)
{
    const ae_usize_t element_size = ae_memory_block_element_size(self);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_DIVISION_BY_ZERO, 0)

    return AE_USIZE_T_MAX / element_size;
}

void
ae_allocated_block_resize(ae_allocated_block_t *self, ae_usize_t number_of_elements)
{
    const ae_usize_t element_size = ae_memory_block_element_size(self);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE)

    const ae_usize_t max_size = ae_allocated_block_max_size(self);
    AE_RUNTIME_ASSERT(number_of_elements <= max_size, AE_RUNTIME_ERROR_EXCEEDS_MAX_SIZE)

    ae_allocated_range_resize((ae_allocated_range_t *)self, element_size * number_of_elements);
}

void
ae_allocated_block_clear(ae_allocated_block_t *self)
{
    ae_allocated_block_resize(self, 0);
}