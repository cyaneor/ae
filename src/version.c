#include <ae/version.h>
/* Дополнительные модули */
#include <ae/stringify.h>

const ae_str_raw_t
ae_version(void)
{
    return ae_stringify_args(AE_VERSION_MAJOR.AE_VERSION_MINOR.AE_VERSION_PATCH);
}

ae_return_t
ae_version_major(void)
{
    return AE_VERSION_MAJOR;
}

ae_return_t
ae_version_minor(void)
{
    return AE_VERSION_MINOR;
}

ae_return_t
ae_version_patch(void)
{
    return AE_VERSION_PATCH;
}