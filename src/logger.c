#include <ae/logger.h>
/* Дополнительные модули */
#include <ae/runtime_error_code.h>
#include <ae/runtime_expect.h>
#include <ae/runtime_assert.h>
#include <ae/ptr_util.h>
#include <ae/bit_util.h>
#include <ae/nullptr.h>

ae_logger_log_fn *
ae_logger_get_log_fn(const void *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, nullptr)
    return ae_ptr_cast(ae_logger_t, self)->log_fn;
}

ae_logger_level_flag_t
ae_logger_get_level_flag(const void *self)
{
    AE_RUNTIME_ASSERT(self, AE_RUNTIME_ERROR_NULL_POINTER, AE_LOGGER_LEVEL_FLAG_NONE)
    return ae_ptr_cast(ae_logger_t, self)->log_flag;
}

void
ae_logger_log(const void *self, ae_logger_level_t level, const char *format, ...)
{
    const ae_logger_level_flag_t level_flag = ae_logger_get_level_flag(self);
    AE_RUNTIME_EXPECT(ae_bit_check_by_index(level_flag, level))

    ae_logger_log_fn *log_fn = ae_logger_get_log_fn(self);
    AE_RUNTIME_EXPECT(log_fn)

    va_list args;
    va_start(args, format);
    log_fn(level, format, args);
    va_end(args);
}