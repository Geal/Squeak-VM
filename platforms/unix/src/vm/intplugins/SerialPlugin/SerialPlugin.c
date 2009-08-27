/* Automatically generated from Squeak on an Array(26 August 2009 10:01:27 pm)
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
#include "SerialPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static char * allocateTerminatedString(char * unterminatedCharactersInStringObject);
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
EXPORT(sqInt) primitiveSerialPortClose(void);
EXPORT(sqInt) primitiveSerialPortCloseByName(void);
EXPORT(sqInt) primitiveSerialPortOpen(void);
EXPORT(sqInt) primitiveSerialPortOpenByName(void);
EXPORT(sqInt) primitiveSerialPortRead(void);
EXPORT(sqInt) primitiveSerialPortReadByName(void);
EXPORT(sqInt) primitiveSerialPortWrite(void);
EXPORT(sqInt) primitiveSerialPortWriteByName(void);
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
	"SerialPlugin 26 August 2009 (i)"
#else
	"SerialPlugin 26 August 2009 (e)"
#endif
;



/*	Allocate a C string with contents of a String value. May cause garbage collection. */

static char * allocateTerminatedString(char * unterminatedCharactersInStringObject) {
	sqInt len;
	sqInt terminatedString;
	char * p;

	len = interpreterProxy->sizeOfSTArrayFromCPrimitive(unterminatedCharactersInStringObject);
	terminatedString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len + 1);
	p = interpreterProxy->arrayValueOf(terminatedString);
	p[len] = 0;
	while (len >= 0) {
		len -= 1;
		p[len] = (unterminatedCharactersInStringObject[len]);
	}
	return p;
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
	return serialPortInit();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveSerialPortClose(void) {
	sqInt portNum;

	portNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	serialPortClose(portNum);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSerialPortCloseByName(void) {
	char * cString;
	char *deviceName;
	sqInt len;
	sqInt terminatedString;
	char * p;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	deviceName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin allocateTerminatedString: */
	len = interpreterProxy->sizeOfSTArrayFromCPrimitive(deviceName);
	terminatedString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len + 1);
	p = interpreterProxy->arrayValueOf(terminatedString);
	p[len] = 0;
	while (len >= 0) {
		len -= 1;
		p[len] = (deviceName[len]);
	}
	cString = p;
	serialPortCloseByName(cString);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSerialPortOpen(void) {
	sqInt portNum;
	sqInt baudRate;
	sqInt stopBitsType;
	sqInt parityType;
	sqInt dataBits;
	sqInt inFlowControl;
	sqInt outFlowControl;
	sqInt xOnChar;
	sqInt xOffChar;

	portNum = interpreterProxy->stackIntegerValue(8);
	baudRate = interpreterProxy->stackIntegerValue(7);
	stopBitsType = interpreterProxy->stackIntegerValue(6);
	parityType = interpreterProxy->stackIntegerValue(5);
	dataBits = interpreterProxy->stackIntegerValue(4);
	inFlowControl = interpreterProxy->stackIntegerValue(3);
	outFlowControl = interpreterProxy->stackIntegerValue(2);
	xOnChar = interpreterProxy->stackIntegerValue(1);
	xOffChar = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	serialPortOpen(
			portNum, baudRate, stopBitsType, parityType, dataBits,
			inFlowControl, outFlowControl, xOnChar, xOffChar);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(9);
	return null;
}

EXPORT(sqInt) primitiveSerialPortOpenByName(void) {
	char * cString;
	char *deviceName;
	sqInt baudRate;
	sqInt stopBitsType;
	sqInt parityType;
	sqInt dataBits;
	sqInt inFlowControl;
	sqInt outFlowControl;
	sqInt xOnChar;
	sqInt xOffChar;
	sqInt len;
	sqInt terminatedString;
	char * p;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(8)));
	deviceName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(8))));
	baudRate = interpreterProxy->stackIntegerValue(7);
	stopBitsType = interpreterProxy->stackIntegerValue(6);
	parityType = interpreterProxy->stackIntegerValue(5);
	dataBits = interpreterProxy->stackIntegerValue(4);
	inFlowControl = interpreterProxy->stackIntegerValue(3);
	outFlowControl = interpreterProxy->stackIntegerValue(2);
	xOnChar = interpreterProxy->stackIntegerValue(1);
	xOffChar = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin allocateTerminatedString: */
	len = interpreterProxy->sizeOfSTArrayFromCPrimitive(deviceName);
	terminatedString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len + 1);
	p = interpreterProxy->arrayValueOf(terminatedString);
	p[len] = 0;
	while (len >= 0) {
		len -= 1;
		p[len] = (deviceName[len]);
	}
	cString = p;
	serialPortOpenByName(
			cString, baudRate, stopBitsType, parityType, dataBits,
			inFlowControl, outFlowControl, xOnChar, xOffChar);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(9);
	return null;
}

