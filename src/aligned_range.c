#include <ae/aligned_range.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_allocator.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>

void
ae_aligned_range_clear(void *self)
{
    void *begin = ae_memory_range_get_begin(self);
    ae_runtime_allocator_align_free(begin);
    ae_memory_range_clear(self);
}

void
ae_aligned_range_exchange(void *self, void *other)
{
    ae_runtime_try
    {
        ae_aligned_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

bool
ae_aligned_range_resize(void *self, ae_usize_t size_in_bytes, ae_usize_t alignment_size)
{
    ae_runtime_try
    {
        void            *begin             = ae_memory_range_get_begin(self);
        const ae_usize_t old_size_in_bytes = ae_memory_range_total_size(self);

        // Вызов ae_runtime_allocator_align_realloc может привести к исключению.
        // Если исключение произойдет, блок try поймает его, и выполнение не
        // перейдет к вызову ae_memory_range_set_with_fallback.
        ae_memory_range_set_with_fallback(
            self,
            ae_runtime_allocator_align_realloc(
                begin, old_size_in_bytes, size_in_bytes, alignment_size),
            size_in_bytes);

        ae_runtime_try_interrupt(true);
    }
    ae_runtime_rethrow(false);
}