/* sqUnixMain.c -- support for Unix.
 * 
 *   Copyright (C) 1996-2003 Ian Piumarta and other authors/contributors
 *     as listed elsewhere in this file.
 *   All rights reserved.
 *   
 *     You are NOT ALLOWED to distribute modified versions of this file
 *     under its original name.  If you want to modify it and then make
 *     your modifications available publicly, rename the file first.
 * 
 *   This file is part of Unix Squeak.
 * 
 *   This file is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *   
 *   You may use and/or distribute this file ONLY as part of Squeak, under
 *   the terms of the Squeak License as described in `LICENSE' in the base of
 *   this distribution, subject to the following additional restrictions:
 * 
 *   1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software.  If you use this software
 *      in a product, an acknowledgment to the original author(s) (and any
 *      other contributors mentioned herein) in the product documentation
 *      would be appreciated but is not required.
 * 
 *   2. You must not distribute (or make publicly available by any
 *      means) a modified copy of this file unless you first rename it.
 * 
 *   3. This notice must not be removed or altered in any source distribution.
 * 
 *   Using (or modifying this file for use) in any context other than Squeak
 *   changes these copyright conditions.  Read the file `COPYING' in the
 *   directory `platforms/unix/doc' before proceeding with any such use.
 */

/* Author: Ian Piumarta <ian.piumarta@inria.fr>
 *
 * Last edited: 2003-11-23 13:23:43 by piumarta on emilia.local
 */

#include "sq.h"
#include "aio.h"
#include "sqUnixCharConv.h"
#include "debug.h"

#ifdef ioMSecs
# undef ioMSecs
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

#if defined(__alpha__)
# include <sys/sysinfo.h>
# include <sys/proc.h>
#endif

#undef	DEBUG_MODULES

#undef	IMAGE_DUMP				/* define to enable SIGHUP and SIGQUIT handling */

#define IMAGE_NAME_SIZE MAXPATHLEN

#define DefaultHeapSize		  20	     	/* megabytes BEYOND actual image size */
#define DefaultMmapSize		1024     	/* megabytes of virtual memory */

       char  *documentName= 0;			/* name if launced from document */
       char   shortImageName[MAXPATHLEN+1];	/* image name */
       char   imageName[MAXPATHLEN+1];		/* full path to image */
static char   vmName[MAXPATHLEN+1];		/* full path to vm */
       char   vmPath[MAXPATHLEN+1];		/* full path to image directory */
       char  *vmLibDir= VM_LIBDIR;		/* full path to lib directory */

       int    argCnt=		0;	/* global copies for access from plugins */
       char **argVec=		0;
       char **envVec=		0;

static int    vmArgCnt=		0;	/* for getAttributeIntoLength() */
static char **vmArgVec=		0;
static int    squeakArgCnt=	0;
static char **squeakArgVec=	0;

static int    extraMemory=	0;
       int    useMmap=		DefaultMmapSize * 1024 * 1024;

static int    useItimer=	1;	/* 0 to disable itimer-based clock */
       int    noEvents=		0;	/* 1 to disable new event handling */
       int    noSoundMixer=	0;	/* 1 to disable writing sound mixer levels */
       char  *squeakPlugins=	0;	/* plugin path */
       int    useJit=		0;	/* use default */
       int    jitProcs=		0;	/* use default */
       int    jitMaxPIC=	0;	/* use default */
       int    withSpy=		0;

       int    uxDropFileCount=	0;	/* number of dropped items	*/
       char **uxDropFileNames=	0;	/* dropped filenames		*/

       int    textEncodingUTF8= 0;	/* 1 if copy from external selection uses UTF8 */

#if defined(IMAGE_DUMP)
static int    dumpImageFile=	0;	/* 1 after SIGHUP received */
#endif

#if defined(DARWIN)
int inModalLoop= 0;
#endif

int sqIgnorePluginErrors	= 0;
int runInterpreter		= 1;

#include "SqDisplay.h"
#include "SqSound.h"

struct SqDisplay *dpy= 0;
struct SqSound   *snd= 0;


/*** timer support ***/


#define	LOW_RES_TICK_MSECS	20	/* 1/50 second resolution */

static unsigned int   lowResMSecs= 0;
static struct timeval startUpTime;

static void sigalrm(int signum)
{
  lowResMSecs+= LOW_RES_TICK_MSECS;
}

static void initTimers(void)
{
  /* set up the micro/millisecond clock */
  gettimeofday(&startUpTime, 0);
  if (useItimer)
    {
      /* set up the low-res (50th second) millisecond clock */
      /* WARNING: all system calls must check for EINTR!!! */
      {
	struct sigaction sa;
	sigset_t ss1, ss2;
	sigemptyset(&ss1);
	sigprocmask(SIG_BLOCK, &ss1, &ss2);
	sa.sa_handler= sigalrm;
	sa.sa_mask= ss2;
#      ifdef SA_RESTART	/* we're probably on Linux */
	sa.sa_flags= SA_RESTART;
#      else
	sa.sa_flags= 0;	/* assume we already have BSD behaviour */
#      endif
#      ifdef __linux__
	sa.sa_restorer= 0;
#      endif
	sigaction(SIGALRM, &sa, 0);
      }
      {
	struct itimerval iv;
	iv.it_interval.tv_sec= 0;
	iv.it_interval.tv_usec= LOW_RES_TICK_MSECS * 1000;
	iv.it_value= iv.it_interval;
	setitimer(ITIMER_REAL, &iv, 0);
      }
    }
}

