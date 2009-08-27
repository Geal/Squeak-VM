/* Automatically generated from Squeak on an Array(26 August 2009 10:01:57 pm)
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
#include "HostWindowPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveCloseHostWindow(void);
EXPORT(sqInt) primitiveCreateHostWindow(void);
EXPORT(sqInt) primitiveHostWindowPosition(void);
EXPORT(sqInt) primitiveHostWindowPositionSet(void);
EXPORT(sqInt) primitiveHostWindowSize(void);
EXPORT(sqInt) primitiveHostWindowSizeSet(void);
EXPORT(sqInt) primitiveHostWindowTitle(void);
EXPORT(sqInt) primitiveShowHostWindowRect(void);
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
	"HostWindowPlugin 26 August 2009 (i)"
#else
	"HostWindowPlugin 26 August 2009 (e)"
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

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Close a host window. windowIndex is the SmallInt handle returned previously by primitiveCreateHostWindow. Fail if the index is invalid or the platform code fails */

EXPORT(sqInt) primitiveCloseHostWindow(void) {
	sqInt ok;
	sqInt windowIndex;

	windowIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	ok = closeWindow(windowIndex);
	if (!(ok)) {
		interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Create a host window of width 'w' pixels, height 'h' with the origin of the
user area at 'x@y' from the topleft corner of the screen.
Return the SmallInt value of the internal index to the window description block
- which is whatever the host platform code needs it to be. */

EXPORT(sqInt) primitiveCreateHostWindow(void) {
	sqInt listLength;
	sqInt windowIndex;
	sqInt w;
	sqInt h;
	sqInt x;
	sqInt y;
	char *list;
	sqInt _return_value;

	w = interpreterProxy->stackIntegerValue(4);
	h = interpreterProxy->stackIntegerValue(3);
	x = interpreterProxy->stackIntegerValue(2);
	y = interpreterProxy->stackIntegerValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	list = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	listLength = interpreterProxy->slotSizeOf((oopForPointer( list ) - 4));
	windowIndex = createWindowWidthheightoriginXyattrlength(w, h, x, y, list, listLength);
	if (windowIndex > 0) {
		_return_value = interpreterProxy->integerObjectOf(windowIndex);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(6, _return_value);
		return null;
	} else {
		interpreterProxy->primitiveFail();
		return null;
	}
}


/*	Return the origin position of the user area of the window in pixels from the topleft corner of the screen. Fail if the windowIndex is invalid or the platform routine returns -1 to indicate failure */

EXPORT(sqInt) primitiveHostWindowPosition(void) {
	sqInt pos;
	sqInt windowIndex;
	sqInt _return_value;

	windowIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	pos = ioPositionOfWindow(windowIndex);
	if (pos == -1) {
		interpreterProxy->primitiveFail();
		return null;
	} else {
		_return_value = interpreterProxy->makePointwithxValueyValue(((usqInt) pos) >> 16, pos & 65535);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
}


/*	Set the origin position of the user area of the window  in pixels from the topleft corner of the screen- return the position actually set by the OS/GUI/window manager. Fail if the windowIndex is invalid or the platform routine returns -1 to indicate failure */

EXPORT(sqInt) primitiveHostWindowPositionSet(void) {
	sqInt pos;
	sqInt windowIndex;
	sqInt x;
	sqInt y;
	sqInt _return_value;

	windowIndex = interpreterProxy->stackIntegerValue(2);
	x = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	pos = ioPositionOfWindowSetxy(windowIndex, x, y);
	if (pos == -1) {
		interpreterProxy->primitiveFail();
		return null;
	} else {
		_return_value = interpreterProxy->makePointwithxValueyValue(((usqInt) pos) >> 16, pos & 65535);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
}


/*	Return the size of the user area of the window in pixels. Fail if the windowIndex is invalid or the platform routine returns -1 to indicate failure */

EXPORT(sqInt) primitiveHostWindowSize(void) {
	sqInt size;
	sqInt windowIndex;
	sqInt _return_value;

	windowIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	size = ioSizeOfWindow(windowIndex);
	if (size == -1) {
		interpreterProxy->primitiveFail();
		return null;
	} else {
		_return_value = interpreterProxy->makePointwithxValueyValue(((usqInt) size) >> 16, size & 65535);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
}


/*	Set the size of the user area of the window in pixels - return what is actually set by the OS/GUI/window manager. Fail if the windowIndex is invalid or the platform routine returns -1 to indicate failure */

EXPORT(sqInt) primitiveHostWindowSizeSet(void) {
	sqInt size;
	sqInt windowIndex;
	sqInt x;
	sqInt y;
	sqInt _return_value;

	windowIndex = interpreterProxy->stackIntegerValue(2);
	x = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	size = ioSizeOfWindowSetxy(windowIndex, x, y);
	if (size == -1) {
		interpreterProxy->primitiveFail();
		return null;
	} else {
		_return_value = interpreterProxy->makePointwithxValueyValue(((usqInt) size) >> 16, size & 65535);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
}


/*	Set the title bar label of the window. Fail if the windowIndex is invalid or the platform routine returns -1 to indicate failure */

EXPORT(sqInt) primitiveHostWindowTitle(void) {
	sqInt res;
	sqInt titleLength;
	sqInt id;
	char *titleString;

	id = interpreterProxy->stackIntegerValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	titleString = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	titleLength = interpreterProxy->slotSizeOf((oopForPointer( titleString ) - 4));
	res = ioSetTitleOfWindow(id, titleString, titleLength);
	if (res == -1) {
		interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Host window analogue of DisplayScreen> primShowRectLeft:right:top:bottom:
(Interpreter>primitiveShowDisplayRect) which takes the window index, bitmap
details and the rectangle bounds. Fail if the windowIndex is invalid or the
platform routine returns false to indicate failure */

EXPORT(sqInt) primitiveShowHostWindowRect(void) {
	sqInt ok;
	sqInt windowIndex;
	usqInt *dispBits;
	sqInt w;
	sqInt h;
	sqInt d;
	sqInt left;
	sqInt right;
	sqInt top;
	sqInt bottom;

	windowIndex = interpreterProxy->stackIntegerValue(8);
	interpreterProxy->success(interpreterProxy->isWords(interpreterProxy->stackValue(7)));
	dispBits = ((unsigned *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(7))));
	w = interpreterProxy->stackIntegerValue(6);
	h = interpreterProxy->stackIntegerValue(5);
	d = interpreterProxy->stackIntegerValue(4);
	left = interpreterProxy->stackIntegerValue(3);
	right = interpreterProxy->stackIntegerValue(2);
	top = interpreterProxy->stackIntegerValue(1);
	bottom = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	ok = ioShowDisplayOnWindow(dispBits, w, h, d, left, right, top,
bottom, windowIndex);
	if (!(ok)) {
		interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(9);
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


/*	do any window related VM closing down work your platform requires. */

EXPORT(sqInt) shutdownModule(void) {
	return ioCloseAllWindows();
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* HostWindowPlugin_exports[][3] = {
	{"HostWindowPlugin", "primitiveHostWindowPositionSet", (void*)primitiveHostWindowPositionSet},
	{"HostWindowPlugin", "primitiveHostWindowSize", (void*)primitiveHostWindowSize},
	{"HostWindowPlugin", "primitiveHostWindowPosition", (void*)primitiveHostWindowPosition},
	{"HostWindowPlugin", "shutdownModule", (void*)shutdownModule},
	{"HostWindowPlugin", "primitiveHostWindowTitle", (void*)primitiveHostWindowTitle},
	{"HostWindowPlugin", "primitiveShowHostWindowRect", (void*)primitiveShowHostWindowRect},
	{"HostWindowPlugin", "setInterpreter", (void*)setInterpreter},
	{"HostWindowPlugin", "getModuleName", (void*)getModuleName},
	{"HostWindowPlugin", "primitiveCloseHostWindow", (void*)primitiveCloseHostWindow},
	{"HostWindowPlugin", "primitiveHostWindowSizeSet", (void*)primitiveHostWindowSizeSet},
	{"HostWindowPlugin", "primitiveCreateHostWindow", (void*)primitiveCreateHostWindow},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

