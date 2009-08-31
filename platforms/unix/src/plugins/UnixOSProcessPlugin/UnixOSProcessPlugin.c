/* Automatically generated from Squeak on an Array(31 August 2009 11:16:19 am)
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
#include <sys/types.h>
/* D T Lewis - UnixOSProcessPlugin.c translated from class
   UnixOSProcessPlugin of OSProcessPlugin version 4.3.3 */
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <sys/stat.h>
#include <errno.h>
#include "config.h"
#define FILEHANDLETYPE FILE *  /* the type of low level stream to be used in a struct SQFile */
#ifndef SQAIO_H
# define SQAIO_H "aio.h"          /* aio.h has been renamed to sqaio.h */
#endif
#include SQAIO_H
#include "FilePlugin.h"
#include "SocketPlugin.h"
#define SESSIONIDENTIFIERTYPE int

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static void aioForwardwithDataandFlags(int fd, void * data, int flags);
static char * cStringFromString(sqInt aString);
static void * callocWrappersize(sqInt count, sqInt objectSize);
static sqInt copyBytesFromtolength(void * charArray1, void * charArray2, sqInt len);
static sqInt createPipeForReaderwriter(FILEHANDLETYPE * readerIOStreamPtr, FILEHANDLETYPE * writerIOStreamPtr);
static sqInt descriptorTableSize(void);
static void dupToStdErr(sqInt anSQFileDataStructure);
static void dupToStdIn(sqInt anSQFileDataStructure);
static void dupToStdOut(sqInt anSQFileDataStructure);
static sqInt fileDescriptorFrom(sqInt aSQFileByteArray);
static FILEHANDLETYPE fileHandleFrom(sqInt sqFileStructByteArray);
static sqInt fileRecordSize(void);
static SQFile * fileValueOf(sqInt anSQFileRecord);
static sqInt fixPointersInArrayOfStringswithOffsetscount(char *flattenedArrayOfStrings, sqInt *offsetArray, sqInt count);
static sqInt forkAndExecInDirectory(sqInt useSignalHandler);
#pragma export on
EXPORT(pid_t) forkSqueak(sqInt useSignalHandler);
#pragma export off
static void * forwardSignaltoSemaphoreAt(sqInt sigNum, sqInt semaphoreIndex);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt getThisSessionIdentifier(void);
static sqInt halt(void);
static void handleSignal(int sigNum);
static void * handleSignalFunctionAddress(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt initializeModuleForPlatform(void);
static sqInt isNonNullSQFile(sqInt objectPointer);
static sqInt isNullSQSocket(sqInt objectPointer);
static sqInt isSQFileObject(sqInt objectPointer);
static sqInt isSQSocketObject(sqInt objectPointer);
static sqInt isValidFileSession(sqInt objectPointer);
static sqInt isVmThread(void);
static sqInt makePipeForReaderwriter(FILEHANDLETYPE * readerIOStreamPtr, FILEHANDLETYPE * writerIOStreamPtr);
static sqInt maskForThisThreadAndResend(int sigNum);
static sqInt maskSignalForThisThread(int sigNum);
#pragma export on
EXPORT(sqInt) moduleUnloaded(char * aModuleName);
#pragma export off
static sqInt msg(char * s);
static sqInt newPthreadTypeByteArray(sqInt aPthreadType);
static sqInt newSQFileByteArray(void);
static sqInt newSQSocketByteArray(void);
static void ** originalSignalHandlers(void);
static void * pointerFrom(sqInt aByteArray);
#pragma export on
EXPORT(sqInt) primitiveAioDisable(void);
EXPORT(sqInt) primitiveAioEnable(void);
EXPORT(sqInt) primitiveAioHandle(void);
EXPORT(sqInt) primitiveAioSuspend(void);
EXPORT(sqInt) primitiveArgumentAt(void);
EXPORT(sqInt) primitiveCanReceiveSignals(sqInt anIntegerPid);
EXPORT(sqInt) primitiveChdir(void);
EXPORT(sqInt) primitiveCreatePipe(void);
EXPORT(sqInt) primitiveCreatePipeWithSessionIdentifier(void);
EXPORT(sqInt) primitiveDupTo(sqInt oldFileDescriptor, sqInt newFileDescriptor);
EXPORT(sqInt) primitiveEnvironmentAt(void);
EXPORT(sqInt) primitiveEnvironmentAtSymbol(void);
EXPORT(sqInt) primitiveErrorMessageAt(void);
EXPORT(sqInt) primitiveFileProtectionMask(void);
EXPORT(sqInt) primitiveFileStat(void);
EXPORT(sqInt) primitiveFixPointersInArrayOfStrings(void);
EXPORT(sqInt) primitiveForkAndExecInDirectory(void);
EXPORT(sqInt) primitiveForkExec(void);
EXPORT(sqInt) primitiveForkSqueak(void);
EXPORT(sqInt) primitiveForkSqueakWithoutSigHandler(void);
EXPORT(sqInt) primitiveForwardSignalToSemaphore(void);
EXPORT(sqInt) primitiveGetCurrentWorkingDirectory(void);
EXPORT(sqInt) primitiveGetEGid(void);
EXPORT(sqInt) primitiveGetEUid(void);
EXPORT(sqInt) primitiveGetGid(void);
EXPORT(sqInt) primitiveGetPGid(void);
EXPORT(sqInt) primitiveGetPGrp(void);
EXPORT(sqInt) primitiveGetPPid(void);
EXPORT(sqInt) primitiveGetPid(void);
EXPORT(sqInt) primitiveGetSession(void);
EXPORT(sqInt) primitiveGetStdErrHandle(void);
EXPORT(sqInt) primitiveGetStdErrHandleWithSessionIdentifier(void);
EXPORT(sqInt) primitiveGetStdInHandle(void);
EXPORT(sqInt) primitiveGetStdInHandleWithSessionIdentifier(void);
EXPORT(sqInt) primitiveGetStdOutHandle(void);
EXPORT(sqInt) primitiveGetStdOutHandleWithSessionIdentifier(void);
EXPORT(sqInt) primitiveGetThreadID(void);
EXPORT(sqInt) primitiveGetUid(void);
EXPORT(sqInt) primitiveIsAtEndOfFile(void);
EXPORT(sqInt) primitiveKillOnExit(void);
EXPORT(sqInt) primitiveLockFileRegion(void);
EXPORT(sqInt) primitiveMakePipe(void);
EXPORT(sqInt) primitiveMakePipeWithSessionIdentifier(void);
EXPORT(sqInt) primitiveModuleName(void);
EXPORT(sqInt) primitiveNice(void);
EXPORT(sqInt) primitivePutEnv(void);
EXPORT(sqInt) primitiveRealpath(void);
EXPORT(sqInt) primitiveReapChildProcess(void);
EXPORT(sqInt) primitiveSQFileFlush(void);
EXPORT(sqInt) primitiveSQFileFlushWithSessionIdentifier(void);
EXPORT(sqInt) primitiveSQFileSetBlocking(void);
EXPORT(sqInt) primitiveSQFileSetBlockingWithSessionIdentifier(void);
EXPORT(sqInt) primitiveSQFileSetNonBlocking(void);
EXPORT(sqInt) primitiveSQFileSetNonBlockingWithSessionIdentifier(void);
EXPORT(sqInt) primitiveSQFileSetUnbuffered(void);
EXPORT(sqInt) primitiveSQFileSetUnbufferedWithSessionIdentifier(void);
EXPORT(sqInt) primitiveSemaIndexFor(void);
EXPORT(sqInt) primitiveSendSigabrtTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigalrmTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigchldTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigcontTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSighupTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigintTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigkillTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigpipeTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigquitTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigstopTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigtermTo(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigusr1To(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSendSigusr2To(sqInt anIntegerPid);
EXPORT(sqInt) primitiveSetPGid(void);
EXPORT(sqInt) primitiveSetPGrp(void);
EXPORT(sqInt) primitiveSetSemaIndex(void);
EXPORT(sqInt) primitiveSetSid(void);
EXPORT(sqInt) primitiveSigChldNumber(void);
EXPORT(sqInt) primitiveSigHupNumber(void);
EXPORT(sqInt) primitiveSigIntNumber(void);
EXPORT(sqInt) primitiveSigKillNumber(void);
EXPORT(sqInt) primitiveSigPipeNumber(void);
EXPORT(sqInt) primitiveSigQuitNumber(void);
EXPORT(sqInt) primitiveSigTermNumber(void);
EXPORT(sqInt) primitiveSigUsr1Number(void);
EXPORT(sqInt) primitiveSigUsr2Number(void);
EXPORT(sqInt) primitiveSizeOfInt(void);
EXPORT(sqInt) primitiveSizeOfPointer(void);
EXPORT(sqInt) primitiveTestEndOfFileFlag(void);
EXPORT(sqInt) primitiveTestLockableFileRegion(void);
EXPORT(sqInt) primitiveUnixFileClose(sqInt anIntegerFileNumber);
EXPORT(sqInt) primitiveUnixFileNumber(void);
EXPORT(sqInt) primitiveUnlockFileRegion(void);
EXPORT(sqInt) primitiveUnsetEnv(void);
EXPORT(sqInt) primitiveVersionString(void);
#pragma export off
static void reapChildProcess(int sigNum);
static sqInt resendSignal(int sigNum);
static void restoreDefaultSignalHandlers(void);
static sqInt sandboxSecurity(void);
static sqInt securityHeurisitic(void);
static unsigned char * semaphoreIndices(void);
static sqInt sendSignaltoPid(sqInt sig, sqInt pid);
static void sendSignalToPids(void);
static SESSIONIDENTIFIERTYPE sessionIdentifierFrom(sqInt aByteArray);
static SESSIONIDENTIFIERTYPE sessionIdentifierFromSqFile(SQFile * sqFile);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
static void setSigChldDefaultHandler(void);
static void setSigChldHandler(void);
static void setSigIntDefaultHandler(void);
static void setSigIntIgnore(void);
static void setSigPipeDefaultHandler(void);
static sqInt setSigPipeHandler(void);
static void setSigPipeIgnore(void);
static void * setSignalNumberhandler(sqInt anInteger, void * signalHandlerAddress);
#pragma export on
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt sigAbrtNumber(void);
static sqInt sigAlrmNumber(void);
static sqInt sigChldNumber(void);
static sqInt sigContNumber(void);
static void * sigDefaultNumber(void);
static void * sigErrorNumber(void);
static sqInt sigHupNumber(void);
static void * sigIgnoreNumber(void);
static sqInt sigIntNumber(void);
static sqInt sigKillNumber(void);
static sqInt sigPipeNumber(void);
static sqInt sigQuitNumber(void);
static sqInt sigStopNumber(void);
static sqInt sigTermNumber(void);
static sqInt sigUsr1Number(void);
static sqInt sigUsr2Number(void);
static sqInt signalArraySize(void);
static void ** signalHandlers(void);
static sqInt sizeOfInt(void);
static sqInt sizeOfPointer(void);
static sqInt sizeOfSession(void);
static int socketDescriptorFrom(sqInt sqSocketOop);
static sqInt socketRecordSize(void);
static SQSocket * socketValueOf(sqInt anSQSocketRecord);
static sqInt stringFromCString(const char * aCString);
static char * transientCStringFromString(sqInt aString);
static int unixFileNumber(FILEHANDLETYPE fileHandle);
static char * versionString(void);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"UnixOSProcessPlugin 31 August 2009 (i)"
#else
	"UnixOSProcessPlugin 31 August 2009 (e)"
#endif
;
static void *originalSigHandlers[NSIG];
static int osprocessSandboxSecurity;
static pid_t *pidArray = NULL;
static sqInt pidCount;
static unsigned char semaIndices[NSIG];
static sqInt sigChldSemaIndex;
static void *sigHandlers[NSIG];
static int sigNumToSend = SIGTERM;
static pthread_t vmThread;



/*	Deprecated. This primitive has been replaced by a similar implementation in AioPlugin. */
/*	This function is called to signal a Smalltalk Semaphore when an asynchronous event is
	detected. When translated to C, the name of this method is aioForwardwithDataandFlags.
	The event handler is set up by #primitiveAioHandle. */

static void aioForwardwithDataandFlags(int fd, void * data, int flags) {
    sqInt *pfd;
    sqInt semaIndex;

	pfd = data;
	semaIndex = *pfd;
	interpreterProxy->signalSemaphoreWithIndex(semaIndex);
}


/*	Answer a new null-terminated C string copied from aString. The C string
	is allocated from the C runtime heap. See transientCStringFromString for
	a version which allocates from object memory.
	Caution: This may invoke the garbage collector. */

static char * cStringFromString(sqInt aString) {
    sqInt len;
    char *cString;
    char *sPtr;

	sPtr = interpreterProxy->arrayValueOf(aString);
	len = interpreterProxy->sizeOfSTArrayFromCPrimitive(sPtr);

	/* Space for a null terminated C string. */

	cString = callocWrappersize(len + 1, 1);
	(char *) strncpy (cString, sPtr, len);
	return cString;
}


/*	Using malloc() and calloc() is something I would like to avoid, since it is
	likely to cause problems some time in the future if somebody redesigns
	object memory allocation. This wrapper just makes it easy to find senders
	of calloc() in my code. -dtl */

static void * callocWrappersize(sqInt count, sqInt objectSize) {
	return calloc(count, objectSize);
}


/*	self cCode: 'memcpy(charArray2, charArray1, len' */

static sqInt copyBytesFromtolength(void * charArray1, void * charArray2, sqInt len) {
	memcpy(charArray2, charArray1, len);
}


/*	Create a pipe and populate the readerIOStream and writerIOStream variables.
	The SIGPIPE handler must have been set before creating the pipe. Answer true for
	success, else false. */

static sqInt createPipeForReaderwriter(FILEHANDLETYPE * readerIOStreamPtr, FILEHANDLETYPE * writerIOStreamPtr) {
    int filedes[2];

	if ((pipe(filedes)) == -1) {
		return 0;
	} else {
		*writerIOStreamPtr= (FILE *) fdopen (filedes[1], "a");
		*readerIOStreamPtr= (FILE *) fdopen (filedes[0], "r");
		return 1;
	}
}


/*	Answer the size of the file descriptor table for a process. I am not sure of the most portable
	way to do this. If this implementation does not work on your Unix platform, try changing
	it to answer the value of FOPEN:=MAX, which will hopefully be defined in stdio.h. If
	all else fails, just hard code it to answer 20, which would be safe for any Unix. */

static sqInt descriptorTableSize(void) {
	return getdtablesize();
}


/*	Dup a file descriptor to allow it to be attached as the standard error when we
	exec() a new executable. This is Unix specific, in that it assumes that file descriptor
	0 is stdin, 1 is stdout, and 2 is stderr. The dup2() call is used to copy the open file
	descriptors into file descriptors 0, 1 and 2 so that the image which we execute will
	use them as stdin, stdout, and stderr. */

static void dupToStdErr(sqInt anSQFileDataStructure) {
    sqInt filenoToDup;

	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(anSQFileDataStructure)) && ((interpreterProxy->byteSizeOf(anSQFileDataStructure)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(anSQFileDataStructure))))) && (isNonNullSQFile(anSQFileDataStructure)))) {
		filenoToDup = -1;
		goto l1;
	}
	filenoToDup = fileno(fileHandleFrom(anSQFileDataStructure));
