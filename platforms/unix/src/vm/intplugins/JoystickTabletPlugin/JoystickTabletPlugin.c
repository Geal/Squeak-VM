/* Automatically generated from Squeak on an Array(26 August 2009 10:01:16 pm)
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
#include "JoystickTabletPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
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
EXPORT(sqInt) primitiveGetTabletParameters(void);
EXPORT(sqInt) primitiveReadJoystick(void);
EXPORT(sqInt) primitiveReadTablet(void);
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
	"JoystickTabletPlugin 26 August 2009 (i)"
#else
	"JoystickTabletPlugin 26 August 2009 (e)"
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

EXPORT(sqInt) initialiseModule(void) {
	return joystickInit();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Get information on the pen tablet attached to this machine. Fail if there is no tablet. If successful, the result is an array of integers; see the Smalltalk call on this primitive for its interpretation. */

EXPORT(sqInt) primitiveGetTabletParameters(void) {
	int *  resultPtr;
	sqInt resultSize;
	sqInt result;
	sqInt cursorIndex;

	cursorIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classBitmap(), resultSize);
	resultPtr = (int *) interpreterProxy->firstIndexableField(result);
	interpreterProxy->success(tabletGetParameters(cursorIndex, resultPtr));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, result);
	return null;
}


/*	Read an input word from the joystick with the given index. */

EXPORT(sqInt) primitiveReadJoystick(void) {
	sqInt index;
	sqInt _return_value;

	index = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	_return_value = interpreterProxy->positive32BitIntegerFor((joystickRead(index)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Get the current state of the cursor of the pen tablet specified by my argument. Fail if there is no tablet. If successful, the result is an array of integers; see the Smalltalk call on this primitive for its interpretation. */

EXPORT(sqInt) primitiveReadTablet(void) {
	int *  resultPtr;
	sqInt resultSize;
	sqInt result;
	sqInt cursorIndex;

	cursorIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classBitmap(), resultSize);
	resultPtr = (int *) interpreterProxy->firstIndexableField(result);
	interpreterProxy->success(tabletRead(cursorIndex, resultPtr));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, result);
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
	return joystickShutdown();
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* JoystickTabletPlugin_exports[][3] = {
	{"JoystickTabletPlugin", "getModuleName", (void*)getModuleName},
	{"JoystickTabletPlugin", "shutdownModule", (void*)shutdownModule},
	{"JoystickTabletPlugin", "primitiveReadJoystick", (void*)primitiveReadJoystick},
	{"JoystickTabletPlugin", "primitiveGetTabletParameters", (void*)primitiveGetTabletParameters},
	{"JoystickTabletPlugin", "setInterpreter", (void*)setInterpreter},
	{"JoystickTabletPlugin", "primitiveReadTablet", (void*)primitiveReadTablet},
	{"JoystickTabletPlugin", "initialiseModule", (void*)initialiseModule},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

