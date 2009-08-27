/* Automatically generated from Squeak on an Array(26 August 2009 10:02:27 pm)
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
#include <unistd.h>
#define FILEHANDLETYPE FILE *  /* the type of low level stream to be used in a struct SQFile */
#include "FilePlugin.h"
#include "SocketPlugin.h"
#include "config.h"
#ifndef SQAIO_H
# define SQAIO_H "aio.h"  /* aio.h has been renamed to sqaio.h */
#endif
#define SESSIONIDENTIFIERTYPE int
#include SQAIO_H

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static void aioForwardwithDataandFlags(int fd, void * data, int flags);
static sqInt fileDescriptorFrom(sqInt aSQFileByteArray);
static FILEHANDLETYPE fileHandleFrom(sqInt sqFileStructByteArray);
static sqInt fileRecordSize(void);
static SQFile * fileValueOf(sqInt anSQFileRecord);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt getThisSessionIdentifier(void);
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt isNonNullSQFile(sqInt objectPointer);
static sqInt isNullSQSocket(sqInt objectPointer);
static sqInt isSQFileObject(sqInt objectPointer);
static sqInt isSQSocketObject(sqInt objectPointer);
static sqInt isValidFileSession(sqInt objectPointer);
#pragma export on
EXPORT(sqInt) moduleUnloaded(char * aModuleName);
#pragma export off
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveAioDisable(void);
EXPORT(sqInt) primitiveAioEnable(void);
EXPORT(sqInt) primitiveAioHandle(void);
EXPORT(sqInt) primitiveAioSuspend(void);
EXPORT(sqInt) primitiveModuleName(void);
EXPORT(sqInt) primitiveOSFileHandle(void);
EXPORT(sqInt) primitiveOSSocketHandle(void);
EXPORT(sqInt) primitiveVersionString(void);
#pragma export off
static SESSIONIDENTIFIERTYPE sessionIdentifierFromSqFile(SQFile * sqFile);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static int socketDescriptorFrom(sqInt sqSocketOop);
static sqInt socketRecordSize(void);
static SQSocket * socketValueOf(sqInt anSQSocketRecord);
static sqInt stringFromCString(const char * aCString);
static char * versionString(void);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"AioPlugin 26 August 2009 (i)"
#else
	"AioPlugin 26 August 2009 (e)"
#endif
;



/*	This function is called to signal a Smalltalk Semaphore when an asynchronous event is
	detected. When translated to C, the name of this method is aioForwardwithDataandFlags.
	The event handler is set up by #primitiveAioHandle. */

static void aioForwardwithDataandFlags(int fd, void * data, int flags) {
    int *pfd;
    sqInt semaIndex;

	pfd = data;
	semaIndex = *pfd;
	interpreterProxy->signalSemaphoreWithIndex(semaIndex);
}


/*	Answer the OS file descriptor, an integer value, from a SQFile data structure
	byte array, or answer -1 if unable to obtain the file descriptor (probably due
	to receiving an incorrect type of object as aFileHandle). */
/*	return type should be int, but skip the declaration to permit inlining */

static sqInt fileDescriptorFrom(sqInt aSQFileByteArray) {
	if (!((((interpreterProxy->isBytes(aSQFileByteArray)) && ((interpreterProxy->byteSizeOf(aSQFileByteArray)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(aSQFileByteArray))))) && (isNonNullSQFile(aSQFileByteArray)))) {
		return -1;
	}
	return fileno(fileHandleFrom(aSQFileByteArray));
}


/*	Answer a file handle from a SQFile structure. On most platforms, this
	will be a (FILE *). On Win32, it is a HANDLE. */

static FILEHANDLETYPE fileHandleFrom(sqInt sqFileStructByteArray) {
    SQFile *sqFile;

	sqFile = interpreterProxy->arrayValueOf(sqFileStructByteArray);
	return sqFile->file;
}


/*	Answer the size of a SQFile data structure in bytes. */

static sqInt fileRecordSize(void) {
	return sizeof(SQFile);
}


/*	Return a pointer to the first byte of of the SQFile data structure file record within
	anSQFileRecord, which is expected to be a ByteArray of size self>>fileRecordSize. */