l1:	/* end fileDescriptorFrom: */;
	if (!(filenoToDup < 0)) {
		if (!(filenoToDup == 2)) {
			fflush(stderr);
			dup2(filenoToDup, 2);
		}
	}
}


/*	Dup a file descriptor to allow it to be attached as the standard input when we
	exec() a new executable. This is Unix specific, in that it assumes that file descriptor
	0 is stdin, 1 is stdout, and 2 is stderr. The dup2() call is used to copy the open file
	descriptors into file descriptors 0, 1 and 2 so that the image which we execute will
	use them as stdin, stdout, and stderr. */

static void dupToStdIn(sqInt anSQFileDataStructure) {
    sqInt filenoToDup;

	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(anSQFileDataStructure)) && ((interpreterProxy->byteSizeOf(anSQFileDataStructure)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(anSQFileDataStructure))))) && (isNonNullSQFile(anSQFileDataStructure)))) {
		filenoToDup = -1;
		goto l1;
	}
	filenoToDup = fileno(fileHandleFrom(anSQFileDataStructure));
l1:	/* end fileDescriptorFrom: */;
	if (!(filenoToDup < 0)) {
		if (!(filenoToDup == 0)) {
			fflush(stdin);
			dup2(filenoToDup, 0);
			rewind(stdin);
		}
	}
}


/*	Dup a file descriptor to allow it to be attached as the standard output when we
	exec() a new executable. This is Unix specific, in that it assumes that file descriptor
	0 is stdin, 1 is stdout, and 2 is stderr. The dup2() call is used to copy the open file
	descriptors into file descriptors 0, 1 and 2 so that the image which we execute will
	use them as stdin, stdout, and stderr. */

static void dupToStdOut(sqInt anSQFileDataStructure) {
    sqInt filenoToDup;

	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(anSQFileDataStructure)) && ((interpreterProxy->byteSizeOf(anSQFileDataStructure)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(anSQFileDataStructure))))) && (isNonNullSQFile(anSQFileDataStructure)))) {
		filenoToDup = -1;
		goto l1;
	}
	filenoToDup = fileno(fileHandleFrom(anSQFileDataStructure));
l1:	/* end fileDescriptorFrom: */;
	if (!(filenoToDup < 0)) {
		if (!(filenoToDup == 1)) {
			fflush(stdout);
			dup2(filenoToDup, 1);
		}
	}
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


/*	Use the address offsets in offsetArray to fix up the pointers in cStringArray.
	The result is a C array of pointers to char, used for argv and env vectors. */

static sqInt fixPointersInArrayOfStringswithOffsetscount(char *flattenedArrayOfStrings, sqInt *offsetArray, sqInt count) {
    char **ptr;
    sqInt idx;

	ptr = ((char **) flattenedArrayOfStrings);
	idx = 0;
	while (idx < count) {
		ptr[idx] = (flattenedArrayOfStrings + (((offsetArray[idx]) >> 1)));
		idx += 1;
	}
}


/*	Fork a child OS process, and do an exec in the child. The parent continues on in
	Smalltalk, and this method answers the pid of the child which was created. If
	useSignalHandler is true, set the signal handler for SIGCHLD. Otherwise, assume
	that death of child events are handled through some other mechanism.

	In this implementation, memory for the argument and environment arrays is allocated
	in the image prior to calling this primitive. This allows us to avoid invoking the
	garbage collector in this primitive (thereby moving the locations of environment
	and argument memory), but comes at the cost of twiddling C pointers here in the
	primitive. An alternative to this whole mess is just to malloc the environment and
	argument vectors, but I think it is a good idea to avoid malloc as much as possible
	so as not to limit future ObjectMemory implementations.

	This primitive replaces #primitiveForkAndExec from earlier versions of the plugin.
	The new name permits backward compatibility for an image running on a VM
	which does not yet have the updated plugin. This implementation uses a different
	argument format on the stack, and differs functionally in that the child now closes
	all file descriptors (including sockets) not required (that is, everything except stdin,
	stdout, and stderr on descriptors 0, 1 and 2). This eliminates some flakey behavior
	in child processes connected to Squeak by pipes, which failed to exit at expected times
	due to the old file descriptors remaining open. This is also cleaner in that garbage
	descriptors are not left hanging around the the child.

	On entry, the stack contains:
		0: workingDir, a null terminated string specifying the working directory to use, or nil.
		1: envOffsets, an array of integers for calculating environment string address offsets.
		2: envVecBuffer, a String buffer containing environment strings arranged to look like char **.
		3: argOffsets, an array of integers for calculating argument string address offsets.
		4: argVecBuffer, a String buffer containing argument strings arranged to look like char **.
		5: stdErr, a ByteArray handle.
		6: stdOut, a ByteArray handle.
		7: stdIn, a ByteArray handle.
		8: executableFile, a null terminated string with the name of the file to execute.
		9: the sender */

static sqInt forkAndExecInDirectory(sqInt useSignalHandler) {
    sqInt executableFile;
    extern char **envVec;
    char *pwdPtr;
    pid_t pid;
    sqInt argVecBuffer;
    sqInt *envOffsetPtr;
    struct itimerval saveIntervalTimer;
    sqInt envCount;
    sqInt idx;
    struct itimerval intervalTimer;
    sqInt stdOut;
    char *progNamePtr;
    char **args;
    sqInt envOffsets;
    sqInt envVecBuffer;
    sqInt stdErr;
    sqInt workingDir;
    sqInt pwd;
    char *envPtr;
    char *argsPtr;
    sqInt *argOffsetPtr;
    sqInt handleCount;
    sqInt argCount;
    char **env;
    sqInt argOffsets;
    sqInt stdIn;
    sqInt sigNum;

	if (useSignalHandler) {
		setSigChldHandler();
	}
	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(10);
		interpreterProxy->pushInteger(-1);
	} else {
		intervalTimer.it_interval.tv_sec = 0;
		intervalTimer.it_interval.tv_usec = 0;
		intervalTimer.it_value.tv_sec = 0;
		intervalTimer.it_value.tv_usec = 0;
		setitimer (ITIMER_REAL, &intervalTimer, &saveIntervalTimer);
		if ((pid = vfork()) == 0) {
			workingDir = interpreterProxy->stackObjectValue(0);
			envOffsets = interpreterProxy->stackObjectValue(1);
			envVecBuffer = interpreterProxy->stackObjectValue(2);
			argOffsets = interpreterProxy->stackObjectValue(3);
			argVecBuffer = interpreterProxy->stackObjectValue(4);
			stdErr = interpreterProxy->stackObjectValue(5);
			stdOut = interpreterProxy->stackObjectValue(6);
			stdIn = interpreterProxy->stackObjectValue(7);

			/* If a new working directory has been specified, try to chdir() to it. */

			executableFile = interpreterProxy->stackObjectValue(8);
			if (workingDir != (interpreterProxy->nilObject())) {
				pwdPtr = interpreterProxy->firstIndexableField(workingDir);
				if (pwdPtr == 0) {
					fprintf(stderr, "bad workingDir parameter\n");
					_exit(-1);
				} else {
					pwd = chdir(pwdPtr);
					if (pwd != 0) {
						perror("chdir");
						_exit(-1);
					}
				}
			}

			/* Dup the file handles to attach the new child process to the right streams
			on descriptors 0, 1 and 2. */

			progNamePtr = interpreterProxy->arrayValueOf(executableFile);
			if (!(stdErr == (interpreterProxy->nilObject()))) {
				dupToStdErr(stdErr);
			}
			if (!(stdOut == (interpreterProxy->nilObject()))) {
				dupToStdOut(stdOut);
			}
			if (!(stdIn == (interpreterProxy->nilObject()))) {
				dupToStdIn(stdIn);
			}

			/* First Unix file descriptor after stdin, stdout, stderr. */

			idx = 3;
			handleCount = descriptorTableSize();
			while (idx < handleCount) {
				close(idx);
				idx += 1;
			}
			if (envVecBuffer == (interpreterProxy->nilObject())) {
				env = envVec;
			} else {
				envCount = interpreterProxy->stSizeOf(envOffsets);
				envPtr = interpreterProxy->arrayValueOf(envVecBuffer);
				envOffsetPtr = interpreterProxy->firstIndexableField(envOffsets);
				fixPointersInArrayOfStringswithOffsetscount(envPtr, envOffsetPtr, envCount);
				env = ((char **) envPtr);
			}
			argCount = interpreterProxy->stSizeOf(argOffsets);
			argsPtr = interpreterProxy->arrayValueOf(argVecBuffer);
			argOffsetPtr = interpreterProxy->firstIndexableField(argOffsets);
			fixPointersInArrayOfStringswithOffsetscount(argsPtr, argOffsetPtr, argCount);

			/* Clean things up before clobbering the running image. */
			/* Note: If any file descriptors, signal handlers, or other references to external
			resources need to be cleaned up, do it here. */

			args = ((char **) argsPtr);
			/* begin restoreDefaultSignalHandlers */
			sigNum = 1;
			while (sigNum <= (signalArraySize())) {
				if ((semaIndices[sigNum]) > 0) {
					setSignalNumberhandler(sigNum, originalSigHandlers[sigNum]);
				}
				sigNum += 1;
			}
			if ((execve(progNamePtr, args, env)) == -1) {
				perror(progNamePtr);
				_exit(-1);
			} else {
				/* Can't get here from there */;
			}
		} else {
			setitimer (ITIMER_REAL, &saveIntervalTimer, 0L);
			interpreterProxy->pop(10);
			interpreterProxy->pushInteger(pid);
		}
	}
}


/*	Fork a child process, and continue running squeak in the child process.
	Answer the result of the fork() call, either the child pid or zero.

	After calling fork(), two OS processes exist, one of which is the child of the other. On
	systems which implement copy-on-write memory management, and which support the
	fork() system call, both processes will be running Smalltalk images, and will be sharing
	the same memory space. In the original OS process, the resulting value of pid is the
	process id of the child process (a non-zero integer). In the child process, the value of
	pid is zero.

	The child recreates sufficient external resources to continue running. This is done by
	attaching to a new X session. The child is otherwise a copy of the parent process, and
	will continue executing the Smalltalk image at the same point as its parent. The return
	value of this primitive may be used by the two running Smalltalk images to determine
	which is the parent and which is the child.

	The child should not depend on using existing connections to external resources. For
	example, the child may lose its connections to stdin, stdout, and stderr after its parent
	exits.

	The new child image does not start itself from the image in the file system; rather it is
	a clone of the parent image as it existed at the time of primitiveForkSqueak. For this
	reason, the parent and child should agree in advance as to whom is allowed to save the
	image to the file system, otherwise one Smalltalk may overwrite the image of the other.

	This is a simple call to fork(), rather than the more common idiom of vfork() followed
	by exec(). The vfork() call cannot be used here because it is designed to be followed by
	an exec(), and its semantics require the parent process to wait for the child to exit. See
	the BSD programmers documentation for details. */

EXPORT(pid_t) forkSqueak(sqInt useSignalHandler) {
    pid_t pid;
    struct itimerval saveIntervalTimer;
    struct itimerval intervalTimer;

	intervalTimer.it_interval.tv_sec = 0;
	intervalTimer.it_interval.tv_usec = 0;
	intervalTimer.it_value.tv_sec = 0;
	intervalTimer.it_value.tv_usec = 0;
	setitimer (ITIMER_REAL, &intervalTimer, &saveIntervalTimer);
	if (useSignalHandler) {
		setSigChldHandler();
	}

	/* Enable the timer again before resuming Smalltalk. */

	pid = fork();
	setitimer (ITIMER_REAL, &saveIntervalTimer, 0L);
	return pid;
}


/*	Set a signal handler in the VM which will signal a Smalltalk semaphore at
	semaphoreIndex whenever an external signal sigNum is received. Answer the
	prior value of the signal handler. If semaphoreIndex is zero, the handler is
	unregistered, and the VM returns to its default behavior for handling that
	signal. A handler must be unregistered before it can be registered again.

	The Smalltalk semaphore is expected to be kept at the same index location
	indefinitely during the lifetime of a Squeak session. If that is not the case, the
	handler must be unregistered prior to unregistering the Smalltalk semaphore. */

