/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2024 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
// 1
int test_bitOr(int x, int y)
{
  return x|y;
}
int test_evenBits(void) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i+=2)
    result |= 1<<i;
  return result;
}
int test_fitsShort(int x)
{
  short int sx = (short int) x;
  return x == sx;
}
int test_thirdBits(void) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i+=3)
    result |= 1<<i;
  return result;
}
int test_tmin(void) {
  return 0x80000000;
}
//2
int test_allOddBits(int x) {
  int i;
  for (i = 1; i < 32; i+=2)
      if ((x & (1<<i)) == 0)
   return 0;
  return 1;
}
int test_copyLSB(int x)
{
  return (x & 0x1) ? -1 : 0;
}
unsigned test_floatAbsVal(unsigned uf) {
  float f = u2f(uf);
  unsigned unf = f2u(-f);
  if (isnan(f))
    return uf;
  /* An unfortunate hack to get around a limitation of the BDD Checker */
  if ((int) uf < 0)
      return unf;
  else
      return uf;
}
int test_isPositive(int x) {
  return x > 0;
}
int test_leastBitPos(int x) {
  int mask = 1;
  if (x == 0)
    return 0;
  while (!(mask & x)) {
    mask = mask << 1;
  }
  return mask;
}
int test_oddBits(void) {
  int result = 0;
  int i;
  for (i = 1; i < 32; i+=2)
    result |= 1<<i;
  return result;
}
//3
int test_conditional(int x, int y, int z)
{
  return x?y:z;
}
int test_isGreater(int x, int y)
{
  return x > y;
}
int test_multFiveEighths(int x)
{
  return (x*5)/8;
}
int test_remainderPower2(int x, int n)
{
    int p2n = 1<<n;
    return x%p2n;
}
int test_subtractionOK(int x, int y)
{
  long long ldiff = (long long) x - y;
  return ldiff == (int) ldiff;
}
//4
int test_bitCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}
int test_bitReverse(int x) {
    int result = 0;
    int i;
    for (i = 0; i < 32; i++) {
 int bit = (x >> i) & 0x1;
 int pos = 31-i;
 result |= bit << pos;
    }
    return result;
}
int test_greatestBitPos(int x) {
    unsigned mask = 1<<31;
    if (x == 0)
 return 0;
    while (!(mask & x)) {
 mask = mask >> 1;
    }
    return mask;
}
int test_intLog2(int x) {
  int mask, result;
  /* find the leftmost bit */
  result = 31;
  mask = 1 << result;
  while (!(x & mask)) {
    result--;
    mask = 1 << result;
  }
  return result;
}
int test_leftBitCount(int x) {
  int result = 0;
  int i;
  for (i = 31; i >= 0; i--) {
      int bit = (x >> i) & 0x1;
      if (!bit)
   break;
      result ++;
  }
  return result;
}
int test_twosComp2SignMag(int x) {
  int sign = x < 0;
  int mag = x < 0 ? -x : x;
  return (sign << 31) | mag;
}