static SQFile * fileValueOf(sqInt anSQFileRecord) {
	return interpreterProxy->arrayValueOf(anSQFileRecord);
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

static sqInt getThisSessionIdentifier(void) {
	return interpreterProxy->getThisSessionID();
}

static sqInt halt(void) {
	;
}

EXPORT(sqInt) initialiseModule(void) {
	return 1;
}


/*	Check for the common failure mode of a SQFile record with all zeros. */

static sqInt isNonNullSQFile(sqInt objectPointer) {
    unsigned char * sqFileBytes;
    sqInt idx;

	sqFileBytes = interpreterProxy->arrayValueOf(objectPointer);
	idx = 0;
	while (idx < (fileRecordSize())) {
		if ((sqFileBytes[idx]) != 0) {
			return 1;
		}
		idx += 1;
	}
	return 0;
}


/*	Check for the common failure mode of a SQSocket record with all zeros. */

static sqInt isNullSQSocket(sqInt objectPointer) {
    sqInt idx;
    unsigned char * sqSocketBytes;

	sqSocketBytes = interpreterProxy->arrayValueOf(objectPointer);
	idx = 0;
	while (idx < (socketRecordSize())) {
		if ((sqSocketBytes[idx]) != 0) {
			return 0;
		}
		idx += 1;
	}
	return 1;
}


/*	Answer true if objectPointer appears to be a valid SQFile ByteArray.
	This check is appropriate if objectPointer has been passed as a parameter
	to a primitive, and is expected to represent a valid file reference. */

static sqInt isSQFileObject(sqInt objectPointer) {
	return (((interpreterProxy->isBytes(objectPointer)) && ((interpreterProxy->byteSizeOf(objectPointer)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(objectPointer))))) && (isNonNullSQFile(objectPointer));
}


/*	Answer true if objectPointer appears to be a valid SQSocket ByteArray. This check
	is appropriate if objectPointer has been passed as a parameter to a primitive, and
	is expected to represent a valid socket reference. */

static sqInt isSQSocketObject(sqInt objectPointer) {
	return ((interpreterProxy->isBytes(objectPointer)) && ((interpreterProxy->byteSizeOf(objectPointer)) == (socketRecordSize()))) && (!(isNullSQSocket(objectPointer)));
}


/*	Answer true if the file session matches the current interpreter session identifier. */

static sqInt isValidFileSession(sqInt objectPointer) {
	return (interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(objectPointer)));
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char * aModuleName) {
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Definitively disable asynchronous event notification for a descriptor. The
	parameter is an OS level integer file descriptor. */

EXPORT(sqInt) primitiveAioDisable(void) {
    sqInt fd;

	if ((interpreterProxy->nilObject()) == (interpreterProxy->stackValue(0))) {
		return interpreterProxy->primitiveFail();
	}
	fd = interpreterProxy->stackIntegerValue(0);
	if (fd < 0) {
		return interpreterProxy->primitiveFail();
	}
	aioDisable(fd);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(fd);
}


/*	Enable asynchronous notification for a descriptor. The first parameter is an OS
	level integer file descriptor. The second parameter is the index of a Semaphore to
	be notified, and the third parameter is a flag indicating that descriptor represents
	an external object and should not be closed on termination of aio handling. Answer
	the semaphore index. */

EXPORT(sqInt) primitiveAioEnable(void) {
    static int eventSemaphoreIndices[FD_SETSIZE];
    sqInt fd;
    sqInt flags;
    sqInt semaIndex;
    sqInt externalObject;

	if ((interpreterProxy->nilObject()) == (interpreterProxy->stackValue(2))) {
		return interpreterProxy->primitiveFail();
	}
	fd = interpreterProxy->stackIntegerValue(2);
	if (fd < 0) {
		return interpreterProxy->primitiveFail();
	}
	semaIndex = interpreterProxy->stackIntegerValue(1);
	eventSemaphoreIndices[semaIndex] = semaIndex;
	externalObject = interpreterProxy->stackObjectValue(0);
	if (externalObject == (interpreterProxy->trueObject())) {
		flags = AIO_EXT;
	} else {
		flags = 0;
	}
	aioEnable(fd, &(eventSemaphoreIndices[semaIndex]), flags);
	interpreterProxy->pop(4);
	interpreterProxy->pushInteger(semaIndex);
}


/*	Handle asynchronous event notification for a descriptor. The first parameter is
	an OS level integer file descriptor. The remaining three parameters are Boolean
	flags representing the types of events for which notification is being requested:
	handle exceptions, handle for read, and handle for write.
	Flags are defined in the aio.h source as:
		AIO_X	(1<<0)	handle for exceptions
		AIO_R	(1<<1)	handle for read
		AIO_W	(1<<2)	handle for write */

EXPORT(sqInt) primitiveAioHandle(void) {
    sqInt fd;
    sqInt readWatch;
    sqInt flags;
    sqInt exceptionWatch;
    sqInt writeWatch;

	if ((interpreterProxy->nilObject()) == (interpreterProxy->stackValue(3))) {
		return interpreterProxy->primitiveFail();
	}
	fd = interpreterProxy->stackIntegerValue(3);
	if (fd < 0) {
		return interpreterProxy->primitiveFail();
	}
	exceptionWatch = interpreterProxy->stackObjectValue(2);
	readWatch = interpreterProxy->stackObjectValue(1);
	writeWatch = interpreterProxy->stackObjectValue(0);
	flags = 0;
	if (exceptionWatch == (interpreterProxy->trueObject())) {
		flags = flags | (AIO_X);
	}
	if (readWatch == (interpreterProxy->trueObject())) {
		flags = flags | (AIO_R);
	}
	if (writeWatch == (interpreterProxy->trueObject())) {
		flags = flags | (AIO_W);
	}
	aioHandle(fd, aioForwardwithDataandFlags, flags);
	interpreterProxy->pop(5);
	interpreterProxy->pushInteger(flags);
}


/*	Temporarily suspend asynchronous event notification for a descriptor. The first
	parameter is an OS level integer file descriptor. The remaining three parameters
	are Boolean flags representing the types of events for which notification is being
	requested: handle exceptions, handle for read, and handle for write.
	Flags are defined in the aio.h source as:
		AIO_X	(1<<0)	handle for exceptions
		AIO_R	(1<<1)	handle for read
		AIO_W	(1<<2)	handle for write */

EXPORT(sqInt) primitiveAioSuspend(void) {
    sqInt fd;
    sqInt readWatch;
    sqInt flags;
    sqInt exceptionWatch;
    sqInt writeWatch;

	if ((interpreterProxy->nilObject()) == (interpreterProxy->stackValue(3))) {
		return interpreterProxy->primitiveFail();
	}
	fd = interpreterProxy->stackIntegerValue(3);
	if (fd < 0) {
		return interpreterProxy->primitiveFail();
	}
	exceptionWatch = interpreterProxy->stackObjectValue(2);
	readWatch = interpreterProxy->stackObjectValue(1);
	writeWatch = interpreterProxy->stackObjectValue(0);
	flags = 0;
	if (exceptionWatch == (interpreterProxy->trueObject())) {
		flags = flags | (AIO_X);
	}
	if (readWatch == (interpreterProxy->trueObject())) {
		flags = flags | (AIO_R);
	}
	if (writeWatch == (interpreterProxy->trueObject())) {
		flags = flags | (AIO_W);
	}
	aioSuspend(fd, flags);
	interpreterProxy->pop(5);
	interpreterProxy->pushInteger(flags);
}


/*	Answer a string containing the module name string for this plugin. */

EXPORT(sqInt) primitiveModuleName(void) {
	interpreterProxy->popthenPush(1, stringFromCString(moduleName));
}


/*	Take a struct SQFile from the stack, and answer the value of its Unix file number. */

EXPORT(sqInt) primitiveOSFileHandle(void) {
    sqInt fileNo;
    sqInt sqFileOop;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		fileNo = -1;
		goto l1;
	}
	fileNo = fileno(fileHandleFrom(sqFileOop));
l1:	/* end fileDescriptorFrom: */;
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(fileNo);
}