static void * forwardSignaltoSemaphoreAt(sqInt sigNum, sqInt semaphoreIndex) {
    void * oldHandler;

	if (semaphoreIndex == 0) {
		if ((semaIndices[sigNum]) > 0) {
			oldHandler = originalSigHandlers[sigNum];
			setSignalNumberhandler(sigNum, oldHandler);
			semaIndices[sigNum] = 0;
			return oldHandler;
		} else {
			return sigErrorNumber();
		}
	}
	if ((semaIndices[sigNum]) > 0) {
		return sigErrorNumber();
	}
	oldHandler = setSignalNumberhandler(sigNum, handleSignalFunctionAddress());
	if (oldHandler != (sigErrorNumber())) {
		originalSigHandlers[sigNum] = oldHandler;
		semaIndices[sigNum] = semaphoreIndex;
	}
	return oldHandler;
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


/*	This is a signal handler function which runs when a signal is received
	from the operating system. When the signal is received, a Smalltalk Semaphore
	is signaled. This effectively passes the external signal to Squeak to allow
	it to be handled in Smalltalk. */

static void handleSignal(int sigNum) {
    sqInt semaIndex;

	semaIndex = semaIndices[sigNum];
	forwardSignaltoSemaphoreAt(sigNum, semaIndex);
	if (isVmThread()) {
		if (semaIndex > 0) {
			interpreterProxy->signalSemaphoreWithIndex(semaIndex);
		}
	} else {
		maskForThisThreadAndResend(sigNum);
	}
}

static void * handleSignalFunctionAddress(void) {
	return handleSignal;
}

EXPORT(sqInt) initialiseModule(void) {
	osprocessSandboxSecurity = -1;
	initializeModuleForPlatform();
	return 1;
}


/*	Platform specific initialization */

static sqInt initializeModuleForPlatform(void) {
	pidCount = 0;
	atexit(sendSignalToPids);
	vmThread = pthread_self();
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


/*	Answer true if this method is executing in the context of the pthread in
	which the interpreter executes. */

static sqInt isVmThread(void) {
    pthread_t thisThread;

	thisThread = pthread_self();
	return pthread_equal(thisThread, vmThread);
}


/*	Create a pipe and populate the readerIOStream and writerIOStream variables.
	Make sure the SIGPIPE handler is set before creating the pipe. Answer true for
	success, else false */

static sqInt makePipeForReaderwriter(FILEHANDLETYPE * readerIOStreamPtr, FILEHANDLETYPE * writerIOStreamPtr) {
    int filedes[2];

	/* begin setSigPipeHandler */
	/* begin setSigPipeIgnore */
	setSignalNumberhandler(sigPipeNumber(), sigIgnoreNumber());
	if ((pipe(filedes)) == -1) {
		return 0;
	} else {
		*writerIOStreamPtr= (FILE *) fdopen (filedes[1], "a");
		*readerIOStreamPtr= (FILE *) fdopen (filedes[0], "r");
		return 1;
	}
}


/*	Prevent any future instances of signal sigNum from being delivered
	to this pthread, and reschedule the current signal to be delivered to
	this OS process. Any pthread other than the interpreter thread will
	call this method. Eventually the signal will be delivered to the
	interpreter thread, which will handle it in the context of the interpreter
	thread. */

static sqInt maskForThisThreadAndResend(int sigNum) {
	maskSignalForThisThread(sigNum);
	resendSignal(sigNum);
}


/*	Prevent future invocations of signal sigNum from being delivered to this pthread. */

static sqInt maskSignalForThisThread(int sigNum) {
    sigset_t sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, sigNum);
	pthread_sigmask(SIG_BLOCK, &sigset, NULL);
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char * aModuleName) {
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	A pthread_t is an unsigned long, which may be 8 bytes on some 64 bit
	platforms. This stores the value in a byte array that can be easily
	passed to the image. */

static sqInt newPthreadTypeByteArray(sqInt aPthreadType) {
    sqInt byteArray;
    pthread_t *ptr;
    sqInt len;

	len = sizeof(pthread_t);
	byteArray = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), len);
	ptr = interpreterProxy->arrayValueOf(byteArray);
	*ptr = aPthreadType;
	return byteArray;
}


/*	Answer a new ByteArray sized to contain a SQFile data structure. */

static sqInt newSQFileByteArray(void) {
	return interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
}


/*	Answer a new ByteArray sized to contain a SQSocket data structure. */

static sqInt newSQSocketByteArray(void) {
	return interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), socketRecordSize());
}


/*	An array of signal handler function addresses, one for each signal type. The
	value at each entry is the address of the original signal handler function prior
	to having set a handler. */

static void ** originalSignalHandlers(void) {
	return originalSigHandlers;
}


/*	Answer the pointer represented by aByteArray. */

static void * pointerFrom(sqInt aByteArray) {
    unsigned char *ptr;
    sqInt idx;
    union {void *address; unsigned char bytes[sizeof(void *)];} pointerUnion;

	if (!((interpreterProxy->isBytes(aByteArray)) && ((interpreterProxy->stSizeOf(aByteArray)) == (sizeOfPointer())))) {
		return null;
	}
	ptr = interpreterProxy->arrayValueOf(aByteArray);
	idx = 0;
	while (idx < (sizeOfPointer())) {
		pointerUnion.bytes[idx] = ptr[idx];
		idx += 1;
	}
	return pointerUnion.address;
}


/*	Deprecated. This primitive has been replaced by a similar implementation in AioPlugin. */
/*	Definitively disable asynchronous event notification for a descriptor. The
	parameter is a sqFile ByteArray representing the ioHandle for a file. */

EXPORT(sqInt) primitiveAioDisable(void) {
    sqInt sqFile;
    int fd;

	sqFile = interpreterProxy->stackObjectValue(0);
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->byteSizeOf(sqFile)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFile))))) && (isNonNullSQFile(sqFile)))) {
		fd = -1;
		goto l1;
	}
	fd = fileno(fileHandleFrom(sqFile));
l1:	/* end fileDescriptorFrom: */;
	if (fd < 0) {
		return interpreterProxy->primitiveFail();
	}
	aioDisable(fd);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(fd);
}


/*	Deprecated. This primitive has been replaced by a similar implementation in AioPlugin. */
/*	Enable asynchronous notification for a descriptor. The first parameter is a sqFile
	ByteArray representing the ioHandle for a file, the second parameter is the index
	of a Semaphore to be notified, and the third parameter is a flag indicating that
	sqFile represents an external object and should not be closed on termination of
	aio handling. Answer the semaphore index. */

EXPORT(sqInt) primitiveAioEnable(void) {
    sqInt sqFile;
    sqInt semaIndex;
    sqInt externalObject;
    int fd;
    int flags;
    static int eventSemaphoreIndices[FD_SETSIZE];

	sqFile = interpreterProxy->stackObjectValue(2);
	if (!((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->stSizeOf(sqFile)) == (fileRecordSize())))) {
		return interpreterProxy->primitiveFail();
	}
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->byteSizeOf(sqFile)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFile))))) && (isNonNullSQFile(sqFile)))) {
		fd = -1;
		goto l1;
	}
	fd = fileno(fileHandleFrom(sqFile));
l1:	/* end fileDescriptorFrom: */;
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


/*	Deprecated. This primitive has been replaced by a similar implementation in AioPlugin. */
/*	Handle asynchronous event notification for a descriptor. The first parameter is
	a sqFile ByteArray representing the ioHandle for a file, and the remaining three
	parameters are Boolean flags representing the types of events for which notification
	is being requested: handle exceptions, handle for read, and handle for write.
	Flags are defined in the aio.h source as:
		AIO_X	(1<<0)	handle for exceptions
		AIO_R	(1<<1)	handle for read
		AIO_W	(1<<2)	handle for write */

EXPORT(sqInt) primitiveAioHandle(void) {
    sqInt writeWatch;
    sqInt readWatch;
    sqInt exceptionWatch;
    sqInt sqFile;
    int fd;
    int flags;

	sqFile = interpreterProxy->stackObjectValue(3);
	if (!((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->stSizeOf(sqFile)) == (fileRecordSize())))) {
		return interpreterProxy->primitiveFail();
	}
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->byteSizeOf(sqFile)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFile))))) && (isNonNullSQFile(sqFile)))) {
		fd = -1;
		goto l1;
	}
	fd = fileno(fileHandleFrom(sqFile));
l1:	/* end fileDescriptorFrom: */;
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


/*	Deprecated. This primitive has been replaced by a similar implementation in AioPlugin. */
/*	Temporarily suspend asynchronous event notification for a descriptor. The first
	parameter is a sqFile ByteArray representing the ioHandle for a file, and the
	remaining three parameters are Boolean flags representing the types of events
	for which notification is being requested: handle exceptions, handle for read,
	and handle for write.
	Flags are defined in the aio.h source as:
		AIO_X	(1<<0)	handle for exceptions
		AIO_R	(1<<1)	handle for read
		AIO_W	(1<<2)	handle for write */

EXPORT(sqInt) primitiveAioSuspend(void) {
    sqInt writeWatch;
    sqInt readWatch;
    sqInt exceptionWatch;
    sqInt sqFile;
    int fd;
    int flags;

	sqFile = interpreterProxy->stackObjectValue(3);
	if (!((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->stSizeOf(sqFile)) == (fileRecordSize())))) {
		return interpreterProxy->primitiveFail();
	}
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFile)) && ((interpreterProxy->byteSizeOf(sqFile)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFile))))) && (isNonNullSQFile(sqFile)))) {
		fd = -1;
		goto l1;
	}
	fd = fileno(fileHandleFrom(sqFile));
l1:	/* end fileDescriptorFrom: */;
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


/*	Answer a string containing the OS process argument at index (an Integer) in the
	argument list. */

EXPORT(sqInt) primitiveArgumentAt(void) {
    extern char **argVec;
    sqInt s;
    sqInt index;
    char *sPtr;
    extern int argCnt;

	index = interpreterProxy->stackIntegerValue(0);
	if ((index > argCnt) || (index < 1)) {
		interpreterProxy->pop(2);
		interpreterProxy->push(interpreterProxy->nilObject());
	} else {
		sPtr = argVec[index - 1];
		s = stringFromCString(sPtr);
		interpreterProxy->pop(2);
		interpreterProxy->push(s);
	}
}


/*	Send a null signal to the OS process identified by anIntegerPid. Answer false for
	a bad parameter on the stack (the common case is for anIntegerPid equal to nil,
	for which case we should answer false). Answer true if the process exists and can
	receive signals from this process, otherwise false. This test is useful for determining
	if a child process still exists following a Squeak image restart. */

EXPORT(sqInt) primitiveCanReceiveSignals(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;

	if (((interpreterProxy->stackValue(0)) & 1)) {
		pidToSignal = interpreterProxy->stackIntegerValue(0);
		result = kill(pidToSignal, 0);
		interpreterProxy->pop(2);
		if (result == 0) {
			interpreterProxy->push(interpreterProxy->trueObject());
		} else {
			interpreterProxy->push(interpreterProxy->falseObject());
		}
	} else {
		interpreterProxy->pop(2);
		interpreterProxy->push(interpreterProxy->falseObject());
	}
}


/*	Call chdir(2) to change current working directory to the specified path string. Answer
	nil for success, or errno on failure. */

EXPORT(sqInt) primitiveChdir(void) {
    extern int errno;
    char * path;

	path = transientCStringFromString(interpreterProxy->stackObjectValue(0));
	if (chdir(path)) {
		interpreterProxy->pop(2);
		interpreterProxy->push(interpreterProxy->nilObject());
	} else {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(errno);
	}
}


/*	Create a pipe, and answer an array of two file handles for the pipe writer and reader.
	The readerIOStream and writerIOStream variables represent the low level pipe streams,
	which will be of type (FILE *) or HANDLE, depending on what the FilePlugin support
	code is using to represent file streams. FILEHANDLETYPE is defined in my subclasses
	in the #declareCVarsIn: class method. */

EXPORT(sqInt) primitiveCreatePipe(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt writer;
    FILEHANDLETYPE writerIOStream;
    SQFile *writerPtr;
    FILEHANDLETYPE *writerIOStreamPtr;
    SQFile *readerPtr;
    sqInt arrayResult;
    sqInt reader;
    FILEHANDLETYPE readerIOStream;
    FILEHANDLETYPE *readerIOStreamPtr;


	/* Create the anonymous OS pipe */

	thisSession = interpreterProxy->getThisSessionID();
	readerIOStreamPtr = &readerIOStream;
	writerIOStreamPtr = &writerIOStream;
	if (!(createPipeForReaderwriter(readerIOStreamPtr, writerIOStreamPtr))) {
		return interpreterProxy->primitiveFail();
	}
	writer = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	writerPtr = interpreterProxy->arrayValueOf(writer);
	writerPtr->file = writerIOStream;
	writerPtr->sessionID = thisSession;
	writerPtr->writable = 1;
	writerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(writer);
	reader = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	readerPtr = interpreterProxy->arrayValueOf(reader);
	readerPtr->file = readerIOStream;
	readerPtr->sessionID = thisSession;
	readerPtr->writable = 0;
	readerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(reader);
	arrayResult = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2);
	interpreterProxy->stObjectatput(arrayResult, 1, interpreterProxy->popRemappableOop());
	interpreterProxy->stObjectatput(arrayResult, 2, interpreterProxy->popRemappableOop());
	interpreterProxy->pop(1);
	interpreterProxy->push(arrayResult);
}


/*	Create a pipe, and answer an array of two file handles for the pipe writer and reader.
	The session identifier is passed as the parameter to this primitive. Use this variant
	if the session identifier is not available directly in the VM (as may be the case if
	it is not possible to link from this plugin to a variable elsewhere in the VM).
	The readerIOStream and writerIOStream variables represent the low level pipe streams,
	which will be of type (FILE *) or HANDLE, depending on what the FilePlugin support
	code is using to represent file streams. FILEHANDLETYPE is defined in my subclasses
	in the #declareCVarsIn: class method. */

