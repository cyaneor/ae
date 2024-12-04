#include <ae/aligned_block.h>
/* Дополнительные модули */
#include <ae/allocated_block.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_errors.h>
#include <ae/aligned_range.h>
#include <ae/ptr_cast.h>

ae_usize_t
ae_aligned_block_alignment_size(const ae_aligned_block_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->alignment_size;
}

void
ae_aligned_block_resize(ae_aligned_block_t *self, ae_usize_t number_of_elements)
{
    const ae_allocated_block_t *allocated_block = ae_ptr_cast(const ae_allocated_block_t, self);
    const ae_usize_t            element_size    = ae_memory_block_element_size(allocated_block);
    AE_RUNTIME_ASSERT(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE)

    const ae_usize_t max_size = ae_allocated_block_max_size(allocated_block);
    AE_RUNTIME_ASSERT(number_of_elements <= max_size, AE_RUNTIME_ERROR_EXCEEDS_MAX_SIZE);

    const ae_usize_t alignment_size = ae_aligned_block_alignment_size(self);
    const ae_usize_t size_in_bytes  = number_of_elements * element_size;
    ae_aligned_range_resize(ae_ptr_cast(ae_aligned_range_t, self), size_in_bytes, alignment_size);
}

void
ae_aligned_block_clear(ae_aligned_block_t *self)
{
    ae_aligned_block_resize(self, 0);
}

bool
ae_aligned_block_alignment_size_equal_to(const ae_aligned_block_t *self, ae_usize_t alignment_size)
{
    return ae_aligned_block_alignment_size(self) == alignment_size;
}

bool
ae_aligned_block_alignment_size_equal(const ae_aligned_block_t *self,
                                      const ae_aligned_block_t *other)
{
    const ae_usize_t alignment_size = ae_aligned_block_alignment_size(other);
    return ae_aligned_block_alignment_size_equal_to(self, alignment_size);
}

bool
ae_aligned_block_equal(const ae_aligned_block_t *self, const ae_aligned_block_t *other)
{
    return ae_aligned_block_alignment_size_equal(self, other) &&
           ae_memory_block_equal(ae_ptr_cast(const ae_memory_block_t, self),
                                 ae_ptr_cast(const ae_memory_block_t, other));
}