int ioLowResMSecs(void)
{
  return (useItimer)
    ? lowResMSecs
    : ioMSecs();
}

int ioMSecs(void)
{
  struct timeval now;
  gettimeofday(&now, 0);
  if ((now.tv_usec-= startUpTime.tv_usec) < 0)
    {
      now.tv_usec+= 1000000;
      now.tv_sec-= 1;
    }
  now.tv_sec-= startUpTime.tv_sec;
  return lowResMSecs= (now.tv_usec / 1000 + now.tv_sec * 1000);
}

int ioMicroMSecs(void)
{
  /* return the highest available resolution of the millisecond clock */
  return ioMSecs();	/* this already to the nearest millisecond */
}

time_t convertToSqueakTime(time_t unixTime)
{
#ifdef HAVE_TM_GMTOFF
  unixTime+= localtime(&unixTime)->tm_gmtoff;
#else
# ifdef HAVE_TIMEZONE
  unixTime+= ((daylight) * 60*60) - timezone;
# else
#  error: cannot determine timezone correction
# endif
#endif
  /* Squeak epoch is Jan 1, 1901.  Unix epoch is Jan 1, 1970: 17 leap years
     and 52 non-leap years later than Squeak. */
  return unixTime + ((52*365UL + 17*366UL) * 24*60*60UL);
}

/* returns the local wall clock time */
int ioSeconds(void)
{
  return convertToSqueakTime(time(0));
}


/*** VM & Image File Naming ***/


/* copy src filename to target, if src is not an absolute filename,
 * prepend the cwd to make target absolute
  */
static void pathCopyAbs(char *target, const char *src, size_t targetSize)
{
  if (src[0] == '/')
    strcpy(target, src);
  else
    {
      getcwd(target, targetSize);
      strcat(target, "/");
      strcat(target, src);
    }
}


static void recordFullPathForVmName(const char *localVmName)
{
#if defined(__linux__)
  char	 name[MAXPATHLEN+1];
  int    len;

  if ((len= readlink("/proc/self/exe", name, sizeof(name))) > 0)
    {
      struct stat st;
      name[len]= '\0';
      if (!stat(name, &st))
	localVmName= name;
    }
#endif

  /* get canonical path to vm */
  if (realpath(localVmName, vmPath) == 0)
    pathCopyAbs(vmPath, localVmName, sizeof(vmPath));

  /* truncate vmPath to dirname */
  {
    int i= 0;
    for (i= strlen(vmPath); i >= 0; i--)
      if ('/' == vmPath[i])
	{
	  vmPath[i+1]= '\0';
	  break;
	}
  }
}

static void recordFullPathForImageName(const char *localImageName)
{
  struct stat s;
  /* get canonical path to image */
  if ((stat(localImageName, &s) == -1) || (realpath(localImageName, imageName) == 0))
    pathCopyAbs(imageName, localImageName, sizeof(imageName));
}

/* vm access */

int imageNameSize(void)
{
  return strlen(imageName);
}

int imageNameGetLength(int sqImageNameIndex, int length)
{
  char *sqImageName= (char *)sqImageNameIndex;
  int count, i;

  count= strlen(imageName);
  count= (length < count) ? length : count;

  /* copy the file name into the Squeak string */
  for (i= 0; i < count; i++)
    sqImageName[i]= imageName[i];

  return count;
}


int imageNamePutLength(int sqImageNameIndex, int length)
{
  char *sqImageName= (char *)sqImageNameIndex;
  int count, i;

  count= (IMAGE_NAME_SIZE < length) ? IMAGE_NAME_SIZE : length;

  /* copy the file name into a null-terminated C string */
  for (i= 0; i < count; i++)
    imageName[i]= sqImageName[i];
  imageName[count]= 0;

  dpy->winSetName(imageName);

  return count;
}


/*** VM Home Directory Path ***/


int vmPathSize(void)
{
  return strlen(vmPath);
}

int vmPathGetLength(int sqVMPathIndex, int length)
{
  char *stVMPath= (char *)sqVMPathIndex;
  int count, i;

  count= strlen(vmPath);
  count= (length < count) ? length : count;

  /* copy the file name into the Squeak string */
  for (i= 0; i < count; i++)
    stVMPath[i]= vmPath[i];

  return count;
}


/*** Profiling ***/


int clearProfile(void) { return 0; }
int dumpProfile(void) { return 0; }
int startProfiling(void) { return 0; }
int stopProfiling(void) { return 0; }


/*** power management ***/


int ioDisablePowerManager(int disableIfNonZero)
{
  return true;
}


/*** Access to system attributes and command-line arguments ***/


/* OS_TYPE may be set in configure.in and passed via the Makefile */

#ifndef OS_TYPE
# ifdef UNIX
#   define OS_TYPE "unix"
# else
#  define OS_TYPE "unknown"
# endif
#endif