EXPORT(sqInt) primitiveCreatePipeWithSessionIdentifier(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt writer;
    FILEHANDLETYPE writerIOStream;
    SQFile *writerPtr;
    FILEHANDLETYPE *writerIOStreamPtr;
    SQFile *readerPtr;
    sqInt arrayResult;
    sqInt reader;
    FILEHANDLETYPE readerIOStream;
    FILEHANDLETYPE *readerIOStreamPtr;


	/* Create the anonymous OS pipe */

	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	readerIOStreamPtr = &readerIOStream;
	writerIOStreamPtr = &writerIOStream;
	if (!(createPipeForReaderwriter(readerIOStreamPtr, writerIOStreamPtr))) {
		return interpreterProxy->primitiveFail();
	}
	writer = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	writerPtr = interpreterProxy->arrayValueOf(writer);
	writerPtr->file = writerIOStream;
	writerPtr->sessionID = thisSession;
	writerPtr->writable = 1;
	writerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(writer);
	reader = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	readerPtr = interpreterProxy->arrayValueOf(reader);
	readerPtr->file = readerIOStream;
	readerPtr->sessionID = thisSession;
	readerPtr->writable = 0;
	readerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(reader);
	arrayResult = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2);
	interpreterProxy->stObjectatput(arrayResult, 1, interpreterProxy->popRemappableOop());
	interpreterProxy->stObjectatput(arrayResult, 2, interpreterProxy->popRemappableOop());
	interpreterProxy->pop(2);
	interpreterProxy->push(arrayResult);
}


/*	Call dup2() to duplicate a file descriptor. Answer the duplicated file descriptor
	or -1 on failure. */

EXPORT(sqInt) primitiveDupTo(sqInt oldFileDescriptor, sqInt newFileDescriptor) {
    int oldfd;
    int newfd;
    int result;

	newfd = interpreterProxy->stackIntegerValue(0);
	oldfd = interpreterProxy->stackIntegerValue(1);
	result = dup2(oldfd, newfd);
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(result);
}


/*	Answer a string containing the OS process environment string at index (an Integer)
	in the environment list. */

EXPORT(sqInt) primitiveEnvironmentAt(void) {
    extern char **envVec;
    char **p;
    sqInt envCnt;
    sqInt s;
    sqInt index;
    char *sPtr;

	p = envVec;
	envCnt = 0;
	while (*p++) envCnt++;
	index = interpreterProxy->stackIntegerValue(0);
	if ((index > envCnt) || (index < 1)) {
		interpreterProxy->pop(2);
		interpreterProxy->push(interpreterProxy->nilObject());
	} else {
		sPtr = envVec[index - 1];
		s = stringFromCString(sPtr);
		interpreterProxy->pop(2);
		interpreterProxy->push(s);
	}
}


/*	Answer the value of an environment variable keyed by a Symbol. */

EXPORT(sqInt) primitiveEnvironmentAtSymbol(void) {
    char * getenvResult;

	getenvResult = getenv(transientCStringFromString(interpreterProxy->stackObjectValue(0)));
	if (getenvResult == 0) {
		return interpreterProxy->primitiveFail();
	} else {
		interpreterProxy->pop(2);
		interpreterProxy->push(stringFromCString(getenvResult));
	}
}


/*	Answer a string describing an error message */

EXPORT(sqInt) primitiveErrorMessageAt(void) {
    char *p;
    sqInt errMessage;
    sqInt index;

	index = interpreterProxy->stackIntegerValue(0);
	p = ((char *) (strerror(index)));
	errMessage = stringFromCString(p);
	interpreterProxy->pop(2);
	interpreterProxy->push(errMessage);
}


/*	Call stat(2) to obtain the file protection mask for a file. Answer an Array of
	four integers representing the protection mask, or answer errno on failure. The
	protection mask is four Integers, each of which may be considered an octal digit
	(0-7), with bit values 4, 2, and 1. The first digit selects the set user ID (4) and set
	group ID (2) and save text image (1) attributes. The second digit selects permissions
	for the user who owns the file: read (4), write (2), and execute (1); the third
	selects permissions for other users in the file's group, with the same values; and
	the fourth for other users not in the file's group, with the same values. */

EXPORT(sqInt) primitiveFileProtectionMask(void) {
    sqInt buffer;
    extern int errno;
    char *path;
    struct stat *statBuf;
    sqInt mode;
    sqInt result;

	buffer = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(struct stat));
	statBuf = interpreterProxy->arrayValueOf(buffer);
	path = transientCStringFromString(interpreterProxy->stackObjectValue(0));
	mode = stat(path, statBuf);
	if (mode == 0) {
		mode = statBuf->st_mode;
		result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4);
		interpreterProxy->stObjectatput(result, 4, (((mode & 07) << 1) | 1));
		interpreterProxy->stObjectatput(result, 3, ((((mode & 070) >> 3) << 1) | 1));
		interpreterProxy->stObjectatput(result, 2, ((((mode & 0700) >> 6) << 1) | 1));
		interpreterProxy->stObjectatput(result, 1, ((((mode & 07000) >> 9) << 1) | 1));
		interpreterProxy->pop(2);
		interpreterProxy->push(result);
	} else {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(errno);
	}
}


/*	Call stat(2) to obtain the file protection mask for a file. Answer errno on failure,
	or on success answer an array with: UID with: GID with: protectionMask. The	
	protectionMask is an Array of four integers representing the protection mask, or
	answer errno on failure. The protection mask is four Integers, each of which may
	be considered an octal digit (0-7), with bit values 4, 2, and 1. The first digit selects
	the set user ID (4) and set group ID (2) and save text image (1) attributes. The second
	digit selects permissions for the user who owns the file: read (4), write (2), and
	execute (1); the third selects permissions for other users in the file's group, with
	the same values; and the fourth for other users not in the file's group, with the
	same values. */

EXPORT(sqInt) primitiveFileStat(void) {
    sqInt buffer;
    sqInt uid;
    char *path;
    struct stat *statBuf;
    sqInt gid;
    sqInt mode;
    extern int errno;
    sqInt result;
    sqInt mask;

	result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 3);
	uid = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(uid_t));
	gid = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(gid_t));
	mask = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4);
	buffer = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(struct stat));
	statBuf = interpreterProxy->arrayValueOf(buffer);
	path = transientCStringFromString(interpreterProxy->stackObjectValue(0));
	mode = stat(path, statBuf);
	if (mode == 0) {
		mode = statBuf->st_mode;
		interpreterProxy->stObjectatput(mask, 4, (((mode & 07) << 1) | 1));
		interpreterProxy->stObjectatput(mask, 3, ((((mode & 070) >> 3) << 1) | 1));
		interpreterProxy->stObjectatput(mask, 2, ((((mode & 0700) >> 6) << 1) | 1));
		interpreterProxy->stObjectatput(mask, 1, ((((mode & 07000) >> 9) << 1) | 1));
		interpreterProxy->stObjectatput(result, 3, mask);
		interpreterProxy->stObjectatput(result, 2, (((statBuf->st_gid) << 1) | 1));
		interpreterProxy->stObjectatput(result, 1, (((statBuf->st_uid) << 1) | 1));
		interpreterProxy->pop(2);
		interpreterProxy->push(result);
	} else {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(errno);
	}
}


/*	This primitive exists only for purposes of testing the
	fixPointersInArrayOfStrings:withOffsets:count: method. I believe it to be
	reasonably machine and compiler independent, but have no way of verifying
	this on a variety of machines, so I'll leave this test method here in case
	someone runs into problems on other hardware or compilers. -dtl */

EXPORT(sqInt) primitiveFixPointersInArrayOfStrings(void) {
    sqInt cStringArray;
    sqInt offsetArray;
    sqInt count;
    char *flattenedArrayOfStrings;
    sqInt *offsets;

	count = interpreterProxy->stackIntegerValue(0);
	offsetArray = interpreterProxy->stackObjectValue(1);
	cStringArray = interpreterProxy->stackObjectValue(2);
	offsets = interpreterProxy->firstIndexableField(offsetArray);
	flattenedArrayOfStrings = interpreterProxy->arrayValueOf(cStringArray);
	fixPointersInArrayOfStringswithOffsetscount(flattenedArrayOfStrings, offsets, count);
	interpreterProxy->pop(4);
	interpreterProxy->push(cStringArray);
}


/*	Fork a child OS process, and do an exec in the child. The parent continues on in
	Smalltalk, and this method answers the pid of the child which was created.

	On entry, the stack contains:
		0: workingDir, a null terminated string specifying the working directory to use, or nil.
		1: envOffsets, an array of integers for calculating environment string address offsets.
		2: envVecBuffer, a String buffer containing environment strings arranged to look like char **.
		3: argOffsets, an array of integers for calculating argument string address offsets.
		4: argVecBuffer, a String buffer containing argument strings arranged to look like char **.
		5: stdErr, a ByteArray handle.
		6: stdOut, a ByteArray handle.
		7: stdIn, a ByteArray handle.
		8: executableFile, a null terminated string with the name of the file to execute.
		9: the sender */

EXPORT(sqInt) primitiveForkAndExecInDirectory(void) {
	return forkAndExecInDirectory(1);
}


/*	Fork a child OS process, and do an exec in the child. The parent continues on in
	Smalltalk, and this method answers the pid of the child which was created.

	On entry, the stack contains:
		0: workingDir, a null terminated string specifying the working directory to use, or nil.
		1: envOffsets, an array of integers for calculating environment string address offsets.
		2: envVecBuffer, a String buffer containing environment strings arranged to look like char **.
		3: argOffsets, an array of integers for calculating argument string address offsets.
		4: argVecBuffer, a String buffer containing argument strings arranged to look like char **.
		5: stdErr, a ByteArray handle.
		6: stdOut, a ByteArray handle.
		7: stdIn, a ByteArray handle.
		8: executableFile, a null terminated string with the name of the file to execute.
		9: the sender */

EXPORT(sqInt) primitiveForkExec(void) {
	return forkAndExecInDirectory(0);
}


/*	Fork a child process, and continue running squeak in the child process. Leave the
	X session connected to the parent process, but close its file descriptor for the child
	process. Open a new X session for the child.

	The child should not depend on using existing connections to external resources. For
	example, the child may lose its connections to stdin, stdout, and stderr after its parent
	exits. */

EXPORT(sqInt) primitiveForkSqueak(void) {
    pid_t pid;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(1);
		interpreterProxy->pushInteger(-1);
	} else {
		pid = forkSqueak(1);
		interpreterProxy->pop(1);
		interpreterProxy->pushInteger(pid);
	}
}


/*	Fork a child process, and continue running squeak in the child process. Leave the
	X session connected to the parent process, but close its file descriptor for the child
	process. Open a new X session for the child.

	The child should not depend on using existing connections to external resources. For
	example, the child may lose its connections to stdin, stdout, and stderr after its parent
	exits. */

EXPORT(sqInt) primitiveForkSqueakWithoutSigHandler(void) {
    pid_t pid;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(1);
		interpreterProxy->pushInteger(-1);
	} else {
		pid = forkSqueak(0);
		interpreterProxy->pop(1);
		interpreterProxy->pushInteger(pid);
	}
}


/*	Set a signal handler in the VM which will signal a Smalltalk semaphore at
	semaphoreIndex whenever an external signal sigNum is received. Answer the
	prior value of the signal handler. If semaphoreIndex is zero or nil, the handler
	is unregistered, and the VM returns to its default behavior for handling that
	signal.

	The Smalltalk semaphore is expected to be kept at the same index location
	indefinitely during the lifetime of a Squeak session. If that is not the case, the
	handler must be unregistered prior to unregistering the Smalltalk semaphore. */

EXPORT(sqInt) primitiveForwardSignalToSemaphore(void) {
    sqInt sigNum;
    void *handler;
    sqInt semaphoreIndex;
    char *hPtr;
    sqInt idx;
    sqInt index;
    union {void *handler; unsigned char bytes[sizeof(void *)];} priorHandler;
    sqInt priorHandlerObject;

	index = interpreterProxy->stackValue(0);
	if (index == (interpreterProxy->nilObject())) {
		semaphoreIndex = 0;
	} else {
		if ((index & 1)) {
			semaphoreIndex = interpreterProxy->stackIntegerValue(0);
		} else {
			return interpreterProxy->primitiveFail();
		}
	}
	sigNum = interpreterProxy->stackIntegerValue(1);
	handler = forwardSignaltoSemaphoreAt(sigNum, semaphoreIndex);
	if (handler == (sigErrorNumber())) {
		return interpreterProxy->primitiveFail();
	}
	priorHandlerObject = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeOfPointer());
	hPtr = interpreterProxy->arrayValueOf(priorHandlerObject);
	priorHandler.handler = handler;
	idx = 0;
	while (idx < (sizeOfPointer())) {
		hPtr[idx] = priorHandler.bytes[idx];
		idx += 1;
	}
	interpreterProxy->popthenPush(3, priorHandlerObject);
}


/*	Answer a string containing the current working directory. */

EXPORT(sqInt) primitiveGetCurrentWorkingDirectory(void) {
    sqInt maxSize;
    char *buffer;
    sqInt cwdString;
    sqInt incrementBy;
    char *cwd;
    sqInt bufferSize;

	bufferSize = 100;
	incrementBy = 100;
	maxSize = 5000;
	while (1) {
		cwdString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), bufferSize);
		buffer = interpreterProxy->arrayValueOf(cwdString);

		/* getcwd(buffer, bufferSize) */

		cwd = getcwd(buffer, bufferSize);
		if (!((cwd == 0) && (bufferSize < maxSize))) break;
		bufferSize += incrementBy;
	}
	if (cwd == 0) {
		return interpreterProxy->primitiveFail();
	} else {
		cwdString = stringFromCString(cwd);
		interpreterProxy->pop(1);
		interpreterProxy->push(cwdString);
	}
}


/*	Answer the effective group ID of my OS process */

EXPORT(sqInt) primitiveGetEGid(void) {
    gid_t eGid;

	eGid = getegid();
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(eGid);
}


/*	Answer the effective user ID of my OS process */

EXPORT(sqInt) primitiveGetEUid(void) {
    uid_t eUid;

	eUid = geteuid();
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(eUid);
}


/*	Answer the group ID of my OS process */

EXPORT(sqInt) primitiveGetGid(void) {
    gid_t gid;

	gid = getgid();
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(gid);
}


/*	Answer the process group ID of the process identified by pid */

