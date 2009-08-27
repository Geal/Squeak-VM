/* Automatically generated from Squeak on an Array(26 August 2009 10:02:35 pm)
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
#include <X11/Xlib.h>

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
EXPORT(sqInt) moduleUnloaded(char * aModuleName);
#pragma export off
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveCanConnectToDisplay(void);
EXPORT(sqInt) primitiveDisconnectDisplay(void);
EXPORT(sqInt) primitiveFlushDisplay(void);
EXPORT(sqInt) primitiveGetDisplayName(void);
EXPORT(sqInt) primitiveIsConnectedToDisplay(void);
EXPORT(sqInt) primitiveKillDisplay(void);
EXPORT(sqInt) primitiveModuleName(void);
EXPORT(sqInt) primitiveOpenDisplay(void);
EXPORT(sqInt) primitiveSetDisplayName(void);
EXPORT(sqInt) primitiveVersionString(void);
#pragma export off
static sqInt sandboxSecurity(void);
static sqInt securityHeurisitic(void);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt stringFromCString(const char * aCString);
static char * transientCStringFromString(sqInt aString);
static char * versionString(void);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"XDisplayControlPlugin 26 August 2009 (i)"
#else
	"XDisplayControlPlugin 26 August 2009 (e)"
#endif
;
static int osprocessSandboxSecurity;



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
	osprocessSandboxSecurity = -1;
	return 1;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char * aModuleName) {
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Open and close a connection to displayName. It the connection was successfully
	opened, answer true; otherwise false. This is intended to check for the ability
	to open an X display prior to actually making the attempt. */

EXPORT(sqInt) primitiveCanConnectToDisplay(void) {
    sqInt name;
    char * namePtr;
    Display *d;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->push(interpreterProxy->falseObject());
	} else {
		name = interpreterProxy->stackObjectValue(0);
		namePtr = transientCStringFromString(name);
		d = XOpenDisplay(namePtr);
		if (d == 0) {
			interpreterProxy->pop(2);
			interpreterProxy->push(interpreterProxy->falseObject());
		} else {
			XCloseDisplay(d);
			interpreterProxy->pop(2);
			interpreterProxy->push(interpreterProxy->trueObject());
		}
	}
}


/*	Call an internal function which will disconnect the X display session. The actual
	Squeak window on the X server is not effected, but this instance of Squeak will
	not have any further interaction with it. */

EXPORT(sqInt) primitiveDisconnectDisplay(void) {
	if (!((sandboxSecurity()) == 1)) {
		forgetXDisplay();
	}
}


/*	Call an internal function to synchronize output to the X display. */

EXPORT(sqInt) primitiveFlushDisplay(void) {
	synchronizeXDisplay();
}


/*	Answer a string containing the name for the X display, or nil if the display was opened
	using the $DISPLAY environment variable. This answers the name of the X display as of
	the time it was last opened, which may be different from the current setting of $DISPLAY. */

EXPORT(sqInt) primitiveGetDisplayName(void) {
    extern char *displayName;

	if (displayName == 0) {
		interpreterProxy->pop(1);
		interpreterProxy->push(interpreterProxy->nilObject());
	} else {
		interpreterProxy->pop(1);
		interpreterProxy->push(stringFromCString(displayName));
	}
}


/*	Answer true if VM is currently connected to an X server. */

EXPORT(sqInt) primitiveIsConnectedToDisplay(void) {
    extern int isConnectedToXServer;

	if (isConnectedToXServer != 0) {
		interpreterProxy->pop(1);
		interpreterProxy->push(interpreterProxy->trueObject());
	} else {
		interpreterProxy->pop(1);
		interpreterProxy->push(interpreterProxy->falseObject());
	}
}


/*	Call an internal function to disconnect the X display session and destroy
	the Squeak window on the X display. */

EXPORT(sqInt) primitiveKillDisplay(void) {
	if (!((sandboxSecurity()) == 1)) {
		disconnectXDisplay();
	}
}


/*	Answer a string containing the module name string for this plugin. */

EXPORT(sqInt) primitiveModuleName(void) {
	interpreterProxy->popthenPush(1, stringFromCString(moduleName));
}


/*	Call an internal function which will open the X display session. */

EXPORT(sqInt) primitiveOpenDisplay(void) {
	if (!((sandboxSecurity()) == 1)) {
		openXDisplay();
	}
}


/*	Set the name for the X display for use in the next call to primitiveOpenXDisplay. Expects
	one parameter which must be either a String or nil. */

EXPORT(sqInt) primitiveSetDisplayName(void) {
    extern char *displayName;
    static char nameBuffer[501];
    sqInt name;
    char * namePtr;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		name = interpreterProxy->stackObjectValue(0);
		if (name == (interpreterProxy->nilObject())) {
			displayName = 0;
		} else {
			namePtr = transientCStringFromString(name);
			strncpy(nameBuffer, namePtr, 500);
			nameBuffer[500] = 0;
			displayName = nameBuffer;
		}
		interpreterProxy->pop(1);
	}
}


/*	Answer a string containing the version string for this plugin. */

EXPORT(sqInt) primitiveVersionString(void) {
	interpreterProxy->pop(1);
	interpreterProxy->push(stringFromCString(versionString()));
}