static char *getAttribute(int id)
{
  if (id < 0) {
    /* VM argument */
    if (-id  < vmArgCnt)
      return vmArgVec[-id];
  } else switch (id) {
    case 0:
      return vmName[0] ? vmName : vmArgVec[0];
    case 1:
      return imageName;
    case 1001:
      /* OS type: "unix", "win32", "mac", ... */
      return OS_TYPE;
    case 1002:
      /* OS name: "solaris2.5" on unix, "win95" on win32, ... */
      return VM_HOST_OS;
    case 1003:
      /* processor architecture: "68k", "x86", "PowerPC", ...  */
      return VM_HOST_CPU;
    case 1004:
      /* Interpreter version string */
      return  (char *)interpreterVersion;
    case 1005:
      /* window system name */
      return  dpy->winSystemName();
    default:
      if ((id-2) < squeakArgCnt)
	return squeakArgVec[id-2];
  }
  success(false);
  return "";
}

int attributeSize(int id)
{
  return strlen(getAttribute(id));
}

int getAttributeIntoLength(int id, int byteArrayIndex, int length)
{
  if (length > 0)
    strncpy((char *)byteArrayIndex, getAttribute(id), length);
  return 0;
}


/*** event handling ***/


int inputEventSemaIndex= 0;


/* set asynchronous input event semaphore  */

int ioSetInputSemaphore(int semaIndex)
{
  if ((semaIndex == 0) || (noEvents == 1))
    success(false);
  else
    inputEventSemaIndex= semaIndex;
  return true;
}


/*** display functions ***/

int ioFormPrint(int bitsAddr, int width, int height, int depth, double hScale, double vScale, int landscapeFlag)
{
  return dpy->ioFormPrint(bitsAddr, width, height, depth, hScale, vScale, landscapeFlag);
}

int ioRelinquishProcessorForMicroseconds(int us)
{
  int nwt= getNextWakeupTick();
  int now= (ioMSecs() & 0x1fffffff);
  int ms=  0;
  if (nwt <= now)
    ms= (nwt ? 0 : (1000/60));
  else
    ms= nwt - now;
  if (ms < (1000/60))		/* < 1 timeslice? */
    {
#    if defined(__MACH__)	/* can sleep with 1ms resolution */
      struct timespec rqtp= { 0, ms * 1000*1000 };
      struct timespec rmtp;
      while ((nanosleep(&rqtp, &rmtp) < 0) && (errno == EINTR))
	rqtp= rmtp;
#    endif
      ms= 0;			/* poll but don't block */
    }
  dpy->ioRelinquishProcessorForMicroseconds(ms*1000);
  setInterruptCheckCounter(0);
  return 0;
}

int ioBeep(void)				 { return dpy->ioBeep(); }

#if defined(IMAGE_DUMP)

static void emergencyDump(int quit)
{
  extern int  preSnapshot(void);
  extern int  postSnapshot(void);
  extern void writeImageFile(int);
  char savedName[MAXPATHLEN];
  char baseName[MAXPATHLEN];
  char *term;
  int  dataSize, i;
  strncpy(savedName, imageName, MAXPATHLEN);
  strncpy(baseName, imageName, MAXPATHLEN);
  if ((term= strrchr(baseName, '.')))
    *term= '\0';
  for (i= 0; ++i;)
    {
      struct stat sb;
      sprintf(imageName, "%s-emergency-dump-%d.image", baseName, i);
      if (stat(imageName, &sb))
	break;
    }
  dataSize= preSnapshot();
  writeImageFile(dataSize);

  fprintf(stderr, "\n");
  printCallStack();
  fprintf(stderr, "\nTo recover valuable content from this image:\n");
  fprintf(stderr, "    squeak %s\n", imageName);
  fprintf(stderr, "and then evaluate\n");
  fprintf(stderr, "    Smalltalk processStartUpList: true\n");
  fprintf(stderr, "in a workspace.  DESTROY the dumped image after recovering content!");

  if (quit) abort();
  strncpy(imageName, savedName, sizeof(imageName));
}

#endif

int ioProcessEvents(void)
{
#if defined(IMAGE_DUMP)
  if (dumpImageFile)
    {
      emergencyDump(0);
      dumpImageFile= 0;
    }
#endif
  return dpy->ioProcessEvents();
}

int ioScreenDepth(void)				 { return dpy->ioScreenDepth(); }
int ioScreenSize(void)				 { return dpy->ioScreenSize(); }

int ioSetCursorWithMask(int cursorBitsIndex, int cursorMaskIndex, int offsetX, int offsetY)
{
  return dpy->ioSetCursorWithMask(cursorBitsIndex, cursorMaskIndex, offsetX, offsetY);
}

int ioSetCursor(int cursorBitsIndex, int offsetX, int offsetY)
{
  return ioSetCursorWithMask(cursorBitsIndex, 0, offsetX, offsetY);
}

int ioSetFullScreen(int fullScreen) { return dpy->ioSetFullScreen(fullScreen); }
int ioForceDisplayUpdate(void)	    { return dpy->ioForceDisplayUpdate(); }

int ioShowDisplay(int dispBitsIndex, int width, int height, int depth, int l, int r, int t, int b)
{
  return dpy->ioShowDisplay(dispBitsIndex, width, height, depth, l, r, t, b);
}

int ioHasDisplayDepth(int i) { return dpy->ioHasDisplayDepth(i); }

int ioSetDisplayMode(int width, int height, int depth, int fullscreenFlag)
{
  return dpy->ioSetDisplayMode(width, height, depth, fullscreenFlag);
}

int clipboardSize(void)
{
  return dpy->clipboardSize();
}

int clipboardWriteFromAt(int count, int byteArrayIndex, int startIndex)
{
  return dpy->clipboardWriteFromAt(count, byteArrayIndex, startIndex);
}

