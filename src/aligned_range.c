#include <ae/aligned_range.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_allocator.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>

void
ae_aligned_range_clear(void *self)
{
    ae_runtime_try
    {
        ae_runtime_allocator_align_free(ae_memory_range_get_begin(self));
        ae_memory_range_clear(self);
        ae_runtime_try_return();
    }
    ae_runtime_raise();
}

void
ae_aligned_range_exchange(void *self, void *other)
{
    ae_runtime_try
    {
        ae_aligned_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_return();
    }
    ae_runtime_raise();
}

void
ae_aligned_range_resize(void *self, ae_usize_t size, ae_usize_t alignment_size)
{
    ae_runtime_try
    {
        void            *begin    = ae_memory_range_get_begin(self);
        const ae_usize_t cur_size = ae_memory_range_size(self);

        void *allocated = ae_runtime_allocator_align_realloc(begin, cur_size, size, alignment_size);
        ae_memory_range_set_with_fallback(self, allocated, size);
        ae_runtime_try_return();
    }
    ae_runtime_raise();
}