/* x86-sysv.c -- FFI support for i386 SVr4 ABI
 * 
 * Author: Ian.Piumarta@INRIA.Fr
 * 
 * Last edited: 2009-08-19 04:22:59 by piumarta on emilia-2.local
 * 
 *   Copyright (C) 1996-2004 by Ian Piumarta and other authors/contributors
 *                              listed elsewhere in this file.
 *   All rights reserved.
 *   
 *   This file is part of Unix Squeak.
 * 
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 * 
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * 
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 *
 * BUGS:
 * 
 *   Because of the way strings and structs are handled, this implementation
 *   is neither reentrant nor thread safe.
 */

#include "sq.h"
#include "sqFFI.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef LONGLONG
# define LONGLONG long long
#endif

#if 0
# define debugf(ARGS)printf ARGS
#else
# define debugf(ARGS)
#endif

#if defined(FFI_TEST)
  static int primitiveFail(void) { puts("primitive fail"); exit(1); return 0; }
#else
  extern struct VirtualMachine *interpreterProxy;
# define primitiveFail() interpreterProxy->primitiveFail()
#endif

enum { FFI_MAX_STACK= 512 };

int	 ffiStack[FFI_MAX_STACK];
int	 ffiStackIndex= 0;

static char	*ffiTempStrings[FFI_MAX_STACK];
static int	 ffiTempStringCount= 0;


int	 ffiIntReturnValue;
int	 ffiLongReturnValue;
double	 ffiFloatReturnValue;
int	*ffiStructReturnValue;


extern int ffiCallAddressOf(void *addr, void *stack, int size);


int ffiInitialize(void)
{
  ffiStackIndex= 0;
  ffiFloatReturnValue= 0.0;
  return 1;
}


int ffiSupportsCallingConvention(int callType)
{
  return (callType == FFICallTypeCDecl)
    ||   (callType == FFICallTypeApi);
}


int ffiAlloc(int byteSize)
{
  return (int)malloc(byteSize);
}


int ffiFree(int ptr)
{
  if (ptr) free((void *)ptr);
  return 1;
}


#define checkStack()				\
  if (ffiStackIndex >= FFI_MAX_STACK)		\
     return primitiveFail();

#define pushInt(value)				\
  checkStack();					\
  ffiStack[ffiStackIndex++]= (value)


int ffiCanReturn(int *structSpec, int specSize)
{
  int header= *structSpec;
  if (header & FFIFlagPointer)
    return 1;
  if (header & FFIFlagStructure)
    {
      /* structs are always returned as pointers to hidden structures */
      int structSize= header & FFIStructSizeMask;
      ffiStructReturnValue= malloc(structSize);
      if (!ffiStructReturnValue)
	return 0;
      pushInt((int)ffiStructReturnValue);
    }
  return 1;
}


int ffiPushSignedChar(int value)
{ 
  debugf(("ffiPushSignedChar %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushUnsignedChar(int value)
{ 
  debugf(("ffiPushUnsignedChar %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushSignedByte(int value)
{ 
  debugf(("ffiPushSignedByte %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushUnsignedByte(int value)
{ 
  debugf(("ffiPushUnsignedByte %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushSignedShort(int value)
{ 
  debugf(("ffiPushSignedShort %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushUnsignedShort(int value)
{ 
  debugf(("ffiPushUnsignedShort %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushSignedInt(int value)
{ 
  debugf(("ffiPushSignedInt %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushUnsignedInt(int value)
{ 
  debugf(("ffiPushUnsignedInt %d\n", value));
  pushInt(value);
  return 1; 
}

int ffiPushSignedLongLong(int low, int high)
{ 
  debugf(("ffiPushSignedLongLong %d %d\n", low, high));
  pushInt(low);
  pushInt(high);
  return 1; 
}

int ffiPushUnsignedLongLong(int low, int high)
{ 
  debugf(("ffiPushUnsignedLongLong %d %d\n", low, high));
  pushInt(low);
  pushInt(high);
  return 1; 
}

int ffiPushPointer(int pointer)
{ 
  debugf(("ffiPushPointer %d\n", pointer));
  pushInt(pointer);
  return 1; 
}

int ffiPushSingleFloat(double value)
{ 
  float f= (float)value;
  debugf(("ffiPushSingleFloat %f\n", value));
  pushInt(*(int *)&f);
  return 1; 
}

int ffiPushDoubleFloat(double value)
{ 
  debugf(("ffiPushDoubleFloat %f\n", value));
  pushInt(((int *)&value)[0]);
  pushInt(((int *)&value)[1]);
  return 1; 
}

int ffiPushStringOfLength(int srcIndex, int length)
{
  char *ptr;
  debugf(("ffiPushStringOfLength %d\n", length));
  checkStack();
  ptr= (char *)malloc(length + 1);
  if (!ptr)
    return primitiveFail();
  debugf(("  ++ alloc string\n"));
  memcpy(ptr, (void *)srcIndex, length);
  ptr[length]= '\0';
  ffiTempStrings[ffiTempStringCount++]= ptr;
  pushInt((int)ptr);
  return 1;
}

int ffiPushStructureOfLength(int pointer, int *structSpec, int specSize)
{
  int lbs= *structSpec & FFIStructSizeMask;
  int size= (lbs + sizeof(int) - 1) / sizeof(int);
  debugf(("ffiPushStructureOfLength %d (%db %dw)\n", specSize, lbs, size));
  if (ffiStackIndex + size > FFI_MAX_STACK)
    return primitiveFail();
  memcpy((void *)(ffiStack + ffiStackIndex), (void *)pointer, lbs);
  ffiStackIndex += size;
  return 1;
}


double  ffiReturnFloatValue(void)	{ return ffiFloatReturnValue; }
int	ffiLongLongResultLow(void)	{ return ffiIntReturnValue; }
int	ffiLongLongResultHigh(void)	{ return ffiLongReturnValue; }


int ffiStoreStructure(int address, int structSize)
{
  debugf(("ffiStoreStructure %d %d\n", address, structSize));
  memcpy((void *)address, (ffiStructReturnValue
			   ? (void *)ffiStructReturnValue
			   : (void *)&ffiIntReturnValue),
	 structSize);
  return 1;
}


int ffiCleanup(void)
{
  int i;
  debugf(("ffiCleanup\n"));
  for (i= 0;  i < ffiTempStringCount;  ++i)
    {
      debugf(("  ++ free string\n"));
      free(ffiTempStrings[i]);
    }
  ffiTempStringCount= 0;
  if (ffiStructReturnValue)
    {
      debugf(("  ++ free struct\n"));
      free(ffiStructReturnValue);
      ffiStructReturnValue= 0;
    }
  return 1;
}


int ffiCallAddressOfWithPointerReturn(int fn, int callType)
{
  return ffiCallAddressOf((void *)fn, (void *)ffiStack,
			  ffiStackIndex * sizeof(int));
}

int ffiCallAddressOfWithStructReturn(int fn, int callType, int* structSpec, int specSize)
{
  return ffiCallAddressOf((void *)fn, (void *)ffiStack,
			  ffiStackIndex * sizeof(int));
}

int ffiCallAddressOfWithReturnType(int fn, int callType, int typeSpec)
{
  return ffiCallAddressOf((void *)fn, (void *)ffiStack,
			  ffiStackIndex * sizeof(int));
}


#if defined(FFI_TEST)
void ffiDoAssertions(void) {}
#endif