int clipboardReadIntoAt(int count, int byteArrayIndex, int startIndex)
{
  return dpy->clipboardReadIntoAt(count, byteArrayIndex, startIndex);
}

int   ioGetButtonState(void)			{ return dpy->ioGetButtonState(); }
int   ioPeekKeystroke(void)			{ return dpy->ioPeekKeystroke(); }
int   ioGetKeystroke(void)			{ return dpy->ioGetKeystroke(); }
int   ioGetNextEvent(sqInputEvent *evt)		{ return dpy->ioGetNextEvent(evt); }
int   ioMousePoint(void)			{ return dpy->ioMousePoint(); }


/*** OpenGL ***/

int verboseLevel= 1;

struct SqDisplay *ioGetDisplayModule(void)	{ return dpy; }

void *ioGetDisplay(void)			{ return dpy->ioGetDisplay(); }
void *ioGetWindow(void)				{ return dpy->ioGetWindow(); }
int   ioGLinitialise(void)			{ return dpy->ioGLinitialise(); }

int   ioGLcreateRenderer(glRenderer *r, int x, int y, int w, int h, int flags)
{
  return dpy->ioGLcreateRenderer(r, x, y, w, h, flags);
}

int   ioGLmakeCurrentRenderer(glRenderer *r)	{ return dpy->ioGLmakeCurrentRenderer(r); }
void  ioGLdestroyRenderer(glRenderer *r)	{	 dpy->ioGLdestroyRenderer(r); }
void  ioGLswapBuffers(glRenderer *r)		{	 dpy->ioGLswapBuffers(r); }

void  ioGLsetBufferRect(glRenderer *r, int x, int y, int w, int h)
{
  dpy->ioGLsetBufferRect(r, x, y, w, h);
}


int   primitivePluginBrowserReady(void)		{ return dpy->primitivePluginBrowserReady(); }
int   primitivePluginRequestURLStream(void)	{ return dpy->primitivePluginRequestURLStream(); }
int   primitivePluginRequestURL(void)		{ return dpy->primitivePluginRequestURL(); }
int   primitivePluginPostURL(void)		{ return dpy->primitivePluginPostURL(); }
int   primitivePluginRequestFileHandle(void)	{ return dpy->primitivePluginRequestFileHandle(); }
int   primitivePluginDestroyRequest(void)	{ return dpy->primitivePluginDestroyRequest(); }
int   primitivePluginRequestState(void)		{ return dpy->primitivePluginRequestState(); }


/*** errors ***/


static void outOfMemory(void)
{
  fprintf(stderr, "out of memory\n");
  exit(1);
}


static void sigsegv(int ignore)
{
  /* error("Segmentation fault"); */
  static int printingStack= 0;

  printf("\nSegmentation fault\n\n");
  if (!printingStack)
    {
      printingStack= 1;
      printCallStack();
    }
  abort();
}


#if defined(IMAGE_DUMP)

static void sighup(int ignore)
{
  dumpImageFile= 1;
}

static void sigquit(int ignore)
{
  emergencyDump(1);
}

#endif


/*** modules ***/


#include "SqModule.h"

struct SqModule *displayModule=	0;
struct SqModule *soundModule=	0;
struct SqModule *modules= 0;

#define modulesDo(M)	for (M= modules;  M;  M= M->next)

struct moduleDescription
{
  struct SqModule **addr;
  char		   *type;
  char		   *name;
};

static struct moduleDescription moduleDescriptions[]=
{
  { &displayModule, "display", "X11"    },	/*** NO DEFAULT ***/
  { &displayModule, "display", "fbdev"  },	/*** NO DEFAULT ***/
  { &displayModule, "display", "null"   },	/*** NO DEFAULT ***/
  { &soundModule,   "sound",   "NAS"    },	/*** NO DEFAULT ***/
  { &displayModule, "display", "Quartz" },
  { &soundModule,   "sound",   "MacOSX" },
  { &soundModule,   "sound",   "Sun"    },
  { &soundModule,   "sound",   "OSS"    },
  { &soundModule,   "sound",   "null"   },
  { 0,              0,         0	}
};

static struct moduleDescription *defaultModules= moduleDescriptions + 4;


struct SqModule *queryLoadModule(char *type, char *name, int query)
{
  char modName[MAXPATHLEN], itfName[32];
  struct SqModule *module= 0;
  int itf= 0;
  sprintf(modName, "vm-%s-%s", type, name);
#ifdef DEBUG_MODULES
  printf("looking for module %s\n", modName);
#endif
  modulesDo (module)
    if (!strcmp(module->name, modName))
      return module;
  sprintf(itfName, "%s_%s", type, name);
  itf= ioFindExternalFunctionIn(itfName, ioLoadModule(0));
  if (!itf)
    {
      int handle= ioLoadModule(modName);
      if (handle)
	itf= ioFindExternalFunctionIn(itfName, handle);
      else
	if (!query)
	  {
	    fprintf(stderr, "could not find module %s\n", modName);
	    return 0;
	  }
    }
  if (itf)
    {
      module= (struct SqModule *)itf;
      if (SqModuleVersion != module->version)
	{
	  fprintf(stderr, "module %s version %x does not have required version %x\n",
		  modName, module->version, SqModuleVersion);
	  abort();
	}
      module->next= modules;
      modules= module;
      module->name= strdup(modName);
      module->parseEnvironment();
      return module;
    }
  if (!query)
    fprintf(stderr, "could not find interface %s in module %s\n", itfName, modName);
  return 0;
}


