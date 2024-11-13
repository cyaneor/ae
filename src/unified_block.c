#include <ae/unified_block.h>
/* Дополнительные модули */
#include <ae/allocated_block.h>
#include <ae/aligned_block.h>
#include <ae/ptr_util.h>
#include <ae/bit_util.h>

void
ae_unified_block_clear(ae_unified_block_t *self)
{
    ae_unified_block_resize(self, 0);
}

void
ae_unified_block_resize(ae_unified_block_t *self, ae_usize_t number_of_elements)
{
    const ae_usize_t alignment_size = ae_aligned_block_alignment_size(self);
    ae_bit_is_single(alignment_size)
        ? ae_aligned_block_resize(self, number_of_elements)
        : ae_allocated_block_resize(ae_ptr_cast(ae_allocated_block_t, self), number_of_elements);
}