EXPORT(sqInt) primitiveSerialPortRead(void) {
	sqInt bytesRead;
	sqInt portNum;
	char *array;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;

	portNum = interpreterProxy->stackIntegerValue(3);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	array = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + count) - 1) <= (interpreterProxy->byteSizeOf((oopForPointer( array ) - 4)))));
	bytesRead = serialPortReadInto(portNum, count, (array + startIndex) - 1);
	_return_value = interpreterProxy->integerObjectOf(bytesRead);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSerialPortReadByName(void) {
	char * cString;
	sqInt bytesRead;
	char *deviceName;
	char *array;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;
	sqInt len;
	sqInt terminatedString;
	char * p;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(3)));
	deviceName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	array = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + count) - 1) <= (interpreterProxy->byteSizeOf((oopForPointer( array ) - 4)))));
	/* begin allocateTerminatedString: */
	len = interpreterProxy->sizeOfSTArrayFromCPrimitive(deviceName);
	terminatedString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len + 1);
	p = interpreterProxy->arrayValueOf(terminatedString);
	p[len] = 0;
	while (len >= 0) {
		len -= 1;
		p[len] = (deviceName[len]);
	}
	cString = p;
	bytesRead = serialPortReadIntoByName(cString, count, (array + startIndex) - 1);
	_return_value = interpreterProxy->integerObjectOf(bytesRead);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSerialPortWrite(void) {
	sqInt bytesWritten;
	sqInt portNum;
	char *array;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;

	portNum = interpreterProxy->stackIntegerValue(3);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	array = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + count) - 1) <= (interpreterProxy->byteSizeOf((oopForPointer( array ) - 4)))));
	if (!(interpreterProxy->failed())) {
		bytesWritten = serialPortWriteFrom(portNum, count, (array + startIndex) - 1);
	}
	_return_value = interpreterProxy->integerObjectOf(bytesWritten);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSerialPortWriteByName(void) {
	char * cString;
	sqInt bytesWritten;
	char *deviceName;
	char *array;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;
	sqInt len;
	sqInt terminatedString;
	char * p;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(3)));
	deviceName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	array = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + count) - 1) <= (interpreterProxy->byteSizeOf((oopForPointer( array ) - 4)))));
	if (!(interpreterProxy->failed())) {
		/* begin allocateTerminatedString: */
		len = interpreterProxy->sizeOfSTArrayFromCPrimitive(deviceName);
		terminatedString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len + 1);
		p = interpreterProxy->arrayValueOf(terminatedString);
		p[len] = 0;
		while (len >= 0) {
			len -= 1;
			p[len] = (deviceName[len]);
		}
		cString = p;
		bytesWritten = serialPortWriteFromByName(cString, count, (array + startIndex) - 1);
	}
	_return_value = interpreterProxy->integerObjectOf(bytesWritten);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
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
	return serialPortShutdown();
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SerialPlugin_exports[][3] = {
	{"SerialPlugin", "primitiveSerialPortWrite", (void*)primitiveSerialPortWrite},
	{"SerialPlugin", "primitiveSerialPortOpen", (void*)primitiveSerialPortOpen},
	{"SerialPlugin", "primitiveSerialPortOpenByName", (void*)primitiveSerialPortOpenByName},
	{"SerialPlugin", "shutdownModule", (void*)shutdownModule},
	{"SerialPlugin", "primitiveSerialPortWriteByName", (void*)primitiveSerialPortWriteByName},
	{"SerialPlugin", "initialiseModule", (void*)initialiseModule},
	{"SerialPlugin", "primitiveSerialPortClose", (void*)primitiveSerialPortClose},
	{"SerialPlugin", "setInterpreter", (void*)setInterpreter},
	{"SerialPlugin", "primitiveSerialPortReadByName", (void*)primitiveSerialPortReadByName},
	{"SerialPlugin", "primitiveSerialPortRead", (void*)primitiveSerialPortRead},
	{"SerialPlugin", "primitiveSerialPortCloseByName", (void*)primitiveSerialPortCloseByName},
	{"SerialPlugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