struct SqModule *queryModule(char *type, char *name)
{
  return queryLoadModule(type, name, 1);
}

struct SqModule *loadModule(char *type, char *name)
{
  return queryLoadModule(type, name, 0);
}

struct SqModule *requireModule(char *type, char *name)
{
  struct SqModule *m= loadModule(type, name);
  if (!m) abort();
  return m;
}


static char *canonicalModuleName(char *name)
{
  struct moduleDescription *md;

  for (md= moduleDescriptions;  md->addr;  ++md)
    if (!strcasecmp(name, md->name))
      return md->name;
  if (!strcasecmp(name, "none"))
    return "null";
  return name;
}


static void requireModuleNamed(char *type)	/*** NOTE: MODIFIES THE ARGUMENT! ***/
{
  if      (!strncmp(type,  "vm-", 3)) type+= 3;
  else if (!strncmp(type, "-vm-", 4)) type+= 4;
  /* we would like to use strsep() here, but neither OSF1 nor Solaris have it */
  {
    char *name= type;

    while (*name && ('-' != *name) && ('=' != *name))
      ++name;
    if (*name) *name++= '\0';

#  if defined(DEBUG_MODULES)
    printf("type %s name %s\n", type, name);
#  endif
    {
      struct SqModule **addr= 0, *module= 0;

      if      (!strcmp(type, "display")) addr= &displayModule;
      else if (!strcmp(type, "sound"))   addr= &soundModule;
      /* let unknown types through to the following to generate a more informative diagnostic */
      name= canonicalModuleName(name);
      module= requireModule(type, name);
      if (!addr)
	{
	  fprintf(stderr, "this cannot happen\n");
	  abort();
	}
      *addr= module;
    }
  }
}

static void requireModulesNamed(char *specs)
{
  char *vec= strdup(specs);
  char *pos= vec;

  while (*pos)
    {
      char *end= pos;
      while (*end && (' ' <= *end) && (',' != *end))
	++end;
      if (*end) *end++= '\0';
      requireModuleNamed(pos);
      pos= end;
    }
  free(vec);
}


static void checkModuleVersion(struct SqModule *module, int required, int actual)
{
  if (required != actual)
    {
      fprintf(stderr, "module %s interface version %x does not have required version %x\n",
	      module->name, actual, required);
      abort();
    }
}


static void loadImplicit(struct SqModule **addr, char *evar, char *type, char *name)
{
  if ((!*addr) && getenv(evar) && !(*addr= queryModule(type, name)))
    {
      fprintf(stderr, "could not find %s driver vm-%s-%s; either:\n", type, type, name);
      fprintf(stderr, "  - check that %s/vm-%s-%s.so exists, or\n", vmLibDir, type, name);
      fprintf(stderr, "  - use the '-plugins <path>' option to tell me where it is, or\n");
      fprintf(stderr, "  - remove %s from your environment.\n", evar);
      abort();
    }
}

static void loadModules(void)
{
  loadImplicit(&displayModule, "DISPLAY",     "display", "X11");
  loadImplicit(&soundModule,   "AUDIOSERVER", "sound",   "NAS");
  {
    struct moduleDescription *md;

    for (md= defaultModules;  md->addr;  ++md)
      if (!*md->addr)
	if ((*md->addr= queryModule(md->type, md->name)))
#	 if defined(DEBUG_MODULES)
	  fprintf(stderr, "squeak: %s driver defaulting to vm-%s-%s\n", md->type, md->type, md->name)
#	 endif
	    ;
  }

  if (!displayModule)
    {
      fprintf(stderr, "squeak: could not find any display driver\n");
      abort();
    }
  if (!soundModule)
    {
      fprintf(stderr, "squeak: could not find any sound driver\n");
      abort();
    }

  dpy= (struct SqDisplay *)displayModule->makeInterface();
  snd= (struct SqSound   *)soundModule  ->makeInterface();

  checkModuleVersion(displayModule, SqDisplayVersion, dpy->version);
  checkModuleVersion(soundModule,   SqSoundVersion,   snd->version);
}

/* built-in main vm module */


static int strtobkm(const char *str)
{
  char *suffix;
  int value= strtol(str, &suffix, 10);
  switch (*suffix)
    {
    case 'k': case 'K':
      value*= 1024;
      break;
    case 'm': case 'M':
      value*= 1024*1024;
      break;
    }
  return value;
}

static int jitArgs(char *str)
{
  char *endptr= str;
  int  args= 3;				/* default JIT mode = fast compiler */
  
  if (*str == '\0') return args;
  if (*str != ',')
    args= strtol(str, &endptr, 10);	/* mode */
  while (*endptr == ',')		/* [,debugFlag]* */
    args|= (1 << (strtol(endptr + 1, &endptr, 10) + 8));
  return args;
}


