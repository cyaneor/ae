#include <ae/allocated_block.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/allocated_range.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_throw.h>
#include <ae/memory_block.h>
#include <ae/runtime_try.h>
#include <ae/ptr_util.h>

void
ae_allocated_block_exchange(void *self, void *other)
{
    ae_runtime_assert(ae_memory_block_is_element_size_equal(self, other),
                      AE_RUNTIME_ERROR_DIFFERENT_ELEMENT_SIZE);

    ae_runtime_try
    {
        ae_allocated_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_interrupt();
    }
    ae_runtime_raise();
}

ae_usize_t
ae_allocated_block_max_size(const void *self)
{
    const ae_usize_t element_size = ae_memory_block_get_element_size(self);
    ae_runtime_assert(element_size, AE_RUNTIME_ERROR_ZERO_ELEMENT_SIZE, 0);
    return AE_USIZE_T_MAX / element_size;
}

bool
ae_allocated_block_is_max_size_exceeds(const void *self, ae_usize_t number_of_elements)
{
    const ae_usize_t max_size = ae_allocated_block_max_size(self);
    return number_of_elements > max_size;
}

void
ae_allocated_block_resize(void *self, ae_usize_t number_of_elements)
{
    ae_runtime_assert(ae_allocated_block_is_max_size_exceeds(self, number_of_elements),
                      AE_RUNTIME_ERROR_EXCEEDS_MAX_SIZE);

    const ae_usize_t element_size  = ae_memory_block_get_element_size(self);
    const ae_usize_t size_in_bytes = number_of_elements * element_size;
    ae_allocated_range_resize(self, size_in_bytes);
}