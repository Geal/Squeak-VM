/* Automatically generated from Squeak on 10 April 2010 7:46:57 pm 
   by VMMaker 4.0.3
 */

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
#include <ft2build.h>
#include <freetype/tttables.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H

#include "sqMemoryAccess.h"


/*** Constants ***/
#define FT2GlyphSlotFaceIndex 0
#define FT2GlyphSlotInstSize 17
#define FT2OutlineContoursIndex 4
#define FT2OutlineContoursSizeIndex 0
#define FT2OutlineFlagsIndex 5
#define FT2OutlineInstSize 6
#define FT2OutlinePointsIndex 2
#define FT2OutlinePointsSizeIndex 1
#define FT2OutlineTagsIndex 3
#define FormBitsIndex 0
#define FormDepthIndex 3
#define FormHeightIndex 2
#define FormInstSize 5
#define FormWidthIndex 1

/*** Function Prototypes ***/
static char * fetchByteArrayofObjectassureSize(sqInt fieldIndex, sqInt objectPointer, sqInt aSize);
static short* fetchShortArrayofObjectassureSize(sqInt fieldIndex, sqInt objectPointer, sqInt aSize);
static long * fetchWordArrayofObjectassureSize(sqInt fieldIndex, sqInt objectPointer, sqInt aSize);
static sqInt ftAllocateHandleInReceiverForPointer(void *aPointer);
static sqInt ftAllocateStringForPointer(const char *aPointer);
static FT_Encoding ftEncodingValueFromString(sqInt string);
static void * ftHandleValueFromReceiver(sqInt rcvrOop);
static int ftInitBitmapfromForm(FT_Bitmap* bitmap, sqInt formOop);
static int ftInitBitmapfromFormrenderMode(FT_Bitmap* bitmap, sqInt formOop, sqInt mode);
static int ftParameterError(void);
static sqInt ftStringFromEncodingValue(FT_Encoding encoding);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveCopyToExternalMemory(void);
EXPORT(sqInt) primitiveDoneFace(void);
EXPORT(sqInt) primitiveDoneFacePreserveFields(void);
EXPORT(sqInt) primitiveEmboldenFaceGlyphSlotOutline(void);
EXPORT(sqInt) primitiveErrorCode(void);
EXPORT(sqInt) primitiveErrorString(void);
EXPORT(sqInt) primitiveFreeExternalMemory(void);
EXPORT(sqInt) primitiveGetFaceCharIndex(void);
EXPORT(sqInt) primitiveGetFaceCharMap(void);
EXPORT(sqInt) primitiveGetFaceCharMapsIntoArray(void);
EXPORT(sqInt) primitiveGetFaceGlyphName(void);
EXPORT(sqInt) primitiveGetKerningLeftRight(void);
EXPORT(sqInt) primitiveGetPostscriptName(void);
EXPORT(sqInt) primitiveGetSfntTableOS2(void);
#pragma export off
static sqInt primitiveGetTrackKerningPointSizedegree(sqInt pointSize, sqInt degree);
#pragma export on
EXPORT(sqInt) primitiveHasKerning(void);
EXPORT(sqInt) primitiveLibraryHandle(void);
EXPORT(sqInt) primitiveLoadCharacter(void);
EXPORT(sqInt) primitiveLoadFaceBbox(void);
EXPORT(sqInt) primitiveLoadFaceFields(void);
EXPORT(sqInt) primitiveLoadGlyph(void);
EXPORT(sqInt) primitiveLoadGlyphSlotFromFace(void);
EXPORT(sqInt) primitiveLoadOutlineArraysFromFace(void);
EXPORT(sqInt) primitiveLoadOutlineSizesFromFace(void);
EXPORT(sqInt) primitiveModuleErrorCode(void);
EXPORT(sqInt) primitiveNewFaceFromFileAndIndex(void);
EXPORT(sqInt) primitiveNewMemoryFaceFromExternalMemoryAndIndex(void);
EXPORT(sqInt) primitiveNumberOfOutlineCountours(void);
EXPORT(sqInt) primitiveRenderGlyphIntoForm(void);
EXPORT(sqInt) primitiveRenderGlyphIntoFormWithRenderMode(void);
EXPORT(sqInt) primitiveResetErrorCode(void);
EXPORT(sqInt) primitiveSetFaceCharMap(void);
EXPORT(sqInt) primitiveSetPixelSizes(void);
EXPORT(sqInt) primitiveSetTransform(void);
EXPORT(sqInt) primitiveTransformFaceGlyphSlotOutline(void);
EXPORT(sqInt) primitiveTranslateFaceGlyphSlotOutline(void);
EXPORT(sqInt) primitiveVersion(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt sqAssert(sqInt aBool);
/*** Variables ***/
static int errorCode;

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static FT_Library library;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FT2Plugin 10 April 2010 (i)"
#else
	"FT2Plugin 10 April 2010 (e)"
#endif
;


static char * fetchByteArrayofObjectassureSize(sqInt fieldIndex, sqInt objectPointer, sqInt aSize) {
	sqInt array;

	array = interpreterProxy->fetchPointerofObject(fieldIndex, objectPointer);
	if ((interpreterProxy->isBytes(array)) && ((interpreterProxy->slotSizeOf(array)) == aSize)) {
		return interpreterProxy->arrayValueOf(array);
	}
	return null;
}

static short* fetchShortArrayofObjectassureSize(sqInt fieldIndex, sqInt objectPointer, sqInt aSize) {
	sqInt array;

	array = interpreterProxy->fetchPointerofObject(fieldIndex, objectPointer);
	if ((interpreterProxy->isWords(array)) && ((interpreterProxy->slotSizeOf(array)) == (((sqInt) (aSize + 1) >> 1)))) {
		return interpreterProxy->arrayValueOf(array);
	}
	return null;
}

static long * fetchWordArrayofObjectassureSize(sqInt fieldIndex, sqInt objectPointer, sqInt aSize) {
	sqInt array;

	array = interpreterProxy->fetchPointerofObject(fieldIndex, objectPointer);
	if ((interpreterProxy->isWords(array)) && ((interpreterProxy->slotSizeOf(array)) == aSize)) {
		return interpreterProxy->arrayValueOf(array);
	}
	return null;
}


/*	given aPointer (returned from a library call),
	set the receiver's (bottom of stack) first instance variable
	to a ByteArray containing the pointer's bytes */

static sqInt ftAllocateHandleInReceiverForPointer(void *aPointer) {
	void **extraByteArrayPtr;
	sqInt returnedHandle;

	if (aPointer) {

		/* Copy from the C bytecode buffer to the Smalltalk ByteArray */

		returnedHandle = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(void **));
		extraByteArrayPtr = interpreterProxy->arrayValueOf(returnedHandle);
		*extraByteArrayPtr = (void *)(aPointer);
	} else {
		returnedHandle = interpreterProxy->nilObject();
	}
	interpreterProxy->storePointerofObjectwithValue(0, interpreterProxy->stackObjectValue(interpreterProxy->methodArgumentCount()), returnedHandle);
	;
	return returnedHandle;
}


