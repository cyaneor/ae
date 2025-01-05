#include <ae/numeric_fixed_types.h>
#include <ae/static_assert.h>

ae_static_assert(sizeof(ae_u8_t) == 1, "Error: Size of type ae_u8_t must be 1 byte.");
ae_static_assert(sizeof(ae_u16_t) == 2, "Error: Size of type ae_u16_t must be 2 bytes.");
ae_static_assert(sizeof(ae_u32_t) == 4, "Error: Size of type ae_u32_t must be 4 bytes.");
ae_static_assert(sizeof(ae_u64_t) == 8, "Error: Size of type ae_u64_t must be 8 bytes.");
