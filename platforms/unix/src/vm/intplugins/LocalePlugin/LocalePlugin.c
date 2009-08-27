/* Automatically generated from Squeak on an Array(26 August 2009 10:01:20 pm)
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
#include "LocalePlugin.h"

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
EXPORT(sqInt) primitiveCountry(void);
EXPORT(sqInt) primitiveCurrencyNotation(void);
EXPORT(sqInt) primitiveCurrencySymbol(void);
EXPORT(sqInt) primitiveDaylightSavings(void);
EXPORT(sqInt) primitiveDecimalSymbol(void);
EXPORT(sqInt) primitiveDigitGroupingSymbol(void);
EXPORT(sqInt) primitiveLanguage(void);
EXPORT(sqInt) primitiveLongDateFormat(void);
EXPORT(sqInt) primitiveMeasurementMetric(void);
EXPORT(sqInt) primitiveShortDateFormat(void);
EXPORT(sqInt) primitiveTimeFormat(void);
EXPORT(sqInt) primitiveTimezoneOffset(void);
EXPORT(sqInt) primitiveVMOffsetToUTC(void);
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
	"LocalePlugin 26 August 2009 (i)"
#else
	"LocalePlugin 26 August 2009 (e)"
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
	return sqLocInitialize();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	return a 3 char string describing the country in use. ISO 3166 is the relevant source here; see http://www.unicode.org/onlinedat/countries.html for details. Using the 3 character Alpha-3 codes */

EXPORT(sqInt) primitiveCountry(void) {
	sqInt oop;

	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), 3);
	sqLocGetCountryInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a boolean specifying whether the currency symbol is pre or post fix. true -> pre */

EXPORT(sqInt) primitiveCurrencyNotation(void) {
	sqInt _return_value;

	_return_value = ((sqLocCurrencyNotation())? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	return a string describing the currency symbol used 
Still need to find details on standard symbols - ISO 4217 is supposed to be it but cannot find on web */

EXPORT(sqInt) primitiveCurrencySymbol(void) {
	sqInt oop;
	sqInt length;

	length = sqLocCurrencySymbolSize();
	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), length);
	sqLocGetCurrencySymbolInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a boolean specifying the DST setting. true -> active */

EXPORT(sqInt) primitiveDaylightSavings(void) {
	sqInt _return_value;

	_return_value = ((sqLocDaylightSavings())? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	return a 1 char string describing the decimal symbol used - usually a . or a , */

EXPORT(sqInt) primitiveDecimalSymbol(void) {
	sqInt oop;

	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), 1);
	sqLocGetDecimalSymbolInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a 1 char string describing the digitGrouping symbol used - usually a . or a , between triples of digits */

EXPORT(sqInt) primitiveDigitGroupingSymbol(void) {
	sqInt oop;

	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), 1);
	sqLocGetDigitGroupingSymbolInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a 3 char string describing the language in use. ISO 639 is the relevant source here; see http://www.w3.org/WAI/ER/IG/ert/iso639.html for details */

EXPORT(sqInt) primitiveLanguage(void) {
	sqInt oop;

	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), 3);
	sqLocGetLanguageInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a string describing the long date formatting.
Format is made up of
d day, m month, y year,
double symbol is null padded, single not padded (m=6, mm=06)
dddd weekday
mmmm month name
 */

EXPORT(sqInt) primitiveLongDateFormat(void) {
	sqInt oop;
	sqInt length;

	length = sqLocLongDateFormatSize();
	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), length);
	sqLocGetLongDateFormatInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a boolean specifying whether the currency symbol is pre or post fix. true -> pre */

EXPORT(sqInt) primitiveMeasurementMetric(void) {
	sqInt _return_value;

	_return_value = ((sqLocMeasurementMetric())? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	return a string describing the long date formatting.
Format is made up of
d day, m month, y year,
double symbol is null padded, single not padded (m=6, mm=06)
dddd weekday
mmmm month name
 */

EXPORT(sqInt) primitiveShortDateFormat(void) {
	sqInt oop;
	sqInt length;

	length = sqLocShortDateFormatSize();
	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), length);
	sqLocGetShortDateFormatInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return a string describing the time formatting.
Format is made up of
h hour (h 12, H 24), m minute, s seconds, x (am/pm String)
double symbol is null padded, single not padded (h=6, hh=06) */

EXPORT(sqInt) primitiveTimeFormat(void) {
	sqInt oop;
	sqInt length;

	length = sqLocTimeFormatSize();
	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), length);
	sqLocGetTimeFormatInto(interpreterProxy->firstIndexableField(oop));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, oop);
	return null;
}


/*	return the number of minutes this VM's time value is offset from UTC */

EXPORT(sqInt) primitiveTimezoneOffset(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sqLocGetTimezoneOffset()));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	return the number of minutes this VM's time value is offset from UTC */

EXPORT(sqInt) primitiveVMOffsetToUTC(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sqLocGetVMOffsetToUTC()));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
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

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* LocalePlugin_exports[][3] = {
	{"LocalePlugin", "primitiveDaylightSavings", (void*)primitiveDaylightSavings},
	{"LocalePlugin", "primitiveLanguage", (void*)primitiveLanguage},
	{"LocalePlugin", "setInterpreter", (void*)setInterpreter},
	{"LocalePlugin", "primitiveCurrencyNotation", (void*)primitiveCurrencyNotation},
	{"LocalePlugin", "getModuleName", (void*)getModuleName},
	{"LocalePlugin", "primitiveShortDateFormat", (void*)primitiveShortDateFormat},
	{"LocalePlugin", "primitiveDigitGroupingSymbol", (void*)primitiveDigitGroupingSymbol},
	{"LocalePlugin", "primitiveCurrencySymbol", (void*)primitiveCurrencySymbol},
	{"LocalePlugin", "primitiveTimezoneOffset", (void*)primitiveTimezoneOffset},
	{"LocalePlugin", "primitiveLongDateFormat", (void*)primitiveLongDateFormat},
	{"LocalePlugin", "primitiveCountry", (void*)primitiveCountry},
	{"LocalePlugin", "primitiveDecimalSymbol", (void*)primitiveDecimalSymbol},
	{"LocalePlugin", "primitiveMeasurementMetric", (void*)primitiveMeasurementMetric},
	{"LocalePlugin", "initialiseModule", (void*)initialiseModule},
	{"LocalePlugin", "primitiveTimeFormat", (void*)primitiveTimeFormat},
	{"LocalePlugin", "primitiveVMOffsetToUTC", (void*)primitiveVMOffsetToUTC},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

