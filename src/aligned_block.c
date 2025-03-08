#include <ae/aligned_block.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/allocated_block.h>
#include <ae/runtime_assert.h>
#include <ae/aligned_range.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>
#include <ae/ptr_traits.h>

ae_usize_t
ae_aligned_block_get_alignment_size(const void *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, 0);
    return ae_ptr_cast(ae_aligned_block_t, self)->alignment_size;
}

void
ae_aligned_block_exchange(void *self, void *other)
{
    ae_runtime_assert(ae_memory_block_is_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE);
    ae_runtime_try
    {
        ae_aligned_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_return();
    }
    ae_runtime_raise();
}

void
ae_aligned_block_resize(void *self, ae_usize_t number_of_elements)
{
    ae_runtime_assert(ae_allocated_block_is_max_size_exceeds(self, number_of_elements),
                      AE_RUNTIME_ERROR_EXCEEDS_MAX_SIZE);

    const ae_usize_t element_size   = ae_memory_block_get_element_size(self);
    const ae_usize_t alignment_size = ae_aligned_block_get_alignment_size(self);

    const ae_usize_t size_in_bytes = number_of_elements * element_size;
    ae_aligned_range_resize(self, size_in_bytes, alignment_size);
}

bool
ae_aligned_block_is_alignment_size_equal_to(const void *self, ae_usize_t alignment_size)
{
    return ae_aligned_block_get_alignment_size(self) == alignment_size;
}

bool
ae_aligned_block_is_alignment_size_equal(const void *self, const void *other)
{
    const ae_usize_t alignment_size = ae_aligned_block_get_alignment_size(other);
    return ae_aligned_block_is_alignment_size_equal_to(self, alignment_size);
}

bool
ae_aligned_block_is_equal(const void *self, const void *other)
{
    return ae_aligned_block_is_alignment_size_equal(self, other) &&
           ae_memory_block_is_equal(self, other);
}