/*	given NUL-terminated char* aPointer (returned from a library call), 
	return the oop for a String containing the pointer's bytes */

static sqInt ftAllocateStringForPointer(const char *aPointer) {
	char *extraByteArrayPtr;
	sqInt returnedHandle;

	if (aPointer) {

		/* Copy from the C bytecode buffer to the Smalltalk ByteArray */

		returnedHandle = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), strlen(aPointer));
		extraByteArrayPtr = interpreterProxy->arrayValueOf(returnedHandle);
		;
		strncpy(extraByteArrayPtr, aPointer, strlen(aPointer));
	} else {
		returnedHandle = interpreterProxy->nilObject();
	}
	return returnedHandle;
}


/*	Return a 32-bit word from the bytes held by string. */

static FT_Encoding ftEncodingValueFromString(sqInt string) {
	unsigned char* ptr;
	unsigned long retval;

	interpreterProxy->success((!((string & 1))) && ((interpreterProxy->isBytes(string)) && ((interpreterProxy->slotSizeOf(string)) == (sizeof(FT_Encoding)))));
	if (interpreterProxy->failed()) {
		return null;
	}
	retval = 0;

	/* 	ptr := self cCode: '(unsigned char *) (string + 4)'. */

	ptr = interpreterProxy->arrayValueOf(string);
	;
	retval = ((unsigned long)ptr[0]) << 24;
	retval += ((unsigned long)ptr[1]) << 16;
	retval += ((unsigned long)ptr[2]) << 8;
	retval += (unsigned long)ptr[3];
	;
	return (FT_Encoding)retval;
}


/*	this is the opposite of #ftAllocateHandleIn:forPointer: .
	It takes rcvr's first instance variable,
	which should be a ByteArray the size of a void*,
	and returns its value as a C pointer. */

static void * ftHandleValueFromReceiver(sqInt rcvrOop) {
	sqInt oop;
	sqInt btw;

	oop = interpreterProxy->fetchPointerofObject(0, rcvrOop);
	interpreterProxy->success((interpreterProxy->isBytes(oop)) && ((interpreterProxy->slotSizeOf(oop)) == (sizeof(void *))));
	if (interpreterProxy->failed()) {
		return null;
	}
	btw =  4;
	return *(void**)(pointerForOop(oop + btw));
}


/*	Initialize the values in an FT_Bitmap from the given Form */