EXPORT(sqInt) primitiveGetPGid(void) {
    pid_t pgid;
    pid_t pid;

	pid = interpreterProxy->stackIntegerValue(0);
	pgid = getpgid(pid);
	if (pgid == -1) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(pgid);
}


/*	Answer the process group ID of this OS process */

EXPORT(sqInt) primitiveGetPGrp(void) {
    pid_t pgid;

	pgid = getpgrp();
	if (pgid == -1) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(pgid);
}


/*	Answer the process ID of the parent process of my OS process */

EXPORT(sqInt) primitiveGetPPid(void) {
    pid_t ppid;

	ppid = getppid();
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(ppid);
}


/*	Answer the process ID of my OS process */

EXPORT(sqInt) primitiveGetPid(void) {
    pid_t pid;

	pid = getpid();
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(pid);
}


/*	Answer the unique session identifier for this Smalltalk instance running in this
	OS process. The C integer value is coerced into a Smalltalk ByteArray to preserve
	the full range of possible values. */

EXPORT(sqInt) primitiveGetSession(void) {
    sqInt sessionOop;
    SESSIONIDENTIFIERTYPE thisSessionID;
    unsigned char *sessionByteArrayPointer;
    sqInt sessionIDSize;

	thisSessionID = interpreterProxy->getThisSessionID();
	sessionIDSize = sizeof(thisSessionID);
	sessionOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sessionIDSize);
	sessionByteArrayPointer = interpreterProxy->arrayValueOf(sessionOop);
	if (thisSessionID == null) {
		return interpreterProxy->primitiveFail();
	}
	copyBytesFromtolength((unsigned char *)&thisSessionID, sessionByteArrayPointer, sessionIDSize);
	interpreterProxy->pop(1);
	interpreterProxy->push(sessionOop);
}


/*	Answer the file handle for standard error of my OS process */

EXPORT(sqInt) primitiveGetStdErrHandle(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt fileOop;
    SQFile *file;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	file = interpreterProxy->arrayValueOf(fileOop);
	thisSession = interpreterProxy->getThisSessionID();
	file->file = stderr;
	file->sessionID = thisSession;
	file->writable = 1;
	file->lastOp = 0;
	interpreterProxy->pop(1);
	interpreterProxy->push(fileOop);
}


/*	Answer the file handle for standard error of my OS process. The session
	identifier is passed as the parameter to this primitive. Use this variant if
	the session identifier is not available directly in the VM (as may be the
	case if it is not possible to link from this plugin to a variable elsewhere
	in the VM). */

EXPORT(sqInt) primitiveGetStdErrHandleWithSessionIdentifier(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt fileOop;
    SQFile *file;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	file = interpreterProxy->arrayValueOf(fileOop);
	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	file->file = stderr;
	file->sessionID = thisSession;
	file->writable = 1;
	file->lastOp = 0;
	interpreterProxy->pop(2);
	interpreterProxy->push(fileOop);
}


/*	Answer the file handle for standard input of my OS process */

EXPORT(sqInt) primitiveGetStdInHandle(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt fileOop;
    SQFile *file;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	file = interpreterProxy->arrayValueOf(fileOop);
	thisSession = interpreterProxy->getThisSessionID();
	file->file = stdin;
	file->sessionID = thisSession;
	file->writable = 0;
	file->lastOp = 0;
	interpreterProxy->pop(1);
	interpreterProxy->push(fileOop);
}


/*	Answer the file handle for standard input of my OS process. The session
	identifier is passed as the parameter to this primitive. Use this variant if
	the session identifier is not available directly in the VM (as may be the
	case if it is not possible to link from this plugin to a variable elsewhere
	in the VM). */

EXPORT(sqInt) primitiveGetStdInHandleWithSessionIdentifier(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt fileOop;
    SQFile *file;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	file = interpreterProxy->arrayValueOf(fileOop);
	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	file->file = stdin;
	file->sessionID = thisSession;
	file->writable = 0;
	file->lastOp = 0;
	interpreterProxy->pop(2);
	interpreterProxy->push(fileOop);
}


/*	Answer the file handle for standard output of my OS process */

EXPORT(sqInt) primitiveGetStdOutHandle(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt fileOop;
    SQFile *file;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	file = interpreterProxy->arrayValueOf(fileOop);
	thisSession = interpreterProxy->getThisSessionID();
	file->file = stdout;
	file->sessionID = thisSession;
	file->writable = 1;
	file->lastOp = 0;
	interpreterProxy->pop(1);
	interpreterProxy->push(fileOop);
}


/*	Answer the file handle for standard output of my OS process. The session
	identifier is passed as the parameter to this primitive. Use this variant if
	the session identifier is not available directly in the VM (as may be the
	case if it is not possible to link from this plugin to a variable elsewhere
	in the VM). */

EXPORT(sqInt) primitiveGetStdOutHandleWithSessionIdentifier(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt fileOop;
    SQFile *file;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	file = interpreterProxy->arrayValueOf(fileOop);
	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	file->file = stdout;
	file->sessionID = thisSession;
	file->writable = 1;
	file->lastOp = 0;
	interpreterProxy->pop(2);
	interpreterProxy->push(fileOop);
}


/*	Answer the ID of the pthread that is currently executing (the interpreter thread).
	A thread ID may be a 64 bit value on some platforms, so answer a byte array
	containing the value in machine-dependent byte order. */

EXPORT(sqInt) primitiveGetThreadID(void) {
	interpreterProxy->popthenPush(1, newPthreadTypeByteArray(vmThread));
}


/*	Answer the user ID of my OS process */

EXPORT(sqInt) primitiveGetUid(void) {
    uid_t uid;

	uid = getuid();
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(uid);
}


/*	Take a struct SQFile from the stack, and call feof(3) to determine if the file has
	reached end of file. */
/*	Deprecated. The return values are reversed. Use primitiveTestEndOfFileFlag. */

EXPORT(sqInt) primitiveIsAtEndOfFile(void) {
    sqInt sqFileOop;
    sqInt result;
    FILEHANDLETYPE file;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	file = fileHandleFrom(sqFileOop);
	if (file == 0) {
		return primitiveFail();
	}
	if (feof(file)) {
		result = interpreterProxy->trueObject();
	} else {
		result = interpreterProxy->falseObject();
	}
	interpreterProxy->pop(2);
	interpreterProxy->push(result);
}


/*	Set a list of pids to kill with signum when VM exits. If the signum
	parameter is nil, the default value of SIGTERM will be used. */

EXPORT(sqInt) primitiveKillOnExit(void) {
    pid_t * p;
    sqInt count;
    pid_t pid;
    sqInt * pidPointer;
    sqInt pids;
    sqInt signum;

	pids = interpreterProxy->stackValue(1);
	signum = interpreterProxy->stackValue(0);
	pidCount = interpreterProxy->stSizeOf(pids);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(pidArray == 0)) {
		free(pidArray);
	}
	pidArray = malloc(pidCount * sizeof(pid_t));
	if (pidArray == 0) {
		pidCount = 0;
		return interpreterProxy->primitiveFail();
	}
	pidPointer = interpreterProxy->firstIndexableField(pids);
	count = 0;
	p = pidArray;
	while (count <= pidCount) {
		pid = ((*pidPointer++) >> 1);
		*p++ = pid;
		count += 1;
	}
	if (!(signum == (interpreterProxy->nilObject()))) {
		sigNumToSend = interpreterProxy->checkedIntegerValueOf(signum);
	}
	if (interpreterProxy->failed()) {
		pidCount = 0;
	}
	interpreterProxy->pop(2);
}


/*	Take a struct SQFile from the stack, and request a lock on the specified region.
	If the exclusive flag is true, then request an exclusive (F_WRLCK) lock on the
     file. Otherwise, request a shared (F_RDLCK) lock. Any number of Unix processes
     may hold  a read lock (shared lock) on a file region, but only one process may
     hold a write lock (exclusive lock). Answer the result of the call to fcntl().

	If length is zero, then the entire file will be locked, including region extents that
	have not yet been allocated for the file. */

EXPORT(sqInt) primitiveLockFileRegion(void) {
    struct flock lockStruct;
    sqInt exclusive;
    sqInt sqFileOop;
    sqInt start;
    int result;
    sqInt len;
    int fileNo;

	exclusive = (interpreterProxy->stackValue(0)) == (interpreterProxy->trueObject());
	len = interpreterProxy->stackIntegerValue(1);
	start = interpreterProxy->stackIntegerValue(2);
	sqFileOop = interpreterProxy->stackValue(3);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}

	/* Set up the flock structure parameter for fcntl() */

	fileNo = unixFileNumber(fileHandleFrom(sqFileOop));
	if (exclusive) {
		lockStruct.l_type = F_WRLCK;
	} else {
		lockStruct.l_type = F_RDLCK;
	}
	lockStruct.l_whence = SEEK_SET;
	lockStruct.l_start = start;
	lockStruct.l_len = len;
	lockStruct.l_pid = 0;
	result = fcntl(fileNo, F_SETLK, &lockStruct);
	interpreterProxy->pop(5);
	interpreterProxy->pushInteger(result);
}


/*	Create a pipe, and answer an array of two file handles for the pipe writer and reader.
	The readerIOStream and writerIOStream variables represent the low level pipe streams,
	which will be of type (FILE *) or HANDLE, depending on what the FilePlugin support
	code is using to represent file streams. FILEHANDLETYPE is defined in my subclasses
	in the #declareCVarsIn: class method. */

EXPORT(sqInt) primitiveMakePipe(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt writer;
    FILEHANDLETYPE writerIOStream;
    SQFile *writerPtr;
    FILEHANDLETYPE *writerIOStreamPtr;
    SQFile *readerPtr;
    sqInt arrayResult;
    sqInt reader;
    FILEHANDLETYPE readerIOStream;
    FILEHANDLETYPE *readerIOStreamPtr;


	/* Create the anonymous OS pipe */

	thisSession = interpreterProxy->getThisSessionID();
	readerIOStreamPtr = &readerIOStream;
	writerIOStreamPtr = &writerIOStream;
	if (!(makePipeForReaderwriter(readerIOStreamPtr, writerIOStreamPtr))) {
		return interpreterProxy->primitiveFail();
	}
	writer = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	writerPtr = interpreterProxy->arrayValueOf(writer);
	writerPtr->file = writerIOStream;
	writerPtr->sessionID = thisSession;
	writerPtr->writable = 1;
	writerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(writer);
	reader = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	readerPtr = interpreterProxy->arrayValueOf(reader);
	readerPtr->file = readerIOStream;
	readerPtr->sessionID = thisSession;
	readerPtr->writable = 0;
	readerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(reader);
	arrayResult = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2);
	interpreterProxy->stObjectatput(arrayResult, 1, interpreterProxy->popRemappableOop());
	interpreterProxy->stObjectatput(arrayResult, 2, interpreterProxy->popRemappableOop());
	interpreterProxy->pop(1);
	interpreterProxy->push(arrayResult);
}


/*	Create a pipe, and answer an array of two file handles for the pipe writer and reader.
	The session identifier is passed as the parameter to this primitive. Use this variant
	if the session identifier is not available directly in the VM (as may be the case if
	it is not possible to link from this plugin to a variable elsewhere in the VM).
	The readerIOStream and writerIOStream variables represent the low level pipe streams,
	which will be of type (FILE *) or HANDLE, depending on what the FilePlugin support
	code is using to represent file streams. FILEHANDLETYPE is defined in my subclasses
	in the #declareCVarsIn: class method. */

EXPORT(sqInt) primitiveMakePipeWithSessionIdentifier(void) {
    SESSIONIDENTIFIERTYPE thisSession;
    sqInt writer;
    FILEHANDLETYPE writerIOStream;
    SQFile *writerPtr;
    FILEHANDLETYPE *writerIOStreamPtr;
    SQFile *readerPtr;
    sqInt arrayResult;
    sqInt reader;
    FILEHANDLETYPE readerIOStream;
    FILEHANDLETYPE *readerIOStreamPtr;


	/* Create the anonymous OS pipe */

	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	readerIOStreamPtr = &readerIOStream;
	writerIOStreamPtr = &writerIOStream;
	if (!(makePipeForReaderwriter(readerIOStreamPtr, writerIOStreamPtr))) {
		return interpreterProxy->primitiveFail();
	}
	writer = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	writerPtr = interpreterProxy->arrayValueOf(writer);
	writerPtr->file = writerIOStream;
	writerPtr->sessionID = thisSession;
	writerPtr->writable = 1;
	writerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(writer);
	reader = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), fileRecordSize());
	readerPtr = interpreterProxy->arrayValueOf(reader);
	readerPtr->file = readerIOStream;
	readerPtr->sessionID = thisSession;
	readerPtr->writable = 0;
	readerPtr->lastOp = 0;
	interpreterProxy->pushRemappableOop(reader);
	arrayResult = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2);
	interpreterProxy->stObjectatput(arrayResult, 1, interpreterProxy->popRemappableOop());
	interpreterProxy->stObjectatput(arrayResult, 2, interpreterProxy->popRemappableOop());
	interpreterProxy->pop(2);
	interpreterProxy->push(arrayResult);
}


/*	Answer a string containing the module name string for this plugin. */

EXPORT(sqInt) primitiveModuleName(void) {
	interpreterProxy->popthenPush(1, stringFromCString(moduleName));
}


/*	Change the scheduling priority of this process by the given nice increment.
	A positive increment decreases the priority. Only the superuser can specify
	a negative value (to increase the priority). See man(2) nice.

	Different versions of Unix are inconsistent in their return values. The only
	reliable test for success is to clear errno prior to the call, and test its value
	if the result of nice() is -1. */

