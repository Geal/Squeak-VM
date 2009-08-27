/* Automatically generated from Squeak on an Array(26 August 2009 10:02:14 pm)
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
#include "Mpeg3Plugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static sqInt checkFileEntry(mpeg3_t *  aMpegFile);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt makeFileEntry(mpeg3_t *  aMpegFile);
static mpeg3_t * mpeg3tValueOf(sqInt mpeg3tHandle);
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveMPEG3AudioChannels(void);
EXPORT(sqInt) primitiveMPEG3AudioSamples(void);
EXPORT(sqInt) primitiveMPEG3CheckSig(void);
EXPORT(sqInt) primitiveMPEG3Close(void);
EXPORT(sqInt) primitiveMPEG3DropFrames(void);
EXPORT(sqInt) primitiveMPEG3EndOfAudio(void);
EXPORT(sqInt) primitiveMPEG3EndOfVideo(void);
EXPORT(sqInt) primitiveMPEG3FrameRate(void);
EXPORT(sqInt) primitiveMPEG3GenerateToc(void);
EXPORT(sqInt) primitiveMPEG3GetFrame(void);
EXPORT(sqInt) primitiveMPEG3GetSample(void);
EXPORT(sqInt) primitiveMPEG3GetTime(void);
EXPORT(sqInt) primitiveMPEG3HasAudio(void);
EXPORT(sqInt) primitiveMPEG3HasVideo(void);
EXPORT(sqInt) primitiveMPEG3Open(void);
EXPORT(sqInt) primitiveMPEG3OpenABuffer(void);
EXPORT(sqInt) primitiveMPEG3PreviousFrame(void);
EXPORT(sqInt) primitiveMPEG3ReReadAudio(void);
EXPORT(sqInt) primitiveMPEG3ReadAudio(void);
EXPORT(sqInt) primitiveMPEG3ReadFrameBufferOffset(void);
EXPORT(sqInt) primitiveMPEG3ReadFrame(void);
EXPORT(sqInt) primitiveMPEG3SampleRate(void);
EXPORT(sqInt) primitiveMPEG3SeekPercentage(void);
EXPORT(sqInt) primitiveMPEG3SetCpus(void);
EXPORT(sqInt) primitiveMPEG3SetFrame(void);
EXPORT(sqInt) primitiveMPEG3SetMmx(void);
EXPORT(sqInt) primitiveMPEG3SetSample(void);
EXPORT(sqInt) primitiveMPEG3TellPercentage(void);
EXPORT(sqInt) primitiveMPEG3TotalAStreams(void);
EXPORT(sqInt) primitiveMPEG3TotalVStreams(void);
EXPORT(sqInt) primitiveMPEG3VideoFrames(void);
EXPORT(sqInt) primitiveMPEG3VideoHeight(void);
EXPORT(sqInt) primitiveMPEG3VideoWidth(void);
#pragma export off
static sqInt removeFileEntry(mpeg3_t *  aMpegFile);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt sqAssert(sqInt aBool);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static sqInt maximumNumberOfFilesToWatch;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"Mpeg3Plugin 26 August 2009 (i)"
#else
	"Mpeg3Plugin 26 August 2009 (e)"
#endif
;
static mpeg3_t *mpegFiles[1024+1];


static sqInt checkFileEntry(mpeg3_t *  aMpegFile) {
	sqInt i;

	for (i = 1; i <= maximumNumberOfFilesToWatch; i += 1) {
		if ((mpegFiles[i]) == aMpegFile) {
			return 1;
		}
	}
	return 0;
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
	sqInt i;

	maximumNumberOfFilesToWatch = 1024;
	for (i = 1; i <= maximumNumberOfFilesToWatch; i += 1) {
		mpegFiles[i] = 0;
	}
	return true;
}

static sqInt makeFileEntry(mpeg3_t *  aMpegFile) {
	sqInt i;

	for (i = 1; i <= maximumNumberOfFilesToWatch; i += 1) {
		if ((mpegFiles[i]) == 0) {
			mpegFiles[i] = aMpegFile;
			return 1;
		}
	}
	return 0;
}


/*	Return a pointer to the first byte of of the mpeg3_t record within the  
	given Smalltalk object, or nil if socketOop is not a mpeg3_t record. */

