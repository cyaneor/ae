#include <ae/error.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/error_initializer.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>
#include <ae/ptr_util.h>
#include <ae/nullptr.h>
#include <ae/runtime_throw.h>

ae_error_code_t
ae_error_get_code(const void *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, AE_ERROR_CODE_NONE);

    const ae_error_t *err = ae_ptr_cast(ae_error_t, self);
    return err->code;
}

ae_error_desc_t
ae_error_get_desc(const void *self)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER, AE_ERROR_CODE_NONE);

    const ae_error_t *err = ae_ptr_cast(ae_error_t, self);
    return err->desc;
}

void
ae_error_set(void *self, ae_error_code_t code, ae_error_desc_t desc)
{
    ae_runtime_assert(self, AE_RUNTIME_ERROR_NULL_POINTER);

    ae_error_t *err = ae_ptr_cast(ae_error_t, self);
    err->code       = code;
    err->desc       = desc;
}

void
ae_error_assign(void *self, const void *other)
{
    const ae_error_code_t code = ae_error_get_code(other);
    ae_error_desc_t       desc = ae_error_get_desc(other);
    ae_error_set(self, code, desc);
}

void
ae_error_clear(void *self)
{
    const ae_error_t _t = ae_error_empty_initializer();
    ae_error_assign(self, &_t);
}

ae_error_code_t
ae_error_get_code_and_clear(void *self)
{
    const ae_error_code_t code = ae_error_get_code(self);
    ae_error_clear(self);
    return code;
}

void
ae_error_swap(void *self, void *other)
{
    ae_error_t _t = ae_error_empty_initializer();
    ae_runtime_try
    {
        ae_error_assign(&_t, self);
        ae_error_assign(self, other);
        ae_error_assign(other, &_t);
        ae_runtime_try_interrupt();
    }
    ae_runtime_raise();
}

void
ae_error_exchange(void *self, void *other)
{
    ae_error_clear(self);
    ae_error_swap(self, other);
}

bool
ae_error_is_code_equal_to(const void *self, ae_error_code_t code)
{
    return ae_error_get_code(self) == code;
}

bool
ae_error_is_code_equal(const void *self, const void *other)
{
    const ae_error_code_t code = ae_error_get_code(other);
    return ae_error_is_code_equal_to(self, code);
}

bool
ae_error_is_desc_equal_to(const void *self, ae_error_desc_t desc)
{
    return ae_error_get_desc(self) == desc;
}

bool
ae_error_is_desc_equal(const void *self, const void *other)
{
    ae_error_desc_t desc = ae_error_get_desc(other);
    return ae_error_is_desc_equal_to(self, desc);
}

bool
ae_error_is_equal(const void *self, const void *other)
{
    return ae_error_is_code_equal(self, other) && ae_error_is_desc_equal(self, other);
}

bool
ae_error_is_none(const void *self)
{
    return ae_error_is_code_equal_to(self, AE_ERROR_CODE_NONE);
}