EXPORT(sqInt) primitiveNice(void) {
    int niceIncrement;
    extern int errno;
    sqInt result;

	niceIncrement = interpreterProxy->stackIntegerValue(0);
	errno = 0;
	result = nice(niceIncrement);
	if (result == -1) {
		if (!(errno == 0)) {
			return interpreterProxy->primitiveFail();
		}
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(result);
}


/*	Set an environment variable using a string of the form 'KEY=value'. This
	implementation allocates a C string using malloc to allocate from the C heap
	(using cStringFromString rather than transientCStringFromString). This
	is necessary because the C runtime library does not make a copy of the
	string into separately allocated environment memory. */

EXPORT(sqInt) primitivePutEnv(void) {
    char *cStringPtr;
    sqInt keyValueString;

	keyValueString = interpreterProxy->stackObjectValue(0);
	cStringPtr = cStringFromString(keyValueString);
	if ((putenv(cStringPtr)) == 0) {
		interpreterProxy->pop(2);
		interpreterProxy->push(keyValueString);
	} else {
		return interpreterProxy->primitiveFail();
	}
}


/*	Answer the real path for a path string as determined by realpath(). */

EXPORT(sqInt) primitiveRealpath(void) {
    char *pathString;
    sqInt newPathString;
    char *buffer;
    sqInt s;
    char * realpathResult;
    sqInt bufferSize;

	bufferSize = 1024;
	newPathString = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), bufferSize);
	interpreterProxy->pushRemappableOop(newPathString);
	pathString = transientCStringFromString(interpreterProxy->stackObjectValue(0));
	newPathString = interpreterProxy->popRemappableOop();
	buffer = interpreterProxy->arrayValueOf(newPathString);
	realpathResult = realpath(pathString, buffer);
	if (realpathResult == 0) {
		return interpreterProxy->primitiveFail();
	} else {
		if ((strlen(realpathResult)) >= 1024) {
			perror("warning: statically allocated array exceeded in UnixOSProcessPlugin>>primitiveRealPath, object memory may have been corrupted");
			return interpreterProxy->primitiveFail();
		}
		s = stringFromCString(realpathResult);
		interpreterProxy->pop(2);
		interpreterProxy->push(s);
	}
}


/*	Clean up after the death of a child, and answer an array with the pid and
	the exit status of the child process. Answer nil if the pidToHandle does not exist. */

EXPORT(sqInt) primitiveReapChildProcess(void) {
    pid_t pidResult;
    sqInt resultArray;
    sqInt *arrayPtr;
    int exitStatus;
    sqInt pidToHandle;


	/* Force C code translator to declare the variable */

	exitStatus = 0;
	pidToHandle = interpreterProxy->stackIntegerValue(0);
	pidResult = waitpid ( pidToHandle, &exitStatus, WNOHANG );
	if (pidResult <= 0) {
		interpreterProxy->pop(2);
		interpreterProxy->push(interpreterProxy->nilObject());
	} else {
		resultArray = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2);
		arrayPtr = interpreterProxy->firstIndexableField(resultArray);
		arrayPtr[0] = integerObjectOf(pidResult);
		arrayPtr[1] = integerObjectOf(exitStatus);
		interpreterProxy->pop(2);
		interpreterProxy->push(resultArray);
	}
}


/*	Take a struct SQFile from the stack, and call fflush() to flush the OS stream. This flushes the
	file stream in the C library, not the stream in Smalltalk. For output streams, consider setting
	the OS stream (C library) to unbuffered output, and letting Smalltalk do all the buffering. */

EXPORT(sqInt) primitiveSQFileFlush(void) {
    sqInt sqFileOop;
    int result;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	result = fflush(fileHandleFrom(sqFileOop));
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(result);
}


/*	Take a struct SQFile from the stack, and call fflush() to flush the OS stream. This flushes the
	file stream in the C library, not the stream in Smalltalk. For output streams, consider setting
	the OS stream (C library) to unbuffered output, and letting Smalltalk do all the buffering.
	The session identifier is passed as the parameter to this primitive. Use this variant if the session
	identifier is not available directly in the VM (as may be the case if it is not possible to link from
	this plugin to a variable elsewhere in the VM). */

EXPORT(sqInt) primitiveSQFileFlushWithSessionIdentifier(void) {
    sqInt sqFileOop;
    int result;

	sqFileOop = interpreterProxy->stackValue(1);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	result = fflush(fileHandleFrom(sqFileOop));
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(result);
}


/*	Take a struct SQFile from the stack, and call fcntl() to set the file for blocking I/O. */

EXPORT(sqInt) primitiveSQFileSetBlocking(void) {
    sqInt sqFileOop;
    sqInt descriptor;
    int flags;
    sqInt retVal;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		descriptor = -1;
		goto l1;
	}
	descriptor = fileno(fileHandleFrom(sqFileOop));
l1:	/* end fileDescriptorFrom: */;
	if (descriptor == -1) {
		return interpreterProxy->primitiveFail();
	}
	flags = fcntl(descriptor, F_GETFL);
	retVal = fcntl(descriptor, F_SETFL, flags & ~O_NONBLOCK);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(retVal);
}


/*	Take a struct SQFile from the stack, and call fcntl() to set the file for blocking I/O.
	Use this variant if the session identifier is not available directly in the VM (as may be
	the case if it is not possible to link from this plugin to a variable elsewhere in the VM). */

EXPORT(sqInt) primitiveSQFileSetBlockingWithSessionIdentifier(void) {
    sqInt sqFileOop;
    sqInt descriptor;
    SESSIONIDENTIFIERTYPE thisSession;
    SQFile *sqFile;
    sqInt flags;
    sqInt retVal;

	sqFileOop = interpreterProxy->stackValue(1);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	sqFile = interpreterProxy->arrayValueOf(sqFileOop);
	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	if (thisSession == (sqFile->sessionID)) {
		/* begin fileDescriptorFrom: */
		if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
			descriptor = -1;
			goto l1;
		}
		descriptor = fileno(fileHandleFrom(sqFileOop));
	l1:	/* end fileDescriptorFrom: */;
		if (descriptor < 0) {
			return interpreterProxy->primitiveFail();
		}
		flags = fcntl(descriptor, F_GETFL);
		retVal = fcntl(descriptor, F_SETFL, flags & ~O_NONBLOCK);
		interpreterProxy->pop(3);
		interpreterProxy->pushInteger(retVal);
	} else {
		return interpreterProxy->primitiveFail();
	}
}


/*	Take a struct SQFile from the stack, and call fcntl() to set the file non-blocking I/O. */

EXPORT(sqInt) primitiveSQFileSetNonBlocking(void) {
    sqInt sqFileOop;
    sqInt descriptor;
    int flags;
    sqInt retVal;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	/* begin fileDescriptorFrom: */
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		descriptor = -1;
		goto l1;
	}
	descriptor = fileno(fileHandleFrom(sqFileOop));
l1:	/* end fileDescriptorFrom: */;
	if (descriptor < 0) {
		return interpreterProxy->primitiveFail();
	}
	flags = fcntl(descriptor, F_GETFL);
	retVal = fcntl(descriptor, F_SETFL, flags | O_NONBLOCK);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(retVal);
}


/*	Take a struct SQFile from the stack, and call fcntl() to set the file non-blocking I/O.
	Use this variant if the session identifier is not available directly in the VM (as may be
	the case if it is not possible to link from this plugin to a variable elsewhere in the VM). */

EXPORT(sqInt) primitiveSQFileSetNonBlockingWithSessionIdentifier(void) {
    sqInt sqFileOop;
    sqInt descriptor;
    SESSIONIDENTIFIERTYPE thisSession;
    SQFile *sqFile;
    sqInt flags;
    sqInt retVal;

	sqFileOop = interpreterProxy->stackValue(1);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	sqFile = interpreterProxy->arrayValueOf(sqFileOop);
	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	if (thisSession == (sqFile->sessionID)) {
		/* begin fileDescriptorFrom: */
		if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
			descriptor = -1;
			goto l1;
		}
		descriptor = fileno(fileHandleFrom(sqFileOop));
	l1:	/* end fileDescriptorFrom: */;
		if (descriptor < 0) {
			return interpreterProxy->primitiveFail();
		}
		flags = fcntl(descriptor, F_GETFL);
		retVal = fcntl(descriptor, F_SETFL, flags | O_NONBLOCK);
		interpreterProxy->pop(3);
		interpreterProxy->pushInteger(retVal);
	} else {
		return interpreterProxy->primitiveFail();
	}
}


/*	Take a struct SQFile from the stack, and call setbuf() to set the OS file stream
	(implemented in the C library) for unbuffered I/O. Answers the result of a fflush()
	call, not the result of the setbuf() call (which is type void). This is nearly useless,
	but may at least provide an indicator that we are operating on a valid file stream. */

EXPORT(sqInt) primitiveSQFileSetUnbuffered(void) {
    sqInt sqFileOop;
    sqInt retVal;
    FILEHANDLETYPE file;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	file = fileHandleFrom(sqFileOop);
	retVal = fflush(file);
	setbuf(file, 0);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(retVal);
}


/*	Take a struct SQFile from the stack, and call setbuf() to set the OS file stream (implemented in
	the C library) for unbuffered I/O. Answers the result of a fflush() call, not the result of the
	setbuf() call (which is type void). This is nearly useless, but may at least provide an indicator
	that we are operating on a valid file stream. Use this variant if the session identifier is not
	available directly in the VM (as may be the case if it is not possible to link from this plugin
	to a variable elsewhere in the VM). */

EXPORT(sqInt) primitiveSQFileSetUnbufferedWithSessionIdentifier(void) {
    sqInt sqFileOop;
    SESSIONIDENTIFIERTYPE thisSession;
    SQFile *sqFile;
    sqInt retVal;

	sqFileOop = interpreterProxy->stackValue(1);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	sqFile = interpreterProxy->arrayValueOf(sqFileOop);
	thisSession = sessionIdentifierFrom(interpreterProxy->stackObjectValue(0));
	if (thisSession == (sqFile->sessionID)) {
		retVal = fflush(sqFile->file);
		setbuf(sqFile->file, NULL);
		interpreterProxy->pop(3);
		interpreterProxy->pushInteger(retVal);
	} else {
		return interpreterProxy->primitiveFail();
	}
}


/*	Answer the registration index of the semaphore currently associated with the
	signal handler for sigNum. */

EXPORT(sqInt) primitiveSemaIndexFor(void) {
    sqInt sigNum;
    sqInt index;

	sigNum = interpreterProxy->stackIntegerValue(0);
	index = semaIndices[sigNum];
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(index);
}


/*	Send SIGABRT (abort) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigabrtTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigAbrtNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGALRM (alarm clock) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigalrmTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigAlrmNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGCHLD (child status has changed, usually death of child) to the OS process
	identified by anIntegerPid. Use an explicit check for isIntegerObject so we can
	return -1 on error (the stackIntegerValue: method answers 1 on error, and 1 is a
	valid pid number). */

EXPORT(sqInt) primitiveSendSigchldTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigChldNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGCONT (continue) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigcontTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigContNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGHUP (hangup) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSighupTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigHupNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGINT (interrupt) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigintTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigIntNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGKILL (kill, unblockable) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigkillTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigKillNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGPIPE (broken pipe) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigpipeTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigPipeNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGQUIT (quit) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigquitTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigQuitNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGSTOP (stop, unblockable) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigstopTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigStopNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGTERM (termination) to the OS process identified by anIntegerPid. Use an explicit
	check for isIntegerObject so we can return -1 on error (the stackIntegerValue: method
	answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigtermTo(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigTermNumber();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGUSR1 (User-defined signal 1) to the OS process identified by anIntegerPid. Use
	an explicit check for isIntegerObject so we can return -1 on error (the stackIntegerValue:
	method answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigusr1To(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigUsr1Number();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Send SIGUSR2 (User-defined signal 2) to the OS process identified by anIntegerPid. Use
	an explicit check for isIntegerObject so we can return -1 on error (the stackIntegerValue:
	method answers 1 on error, and 1 is a valid pid number). */

EXPORT(sqInt) primitiveSendSigusr2To(sqInt anIntegerPid) {
    pid_t pidToSignal;
    int result;
    sqInt sig;

	if ((sandboxSecurity()) == 1) {
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(-1);
	} else {
		if (((interpreterProxy->stackValue(0)) & 1)) {
			pidToSignal = interpreterProxy->stackIntegerValue(0);
			/* begin sendSignal:toPid: */
			sig = sigUsr2Number();
			result = kill(pidToSignal, sig);
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(result);
		} else {
			interpreterProxy->pop(2);
			interpreterProxy->pushInteger(-1);
		}
	}
}


/*	Set the process group ID of the process identified by pid to a new process
	group ID. */

EXPORT(sqInt) primitiveSetPGid(void) {
    pid_t pgid;
    pid_t pid;

	pid = interpreterProxy->stackIntegerValue(1);
	pgid = interpreterProxy->stackIntegerValue(0);
	if ((setpgid(pid, pgid)) == -1) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
}


/*	Set a new process group for this OS process. Newly created child processes
	will be members of the new process group. Note: Use setpgid(0,0) rather than
	the equivalent setpgrp() because setpgrp() is implemented differently on
	some flavors of Unix. */

EXPORT(sqInt) primitiveSetPGrp(void) {
	if ((setpgid(0, 0)) == -1) {
		return interpreterProxy->primitiveFail();
	}
}


/*	Set the index of the semaphore used by the OSProcess with which I collaborate. My
	OSProcess should set this value so that I can use it when handling SIGCHLD signals
	(death of child). In the C translation this is a static int which would be shared by all
	instances of UnixOSProcessPlugin, which is expected to be a singleton. Answer the
	value of the semaphore index. */

EXPORT(sqInt) primitiveSetSemaIndex(void) {
	sigChldSemaIndex = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(sigChldSemaIndex);
}


/*	Quoted from Linux man pages:
	setsid() creates a new session if the calling process is not a process group leader.
	The calling process is the leader of the new session, the process  group  leader  of
	the new process group, and has no controlling tty.  The process group ID and session
	ID of the calling process are set to the PID of the calling  process.   The  calling
	process  will be the only process in this new process group and in this new session. */

EXPORT(sqInt) primitiveSetSid(void) {
    pid_t sessionId;

	sessionId = setsid();
	if (sessionId == -1) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sessionId);
}


/*	Integer value corresponding to SIGCHLD */

EXPORT(sqInt) primitiveSigChldNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigChldNumber());
}


/*	Integer value corresponding to SIGHUP */

EXPORT(sqInt) primitiveSigHupNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigHupNumber());
}