static void vm_parseEnvironment(void)
{
  char *ev= 0;

  if (documentName)
    strcpy(shortImageName, documentName);
  else if ((ev= getenv("SQUEAK_IMAGE")))
    strcpy(shortImageName, ev);
  else
    strcpy(shortImageName, "squeak.image");

  if ((ev= getenv("SQUEAK_MEMORY")))	extraMemory= strtobkm(ev);
  if ((ev= getenv("SQUEAK_MMAP")))	useMmap= strtobkm(ev);
  if ((ev= getenv("SQUEAK_PLUGINS")))	squeakPlugins= strdup(ev);
  if ((ev= getenv("SQUEAK_NOEVENTS")))	noEvents= 1;
  if ((ev= getenv("SQUEAK_NOTIMER")))	useItimer= 0;
  if ((ev= getenv("SQUEAK_JIT")))	useJit= jitArgs(ev);
  if ((ev= getenv("SQUEAK_PROCS")))	jitProcs= atoi(ev);
  if ((ev= getenv("SQUEAK_MAXPIC")))	jitMaxPIC= atoi(ev);
  if ((ev= getenv("SQUEAK_ENCODING")))	setEncoding(&sqTextEncoding, ev);
  if ((ev= getenv("SQUEAK_PATHENC")))	setEncoding(&uxPathEncoding, ev);
  if ((ev= getenv("SQUEAK_TEXTENC")))	setEncoding(&uxTextEncoding, ev);

  if ((ev= getenv("SQUEAK_VM")))	requireModulesNamed(ev);
}


static void usage(void);
static void versionInfo(void);


static int parseModuleArgument(int argc, char **argv, struct SqModule **addr, char *type, char *name)
{
  if (*addr)
    {
      fprintf(stderr, "option '%s' conflicts with previously-loaded module '%s'\n", *argv, (*addr)->name);
      exit(1);
    }
  *addr= requireModule(type, name);
  return (*addr)->parseArgument(argc, argv);
}


