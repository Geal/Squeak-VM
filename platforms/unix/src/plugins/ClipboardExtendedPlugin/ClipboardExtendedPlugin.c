/* Automatically generated from Squeak on an Array(26 August 2009 10:01:39 pm)
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

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) ioAddClipboardData(void);
EXPORT(sqInt) ioClearClipboard(void);
EXPORT(sqInt) ioCreateClipboard(void);
EXPORT(sqInt) ioGetClipboardFormat(void);
EXPORT(sqInt) ioReadClipboardData(void);
#pragma export off
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
static sqInt sqAssert(sqInt aBool);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"ClipboardExtendedPlugin 26 August 2009 (i)"
#else
	"ClipboardExtendedPlugin 26 August 2009 (e)"
#endif
;



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

EXPORT(sqInt) ioAddClipboardData(void) {
	sqInt clipboardAddress;
	sqInt dataLength;
	sqInt formatLength;
	sqInt clipboard;
	char *data;
	char *aFormat;

	clipboard = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	data = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aFormat = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	clipboardAddress = interpreterProxy->positive32BitValueOf(clipboard);
	dataLength = interpreterProxy->slotSizeOf((oopForPointer( data ) - 4));
	formatLength = interpreterProxy->slotSizeOf((oopForPointer( aFormat ) - 4));
	sqPasteboardPutItemFlavordatalengthformatTypeformatLength(clipboardAddress, data, dataLength, aFormat, formatLength);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) ioClearClipboard(void) {
	sqInt clipboardAddress;
	sqInt clipboard;

	clipboard = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	clipboardAddress = interpreterProxy->positive32BitValueOf(clipboard);
	sqPasteboardClear(clipboardAddress);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) ioCreateClipboard(void) {
	sqInt clipboardAddress;

	clipboardAddress = interpreterProxy->positive32BitIntegerFor(sqCreateClipboard());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, clipboardAddress);
	return null;
}

EXPORT(sqInt) ioGetClipboardFormat(void) {
	sqInt itemCount;
	sqInt clipboardAddress;
	sqInt clipboard;
	sqInt formatNumber;
	sqInt _return_value;

	clipboard = interpreterProxy->stackValue(1);
	formatNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	clipboardAddress = interpreterProxy->positive32BitValueOf(clipboard);
	itemCount = sqPasteboardGetItemCount(clipboardAddress);
	if (itemCount > 0) {
		_return_value = sqPasteboardCopyItemFlavorsitemNumber(clipboardAddress, formatNumber);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	_return_value = interpreterProxy->nilObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) ioReadClipboardData(void) {
	sqInt formatLength;
	sqInt clipboardAddress;
	sqInt clipboard;
	char *format;
	sqInt _return_value;

	clipboard = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	format = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	clipboardAddress = interpreterProxy->positive32BitValueOf(clipboard);
	formatLength = interpreterProxy->slotSizeOf((oopForPointer( format ) - 4));
	_return_value = sqPasteboardCopyItemFlavorDataformatformatLength(clipboardAddress, format, formatLength);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
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

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* ClipboardExtendedPlugin_exports[][3] = {
	{"ClipboardExtendedPlugin", "ioReadClipboardData", (void*)ioReadClipboardData},
	{"ClipboardExtendedPlugin", "ioCreateClipboard", (void*)ioCreateClipboard},
	{"ClipboardExtendedPlugin", "ioAddClipboardData", (void*)ioAddClipboardData},
	{"ClipboardExtendedPlugin", "getModuleName", (void*)getModuleName},
	{"ClipboardExtendedPlugin", "setInterpreter", (void*)setInterpreter},
	{"ClipboardExtendedPlugin", "ioGetClipboardFormat", (void*)ioGetClipboardFormat},
	{"ClipboardExtendedPlugin", "ioClearClipboard", (void*)ioClearClipboard},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

