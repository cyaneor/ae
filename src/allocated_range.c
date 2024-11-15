#include <ae/allocated_range.h>
#include <ae/runtime_allocator.h>
#include <ae/runtime_throw.h>
#include <ae/runtime_try.h>

void
ae_allocated_range_clear(ae_allocated_range_t *self)
{
    void *begin = ae_memory_range_begin(self);
    if (begin)
    {
        ae_runtime_allocator_free(begin);
        ae_memory_range_clear(self);
    }
}

void
ae_allocated_range_exchange(ae_allocated_range_t *self, ae_allocated_range_t *other)
{
    ae_runtime_try
    {
        ae_allocated_range_clear(self);
        ae_memory_range_swap(self, other);
        ae_runtime_try_finalize();
    }
    ae_runtime_rethrow();
}

void
ae_allocated_range_resize(ae_allocated_range_t *self, ae_usize_t size_in_bytes)
{
    ae_runtime_try
    {
        void            *begin      = ae_memory_range_begin(self);
        const ae_usize_t total_size = ae_memory_range_total_size(self);

        // В этом блоке мы пытаемся изменить размер выделенной памяти.
        // Если функция realloc не сможет выделить новую память (например, из-за нехватки памяти),
        // то произойдет исключение, и управление передастся в блок catch (ae_runtime_rethrow).
        //
        // Это значит, что вызов ae_memory_range_reset_with_fallback не произойдет,
        // и память, ранее выделенная для self, останется нетронутой.
        // Таким образом, мы защищаемся от потери данных в случае ошибки выделения памяти.
        ae_memory_range_reset_with_fallback(
            self, ae_runtime_allocator_realloc(begin, total_size, size_in_bytes), size_in_bytes);

        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}