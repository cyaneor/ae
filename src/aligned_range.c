#include <ae/aligned_range.h>
/* Дополнительные модули */
#include <ae/runtime_allocator.h>
#include <ae/memory_allocator.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>

void
ae_aligned_range_clear(ae_aligned_range_t *self)
{
    void *begin = ae_memory_range_get_begin(self);
    if (begin)
    {
        ae_memory_allocator_align_free(ae_runtime_allocator(), begin);
        ae_memory_range_clear(self);
    }
}

void
ae_aligned_range_exchange(ae_aligned_range_t *self, ae_aligned_range_t *other)
{
    ae_runtime_try
    {
        ae_aligned_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_finalize();
    }
    ae_runtime_rethrow();
}

void
ae_aligned_range_resize(ae_aligned_range_t *self,
                        ae_usize_t          size_in_bytes,
                        ae_usize_t          alignment_size)
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
            ae_memory_allocator_align_realloc(
                ae_runtime_allocator(), begin, old_size_in_bytes, size_in_bytes, alignment_size),
            size_in_bytes);

        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}