/*	Integer value corresponding to SIGINT */

EXPORT(sqInt) primitiveSigIntNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigIntNumber());
}


/*	Integer value corresponding to SIGKILL */

EXPORT(sqInt) primitiveSigKillNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigKillNumber());
}


/*	Integer value corresponding to SIGPIPE */

EXPORT(sqInt) primitiveSigPipeNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigPipeNumber());
}


/*	Integer value corresponding to SIGQUIT */

EXPORT(sqInt) primitiveSigQuitNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigQuitNumber());
}


/*	Integer value corresponding to SIGTERM */

EXPORT(sqInt) primitiveSigTermNumber(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigTermNumber());
}


/*	Integer value corresponding to SIGUSR1 */

EXPORT(sqInt) primitiveSigUsr1Number(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigUsr1Number());
}


/*	Integer value corresponding to SIGUSR2 */

EXPORT(sqInt) primitiveSigUsr2Number(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sigUsr2Number());
}


/*	Size in bytes of an integer, for this C compiler on this machine. */

EXPORT(sqInt) primitiveSizeOfInt(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sizeOfInt());
}


/*	Size in bytes of a void pointer, for this C compiler on this machine. */

EXPORT(sqInt) primitiveSizeOfPointer(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(sizeOfPointer());
}


/*	Take a struct SQFile from the stack, and call feof(3) to determine if the file has
	reached end of file. The flag is set only by a previous read operation, so end of
	file is not detected until an actual EOF condition has been detected by a read attempt. */

EXPORT(sqInt) primitiveTestEndOfFileFlag(void) {
    sqInt sqFileOop;
    sqInt result;
    FILEHANDLETYPE file;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	file = fileHandleFrom(sqFileOop);
	if (file == 0) {
		return primitiveFail();
	}
	if (feof(file)) {
		result = interpreterProxy->trueObject();
	} else {
		result = interpreterProxy->falseObject();
	}
	interpreterProxy->pop(2);
	interpreterProxy->push(result);
}


/*	Take a struct SQFile from the stack, and check for ability to lock the specified region.
	If the exclusive flag is true, then specify an exclusive (F_WRLCK) lock on the
     file. Otherwise, specify a shared (F_RDLCK) lock. Any number of Unix processes
     may hold  a read lock (shared lock) on a file region, but only one process may
     hold a write lock (exclusive lock).

	If length is zero, then the request is for the entire file to be locked, including
	region extents that have not yet been allocated for the file.

	If the fcntl() call fails, answer -1 (the result of the failed call). Otherwise,
	answer an array with the following six fields:
		lockable (true or false)
		l_pid (pid of the process preventing this lock request, or nil)
		l_type (request type F_WRLCK or F_RDLOCK of the process preventing this lock request)
		l_whence (the SEEK_SET, SEEK_CUR, or SEEK_END value of the lock preventing this lock request).
		l_start (offset of the region lock preventing this lock request)
		l_len (length of the region lock preventing this lock request) */

EXPORT(sqInt) primitiveTestLockableFileRegion(void) {
    struct flock lockStruct;
    sqInt exclusive;
    sqInt sqFileOop;
    sqInt start;
    sqInt resultArray;
    int result;
    sqInt len;
    int fileNo;
    sqInt canObtainLock;

	exclusive = (interpreterProxy->stackValue(0)) == (interpreterProxy->trueObject());
	len = interpreterProxy->stackIntegerValue(1);
	start = interpreterProxy->stackIntegerValue(2);
	sqFileOop = interpreterProxy->stackValue(3);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}

	/* Set up the flock structure parameter for fcntl() */

	fileNo = unixFileNumber(fileHandleFrom(sqFileOop));
	if (exclusive) {
		lockStruct.l_type = F_WRLCK;
	} else {
		lockStruct.l_type = F_RDLCK;
	}
	lockStruct.l_whence = SEEK_SET;
	lockStruct.l_start = start;
	lockStruct.l_len = len;
	lockStruct.l_pid = 0;
	result = fcntl(fileNo, F_GETLK, &lockStruct);
	if (result == -1) {
		interpreterProxy->pop(5);
		interpreterProxy->pushInteger(result);
	} else {
		if (lockStruct.l_type == F_UNLCK) {
			canObtainLock = interpreterProxy->trueObject();
		} else {
			canObtainLock = interpreterProxy->falseObject();
		}
		resultArray = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 6);
		interpreterProxy->stObjectatput(resultArray, 1, canObtainLock);
		interpreterProxy->stObjectatput(resultArray, 2, (((lockStruct.l_pid) << 1) | 1));
		interpreterProxy->stObjectatput(resultArray, 3, (((lockStruct.l_type) << 1) | 1));
		interpreterProxy->stObjectatput(resultArray, 4, (((lockStruct.l_whence) << 1) | 1));
		interpreterProxy->stObjectatput(resultArray, 5, (((lockStruct.l_start) << 1) | 1));
		interpreterProxy->stObjectatput(resultArray, 6, (((lockStruct.l_len) << 1) | 1));
		interpreterProxy->popthenPush(5, resultArray);
	}
}


/*	Close a file handle at the close(2) level, using a handle returned by
	#primitiveUnixFileNumber. */

EXPORT(sqInt) primitiveUnixFileClose(sqInt anIntegerFileNumber) {
    int result;
    int handle;

	handle = interpreterProxy->stackIntegerValue(0);
	result = close(handle);
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(result);
}


/*	Take a struct SQFile from the stack, and answer the value of its Unix file number.
	The Unix file number is not directly useful to Squeak, but may be interesting for
	debugging problems involving failure to close unused file handles. */

EXPORT(sqInt) primitiveUnixFileNumber(void) {
    sqInt sqFileOop;
    int fileNo;

	sqFileOop = interpreterProxy->stackValue(0);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}
	fileNo = unixFileNumber(fileHandleFrom(sqFileOop));
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(fileNo);
}


/*	Take a struct SQFile from the stack, and unlock the specified region.
	Answer the result of the call to fcntl(). If the region is in the file lock cache,
	remove it, but otherwise ignore the cache. The cache supports Win32 semantics
	within a single Squeak image, but not across separate images, therefore the
	unlock should be attempted regardless of whether this image thinks that the
	region has previously been locked. Answer the result of the call to fcntl(). */

EXPORT(sqInt) primitiveUnlockFileRegion(void) {
    struct flock lockStruct;
    sqInt sqFileOop;
    sqInt start;
    int result;
    sqInt len;
    int fileNo;

	len = interpreterProxy->stackIntegerValue(0);
	start = interpreterProxy->stackIntegerValue(1);
	sqFileOop = interpreterProxy->stackValue(2);
	if (!((((interpreterProxy->isBytes(sqFileOop)) && ((interpreterProxy->byteSizeOf(sqFileOop)) == (fileRecordSize()))) && ((interpreterProxy->getThisSessionID()) == (sessionIdentifierFromSqFile(interpreterProxy->arrayValueOf(sqFileOop))))) && (isNonNullSQFile(sqFileOop)))) {
		return interpreterProxy->primitiveFail();
	}

	/* Set up the flock structure parameter for fcntl() */

	fileNo = unixFileNumber(fileHandleFrom(sqFileOop));
	lockStruct.l_type = F_UNLCK;
	lockStruct.l_whence = SEEK_SET;
	lockStruct.l_start = start;
	lockStruct.l_len = len;
	lockStruct.l_pid = 0;
	result = fcntl(fileNo, F_SETLK, &lockStruct);
	interpreterProxy->pop(4);
	interpreterProxy->pushInteger(result);
}


/*	Unset an environment variable. */
/*	FIXME: unsetenv() is not portable. For Solaris or any other system which does not
	support unsetenv(), just comment it out in this method and rebuild the plugin. */

EXPORT(sqInt) primitiveUnsetEnv(void) {
	unsetenv(transientCStringFromString(interpreterProxy->stackObjectValue(0)));
	interpreterProxy->pop(1);
}


/*	Answer a string containing the version string for this plugin. */

EXPORT(sqInt) primitiveVersionString(void) {
	interpreterProxy->pop(1);
	interpreterProxy->push(stringFromCString(versionString()));
}


/*	This is a signal handler for SIGCHLD. It is not meant to be called from Smalltalk,
	and should only be called indirectly as a result of a death of child signal from
	the operating system.

	Child processes must be cleaned up by the parent, otherwise they continue
	to exist as zombies until the parent exits. This handler resets the signal handler
	to catch the next SIGCHLD signal, then sets a semaphore to notify the system
	that a child process needs to be cleaned up. The actual clean up is done by a
	Smalltalk process which waits on the semaphore, then calls primitiveReapChildProcess.

	Note: If child processes die faster than we can clean them up, signals will be lost
	and child processes will remain as zombies. */

static void reapChildProcess(int sigNum) {
	setSigChldHandler();
	if (sigChldSemaIndex > 0) {
		interpreterProxy->signalSemaphoreWithIndex(sigChldSemaIndex);
	}
}


/*	Signal sigNum has been caught by a thread other than the pthread in which
	the interpreter is executing. Rather than handling it in this thread, resend
	it to the interpreter thread. */

static sqInt resendSignal(int sigNum) {
	pthread_kill(vmThread, sigNum);
}


/*	Restore signal handlers to their original behaviors. */

