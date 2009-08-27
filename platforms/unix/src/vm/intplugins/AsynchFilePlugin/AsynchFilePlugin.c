/* Automatically generated from Squeak on an Array(26 August 2009 10:00:23 pm)
by VMMaker 3.11.3
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
#include "AsynchFilePlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static AsyncFile * asyncFileValueOf(sqInt oop);
static char * bufferPointerstartIndex(sqInt buffer, sqInt startIndex);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) moduleUnloaded(char * aModuleName);
#pragma export off
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveAsyncFileClose(void);
EXPORT(sqInt) primitiveAsyncFileOpen(void);
EXPORT(sqInt) primitiveAsyncFileReadResult(void);
EXPORT(sqInt) primitiveAsyncFileReadStart(void);
EXPORT(sqInt) primitiveAsyncFileWriteResult(void);
EXPORT(sqInt) primitiveAsyncFileWriteStart(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt sqAssert(sqInt aBool);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"AsynchFilePlugin 26 August 2009 (i)"
#else
	"AsynchFilePlugin 26 August 2009 (e)"
#endif
;
static void * sCOAFfn;



/*	Return a pointer to the first byte of the async file record within the given Smalltalk bytes object, or nil if oop is not an async file record. */

static AsyncFile * asyncFileValueOf(sqInt oop) {
	interpreterProxy->success((!((oop & 1))) && ((interpreterProxy->isBytes(oop)) && ((interpreterProxy->slotSizeOf(oop)) == (sizeof(AsyncFile)))));
	if (interpreterProxy->failed()) {
		return null;
	}
	return (AsyncFile *) (oop + 4);
}


/*	Adjust for zero-origin indexing. This is implemented as a separate method in order
	to encourage inlining. */

static char * bufferPointerstartIndex(sqInt buffer, sqInt startIndex) {
	return (((pointerForOop(buffer)) + ( 4)) + startIndex) - 1;
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


/*	Initialise the module */

EXPORT(sqInt) initialiseModule(void) {
	sCOAFfn = interpreterProxy->ioLoadFunctionFrom("secCanOpenAsyncFileOfSizeWritable", "SecurityPlugin");
	return asyncFileInit();
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char * aModuleName) {
	if ((strcmp(aModuleName, "SecurityPlugin")) == 0) {
		sCOAFfn = 0;
	}
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveAsyncFileClose(void) {
	AsyncFile * f;
	sqInt fh;

	fh = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	f = asyncFileValueOf(fh);
	asyncFileClose(f);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveAsyncFileOpen(void) {
	AsyncFile * f;
	sqInt fOop;
	sqInt okToOpen;
	sqInt fileNameSize;
	char *fileName;
	sqInt writeFlag;
	sqInt semaIndex;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	fileName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	writeFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	semaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	fileNameSize = interpreterProxy->slotSizeOf(oopForPointer(fileName) - 4);
	if (sCOAFfn != 0) {
		okToOpen =  ((sqInt (*) (char *, sqInt, sqInt)) sCOAFfn)(fileName, fileNameSize, writeFlag);
		if (!(okToOpen)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	fOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(AsyncFile));
	f = asyncFileValueOf(fOop);
	if (!(interpreterProxy->failed())) {
		asyncFileOpen(f, (int)fileName, fileNameSize, writeFlag, semaIndex);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, fOop);
	return null;
}

EXPORT(sqInt) primitiveAsyncFileReadResult(void) {
	AsyncFile * f;
	sqInt count;
	sqInt startIndex;
	sqInt bufferSize;
	sqInt r;
	char * bufferPtr;
	sqInt fhandle;
	sqInt buffer;
	sqInt start;
	sqInt num;
	sqInt _return_value;

	fhandle = interpreterProxy->stackValue(3);
	buffer = interpreterProxy->stackValue(2);
	start = interpreterProxy->stackIntegerValue(1);
	num = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	f = asyncFileValueOf(fhandle);
	count = num;
	startIndex = start;

	/* in bytes or words */

	bufferSize = interpreterProxy->slotSizeOf(buffer);
	if (interpreterProxy->isWords(buffer)) {
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + count) - 1) <= bufferSize));
	bufferPtr = (((pointerForOop(buffer)) + ( 4)) + startIndex) - 1;
	if (!(interpreterProxy->failed())) {
		r = asyncFileReadResult(f, bufferPtr, count);
	}
	_return_value = interpreterProxy->integerObjectOf(r);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveAsyncFileReadStart(void) {
	AsyncFile * f;
	sqInt fHandle;
	sqInt fPosition;
	sqInt count;

	fHandle = interpreterProxy->stackValue(2);
	fPosition = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	f = asyncFileValueOf(fHandle);
	asyncFileReadStart(f, fPosition, count);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitiveAsyncFileWriteResult(void) {
	AsyncFile * f;
	sqInt r;
	sqInt fHandle;
	sqInt _return_value;

	fHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	f = asyncFileValueOf(fHandle);
	r =  asyncFileWriteResult(f);
	_return_value = interpreterProxy->integerObjectOf(r);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveAsyncFileWriteStart(void) {
	AsyncFile * f;
	sqInt count;
	sqInt startIndex;
	sqInt bufferSize;
	char * bufferPtr;
	sqInt fHandle;
	sqInt fPosition;
	sqInt buffer;
	sqInt start;
	sqInt num;

	fHandle = interpreterProxy->stackValue(4);
	fPosition = interpreterProxy->stackIntegerValue(3);
	buffer = interpreterProxy->stackValue(2);
	start = interpreterProxy->stackIntegerValue(1);
	num = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	f = asyncFileValueOf(fHandle);
	if (interpreterProxy->failed()) {
		return null;
	}
	count = num;
	startIndex = start;

	/* in bytes or words */

	bufferSize = interpreterProxy->slotSizeOf(buffer);
	if (interpreterProxy->isWords(buffer)) {
		count = count * ( 4);
		startIndex = ((startIndex - 1) * ( 4)) + 1;
		bufferSize = bufferSize * ( 4);
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + count) - 1) <= bufferSize));
	bufferPtr = (((pointerForOop(buffer)) + ( 4)) + startIndex) - 1;
	if (!(interpreterProxy->failed())) {
		asyncFileWriteStart(f, fPosition, bufferPtr, count);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(5);
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


/*	Initialise the module */

EXPORT(sqInt) shutdownModule(void) {
	return asyncFileShutdown();
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* AsynchFilePlugin_exports[][3] = {
	{"AsynchFilePlugin", "primitiveAsyncFileOpen", (void*)primitiveAsyncFileOpen},
	{"AsynchFilePlugin", "shutdownModule", (void*)shutdownModule},
	{"AsynchFilePlugin", "primitiveAsyncFileReadResult", (void*)primitiveAsyncFileReadResult},
	{"AsynchFilePlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"AsynchFilePlugin", "setInterpreter", (void*)setInterpreter},
	{"AsynchFilePlugin", "primitiveAsyncFileReadStart", (void*)primitiveAsyncFileReadStart},
	{"AsynchFilePlugin", "initialiseModule", (void*)initialiseModule},
	{"AsynchFilePlugin", "primitiveAsyncFileWriteStart", (void*)primitiveAsyncFileWriteStart},
	{"AsynchFilePlugin", "getModuleName", (void*)getModuleName},
	{"AsynchFilePlugin", "primitiveAsyncFileWriteResult", (void*)primitiveAsyncFileWriteResult},
	{"AsynchFilePlugin", "primitiveAsyncFileClose", (void*)primitiveAsyncFileClose},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

