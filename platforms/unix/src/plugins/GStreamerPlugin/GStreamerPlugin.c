/* Automatically generated from Squeak on an Array(26 August 2009 10:01:52 pm)
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
#include <gst/gst.h>
#include <gst/controller/gstcontroller.h>
#include "squeakAudioVideoPipeLineSignalInterface.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static sqInt cbnewpad(sqInt element, sqInt newPad, sqInt  *data);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt initialiseModule(void);
static sqInt msg(char * s);
static sqInt positive64BitIntegerForOverride(sqLong integerValue);
#pragma export on
EXPORT(sqInt) primitiveSqueakSinkAllocate(void);
EXPORT(sqInt) primitiveSqueakSinkAudioGetData(void);
EXPORT(sqInt) primitiveSqueakSinkFree(void);
EXPORT(sqInt) primitiveSqueakSinkGetFrameRateDenominator(void);
EXPORT(sqInt) primitiveSqueakSinkGetFrameRateNumerator(void);
EXPORT(sqInt) primitiveSqueakSinkGetHeight(void);
EXPORT(sqInt) primitiveSqueakSinkGetWidth(void);
EXPORT(sqInt) primitiveSqueakSinkVideo(void);
EXPORT(sqInt) primitiveSqueakSrc(void);
EXPORT(sqInt) primitiveSqueakSrcWithTime(void);
EXPORT(sqInt) primitiveSqueakSrcAllocate(void);
EXPORT(sqInt) primitivecallbacksignalseenfor(void);
EXPORT(sqInt) primitivegetinterpreterproxy(void);
EXPORT(sqInt) primitivegetoop(void);
EXPORT(sqInt) primitivegobjectclasslistproperties(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyboolatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertydoubleatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyenumatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyfloatatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyintatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertylongatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertylonglongatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertymetaDataatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertypointeratIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertystringatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyuintatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyulongatIndex(void);
EXPORT(sqInt) primitivegobjectclasslistpropertyulonglongatIndex(void);
EXPORT(sqInt) primitivegobjectfree(void);
EXPORT(sqInt) primitivegobjectgetboolfrom(void);
EXPORT(sqInt) primitivegobjectgetdoublefrom(void);
EXPORT(sqInt) primitivegobjectgetfloatfrom(void);
EXPORT(sqInt) primitivegobjectgetlongfrom(void);
EXPORT(sqInt) primitivegobjectgetlonglongfrom(void);
EXPORT(sqInt) primitivegobjectgetpointerfrom(void);
EXPORT(sqInt) primitivegobjectgetsmalltalkobject(void);
EXPORT(sqInt) primitivegobjectgetstringfrom(void);
EXPORT(sqInt) primitivegobjectgetulongfrom(void);
EXPORT(sqInt) primitivegobjectgetulonglongfrom(void);
EXPORT(sqInt) primitivegobjectsetboolon(void);
EXPORT(sqInt) primitivegobjectsetdoubleon(void);
EXPORT(sqInt) primitivegobjectsetfloaton(void);
EXPORT(sqInt) primitivegobjectsetlonglongon(void);
EXPORT(sqInt) primitivegobjectsetlongon(void);
EXPORT(sqInt) primitivegobjectsetpointeron(void);
EXPORT(sqInt) primitivegobjectsetstringon(void);
EXPORT(sqInt) primitivegobjectsetulonglongon(void);
EXPORT(sqInt) primitivegobjectsetulongon(void);
EXPORT(sqInt) primitivegsignalconnect(void);
EXPORT(sqInt) primitivegstbinadd(void);
EXPORT(sqInt) primitivegstbinnew(void);
EXPORT(sqInt) primitivegstbushavepending(void);
EXPORT(sqInt) primitivegstbuspeek(void);
EXPORT(sqInt) primitivegstbuspop(void);
EXPORT(sqInt) primitivegstbuspopfilter(void);
EXPORT(sqInt) primitivegstcapsfromstring(void);
EXPORT(sqInt) primitivegstcapstostring(void);
EXPORT(sqInt) primitivegstelementadd(void);
EXPORT(sqInt) primitivegstelementfactorycreate(void);
EXPORT(sqInt) primitivegstelementfactoryfind(void);
EXPORT(sqInt) primitivegstelementfactorygetauthor(void);
EXPORT(sqInt) primitivegstelementfactorygetdescription(void);
EXPORT(sqInt) primitivegstelementfactorygetklass(void);
EXPORT(sqInt) primitivegstelementfactorygetlongname(void);
EXPORT(sqInt) primitivegstelementfactorygeturitype(void);
EXPORT(sqInt) primitivegstelementfactorymake(void);
EXPORT(sqInt) primitivegstelementgetcompatiblepad(void);
EXPORT(sqInt) primitivegstelementgetrequestpad(void);
EXPORT(sqInt) primitivegstelementgetstate(void);
EXPORT(sqInt) primitivegstelementgetstaticpad(void);
EXPORT(sqInt) primitivegstelementgsignalconnect(void);
EXPORT(sqInt) primitivegstelementlink(void);
EXPORT(sqInt) primitivegstelementlinkfiltered(void);
EXPORT(sqInt) primitivegstelementqueryconvert(void);
EXPORT(sqInt) primitivegstelementqueryduration(void);
EXPORT(sqInt) primitivegstelementqueryposition(void);
EXPORT(sqInt) primitivegstelementreleaserequestpad(void);
EXPORT(sqInt) primitivegstelementseek(void);
EXPORT(sqInt) primitivegstelementseeksimple(void);
EXPORT(sqInt) primitivegstelementsetstate(void);
EXPORT(sqInt) primitivegstghostpadnew(void);
EXPORT(sqInt) primitivegstinitcheck(void);
EXPORT(sqInt) primitivegstmessageparsebuffering(void);
EXPORT(sqInt) primitivegstmessageparseduration(void);
EXPORT(sqInt) primitivegstmessageparseerror(void);
EXPORT(sqInt) primitivegstmessageparseinfo(void);
EXPORT(sqInt) primitivegstmessageparsesegmentdone(void);
EXPORT(sqInt) primitivegstmessageparsesegmentstart(void);
EXPORT(sqInt) primitivegstmessageparsestatechanged(void);
EXPORT(sqInt) primitivegstmessageparsewarning(void);
EXPORT(sqInt) primitivegstmessagesrc(void);
EXPORT(sqInt) primitivegstmessagetypestring(void);
EXPORT(sqInt) primitivegstmessageunref(void);
EXPORT(sqInt) primitivegstobjectunref(void);
EXPORT(sqInt) primitivegstpadacceptcaps(void);
EXPORT(sqInt) primitivegstpadgetcaps(void);
EXPORT(sqInt) primitivegstpadgetparentelement(void);
EXPORT(sqInt) primitivegstpadlink(void);
EXPORT(sqInt) primitivegstpadsetactive(void);
EXPORT(sqInt) primitivegstpadsetcaps(void);
EXPORT(sqInt) primitivegstpipelineautoclock(void);
EXPORT(sqInt) primitivegstpipelinegetautoflushbus(void);
EXPORT(sqInt) primitivegstpipelinegetbus(void);
EXPORT(sqInt) primitivegstpipelinegetclock(void);
EXPORT(sqInt) primitivegstpipelinegetdelay(void);
EXPORT(sqInt) primitivegstpipelinegetlaststreamtime(void);
EXPORT(sqInt) primitivegstpipelinenew(void);
EXPORT(sqInt) primitivegstpipelinesetautoflushbus(void);
EXPORT(sqInt) primitivegstpipelinesetclock(void);
EXPORT(sqInt) primitivegstpipelinesetdelay(void);
EXPORT(sqInt) primitivegstpipelinesetnewstreamtime(void);
EXPORT(sqInt) primitivegstpipelineuseclock(void);
EXPORT(sqInt) primitivegstregistryforksetenabled(void);
EXPORT(sqInt) primitivegstsegtrapisenabled(void);
EXPORT(sqInt) primitivegstsegtrapsetenabled(void);
EXPORT(sqInt) primitivegstversionstring(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
static sqInt shutdownModule(void);
static sqInt signed32BitValueOfOverride(sqInt oop);
static sqInt signed64BitIntegerForOverride(sqLong integerValue);
static sqLong signed64BitValueOfOverride(sqInt oop);
static sqInt sqAssert(sqInt aBool);
static sqInt stringFromCString(const char * aCString);
/*** Variables ***/
static gboolean callbackForPadHookupElement[128];

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"GStreamerPlugin 26 August 2009 (i)"
#else
	"GStreamerPlugin 26 August 2009 (e)"
#endif
;



/*	Ok the trick here is on the signal pad_add we may have multiple pads being created.
	Therefore we must find the sink pad that can handle the request. Note for ogg you could have the 
	audio and video stream for example */

