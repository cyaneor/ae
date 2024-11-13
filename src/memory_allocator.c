#include <ae/memory_allocator.h>
#include <ae/runtime_assert.h>
#include <ae/nullptr.h>

ae_memory_allocator_alloc_t *
ae_memory_allocator_alloc_fn(const ae_memory_allocator_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return self->alloc;
}

ae_memory_allocator_free_t *
ae_memory_allocator_free_fn(const ae_memory_allocator_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return self->free;
}

void *
ae_memory_allocator_alloc(ae_memory_allocator_t *self, ae_usize_t size_in_bytes)
{
    ae_memory_allocator_alloc_t *alloc_fn = ae_memory_allocator_alloc_fn(self);
    AE_RUNTIME_ASSERT(alloc_fn, AE_RUNTIME_ERROR_ALLOCATOR_FUNCTION_NOT_INITIALIZED, nullptr)
    return alloc_fn(size_in_bytes);
}

void
ae_memory_allocator_free(ae_memory_allocator_t *self, void *ptr)
{
    ae_memory_allocator_free_t *free_fn = ae_memory_allocator_free_fn(self);
    AE_RUNTIME_ASSERT(free_fn, AE_RUNTIME_ERROR_DEALLOCATOR_FUNCTION_NOT_INITIALIZED)
    free_fn(ptr);
}