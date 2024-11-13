#include <ae/aligned_block.h>
#include <ae/runtime_assert.h>
#include <ae/aligned_range.h>
#include <ae/memory_block.h>

ae_usize_t
ae_aligned_block_alignment_size(const ae_aligned_block_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->alignment_size;
}

void
ae_aligned_block_resize(ae_aligned_block_t *self, ae_usize_t number_of_elements)
{
    const ae_usize_t element_size = ae_memory_block_element_size((const ae_memory_block_t *)self);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE)

    const ae_usize_t alignment_size = ae_aligned_block_alignment_size(self);
    ae_aligned_range_resize(
        (ae_aligned_range_t *)self, number_of_elements * element_size, alignment_size);
}

void
ae_aligned_block_clear(ae_aligned_block_t *self)
{
    ae_aligned_block_resize(self, 0);
}