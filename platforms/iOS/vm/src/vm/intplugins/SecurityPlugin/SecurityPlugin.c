/* Automatically generated from Squeak on 15 June 2010 5:06:21 pm 
   by VMMaker 4.2.4
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
#include "SecurityPlugin.h"

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
EXPORT(sqInt) primitiveCanWriteImage(void);
EXPORT(sqInt) primitiveDisableImageWrite(void);
EXPORT(sqInt) primitiveGetSecureUserDirectory(void);
EXPORT(sqInt) primitiveGetUntrustedUserDirectory(void);
EXPORT(sqInt) secCanListenOnPort(sqInt socket, sqInt port);
EXPORT(sqInt) secCanConnectToPort(sqInt addr, sqInt port);
EXPORT(sqInt) secCanCreateSocketOfType(sqInt netType, sqInt socketType);
EXPORT(sqInt) secCanCreatePathOfSize(char * dirName, sqInt dirNameSize);
EXPORT(sqInt) secCanDeleteFileOfSize(char * fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanDeletePathOfSize(char * dirName, sqInt dirNameSize);
EXPORT(sqInt) secCanGetFileTypeOfSize(char * fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanListPathOfSize(char * pathName, sqInt pathNameSize);
EXPORT(sqInt) secCanOpenAsyncFileOfSizeWritable(char * fileName, sqInt fileNameSize, sqInt writeFlag);
EXPORT(sqInt) secCanOpenFileOfSizeWritable(char * fileName, sqInt fileNameSize, sqInt writeFlag);
EXPORT(sqInt) secCanRenameFileOfSize(char * fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanRenameImage(void);
EXPORT(sqInt) secCanSetFileTypeOfSize(char * fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanWriteImage(void);
EXPORT(sqInt) secDisableFileAccess(void);
EXPORT(sqInt) secDisableSocketAccess(void);
EXPORT(sqInt) secHasFileAccess(void);
EXPORT(sqInt) secHasSocketAccess(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SecurityPlugin 15 June 2010 (i)"
#else
	"SecurityPlugin 15 June 2010 (e)"
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
	return ioInitSecurity();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveCanWriteImage(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(ioCanWriteImage());
}

EXPORT(sqInt) primitiveDisableImageWrite(void) {
	ioDisableImageWrite();
}


/*	Primitive. Return the secure directory for the current user. */

EXPORT(sqInt) primitiveGetSecureUserDirectory(void) {
    sqInt dirOop;
    char * dirName;
    sqInt i;
    sqInt dirLen;
    char * dirPtr;

	dirName = ioGetSecureUserDirectory();
	if ((dirName == null) || (interpreterProxy->failed())) {
		return interpreterProxy->primitiveFail();
	}
	dirLen = strlen(dirName);
	dirOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), dirLen);
	if (interpreterProxy->failed()) {
		return null;
	}
	dirPtr = interpreterProxy->firstIndexableField(dirOop);
	for (i = 0; i <= (dirLen - 1); i += 1) {
		dirPtr[i] = (dirName[i]);
	}
	interpreterProxy->popthenPush(1, dirOop);
}


/*	Primitive. Return the untrusted user directory name. */

EXPORT(sqInt) primitiveGetUntrustedUserDirectory(void) {
    sqInt dirOop;
    char * dirName;
    sqInt i;
    sqInt dirLen;
    char * dirPtr;

	dirName = ioGetUntrustedUserDirectory();
	if ((dirName == null) || (interpreterProxy->failed())) {
		return interpreterProxy->primitiveFail();
	}
	dirLen = strlen(dirName);
	dirOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), dirLen);
	if (interpreterProxy->failed()) {
		return null;
	}
	dirPtr = interpreterProxy->firstIndexableField(dirOop);
	for (i = 0; i <= (dirLen - 1); i += 1) {
		dirPtr[i] = (dirName[i]);
	}
	interpreterProxy->popthenPush(1, dirOop);
}

EXPORT(sqInt) secCanListenOnPort(sqInt socket, sqInt port) {
	return ioCanListenOnPort(socket, port);
}

EXPORT(sqInt) secCanConnectToPort(sqInt addr, sqInt port) {
	return ioCanConnectToPort(addr, port);
}

EXPORT(sqInt) secCanCreateSocketOfType(sqInt netType, sqInt socketType) {
	return ioCanCreateSocketOfType(netType, socketType);
}

EXPORT(sqInt) secCanCreatePathOfSize(char * dirName, sqInt dirNameSize) {
	return ioCanCreatePathOfSize(dirName, dirNameSize);
}

EXPORT(sqInt) secCanDeleteFileOfSize(char * fileName, sqInt fileNameSize) {
	return ioCanDeleteFileOfSize(fileName, fileNameSize);
}