static int ftInitBitmapfromForm(FT_Bitmap* bitmap, sqInt formOop) {
	sqInt width;
	sqInt numGrays;
	sqInt wordsPerRow;
	sqInt pitch;
	sqInt pixelMode;
	unsigned char* buffer;
	sqInt height;
	sqInt depth;

	interpreterProxy->success(interpreterProxy->isPointers(formOop));
	interpreterProxy->success((interpreterProxy->slotSizeOf(formOop)) >= FormInstSize);
	if (interpreterProxy->failed()) {
		return null;
	}
	width = interpreterProxy->fetchIntegerofObject(FormWidthIndex, formOop);
	height = interpreterProxy->fetchIntegerofObject(FormHeightIndex, formOop);
	depth = interpreterProxy->fetchIntegerofObject(FormDepthIndex, formOop);
	buffer = ((void*) (interpreterProxy->fetchArrayofObject(FormBitsIndex, formOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (depth < 0) {
		depth = depth * -1;
	}
	if (depth == 1) {
		wordsPerRow = ((sqInt) (width + 31) >> 5);
		numGrays = 1;
		pixelMode = FT_PIXEL_MODE_MONO;
	} else {
		if (depth == 8) {
			wordsPerRow = ((sqInt) (width + 3) >> 2);
			numGrays = 256;
			pixelMode = FT_PIXEL_MODE_GRAY;
		} else {
			return interpreterProxy->primitiveFail();
		}
	}
	
#ifndef WORDS_BIGENDIAN
	depth = depth * -1;
#endif
;
	interpreterProxy->storeIntegerofObjectwithValue(FormDepthIndex, formOop, depth);
	pitch = wordsPerRow * 4;
	bitmap->rows = height;
	bitmap->width = width;
	bitmap->pitch = pitch;
	bitmap->buffer = buffer;
	bitmap->num_grays = numGrays;
	bitmap->pixel_mode = pixelMode;
	return 1;
}


/*	Initialize the values in an FT_Bitmap from the given Form */
/*	pixelMode */

static int ftInitBitmapfromFormrenderMode(FT_Bitmap* bitmap, sqInt formOop, sqInt mode) {
	sqInt depth;
	sqInt numGrays;
	sqInt wordsPerRow;
	sqInt pitch;
	unsigned char* buffer;
	sqInt height;
	sqInt width;

	interpreterProxy->success(interpreterProxy->isPointers(formOop));
	interpreterProxy->success((interpreterProxy->slotSizeOf(formOop)) >= FormInstSize);
	if (interpreterProxy->failed()) {
		return null;
	}
	width = interpreterProxy->fetchIntegerofObject(FormWidthIndex, formOop);
	height = interpreterProxy->fetchIntegerofObject(FormHeightIndex, formOop);
	depth = interpreterProxy->fetchIntegerofObject(FormDepthIndex, formOop);
	buffer = ((void*) (interpreterProxy->fetchArrayofObject(FormBitsIndex, formOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (depth < 0) {
		depth = depth * -1;
	}
	if (depth == 1) {
		wordsPerRow = ((sqInt) (width + 31) >> 5);
		numGrays = 1;
	} else {
		if (depth == 8) {
			wordsPerRow = ((sqInt) (width + 3) >> 2);
			numGrays = 256;
		} else {
			return interpreterProxy->primitiveFail();
		}
	}
	
#ifndef WORDS_BIGENDIAN
	depth = depth * -1;
#endif
;
	interpreterProxy->storeIntegerofObjectwithValue(FormDepthIndex, formOop, depth);
	pitch = wordsPerRow * 4;
	bitmap->rows = height;
	bitmap->width = width;
	bitmap->pitch = pitch;
	bitmap->buffer = buffer;
	bitmap->num_grays = numGrays;
	bitmap->pixel_mode = mode;
	return 1;
}

static int ftParameterError(void) {
	errorCode = 255;
	return interpreterProxy->primitiveFail();
}


/*	Return a newly allocated String from the given 32-bit word */

static sqInt ftStringFromEncodingValue(FT_Encoding encoding) {
	unsigned char* ptr;
	sqInt stringOop;

	stringOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), sizeof(FT_Encoding));
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	ptr = interpreterProxy->firstIndexableField(stringOop);
	;
	ptr[0] = (encoding & 0xFF000000) >> 24;
	ptr[1] = (encoding & 0x00FF0000) >> 16;
	ptr[2] = (encoding & 0x0000FF00) >> 8;
	ptr[3] = (encoding & 0x000000FF);
	return stringOop;
}


/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine * getInterpreter(void) {
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
}

EXPORT(sqInt) initialiseModule(void) {
	library = null;
	
#ifdef macintoshSqueak
	fetchPreferences();
#endif
;
	errorCode = FT_Init_FreeType(&library);
	return errorCode == 0;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveCopyToExternalMemory(void) {
	sqInt rcvr;
	void *aPointer;
	size_t byteSize;
	char *aByteArray;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aByteArray = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FreeTypeExternalMemory"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	;
	errorCode = 0;
	byteSize = interpreterProxy->byteSizeOf((oopForPointer( aByteArray ) - 4));
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	aPointer = malloc(byteSize);
	memcpy(aPointer,aByteArray,byteSize);
	ftAllocateHandleInReceiverForPointer(aPointer);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Call the library to release the given face record.
	Nil out the pointer fields */

EXPORT(sqInt) primitiveDoneFace(void) {
	sqInt i;
	sqInt rcvr;
	FT_Face face;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;

	/* nil out all the fields */

	errorCode = FT_Done_Face(face);
	for (i = 0; i <= 23; i += 1) {
		interpreterProxy->storePointerofObjectwithValue(i, rcvr, interpreterProxy->nilObject());
	}
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}


/*	Call the library to release the given face record.
	Nil out the handle field, but do not nil the other fields,
	as their values are needed even if the face cannot be re-opened
	in the future due to a missing font file etc. */

EXPORT(sqInt) primitiveDoneFacePreserveFields(void) {
	sqInt rcvr;
	FT_Face face;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;

	/* nil the handle field */

	errorCode = FT_Done_Face(face);
	interpreterProxy->storePointerofObjectwithValue(0, rcvr, interpreterProxy->nilObject());
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}


/*	emboldens the outline in the face's glyphSlot by strength (expressed in 26.6 pixel format).
	The new outline will be at most 4 times `strength' pixels wider and higher.  */

EXPORT(sqInt) primitiveEmboldenFaceGlyphSlotOutline(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt strength;

	strength = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	errorCode = FT_Outline_Embolden( &face->glyph->outline, strength );
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	high byte is module error, low is generic error */

EXPORT(sqInt) primitiveErrorCode(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->positive32BitIntegerFor((FT_ERROR_BASE(errorCode)));
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveErrorString(void) {
	const struct ftError * ftError;
	const char * str;

	
struct ftError { int errCode; const char* errMsg; };
#undef __FTERRORS_H__
#define FT_ERRORDEF( e, v, s )  { e, s },
#define FT_ERROR_START_LIST     {
#define FT_ERROR_END_LIST       { 0xFF, "Bad Squeak Method Parameter" }, { 0, NULL } };
static const struct ftError ftErrors[] =
#include FT_ERRORS_H
;
	ftError = ftErrors;
	;
	while ((str = ftError->errMsg) && (FT_ERROR_BASE(errorCode) != ftError->errCode)) {
		ftError++;
	}
	;
	if (!(str)) {
		interpreterProxy->success(0);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ftAllocateStringForPointer(str));
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveFreeExternalMemory(void) {
	sqInt rcvr;
	void* memPointer;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FreeTypeExternalMemory"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	;

	/* free the memory handle */

	errorCode = 0;
	memPointer = ftHandleValueFromReceiver(rcvr);
	if (!(memPointer == null)) {
		free(memPointer);
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}


/*	Return the Freetype glyph index of the given character code, in the 
	current encoding. 
	Return value of 0 means 'undefined character code'. */

EXPORT(sqInt) primitiveGetFaceCharIndex(void) {
	sqInt rcvr;
	FT_Face face;
	sqInt result;
	sqInt charIndex;
	sqInt _return_value;

	charIndex = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	result = FT_Get_Char_Index(face, charIndex);
	_return_value = interpreterProxy->positive32BitIntegerFor(result);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetFaceCharMap(void) {
	sqInt stringOop;
	FT_Face face;
	sqInt rcvr;
	FT_CharMap charmap;
	FT_Encoding encoding;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	charmap = face->charmap;
	if (!(charmap)) {
		return null;
	}
	interpreterProxy->pushRemappableOop(rcvr);
	encoding = charmap->encoding;
	stringOop = ftStringFromEncodingValue(encoding);
	rcvr = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(22, rcvr, stringOop);
	interpreterProxy->storeIntegerofObjectwithValue(23, rcvr, charmap->platform_id);
	interpreterProxy->storeIntegerofObjectwithValue(24, rcvr, charmap->encoding_id);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveGetFaceCharMapsIntoArray(void) {
	sqInt stringOop;
	sqInt arrayOop;
	FT_Face face;
	sqInt rcvr;
	sqInt i;
	FT_CharMap * charmap;
	int numCharmaps;
	sqInt *array;

	interpreterProxy->success(interpreterProxy->isIndexable(interpreterProxy->stackValue(0)));
	array = ((int *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	numCharmaps = face->num_charmaps;
	arrayOop = oopForPointer(array) - 4;
	interpreterProxy->success((interpreterProxy->slotSizeOf(arrayOop)) == numCharmaps);
	if (interpreterProxy->failed()) {
		return null;
	}
	charmap = face->charmaps;
	;
	for (i = 0; i <= (numCharmaps - 1); i += 1) {
		interpreterProxy->pushRemappableOop(arrayOop);
		stringOop = ftStringFromEncodingValue((*charmap)->encoding);
		arrayOop = interpreterProxy->popRemappableOop();
		interpreterProxy->storePointerofObjectwithValue(i, arrayOop, stringOop);
		charmap++;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	return a String */

EXPORT(sqInt) primitiveGetFaceGlyphName(void) {
	sqInt string;
	FT_Face face;
	sqInt rcvr;
	char buffer[100];
	sqInt glyphIndex;

	glyphIndex = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	errorCode = FT_Get_Glyph_Name(face, glyphIndex, buffer, 100);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	string = ftAllocateStringForPointer(buffer);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(2, string);
	return null;
}

EXPORT(sqInt) primitiveGetKerningLeftRight(void) {
	sqInt pointOop;
	FT_Vector result;
	sqInt rcvr;
	FT_Face face;
	sqInt kernMode;
	sqInt leftGlyph;
	sqInt rightGlyph;

	leftGlyph = interpreterProxy->stackIntegerValue(1);
	rightGlyph = interpreterProxy->stackIntegerValue(0);
	
		result.x=3;
		result.y=4;;
	;
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	rcvr = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	kernMode = FT_KERNING_UNSCALED;
	;
	FT_Get_Kerning(face, leftGlyph, rightGlyph, kernMode, &result);;
	pointOop = interpreterProxy->makePointwithxValueyValue(result.x, result.y);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(3, pointOop);
	return null;
}


/*	return a String */

EXPORT(sqInt) primitiveGetPostscriptName(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt string;
	char* buffer;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	buffer = 0;
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	buffer = FT_Get_Postscript_Name(face);
	interpreterProxy->success(buffer != 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	string = ftAllocateStringForPointer(buffer);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, string);
	return null;
}


/*	return the bytes from the OS/2 table */

EXPORT(sqInt) primitiveGetSfntTableOS2(void) {
	char *extraByteArrayPtr;
	FT_Face face;
	sqInt rcvr;
	sqInt returnedHandle;
	char *buffer;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	buffer = 0;
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	buffer = FT_Get_Sfnt_Table(face,ft_sfnt_os2);
	if (buffer == 0) {
		_return_value = interpreterProxy->integerObjectOf(-1);
		if (interpreterProxy->failed()) {
			ftParameterError();
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}

	/* Copy from the C bytecode buffer to the Smalltalk ByteArray */

	returnedHandle = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(TT_OS2));
	extraByteArrayPtr = interpreterProxy->arrayValueOf(returnedHandle);
	;
	memcpy(extraByteArrayPtr, buffer, sizeof(TT_OS2));
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, returnedHandle);
	return null;
}


/*	disabled becaus of yet implemented */

static sqInt primitiveGetTrackKerningPointSizedegree(sqInt pointSize, sqInt degree) {
	return interpreterProxy->primitiveFail();
}

EXPORT(sqInt) primitiveHasKerning(void) {
	sqInt rcvr;
	FT_Face face;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	_return_value = (((FT_HAS_KERNING( face )) << 1) | 1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Fill in the handle in an FT2Library structure with a copy of our global pointer. */

EXPORT(sqInt) primitiveLibraryHandle(void) {
	sqInt rcvr;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Library"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	ftAllocateHandleInReceiverForPointer(library);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}


/*	Load the glyph at the given index in the current charmap.
	The default map upon opening a font is the 'unic' or Unicode charmap, if any. */

EXPORT(sqInt) primitiveLoadCharacter(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt index;
	sqInt flags;

	index = interpreterProxy->stackIntegerValue(1);
	flags = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	rcvr = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	errorCode = FT_Load_Char(face, index, flags);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveLoadFaceBbox(void) {
	sqInt pointOop;
	sqInt rectOop;
	FT_Face face;
	sqInt rcvr;
	sqInt aRectangle;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "Rectangle"));
	aRectangle = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	rectOop = aRectangle;
	if (!(interpreterProxy->isPointers(rectOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(rectOop)) < 2) {
		interpreterProxy->primitiveFail();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;
	if (!(face->face_flags & FT_FACE_FLAG_SCALABLE)) {
		interpreterProxy->success(0);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pushRemappableOop(rectOop);
	pointOop = interpreterProxy->makePointwithxValueyValue(face->bbox.xMin, face->bbox.yMin);
	rectOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, rectOop, pointOop);
	interpreterProxy->pushRemappableOop(rectOop);
	pointOop = interpreterProxy->makePointwithxValueyValue(face->bbox.xMax, face->bbox.yMax);
	rectOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(1, rectOop, pointOop);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Fill in many of the receiver's (an FT2Face) fields (other than its handle)
	from the FT_Face record that it points to. */

EXPORT(sqInt) primitiveLoadFaceFields(void) {
	sqInt rcvr;
	FT_Face face;
	sqInt strOop;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;
	interpreterProxy->storeIntegerofObjectwithValue(1, rcvr, face->num_faces);
	interpreterProxy->storeIntegerofObjectwithValue(2, rcvr, face->face_index);
	interpreterProxy->storeIntegerofObjectwithValue(3, rcvr, face->face_flags);
	interpreterProxy->storeIntegerofObjectwithValue(4, rcvr, face->style_flags);
	interpreterProxy->storeIntegerofObjectwithValue(5, rcvr, face->num_glyphs);
	interpreterProxy->pushRemappableOop(rcvr);
	strOop = ftAllocateStringForPointer(face->family_name);
	rcvr = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(6, rcvr, strOop);
	interpreterProxy->pushRemappableOop(rcvr);
	strOop = ftAllocateStringForPointer(face->style_name);
	rcvr = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(7, rcvr, strOop);
	interpreterProxy->storeIntegerofObjectwithValue(8, rcvr, face->num_fixed_sizes);
	interpreterProxy->storeIntegerofObjectwithValue(10, rcvr, face->num_charmaps);
	if (face->face_flags & FT_FACE_FLAG_SCALABLE) {
		interpreterProxy->storeIntegerofObjectwithValue(13, rcvr, face->units_per_EM);
		interpreterProxy->storeIntegerofObjectwithValue(14, rcvr, face->ascender);
		interpreterProxy->storeIntegerofObjectwithValue(15, rcvr, face->descender);
		interpreterProxy->storeIntegerofObjectwithValue(16, rcvr, face->height);
		interpreterProxy->storeIntegerofObjectwithValue(17, rcvr, face->max_advance_width);
		interpreterProxy->storeIntegerofObjectwithValue(18, rcvr, face->max_advance_height);
		interpreterProxy->storeIntegerofObjectwithValue(19, rcvr, face->underline_position);
		interpreterProxy->storeIntegerofObjectwithValue(20, rcvr, face->underline_thickness);
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveLoadGlyph(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt index;
	sqInt flags;

	index = interpreterProxy->stackIntegerValue(1);
	flags = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	rcvr = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	errorCode = FT_Load_Glyph(face, index, flags);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Assumes that primitiveLoadGlyph:flags: has been called earlier to set face->glyph. */

EXPORT(sqInt) primitiveLoadGlyphSlotFromFace(void) {
	FT_Glyph_Format *gfPtr;
	FT_Face face;
	sqInt rcvr;
	sqInt gfOop;
	FT_GlyphSlot gs;
	sqInt btw;
	sqInt aFace;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	aFace = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2GlyphSlot"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	if ((interpreterProxy->slotSizeOf(rcvr)) < 8) {
		interpreterProxy->primitiveFail();
		return null;
	}
	face = ftHandleValueFromReceiver(aFace);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	gs = face->glyph;
	if (!(gs)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;
	interpreterProxy->storePointerofObjectwithValue(0, rcvr, aFace);
	interpreterProxy->storeIntegerofObjectwithValue(1, rcvr, gs->linearHoriAdvance);
	interpreterProxy->storeIntegerofObjectwithValue(2, rcvr, gs->linearVertAdvance);
	interpreterProxy->storeIntegerofObjectwithValue(3, rcvr, gs->advance.x);
	interpreterProxy->storeIntegerofObjectwithValue(4, rcvr, gs->advance.y);
	interpreterProxy->pushRemappableOop(rcvr);
	gfOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(FT_Glyph_Format));
	;
	btw =  4;
	gfPtr = (FT_Glyph_Format *) pointerForOop(gfOop + btw);
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	*gfPtr = gs->format;
	rcvr = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(5, rcvr, gfOop);
	interpreterProxy->storeIntegerofObjectwithValue(6, rcvr, gs->bitmap_left);
	interpreterProxy->storeIntegerofObjectwithValue(7, rcvr, gs->bitmap_top);
	interpreterProxy->storeIntegerofObjectwithValue(8, rcvr, gs->metrics.width);
	interpreterProxy->storeIntegerofObjectwithValue(9, rcvr, gs->metrics.height);
	interpreterProxy->storeIntegerofObjectwithValue(10, rcvr, gs->metrics.horiBearingX);
	interpreterProxy->storeIntegerofObjectwithValue(11, rcvr, gs->metrics.horiBearingY);
	interpreterProxy->storeIntegerofObjectwithValue(12, rcvr, gs->metrics.horiAdvance);
	interpreterProxy->storeIntegerofObjectwithValue(13, rcvr, gs->metrics.vertBearingX);
	interpreterProxy->storeIntegerofObjectwithValue(14, rcvr, gs->metrics.vertBearingY);
	interpreterProxy->storeIntegerofObjectwithValue(15, rcvr, gs->metrics.vertAdvance);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Assumes that primitiveLoadGlyph:flags: has been called earlier to set face->glyph. */

EXPORT(sqInt) primitiveLoadOutlineArraysFromFace(void) {
	char * tags;
	short* contours;
	sqInt pointsSize;
	sqInt i;
	FT_Face face;
	sqInt rcvr;
	long * points;
	sqInt contoursSize;
	FT_GlyphSlot gs;
	sqInt aFace;
	sqInt array;
	sqInt array1;
	sqInt array2;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	aFace = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Outline"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	if ((interpreterProxy->slotSizeOf(rcvr)) < FT2OutlineInstSize) {
		interpreterProxy->primitiveFail();
		return null;
	}
	face = ftHandleValueFromReceiver(aFace);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	gs = face->glyph;
	if (!(gs)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;
	pointsSize = gs->outline.n_points;
	/* begin fetchWordArray:ofObject:assureSize: */
	array1 = interpreterProxy->fetchPointerofObject(FT2OutlinePointsIndex, rcvr);
	if ((interpreterProxy->isWords(array1)) && ((interpreterProxy->slotSizeOf(array1)) == (pointsSize * 2))) {
		points = interpreterProxy->arrayValueOf(array1);
		goto l2;
	}
	points = null;
l2:	/* end fetchWordArray:ofObject:assureSize: */;
	if (points == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	/* begin fetchByteArray:ofObject:assureSize: */
	array2 = interpreterProxy->fetchPointerofObject(FT2OutlineTagsIndex, rcvr);
	if ((interpreterProxy->isBytes(array2)) && ((interpreterProxy->slotSizeOf(array2)) == pointsSize)) {
		tags = interpreterProxy->arrayValueOf(array2);
		goto l3;
	}
	tags = null;
l3:	/* end fetchByteArray:ofObject:assureSize: */;
	if (tags == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	for (i = 0; i <= (pointsSize - 1); i += 1) {
		points[2 * i] = (gs->outline.points[i].x);
		points[(2 * i) + 1] = (gs->outline.points[i].y);
		tags[i] = (gs->outline.tags[i]);
	}
	contoursSize = gs->outline.n_contours;
	/* begin fetchShortArray:ofObject:assureSize: */
	array = interpreterProxy->fetchPointerofObject(FT2OutlineContoursIndex, rcvr);
	if ((interpreterProxy->isWords(array)) && ((interpreterProxy->slotSizeOf(array)) == (((sqInt) (contoursSize + 1) >> 1)))) {
		contours = interpreterProxy->arrayValueOf(array);
		goto l1;
	}
	contours = null;
l1:	/* end fetchShortArray:ofObject:assureSize: */;
	for (i = 0; i <= (contoursSize - 1); i += 1) {
		contours[i] = (gs->outline.contours[i]);
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Assumes that primitiveLoadGlyph:flags: has been called earlier to set face->glyph. */

EXPORT(sqInt) primitiveLoadOutlineSizesFromFace(void) {
	sqInt rcvr;
	FT_Face face;
	FT_GlyphSlot gs;
	sqInt aFace;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Face"));
	aFace = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Outline"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	if ((interpreterProxy->slotSizeOf(rcvr)) < FT2OutlineInstSize) {
		interpreterProxy->primitiveFail();
		return null;
	}
	face = ftHandleValueFromReceiver(aFace);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	gs = face->glyph;
	if (!(gs)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;
	interpreterProxy->storeIntegerofObjectwithValue(FT2OutlineContoursSizeIndex, rcvr, gs->outline.n_contours);
	interpreterProxy->storeIntegerofObjectwithValue(FT2OutlinePointsSizeIndex, rcvr, gs->outline.n_points);
	interpreterProxy->storeIntegerofObjectwithValue(FT2OutlineFlagsIndex, rcvr, gs->outline.flags);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	high byte is module error, low is generic error */

EXPORT(sqInt) primitiveModuleErrorCode(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->positive32BitIntegerFor((FT_ERROR_MODULE(errorCode)));
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Fill in the receiver's (a FT2Face object) fields
	from the address and fields of a newly opened FT_Face object. */

EXPORT(sqInt) primitiveNewFaceFromFileAndIndex(void) {
	char translatedFilePath[1024];
	size_t byteSize;
	FT_Face face;
	sqInt rcvr;
	char *fontFilePath;
	sqInt anInteger;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	fontFilePath = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	anInteger = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	rcvr = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	;
	errorCode = 0;
	byteSize = interpreterProxy->byteSizeOf((oopForPointer( fontFilePath ) - 4));
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	if (byteSize > 1000) {
		interpreterProxy->success(0);
		return null;
	}
	interpreterProxy->ioFilenamefromStringofLengthresolveAliases(translatedFilePath, fontFilePath, byteSize, 1);
	errorCode = FT_New_Face(library, translatedFilePath, anInteger, &face);
	;
	;
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	ftAllocateHandleInReceiverForPointer(face);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Fill in the receiver's (a FT2Face object) fields
	from the address and fields of a newly opened FT_Face object. */

EXPORT(sqInt) primitiveNewMemoryFaceFromExternalMemoryAndIndex(void) {
	FT_Face face;
	sqInt rcvr;
	void *memPointer;
	sqInt aFreeTypeExternalMemory;
	sqInt byteSize;
	sqInt anInteger;

	aFreeTypeExternalMemory = interpreterProxy->stackValue(2);
	byteSize = interpreterProxy->stackIntegerValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(3), "FT2Face"));
	rcvr = interpreterProxy->stackValue(3);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	;
	errorCode = 0;
	memPointer = ftHandleValueFromReceiver(aFreeTypeExternalMemory);
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	errorCode = FT_New_Memory_Face(library, memPointer, byteSize, anInteger, &face);
	;
	;
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	ftAllocateHandleInReceiverForPointer(face);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	Assumes that primitiveLoadGlyph:flags: has been called earlier to set face->glyph. */

EXPORT(sqInt) primitiveNumberOfOutlineCountours(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt aFace;
	sqInt contoursSize;
	FT_GlyphSlot gs;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2GlyphSlot"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	if ((interpreterProxy->slotSizeOf(rcvr)) < FT2GlyphSlotInstSize) {
		interpreterProxy->primitiveFail();
		return null;
	}
	aFace = interpreterProxy->fetchPointerofObject(FT2GlyphSlotFaceIndex, rcvr);
	face = ftHandleValueFromReceiver(aFace);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	gs = face->glyph;
	if (!(gs)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	;
	contoursSize = gs->outline.n_contours;
	_return_value = ((contoursSize << 1) | 1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Render this face into the given form */

EXPORT(sqInt) primitiveRenderGlyphIntoForm(void) {
	FT_Face face;
	FT_Bitmap bitmap;
	sqInt faceOop;
	sqInt formOop;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "Form"));
	formOop = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	faceOop = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(faceOop);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	ftInitBitmapfromForm(&bitmap, formOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	errorCode = FT_Outline_Get_Bitmap(library, &face->glyph->outline, &bitmap);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Render this face into the given form */

EXPORT(sqInt) primitiveRenderGlyphIntoFormWithRenderMode(void) {
	FT_Bitmap bitmap;
	FT_Face face;
	sqInt faceOop;
	sqInt formOop;
	sqInt mode;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "Form"));
	formOop = interpreterProxy->stackValue(1);
	mode = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	faceOop = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(faceOop);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	ftInitBitmapfromFormrenderMode(&bitmap, formOop, mode);
	if (interpreterProxy->failed()) {
		return null;
	}
	errorCode = FT_Outline_Get_Bitmap(library, &face->glyph->outline, &bitmap);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveResetErrorCode(void) {
	sqInt oldError;
	sqInt _return_value;

	oldError = errorCode;
	errorCode = 0;
	_return_value = interpreterProxy->positive32BitIntegerFor(oldError);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSetFaceCharMap(void) {
	FT_Face face;
	sqInt rcvr;
	FT_Encoding encoding;
	sqInt encodingString;

	encodingString = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	encoding = ftEncodingValueFromString(encodingString);
	if (interpreterProxy->failed()) {
		return null;
	}
	;
	errorCode = FT_Select_Charmap(face, encoding);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSetPixelSizes(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt x;
	sqInt y;

	x = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	rcvr = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	errorCode = FT_Set_Pixel_Sizes(face, x, y);
	interpreterProxy->success(errorCode == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveSetTransform(void) {
	sqInt *deltasqIntPtr;
	FT_Face face;
	sqInt rcvr;
	FT_Vector delta;
	sqInt *matrixsqIntPtr;
	FT_Matrix matrix;
	sqInt matrixWordArray;
	sqInt deltaWordArray;

	matrixWordArray = interpreterProxy->stackValue(1);
	deltaWordArray = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "FT2Face"));
	rcvr = interpreterProxy->stackValue(2);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	matrixsqIntPtr = interpreterProxy->arrayValueOf(matrixWordArray);
	deltasqIntPtr = interpreterProxy->arrayValueOf(deltaWordArray);
	delta.x = deltasqIntPtr[0]; delta.y = deltasqIntPtr[1];;
	matrix.xx = matrixsqIntPtr[0]; matrix.xy = matrixsqIntPtr[1]; 
		matrix.yx = matrixsqIntPtr[2]; matrix.yy = matrixsqIntPtr[3]; ;
	if (!(interpreterProxy->failed())) {
		FT_Set_Transform( face, &matrix, &delta);
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveTransformFaceGlyphSlotOutline(void) {
	FT_Face face;
	sqInt rcvr;
	sqInt *matrixsqIntPtr;
	FT_Matrix matrix;
	sqInt matrixWordArray;

	matrixWordArray = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	matrixsqIntPtr = interpreterProxy->arrayValueOf(matrixWordArray);
	matrix.xx = matrixsqIntPtr[0]; matrix.xy = matrixsqIntPtr[1]; 
		matrix.yx = matrixsqIntPtr[2]; matrix.yy = matrixsqIntPtr[3]; ;
	if (!(interpreterProxy->failed())) {
		FT_Outline_Transform( &face->glyph->outline, &matrix );
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveTranslateFaceGlyphSlotOutline(void) {
	sqInt *deltasqIntPtr;
	FT_Face face;
	sqInt rcvr;
	FT_Vector delta;
	sqInt deltaWordArray;

	deltaWordArray = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(1), "FT2Face"));
	rcvr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	face = ftHandleValueFromReceiver(rcvr);
	if (face == null) {
		interpreterProxy->primitiveFail();
		return null;
	}
	deltasqIntPtr = interpreterProxy->arrayValueOf(deltaWordArray);
	delta.x = deltasqIntPtr[0]; delta.y = deltasqIntPtr[1];;
	if (!(interpreterProxy->failed())) {
		FT_Outline_Translate( &face->glyph->outline, delta.x, delta.y );
	}
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveVersion(void) {
	sqInt rcvr;
	int amajor;
	int apatch;
	int aminor;

	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(0), "FT2Version"));
	rcvr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	errorCode = 0;
	FT_Library_Version(library, &amajor, &aminor, &apatch);
	;
	interpreterProxy->storeIntegerofObjectwithValue(0, rcvr, amajor);
	;
	interpreterProxy->storeIntegerofObjectwithValue(1, rcvr, aminor);
	;
	interpreterProxy->storeIntegerofObjectwithValue(2, rcvr, apatch);
	if (interpreterProxy->failed()) {
		ftParameterError();
		return null;
	}
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter) {
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

EXPORT(sqInt) shutdownModule(void) {
	errorCode = FT_Done_FreeType(library);
	if (errorCode == 0) {
		library = null;
	}
	return errorCode == 0;
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* FT2Plugin_exports[][3] = {
	{"FT2Plugin", "primitiveFreeExternalMemory", (void*)primitiveFreeExternalMemory},
	{"FT2Plugin", "shutdownModule", (void*)shutdownModule},
	{"FT2Plugin", "setInterpreter", (void*)setInterpreter},
	{"FT2Plugin", "primitiveModuleErrorCode", (void*)primitiveModuleErrorCode},
	{"FT2Plugin", "primitiveRenderGlyphIntoForm", (void*)primitiveRenderGlyphIntoForm},
	{"FT2Plugin", "primitiveTransformFaceGlyphSlotOutline", (void*)primitiveTransformFaceGlyphSlotOutline},
	{"FT2Plugin", "primitiveGetPostscriptName", (void*)primitiveGetPostscriptName},
	{"FT2Plugin", "primitiveRenderGlyphIntoFormWithRenderMode", (void*)primitiveRenderGlyphIntoFormWithRenderMode},
	{"FT2Plugin", "primitiveLibraryHandle", (void*)primitiveLibraryHandle},
	{"FT2Plugin", "initialiseModule", (void*)initialiseModule},
	{"FT2Plugin", "primitiveTranslateFaceGlyphSlotOutline", (void*)primitiveTranslateFaceGlyphSlotOutline},
	{"FT2Plugin", "primitiveSetTransform", (void*)primitiveSetTransform},
	{"FT2Plugin", "primitiveLoadFaceBbox", (void*)primitiveLoadFaceBbox},
	{"FT2Plugin", "primitiveNewFaceFromFileAndIndex", (void*)primitiveNewFaceFromFileAndIndex},
	{"FT2Plugin", "primitiveLoadFaceFields", (void*)primitiveLoadFaceFields},
	{"FT2Plugin", "primitiveGetSfntTableOS2", (void*)primitiveGetSfntTableOS2},
	{"FT2Plugin", "primitiveDoneFacePreserveFields", (void*)primitiveDoneFacePreserveFields},
	{"FT2Plugin", "primitiveErrorString", (void*)primitiveErrorString},
	{"FT2Plugin", "primitiveNumberOfOutlineCountours", (void*)primitiveNumberOfOutlineCountours},
	{"FT2Plugin", "primitiveSetFaceCharMap", (void*)primitiveSetFaceCharMap},
	{"FT2Plugin", "primitiveResetErrorCode", (void*)primitiveResetErrorCode},
	{"FT2Plugin", "primitiveSetPixelSizes", (void*)primitiveSetPixelSizes},
	{"FT2Plugin", "primitiveVersion", (void*)primitiveVersion},
	{"FT2Plugin", "primitiveGetFaceGlyphName", (void*)primitiveGetFaceGlyphName},
	{"FT2Plugin", "primitiveGetKerningLeftRight", (void*)primitiveGetKerningLeftRight},
	{"FT2Plugin", "getModuleName", (void*)getModuleName},
	{"FT2Plugin", "primitiveLoadOutlineSizesFromFace", (void*)primitiveLoadOutlineSizesFromFace},
	{"FT2Plugin", "primitiveLoadGlyph", (void*)primitiveLoadGlyph},
	{"FT2Plugin", "primitiveEmboldenFaceGlyphSlotOutline", (void*)primitiveEmboldenFaceGlyphSlotOutline},
	{"FT2Plugin", "primitiveGetFaceCharMap", (void*)primitiveGetFaceCharMap},
	{"FT2Plugin", "primitiveDoneFace", (void*)primitiveDoneFace},
	{"FT2Plugin", "primitiveErrorCode", (void*)primitiveErrorCode},
	{"FT2Plugin", "primitiveHasKerning", (void*)primitiveHasKerning},
	{"FT2Plugin", "primitiveGetFaceCharMapsIntoArray", (void*)primitiveGetFaceCharMapsIntoArray},
	{"FT2Plugin", "primitiveLoadCharacter", (void*)primitiveLoadCharacter},
	{"FT2Plugin", "primitiveCopyToExternalMemory", (void*)primitiveCopyToExternalMemory},
	{"FT2Plugin", "primitiveNewMemoryFaceFromExternalMemoryAndIndex", (void*)primitiveNewMemoryFaceFromExternalMemoryAndIndex},
	{"FT2Plugin", "primitiveLoadOutlineArraysFromFace", (void*)primitiveLoadOutlineArraysFromFace},
	{"FT2Plugin", "primitiveLoadGlyphSlotFromFace", (void*)primitiveLoadGlyphSlotFromFace},
	{"FT2Plugin", "primitiveGetFaceCharIndex", (void*)primitiveGetFaceCharIndex},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

