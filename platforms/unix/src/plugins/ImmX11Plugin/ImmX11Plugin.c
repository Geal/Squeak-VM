/* Automatically generated from Squeak on an Array(26 August 2009 10:01:58 pm)
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
#include <locale.h>
#include "sqUnixMain.h"
#include "sqUnixCharConv.h"
extern char *setLocale(char *, size_t);
extern int setCompositionWindowPosition(int, int);
extern int setCompostionFocus(int);

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
EXPORT(sqInt) primGetEncoding(void);
EXPORT(sqInt) primGetLocale(void);
EXPORT(sqInt) primGetLocaleEncoding(void);
EXPORT(sqInt) primGetPathEnc(void);
EXPORT(sqInt) primGetTextEnc(void);
EXPORT(sqInt) primGetXWinEnc(void);
EXPORT(sqInt) primIsTextEncUTF8(void);
EXPORT(sqInt) primSetCompositionFocus(void);
EXPORT(sqInt) primSetCompositionWindowPosition(void);
EXPORT(sqInt) primSetEncoding(void);
EXPORT(sqInt) primSetEncodingToLocale(void);
EXPORT(sqInt) primSetLocale(void);
EXPORT(sqInt) primSetLocaleEncoding(void);
EXPORT(sqInt) primSetPathEnc(void);
EXPORT(sqInt) primSetPathEncToLocale(void);
EXPORT(sqInt) primSetTextEnc(void);
EXPORT(sqInt) primSetTextEncToLocale(void);
EXPORT(sqInt) primSetTextEncUTF8(void);
EXPORT(sqInt) primSetXWinEnc(void);
EXPORT(sqInt) primSetXWinEncToLocale(void);
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
	"ImmX11Plugin 26 August 2009 (i)"
#else
	"ImmX11Plugin 26 August 2009 (e)"
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
	return 1;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primGetEncoding(void) {
	int len;
	sqInt ret;
	char * array;

	len = strlen(sqTextEncoding);
	ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
	array = ((char *) (interpreterProxy->firstIndexableField(ret)));
	strncpy(array, (char *)sqTextEncoding, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primGetLocale(void) {
	int len;
	char * locale;
	sqInt ret;
	char * array;

	locale = setlocale(LC_CTYPE, "");
	if (locale) {
		len = strlen(locale);
		ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
		array = ((char *) (interpreterProxy->firstIndexableField(ret)));
		strncpy(array, (char *)locale, len);
	} else {
		ret = interpreterProxy->nilObject();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primGetLocaleEncoding(void) {
	int len;
	sqInt ret;
	char * array;

	if ((int) localeEncoding) {
		len = strlen(localeEncoding);
		ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
		array = ((char *) (interpreterProxy->firstIndexableField(ret)));
		strncpy(array, (char *)localeEncoding, len);
	} else {
		ret = interpreterProxy->nilObject();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primGetPathEnc(void) {
	int len;
	sqInt ret;
	char * array;

	len = strlen(uxPathEncoding);
	ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
	array = ((char *) (interpreterProxy->firstIndexableField(ret)));
	strncpy(array, (char *)uxPathEncoding, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primGetTextEnc(void) {
	int len;
	sqInt ret;
	char * array;

	len = strlen(uxTextEncoding);
	ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
	array = ((char *) (interpreterProxy->firstIndexableField(ret)));
	strncpy(array, (char *)uxTextEncoding, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primGetXWinEnc(void) {
	int len;
	sqInt ret;
	char * array;

	len = strlen(uxXWinEncoding);
	ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
	array = ((char *) (interpreterProxy->firstIndexableField(ret)));
	strncpy(array, (char *)uxXWinEncoding, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primIsTextEncUTF8(void) {
	sqInt _return_value;

	_return_value = ((textEncodingUTF8)? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primSetCompositionFocus(void) {
	sqInt ret;
	sqInt bool;
	sqInt _return_value;

	bool = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	ret = setCompositionFocus(bool);
	if (ret == 0) {
		interpreterProxy->primitiveFail();
		return null;
	}
	_return_value = (ret? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primSetCompositionWindowPosition(void) {
	sqInt ret;
	sqInt x;
	sqInt y;
	sqInt _return_value;

	x = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	ret = setCompositionWindowPosition(x, y);
	if (ret == 0) {
		interpreterProxy->primitiveFail();
		return null;
	}
	_return_value = (ret? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primSetEncoding(void) {
	size_t len;
	char * name;
	sqInt encoding;

	encoding = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = interpreterProxy->stSizeOf(encoding);
	name = ((char *) (interpreterProxy->firstIndexableField(encoding)));
	setNEncoding(&sqTextEncoding, name, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, encoding);
	return null;
}

EXPORT(sqInt) primSetEncodingToLocale(void) {
	sqInt ret;

	if ((int) localeEncoding) {
		sqTextEncoding = (void *)localeEncoding;
		ret = interpreterProxy->trueObject();
	} else {
		ret = interpreterProxy->falseObject();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primSetLocale(void) {
	size_t len;
	char * name;
	sqInt ret;
	char * array;
	sqInt locale;
	sqInt _return_value;

	locale = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = interpreterProxy->stSizeOf(locale);
	name = ((char *) (interpreterProxy->arrayValueOf(locale)));
	name = setLocale(name, len);
	if ((int) name) {
		len = strlen(name);
		ret = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
		array = ((char *) (interpreterProxy->firstIndexableField(ret)));
		strncpy(array, (char *)name, len);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, ret);
		return null;
	} else {
		_return_value = interpreterProxy->nilObject();
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
}

EXPORT(sqInt) primSetLocaleEncoding(void) {
	size_t len;
	char * name;
	sqInt encoding;

	encoding = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = interpreterProxy->stSizeOf(encoding);
	name = ((char *) (interpreterProxy->firstIndexableField(encoding)));
	setNEncoding(&localeEncoding, name, len);
	sqTextEncoding= uxTextEncoding= uxPathEncoding= uxXWinEncoding= localeEncoding;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, encoding);
	return null;
}

EXPORT(sqInt) primSetPathEnc(void) {
	size_t len;
	char * name;
	sqInt encoding;

	encoding = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = interpreterProxy->stSizeOf(encoding);
	name = ((char *) (interpreterProxy->firstIndexableField(encoding)));
	setNEncoding(&uxPathEncoding, name, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, encoding);
	return null;
}

EXPORT(sqInt) primSetPathEncToLocale(void) {
	sqInt ret;

	if ((int) localeEncoding) {
		uxPathEncoding = (void *)localeEncoding;
		ret = interpreterProxy->trueObject();
	} else {
		ret = interpreterProxy->falseObject();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primSetTextEnc(void) {
	size_t len;
	char * name;
	sqInt encoding;

	encoding = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = interpreterProxy->stSizeOf(encoding);
	name = ((char *) (interpreterProxy->firstIndexableField(encoding)));
	setNEncoding(&uxTextEncoding, name, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, encoding);
	return null;
}

EXPORT(sqInt) primSetTextEncToLocale(void) {
	sqInt ret;

	if ((int) localeEncoding) {
		uxTextEncoding = (void *)localeEncoding;
		ret = interpreterProxy->trueObject();
	} else {
		ret = interpreterProxy->falseObject();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
	return null;
}

EXPORT(sqInt) primSetTextEncUTF8(void) {
	sqInt bool;
	sqInt _return_value;

	bool = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	textEncodingUTF8 = bool;
	_return_value = (bool? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primSetXWinEnc(void) {
	size_t len;
	char * name;
	sqInt encoding;

	encoding = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = interpreterProxy->stSizeOf(encoding);
	name = ((char *) (interpreterProxy->firstIndexableField(encoding)));
	setNEncoding(&uxXWinEncoding, name, len);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, encoding);
	return null;
}

EXPORT(sqInt) primSetXWinEncToLocale(void) {
	sqInt ret;

	if ((int) localeEncoding) {
		uxXWinEncoding = (void *)localeEncoding;
		ret = interpreterProxy->trueObject();
	} else {
		ret = interpreterProxy->falseObject();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, ret);
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
	return 1;
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* ImmX11Plugin_exports[][3] = {
	{"ImmX11Plugin", "primSetTextEnc", (void*)primSetTextEnc},
	{"ImmX11Plugin", "primSetTextEncToLocale", (void*)primSetTextEncToLocale},
	{"ImmX11Plugin", "shutdownModule", (void*)shutdownModule},
	{"ImmX11Plugin", "primGetLocaleEncoding", (void*)primGetLocaleEncoding},
	{"ImmX11Plugin", "primSetEncodingToLocale", (void*)primSetEncodingToLocale},
	{"ImmX11Plugin", "setInterpreter", (void*)setInterpreter},
	{"ImmX11Plugin", "primGetEncoding", (void*)primGetEncoding},
	{"ImmX11Plugin", "primGetLocale", (void*)primGetLocale},
	{"ImmX11Plugin", "primSetLocale", (void*)primSetLocale},
	{"ImmX11Plugin", "primSetXWinEnc", (void*)primSetXWinEnc},
	{"ImmX11Plugin", "getModuleName", (void*)getModuleName},
	{"ImmX11Plugin", "primGetXWinEnc", (void*)primGetXWinEnc},
	{"ImmX11Plugin", "primSetEncoding", (void*)primSetEncoding},
	{"ImmX11Plugin", "primSetCompositionFocus", (void*)primSetCompositionFocus},
	{"ImmX11Plugin", "primSetXWinEncToLocale", (void*)primSetXWinEncToLocale},
	{"ImmX11Plugin", "initialiseModule", (void*)initialiseModule},
	{"ImmX11Plugin", "primSetPathEncToLocale", (void*)primSetPathEncToLocale},
	{"ImmX11Plugin", "primIsTextEncUTF8", (void*)primIsTextEncUTF8},
	{"ImmX11Plugin", "primSetTextEncUTF8", (void*)primSetTextEncUTF8},
	{"ImmX11Plugin", "primGetPathEnc", (void*)primGetPathEnc},
	{"ImmX11Plugin", "primSetCompositionWindowPosition", (void*)primSetCompositionWindowPosition},
	{"ImmX11Plugin", "primSetLocaleEncoding", (void*)primSetLocaleEncoding},
	{"ImmX11Plugin", "primSetPathEnc", (void*)primSetPathEnc},
	{"ImmX11Plugin", "primGetTextEnc", (void*)primGetTextEnc},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