static void restoreDefaultSignalHandlers(void) {
    sqInt sigNum;

	sigNum = 1;
	while (sigNum <= (signalArraySize())) {
		if ((semaIndices[sigNum]) > 0) {
			setSignalNumberhandler(sigNum, originalSigHandlers[sigNum]);
		}
		sigNum += 1;
	}
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


/*	An array of Smalltalk Semaphore indices, one for each signal type for which
	a handler has been set. If an entry is zero, then no handler is active. */

static unsigned char * semaphoreIndices(void) {
	return semaIndices;
}


/*	kill(pid, sig) */

static sqInt sendSignaltoPid(sqInt sig, sqInt pid) {
	return kill(pid, sig);
}


/*	Exit function to be registered with atexit() to signal child processes on VM exit. */

static void sendSignalToPids(void) {
    sqInt count;
    pid_t pid;
    sqInt sig;

	count = 0;
	while (count < pidCount) {
		pid = pidArray[count];
		/* begin sendSignal:toPid: */
		sig = sigNumToSend;
		kill(pid, sig);
		count += 1;
	}
}


/*	Answer a session ID represented by aByteArray. The session ID is used in
	the SQFile structure. If that data structure changes, we should see compiler
	warnings about type mismatch with SESSIONIDENTIFIERTYPE. */

static SESSIONIDENTIFIERTYPE sessionIdentifierFrom(sqInt aByteArray) {
    union {SESSIONIDENTIFIERTYPE session; unsigned char bytes[sizeof(SESSIONIDENTIFIERTYPE)];} sessionUnion;
    unsigned char *session;
    sqInt idx;

	if (!((interpreterProxy->isBytes(aByteArray)) && ((interpreterProxy->stSizeOf(aByteArray)) == (sizeOfSession())))) {
		return null;
	}
	session = interpreterProxy->arrayValueOf(aByteArray);
	idx = 0;
	while (idx < (sizeOfSession())) {
		sessionUnion.bytes[idx] = session[idx];
		idx += 1;
	}
	return sessionUnion.session;
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

static void setSigChldDefaultHandler(void) {
	setSignalNumberhandler(sigChldNumber(), sigDefaultNumber());
}


/*	Set the SIGCHLD signal handler in the virtual machine. */

static void setSigChldHandler(void) {
	if ((signal(SIGCHLD, reapChildProcess)) == (sigErrorNumber())) {
		perror("signal");
	}
}

static void setSigIntDefaultHandler(void) {
	setSignalNumberhandler(sigIntNumber(), sigDefaultNumber());
}


/*	Set the SIGINT signal handler in the virtual machine to ignore interrupts. */

static void setSigIntIgnore(void) {
	setSignalNumberhandler(sigIntNumber(), sigIgnoreNumber());
}

static void setSigPipeDefaultHandler(void) {
	setSignalNumberhandler(sigPipeNumber(), sigDefaultNumber());
}


/*	Set the SIGPIPE signal handler in the virtual machine to ignore pipe error signals.
	If a pipe is opened to a child process, and the child exits, then subsequent writes to
	the pipe generate a SIGPIPE signal. If this signal is not handled, the VM will exit
	without warning. */

static sqInt setSigPipeHandler(void) {
	/* begin setSigPipeIgnore */
	setSignalNumberhandler(sigPipeNumber(), sigIgnoreNumber());
}


/*	Set the SIGPIPE signal handler in the virtual machine to ignore pipe error signals. */

static void setSigPipeIgnore(void) {
	setSignalNumberhandler(sigPipeNumber(), sigIgnoreNumber());
}


/*	Set a signal handler. The C code translator will convert #sig:nal: into 'signal(parm1, parm2)' */

static void * setSignalNumberhandler(sqInt anInteger, void * signalHandlerAddress) {
	return signal(anInteger, signalHandlerAddress);
}

EXPORT(sqInt) shutdownModule(void) {
    sqInt sigNum;

	/* begin restoreDefaultSignalHandlers */
	sigNum = 1;
	while (sigNum <= (signalArraySize())) {
		if ((semaIndices[sigNum]) > 0) {
			setSignalNumberhandler(sigNum, originalSigHandlers[sigNum]);
		}
		sigNum += 1;
	}
}


/*	Abort signal from abort(3) */

static sqInt sigAbrtNumber(void) {
	return SIGABRT;
}


/*	Timer signal from alarm(2) */

static sqInt sigAlrmNumber(void) {
	return SIGALRM;
}


/*	Child status has changed (POSIX). */

static sqInt sigChldNumber(void) {
	return SIGCHLD;
}


/*	Continue if stopped */

static sqInt sigContNumber(void) {
	return SIGCONT;
}


/*	Default action for a signal */

static void * sigDefaultNumber(void) {
	return SIG_DFL;
}


/*	Error return from signal() */

static void * sigErrorNumber(void) {
	return SIG_ERR;
}


/*	Hangup detected on controlling terminal or death of controlling process */

static sqInt sigHupNumber(void) {
	return SIGHUP;
}


/*	Ignore action for a signal */

static void * sigIgnoreNumber(void) {
	return SIG_IGN;
}


/*	Interrupt (ANSI). */

static sqInt sigIntNumber(void) {
	return SIGINT;
}


/*	Kill signal */

static sqInt sigKillNumber(void) {
	return SIGKILL;
}


/*	Broken pipe (POSIX). */

static sqInt sigPipeNumber(void) {
	return SIGPIPE;
}


/*	Quit from keyboard */

static sqInt sigQuitNumber(void) {
	return SIGQUIT;
}


/*	Stop process */

static sqInt sigStopNumber(void) {
	return SIGSTOP;
}


/*	Termination signal. This is the default signal sent by the unix kill(1) command. */

static sqInt sigTermNumber(void) {
	return SIGTERM;
}


/*	User defined signal number 1. This is value is platform-dependent, so the
	inSmalltalk default of 10 may be wrong on some platforms. */

static sqInt sigUsr1Number(void) {
	return SIGUSR1;
}


/*	User defined signal number 2. This is value is platform-dependent, so the
	inSmalltalk default of 12 may be wrong on some platforms. */

static sqInt sigUsr2Number(void) {
	return SIGUSR2;
}


/*	Number of possible signals for this OS plus one. The signal handler arrays
	declared in #declareCVarsIn: are this size. */

static sqInt signalArraySize(void) {
	return NSIG;
}


/*	An array of signal handler function addresses, with each entry corresponding
	to a signal type. */

static void ** signalHandlers(void) {
	return sigHandlers;
}


/*	Size in bytes of an integer, for this C compiler on this machine. */

static sqInt sizeOfInt(void) {
	return sizeof(int);
}


/*	Size in bytes of a void pointer, for this C compiler on this machine. */

static sqInt sizeOfPointer(void) {
	return sizeof(void *);
}


/*	Size of a SESSIONIDENTIFIERTYPE. Should match usage in the SQFile data structure,
	otherwise we should get compiler warnings. */

static sqInt sizeOfSession(void) {
	return sizeof(SESSIONIDENTIFIERTYPE);
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


/*	Answer the integer Unix file number corresponding to a file handle (FILE* ). */

static int unixFileNumber(FILEHANDLETYPE fileHandle) {
	return fileno(fileHandle);
}


/*	Answer a string containing the version string for this plugin. Handle MNU
	errors, which can occur if class InterpreterPlugin has been removed from
	the system.

	Important: When this method is changed, the class side method must also be
	changed to match. */
/*	4.0 supports 64bit code base */

static char * versionString(void) {
    static char version[]= "4.3.3";

	return version;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* UnixOSProcessPlugin_exports[][3] = {
	{"UnixOSProcessPlugin", "primitiveSendSigalrmTo", (void*)primitiveSendSigalrmTo},
	{"UnixOSProcessPlugin", "primitiveSendSigchldTo", (void*)primitiveSendSigchldTo},
	{"UnixOSProcessPlugin", "primitiveCanReceiveSignals", (void*)primitiveCanReceiveSignals},
	{"UnixOSProcessPlugin", "primitiveSendSigquitTo", (void*)primitiveSendSigquitTo},
	{"UnixOSProcessPlugin", "primitiveGetStdInHandle", (void*)primitiveGetStdInHandle},
	{"UnixOSProcessPlugin", "primitiveLockFileRegion", (void*)primitiveLockFileRegion},
	{"UnixOSProcessPlugin", "primitiveEnvironmentAt", (void*)primitiveEnvironmentAt},
	{"UnixOSProcessPlugin", "setInterpreter", (void*)setInterpreter},
	{"UnixOSProcessPlugin", "primitiveGetUid", (void*)primitiveGetUid},
	{"UnixOSProcessPlugin", "primitiveForkSqueakWithoutSigHandler", (void*)primitiveForkSqueakWithoutSigHandler},
	{"UnixOSProcessPlugin", "primitiveSetSid", (void*)primitiveSetSid},
	{"UnixOSProcessPlugin", "primitiveCreatePipeWithSessionIdentifier", (void*)primitiveCreatePipeWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveGetStdOutHandleWithSessionIdentifier", (void*)primitiveGetStdOutHandleWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveSigKillNumber", (void*)primitiveSigKillNumber},
	{"UnixOSProcessPlugin", "primitiveArgumentAt", (void*)primitiveArgumentAt},
	{"UnixOSProcessPlugin", "primitiveAioHandle", (void*)primitiveAioHandle},
	{"UnixOSProcessPlugin", "primitiveAioSuspend", (void*)primitiveAioSuspend},
	{"UnixOSProcessPlugin", "primitiveModuleName", (void*)primitiveModuleName},
	{"UnixOSProcessPlugin", "primitiveTestLockableFileRegion", (void*)primitiveTestLockableFileRegion},
	{"UnixOSProcessPlugin", "primitiveSetPGrp", (void*)primitiveSetPGrp},
	{"UnixOSProcessPlugin", "primitiveSQFileSetBlocking", (void*)primitiveSQFileSetBlocking},
	{"UnixOSProcessPlugin", "primitiveGetEUid", (void*)primitiveGetEUid},
	{"UnixOSProcessPlugin", "primitiveSigQuitNumber", (void*)primitiveSigQuitNumber},
	{"UnixOSProcessPlugin", "primitiveGetPGrp", (void*)primitiveGetPGrp},
	{"UnixOSProcessPlugin", "primitiveSendSigcontTo", (void*)primitiveSendSigcontTo},
	{"UnixOSProcessPlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"UnixOSProcessPlugin", "initialiseModule", (void*)initialiseModule},
	{"UnixOSProcessPlugin", "primitiveFixPointersInArrayOfStrings", (void*)primitiveFixPointersInArrayOfStrings},
	{"UnixOSProcessPlugin", "primitiveSendSigstopTo", (void*)primitiveSendSigstopTo},
	{"UnixOSProcessPlugin", "primitiveGetGid", (void*)primitiveGetGid},
	{"UnixOSProcessPlugin", "primitiveSizeOfInt", (void*)primitiveSizeOfInt},
	{"UnixOSProcessPlugin", "primitiveTestEndOfFileFlag", (void*)primitiveTestEndOfFileFlag},
	{"UnixOSProcessPlugin", "primitiveSetSemaIndex", (void*)primitiveSetSemaIndex},
	{"UnixOSProcessPlugin", "primitiveCreatePipe", (void*)primitiveCreatePipe},
	{"UnixOSProcessPlugin", "primitiveFileStat", (void*)primitiveFileStat},
	{"UnixOSProcessPlugin", "primitiveSQFileSetUnbuffered", (void*)primitiveSQFileSetUnbuffered},
	{"UnixOSProcessPlugin", "primitiveSQFileSetNonBlockingWithSessionIdentifier", (void*)primitiveSQFileSetNonBlockingWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveNice", (void*)primitiveNice},
	{"UnixOSProcessPlugin", "primitiveSQFileFlushWithSessionIdentifier", (void*)primitiveSQFileFlushWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveGetCurrentWorkingDirectory", (void*)primitiveGetCurrentWorkingDirectory},
	{"UnixOSProcessPlugin", "primitiveSigHupNumber", (void*)primitiveSigHupNumber},
	{"UnixOSProcessPlugin", "primitiveSigUsr1Number", (void*)primitiveSigUsr1Number},
	{"UnixOSProcessPlugin", "primitiveMakePipe", (void*)primitiveMakePipe},
	{"UnixOSProcessPlugin", "primitiveGetStdErrHandleWithSessionIdentifier", (void*)primitiveGetStdErrHandleWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveSQFileSetBlockingWithSessionIdentifier", (void*)primitiveSQFileSetBlockingWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveForkExec", (void*)primitiveForkExec},
	{"UnixOSProcessPlugin", "primitiveErrorMessageAt", (void*)primitiveErrorMessageAt},
	{"UnixOSProcessPlugin", "primitiveGetPid", (void*)primitiveGetPid},
	{"UnixOSProcessPlugin", "primitiveDupTo", (void*)primitiveDupTo},
	{"UnixOSProcessPlugin", "primitiveRealpath", (void*)primitiveRealpath},
	{"UnixOSProcessPlugin", "primitiveSendSigusr2To", (void*)primitiveSendSigusr2To},
	{"UnixOSProcessPlugin", "primitiveReapChildProcess", (void*)primitiveReapChildProcess},
	{"UnixOSProcessPlugin", "primitiveSendSigkillTo", (void*)primitiveSendSigkillTo},
	{"UnixOSProcessPlugin", "primitiveSQFileSetUnbufferedWithSessionIdentifier", (void*)primitiveSQFileSetUnbufferedWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveForkAndExecInDirectory", (void*)primitiveForkAndExecInDirectory},
	{"UnixOSProcessPlugin", "primitiveGetStdErrHandle", (void*)primitiveGetStdErrHandle},
	{"UnixOSProcessPlugin", "primitiveUnixFileClose", (void*)primitiveUnixFileClose},
	{"UnixOSProcessPlugin", "primitiveUnlockFileRegion", (void*)primitiveUnlockFileRegion},
	{"UnixOSProcessPlugin", "shutdownModule", (void*)shutdownModule},
	{"UnixOSProcessPlugin", "primitiveSizeOfPointer", (void*)primitiveSizeOfPointer},
	{"UnixOSProcessPlugin", "primitiveGetThreadID", (void*)primitiveGetThreadID},
	{"UnixOSProcessPlugin", "primitiveSQFileFlush", (void*)primitiveSQFileFlush},
	{"UnixOSProcessPlugin", "primitiveSendSigabrtTo", (void*)primitiveSendSigabrtTo},
	{"UnixOSProcessPlugin", "primitivePutEnv", (void*)primitivePutEnv},
	{"UnixOSProcessPlugin", "primitiveKillOnExit", (void*)primitiveKillOnExit},
	{"UnixOSProcessPlugin", "primitiveUnsetEnv", (void*)primitiveUnsetEnv},
	{"UnixOSProcessPlugin", "primitiveForkSqueak", (void*)primitiveForkSqueak},
	{"UnixOSProcessPlugin", "primitiveSetPGid", (void*)primitiveSetPGid},
	{"UnixOSProcessPlugin", "primitiveSigIntNumber", (void*)primitiveSigIntNumber},
	{"UnixOSProcessPlugin", "primitiveGetPGid", (void*)primitiveGetPGid},
	{"UnixOSProcessPlugin", "primitiveGetSession", (void*)primitiveGetSession},
	{"UnixOSProcessPlugin", "primitiveSendSighupTo", (void*)primitiveSendSighupTo},
	{"UnixOSProcessPlugin", "primitiveGetEGid", (void*)primitiveGetEGid},
	{"UnixOSProcessPlugin", "primitiveFileProtectionMask", (void*)primitiveFileProtectionMask},
	{"UnixOSProcessPlugin", "primitiveMakePipeWithSessionIdentifier", (void*)primitiveMakePipeWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveGetStdInHandleWithSessionIdentifier", (void*)primitiveGetStdInHandleWithSessionIdentifier},
	{"UnixOSProcessPlugin", "primitiveVersionString", (void*)primitiveVersionString},
	{"UnixOSProcessPlugin", "primitiveChdir", (void*)primitiveChdir},
	{"UnixOSProcessPlugin", "primitiveGetStdOutHandle", (void*)primitiveGetStdOutHandle},
	{"UnixOSProcessPlugin", "primitiveSQFileSetNonBlocking", (void*)primitiveSQFileSetNonBlocking},
	{"UnixOSProcessPlugin", "primitiveSendSigintTo", (void*)primitiveSendSigintTo},
	{"UnixOSProcessPlugin", "primitiveSemaIndexFor", (void*)primitiveSemaIndexFor},
	{"UnixOSProcessPlugin", "primitiveSigChldNumber", (void*)primitiveSigChldNumber},
	{"UnixOSProcessPlugin", "primitiveSendSigpipeTo", (void*)primitiveSendSigpipeTo},
	{"UnixOSProcessPlugin", "getModuleName", (void*)getModuleName},
	{"UnixOSProcessPlugin", "primitiveForwardSignalToSemaphore", (void*)primitiveForwardSignalToSemaphore},
	{"UnixOSProcessPlugin", "primitiveSigTermNumber", (void*)primitiveSigTermNumber},
	{"UnixOSProcessPlugin", "primitiveAioDisable", (void*)primitiveAioDisable},
	{"UnixOSProcessPlugin", "primitiveGetPPid", (void*)primitiveGetPPid},
	{"UnixOSProcessPlugin", "primitiveAioEnable", (void*)primitiveAioEnable},
	{"UnixOSProcessPlugin", "primitiveSigPipeNumber", (void*)primitiveSigPipeNumber},
	{"UnixOSProcessPlugin", "primitiveSendSigtermTo", (void*)primitiveSendSigtermTo},
	{"UnixOSProcessPlugin", "primitiveSendSigusr1To", (void*)primitiveSendSigusr1To},
	{"UnixOSProcessPlugin", "primitiveUnixFileNumber", (void*)primitiveUnixFileNumber},
	{"UnixOSProcessPlugin", "primitiveIsAtEndOfFile", (void*)primitiveIsAtEndOfFile},
	{"UnixOSProcessPlugin", "primitiveEnvironmentAtSymbol", (void*)primitiveEnvironmentAtSymbol},
	{"UnixOSProcessPlugin", "primitiveSigUsr2Number", (void*)primitiveSigUsr2Number},
	{"UnixOSProcessPlugin", "forkSqueak", (void*)forkSqueak},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

