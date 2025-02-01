#include <ae/unified_block.h>
/* Дополнительные модули */
#include <ae/allocated_block.h>
#include <ae/aligned_block.h>
#include <ae/aligned_range.h>
#include <ae/bit_util.h>

void
ae_unified_block_clear(void *self)
{
    const ae_usize_t alignment_size = ae_aligned_block_get_alignment_size(self);
    ae_bit_is_single(alignment_size) ? ae_aligned_range_clear(self)
                                     : ae_allocated_range_clear(self);
}

void
ae_unified_block_exchange(void *self, void *other)
{
    const ae_usize_t alignment_size = ae_aligned_block_get_alignment_size(self);
    ae_bit_is_single(alignment_size) ? ae_aligned_block_exchange(self, other)
                                     : ae_allocated_block_exchange(self, other);
}

void
ae_unified_block_resize(void *self, ae_usize_t number_of_elements)
{
    const ae_usize_t alignment_size = ae_aligned_block_get_alignment_size(self);
    ae_bit_is_single(alignment_size) ? ae_aligned_block_resize(self, number_of_elements)
                                     : ae_allocated_block_resize(self, number_of_elements);
}