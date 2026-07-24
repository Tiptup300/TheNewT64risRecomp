#ifndef __ULTRATYPES_H__
#define __ULTRATYPES_H__

/*
 * Minimal libultra fixed-width type definitions.
 *
 * The vendored recomp mod headers (recomputils.h) reference these standard N64
 * SDK type names. A real decomp ships the full <PR/ultratypes.h> from the SDK;
 * mods here only need the integer/float aliases, so we provide a self-contained
 * subset instead of depending on the (unavailable) SDK headers. Compiled with
 * -nostdinc, so this must not pull in any system header.
 *
 * MIPS o32 ABI: long is 32-bit, long long is 64-bit.
 */

typedef signed char        s8;
typedef unsigned char      u8;
typedef signed short       s16;
typedef unsigned short     u16;
typedef signed int         s32;
typedef unsigned int       u32;
typedef signed long long   s64;
typedef unsigned long long u64;

typedef float  f32;
typedef double f64;

typedef volatile s8  vs8;
typedef volatile u8  vu8;
typedef volatile s16 vs16;
typedef volatile u16 vu16;
typedef volatile s32 vs32;
typedef volatile u32 vu32;
typedef volatile s64 vs64;
typedef volatile u64 vu64;

#endif