EXPORT(sqInt) secCanDeletePathOfSize(char * dirName, sqInt dirNameSize) {
	return ioCanDeletePathOfSize(dirName, dirNameSize);
}

EXPORT(sqInt) secCanGetFileTypeOfSize(char * fileName, sqInt fileNameSize) {
	return ioCanGetFileTypeOfSize(fileName, fileNameSize);
}

EXPORT(sqInt) secCanListPathOfSize(char * pathName, sqInt pathNameSize) {
	return ioCanListPathOfSize(pathName, pathNameSize);
}

EXPORT(sqInt) secCanOpenAsyncFileOfSizeWritable(char * fileName, sqInt fileNameSize, sqInt writeFlag) {
	return ioCanOpenAsyncFileOfSizeWritable(fileName, fileNameSize, writeFlag);
}

EXPORT(sqInt) secCanOpenFileOfSizeWritable(char * fileName, sqInt fileNameSize, sqInt writeFlag) {
	return ioCanOpenFileOfSizeWritable(fileName, fileNameSize, writeFlag);
}

EXPORT(sqInt) secCanRenameFileOfSize(char * fileName, sqInt fileNameSize) {
	return ioCanRenameFileOfSize(fileName, fileNameSize);
}

EXPORT(sqInt) secCanRenameImage(void) {
	return ioCanRenameImage();
}

EXPORT(sqInt) secCanSetFileTypeOfSize(char * fileName, sqInt fileNameSize) {
	return ioCanSetFileTypeOfSize(fileName, fileNameSize);
}

EXPORT(sqInt) secCanWriteImage(void) {
	return ioCanWriteImage();
}

EXPORT(sqInt) secDisableFileAccess(void) {
	return ioDisableFileAccess();
}

EXPORT(sqInt) secDisableSocketAccess(void) {
	return ioDisableSocketAccess();
}

EXPORT(sqInt) secHasFileAccess(void) {
	return ioHasFileAccess();
}

EXPORT(sqInt) secHasSocketAccess(void) {
	return ioHasSocketAccess();
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


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SecurityPlugin_exports[][3] = {
	{"SecurityPlugin", "secCanSetFileTypeOfSize", (void*)secCanSetFileTypeOfSize},
	{"SecurityPlugin", "primitiveCanWriteImage", (void*)primitiveCanWriteImage},
	{"SecurityPlugin", "secDisableFileAccess", (void*)secDisableFileAccess},
	{"SecurityPlugin", "secHasFileAccess", (void*)secHasFileAccess},
	{"SecurityPlugin", "secCanCreatePathOfSize", (void*)secCanCreatePathOfSize},
	{"SecurityPlugin", "secCanListenOnPort", (void*)secCanListenOnPort},
	{"SecurityPlugin", "secCanGetFileTypeOfSize", (void*)secCanGetFileTypeOfSize},
	{"SecurityPlugin", "secCanListPathOfSize", (void*)secCanListPathOfSize},
	{"SecurityPlugin", "secCanWriteImage", (void*)secCanWriteImage},
	{"SecurityPlugin", "secDisableSocketAccess", (void*)secDisableSocketAccess},
	{"SecurityPlugin", "secCanRenameFileOfSize", (void*)secCanRenameFileOfSize},
	{"SecurityPlugin", "secCanDeletePathOfSize", (void*)secCanDeletePathOfSize},
	{"SecurityPlugin", "secCanDeleteFileOfSize", (void*)secCanDeleteFileOfSize},
	{"SecurityPlugin", "secCanOpenFileOfSizeWritable", (void*)secCanOpenFileOfSizeWritable},
	{"SecurityPlugin", "secHasSocketAccess", (void*)secHasSocketAccess},
	{"SecurityPlugin", "primitiveGetSecureUserDirectory", (void*)primitiveGetSecureUserDirectory},
	{"SecurityPlugin", "secCanCreateSocketOfType", (void*)secCanCreateSocketOfType},
	{"SecurityPlugin", "primitiveGetUntrustedUserDirectory", (void*)primitiveGetUntrustedUserDirectory},
	{"SecurityPlugin", "initialiseModule", (void*)initialiseModule},
	{"SecurityPlugin", "secCanOpenAsyncFileOfSizeWritable", (void*)secCanOpenAsyncFileOfSizeWritable},
	{"SecurityPlugin", "secCanConnectToPort", (void*)secCanConnectToPort},
	{"SecurityPlugin", "setInterpreter", (void*)setInterpreter},
	{"SecurityPlugin", "getModuleName", (void*)getModuleName},
	{"SecurityPlugin", "primitiveDisableImageWrite", (void*)primitiveDisableImageWrite},
	{"SecurityPlugin", "secCanRenameImage", (void*)secCanRenameImage},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

