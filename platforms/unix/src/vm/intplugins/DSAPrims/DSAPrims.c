/* Automatically generated from Squeak on #(22 March 2005 1:50:46 pm) */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

/* memory access macros */
#define byteAt(i) (*((unsigned char *) (i)))
#define byteAtput(i, val) (*((unsigned char *) (i)) = val)
#define longAt(i) (*((int *) (i)))
#define longAtput(i, val) (*((int *) (i)) = val)


/*** Constants ***/

/*** Function Prototypes ***/
static int addBackDivisorDigitShift(int digitShift);
static int bigDivideLoop(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static int halt(void);
static int leftRotateby(unsigned int anInteger, int bits);
static int msg(char *s);
#pragma export on
EXPORT(int) primitiveBigDivide(void);
EXPORT(int) primitiveBigMultiply(void);
EXPORT(int) primitiveExpandBlock(void);
EXPORT(int) primitiveHasSecureHashPrimitive(void);
EXPORT(int) primitiveHashBlock(void);
EXPORT(int) primitiveHighestNonZeroDigitIndex(void);
EXPORT(int) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
static int subtractDivisorMultipliedByDigitdigitShift(int digit, int digitShift);
/*** Variables ***/
static int divisorDigitCount;
static unsigned char* dsaDivisor;
static unsigned char* dsaQuotient;
static unsigned char* dsaRemainder;

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"DSAPrims 22 March 2005 (i)"
#else
	"DSAPrims 22 March 2005 (e)"
#endif
;
static int remainderDigitCount;



/*	Add back the divisor shifted left by the given number of digits. This is done only when the estimate of quotient digit was one larger than the correct value. */

static int addBackDivisorDigitShift(int digitShift) {
    int sum;
    int i;
    int carry;
    int rIndex;

	carry = 0;
	rIndex = digitShift + 1;
	for (i = 1; i <= divisorDigitCount; i += 1) {
		sum = ((dsaRemainder[rIndex]) + (dsaDivisor[i])) + carry;
		dsaRemainder[rIndex] = (sum & 255);
		carry = ((unsigned) sum >> 8);
		rIndex += 1;
	}
	sum = (dsaRemainder[rIndex]) + carry;
	dsaRemainder[rIndex] = (sum & 255);
}


/*	This is the core of the divide algorithm. This loop steps through the digit positions of the quotient, each time estimating the right quotient digit, subtracting from the remainder the divisor times the quotient digit shifted left by the appropriate number of digits. When the loop terminates, all digits of the quotient have been filled in and the remainder contains a value less than the divisor. The tricky bit is estimating the next quotient digit. Knuth shows that the digit estimate computed here will never be less than it should be and cannot be more than one over what it should be. Furthermore, the case where the estimate is one too large is extremely rare. For example, in a typical test of 100000 random 60-bit division problems, the rare case only occured five times. See Knuth, volume 2 ('Semi-Numerical Algorithms') 2nd edition, pp. 257-260 */
/*	extract the top two digits of the divisor */

static int bigDivideLoop(void) {
    int thirdDigit;
    int d2;
    int firstDigit;
    int j;
    int d1;
    int digitShift;
    int qTooBig;
    int firstTwoDigits;
    int q;
    int sum;
    int i;
    int carry;
    int rIndex;
    int resultDigit;
    int borrow;
    int prod;
    int rIndex1;
    int i1;

	d1 = dsaDivisor[divisorDigitCount];
	d2 = dsaDivisor[divisorDigitCount - 1];
	for (j = remainderDigitCount; j >= (divisorDigitCount + 1); j += -1) {
		firstDigit = dsaRemainder[j];
		firstTwoDigits = (((unsigned) firstDigit << 8)) + (dsaRemainder[j - 1]);

		/* estimate q, the next digit of the quotient */

		thirdDigit = dsaRemainder[j - 2];
		if (firstDigit == d1) {
			q = 255;
		} else {
			q = firstTwoDigits / d1;
		}
		if ((d2 * q) > ((((unsigned) (firstTwoDigits - (q * d1)) << 8)) + thirdDigit)) {
			q -= 1;
			if ((d2 * q) > ((((unsigned) (firstTwoDigits - (q * d1)) << 8)) + thirdDigit)) {
				q -= 1;
			}
		}
		digitShift = (j - divisorDigitCount) - 1;
		if (q > 0) {
			/* begin subtractDivisorMultipliedByDigit:digitShift: */
			borrow = 0;
			rIndex1 = digitShift + 1;
			for (i1 = 1; i1 <= divisorDigitCount; i1 += 1) {
				prod = ((dsaDivisor[i1]) * q) + borrow;
				borrow = ((unsigned) prod >> 8);
				resultDigit = (dsaRemainder[rIndex1]) - (prod & 255);
				if (resultDigit < 0) {
					resultDigit += 256;
					borrow += 1;
				}
				dsaRemainder[rIndex1] = resultDigit;
				rIndex1 += 1;
			}
			if (borrow == 0) {
				qTooBig = 0;
				goto l1;
			}
			resultDigit = (dsaRemainder[rIndex1]) - borrow;
			if (resultDigit < 0) {
				dsaRemainder[rIndex1] = (resultDigit + 256);
				qTooBig = 1;
				goto l1;
			} else {
				dsaRemainder[rIndex1] = resultDigit;
				qTooBig = 0;
				goto l1;
			}
		l1:	/* end subtractDivisorMultipliedByDigit:digitShift: */;
			if (qTooBig) {
				/* begin addBackDivisorDigitShift: */
				carry = 0;
				rIndex = digitShift + 1;
				for (i = 1; i <= divisorDigitCount; i += 1) {
					sum = ((dsaRemainder[rIndex]) + (dsaDivisor[i])) + carry;
					dsaRemainder[rIndex] = (sum & 255);
					carry = ((unsigned) sum >> 8);
					rIndex += 1;
				}
				sum = (dsaRemainder[rIndex]) + carry;
				dsaRemainder[rIndex] = (sum & 255);
				q -= 1;
			}
		}
		dsaQuotient[digitShift + 1] = q;
	}
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static int halt(void) {
	;
}


/*	Rotate the given 32-bit integer left by the given number of bits and answer the result. */

static int leftRotateby(unsigned int anInteger, int bits) {
	return (anInteger << bits) | (((unsigned) anInteger) >> (32 - bits));
}

static int msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Called with three LargePositiveInteger arguments, rem, div, quo. Divide div into rem and store the quotient into quo, leaving the remainder in rem. */
/*	Assume: quo starts out filled with zeros. */

EXPORT(int) primitiveBigDivide(void) {
    int rem;
    int div;
    int quo;
    int thirdDigit;
    int d2;
    int firstDigit;
    int j;
    int d1;
    int digitShift;
    int qTooBig;
    int firstTwoDigits;
    int q;
    int sum;
    int i;
    int carry;
    int rIndex;
    int resultDigit;
    int borrow;
    int prod;
    int rIndex1;
    int i1;

	quo = interpreterProxy->stackObjectValue(0);
	div = interpreterProxy->stackObjectValue(1);
	rem = interpreterProxy->stackObjectValue(2);
	interpreterProxy->success((interpreterProxy->fetchClassOf(rem)) == (interpreterProxy->classLargePositiveInteger()));
	interpreterProxy->success((interpreterProxy->fetchClassOf(div)) == (interpreterProxy->classLargePositiveInteger()));
	interpreterProxy->success((interpreterProxy->fetchClassOf(quo)) == (interpreterProxy->classLargePositiveInteger()));
	if (interpreterProxy->failed()) {
		return null;
	}
	dsaRemainder = interpreterProxy->firstIndexableField(rem);
	dsaDivisor = interpreterProxy->firstIndexableField(div);
	dsaQuotient = interpreterProxy->firstIndexableField(quo);
	divisorDigitCount = interpreterProxy->stSizeOf(div);

	/* adjust pointers for base-1 indexing */

	remainderDigitCount = interpreterProxy->stSizeOf(rem);
	dsaRemainder -= 1;
	dsaDivisor -= 1;
	dsaQuotient -= 1;
	/* begin bigDivideLoop */
	d1 = dsaDivisor[divisorDigitCount];
	d2 = dsaDivisor[divisorDigitCount - 1];
	for (j = remainderDigitCount; j >= (divisorDigitCount + 1); j += -1) {
		firstDigit = dsaRemainder[j];
		firstTwoDigits = (((unsigned) firstDigit << 8)) + (dsaRemainder[j - 1]);
		thirdDigit = dsaRemainder[j - 2];
		if (firstDigit == d1) {
			q = 255;
		} else {
			q = firstTwoDigits / d1;
		}
		if ((d2 * q) > ((((unsigned) (firstTwoDigits - (q * d1)) << 8)) + thirdDigit)) {
			q -= 1;
			if ((d2 * q) > ((((unsigned) (firstTwoDigits - (q * d1)) << 8)) + thirdDigit)) {
				q -= 1;
			}
		}
		digitShift = (j - divisorDigitCount) - 1;
		if (q > 0) {
			/* begin subtractDivisorMultipliedByDigit:digitShift: */
			borrow = 0;
			rIndex1 = digitShift + 1;
			for (i1 = 1; i1 <= divisorDigitCount; i1 += 1) {
				prod = ((dsaDivisor[i1]) * q) + borrow;
				borrow = ((unsigned) prod >> 8);
				resultDigit = (dsaRemainder[rIndex1]) - (prod & 255);
				if (resultDigit < 0) {
					resultDigit += 256;
					borrow += 1;
				}
				dsaRemainder[rIndex1] = resultDigit;
				rIndex1 += 1;
			}
			if (borrow == 0) {
				qTooBig = 0;
				goto l1;
			}
			resultDigit = (dsaRemainder[rIndex1]) - borrow;
			if (resultDigit < 0) {
				dsaRemainder[rIndex1] = (resultDigit + 256);
				qTooBig = 1;
				goto l1;
			} else {
				dsaRemainder[rIndex1] = resultDigit;
				qTooBig = 0;
				goto l1;
			}
		l1:	/* end subtractDivisorMultipliedByDigit:digitShift: */;
			if (qTooBig) {
				/* begin addBackDivisorDigitShift: */
				carry = 0;
				rIndex = digitShift + 1;
				for (i = 1; i <= divisorDigitCount; i += 1) {
					sum = ((dsaRemainder[rIndex]) + (dsaDivisor[i])) + carry;
					dsaRemainder[rIndex] = (sum & 255);
					carry = ((unsigned) sum >> 8);
					rIndex += 1;
				}
				sum = (dsaRemainder[rIndex]) + carry;
				dsaRemainder[rIndex] = (sum & 255);
				q -= 1;
			}
		}
		dsaQuotient[digitShift + 1] = q;
	}
	interpreterProxy->pop(3);
}


/*	Multiple f1 by f2, placing the result into prod. f1, f2, and prod must be LargePositiveIntegers, and the length of prod must be the sum of the lengths of f1 and f2. */
/*	Assume: prod starts out filled with zeros */

EXPORT(int) primitiveBigMultiply(void) {
    unsigned char *f1Ptr;
    int sum;
    int k;
    int f2;
    int i;
    int f1Len;
    int f2Len;
    int prod;
    unsigned char *f2Ptr;
    int carry;
    int j;
    int f1;
    unsigned char *prodPtr;
    int digit;
    int prodLen;

	prod = interpreterProxy->stackObjectValue(0);
	f2 = interpreterProxy->stackObjectValue(1);
	f1 = interpreterProxy->stackObjectValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(prod));
	interpreterProxy->success(interpreterProxy->isBytes(f2));
	interpreterProxy->success(interpreterProxy->isBytes(f1));
	interpreterProxy->success((interpreterProxy->fetchClassOf(prod)) == (interpreterProxy->classLargePositiveInteger()));
	interpreterProxy->success((interpreterProxy->fetchClassOf(f2)) == (interpreterProxy->classLargePositiveInteger()));
	interpreterProxy->success((interpreterProxy->fetchClassOf(f1)) == (interpreterProxy->classLargePositiveInteger()));
	if (interpreterProxy->failed()) {
		return null;
	}
	prodLen = interpreterProxy->stSizeOf(prod);
	f1Len = interpreterProxy->stSizeOf(f1);
	f2Len = interpreterProxy->stSizeOf(f2);
	interpreterProxy->success(prodLen == (f1Len + f2Len));
	if (interpreterProxy->failed()) {
		return null;
	}
	prodPtr = interpreterProxy->firstIndexableField(prod);
	f2Ptr = interpreterProxy->firstIndexableField(f2);
	f1Ptr = interpreterProxy->firstIndexableField(f1);
	for (i = 0; i <= (f1Len - 1); i += 1) {
		if ((digit = f1Ptr[i]) != 0) {
			carry = 0;

			/* Loop invariants: 0 <= carry <= 16rFF, k = i + j - 1 */

			k = i;
			for (j = 0; j <= (f2Len - 1); j += 1) {
				sum = (((f2Ptr[j]) * digit) + (prodPtr[k])) + carry;
				carry = ((unsigned) sum >> 8);
				prodPtr[k] = (sum & 255);
				k += 1;
			}
			prodPtr[k] = carry;
		}
	}
	interpreterProxy->pop(3);
}


/*	Expand a 64 byte ByteArray (the first argument) into and an Bitmap of 80 32-bit words (the second argument). When reading a 32-bit integer from the ByteArray, consider the first byte to contain the most significant bits of the word (i.e., use big-endian byte ordering). */

EXPORT(int) primitiveExpandBlock(void) {
    int expanded;
    int buf;
    int i;
    int src;
    unsigned int *wordPtr;
    unsigned char *bytePtr;
    int v;

	expanded = interpreterProxy->stackObjectValue(0);
	buf = interpreterProxy->stackObjectValue(1);
	interpreterProxy->success(interpreterProxy->isWords(expanded));
	interpreterProxy->success(interpreterProxy->isBytes(buf));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((interpreterProxy->stSizeOf(expanded)) == 80);
	interpreterProxy->success((interpreterProxy->stSizeOf(buf)) == 64);
	if (interpreterProxy->failed()) {
		return null;
	}
	wordPtr = interpreterProxy->firstIndexableField(expanded);
	bytePtr = interpreterProxy->firstIndexableField(buf);
	src = 0;
	for (i = 0; i <= 15; i += 1) {
		v = ((((bytePtr[src]) << 24) + ((bytePtr[src + 1]) << 16)) + ((bytePtr[src + 2]) << 8)) + (bytePtr[src + 3]);
		wordPtr[i] = v;
		src += 4;
	}
	for (i = 16; i <= 79; i += 1) {
		v = (((wordPtr[i - 3]) ^ (wordPtr[i - 8])) ^ (wordPtr[i - 14])) ^ (wordPtr[i - 16]);
		v = leftRotateby(v, 1);
		wordPtr[i] = v;
	}
	interpreterProxy->pop(2);
}


/*	Answer true if the secure hash primitive is implemented. */

EXPORT(int) primitiveHasSecureHashPrimitive(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(1);
}


/*	Hash a Bitmap of 80 32-bit words (the first argument), using the given state (the second argument). */

EXPORT(int) primitiveHashBlock(void) {
    int a;
    int state;
    unsigned int *bufPtr;
    int e;
    int buf;
    int d;
    unsigned int *statePtr;
    int i;
    int c;
    int tmp;
    int b;

	state = interpreterProxy->stackObjectValue(0);
	buf = interpreterProxy->stackObjectValue(1);
	interpreterProxy->success(interpreterProxy->isWords(state));
	interpreterProxy->success(interpreterProxy->isWords(buf));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((interpreterProxy->stSizeOf(state)) == 5);
	interpreterProxy->success((interpreterProxy->stSizeOf(buf)) == 80);
	if (interpreterProxy->failed()) {
		return null;
	}
	statePtr = interpreterProxy->firstIndexableField(state);
	bufPtr = interpreterProxy->firstIndexableField(buf);
	a = statePtr[0];
	b = statePtr[1];
	c = statePtr[2];
	d = statePtr[3];
	e = statePtr[4];
	for (i = 0; i <= 19; i += 1) {
		tmp = (((1518500249 + ((b & c) | ((~b) & d))) + (leftRotateby(a, 5))) + e) + (bufPtr[i]);
		e = d;
		d = c;
		c = leftRotateby(b, 30);
		b = a;
		a = tmp;
	}
	for (i = 20; i <= 39; i += 1) {
		tmp = (((1859775393 + ((b ^ c) ^ d)) + (leftRotateby(a, 5))) + e) + (bufPtr[i]);
		e = d;
		d = c;
		c = leftRotateby(b, 30);
		b = a;
		a = tmp;
	}
	for (i = 40; i <= 59; i += 1) {
		tmp = (((2400959708U + (((b & c) | (b & d)) | (c & d))) + (leftRotateby(a, 5))) + e) + (bufPtr[i]);
		e = d;
		d = c;
		c = leftRotateby(b, 30);
		b = a;
		a = tmp;
	}
	for (i = 60; i <= 79; i += 1) {
		tmp = (((3395469782U + ((b ^ c) ^ d)) + (leftRotateby(a, 5))) + e) + (bufPtr[i]);
		e = d;
		d = c;
		c = leftRotateby(b, 30);
		b = a;
		a = tmp;
	}
	statePtr[0] = ((statePtr[0]) + a);
	statePtr[1] = ((statePtr[1]) + b);
	statePtr[2] = ((statePtr[2]) + c);
	statePtr[3] = ((statePtr[3]) + d);
	statePtr[4] = ((statePtr[4]) + e);
	interpreterProxy->pop(2);
}


/*	Called with one LargePositiveInteger argument. Answer the index of the top-most non-zero digit. */

EXPORT(int) primitiveHighestNonZeroDigitIndex(void) {
    int i;
    unsigned char *bigIntPtr;
    int arg;

	arg = interpreterProxy->stackObjectValue(0);
	interpreterProxy->success((interpreterProxy->fetchClassOf(arg)) == (interpreterProxy->classLargePositiveInteger()));
	if (interpreterProxy->failed()) {
		return null;
	}
	bigIntPtr = interpreterProxy->firstIndexableField(arg);
	i = interpreterProxy->stSizeOf(arg);
	while ((i > 0) && ((bigIntPtr[i -= 1]) == 0)) {
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(i + 1);
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(int) setInterpreter(struct VirtualMachine* anInterpreter) {
    int ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


/*	Multiply the divisor by the given digit (an integer in the range 0..255), shift it left by the given number of digits, and subtract the result from the current remainder. Answer true if there is an excess borrow, indicating that digit was one too large. (This case is quite rare.) */

static int subtractDivisorMultipliedByDigitdigitShift(int digit, int digitShift) {
    int resultDigit;
    int borrow;
    int prod;
    int rIndex;
    int i;

	borrow = 0;
	rIndex = digitShift + 1;
	for (i = 1; i <= divisorDigitCount; i += 1) {
		prod = ((dsaDivisor[i]) * digit) + borrow;
		borrow = ((unsigned) prod >> 8);
		resultDigit = (dsaRemainder[rIndex]) - (prod & 255);
		if (resultDigit < 0) {
			resultDigit += 256;
			borrow += 1;
		}
		dsaRemainder[rIndex] = resultDigit;
		rIndex += 1;
	}
	if (borrow == 0) {
		return 0;
	}
	resultDigit = (dsaRemainder[rIndex]) - borrow;
	if (resultDigit < 0) {
		dsaRemainder[rIndex] = (resultDigit + 256);
		return 1;
	} else {
		dsaRemainder[rIndex] = resultDigit;
		return 0;
	}
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* DSAPrims_exports[][3] = {
	{"DSAPrims", "primitiveHashBlock", (void*)primitiveHashBlock},
	{"DSAPrims", "primitiveExpandBlock", (void*)primitiveExpandBlock},
	{"DSAPrims", "primitiveBigMultiply", (void*)primitiveBigMultiply},
	{"DSAPrims", "primitiveHasSecureHashPrimitive", (void*)primitiveHasSecureHashPrimitive},
	{"DSAPrims", "getModuleName", (void*)getModuleName},
	{"DSAPrims", "primitiveBigDivide", (void*)primitiveBigDivide},
	{"DSAPrims", "primitiveHighestNonZeroDigitIndex", (void*)primitiveHighestNonZeroDigitIndex},
	{"DSAPrims", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