static sqInt cbnewpad(sqInt element, sqInt newPad, sqInt  *data) {
	GstCaps*  gstCapsValue;
	sqInt result;
	sqInt i;
	GstPad*  gstPadValue;
	sqInt max;

	max = data[0];
	gstCapsValue = null;
	gstPadValue = null;
	;
	;
	result = 0;
	for (i = 1; i <= max; i += 1) {
		gstPadValue = ((GstPad*) (data[i]));
		gstCapsValue = gst_pad_get_caps (newPad);
		result =  gst_pad_accept_caps (gstPadValue, gstCapsValue);
		if (result) {
			if (i < 128) {
				callbackForPadHookupElement[i] = 1;
			}
			gst_pad_link (newPad, gstPadValue);
			return null;
		}
	}
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


/*	Initialise the module */

static sqInt initialiseModule(void) {
	return 1;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

static sqInt positive64BitIntegerForOverride(sqLong integerValue) {
	sqInt highWord;
	sqInt value;
	unsigned char * where;
	sqInt i;
	sqInt newLargeInteger;
	sqInt sz;

	if ((sizeof(integerValue)) == 4) {
		return interpreterProxy->positive32BitIntegerFor(integerValue);
	}

	/* shift is coerced to usqInt otherwise */

	highWord = integerValue >> 32;
	if (highWord == 0) {
		return interpreterProxy->positive32BitIntegerFor(integerValue);
	}
	sz = 5;
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	newLargeInteger = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classLargePositiveInteger(), sz);
	where = interpreterProxy->firstIndexableField(newLargeInteger);
	for (i = 0; i <= (sz - 1); i += 1) {
		value = (integerValue >> (i * 8)) & 255;
		where[i] = value;
	}
	return newLargeInteger;
}

EXPORT(sqInt) primitiveSqueakSinkAllocate(void) {
	SqueakAudioVideoSinkPtr squeaker;
	GstElement*  gstElement;
	sqInt type;
	sqInt semaphoreIndex;
	sqInt gstElementOoop;
	sqInt _return_value;

	type = interpreterProxy->stackIntegerValue(2);
	semaphoreIndex = interpreterProxy->stackIntegerValue(1);
	gstElementOoop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	squeaker = 0;
	
		squeaker = g_malloc0(sizeof(SqueakAudioVideoSink));
		if (type) 
			squeaker->handler = squeakVideoHandOff;
		else
			squeaker->handler = squeakAudioHandOff;
		squeaker->owner = gstElement;
		squeaker->interpreterProxy = interpreterProxy;
		squeaker->semaphoreIndexForSink = semaphoreIndex;
		squeaker->prerollCounter = 5;
	;
	;
	_return_value = interpreterProxy->positive32BitIntegerFor(squeaker);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkAudioGetData(void) {
	SqueakAudioVideoSinkPtr  sink;
	sqInt newBytes;
	sqInt aSqueakSinkObject;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sink = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	newBytes = 0;
	;
	
	GST_LOCK(sink->owner);
	if (sink->copyToSendToSqueakAudio && GST_BUFFER_DATA(sink->copyToSendToSqueakAudio) 
		&& GST_BUFFER_OFFSET_END(sink->copyToSendToSqueakAudio)) {
		
	/* Got data, yes lets move that into Squeak object space */ 
	/* Also turn the semaphore off */
			
		newBytes = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), 
			GST_BUFFER_OFFSET_END(sink->copyToSendToSqueakAudio));
		if (newBytes) 
			memcpy(interpreterProxy->arrayValueOf(newBytes), GST_BUFFER_DATA(sink->copyToSendToSqueakAudio),
				 GST_BUFFER_OFFSET_END(sink->copyToSendToSqueakAudio));
		GST_BUFFER_OFFSET_END(sink->copyToSendToSqueakAudio) = 0;
	}

	sink->semaphoreWasSignaled = 0;
	GST_UNLOCK(sink->owner);
	if (newBytes == 0) {
		_return_value = interpreterProxy->nilObject();
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, newBytes);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkFree(void) {
	SqueakAudioVideoSinkPtr  squeakSinkObject;
	sqInt aSqueakSinkObject;

	aSqueakSinkObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	squeakSinkObject = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	if (squeakSinkObject-> copyToSendToSqueakAudio) gst_buffer_unref(squeakSinkObject-> copyToSendToSqueakAudio);
		if (squeakSinkObject-> copyToSendToSqueakVideo) g_free(squeakSinkObject->copyToSendToSqueakVideo); 
		g_free(squeakSinkObject);
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkGetFrameRateDenominator(void) {
	sqInt value;
	SqueakAudioVideoSinkPtr  squeakSinkObject;
	sqInt aSqueakSinkObject;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	squeakSinkObject = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	;
	value = 0;
	value = squeakSinkObject->fps_d;
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkGetFrameRateNumerator(void) {
	sqInt value;
	SqueakAudioVideoSinkPtr  squeakSinkObject;
	sqInt aSqueakSinkObject;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	squeakSinkObject = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	;
	value = 0;
	value = squeakSinkObject->fps_n;
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkGetHeight(void) {
	sqInt value;
	SqueakAudioVideoSinkPtr  squeakSinkObject;
	sqInt aSqueakSinkObject;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	squeakSinkObject = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	;
	value = 0;
	value = squeakSinkObject->height;
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkGetWidth(void) {
	sqInt value;
	SqueakAudioVideoSinkPtr  squeakSinkObject;
	sqInt aSqueakSinkObject;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	squeakSinkObject = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	;
	value = 0;
	value = squeakSinkObject->width;
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSinkVideo(void) {
	SqueakAudioVideoSinkPtr  sink;
	sqInt returnValue;
	sqInt aSqueakSinkObject;
	sqInt aBitMap;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(1);
	aBitMap = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sink = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	returnValue = 0;
	;
	
	GST_LOCK(sink->owner);
	if (sink->allocbytes) {
		
	/* Got data, yes lets move that into Squeak object space */ 
	/* Also turn the semaphore off */
		memcpy(interpreterProxy->arrayValueOf(aBitMap), sink->copyToSendToSqueakVideo,sink->allocbytes);
		returnValue = sink->frame_ready;
	}

	sink->semaphoreWasSignaled = 0;
	sink->frame_ready = FALSE;
	GST_UNLOCK(sink->owner);
	_return_value = (returnValue) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSrc(void) {
	sqInt doesFrameExist;
	SqueakAudioVideoSinkPtr  sink;
	sqInt aSqueakSinkObject;
	sqInt data;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(1);
	data = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sink = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	;
	doesFrameExist = 0;
	doesFrameExist = sink->frame_ready;
	if (doesFrameExist) {
		_return_value = (0) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	
	GST_LOCK(sink->owner);
	sink->actualbytes = interpreterProxy->byteSizeOf(data);
	if (sink->allocbytes && (sink->allocbytes >= sink->actualbytes)) {
		memcpy(sink->copyToSendToSqueakVideo,interpreterProxy->arrayValueOf(data),sink->actualbytes);
		sink->frame_ready = TRUE;
	}

	GST_UNLOCK(sink->owner);
	_return_value = (1) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSrcWithTime(void) {
	GstClockTime  startTimeValue;
	GstClockTime  durationValue;
	SqueakAudioVideoSinkPtr  sink;
	sqInt doesFrameExist;
	sqInt aSqueakSinkObject;
	sqInt data;
	sqInt startTime;
	sqInt duration;
	sqInt _return_value;

	aSqueakSinkObject = interpreterProxy->stackValue(3);
	data = interpreterProxy->stackValue(2);
	startTime = interpreterProxy->stackValue(1);
	duration = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	sink = ((SqueakAudioVideoSinkPtr) (interpreterProxy->positive32BitValueOf(aSqueakSinkObject)));
	startTimeValue = ((GstClockTime) (interpreterProxy->positive64BitValueOf(startTime)));
	durationValue = ((GstClockTime) (interpreterProxy->positive64BitValueOf(duration)));
	;
	;
	;
	doesFrameExist = 0;
	doesFrameExist = sink->frame_ready;
	if (doesFrameExist) {
		_return_value = (0) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(5, _return_value);
		return null;
	}
	
	GST_LOCK(sink->owner);
	sink->actualbytes = interpreterProxy->byteSizeOf(data);
	if (sink->allocbytes && (sink->allocbytes >= sink->actualbytes)) {
		memcpy(sink->copyToSendToSqueakVideo,interpreterProxy->arrayValueOf(data),sink->actualbytes);
		sink->frame_ready = TRUE;
		sink->startTime = startTimeValue;
		sink->duration = durationValue;
	}

	GST_UNLOCK(sink->owner);
	_return_value = (1) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSqueakSrcAllocate(void) {
	SqueakAudioVideoSinkPtr squeaker;
	GstElement*  gstElement;
	sqInt numberOfBytes;
	sqInt semaphoreIndex;
	sqInt gstElementOoop;
	sqInt _return_value;

	numberOfBytes = interpreterProxy->stackIntegerValue(2);
	semaphoreIndex = interpreterProxy->stackIntegerValue(1);
	gstElementOoop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	squeaker = 0;
	
		squeaker = g_malloc0(sizeof(SqueakAudioVideoSink));
		squeaker->handler = squeakSrcHandOff;
		squeaker->owner = gstElement;
		squeaker->semaphoreIndexForSink = semaphoreIndex;
		squeaker->copyToSendToSqueakVideo = g_malloc(numberOfBytes);
		squeaker->allocbytes = numberOfBytes;
		squeaker->interpreterProxy = interpreterProxy;
	;
	;
	_return_value = interpreterProxy->positive32BitIntegerFor(squeaker);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}

EXPORT(sqInt) primitivecallbacksignalseenfor(void) {
	gboolean  value;
	sqInt aIndex;
	sqInt _return_value;

	aIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	value = 0;
	if ((aIndex < 1) || (aIndex > 127)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	value = callbackForPadHookupElement[aIndex];
	_return_value = (value) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegetinterpreterproxy(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->positive32BitIntegerFor(interpreterProxy);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitivegetoop(void) {
	void  *oopThing;
	sqInt aHopefullObject;

	aHopefullObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	oopThing = ((void *) (interpreterProxy->positive32BitValueOf(aHopefullObject)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, oopThing);
	return null;
}


/*	Returns an array element 1 is numer of properties, number 2 is array of GParamSpec* for all properties of a class. */

EXPORT(sqInt) primitivegobjectclasslistproperties(void) {
	 GParamSpec **  propertyspecs;
	sqInt numpropertiesOop;
	GstElement*  element;
	sqInt arrayOop;
	guint  numproperties;
	sqInt propertyspecsOop;
	sqInt elementOop;

	elementOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	propertyspecs = null;
	numproperties = 0;
	element = ((GstElement*) (interpreterProxy->positive32BitValueOf(elementOop)));
	propertyspecs = g_object_class_list_properties(G_OBJECT_GET_CLASS (element), &numproperties);;
	;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(numproperties));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(propertyspecs));
	propertyspecsOop = interpreterProxy->popRemappableOop();
	numpropertiesOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, numpropertiesOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, propertyspecsOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyboolatIndex(void) {
	 GParamSpec **  propertyspecs;
	gboolean defaultValue;
	GParamSpecBoolean * pstring;
	sqInt boolValueOop;
	sqInt defaultValueOop;
	sqInt arrayOop;
	GParamSpec * param;
	gboolean boolValue;
	GValue valueType = { 0, };
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	boolValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_BOOLEAN (param);
		defaultValue = pstring->default_value;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	defaultValueOop = (defaultValue) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	interpreterProxy->pushRemappableOop(defaultValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					boolValue = g_value_get_boolean (&valueType);
		boolValueOop = (boolValue) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	} else {
		boolValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(boolValueOop);
	boolValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, boolValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertydoubleatIndex(void) {
	 GParamSpec **  propertyspecs;
	sqInt longValueOop;
	gdouble defaultValue;
	GParamSpecDouble * pstring;
	sqInt doubleValueOop;
	gdouble minimumValue;
	sqInt defaultValueOop;
	sqInt doubleValue;
	sqInt arrayOop;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	gdouble maximumValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	doubleValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_DOUBLE (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = interpreterProxy->floatObjectOf(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = interpreterProxy->floatObjectOf(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = interpreterProxy->floatObjectOf(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					doubleValue = g_value_get_double (&valueType);
		doubleValueOop = interpreterProxy->floatObjectOf(doubleValue);
	} else {
		doubleValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(doubleValueOop);
	longValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, longValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyenumatIndex(void) {
	 GParamSpec **  propertyspecs;
	long longValue;
	sqInt longValueOop;
	long defaultValue;
	GParamSpecEnum * pstring;
	sqInt defaultValueOop;
	sqInt arrayOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	longValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_ENUM (param);
		defaultValue = pstring->default_value;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	defaultValueOop = interpreterProxy->positive32BitIntegerFor(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					longValue = g_value_get_enum (&valueType);
		longValueOop = interpreterProxy->positive32BitIntegerFor(longValue);
	} else {
		longValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(longValueOop);
	longValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, longValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyfloatatIndex(void) {
	 GParamSpec **  propertyspecs;
	gfloat defaultValue;
	gfloat floatValue;
	GParamSpecFloat * pstring;
	gfloat minimumValue;
	sqInt defaultValueOop;
	sqInt arrayOop;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	sqInt floatValueOop;
	gfloat maximumValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	floatValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_FLOAT (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = interpreterProxy->floatObjectOf(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = interpreterProxy->floatObjectOf(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = interpreterProxy->floatObjectOf(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					floatValue = g_value_get_float (&valueType);
		floatValueOop = interpreterProxy->floatObjectOf(floatValue);
	} else {
		floatValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(floatValueOop);
	floatValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, floatValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyintatIndex(void) {
	 GParamSpec **  propertyspecs;
	int intValue;
	int defaultValue;
	GParamSpecInt * pstring;
	int minimumValue;
	sqInt defaultValueOop;
	sqInt arrayOop;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	int maximumValue;
	sqInt maximumValueOop;
	sqInt intValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	intValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_INT (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = interpreterProxy->signed32BitIntegerFor(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = interpreterProxy->signed32BitIntegerFor(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = interpreterProxy->signed32BitIntegerFor(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					intValue = g_value_get_int (&valueType);
		intValueOop = interpreterProxy->signed32BitIntegerFor(intValue);
	} else {
		intValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(intValueOop);
	intValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, intValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertylongatIndex(void) {
	 GParamSpec **  propertyspecs;
	long longValue;
	sqInt longValueOop;
	long defaultValue;
	GParamSpecLong * pstring;
	long minimumValue;
	sqInt defaultValueOop;
	sqInt arrayOop;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	long maximumValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	longValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_LONG (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = interpreterProxy->signed32BitIntegerFor(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = interpreterProxy->signed32BitIntegerFor(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = interpreterProxy->signed32BitIntegerFor(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					longValue = g_value_get_long (&valueType);
		longValueOop = interpreterProxy->signed32BitIntegerFor(longValue);
	} else {
		longValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(longValueOop);
	longValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, longValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertylonglongatIndex(void) {
	 GParamSpec **  propertyspecs;
	long long defaultValue;
	GParamSpecInt64 * pstring;
	long long minimumValue;
	sqInt defaultValueOop;
	sqInt arrayOop;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	long long maximumValue;
	sqInt longlongValueOop;
	long long longlongValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	longlongValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_INT64 (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = signed64BitIntegerForOverride(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = signed64BitIntegerForOverride(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = signed64BitIntegerForOverride(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					longlongValue = g_value_get_int64 (&valueType);
		longlongValueOop = signed64BitIntegerForOverride(longlongValue);
	} else {
		longlongValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(longlongValueOop);
	longlongValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, longlongValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertymetaDataatIndex(void) {
	 GParamSpec **  propertyspecs;
	sqInt nameOop;
	sqInt readwriteOop;
	sqInt valueCode;
	sqInt blurbOop;
	sqInt arrayOop;
	sqInt readwrite;
	 char *  blurb;
	GParamSpec * param;
	GValue valueType = { 0, };
	sqInt valueCodeOop;
	 char *  name;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = 0;
	;
	param = propertyspecs[index];
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	g_value_init (&valueType, param->value_type); 
		valueCode = G_VALUE_TYPE (&valueType);
		name = g_param_spec_get_name (param);
		blurb = g_param_spec_get_blurb (param);;
	nameOop = stringFromCString(name);
	interpreterProxy->pushRemappableOop(nameOop);
	blurbOop = stringFromCString(blurb);
	interpreterProxy->pushRemappableOop(blurbOop);
	readwrite = 0;
	
		if (param->flags & G_PARAM_READABLE) readwrite = 1;
		if (param->flags & G_PARAM_WRITABLE) readwrite = readwrite+2;
		if (param->flags & GST_PARAM_CONTROLLABLE) readwrite = readwrite+4;;
	;
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(readwrite));
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(valueCode));
	valueCodeOop = interpreterProxy->popRemappableOop();
	readwriteOop = interpreterProxy->popRemappableOop();
	blurbOop = interpreterProxy->popRemappableOop();
	nameOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, nameOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, blurbOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, readwriteOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, valueCodeOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertypointeratIndex(void) {
	 GParamSpec **  propertyspecs;
	long defaultValue;
	GParamSpecEnum * pstring;
	sqInt defaultValueOop;
	sqInt pointerValueOop;
	sqInt arrayOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	GObject *pointerValue;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	pointerValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_ENUM (param);
		defaultValue = pstring->default_value;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	defaultValueOop = interpreterProxy->positive32BitIntegerFor(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					pointerValue = g_value_get_pointer (&valueType);
		pointerValueOop = interpreterProxy->positive32BitIntegerFor(pointerValue);
	} else {
		pointerValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(pointerValueOop);
	pointerValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, pointerValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertystringatIndex(void) {
	 GParamSpec **  propertyspecs;
	sqInt readable;
	 gchar *  defaultValue;
	GParamSpecString * pstring;
	sqInt defaultValueOop;
	char *stringValue;
	sqInt arrayOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	sqInt stringValueOop;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	stringValue = null;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_STRING (param);
		defaultValue = pstring->default_value;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	if (defaultValue == 0) {
		defaultValueOop = interpreterProxy->nilObject();
	} else {
		defaultValueOop = stringFromCString(defaultValue);
	}
	interpreterProxy->pushRemappableOop(defaultValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					stringValue = g_value_get_string (&valueType);
		stringValueOop = stringFromCString(stringValue);
	} else {
		stringValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(stringValueOop);
	stringValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, stringValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyuintatIndex(void) {
	 GParamSpec **  propertyspecs;
	unsigned int  defaultValue;
	GParamSpecUInt * pstring;
	unsigned int  minimumValue;
	sqInt defaultValueOop;
	sqInt arrayOop;
	unsigned int uintValue;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	sqInt uintValueOop;
	unsigned int  maximumValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	uintValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_UINT (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = interpreterProxy->positive32BitIntegerFor(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = interpreterProxy->positive32BitIntegerFor(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = interpreterProxy->positive32BitIntegerFor(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					uintValue = g_value_get_uint (&valueType);
		uintValueOop = interpreterProxy->positive32BitIntegerFor(uintValue);
	} else {
		uintValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(uintValueOop);
	uintValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, uintValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyulongatIndex(void) {
	 GParamSpec **  propertyspecs;
	unsigned long  defaultValue;
	GParamSpecULong * pstring;
	unsigned long minimumValue;
	sqInt defaultValueOop;
	sqInt ulongValueOop;
	sqInt arrayOop;
	unsigned long ulongValue;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	unsigned long maximumValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	ulongValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_ULONG (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = interpreterProxy->positive32BitIntegerFor(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = interpreterProxy->positive32BitIntegerFor(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = interpreterProxy->positive32BitIntegerFor(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					ulongValue = g_value_get_ulong (&valueType);
		ulongValueOop = interpreterProxy->positive32BitIntegerFor(ulongValue);
	} else {
		ulongValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(ulongValueOop);
	ulongValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, ulongValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegobjectclasslistpropertyulonglongatIndex(void) {
	 GParamSpec **  propertyspecs;
	unsigned long long defaultValue;
	GParamSpecUInt64 * pstring;
	unsigned long long ulonglongValue;
	sqInt defaultValueOop;
	unsigned long long minimumValue;
	sqInt ulonglongValueOop;
	sqInt arrayOop;
	sqInt minimumValueOop;
	GParamSpec * param;
	GValue valueType = { 0, };
	unsigned long long maximumValue;
	sqInt maximumValueOop;
	sqInt readable;
	sqInt index;
	sqInt propertyspecsOop;

	index = interpreterProxy->stackIntegerValue(1);
	propertyspecsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	defaultValue = 0;
	ulonglongValue = 0;
	param = 0;
	;
	pstring = 0;
	;
	propertyspecs = ((GParamSpec **) (interpreterProxy->positive32BitValueOf(propertyspecsOop)));
	;
	param = propertyspecs[index];
	pstring = G_PARAM_SPEC_UINT64 (param);
		defaultValue = pstring->default_value;
		minimumValue = pstring->minimum;
		maximumValue = pstring->maximum;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
	defaultValueOop = positive64BitIntegerForOverride(defaultValue);
	interpreterProxy->pushRemappableOop(defaultValueOop);
	minimumValueOop = positive64BitIntegerForOverride(minimumValue);
	interpreterProxy->pushRemappableOop(minimumValueOop);
	maximumValueOop = positive64BitIntegerForOverride(maximumValue);
	interpreterProxy->pushRemappableOop(maximumValueOop);
	readable = 0;
	if (param->flags & G_PARAM_READABLE) readable = 1;
	if (readable) {
		g_value_init (&valueType, param->value_type);
					ulonglongValue = g_value_get_uint64 (&valueType);
		ulonglongValueOop = positive64BitIntegerForOverride(ulonglongValue);
	} else {
		ulonglongValueOop = interpreterProxy->nilObject();
	}
	;
	interpreterProxy->pushRemappableOop(ulonglongValueOop);
	ulonglongValueOop = interpreterProxy->popRemappableOop();
	maximumValueOop = interpreterProxy->popRemappableOop();
	minimumValueOop = interpreterProxy->popRemappableOop();
	defaultValueOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, defaultValueOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, ulonglongValueOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, minimumValueOop);
	interpreterProxy->storePointerofObjectwithValue(3, arrayOop, maximumValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}


/*	g_object free it  */

EXPORT(sqInt) primitivegobjectfree(void) {
	gpointer  gObject;
	sqInt obj;

	obj = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gObject = ((gpointer) (interpreterProxy->positive32BitValueOf(obj)));
	;
	g_free(gObject);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitivegobjectgetboolfrom(void) {
	gpointer  gstObject;
	gboolean  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = (value) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetdoublefrom(void) {
	gpointer  gstObject;
	gdouble  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = interpreterProxy->floatObjectOf(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetfloatfrom(void) {
	gpointer  gstObject;
	gfloat  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = interpreterProxy->floatObjectOf(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetlongfrom(void) {
	gpointer  gstObject;
	long  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = interpreterProxy->signed32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetlonglongfrom(void) {
	gpointer  gstObject;
	long long  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = signed64BitIntegerForOverride(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetpointerfrom(void) {
	gpointer  gstObject;
	gpointer  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetsmalltalkobject(void) {
	gpointer  gstObject;
	gpointer  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	if (value == 0) {
		_return_value = interpreterProxy->nilObject();
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetstringfrom(void) {
	gpointer  gstObject;
	sqInt characterOop;
	char * value;
	sqInt aGstObject;
	char *aName;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	g_object_get(gstObject,aName,&value,NULL);
	characterOop = stringFromCString(value);
	g_free(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, characterOop);
	return null;
}

EXPORT(sqInt) primitivegobjectgetulongfrom(void) {
	gpointer  gstObject;
	unsigned long  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectgetulonglongfrom(void) {
	gpointer  gstObject;
	unsigned long long  value;
	sqInt aGstObject;
	char *aName;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	g_object_get(gstObject,aName,&value,NULL);
	_return_value = positive64BitIntegerForOverride(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegobjectsetboolon(void) {
	gpointer  gstObject;
	gboolean  value;
	sqInt aGstObject;
	char *aName;
	sqInt aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = aValue;
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetdoubleon(void) {
	gpointer  gstObject;
	gdouble  value;
	sqInt aGstObject;
	char *aName;
	double aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = aValue;
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetfloaton(void) {
	gpointer  gstObject;
	gfloat  value;
	sqInt aGstObject;
	char *aName;
	double aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = aValue;
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetlonglongon(void) {
	gpointer  gstObject;
	long long  value;
	sqInt aGstObject;
	char *aName;
	sqInt aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = ((gint64) (signed64BitValueOfOverride(aValue)));
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetlongon(void) {
	gpointer  gstObject;
	long  value;
	sqInt aGstObject;
	char *aName;
	sqInt aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = ((glong) (signed32BitValueOfOverride(aValue)));
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetpointeron(void) {
	gpointer  gstObject;
	gpointer  value;
	sqInt aGstObject;
	char *aName;
	sqInt aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = ((gpointer) (interpreterProxy->positive32BitValueOf(aValue)));
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetstringon(void) {
	gpointer  gstObject;
	sqInt aGstObject;
	char *aName;
	char *aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aValue = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	g_object_set(gstObject,aName,aValue,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetulonglongon(void) {
	gpointer  gstObject;
	unsigned long long value;
	sqInt aGstObject;
	char *aName;
	sqInt aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = ((guint64) (interpreterProxy->positive64BitValueOf(aValue)));
	;
	;
	g_object_set(gstObject,aName,value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegobjectsetulongon(void) {
	gpointer  gstObject;
	unsigned long  value;
	sqInt aGstObject;
	char *aName;
	sqInt aValue;

	aGstObject = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	aValue = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = ((gulong) (interpreterProxy->positive32BitValueOf(aValue)));
	;
	;
	g_object_set(gstObject,aName,&value,NULL);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitivegsignalconnect(void) {
	GstElement*  gstElement;
	void*  data;
	sqInt gstElementOoop;
	char *aString;
	sqInt dataOops;

	gstElementOoop = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aString = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	dataOops = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	data = ((void*) (interpreterProxy->positive32BitValueOf(dataOops)));
	;
	;
	g_signal_connect(gstElement,aString, ((SqueakAudioVideoSinkPtr)data)->handler, data);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	Adds the given element to the bin. Sets the element's parent, and thus takes ownership of the element. An element can only be added to one bin.
If the element's pads are linked to other pads, the pads will be unlinked before the element is added to the bin. */

EXPORT(sqInt) primitivegstbinadd(void) {
	GstBin *bin;
	 GstElement *element;
	sqInt result;
	sqInt binOop;
	sqInt elementOop;
	sqInt _return_value;

	binOop = interpreterProxy->stackValue(1);
	elementOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = 0;
	bin = 0;
	element = 0;
	bin = ((GstBin *) (interpreterProxy->positive32BitValueOf(binOop)));
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	result =  gst_bin_add(bin,element);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Creates a new bin with the given name. */

EXPORT(sqInt) primitivegstbinnew(void) {
	GstElement*  gstElement;
	char *name;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = 0;
	gstElement = gst_bin_new(name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstElement);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstbushavepending(void) {
	gpointer  gstObject;
	gboolean  value;
	sqInt aGstObject;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	value = gst_bus_have_pending(gstObject);
	_return_value = (value) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstbuspeek(void) {
	gpointer  gstObject;
	gpointer  value;
	sqInt aGstObject;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	value = gst_bus_peek(gstObject);
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstbuspop(void) {
	gpointer  gstObject;
	gpointer  value;
	sqInt aGstObject;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	value = gst_bus_pop(gstObject);
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstbuspopfilter(void) {
	gpointer  gstObject;
	gpointer  value;
	sqInt aGstObject;
	sqInt types;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(1);
	types = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	;
	// value = gst_bus_pop_filtered(gstObject,types);
	_return_value = interpreterProxy->positive32BitIntegerFor(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstcapsfromstring(void) {
	GstCaps*  gstObject;
	char *aString;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aString = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = null;
	gstObject = gst_caps_from_string(aString);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstObject);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstcapstostring(void) {
	GstCaps*  gstObject;
	sqInt characterOop;
	char * value;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((GstCaps*) (interpreterProxy->positive32BitValueOf(aGstObject)));
	value = 0;
	;
	value = gst_caps_to_string(gstObject);
	characterOop = stringFromCString(value);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, characterOop);
	return null;
}

EXPORT(sqInt) primitivegstelementadd(void) {
	GstElement*  element;
	GstPad*  gstPad;
	sqInt result;
	sqInt elementOop;
	sqInt padOop;
	sqInt _return_value;

	elementOop = interpreterProxy->stackValue(1);
	padOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	gstPad = ((GstPad *) (interpreterProxy->positive32BitValueOf(padOop)));
	;
	;
	result = 0;
	result = gst_element_add_pad(element, gstPad);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Create a new element of the type defined by the given elementfactory. It will be given the name supplied, since all elements require a name as their first argument. */

EXPORT(sqInt) primitivegstelementfactorycreate(void) {
	GstElement*  gstElement;
	GstElementFactory*  gstElementFactory;
	sqInt factory;
	char *name;
	sqInt _return_value;

	factory = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElementFactory = ((GstElementFactory*) (interpreterProxy->positive32BitValueOf(factory)));
	gstElement = 0;
	;
	gstElement = gst_element_factory_create(gstElementFactory, name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstElement);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Search for an element factory of the given name. Refs the returned element factory; caller is responsible for unreffing. */

EXPORT(sqInt) primitivegstelementfactoryfind(void) {
	GstElementFactory*  gstElementFactory;
	char *name;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElementFactory = 0;
	;
	gstElementFactory = gst_element_factory_find (name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstElementFactory);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Gets the author for this factory */

EXPORT(sqInt) primitivegstelementfactorygetauthor(void) {
	gchar*  author;
	sqInt authorOop;
	GstElementFactory*  gstElementFactory;
	sqInt factory;

	factory = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	author = null;
	gstElementFactory = null;
	;
	gstElementFactory = ((GstElementFactory*) (interpreterProxy->positive32BitValueOf(factory)));
	author = gst_element_factory_get_author (gstElementFactory);
	authorOop = stringFromCString(author);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, authorOop);
	return null;
}


/*	Gets the description for this factory */

EXPORT(sqInt) primitivegstelementfactorygetdescription(void) {
	gchar*  description;
	sqInt descriptionOop;
	GstElementFactory*  gstElementFactory;
	sqInt factory;

	factory = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	description = null;
	gstElementFactory = null;
	;
	gstElementFactory = ((GstElementFactory*) (interpreterProxy->positive32BitValueOf(factory)));
	description = gst_element_factory_get_description (gstElementFactory);
	descriptionOop = stringFromCString(description);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, descriptionOop);
	return null;
}


/*	ets the longname for this factory */

EXPORT(sqInt) primitivegstelementfactorygetklass(void) {
	sqInt klassOop;
	gchar*  klass;
	GstElementFactory*  gstElementFactory;
	sqInt factory;

	factory = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	klass = null;
	gstElementFactory = null;
	;
	gstElementFactory = ((GstElementFactory*) (interpreterProxy->positive32BitValueOf(factory)));
	;
	klass = gst_element_factory_get_klass (gstElementFactory);
	klassOop = stringFromCString(klass);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, klassOop);
	return null;
}


/*	ets the longname for this factory */

EXPORT(sqInt) primitivegstelementfactorygetlongname(void) {
	sqInt longNameOop;
	gchar*  longName;
	GstElementFactory*  gstElementFactory;
	sqInt factory;

	factory = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	longName = null;
	gstElementFactory = null;
	;
	gstElementFactory = ((GstElementFactory*) (interpreterProxy->positive32BitValueOf(factory)));
	;
	longName = gst_element_factory_get_longname (gstElementFactory);
	longNameOop = stringFromCString(longName);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, longNameOop);
	return null;
}


/*	Gets the type of URIs the element supports or GST_URI_UNKNOWN if none. */

EXPORT(sqInt) primitivegstelementfactorygeturitype(void) {
	sqInt uriTypeCount;
	GstElementFactory*  gstElementFactory;
	sqInt factory;
	sqInt _return_value;

	factory = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	uriTypeCount = null;
	gstElementFactory = null;
	;
	gstElementFactory = ((GstElementFactory*) (interpreterProxy->positive32BitValueOf(factory)));
	;
	uriTypeCount = gst_element_factory_get_uri_type  (gstElementFactory);
	_return_value = interpreterProxy->integerObjectOf(uriTypeCount);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Create a new element of the type defined by the given element factory. If name is NULL, then the element will receive a guaranteed unique name, consisting of the element factory name and a number. If name is given, it will be given the name supplied. */

EXPORT(sqInt) primitivegstelementfactorymake(void) {
	GstElement*  gstElement;
	char *factoryName;
	char *name;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	factoryName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = null;
	;
	gstElement = gst_element_factory_make(factoryName, name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstElement);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstelementgetcompatiblepad(void) {
	GstElement*  gstElement;
	GstCaps*  gstCapsValue;
	GstPad*  gstPadFound;
	GstPad*  gstPadValue;
	sqInt gstElementOoop;
	sqInt aPadOop;
	sqInt capsOop;
	sqInt _return_value;

	gstElementOoop = interpreterProxy->stackValue(2);
	aPadOop = interpreterProxy->stackValue(1);
	capsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(aPadOop)));
	gstCapsValue = ((GstCaps*) (interpreterProxy->positive32BitValueOf(capsOop)));
	gstPadFound = 0;
	;
	;
	;
	gstPadFound = gst_element_get_compatible_pad (gstElement,gstPadValue,gstCapsValue);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstPadFound);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstelementgetrequestpad(void) {
	GstElement*  gstElement;
	GstPad*  gstPadValue;
	sqInt gstElementOoop;
	char *name;
	sqInt _return_value;

	gstElementOoop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPadValue = 0;
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	;
	gstPadValue = gst_element_get_request_pad (gstElement,name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstPadValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Sets the state of the element. This function will try to set the requested state by going through all the intermediary states and calling the class's state change function for each.
This function can return GST_STATE_CHANGE_ASYNC, in which case the element will perform the remainder of the state change asynchronously in another thread. An application can use gst_element_get_state() to wait for the completion of the state change or it can wait for a state change message on the bus. */

EXPORT(sqInt) primitivegstelementgetstate(void) {
	GstState  pending;
	GstState  state;
	GstElement*  element;
	sqInt result;
	sqInt arrayOop;
	GstClockTime  gstClockTime;
	sqInt elementOop;
	sqInt gstClockTimeOop;

	elementOop = interpreterProxy->stackValue(1);
	gstClockTimeOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	gstClockTime = ((GstClockTime) (interpreterProxy->positive64BitValueOf(gstClockTimeOop)));
	state = 0;
	pending = 0;
	result = 0;
	;
	;
	;
	;
	result = gst_element_get_state(element, &state, &pending, gstClockTime);
	arrayOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 3);
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, ((result << 1) | 1));
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, ((state << 1) | 1));
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, ((pending << 1) | 1));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstelementgetstaticpad(void) {
	GstElement*  gstElement;
	GstPad*  gstPadValue;
	sqInt gstElementOoop;
	char *name;
	sqInt _return_value;

	gstElementOoop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPadValue = 0;
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	;
	gstPadValue =  gst_element_get_static_pad(gstElement,name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstPadValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Connects a GCallback function to a signal for a particular object.
The handler will be called before the default handler of the signal. */

EXPORT(sqInt) primitivegstelementgsignalconnect(void) {
	sqInt listLength;
	GstElement*  element;
	sqInt i;
	sqInt  *callBackData;
	sqInt  dataPad;
	sqInt elementOop;
	char *aSignalName;
	sqInt *data;

	elementOop = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	aSignalName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isIndexable(interpreterProxy->stackValue(0)));
	data = ((int *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	listLength = interpreterProxy->slotSizeOf((oopForPointer( data ) - 4));
	callBackData = 0;
	callBackData = (sqInt*) g_malloc0(sizeof(sqInt)*(1+listLength));
	callBackData[0] = (((sqInt) listLength));
	for (i = 0; i <= (listLength - 1); i += 1) {
		dataPad = ((sqInt) (data[i]));
		callBackData[i + 1] = dataPad;
		if (i < 128) {
			callbackForPadHookupElement[i + 1] = 0;
		}
	}
	;
	;
	;
	;
	g_signal_connect(element, aSignalName,G_CALLBACK (cbnewpad),callBackData);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	Links src to dest. The link must be from source to destination; the other direction will not be tried. The function looks for existing pads that aren't linked yet. It will request new pads if necessary. Such pads need to be released manualy when unlinking. If multiple links are possible, only one is established.
Make sure you have added your elements to a bin or pipeline with gst_bin_add() before trying to link them. */

EXPORT(sqInt) primitivegstelementlink(void) {
	GstElement*  dest;
	GstElement*  src;
	sqInt result;
	sqInt srcOop;
	sqInt destOop;
	sqInt _return_value;

	srcOop = interpreterProxy->stackValue(1);
	destOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	src = ((GstElement *) (interpreterProxy->positive32BitValueOf(srcOop)));
	dest = ((GstElement *) (interpreterProxy->positive32BitValueOf(destOop)));
	;
	;
	result = gst_element_link(src, dest);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstelementlinkfiltered(void) {
	GstElement*  dest;
	sqInt result;
	GstElement*  src;
	GstCaps*  caps;
	sqInt srcOop;
	sqInt destOop;
	sqInt capsOop;
	sqInt _return_value;

	srcOop = interpreterProxy->stackValue(2);
	destOop = interpreterProxy->stackValue(1);
	capsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	src = ((GstElement *) (interpreterProxy->positive32BitValueOf(srcOop)));
	dest = ((GstElement *) (interpreterProxy->positive32BitValueOf(destOop)));
	caps = ((GstCaps *) (interpreterProxy->positive32BitValueOf(destOop)));
	result = 0;
	;
	;
	;
	result =  gst_element_link_filtered(src, dest,caps);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	Queries an element for the stream position */

EXPORT(sqInt) primitivegstelementqueryconvert(void) {
	gint64 val;
	sqInt destValueOop;
	sqInt resultOop;
	GstElement*  element;
	sqInt result;
	sqInt arrayOop;
	gint64 destValue;
	GstFormat destformat;
	sqInt elementOop;
	sqInt srcformat;
	sqInt valOop;
	sqInt destformatOop;

	elementOop = interpreterProxy->stackValue(3);
	srcformat = interpreterProxy->stackIntegerValue(2);
	valOop = interpreterProxy->stackValue(1);
	destformatOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	destformat = ((GstFormat) (interpreterProxy->positive32BitValueOf(destformatOop)));
	val = ((gint64) (signed64BitValueOfOverride(valOop)));
	;
	;
	;
	result = 0;
	destValue = 0;
	result =  gst_element_query_convert(element,srcformat,val,&destformat,&destValue);
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	interpreterProxy->pushRemappableOop((result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	interpreterProxy->pushRemappableOop(signed64BitIntegerForOverride(destValue));
	destValueOop = interpreterProxy->popRemappableOop();
	resultOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, resultOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, destValueOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, arrayOop);
	return null;
}


/*	Queries an element for the stream position */

EXPORT(sqInt) primitivegstelementqueryduration(void) {
	sqInt resultOop;
	gint64 duration;
	sqInt formatOopReturn;
	sqInt durationOop;
	GstElement*  element;
	sqInt result;
	sqInt arrayOop;
	GstFormat format;
	sqInt elementOop;
	sqInt formatOop;

	elementOop = interpreterProxy->stackValue(1);
	formatOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	format = ((GstFormat) (interpreterProxy->positive32BitValueOf(formatOop)));
	;
	;
	result = 0;
	duration = 0;
	result =  gst_element_query_duration(element,&format,&duration);
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 3));
	interpreterProxy->pushRemappableOop((result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(format));
	interpreterProxy->pushRemappableOop(signed64BitIntegerForOverride(duration));
	durationOop = interpreterProxy->popRemappableOop();
	formatOopReturn = interpreterProxy->popRemappableOop();
	resultOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, resultOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, formatOopReturn);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, durationOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}


/*	Queries an element for the stream position */

EXPORT(sqInt) primitivegstelementqueryposition(void) {
	sqInt resultOop;
	sqInt formatOopReturn;
	GstElement*  element;
	sqInt result;
	sqInt arrayOop;
	sqInt curOop;
	GstFormat format;
	gint64 cur;
	sqInt elementOop;
	sqInt formatOop;

	elementOop = interpreterProxy->stackValue(1);
	formatOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	format = ((GstFormat) (interpreterProxy->positive32BitValueOf(formatOop)));
	;
	;
	result = 0;
	cur = 0;
	result =  gst_element_query_position(element,&format,&cur);
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 3));
	interpreterProxy->pushRemappableOop((result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(format));
	interpreterProxy->pushRemappableOop(signed64BitIntegerForOverride(cur));
	curOop = interpreterProxy->popRemappableOop();
	formatOopReturn = interpreterProxy->popRemappableOop();
	resultOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, resultOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, formatOopReturn);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, curOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstelementreleaserequestpad(void) {
	GstElement*  gstElement;
	GstPad*  gstPadValue;
	sqInt gstElementOoop;
	sqInt aPadOop;

	gstElementOoop = interpreterProxy->stackValue(1);
	aPadOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = ((GstElement*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(aPadOop)));
	;
	;
	gst_element_release_request_pad(gstElement,gstPadValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Sends a seek event to an element. See gst_event_new_seek() for the details of the parameters. 
The seek event is sent to the element using gst_element_send_event(). */

EXPORT(sqInt) primitivegstelementseek(void) {
	gint64  cur;
	GstElement*  element;
	gboolean  result;
	gint64  stop;
	sqInt elementOop;
	double aRate;
	sqInt aFormat;
	sqInt aFlags;
	sqInt aCurrentType;
	sqInt curOop;
	sqInt aStopType;
	sqInt stopOop;
	sqInt _return_value;

	elementOop = interpreterProxy->stackValue(7);
	aRate = interpreterProxy->stackFloatValue(6);
	aFormat = interpreterProxy->stackIntegerValue(5);
	aFlags = interpreterProxy->stackIntegerValue(4);
	aCurrentType = interpreterProxy->stackIntegerValue(3);
	curOop = interpreterProxy->stackValue(2);
	aStopType = interpreterProxy->stackIntegerValue(1);
	stopOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	cur = ((gint64) (signed64BitValueOfOverride(curOop)));
	stop = ((gint64) (signed64BitValueOfOverride(stopOop)));
	;
	;
	;
	result = 0;
	result = gst_element_seek(element, aRate, aFormat, aFlags, aCurrentType, cur, aStopType, stop);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(9, _return_value);
	return null;
}


/*	Sends a seek event to an element. */

EXPORT(sqInt) primitivegstelementseeksimple(void) {
	GstElement*  element;
	gboolean  result;
	gint64  cur;
	sqInt elementOop;
	sqInt aFormat;
	sqInt aFlags;
	sqInt curOop;
	sqInt _return_value;

	elementOop = interpreterProxy->stackValue(3);
	aFormat = interpreterProxy->stackIntegerValue(2);
	aFlags = interpreterProxy->stackIntegerValue(1);
	curOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	cur = ((gint64) (signed64BitValueOfOverride(curOop)));
	;
	;
	result = 0;
	result = gst_element_seek_simple(element, aFormat, aFlags, cur);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}


/*	Sets the state of the element. This function will try to set the requested state by going through all the intermediary states and calling the class's state change function for each.
This function can return GST_STATE_CHANGE_ASYNC, in which case the element will perform the remainder of the state change asynchronously in another thread. An application can use gst_element_get_state() to wait for the completion of the state change or it can wait for a state change message on the bus. */

EXPORT(sqInt) primitivegstelementsetstate(void) {
	sqInt result;
	GstElement*  element;
	sqInt elementOop;
	sqInt aControlValue;
	sqInt _return_value;

	elementOop = interpreterProxy->stackValue(1);
	aControlValue = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	element = ((GstElement *) (interpreterProxy->positive32BitValueOf(elementOop)));
	;
	result = gst_element_set_state(element, aControlValue);
	_return_value = interpreterProxy->positive32BitIntegerFor(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstghostpadnew(void) {
	GstPad*  newGstPad;
	GstPad*  gstPad;
	sqInt gstElementOoop;
	char *name;
	sqInt _return_value;

	gstElementOoop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	newGstPad = 0;
	gstPad = ((GstPad*) (interpreterProxy->positive32BitValueOf(gstElementOoop)));
	;
	newGstPad  =   gst_ghost_pad_new(name,gstPad);
	_return_value = interpreterProxy->positive32BitIntegerFor(newGstPad);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Initializes the GStreamer library, setting up internal path lists, registering built-in elements, and loading standard plugins. */

EXPORT(sqInt) primitivegstinitcheck(void) {
	gboolean initialize;
	sqInt _return_value;

	initialize = 0;
	initialize = gst_init_check(null,null,null);
	_return_value = (initialize? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstmessageparsebuffering(void) {
	sqInt percent;
	gpointer  gstObject;
	sqInt aGstObject;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	percent = 0;
	gst_message_parse_buffering(gstObject,&percent);
	_return_value = interpreterProxy->positive32BitIntegerFor(percent);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstmessageparseduration(void) {
	sqInt positionOop;
	gint64 position;
	sqInt arrayOop;
	gpointer  gstObject;
	sqInt formatOop;
	 GstFormat  format;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	format = 0;
	position = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	 gst_message_parse_duration(gstObject,&format,&position);
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(format));
	interpreterProxy->pushRemappableOop(signed64BitIntegerForOverride(position));
	positionOop = interpreterProxy->popRemappableOop();
	formatOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, formatOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, positionOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessageparseerror(void) {
	 GError *  errorString;
	sqInt debugStringOop;
	 char *  debugString;
	sqInt arrayOop;
	sqInt errorStringOop;
	gpointer  gstObject;
	 char *  errorMessage;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	errorString = 0;
	debugString = 0;
	errorMessage = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	gst_message_parse_error(gstObject,&errorString,&debugString);
		errorMessage = errorString->message;
	errorStringOop = stringFromCString(errorMessage);
	interpreterProxy->pushRemappableOop(errorStringOop);
	g_error_free(errorString);
	if (debugString == 0) {
		debugStringOop = interpreterProxy->nilObject();
	} else {
		debugStringOop = stringFromCString(debugString);
		g_free(debugString);
	}
	interpreterProxy->pushRemappableOop(debugStringOop);
	debugStringOop = interpreterProxy->popRemappableOop();
	errorStringOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, errorStringOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, debugStringOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessageparseinfo(void) {
	 GError *  errorString;
	sqInt debugStringOop;
	 char *  debugString;
	sqInt arrayOop;
	sqInt errorStringOop;
	gpointer  gstObject;
	 char *  errorMessage;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	errorString = 0;
	debugString = 0;
	errorMessage = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	gst_message_parse_info(gstObject,&errorString,&debugString);
		errorMessage = errorString->message;
	errorStringOop = stringFromCString(errorMessage);
	interpreterProxy->pushRemappableOop(errorStringOop);
	g_error_free(errorString);
	if (debugString == 0) {
		debugStringOop = interpreterProxy->nilObject();
	} else {
		debugStringOop = stringFromCString(debugString);
		g_free(debugString);
	}
	interpreterProxy->pushRemappableOop(debugStringOop);
	debugStringOop = interpreterProxy->popRemappableOop();
	errorStringOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, errorStringOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, debugStringOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessageparsesegmentdone(void) {
	sqInt positionOop;
	gint64 position;
	sqInt arrayOop;
	gpointer  gstObject;
	sqInt formatOop;
	 GstFormat  format;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	format = 0;
	position = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	gst_message_parse_segment_done(gstObject,&format,&position);
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(format));
	interpreterProxy->pushRemappableOop(signed64BitIntegerForOverride(position));
	positionOop = interpreterProxy->popRemappableOop();
	formatOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, formatOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, positionOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessageparsesegmentstart(void) {
	sqInt positionOop;
	gint64 position;
	sqInt arrayOop;
	gpointer  gstObject;
	sqInt formatOop;
	 GstFormat  format;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	format = 0;
	position = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	gst_message_parse_segment_start(gstObject,&format,&position);
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(format));
	interpreterProxy->pushRemappableOop(signed64BitIntegerForOverride(position));
	positionOop = interpreterProxy->popRemappableOop();
	formatOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, formatOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, positionOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessageparsestatechanged(void) {
	sqInt pendingOop;
	  GstState  pending;
	sqInt arrayOop;
	sqInt newOop;
	  GstState  new;
	  GstState  old;
	gpointer  gstObject;
	sqInt oldOop;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	old = new = pending = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 3));
	gst_message_parse_state_changed(gstObject,&old,&new,&pending);
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(old));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(new));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(pending));
	pendingOop = interpreterProxy->popRemappableOop();
	newOop = interpreterProxy->popRemappableOop();
	oldOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, oldOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, newOop);
	interpreterProxy->storePointerofObjectwithValue(2, arrayOop, pendingOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessageparsewarning(void) {
	 GError *  errorString;
	sqInt debugStringOop;
	 char *  debugString;
	sqInt arrayOop;
	sqInt errorStringOop;
	gpointer  gstObject;
	 char *  errorMessage;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	errorString = 0;
	debugString = 0;
	errorMessage = 0;
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	gst_message_parse_warning(gstObject,&errorString,&debugString);
		errorMessage = errorString->message;
	errorStringOop = stringFromCString(errorMessage);
	interpreterProxy->pushRemappableOop(errorStringOop);
	g_error_free(errorString);
	if (debugString == 0) {
		debugStringOop = interpreterProxy->nilObject();
	} else {
		debugStringOop = stringFromCString(debugString);
		g_free(debugString);
	}
	interpreterProxy->pushRemappableOop(debugStringOop);
	debugStringOop = interpreterProxy->popRemappableOop();
	errorStringOop = interpreterProxy->popRemappableOop();
	arrayOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, arrayOop, errorStringOop);
	interpreterProxy->storePointerofObjectwithValue(1, arrayOop, debugStringOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, arrayOop);
	return null;
}

EXPORT(sqInt) primitivegstmessagesrc(void) {
	GstObject * gstSrcObject;
	gpointer  gstObject;
	sqInt aGstObject;
	sqInt _return_value;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	gstSrcObject = null;
	;
	;
	gstSrcObject = GST_MESSAGE_SRC(gstObject);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstSrcObject);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstmessagetypestring(void) {
	 char *  msgString;
	gpointer  gstObject;
	sqInt value;
	sqInt msgStringOop;
	sqInt aGstObject;

	aGstObject = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(aGstObject)));
	;
	;
	value = GST_MESSAGE_TYPE(gstObject);
		msgString = gst_message_type_get_name(value);
	msgStringOop = stringFromCString(msgString);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, msgStringOop);
	return null;
}


/*	Convenience macro to decrease the reference count of the message, possibly freeing it. */

EXPORT(sqInt) primitivegstmessageunref(void) {
	gpointer  gstObject;
	sqInt obj;

	obj = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(obj)));
	gst_message_unref(gstObject);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Decrements the reference count on object. If reference count hits zero, destroy object. This function does not take the lock on object as it relies on atomic refcounting.
The unref method should never be called with the LOCK held since this might deadlock the dispose function. */

EXPORT(sqInt) primitivegstobjectunref(void) {
	gpointer  gstObject;
	sqInt obj;

	obj = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstObject = ((gpointer) (interpreterProxy->positive32BitValueOf(obj)));
	gst_object_unref(gstObject);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitivegstpadacceptcaps(void) {
	GstPad*  gstPadValue;
	GstCaps*  gstCapsValue;
	sqInt result;
	sqInt gstPadOop;
	sqInt gstCapsOop;
	sqInt _return_value;

	gstPadOop = interpreterProxy->stackValue(1);
	gstCapsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(gstPadOop)));
	gstCapsValue = ((GstCaps*) (interpreterProxy->positive32BitValueOf(gstCapsOop)));
	;
	;
	result = 0;
	result =  gst_pad_accept_caps (gstPadValue, gstCapsValue);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstpadgetcaps(void) {
	GstPad*  gstPadValue;
	GstCaps*  gstCapsValue;
	sqInt gstPadOop;
	sqInt _return_value;

	gstPadOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstCapsValue = 0;
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(gstPadOop)));
	;
	gstCapsValue = gst_pad_get_caps (gstPadValue);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstCapsValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstpadgetparentelement(void) {
	GstPad*  gstPadValue;
	GstElement*  gstEvementValue;
	sqInt gstPadOop;
	sqInt _return_value;

	gstPadOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstEvementValue = 0;
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(gstPadOop)));
	;
	gstEvementValue = gst_pad_get_parent_element (gstPadValue);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstEvementValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstpadlink(void) {
	GstPad*  dest;
	GstPad*  src;
	sqInt result;
	sqInt srcOop;
	sqInt destOop;
	sqInt _return_value;

	srcOop = interpreterProxy->stackValue(1);
	destOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	src = ((GstPad *) (interpreterProxy->positive32BitValueOf(srcOop)));
	dest = ((GstPad *) (interpreterProxy->positive32BitValueOf(destOop)));
	result = 0;
	;
	;
	result =  gst_pad_link(src, dest);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstpadsetactive(void) {
	GstPad*  gstPadValue;
	sqInt result;
	sqInt gstPadOop;
	sqInt aBoolean;
	sqInt _return_value;

	gstPadOop = interpreterProxy->stackValue(1);
	aBoolean = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(gstPadOop)));
	;
	result = 0;
	result =  gst_pad_set_active (gstPadValue, aBoolean);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitivegstpadsetcaps(void) {
	GstPad*  gstPadValue;
	GstCaps*  gstCapsValue;
	sqInt result;
	sqInt gstPadOop;
	sqInt gstCapsOop;
	sqInt _return_value;

	gstPadOop = interpreterProxy->stackValue(1);
	gstCapsOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPadValue = ((GstPad*) (interpreterProxy->positive32BitValueOf(gstPadOop)));
	gstCapsValue = ((GstCaps*) (interpreterProxy->positive32BitValueOf(gstCapsOop)));
	;
	;
	result = 0;
	result =  gst_pad_set_caps(gstPadValue, gstCapsValue);
	_return_value = (result) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Gets the gstClock of pipeline. */

EXPORT(sqInt) primitivegstpipelineautoclock(void) {
	GstPipeline*  gstPipeline;
	sqInt gstPipelineOop;

	gstPipelineOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	;
	gst_pipeline_auto_clock(gstPipeline);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Usually, when a pipeline goes from READY to NULL state, it automatically flushes all pending messages on the bus, which is done for refcounting purposes, to break circular references.
This means that applications that update state using (async) bus messages (e.g. do certain things when a pipeline goes from PAUSED to READY) might not get to see messages when the pipeline is shut down, because they might be flushed before they can be dispatched in the main thread. This behaviour can be disabled using this function.
It is important that all messages on the bus are handled when the automatic flushing is disabled else memory leaks will be introduced.
 */

EXPORT(sqInt) primitivegstpipelinegetautoflushbus(void) {
	GstPipeline*  gstPipeline;
	gboolean  aBoolean;
	sqInt gstPipelineOop;
	sqInt _return_value;

	gstPipelineOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	aBoolean = 0;
	;
	aBoolean = gst_pipeline_get_auto_flush_bus(gstPipeline);
	_return_value = (aBoolean) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Gets the GstBus of pipeline. */

EXPORT(sqInt) primitivegstpipelinegetbus(void) {
	GstBus*  gstBus;
	GstPipeline*  gstPipeline;
	sqInt gstPipelineOop;
	sqInt _return_value;

	gstPipelineOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstBus = 0;
	gstBus = gst_pipeline_get_bus(gstPipeline);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstBus);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Gets the gstClock of pipeline. */

EXPORT(sqInt) primitivegstpipelinegetclock(void) {
	GstPipeline*  gstPipeline;
	GstClock*  gstClock;
	sqInt gstPipelineOop;
	sqInt _return_value;

	gstPipelineOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClock = 0;
	;
	gstClock = gst_pipeline_get_clock(gstPipeline);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstClock);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Get the configured delay (see gst_pipeline_set_delay()). */

EXPORT(sqInt) primitivegstpipelinegetdelay(void) {
	GstPipeline*  gstPipeline;
	GstClockTime  gstClockTime;
	sqInt gstPipelineOop;
	sqInt _return_value;

	gstPipelineOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClockTime = 0;
	;
	gstClockTime = gst_pipeline_get_delay(gstPipeline);
	_return_value = positive64BitIntegerForOverride(gstClockTime);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Gets the last stream time of pipeline. If the pipeline is PLAYING, the returned time is the stream time used to configure the element's base time in the PAUSED->PLAYING state. If the pipeline is PAUSED, the returned time is the stream time when the pipeline was paused.
This function returns GST_CLOCK_TIME_NONE if the pipeline was configured to not handle the management of the element's base time (see gst_pipeline_set_new_stream_time()). */

EXPORT(sqInt) primitivegstpipelinegetlaststreamtime(void) {
	GstPipeline*  gstPipeline;
	GstClockTime  gstClockTime;
	sqInt gstPipelineOop;
	sqInt _return_value;

	gstPipelineOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClockTime = 0;
	;
	gstClockTime = gst_pipeline_get_last_stream_time(gstPipeline);
	_return_value = positive64BitIntegerForOverride(gstClockTime);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Create a new pipeline with the given name. */

EXPORT(sqInt) primitivegstpipelinenew(void) {
	GstElement*  gstElement;
	char *name;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstElement = 0;
	gstElement = gst_pipeline_new(name);
	_return_value = interpreterProxy->positive32BitIntegerFor(gstElement);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Usually, when a pipeline goes from READY to NULL state, it automatically flushes all pending messages on the bus, which is done for refcounting purposes, to break circular references.
This means that applications that update state using (async) bus messages (e.g. do certain things when a pipeline goes from PAUSED to READY) might not get to see messages when the pipeline is shut down, because they might be flushed before they can be dispatched in the main thread. This behaviour can be disabled using this function.
It is important that all messages on the bus are handled when the automatic flushing is disabled else memory leaks will be introduced. */

EXPORT(sqInt) primitivegstpipelinesetautoflushbus(void) {
	GstPipeline*  gstPipeline;
	sqInt gstPipelineOop;
	sqInt aBoolean;

	gstPipelineOop = interpreterProxy->stackValue(1);
	aBoolean = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	;
	gst_pipeline_set_auto_flush_bus(gstPipeline,aBoolean);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Let pipeline select a clock automatically. This is the default behaviour.
Use this function if you previous forced a fixed clock with gst_pipeline_use_clock() and want to restore the default pipeline clock selection algorithm.
 */

EXPORT(sqInt) primitivegstpipelinesetclock(void) {
	gboolean  aResult;
	GstPipeline*  gstPipeline;
	GstClock*  gstClock;
	sqInt gstPipelineOop;
	sqInt aClockValueOop;
	sqInt _return_value;

	gstPipelineOop = interpreterProxy->stackValue(1);
	aClockValueOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClock = ((GstClock*) (interpreterProxy->positive32BitValueOf(aClockValueOop)));
	;
	;
	aResult = 0;
	aResult =  gst_pipeline_set_clock(gstPipeline,gstClock);
	_return_value = (aResult) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Set the expected delay needed for all elements to perform the PAUSED to PLAYING state change. delay will be added to the base time of the elements so that they wait an additional delay amount of time before starting to process buffers and cannot be GST_CLOCK_TIME_NONE.
This option is used for tuning purposes and should normally not be used.
 */

EXPORT(sqInt) primitivegstpipelinesetdelay(void) {
	GstPipeline*  gstPipeline;
	GstClockTime  gstClockTime ;
	sqInt gstPipelineOop;
	sqInt aClockValueOop;

	gstPipelineOop = interpreterProxy->stackValue(1);
	aClockValueOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClockTime = ((GstClockTime) (interpreterProxy->positive64BitValueOf(aClockValueOop)));
	;
	;
	gst_pipeline_set_delay(gstPipeline,gstClockTime);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Set the new stream time of pipeline to time. The stream time is used to set the base time on the elements (see gst_element_set_base_time()) in the PAUSED->PLAYING state transition.
Setting time to GST_CLOCK_TIME_NONE will disable the pipeline's management of element base time. The application will then be responsible for performing base time distribution. This is sometimes useful if you want to synchronize capture from multiple pipelines, and you can also ensure that the pipelines have the same clock. */

EXPORT(sqInt) primitivegstpipelinesetnewstreamtime(void) {
	GstPipeline*  gstPipeline;
	GstClockTime  gstClockTime ;
	sqInt gstPipelineOop;
	sqInt aClockValueOop;

	gstPipelineOop = interpreterProxy->stackValue(1);
	aClockValueOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClockTime = ((GstClockTime) (interpreterProxy->positive64BitValueOf(aClockValueOop)));
	;
	;
	gst_pipeline_set_new_stream_time(gstPipeline,gstClockTime);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Force pipeline to use the given clock. The pipeline will always use the given clock even if new clock providers are added to this pipeline.
If clock is NULL all clocking will be disabled which will make the pipeline run as fast as possible.
 */

EXPORT(sqInt) primitivegstpipelineuseclock(void) {
	gboolean  aResult;
	GstPipeline*  gstPipeline;
	GstClock*  gstClock;
	sqInt gstPipelineOop;
	sqInt aClockValueOop;

	gstPipelineOop = interpreterProxy->stackValue(1);
	aClockValueOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	gstPipeline = ((GstPipeline*) (interpreterProxy->positive32BitValueOf(gstPipelineOop)));
	gstClock = ((GstClock*) (interpreterProxy->positive32BitValueOf(aClockValueOop)));
	;
	;
	aResult = 0;
	gst_pipeline_use_clock(gstPipeline,gstClock);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Applications might want to disable/enable the usage of fork() when rebuilding the registry. See gst_registry_fork_is_enabled() for more information.
On platforms without fork(), this function will have no effect on the return value of gst_registry_fork_is_enabled().

enabled:
whether rebuilding the registry may fork
 */

EXPORT(sqInt) primitivegstregistryforksetenabled(void) {
	gboolean on;
	sqInt aBoolean;

	aBoolean = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	on = aBoolean;
	;
	gst_registry_fork_set_enabled(on);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Some functions in the GStreamer core might install a custom SIGSEGV handler to better catch and report errors to the application. Currently this feature is enabled by default when loading plugins.
Applications might want to disable this behaviour with the gst_segtrap_set_enabled() function. This is typically done if the application wants to install its own handler without GStreamer interfering. */

EXPORT(sqInt) primitivegstsegtrapisenabled(void) {
	gboolean on;
	sqInt _return_value;

	on = 0;
	on = gst_segtrap_is_enabled();
	_return_value = (on? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Some functions in the GStreamer core might install a custom SIGSEGV handler to better catch and report errors to the application. Currently this feature is enabled by default when loading plugins.
Applications might want to disable this behaviour with the gst_segtrap_set_enabled() function. This is typically done if the application wants to install its own handler without GStreamer interfering. */

EXPORT(sqInt) primitivegstsegtrapsetenabled(void) {
	gboolean on;
	sqInt aBoolean;

	aBoolean = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	on = aBoolean;
	;
	gst_segtrap_set_enabled(on);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	This function returns a string that is useful for describing this version of GStreamer to the outside world: user agent strings, logging, ... */

EXPORT(sqInt) primitivegstversionstring(void) {
	gchar *version;
	sqInt versionOOp;

	version = gst_version_string();
	versionOOp = stringFromCString(version);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, versionOOp);
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

static sqInt shutdownModule(void) {
	return 1;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargeInteger. */

static sqInt signed32BitValueOfOverride(sqInt oop) {
	sqInt value;
	sqInt largeClass;
	unsigned char * where;
	sqInt negative;
	sqInt sz;

	if ((oop & 1)) {
		return (oop >> 1);
	}
	largeClass = interpreterProxy->fetchClassOf(oop);
	if (largeClass == (interpreterProxy->classLargePositiveInteger())) {
		negative = 0;
	} else {
		if (largeClass == (interpreterProxy->classLargeNegativeInteger())) {
			negative = 1;
		} else {
			return interpreterProxy->primitiveFail();
		}
	}
	sz = interpreterProxy->slotSizeOf(oop);
	if (!(sz == 4)) {
		return interpreterProxy->primitiveFail();
	}
	where = interpreterProxy->firstIndexableField(oop);

	/* Filter out values out of range for the signed interpretation such as
	16rFFFFFFFF (positive w/ bit 32 set) and -16rFFFFFFFF (negative w/ bit
	32 set). Since the sign is implicit in the class we require that the
	high bit of the magnitude is not set which is a simple test here. */

	value = (((where[0]) + ((where[1]) << 8)) + ((where[2]) << 16)) + ((where[3]) << 24);
	if (negative && (value == (1 << 31))) {
		return value;
	}
	if (value < 0) {
		return interpreterProxy->primitiveFail();
	}
	if (negative) {
		return 0 - value;
	} else {
		return value;
	}
}


/*	Return a Large Integer object for the given integer value */

static sqInt signed64BitIntegerForOverride(sqLong integerValue) {
	usqInt highWord;
	sqLong lowestIntegerValue;
	sqInt largeClass;
	unsigned char* where;
	sqInt i;
	sqInt newLargeInteger;
	sqLong magnitude;
	sqInt sz;
	sqInt intValue;

	lowestIntegerValue = 1;
	lowestIntegerValue = lowestIntegerValue << 63;
	if (integerValue == lowestIntegerValue) {

		/* newLargeInteger := self instantiateClass: largeClass indexableSize:  8. */

		largeClass = interpreterProxy->classLargeNegativeInteger();
		newLargeInteger = interpreterProxy->instantiateClassindexableSize(largeClass, 8);
		where = interpreterProxy->firstIndexableField(newLargeInteger);
		where[7] = 128;
		return newLargeInteger;
	}
	if (integerValue < 0) {
		largeClass = interpreterProxy->classLargeNegativeInteger();
		magnitude = 0 - integerValue;
	} else {
		largeClass = interpreterProxy->classLargePositiveInteger();
		magnitude = integerValue;
	}
	if (magnitude <= 2147483647U) {
		return interpreterProxy->signed32BitIntegerFor(integerValue);
	}

	/* shift is coerced to usqInt otherwise */

	highWord = magnitude >> 32;
	if (highWord == 0) {
		sz = 4;
	} else {
		sz = 5;
		if ((highWord = ((usqInt) highWord) >> 8) > 0) {
			sz += 1;
		}
		if ((highWord = ((usqInt) highWord) >> 8) > 0) {
			sz += 1;
		}
		if ((highWord = ((usqInt) highWord) >> 8) > 0) {
			sz += 1;
		}
	}
	newLargeInteger = interpreterProxy->instantiateClassindexableSize(largeClass, sz);
	where = interpreterProxy->firstIndexableField(newLargeInteger);
	for (i = 0; i <= (sz - 1); i += 1) {

		/* self storeByte: i ofObject: newLargeInteger withValue: intValue */

		intValue = (magnitude >> (i * 8)) & 255;
		where[i] = intValue;
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargeInteger. */

static sqLong signed64BitValueOfOverride(sqInt oop) {
	sqLong lowestIntegerValue;
	sqLong value;
	sqInt largeClass;
	unsigned char * where;
	sqInt i;
	sqInt negative;
	sqInt sz;
	sqInt szsqLong;

	if ((oop & 1)) {
		return ((sqLong) ((oop >> 1)));
	}
	largeClass = interpreterProxy->fetchClassOf(oop);
	if (largeClass == (interpreterProxy->classLargePositiveInteger())) {
		negative = 0;
	} else {
		if (largeClass == (interpreterProxy->classLargeNegativeInteger())) {
			negative = 1;
		} else {
			return interpreterProxy->primitiveFail();
		}
	}
	szsqLong = sizeof(sqLong);
	sz = interpreterProxy->slotSizeOf(oop);
	if (sz > szsqLong) {
		return interpreterProxy->primitiveFail();
	}
	value = 0;
	where = interpreterProxy->firstIndexableField(oop);
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((sqLong) (where[i]))) << (i * 8);
	}
	lowestIntegerValue = 1;
	lowestIntegerValue = lowestIntegerValue << 63;
	if (negative && (value == lowestIntegerValue)) {
		return value;
	}
	if (value < 0) {
		return interpreterProxy->primitiveFail();
	}
	if (negative) {
		return 0 - value;
	} else {
		return value;
	}
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


/*	Answer a new String copied from a null-terminated C string.
	Caution: This may invoke the garbage collector. */

static sqInt stringFromCString(const char * aCString) {
	sqInt len;
	sqInt newString;

	if (aCString == null) {
		return interpreterProxy->nilObject();
	}
	len = strlen(aCString);
	newString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), len);
	strncpy(interpreterProxy->arrayValueOf(newString), aCString, len);
	return newString;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* GStreamerPlugin_exports[][3] = {
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyulonglongatIndex", (void*)primitivegobjectclasslistpropertyulonglongatIndex},
	{"GStreamerPlugin", "primitivegstelementfactorygetdescription", (void*)primitivegstelementfactorygetdescription},
	{"GStreamerPlugin", "primitivegstelementreleaserequestpad", (void*)primitivegstelementreleaserequestpad},
	{"GStreamerPlugin", "primitivegstbuspopfilter", (void*)primitivegstbuspopfilter},
	{"GStreamerPlugin", "primitivegstpadlink", (void*)primitivegstpadlink},
	{"GStreamerPlugin", "primitivegstelementfactorygetlongname", (void*)primitivegstelementfactorygetlongname},
	{"GStreamerPlugin", "primitiveSqueakSinkGetFrameRateNumerator", (void*)primitiveSqueakSinkGetFrameRateNumerator},
	{"GStreamerPlugin", "setInterpreter", (void*)setInterpreter},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertymetaDataatIndex", (void*)primitivegobjectclasslistpropertymetaDataatIndex},
	{"GStreamerPlugin", "primitivegstpipelinesetdelay", (void*)primitivegstpipelinesetdelay},
	{"GStreamerPlugin", "primitivegstelementsetstate", (void*)primitivegstelementsetstate},
	{"GStreamerPlugin", "primitivegobjectsetulongon", (void*)primitivegobjectsetulongon},
	{"GStreamerPlugin", "primitivegstelementqueryposition", (void*)primitivegstelementqueryposition},
	{"GStreamerPlugin", "primitivegstbushavepending", (void*)primitivegstbushavepending},
	{"GStreamerPlugin", "primitivegstmessageparseinfo", (void*)primitivegstmessageparseinfo},
	{"GStreamerPlugin", "primitivegstpadgetparentelement", (void*)primitivegstpadgetparentelement},
	{"GStreamerPlugin", "primitivegobjectsetstringon", (void*)primitivegobjectsetstringon},
	{"GStreamerPlugin", "primitivegstelementgetcompatiblepad", (void*)primitivegstelementgetcompatiblepad},
	{"GStreamerPlugin", "primitivegstpipelinesetclock", (void*)primitivegstpipelinesetclock},
	{"GStreamerPlugin", "primitiveSqueakSrc", (void*)primitiveSqueakSrc},
	{"GStreamerPlugin", "primitivegobjectgetdoublefrom", (void*)primitivegobjectgetdoublefrom},
	{"GStreamerPlugin", "primitivecallbacksignalseenfor", (void*)primitivecallbacksignalseenfor},
	{"GStreamerPlugin", "primitivegstmessageparsewarning", (void*)primitivegstmessageparsewarning},
	{"GStreamerPlugin", "primitivegstmessagesrc", (void*)primitivegstmessagesrc},
	{"GStreamerPlugin", "primitivegstmessageparseerror", (void*)primitivegstmessageparseerror},
	{"GStreamerPlugin", "primitiveSqueakSinkFree", (void*)primitiveSqueakSinkFree},
	{"GStreamerPlugin", "primitivegobjectsetulonglongon", (void*)primitivegobjectsetulonglongon},
	{"GStreamerPlugin", "primitivegstpipelinegetdelay", (void*)primitivegstpipelinegetdelay},
	{"GStreamerPlugin", "primitivegstmessageparsebuffering", (void*)primitivegstmessageparsebuffering},
	{"GStreamerPlugin", "primitivegstmessagetypestring", (void*)primitivegstmessagetypestring},
	{"GStreamerPlugin", "primitiveSqueakSinkAudioGetData", (void*)primitiveSqueakSinkAudioGetData},
	{"GStreamerPlugin", "primitivegstelementseeksimple", (void*)primitivegstelementseeksimple},
	{"GStreamerPlugin", "primitivegobjectclasslistproperties", (void*)primitivegobjectclasslistproperties},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyintatIndex", (void*)primitivegobjectclasslistpropertyintatIndex},
	{"GStreamerPlugin", "primitivegstpipelinegetlaststreamtime", (void*)primitivegstpipelinegetlaststreamtime},
	{"GStreamerPlugin", "primitivegstregistryforksetenabled", (void*)primitivegstregistryforksetenabled},
	{"GStreamerPlugin", "primitivegobjectgetulonglongfrom", (void*)primitivegobjectgetulonglongfrom},
	{"GStreamerPlugin", "primitivegobjectgetpointerfrom", (void*)primitivegobjectgetpointerfrom},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertystringatIndex", (void*)primitivegobjectclasslistpropertystringatIndex},
	{"GStreamerPlugin", "primitivegstelementfactorygetklass", (void*)primitivegstelementfactorygetklass},
	{"GStreamerPlugin", "primitivegstpipelineautoclock", (void*)primitivegstpipelineautoclock},
	{"GStreamerPlugin", "primitivegstpadsetactive", (void*)primitivegstpadsetactive},
	{"GStreamerPlugin", "primitivegstcapstostring", (void*)primitivegstcapstostring},
	{"GStreamerPlugin", "primitivegstpipelinegetautoflushbus", (void*)primitivegstpipelinegetautoflushbus},
	{"GStreamerPlugin", "primitivegstelementgetrequestpad", (void*)primitivegstelementgetrequestpad},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyfloatatIndex", (void*)primitivegobjectclasslistpropertyfloatatIndex},
	{"GStreamerPlugin", "primitivegsignalconnect", (void*)primitivegsignalconnect},
	{"GStreamerPlugin", "primitivegstelementfactorycreate", (void*)primitivegstelementfactorycreate},
	{"GStreamerPlugin", "primitivegstpipelinegetclock", (void*)primitivegstpipelinegetclock},
	{"GStreamerPlugin", "primitivegstelementlinkfiltered", (void*)primitivegstelementlinkfiltered},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertylongatIndex", (void*)primitivegobjectclasslistpropertylongatIndex},
	{"GStreamerPlugin", "primitivegstcapsfromstring", (void*)primitivegstcapsfromstring},
	{"GStreamerPlugin", "primitivegstbinnew", (void*)primitivegstbinnew},
	{"GStreamerPlugin", "primitiveSqueakSinkGetHeight", (void*)primitiveSqueakSinkGetHeight},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyulongatIndex", (void*)primitivegobjectclasslistpropertyulongatIndex},
	{"GStreamerPlugin", "primitivegstpipelinenew", (void*)primitivegstpipelinenew},
	{"GStreamerPlugin", "primitivegstmessageparsestatechanged", (void*)primitivegstmessageparsestatechanged},
	{"GStreamerPlugin", "primitivegobjectgetstringfrom", (void*)primitivegobjectgetstringfrom},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertypointeratIndex", (void*)primitivegobjectclasslistpropertypointeratIndex},
	{"GStreamerPlugin", "primitivegstversionstring", (void*)primitivegstversionstring},
	{"GStreamerPlugin", "primitivegstpipelinesetnewstreamtime", (void*)primitivegstpipelinesetnewstreamtime},
	{"GStreamerPlugin", "primitivegstsegtrapsetenabled", (void*)primitivegstsegtrapsetenabled},
	{"GStreamerPlugin", "primitivegstpipelinesetautoflushbus", (void*)primitivegstpipelinesetautoflushbus},
	{"GStreamerPlugin", "primitivegstsegtrapisenabled", (void*)primitivegstsegtrapisenabled},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertydoubleatIndex", (void*)primitivegobjectclasslistpropertydoubleatIndex},
	{"GStreamerPlugin", "primitivegstelementqueryduration", (void*)primitivegstelementqueryduration},
	{"GStreamerPlugin", "primitivegstmessageparseduration", (void*)primitivegstmessageparseduration},
	{"GStreamerPlugin", "primitivegstelementfactorymake", (void*)primitivegstelementfactorymake},
	{"GStreamerPlugin", "primitivegstinitcheck", (void*)primitivegstinitcheck},
	{"GStreamerPlugin", "primitivegstmessageparsesegmentstart", (void*)primitivegstmessageparsesegmentstart},
	{"GStreamerPlugin", "primitivegstpadsetcaps", (void*)primitivegstpadsetcaps},
	{"GStreamerPlugin", "primitivegstelementfactoryfind", (void*)primitivegstelementfactoryfind},
	{"GStreamerPlugin", "primitiveSqueakSinkGetFrameRateDenominator", (void*)primitiveSqueakSinkGetFrameRateDenominator},
	{"GStreamerPlugin", "primitivegobjectgetfloatfrom", (void*)primitivegobjectgetfloatfrom},
	{"GStreamerPlugin", "primitivegstmessageunref", (void*)primitivegstmessageunref},
	{"GStreamerPlugin", "primitivegobjectsetdoubleon", (void*)primitivegobjectsetdoubleon},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyboolatIndex", (void*)primitivegobjectclasslistpropertyboolatIndex},
	{"GStreamerPlugin", "primitivegetoop", (void*)primitivegetoop},
	{"GStreamerPlugin", "primitivegobjectsetlongon", (void*)primitivegobjectsetlongon},
	{"GStreamerPlugin", "primitivegobjectsetfloaton", (void*)primitivegobjectsetfloaton},
	{"GStreamerPlugin", "primitivegstelementseek", (void*)primitivegstelementseek},
	{"GStreamerPlugin", "primitivegstghostpadnew", (void*)primitivegstghostpadnew},
	{"GStreamerPlugin", "primitivegstelementgetstaticpad", (void*)primitivegstelementgetstaticpad},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertylonglongatIndex", (void*)primitivegobjectclasslistpropertylonglongatIndex},
	{"GStreamerPlugin", "primitivegstpipelineuseclock", (void*)primitivegstpipelineuseclock},
	{"GStreamerPlugin", "primitivegobjectgetsmalltalkobject", (void*)primitivegobjectgetsmalltalkobject},
	{"GStreamerPlugin", "primitivegobjectgetboolfrom", (void*)primitivegobjectgetboolfrom},
	{"GStreamerPlugin", "primitivegstbuspeek", (void*)primitivegstbuspeek},
	{"GStreamerPlugin", "primitivegstelementfactorygetauthor", (void*)primitivegstelementfactorygetauthor},
	{"GStreamerPlugin", "primitiveSqueakSinkVideo", (void*)primitiveSqueakSinkVideo},
	{"GStreamerPlugin", "primitivegobjectgetlonglongfrom", (void*)primitivegobjectgetlonglongfrom},
	{"GStreamerPlugin", "primitivegstobjectunref", (void*)primitivegstobjectunref},
	{"GStreamerPlugin", "primitivegobjectgetulongfrom", (void*)primitivegobjectgetulongfrom},
	{"GStreamerPlugin", "primitivegstelementgetstate", (void*)primitivegstelementgetstate},
	{"GStreamerPlugin", "primitivegstpadgetcaps", (void*)primitivegstpadgetcaps},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyuintatIndex", (void*)primitivegobjectclasslistpropertyuintatIndex},
	{"GStreamerPlugin", "primitivegobjectsetlonglongon", (void*)primitivegobjectsetlonglongon},
	{"GStreamerPlugin", "primitivegobjectsetboolon", (void*)primitivegobjectsetboolon},
	{"GStreamerPlugin", "primitivegstpadacceptcaps", (void*)primitivegstpadacceptcaps},
	{"GStreamerPlugin", "getModuleName", (void*)getModuleName},
	{"GStreamerPlugin", "primitivegetinterpreterproxy", (void*)primitivegetinterpreterproxy},
	{"GStreamerPlugin", "primitivegstelementadd", (void*)primitivegstelementadd},
	{"GStreamerPlugin", "primitiveSqueakSinkGetWidth", (void*)primitiveSqueakSinkGetWidth},
	{"GStreamerPlugin", "primitivegobjectclasslistpropertyenumatIndex", (void*)primitivegobjectclasslistpropertyenumatIndex},
	{"GStreamerPlugin", "primitivegobjectgetlongfrom", (void*)primitivegobjectgetlongfrom},
	{"GStreamerPlugin", "primitivegstelementgsignalconnect", (void*)primitivegstelementgsignalconnect},
	{"GStreamerPlugin", "primitivegstbuspop", (void*)primitivegstbuspop},
	{"GStreamerPlugin", "primitiveSqueakSrcWithTime", (void*)primitiveSqueakSrcWithTime},
	{"GStreamerPlugin", "primitivegstelementfactorygeturitype", (void*)primitivegstelementfactorygeturitype},
	{"GStreamerPlugin", "primitivegstbinadd", (void*)primitivegstbinadd},
	{"GStreamerPlugin", "primitiveSqueakSinkAllocate", (void*)primitiveSqueakSinkAllocate},
	{"GStreamerPlugin", "primitivegstelementqueryconvert", (void*)primitivegstelementqueryconvert},
	{"GStreamerPlugin", "primitivegstpipelinegetbus", (void*)primitivegstpipelinegetbus},
	{"GStreamerPlugin", "primitivegstmessageparsesegmentdone", (void*)primitivegstmessageparsesegmentdone},
	{"GStreamerPlugin", "primitiveSqueakSrcAllocate", (void*)primitiveSqueakSrcAllocate},
	{"GStreamerPlugin", "primitivegobjectfree", (void*)primitivegobjectfree},
	{"GStreamerPlugin", "primitivegstelementlink", (void*)primitivegstelementlink},
	{"GStreamerPlugin", "primitivegobjectsetpointeron", (void*)primitivegobjectsetpointeron},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

