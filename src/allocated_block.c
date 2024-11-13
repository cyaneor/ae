#include <ae/allocated_block.h>
#include <ae/allocated_range.h>
#include <ae/runtime_assert.h>
#include <ae/memory_block.h>

void
ae_allocated_block_resize(ae_allocated_block_t *self, ae_usize_t number_of_elements)
{
    const ae_usize_t element_size = ae_memory_block_element_size(self);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE)
    ae_allocated_range_resize((ae_allocated_range_t *)self, element_size * number_of_elements);
}

void
ae_allocated_block_clear(ae_allocated_block_t *self)
{
    ae_allocated_block_resize(self, 0);
}