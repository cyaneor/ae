#include <ae/aligned_range.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_allocator.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>

bool
ae_aligned_range_clear(void *self)
{
    ae_runtime_try
    {
        ae_runtime_allocator_align_free(ae_memory_range_get_begin(self));
        ae_runtime_try_interrupt(ae_memory_range_clear(self));
    }
    ae_runtime_raise(false);
}

bool
ae_aligned_range_exchange(void *self, void *other)
{
    return ae_aligned_range_clear(self) && ae_memory_range_swap(self, other);
}

bool
ae_aligned_range_resize(void *self, ae_usize_t size_in_bytes, ae_usize_t alignment_size)
{
    ae_runtime_try
    {
        void            *begin             = ae_memory_range_get_begin(self);
        const ae_usize_t old_size_in_bytes = ae_memory_range_total_size(self);

        void *allocated = ae_runtime_allocator_align_realloc(
            begin, old_size_in_bytes, size_in_bytes, alignment_size);

        ae_runtime_try_interrupt(ae_memory_range_set_with_fallback(self, allocated, size_in_bytes));
    }
    ae_runtime_raise(false);
}