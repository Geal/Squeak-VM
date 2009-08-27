/* Automatically generated from Squeak on an Array(26 August 2009 10:02:12 pm)
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
#include "MIDIPlugin.h"

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
EXPORT(sqInt) primitiveMIDIClosePort(void);
EXPORT(sqInt) primitiveMIDIGetClock(void);
EXPORT(sqInt) primitiveMIDIGetPortCount(void);
EXPORT(sqInt) primitiveMIDIGetPortDirectionality(void);
EXPORT(sqInt) primitiveMIDIGetPortName(void);
EXPORT(sqInt) primitiveMIDIOpenPort(void);
EXPORT(sqInt) primitiveMIDIParameterGet(void);
EXPORT(sqInt) primitiveMIDIParameterGetOrSet(void);
EXPORT(sqInt) primitiveMIDIParameterSet(void);
EXPORT(sqInt) primitiveMIDIRead(void);
EXPORT(sqInt) primitiveMIDIWrite(void);
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
	"MIDIPlugin 26 August 2009 (i)"
#else
	"MIDIPlugin 26 August 2009 (e)"
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
	return midiInit();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveMIDIClosePort(void) {
	sqInt portNum;

	portNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sqMIDIClosePort(portNum);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Return the value of the MIDI clock as a SmallInteger. The range is limited to SmallInteger maxVal / 2 to allow scheduling MIDI events into the future without overflowing a SmallInteger. The sqMIDIGetClock function is assumed to wrap at or before 16r20000000. */

EXPORT(sqInt) primitiveMIDIGetClock(void) {
	sqInt clockValue;
	sqInt _return_value;

	clockValue = (sqMIDIGetClock()) & 536870911;
	_return_value = interpreterProxy->integerObjectOf(clockValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveMIDIGetPortCount(void) {
	sqInt n;
	sqInt _return_value;

	n = sqMIDIGetPortCount();
	_return_value = interpreterProxy->integerObjectOf(n);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveMIDIGetPortDirectionality(void) {
	sqInt dir;
	sqInt portNum;
	sqInt _return_value;

	portNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	dir = sqMIDIGetPortDirectionality(portNum);
	_return_value = interpreterProxy->integerObjectOf(dir);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveMIDIGetPortName(void) {
	sqInt nameObj;
	char portName[256];
	sqInt sz;
	char *  namePtr;
	sqInt portNum;

	portNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sz = sqMIDIGetPortName(portNum, (int) &portName, 255);
	nameObj = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	namePtr = ((char *) interpreterProxy->firstIndexableField(nameObj));
	memcpy(namePtr, portName, sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, nameObj);
	return null;
}

EXPORT(sqInt) primitiveMIDIOpenPort(void) {
	sqInt portNum;
	sqInt semaIndex;
	sqInt clockRate;

	portNum = interpreterProxy->stackIntegerValue(2);
	semaIndex = interpreterProxy->stackIntegerValue(1);
	clockRate = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sqMIDIOpenPort(portNum, semaIndex, clockRate);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	read parameter */

EXPORT(sqInt) primitiveMIDIParameterGet(void) {
	sqInt currentValue;
	sqInt whichParameter;
	sqInt _return_value;

	whichParameter = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	currentValue = sqMIDIParameterGet(whichParameter);
	_return_value = interpreterProxy->integerObjectOf(currentValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Backward compatibility */

EXPORT(sqInt) primitiveMIDIParameterGetOrSet(void) {
	if ((interpreterProxy->methodArgumentCount()) == 1) {
		return primitiveMIDIParameterGet();
	} else {
		return primitiveMIDIParameterSet();
	}
}


/*	write parameter */

EXPORT(sqInt) primitiveMIDIParameterSet(void) {
	sqInt whichParameter;
	sqInt newValue;

	whichParameter = interpreterProxy->stackIntegerValue(1);
	newValue = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sqMIDIParameterSet(whichParameter, newValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveMIDIRead(void) {
	sqInt arrayLength;
	sqInt bytesRead;
	sqInt portNum;
	char *array;
	sqInt _return_value;

	portNum = interpreterProxy->stackIntegerValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	array = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	arrayLength = interpreterProxy->byteSizeOf((oopForPointer( array ) - 4));
	bytesRead = sqMIDIPortReadInto(portNum, arrayLength, ((sqInt) array ));
	_return_value = interpreterProxy->integerObjectOf(bytesRead);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveMIDIWrite(void) {
	sqInt arrayLength;
	sqInt bytesWritten;
	sqInt portNum;
	char *array;
	sqInt time;
	sqInt _return_value;

	portNum = interpreterProxy->stackIntegerValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	array = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	time = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	arrayLength = interpreterProxy->byteSizeOf((oopForPointer( array ) - 4));
	bytesWritten = sqMIDIPortWriteFromAt(portNum, arrayLength, ((sqInt) array ), time);
	_return_value = interpreterProxy->integerObjectOf(bytesWritten);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
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
	return midiShutdown();
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* MIDIPlugin_exports[][3] = {
	{"MIDIPlugin", "shutdownModule", (void*)shutdownModule},
	{"MIDIPlugin", "primitiveMIDIParameterSet", (void*)primitiveMIDIParameterSet},
	{"MIDIPlugin", "primitiveMIDIGetPortName", (void*)primitiveMIDIGetPortName},
	{"MIDIPlugin", "primitiveMIDIParameterGet", (void*)primitiveMIDIParameterGet},
	{"MIDIPlugin", "setInterpreter", (void*)setInterpreter},
	{"MIDIPlugin", "primitiveMIDIGetPortDirectionality", (void*)primitiveMIDIGetPortDirectionality},
	{"MIDIPlugin", "initialiseModule", (void*)initialiseModule},
	{"MIDIPlugin", "primitiveMIDIGetPortCount", (void*)primitiveMIDIGetPortCount},
	{"MIDIPlugin", "primitiveMIDIRead", (void*)primitiveMIDIRead},
	{"MIDIPlugin", "getModuleName", (void*)getModuleName},
	{"MIDIPlugin", "primitiveMIDIOpenPort", (void*)primitiveMIDIOpenPort},
	{"MIDIPlugin", "primitiveMIDIClosePort", (void*)primitiveMIDIClosePort},
	{"MIDIPlugin", "primitiveMIDIWrite", (void*)primitiveMIDIWrite},
	{"MIDIPlugin", "primitiveMIDIGetClock", (void*)primitiveMIDIGetClock},
	{"MIDIPlugin", "primitiveMIDIParameterGetOrSet", (void*)primitiveMIDIParameterGetOrSet},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