/*	Take a struct SQSocket from the stack, and answer the value of its Unix file number. */

EXPORT(sqInt) primitiveOSSocketHandle(void) {
    sqInt fileNo;
    sqInt sqSocketOop;

	sqSocketOop = interpreterProxy->stackValue(0);
	if (!(((interpreterProxy->isBytes(sqSocketOop)) && ((interpreterProxy->byteSizeOf(sqSocketOop)) == (socketRecordSize()))) && (!(isNullSQSocket(sqSocketOop))))) {
		return interpreterProxy->primitiveFail();
	}
	fileNo = socketDescriptorFrom(sqSocketOop);
	if (fileNo < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(fileNo);
}


/*	Answer a string containing the version string for this plugin. */

EXPORT(sqInt) primitiveVersionString(void) {
	interpreterProxy->popthenPush(1, stringFromCString(versionString()));
}


/*	Answer the session identifier from a SQFile structure. For a valid file
	reference, this identifier will match the session identifier supplied by
	the interpreter. */

static SESSIONIDENTIFIERTYPE sessionIdentifierFromSqFile(SQFile * sqFile) {
	return sqFile->sessionID;
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
}


/*	Answer the OS file descriptor, an integer value, from a SQSocket data structure,
	or answer -1 if unable to obtain the file descriptor (probably due to receiving
	an incorrect type of object as aFileHandle).

	Warning: The first element of privateSocketStruct happens to be the Unix file
	number of the socket. See sqUnixSocket.c for the definition. This method takes
	advantage of this, and will break if anyone ever redefines the data structure. */

static int socketDescriptorFrom(sqInt sqSocketOop) {
    SQSocket *sqSocket;
    void *privateSocketStruct;

	sqSocket = interpreterProxy->arrayValueOf(sqSocketOop);
	privateSocketStruct = sqSocket->privateSocketPtr;
	if (privateSocketStruct == 0) {
		return -1;
	}
	return * (int *) privateSocketStruct;
}


/*	Answer the size of a SQSocket data structure in bytes. */

static sqInt socketRecordSize(void) {
	return sizeof(SQSocket);
}


/*	Return a pointer to the first byte of of the SQsocket data structure socket record within
	anSQSocketRecord, which is expected to be a ByteArray of size self>>socketRecordSize. */

static SQSocket * socketValueOf(sqInt anSQSocketRecord) {
	return interpreterProxy->arrayValueOf(anSQSocketRecord);
}


/*	Answer a new String copied from a null-terminated C string.
	Caution: This may invoke the garbage collector. */

static sqInt stringFromCString(const char * aCString) {
    sqInt len;
    sqInt newString;

	len = strlen(aCString);
	newString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
	strncpy(interpreterProxy->arrayValueOf(newString), aCString, len);
	return newString;
}


/*	Answer a string containing the version string for this plugin. Handle MNU
	errors, which can occur if class InterpreterPlugin has been removed from
	the system.

	Important: When this method is changed, the class side method must also be
	changed to match. */
/*	2.0 supports 64bit code base */

static char * versionString(void) {
    static char version[]= "2.2.2";

	return version;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* AioPlugin_exports[][3] = {
	{"AioPlugin", "primitiveOSFileHandle", (void*)primitiveOSFileHandle},
	{"AioPlugin", "primitiveAioSuspend", (void*)primitiveAioSuspend},
	{"AioPlugin", "shutdownModule", (void*)shutdownModule},
	{"AioPlugin", "primitiveAioHandle", (void*)primitiveAioHandle},
	{"AioPlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"AioPlugin", "initialiseModule", (void*)initialiseModule},
	{"AioPlugin", "setInterpreter", (void*)setInterpreter},
	{"AioPlugin", "getModuleName", (void*)getModuleName},
	{"AioPlugin", "primitiveOSSocketHandle", (void*)primitiveOSSocketHandle},
	{"AioPlugin", "primitiveAioDisable", (void*)primitiveAioDisable},
	{"AioPlugin", "primitiveModuleName", (void*)primitiveModuleName},
	{"AioPlugin", "primitiveAioEnable", (void*)primitiveAioEnable},
	{"AioPlugin", "primitiveVersionString", (void*)primitiveVersionString},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

