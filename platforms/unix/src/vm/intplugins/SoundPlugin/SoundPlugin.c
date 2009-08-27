/* Automatically generated from Squeak on an Array(26 August 2009 10:01:34 pm)
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
#include "SoundPlugin.h"

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
EXPORT(sqInt) primitiveSoundAvailableSpace(void);
EXPORT(sqInt) primitiveSoundGetRecordingSampleRate(void);
EXPORT(sqInt) primitiveSoundGetSwitch(void);
EXPORT(sqInt) primitiveSoundGetVolume(void);
EXPORT(sqInt) primitiveSoundInsertSamples(void);
EXPORT(sqInt) primitiveSoundPlaySamples(void);
EXPORT(sqInt) primitiveSoundPlaySilence(void);
EXPORT(sqInt) primitiveSoundRecordSamples(void);
EXPORT(sqInt) primitiveSoundSetDevice(void);
EXPORT(sqInt) primitiveSoundSetLeftVolume(void);
EXPORT(sqInt) primitiveSoundSetRecordLevel(void);
EXPORT(sqInt) primitiveSoundSetSwitch(void);
EXPORT(sqInt) primitiveSoundStart(void);
EXPORT(sqInt) primitiveSoundStartWithSemaphore(void);
EXPORT(sqInt) primitiveSoundStartRecording(void);
EXPORT(sqInt) primitiveSoundStop(void);
EXPORT(sqInt) primitiveSoundStopRecording(void);
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
	"SoundPlugin 26 August 2009 (i)"
#else
	"SoundPlugin 26 August 2009 (e)"
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
	return soundInit();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Returns the number of bytes of available sound output buffer space.  This should be (frames*4) if the device is in stereo mode, or (frames*2) otherwise */