static int vm_parseArgument(int argc, char **argv)
{
  /* deal with arguments that implicitly load modules */

  if (!strncmp(argv[0], "-psn_", 5))
    {
      displayModule= requireModule("display", "Quartz");
      return displayModule->parseArgument(argc, argv);
    }

  if ((!strcmp(argv[0], "-vm")) && (argc > 1))
    {
      requireModulesNamed(argv[1]);
      return 2;
    }

  if (!strncmp(argv[0], "-vm-", 4))
    {
      requireModulesNamed(argv[0] + 4);
      return 1;
    }

  /* legacy compatibility */		/*** XXX to be removed at some time ***/

# define moduleArg(arg, type, name)						\
    if (!strcmp(argv[0], arg))							\
      return parseModuleArgument(argc, argv, &type##Module, #type, name);

  moduleArg("-nodisplay",	display, "null");
  moduleArg("-display",		display, "X11");
  moduleArg("-headless",	display, "X11");
  moduleArg("-quartz",		display, "Quartz");
  moduleArg("-nosound",		sound,   "null");

# undef moduleArg

  /* vm arguments */

  if      (!strcmp(argv[0], "-help"))		{ usage();				return 1; }
  else if (!strcmp(argv[0], "-noevents"))	{ noEvents	= 1;			return 1; }
  else if (!strcmp(argv[0], "-nomixer"))	{ noSoundMixer	= 1;			return 1; }
  else if (!strcmp(argv[0], "-notimer"))	{ useItimer	= 0;			return 1; }
  else if (!strncmp(argv[0],"-jit", 4))		{ useJit	= jitArgs(argv[0]+4);	return 1; }
  else if (!strcmp(argv[0], "-nojit"))		{ useJit	= 0;			return 1; }
  else if (!strcmp(argv[0], "-spy"))		{ withSpy	= 1;			return 1; }
  else if (!strcmp(argv[0], "-version"))	{ versionInfo();			return 1; }
  /* option requires an argument */
  else if (argc > 1)
    {
      if      (!strcmp(argv[0], "-procs"))	{ jitProcs=	 atoi(argv[1]);		 return 2; }
      else if (!strcmp(argv[0], "-maxpic"))	{ jitMaxPIC=	 atoi(argv[1]);		 return 2; }
      else if (!strcmp(argv[0], "-memory"))	{ extraMemory=	 strtobkm(argv[1]);	 return 2; }
      else if (!strcmp(argv[0], "-mmap"))	{ useMmap=	 strtobkm(argv[1]);	 return 2; }
      else if (!strcmp(argv[0], "-plugins"))	{ squeakPlugins= strdup(argv[1]);	 return 2; }
      else if (!strcmp(argv[0], "-encoding"))	{ setEncoding(&sqTextEncoding, argv[1]); return 2; }
      else if (!strcmp(argv[0], "-pathenc"))	{ setEncoding(&uxPathEncoding, argv[1]); return 2; }
      else if (!strcmp(argv[0], "-textenc"))
	{
	  char *buf= (char *)malloc(strlen(argv[1]) + 1);
	  int len, i;
	  strcpy(buf, argv[1]);
	  len= strlen(buf);
	  for (i= 0;  i < len;  ++i)
	    buf[i]= toupper(buf[i]);
	  if ((!strcmp(buf, "UTF8")) || (!strcmp(buf, "UTF-8")))
	    textEncodingUTF8= 1;
	  else
	    setEncoding(&uxTextEncoding, buf);
	  free(buf);
	  return 2;
	}
    }
  return 0;	/* option not recognised */
}


static void vm_printUsage(void)
{
  printf("\nCommon <option>s:\n");
  printf("  -encoding <enc>       set the internal character encoding (default: MacRoman)\n");
  printf("  -help                 print this help message, then exit\n");
/*printf("  -jit                  enable the dynamic compiler (if available)\n");*/
  printf("  -memory <size>[mk]    use fixed heap size (added to image size)\n");
  printf("  -mmap <size>[mk]      limit dynamic heap size (default: %dm)\n", DefaultMmapSize);
  printf("  -noevents             disable event-driven input support\n");
  printf("  -notimer              disable interval timer for low-res clock \n");
  printf("  -pathenc <enc>        set encoding for pathnames (default: UTF-8)\n");
  printf("  -plugins <path>       specify alternative plugin location (see manpage)\n");
  printf("  -textenc <enc>        set encoding for external text (default: UTF-8)\n");
  printf("  -version              print version information, then exit\n");
  printf("  -vm-<sys>-<dev>       use the <dev> driver for <sys> (see below)\n");
#if 1
  printf("Deprecated:\n");
  printf("  -display <dpy>        quivalent to '-vm-display-X11 -display <dpy>'\n");
  printf("  -headless             quivalent to '-vm-display-X11 -headless'\n");
  printf("  -nodisplay            quivalent to '-vm-display-null'\n");
  printf("  -nomixer              disable modification of mixer settings\n");
  printf("  -nosound              quivalent to '-vm-sound-null'\n");
  printf("  -quartz               quivalent to '-vm-display-Quartz'\n");
#endif
}


static void vm_printUsageNotes(void)
{
  printf("  If `-memory' is not specified then the heap will grow dynamically.\n");
  printf("  <argument>s are ignored, but are processed by the Squeak image.\n");
  printf("  The first <argument> normally names a Squeak `script' to execute.\n");
  printf("  Precede <arguments> by `--' to use default image.\n");
}


static void *vm_makeInterface(void)
{
  fprintf(stderr, "this cannot happen\n");
  abort();
}


SqModuleDefine(vm, Module);


/*** options processing ***/


static void usage(void)
{
  struct SqModule *m= 0;
  printf("Usage: %s [<option>...] [<imageName> [<argument>...]]\n", argVec[0]);
  printf("       %s [<option>...] -- [<argument>...]\n", argVec[0]);
  sqIgnorePluginErrors= 1;
  {
    struct moduleDescription *md;
    for (md= moduleDescriptions;  md->addr;  ++md)
      queryModule(md->type, md->name);
  }
  modulesDo(m)
    m->printUsage();
  if (useJit)
    {
      printf("\njit <option>s:\n");
      printf("  -align <n>            align functions at <n>-byte boundaries\n");
      printf("  -jit<o>[,<d>...]      set optimisation [and debug] levels\n");
      printf("  -maxpic <n>           set maximum PIC size to <n> entries\n");
      printf("  -procs <n>            allow <n> concurrent volatile processes\n");
      printf("  -spy                  enable the system spy\n");
    }
  printf("\nNotes:\n");
  printf("  <imageName> defaults to `squeak.image'.\n");
  modulesDo(m)
    m->printUsageNotes();
  printf("\nAvailable drivers:\n");
  for (m= modules;  m->next;  m= m->next)
    printf("  %s\n", m->name);
  exit(1);
}


char *getVersionInfo(int verbose)
{
  extern int   vm_serial;
  extern char *vm_date, *cc_version, *ux_version;
  char *info= (char *)malloc(4096);
  info[0]= '\0';

  if (verbose)
    sprintf(info+strlen(info), "Squeak VM version: ");
  sprintf(info+strlen(info), "%s #%d", VM_VERSION, vm_serial);
#if defined(USE_XSHM)
  sprintf(info+strlen(info), " XShm");
#endif
  sprintf(info+strlen(info), " %s %s\n", vm_date, cc_version);
  if (verbose)
    sprintf(info+strlen(info), "Built from: ");
  sprintf(info+strlen(info), "%s\n", interpreterVersion);
  if (verbose)
    sprintf(info+strlen(info), "Build host: ");
  sprintf(info+strlen(info), "%s\n", ux_version);
  sprintf(info+strlen(info), "default plugin location: %s/*.so\n", vmLibDir);
  return info;
}


static void versionInfo(void)
{
  printf("%s", getVersionInfo(0));
  exit(0);
}


static void parseArguments(int argc, char **argv)
{
# define skipArg()	(--argc, argv++)
# define saveArg()	(vmArgVec[vmArgCnt++]= *skipArg())

  saveArg();	/* vm name */

  while ((argc > 0) && (**argv == '-'))	/* more options to parse */
    {
      struct SqModule *m= 0;
      int n= 0;
      if (!strcmp(*argv, "--"))		/* escape from option processing */
	break;
      modulesDo (m)
	if ((n= m->parseArgument(argc, argv)))
	  break;
#    ifdef DEBUG_IMAGE
      printf("parseArgument n = %d\n", n);
#    endif
      if (n == 0)			/* option not recognised */
	{
	  fprintf(stderr, "unknown option: %s\n", argv[0]);
	  usage();
	}
      while (n--)
	saveArg();
    }
  if (!argc)
    return;
  if (!strcmp(*argv, "--"))
    skipArg();
  else					/* image name */
    {
      if (!documentName)
	strcpy(shortImageName, saveArg());
      if (!strstr(shortImageName, ".image"))
	strcat(shortImageName, ".image");
    }
  /* save remaining arguments as Squeak arguments */
  while (argc > 0)
    squeakArgVec[squeakArgCnt++]= *skipArg();

# undef saveArg
# undef skipArg
}


/*** main ***/


static void imageNotFound(char *imageName)
{
  /* image file is not found */
  fprintf(stderr,
	  "Could not open the Squeak image file `%s'.\n"
	  "\n"
	  "There are three ways to open a Squeak image file.  You can:\n"
	  "  1. Put copies of the default image and changes files in this directory.\n"
	  "  2. Put the name of the image file on the command line when you\n"
	  "     run squeak (use the `-help' option for more information).\n"
	  "  3. Set the environment variable SQUEAK_IMAGE to the name of the image\n"
	  "     that you want to use by default.\n"
	  "\n"
	  "For more information, type: `man squeak' (without the quote characters).\n",
	  imageName);
  exit(1);
}


void imgInit(void)
{
  /* read the image file and allocate memory for Squeak heap */
  for (;;)
    {
      FILE *f= 0;
      struct stat sb;
      char imageName[MAXPATHLEN];
      sqFilenameFromStringOpen(imageName, (int)shortImageName, strlen(shortImageName));
      if ((  (-1 == stat(imageName, &sb)))
	  || ( 0 == (f= fopen(imageName, "r"))))
	{
	  if (dpy->winImageFind(shortImageName, sizeof(shortImageName)))
	    continue;
	  dpy->winImageNotFound();
	  imageNotFound(shortImageName);
	}
      {
	int fd= open(imageName, O_RDONLY);
	if (fd < 0) abort();
#      ifdef DEBUG_IMAGE
	printf("fstat(%d) => %d\n", fd, fstat(fd, &sb));
#      endif
      }
      recordFullPathForImageName(shortImageName); /* full image path */
      if (extraMemory)
	useMmap= 0;
      else
	extraMemory= DefaultHeapSize * 1024 *1024;
#    ifdef DEBUG_IMAGE
      printf("image size %d + heap size %d (useMmap = %d)\n", (int)sb.st_size, extraMemory, useMmap);
#    endif
      extraMemory += (int)sb.st_size;
      readImageFromFileHeapSize(f, extraMemory);
      sqImageFileClose(f);
      break;
    }
}


int main(int argc, char **argv, char **envp)
{
  /* Make parameters global for access from plugins */

  argCnt= argc;
  argVec= argv;
  envVec= envp;

#ifdef DEBUG_IMAGE
  {
    int i= argc;
    char **p= argv;
    while (i--)
      printf("arg: %s\n", *p++);
  }
#endif

  /* Allocate arrays to store copies of pointers to command line
     arguments.  Used by getAttributeIntoLength(). */

  if ((vmArgVec= calloc(argc + 1, sizeof(char *))) == 0)
    outOfMemory();

  if ((squeakArgVec= calloc(argc + 1, sizeof(char *))) == 0)
    outOfMemory();

  signal(SIGSEGV, sigsegv);

#if defined(__alpha__)
  /* disable printing of unaligned access exceptions */
  {
    int buf[2]= { SSIN_UACPROC, UAC_NOPRINT };
    if (setsysinfo(SSI_NVPAIRS, buf, 1, 0, 0, 0) < 0)
      {
	perror("setsysinfo(UAC_NOPRINT)");
      }
  }
#endif

#if defined(HAVE_TZSET)
  tzset();	/* should _not_ be necessary! */
#endif

  recordFullPathForVmName(argv[0]); /* full vm path */

  sqIgnorePluginErrors= 1;
  if (!modules)
    modules= &vm_Module;
  vm_Module.parseEnvironment();
  parseArguments(argc, argv);
  if ((!dpy) || (!snd))
    loadModules();
  sqIgnorePluginErrors= 0;

#if defined(DEBUG_MODULES)
  printf("displayModule %p %s\n", displayModule, displayModule->name);
  if (soundModule)
    printf("soundModule   %p %s\n", soundModule,   soundModule->name);
#endif

  if (!realpath(argv[0], vmName))
    vmName[0]= 0; /* full VM name */

#ifdef DEBUG_IMAGE
  printf("vmName: %s -> %s\n", argv[0], vmName);
  printf("viName: %s\n", shortImageName);
  printf("documentName: %s\n", documentName);
#endif

  initTimers();
  aioInit();
  dpy->winInit();
  imgInit();
  dpy->winOpen();

#if defined(HAVE_LIBDL)
  if (useJit)
    {
      /* first try to find an internal dynamic compiler... */
      int handle= ioLoadModule(0);
      int comp= ioFindExternalFunctionIn("j_interpret", handle);
      /* ...and if that fails... */
      if (comp == 0)
	{
	  /* ...try to find an external one */
	  handle= ioLoadModule("SqueakCompiler");
	  if (handle != 0)
	    comp= ioFindExternalFunctionIn("j_interpret", handle);
	}
      if (comp)
	{
	  ((void (*)(void))comp)();
	  fprintf(stderr, "handing control back to interpret() -- have a nice day\n");
	}
      else
	printf("could not find j_interpret\n");
      exit(1);
    }
#endif

#if defined(IMAGE_DUMP)
  signal(SIGHUP,  sighup);
  signal(SIGQUIT, sigquit);
#endif

  /* run Squeak */
  if (runInterpreter)
    interpret();

  /* we need these, even if not referenced from main executable */
  (void)sq2uxPath;
  (void)ux2sqPath;
  sqDebugAnchor();
  
  return 0;
}


int ioExit(void)
{
  dpy->winExit();
  exit(0);
}