/*	Answer 1 if running in secure mode, else 0. The osprocessSandboxSecurity
	variable is initialized to -1. On the first call to this method, set its value to
	either 0 (user has full access to the plugin) or 1 (user is not permitted to do
	dangerous things). */

static sqInt sandboxSecurity(void) {
	if (osprocessSandboxSecurity < 0) {
		osprocessSandboxSecurity = securityHeurisitic();
	}
	return osprocessSandboxSecurity;
}


/*	Answer 0 to permit full access to OSProcess functions, or 1 if access should be
	restricted for dangerous functions. The rules are:
		- If the security plugin is not present, grant full access
		- If the security plugin can be loaded, restrict access unless user has all
		  of secCanWriteImage, secHasFileAccess and secHasSocketAccess */
/*	FIXME: This function has not been tested. -dtl */
/*	If the security plugin can be loaded, use it to check. If not, assume it's ok */

static sqInt securityHeurisitic(void) {
    sqInt hasSocketAccess;
    void (*sHSAfn)(void);
    sqInt canWriteImage;
    void (*sCWIfn)(void);
    void (*sHFAfn)(void);
    sqInt hasFileAccess;

	sCWIfn = interpreterProxy->ioLoadFunctionFrom("secCanWriteImage", "SecurityPlugin");
	if (sCWIfn == 0) {
		return 0;
	}
	canWriteImage =  ((int (*) (void)) sCWIfn)();
	sHFAfn = interpreterProxy->ioLoadFunctionFrom("secHasFileAccess", "SecurityPlugin");
	if (sHFAfn == 0) {
		return 0;
	}
	hasFileAccess =  ((int (*) (void)) sHFAfn)();
	sHSAfn = interpreterProxy->ioLoadFunctionFrom("secHasSocketAccess", "SecurityPlugin");
	if (sHSAfn == 0) {
		return 0;
	}
	hasSocketAccess =  ((int (*) (void)) sHSAfn)();
	if ((canWriteImage && (hasFileAccess)) && (hasSocketAccess)) {
		return 0;
	} else {
		return 1;
	}
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


/*	Answer a new null-terminated C string copied from aString.
	The string is allocated in object memory, and will be moved
	without warning by the garbage collector. Any C pointer
	reference the the result is valid only until the garbage
	collector next runs. Therefore, this method should only be used
	within a single primitive in a section of code in which the
	garbage collector is guaranteed not to run. Note also that
	this method may itself invoke the garbage collector prior
	to allocating the new C string.

	Warning: The result of this method will be invalidated by the
	next garbage collection, including a GC triggered by creation
	of a new object within a primitive. Do not call this method
	twice to obtain two string pointers. */

static char * transientCStringFromString(sqInt aString) {
    sqInt len;
    char *cString;
    char *stringPtr;
    sqInt newString;


	/* Allocate space for a null terminated C string. */

	len = interpreterProxy->sizeOfSTArrayFromCPrimitive(interpreterProxy->arrayValueOf(aString));
	interpreterProxy->pushRemappableOop(aString);
	newString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len + 1);
	stringPtr = interpreterProxy->arrayValueOf(interpreterProxy->popRemappableOop());

	/* Point to the actual C string. */

	cString = interpreterProxy->arrayValueOf(newString);
	(char *)strncpy(cString, stringPtr, len);
	cString[len] = 0;
	return cString;
}


/*	Answer a string containing the version string for this plugin. Handle MNU
	errors, which can occur if class InterpreterPlugin has been removed from
	the system.

	Important: When this method is changed, the class side method must also be
	changed to match. */
/*	2.0 supports 64bit code base */

static char * versionString(void) {
    static char version[]= "2.1.4";

	return version;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* XDisplayControlPlugin_exports[][3] = {
	{"XDisplayControlPlugin", "primitiveGetDisplayName", (void*)primitiveGetDisplayName},
	{"XDisplayControlPlugin", "shutdownModule", (void*)shutdownModule},
	{"XDisplayControlPlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"XDisplayControlPlugin", "primitiveSetDisplayName", (void*)primitiveSetDisplayName},
	{"XDisplayControlPlugin", "primitiveDisconnectDisplay", (void*)primitiveDisconnectDisplay},
	{"XDisplayControlPlugin", "primitiveFlushDisplay", (void*)primitiveFlushDisplay},
	{"XDisplayControlPlugin", "setInterpreter", (void*)setInterpreter},
	{"XDisplayControlPlugin", "primitiveOpenDisplay", (void*)primitiveOpenDisplay},
	{"XDisplayControlPlugin", "primitiveCanConnectToDisplay", (void*)primitiveCanConnectToDisplay},
	{"XDisplayControlPlugin", "getModuleName", (void*)getModuleName},
	{"XDisplayControlPlugin", "initialiseModule", (void*)initialiseModule},
	{"XDisplayControlPlugin", "primitiveKillDisplay", (void*)primitiveKillDisplay},
	{"XDisplayControlPlugin", "primitiveModuleName", (void*)primitiveModuleName},
	{"XDisplayControlPlugin", "primitiveIsConnectedToDisplay", (void*)primitiveIsConnectedToDisplay},
	{"XDisplayControlPlugin", "primitiveVersionString", (void*)primitiveVersionString},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