static mpeg3_t * mpeg3tValueOf(sqInt mpeg3tHandle) {
	mpeg3_t **  index;
	sqInt check;

	interpreterProxy->success((interpreterProxy->isBytes(mpeg3tHandle)) && ((interpreterProxy->byteSizeOf(mpeg3tHandle)) == 4));
	if (interpreterProxy->failed()) {
		return null;
	} else {
		index = ((mpeg3_t **) (interpreterProxy->firstIndexableField(mpeg3tHandle)));
		check = checkFileEntry(*index);
		if (check == 0) {
			return null;
		}
		return *index;
	}
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	int mpeg3_audio_channels(mpeg3_t *file,int stream) */

EXPORT(sqInt) primitiveMPEG3AudioChannels(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber >= (mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_audio_channels(file,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	long mpeg3_audio_samples(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3AudioSamples(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_audio_samples(file,aNumber);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_check_sig(char *path) */

EXPORT(sqInt) primitiveMPEG3CheckSig(void) {
	sqInt sz;
	char storage[1024] ;
	sqInt result;
	char *path;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	path = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	sz = interpreterProxy->byteSizeOf((oopForPointer( path ) - 4));
	interpreterProxy->ioFilenamefromStringofLengthresolveAliases(storage, path, sz, 1);
	result = mpeg3_check_sig(storage);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	int mpeg3_close(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3Close(void) {
	mpeg3_t **  index;
	mpeg3_t *  file;
	sqInt fileHandle;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	removeFileEntry(file); mpeg3_close(file);
	index = ((mpeg3_t **) (interpreterProxy->firstIndexableField(fileHandle)));
	*index = 0;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}


/*	int mpeg3_drop_frames(mpeg3_t *file, long frames, int stream) */

EXPORT(sqInt) primitiveMPEG3DropFrames(void) {
	sqInt result;
	mpeg3_t *  file;
	sqInt fileHandle;
	sqInt aFrameNumber;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(2);
	aFrameNumber = interpreterProxy->stackIntegerValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, 0);
		return null;
	}
	result = mpeg3_drop_frames(file,aFrameNumber,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	int mpeg3_end_of_audio(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3EndOfAudio(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_end_of_audio(file,aNumber);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_end_of_video(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3EndOfVideo(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_end_of_video(file,aNumber);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	float mpeg3_frame_rate(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3FrameRate(void) {
	mpeg3_t *  file;
	double  result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result =  mpeg3_frame_rate(file,aNumber);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_generate_toc_for_Squeak(FILE *output, char *path, int timecode_search, int print_streams, char *buffer) */

EXPORT(sqInt) primitiveMPEG3GenerateToc(void) {
	sqInt bufferSize;
	mpeg3_t *  file;
	sqInt fileHandle;
	sqInt timecode;
	sqInt streams;
	char *aString;

	fileHandle = interpreterProxy->stackValue(3);
	timecode = interpreterProxy->stackIntegerValue(2);
	streams = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aString = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	bufferSize = interpreterProxy->slotSizeOf(interpreterProxy->stackValue(0));
	mpeg3_generate_toc_for_Squeak(file,timecode,streams,aString,bufferSize);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(4);
	return null;
}


/*	long mpeg3_get_frame(mpeg3_t *file,int stream) */

EXPORT(sqInt) primitiveMPEG3GetFrame(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_get_frame(file,aNumber);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_video_width(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3GetSample(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_get_sample(file,aNumber);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	double mpeg3_get_time(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3GetTime(void) {
	mpeg3_t *  file;
	double  result;
	sqInt fileHandle;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	result = mpeg3_get_time(file);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	int mpeg3_has_audio(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3HasAudio(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	result = mpeg3_has_audio(file);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	int mpeg3_has_video(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3HasVideo(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	result = mpeg3_has_video(file);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	mpeg3_t* mpeg3_open(char *path) */

EXPORT(sqInt) primitiveMPEG3Open(void) {
	sqInt mpeg3Oop;
	mpeg3_t ** index;
	sqInt sz;
	char storage[1024];
	char *path;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	path = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	sz = interpreterProxy->byteSizeOf((oopForPointer( path ) - 4));
	interpreterProxy->ioFilenamefromStringofLengthresolveAliases(storage, path, sz, 1);
	mpeg3Oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), 4);
	index = ((mpeg3_t **) (interpreterProxy->firstIndexableField(mpeg3Oop)));
	*index = mpeg3_open(storage,0); makeFileEntry(*index);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, mpeg3Oop);
	return null;
}

EXPORT(sqInt) primitiveMPEG3OpenABuffer(void) {
	sqInt mpeg3Oop;
	mpeg3_t ** index;
	char *path;
	sqInt size;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	path = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	size = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	mpeg3Oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), 4);
	index = ((mpeg3_t **) (interpreterProxy->firstIndexableField(mpeg3Oop)));
	*index = mpeg3_open(path,size); makeFileEntry(*index);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, mpeg3Oop);
	return null;
}


/*	int mpeg3_previous_frame(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3PreviousFrame(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (file == null) {
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_previous_frame(file,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_reread_audio(mpeg3_t *file, 
		float *output_f, 
		short *output_i, 
		int channel, 
		long samples,
		int stream) */

EXPORT(sqInt) primitiveMPEG3ReReadAudio(void) {
	short *  arrayBase;
	sqInt result;
	mpeg3_t *  file;
	sqInt fileHandle;
	sqInt *anArray;
	sqInt aChannelNumber;
	sqInt aSampleNumber;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(4);
	interpreterProxy->success(interpreterProxy->isIndexable(interpreterProxy->stackValue(3)));
	anArray = ((int *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	aChannelNumber = interpreterProxy->stackIntegerValue(2);
	aSampleNumber = interpreterProxy->stackIntegerValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(6, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(6, 0);
		return null;
	}
	arrayBase = ((short *) anArray);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = mpeg3_reread_audio(file,(float *) NULL,arrayBase,aChannelNumber,aSampleNumber,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(6, _return_value);
	return null;
}


/*	int mpeg3_read_audio(mpeg3_t *file, 
		float *output_f, 
		short *output_i, 
		int channel, 
		long samples,
		int stream) */

EXPORT(sqInt) primitiveMPEG3ReadAudio(void) {
	short *  arrayBase;
	sqInt result;
	mpeg3_t *  file;
	sqInt fileHandle;
	sqInt *anArray;
	sqInt aChannelNumber;
	sqInt aSampleNumber;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(4);
	interpreterProxy->success(interpreterProxy->isIndexable(interpreterProxy->stackValue(3)));
	anArray = ((int *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	aChannelNumber = interpreterProxy->stackIntegerValue(2);
	aSampleNumber = interpreterProxy->stackIntegerValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(6, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(6, 0);
		return null;
	}
	arrayBase = ((short *) anArray);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = mpeg3_read_audio(file,(float *) NULL,arrayBase,aChannelNumber,aSampleNumber,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(6, _return_value);
	return null;
}


/*	int mpeg3_read_frame(mpeg3_t *file, 
		unsigned char **output_rows, 
		int in_x, 
		int in_y, 
		int in_w, 
		int in_h, 
		int out_w, 
		int out_h, 
		int color_model,
		int stream) */

EXPORT(sqInt) primitiveMPEG3ReadFrameBufferOffset(void) {
	unsigned char *bufferBaseAddr;
	sqInt result;
	sqInt i;
	unsigned char  ** outputRowsPtr;
	mpeg3_t * file;
	sqInt fileHandle;
	usqInt *aBuffer;
	sqInt aBufferOffset;
	sqInt xNumber;
	sqInt yNumber;
	sqInt width;
	sqInt height;
	sqInt outWidth;
	sqInt outHeight;
	sqInt model;
	sqInt aNumber;
	sqInt aByteNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(11);
	interpreterProxy->success(interpreterProxy->isWords(interpreterProxy->stackValue(10)));
	aBuffer = ((unsigned *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(10))));
	aBufferOffset = interpreterProxy->stackIntegerValue(9);
	xNumber = interpreterProxy->stackIntegerValue(8);
	yNumber = interpreterProxy->stackIntegerValue(7);
	width = interpreterProxy->stackIntegerValue(6);
	height = interpreterProxy->stackIntegerValue(5);
	outWidth = interpreterProxy->stackIntegerValue(4);
	outHeight = interpreterProxy->stackIntegerValue(3);
	model = interpreterProxy->stackIntegerValue(2);
	aNumber = interpreterProxy->stackIntegerValue(1);
	aByteNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(13, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(13, 0);
		return null;
	}
	bufferBaseAddr = ((unsigned char *) aBuffer);
	outputRowsPtr = (unsigned char **) memoryAllocate(1,sizeof(unsigned char*) * outHeight);
	for (i = 0; i <= (outHeight - 1); i += 1) {
		outputRowsPtr[i] = ((bufferBaseAddr + aBufferOffset) + (aByteNumber * i));
	}
	result = mpeg3_read_frame(file,outputRowsPtr,xNumber,yNumber,width,height,outWidth,outHeight,model,aNumber);
	memoryFree(outputRowsPtr);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(13, _return_value);
	return null;
}


/*	int mpeg3_read_frame(mpeg3_t *file, 
		unsigned char **output_rows, 
		int in_x, 
		int in_y, 
		int in_w, 
		int in_h, 
		int out_w, 
		int out_h, 
		int color_model,
		int stream) */

EXPORT(sqInt) primitiveMPEG3ReadFrame(void) {
	unsigned char * bufferBaseAddr;
	sqInt result;
	sqInt i;
	unsigned char  **  outputRowsPtr;
	mpeg3_t *  file;
	sqInt fileHandle;
	usqInt *aBuffer;
	sqInt xNumber;
	sqInt yNumber;
	sqInt width;
	sqInt height;
	sqInt outWidth;
	sqInt outHeight;
	sqInt model;
	sqInt aNumber;
	sqInt aByteNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(10);
	interpreterProxy->success(interpreterProxy->isWords(interpreterProxy->stackValue(9)));
	aBuffer = ((unsigned *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(9))));
	xNumber = interpreterProxy->stackIntegerValue(8);
	yNumber = interpreterProxy->stackIntegerValue(7);
	width = interpreterProxy->stackIntegerValue(6);
	height = interpreterProxy->stackIntegerValue(5);
	outWidth = interpreterProxy->stackIntegerValue(4);
	outHeight = interpreterProxy->stackIntegerValue(3);
	model = interpreterProxy->stackIntegerValue(2);
	aNumber = interpreterProxy->stackIntegerValue(1);
	aByteNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(12, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(12, 0);
		return null;
	}
	bufferBaseAddr = ((unsigned char *) aBuffer);
	outputRowsPtr = (unsigned char **) memoryAllocate(1,sizeof(unsigned char*) * outHeight);
	for (i = 0; i <= (outHeight - 1); i += 1) {
		outputRowsPtr[i] = (bufferBaseAddr + (aByteNumber * i));
	}
	result = mpeg3_read_frame(file,outputRowsPtr,xNumber,yNumber,width,height,outWidth,outHeight,model,aNumber);
	memoryFree(outputRowsPtr);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(12, _return_value);
	return null;
}


/*	int mpeg3_sample_rate(mpeg3_t *file,int stream) */

EXPORT(sqInt) primitiveMPEG3SampleRate(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_sample_rate(file,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_seek_percentage(mpeg3_t *file, double percentage) */

EXPORT(sqInt) primitiveMPEG3SeekPercentage(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	double aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (aNumber < 0.0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber > 1.0) {
		interpreterProxy->success(0);
		return null;
	}
	if (file == null) {
		return null;
	}
	result = mpeg3_seek_percentage(file,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_set_cpus(mpeg3_t *file, int cpus) */

EXPORT(sqInt) primitiveMPEG3SetCpus(void) {
	mpeg3_t *  file;
	sqInt fileHandle;
	sqInt cpus;

	fileHandle = interpreterProxy->stackValue(1);
	cpus = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (cpus < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (file == null) {
		return null;
	}
	mpeg3_set_cpus(file,cpus);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	int mpeg3_set_frame(mpeg3_t *file, long frame, int stream) */

EXPORT(sqInt) primitiveMPEG3SetFrame(void) {
	sqInt result;
	mpeg3_t *  file;
	sqInt fileHandle;
	double aFrameNumber;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(2);
	aFrameNumber = interpreterProxy->stackFloatValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, 0);
		return null;
	}
	result = mpeg3_set_frame(file,(long) aFrameNumber,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	int mpeg3_set_mmx(mpeg3_t *file, int use_mmx) */

EXPORT(sqInt) primitiveMPEG3SetMmx(void) {
	mpeg3_t *  file;
	sqInt fileHandle;
	sqInt mmx;

	fileHandle = interpreterProxy->stackValue(1);
	mmx = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	mpeg3_set_mmx(file,mmx);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	int mpeg3_set_sample(mpeg3_t *file, long sample, int stream) */

EXPORT(sqInt) primitiveMPEG3SetSample(void) {
	sqInt result;
	mpeg3_t *  file;
	sqInt fileHandle;
	double aSampleNumber;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(2);
	aSampleNumber = interpreterProxy->stackFloatValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_astreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, 0);
		return null;
	}
	if (aSampleNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	result = mpeg3_set_sample(file,aSampleNumber,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, _return_value);
	return null;
}


/*	double mpeg3_tell_percentage(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3TellPercentage(void) {
	mpeg3_t *  file;
	double  result;
	sqInt fileHandle;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	result = mpeg3_tell_percentage(file);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	int mpeg3_total_astreams(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3TotalAStreams(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, 0);
		return null;
	}
	result = mpeg3_total_astreams(file);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	int mpeg3_total_vstreams(mpeg3_t *file) */

EXPORT(sqInt) primitiveMPEG3TotalVStreams(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		return null;
	}
	result = mpeg3_total_vstreams(file);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	long mpeg3_video_frames(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3VideoFrames(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_video_frames(file,aNumber);
	_return_value = interpreterProxy->floatObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_video_height(mpeg3_t *file,int stream) */

EXPORT(sqInt) primitiveMPEG3VideoHeight(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_video_height(file,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}


/*	int mpeg3_video_width(mpeg3_t *file, int stream) */

EXPORT(sqInt) primitiveMPEG3VideoWidth(void) {
	mpeg3_t *  file;
	sqInt result;
	sqInt fileHandle;
	sqInt aNumber;
	sqInt _return_value;

	fileHandle = interpreterProxy->stackValue(1);
	aNumber = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	file = mpeg3tValueOf(fileHandle);
	if (file == null) {
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	if (aNumber < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if (aNumber >= (result = mpeg3_total_vstreams(file))) {
		interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, 0);
		return null;
	}
	result = mpeg3_video_width(file,aNumber);
	_return_value = interpreterProxy->integerObjectOf(result);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

static sqInt removeFileEntry(mpeg3_t *  aMpegFile) {
	sqInt i;

	for (i = 1; i <= maximumNumberOfFilesToWatch; i += 1) {
		if ((mpegFiles[i]) == aMpegFile) {
			mpegFiles[i] = 0;
			return 1;
		}
	}
	return 0;
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
	sqInt i;

	for (i = 1; i <= maximumNumberOfFilesToWatch; i += 1) {
		if ((mpegFiles[i]) != 0) {
			mpeg3_close(mpegFiles[i]);
			mpegFiles[i] = 0;
		}
	}
	return true;
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* Mpeg3Plugin_exports[][3] = {
	{"Mpeg3Plugin", "primitiveMPEG3EndOfAudio", (void*)primitiveMPEG3EndOfAudio},
	{"Mpeg3Plugin", "primitiveMPEG3EndOfVideo", (void*)primitiveMPEG3EndOfVideo},
	{"Mpeg3Plugin", "primitiveMPEG3GenerateToc", (void*)primitiveMPEG3GenerateToc},
	{"Mpeg3Plugin", "shutdownModule", (void*)shutdownModule},
	{"Mpeg3Plugin", "setInterpreter", (void*)setInterpreter},
	{"Mpeg3Plugin", "primitiveMPEG3TotalAStreams", (void*)primitiveMPEG3TotalAStreams},
	{"Mpeg3Plugin", "primitiveMPEG3SetMmx", (void*)primitiveMPEG3SetMmx},
	{"Mpeg3Plugin", "primitiveMPEG3ReadFrame", (void*)primitiveMPEG3ReadFrame},
	{"Mpeg3Plugin", "primitiveMPEG3SeekPercentage", (void*)primitiveMPEG3SeekPercentage},
	{"Mpeg3Plugin", "primitiveMPEG3ReReadAudio", (void*)primitiveMPEG3ReReadAudio},
	{"Mpeg3Plugin", "primitiveMPEG3SetCpus", (void*)primitiveMPEG3SetCpus},
	{"Mpeg3Plugin", "initialiseModule", (void*)initialiseModule},
	{"Mpeg3Plugin", "primitiveMPEG3AudioChannels", (void*)primitiveMPEG3AudioChannels},
	{"Mpeg3Plugin", "primitiveMPEG3HasVideo", (void*)primitiveMPEG3HasVideo},
	{"Mpeg3Plugin", "primitiveMPEG3VideoHeight", (void*)primitiveMPEG3VideoHeight},
	{"Mpeg3Plugin", "primitiveMPEG3HasAudio", (void*)primitiveMPEG3HasAudio},
	{"Mpeg3Plugin", "primitiveMPEG3SampleRate", (void*)primitiveMPEG3SampleRate},
	{"Mpeg3Plugin", "primitiveMPEG3DropFrames", (void*)primitiveMPEG3DropFrames},
	{"Mpeg3Plugin", "primitiveMPEG3AudioSamples", (void*)primitiveMPEG3AudioSamples},
	{"Mpeg3Plugin", "primitiveMPEG3VideoWidth", (void*)primitiveMPEG3VideoWidth},
	{"Mpeg3Plugin", "getModuleName", (void*)getModuleName},
	{"Mpeg3Plugin", "primitiveMPEG3ReadFrameBufferOffset", (void*)primitiveMPEG3ReadFrameBufferOffset},
	{"Mpeg3Plugin", "primitiveMPEG3Close", (void*)primitiveMPEG3Close},
	{"Mpeg3Plugin", "primitiveMPEG3GetFrame", (void*)primitiveMPEG3GetFrame},
	{"Mpeg3Plugin", "primitiveMPEG3OpenABuffer", (void*)primitiveMPEG3OpenABuffer},
	{"Mpeg3Plugin", "primitiveMPEG3TellPercentage", (void*)primitiveMPEG3TellPercentage},
	{"Mpeg3Plugin", "primitiveMPEG3VideoFrames", (void*)primitiveMPEG3VideoFrames},
	{"Mpeg3Plugin", "primitiveMPEG3CheckSig", (void*)primitiveMPEG3CheckSig},
	{"Mpeg3Plugin", "primitiveMPEG3SetFrame", (void*)primitiveMPEG3SetFrame},
	{"Mpeg3Plugin", "primitiveMPEG3GetTime", (void*)primitiveMPEG3GetTime},
	{"Mpeg3Plugin", "primitiveMPEG3ReadAudio", (void*)primitiveMPEG3ReadAudio},
	{"Mpeg3Plugin", "primitiveMPEG3TotalVStreams", (void*)primitiveMPEG3TotalVStreams},
	{"Mpeg3Plugin", "primitiveMPEG3PreviousFrame", (void*)primitiveMPEG3PreviousFrame},
	{"Mpeg3Plugin", "primitiveMPEG3Open", (void*)primitiveMPEG3Open},
	{"Mpeg3Plugin", "primitiveMPEG3GetSample", (void*)primitiveMPEG3GetSample},
	{"Mpeg3Plugin", "primitiveMPEG3FrameRate", (void*)primitiveMPEG3FrameRate},
	{"Mpeg3Plugin", "primitiveMPEG3SetSample", (void*)primitiveMPEG3SetSample},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

