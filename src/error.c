#include <ae/error.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/error_initializer.h>
#include <ae/runtime_assert.h>
#include <ae/runtime_try.h>

ae_error_code_t
ae_error_get_code(const ae_error_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->code;
}

ae_error_message_t
ae_error_get_message(const ae_error_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->message;
}

void
ae_error_set(ae_error_t *self, ae_error_code_t code, ae_error_message_t message)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)

    self->code    = code;
    self->message = message;
}

void
ae_error_set_code(ae_error_t *self, ae_error_code_t code)
{
    ae_error_set(self, code, nullptr);
}

void
ae_error_assign(ae_error_t *self, const ae_error_t *other)
{
    ae_error_code_t    code    = ae_error_get_code(other);
    ae_error_message_t message = ae_error_get_message(other);

    ae_error_set(self, code, message);
}

void
ae_error_swap(ae_error_t *self, ae_error_t *other)
{
    ae_error_t _t = ae_error_empty_initializer();
    ae_runtime_try
    {
        ae_error_assign(&_t, self);
        ae_error_assign(self, other);
        ae_error_assign(other, &_t);

        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

void
ae_error_clear(ae_error_t *self)
{
    const ae_error_t other = ae_error_empty_initializer();
    ae_error_assign(self, &other);
}

void
ae_error_exchange(ae_error_t *self, ae_error_t *other)
{
    ae_error_clear(self);
    ae_error_swap(self, other);
}

ae_error_code_t
ae_error_get_code_and_clear(ae_error_t *self)
{
    const ae_error_code_t code = ae_error_get_code(self);
    ae_error_clear(self);
    return code;
}

bool
ae_error_is_equal_code_to(const ae_error_t *self, ae_error_code_t code)
{
    return ae_error_get_code(self) == code;
}

bool
ae_error_is_equal_code(const ae_error_t *self, const ae_error_t *other)
{
    const ae_error_code_t code = ae_error_get_code(other);
    return ae_error_is_equal_code_to(self, code);
}

bool
ae_error_is_equal_message_to(const ae_error_t *self, ae_error_message_t message)
{
    return ae_error_get_message(self) == message;
}

bool
ae_error_is_equal_message(const ae_error_t *self, const ae_error_t *other)
{
    ae_error_message_t message = ae_error_get_message(other);
    return ae_error_is_equal_message_to(self, message);
}

bool
ae_error_is_equal(const ae_error_t *self, const ae_error_t *other)
{
    return ae_error_is_equal_code(self, other) && ae_error_is_equal_message(self, other);
}

bool
ae_error_is_none(const ae_error_t *self)
{
    return ae_error_get_code(self) == AE_ERROR_CODE_NONE;
}

bool
ae_error_is_some(const ae_error_t *self)
{
    return !ae_error_is_none(self);
}