EXPORT(sqInt) primitiveSoundAvailableSpace(void) {
	sqInt frames;
	sqInt _return_value;


	/* -1 if sound output not started */

	frames = snd_AvailableSpace();
	interpreterProxy->success(frames >= 0);
	_return_value = interpreterProxy->positive32BitIntegerFor(frames);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Return a float representing the actual sampling rate during recording. Fail if not currently recording. */

EXPORT(sqInt) primitiveSoundGetRecordingSampleRate(void) {
	double  rate;
	sqInt _return_value;


	/* fail if not recording */

	rate = snd_GetRecordingSampleRate();
	_return_value = interpreterProxy->floatObjectOf(rate);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Get the switch of device at id.  captureFlag specifies the direction of operation, and chennel specifies the channel of the device. */

EXPORT(sqInt) primitiveSoundGetSwitch(void) {
	sqInt ret;
	sqInt id;
	sqInt captureFlag;
	sqInt channel;
	sqInt _return_value;

	id = interpreterProxy->stackIntegerValue(2);
	captureFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	channel = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	ret = snd_GetSwitch(id, captureFlag, channel);
	if (ret < 0) {
		interpreterProxy->primitiveFail();
		return null;
	}
	_return_value = (ret) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	Set the sound input recording level. */

EXPORT(sqInt) primitiveSoundGetVolume(void) {
	double  left;
	double  right;
	sqInt results;

	left = 0;
	right = 0;
	snd_Volume((double *) &left,(double *) &right);
	interpreterProxy->pushRemappableOop(interpreterProxy->floatObjectOf(right));
	interpreterProxy->pushRemappableOop(interpreterProxy->floatObjectOf(left));
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	results = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, results, interpreterProxy->popRemappableOop());
	interpreterProxy->storePointerofObjectwithValue(1, results, interpreterProxy->popRemappableOop());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, results);
	return null;
}


/*	Insert a buffer's worth of sound samples into the currently playing  
	buffer. Used to make a sound start playing as quickly as possible. The  
	new sound is mixed with the previously buffered sampled. */
/*	Details: Unlike primitiveSoundPlaySamples, this primitive always starts  
	with the first sample the given sample buffer. Its third argument  
	specifies the number of samples past the estimated sound output buffer  
	position the inserted sound should start. If successful, it returns the  
	number of samples inserted. */

EXPORT(sqInt) primitiveSoundInsertSamples(void) {
	sqInt framesPlayed;
	sqInt frameCount;
	usqInt *buf;
	sqInt leadTime;
	sqInt _return_value;

	frameCount = interpreterProxy->stackIntegerValue(2);
	interpreterProxy->success(interpreterProxy->isWords(interpreterProxy->stackValue(1)));
	buf = ((unsigned *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	leadTime = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(frameCount <= (interpreterProxy->slotSizeOf((oopForPointer( buf ) - 4))));
	if (!(interpreterProxy->failed())) {
		framesPlayed = snd_InsertSamplesFromLeadTime(frameCount, (int)buf, leadTime);
		interpreterProxy->success(framesPlayed >= 0);
	}
	_return_value = interpreterProxy->positive32BitIntegerFor(framesPlayed);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	Output a buffer's worth of sound samples. */

EXPORT(sqInt) primitiveSoundPlaySamples(void) {
	sqInt framesPlayed;
	sqInt frameCount;
	usqInt *buf;
	sqInt startIndex;
	sqInt _return_value;

	frameCount = interpreterProxy->stackIntegerValue(2);
	interpreterProxy->success(interpreterProxy->isWords(interpreterProxy->stackValue(1)));
	buf = ((unsigned *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	startIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success((startIndex >= 1) && (((startIndex + frameCount) - 1) <= (interpreterProxy->slotSizeOf((oopForPointer( buf ) - 4)))));
	if (!(interpreterProxy->failed())) {
		framesPlayed = snd_PlaySamplesFromAtLength(frameCount, (int)buf, startIndex - 1);
		interpreterProxy->success(framesPlayed >= 0);
	}
	_return_value = interpreterProxy->positive32BitIntegerFor(framesPlayed);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	Output a buffer's worth of silence. Returns the number of sample frames played. */

EXPORT(sqInt) primitiveSoundPlaySilence(void) {
	sqInt framesPlayed;
	sqInt _return_value;


	/* -1 if sound output not started */

	framesPlayed = snd_PlaySilence();
	interpreterProxy->success(framesPlayed >= 0);
	_return_value = interpreterProxy->positive32BitIntegerFor(framesPlayed);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Record a buffer's worth of 16-bit sound samples. */

EXPORT(sqInt) primitiveSoundRecordSamples(void) {
	sqInt bufSizeInBytes;
	sqInt samplesRecorded;
	usqInt *buf;
	sqInt startWordIndex;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isWords(interpreterProxy->stackValue(1)));
	buf = ((unsigned *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	startWordIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		bufSizeInBytes = (interpreterProxy->slotSizeOf((oopForPointer( buf ) - 4))) * 4;
		interpreterProxy->success((startWordIndex >= 1) && (((startWordIndex - 1) * 2) < bufSizeInBytes));
	}
	if (!(interpreterProxy->failed())) {
		samplesRecorded = snd_RecordSamplesIntoAtLength((int)buf, startWordIndex - 1, bufSizeInBytes);
	}
	_return_value = interpreterProxy->positive32BitIntegerFor(samplesRecorded);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Set the device slot specified by id with deviceName. */

EXPORT(sqInt) primitiveSoundSetDevice(void) {
	sqInt ret;
	sqInt i;
	sqInt s;
	char buffer[128];
	char *deviceName;
	sqInt isArgNil;
	sqInt id;
	sqInt deviceNameOop;
	sqInt _return_value;

	id = interpreterProxy->stackIntegerValue(1);
	deviceNameOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	;
	isArgNil = (interpreterProxy->nilObject()) == deviceNameOop;
	if (!(isArgNil || (interpreterProxy->isBytes(deviceNameOop)))) {
		primitiveFail();
		return null;
	}
	if ((!isArgNil) && ((s = interpreterProxy->stSizeOf(deviceNameOop)) > 127)) {
		primitiveFail();
		return null;
	}
	if (isArgNil) {
		ret = snd_SetDevice(id, NULL);
	} else {
		deviceName = interpreterProxy->firstIndexableField(deviceNameOop);
		for (i = 0; i <= (s - 1); i += 1) {
			buffer[i] = (deviceName[i]);
		}
		buffer[s] = 0;
		ret = snd_SetDevice(id, buffer);
	}
	if (ret < 0) {
		primitiveFail();
		return null;
	}
	_return_value = (ret) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	Set the sound input recording level. */

EXPORT(sqInt) primitiveSoundSetLeftVolume(void) {
	double aLeftVolume;
	double aRightVolume;

	aLeftVolume = interpreterProxy->stackFloatValue(1);
	aRightVolume = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		snd_SetVolume(aLeftVolume,aRightVolume);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Set the sound input recording level. */

EXPORT(sqInt) primitiveSoundSetRecordLevel(void) {
	sqInt level;

	level = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		snd_SetRecordLevel(level);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Set the switch of device at id.  captureFlag specifies the direction of operation, and parameter is the new value. */

EXPORT(sqInt) primitiveSoundSetSwitch(void) {
	sqInt ret;
	sqInt id;
	sqInt captureFlag;
	sqInt parameter;
	sqInt _return_value;

	id = interpreterProxy->stackIntegerValue(2);
	captureFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	parameter = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	ret = snd_SetSwitch(id, captureFlag, parameter);
	if (ret < 0) {
		interpreterProxy->primitiveFail();
		return null;
	}
	_return_value = (ret) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	Start the double-buffered sound output with the given buffer size, sample rate, and stereo flag. */

EXPORT(sqInt) primitiveSoundStart(void) {
	sqInt bufFrames;
	sqInt samplesPerSec;
	sqInt stereoFlag;

	bufFrames = interpreterProxy->stackIntegerValue(2);
	samplesPerSec = interpreterProxy->stackIntegerValue(1);
	stereoFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(snd_Start(bufFrames, samplesPerSec, stereoFlag, 0));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	Start the double-buffered sound output with the given buffer size, sample rate, stereo flag, and semaphore index. */

EXPORT(sqInt) primitiveSoundStartWithSemaphore(void) {
	sqInt bufFrames;
	sqInt samplesPerSec;
	sqInt stereoFlag;
	sqInt semaIndex;

	bufFrames = interpreterProxy->stackIntegerValue(3);
	samplesPerSec = interpreterProxy->stackIntegerValue(2);
	stereoFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	semaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(snd_Start(bufFrames, samplesPerSec, stereoFlag, semaIndex));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(4);
	return null;
}


/*	Start recording sound with the given parameters. */

EXPORT(sqInt) primitiveSoundStartRecording(void) {
	sqInt desiredSamplesPerSec;
	sqInt stereoFlag;
	sqInt semaIndex;

	desiredSamplesPerSec = interpreterProxy->stackIntegerValue(2);
	stereoFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	semaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	snd_StartRecording(desiredSamplesPerSec, stereoFlag, semaIndex);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	Stop double-buffered sound output. */

EXPORT(sqInt) primitiveSoundStop(void) {
	snd_Stop();
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}


/*	Stop recording sound. */

EXPORT(sqInt) primitiveSoundStopRecording(void) {
	snd_StopRecording();
	if (interpreterProxy->failed()) {
		return null;
	}
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
	return soundShutdown();
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SoundPlugin_exports[][3] = {
	{"SoundPlugin", "primitiveSoundStart", (void*)primitiveSoundStart},
	{"SoundPlugin", "shutdownModule", (void*)shutdownModule},
	{"SoundPlugin", "primitiveSoundSetSwitch", (void*)primitiveSoundSetSwitch},
	{"SoundPlugin", "primitiveSoundGetSwitch", (void*)primitiveSoundGetSwitch},
	{"SoundPlugin", "primitiveSoundStartRecording", (void*)primitiveSoundStartRecording},
	{"SoundPlugin", "setInterpreter", (void*)setInterpreter},
	{"SoundPlugin", "primitiveSoundSetDevice", (void*)primitiveSoundSetDevice},
	{"SoundPlugin", "primitiveSoundPlaySamples", (void*)primitiveSoundPlaySamples},
	{"SoundPlugin", "primitiveSoundStopRecording", (void*)primitiveSoundStopRecording},
	{"SoundPlugin", "primitiveSoundSetRecordLevel", (void*)primitiveSoundSetRecordLevel},
	{"SoundPlugin", "getModuleName", (void*)getModuleName},
	{"SoundPlugin", "primitiveSoundRecordSamples", (void*)primitiveSoundRecordSamples},
	{"SoundPlugin", "primitiveSoundAvailableSpace", (void*)primitiveSoundAvailableSpace},
	{"SoundPlugin", "primitiveSoundStartWithSemaphore", (void*)primitiveSoundStartWithSemaphore},
	{"SoundPlugin", "initialiseModule", (void*)initialiseModule},
	{"SoundPlugin", "primitiveSoundSetLeftVolume", (void*)primitiveSoundSetLeftVolume},
	{"SoundPlugin", "primitiveSoundPlaySilence", (void*)primitiveSoundPlaySilence},
	{"SoundPlugin", "primitiveSoundGetRecordingSampleRate", (void*)primitiveSoundGetRecordingSampleRate},
	{"SoundPlugin", "primitiveSoundInsertSamples", (void*)primitiveSoundInsertSamples},
	{"SoundPlugin", "primitiveSoundGetVolume", (void*)primitiveSoundGetVolume},
	{"SoundPlugin", "primitiveSoundStop", (void*)primitiveSoundStop},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

