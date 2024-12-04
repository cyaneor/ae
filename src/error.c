#include <ae/error.h>
/* Дополнительные модули */
#include <ae/runtime_assert.h>
#include <ae/runtime_errors.h>
#include <ae/runtime_try.h>
#include <ae/nullptr.h>

ae_error_code_t
ae_error_get_code(const ae_error_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->code;
}

const ae_error_message_t
ae_error_get_message(const ae_error_t *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, 0)
    return self->message;
}

void
ae_error_set_code(ae_error_t *self, ae_error_code_t code)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)
    self->code = code;
}

void
ae_error_set_message(ae_error_t *self, const ae_error_message_t message)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER)
    self->message = message;
}

void
ae_error_set(ae_error_t *self, ae_error_code_t code, const ae_error_message_t message)
{
    ae_runtime_try
    {
        ae_error_set_code(self, code);
        ae_error_set_message(self, message);
        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

void
ae_error_clear(ae_error_t *self)
{
    ae_error_set(self, AE_ERROR_CODE_NONE, nullptr);
}

void
ae_error_assign(ae_error_t *self, const ae_error_t *other)
{
    ae_runtime_try
    {
        const ae_error_code_t    code    = ae_error_get_code(other);
        const ae_error_message_t message = ae_error_get_message(other);

        ae_error_set(self, code, message);
        ae_runtime_try_interrupt();
    }
    ae_runtime_rethrow();
}

bool
ae_error_equal_code_to(const ae_error_t *self, ae_error_code_t code)
{
    return ae_error_get_code(self) == code;
}

bool
ae_error_equal_message_to(const ae_error_t *self, const ae_error_message_t message)
{
    return ae_error_get_message(self) == message;
}

bool
ae_error_equal_to(const ae_error_t *self, ae_error_code_t code, const ae_error_message_t message)
{
    return ae_error_equal_code_to(self, code) && ae_error_equal_message_to(self, message);
}

bool
ae_error_equal(const ae_error_t *self, const ae_error_t *other)
{
    const ae_error_code_t    code    = ae_error_get_code(other);
    const ae_error_message_t message = ae_error_get_message(other);

    return ae_error_equal_to(self, code, message);
}

bool
ae_error_is_none(const ae_error_t *self)
{
    return ae_error_equal_code_to(self, AE_ERROR_CODE_NONE);
}

bool
ae_error_is_exists(const ae_error_t *self)
{
    return !ae_error_is_none(self);
}
