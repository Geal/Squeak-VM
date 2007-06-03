/****************************************************************************
*   PROJECT: Squeak port for Win32 (NT / Win95)
*   FILE:    sqWin32Directory.c
*   CONTENT: Directory management
*
*   AUTHOR:  Andreas Raab (ar)
*   ADDRESS: University of Magdeburg, Germany
*   EMAIL:   raab@isg.cs.uni-magdeburg.de
*   RCSID:   $Id$
*
*   NOTES:
*
*****************************************************************************/
#include <windows.h>
#include "sq.h"

extern struct VirtualMachine *interpreterProxy;

#ifndef NO_RCSID
  static char RCSID[]="$Id$";
#endif

/***
	The interface to the directory primitive is path based.
	That is, the client supplies a Squeak string describing
	the path to the directory on every call. To avoid traversing
	this path on every call, a cache is maintained of the last
	path seen.
***/

/*** Constants ***/
#define ENTRY_FOUND     0
#define NO_MORE_ENTRIES 1
#define BAD_PATH        2

/* figure out if a case sensitive duplicate of the given path exists.
   useful for trying to stay in sync with case-sensitive platforms. */
int caseSensitiveFileMode = 0;

int hasCaseSensitiveDuplicate(WCHAR *path) {
  WCHAR *src, *dst, *prev;
  WCHAR findPath[MAX_PATH];
  WIN32_FIND_DATAW findData; /* cached find data */
  HANDLE findHandle = 0; /* cached find handle */

  if(!caseSensitiveFileMode) return 0;

  if(!path) return 0;
  if(*path == 0) return 0;

  /* figure out the root of the path (we can't test it) */
  dst = findPath;
  src = path;
  *dst++ = *src++;
  *dst++ = *src++;
  if(path[0] == '\\' && path[1] == '\\') {
    /* \\server\name */
    while(*src != 0 && *src != '\\') *dst++ = *src++;
  } else if(path[1] != ':' || path[2] != '\\') {
    /* Oops??? What is this??? */
    printf("hasCaseSensitiveDuplicate: Unrecognized path root\n");
    return 0;
  }
  *dst = 0;

  /* from the root, enumerate all the path components and find 
     potential mismatches */
  while(true) {
    /* skip backslashes */
    while(*src != 0 && *src == '\\') src++;
    if(!*src) return 0; /* we're done */
    /* copy next path component into findPath */
    *dst++ = '\\';
    prev = dst;
    while(*src != 0 && *src != '\\') *dst++ = *src++;
    *dst = 0;
    /* now let's go find it */
    findHandle = FindFirstFileW(findPath, &findData);
    /* not finding a path means there is no duplicate */
    if(findHandle == INVALID_HANDLE_VALUE) return 0;
    FindClose(findHandle);
    {
      WCHAR *tmp = findData.cFileName;
      while(*tmp) if(*tmp++ != *prev++) break;
      if(*tmp == *prev) return 1; /* duplicate */
    }
  }
}

typedef union {
  struct {
    DWORD dwLow;
    DWORD dwHigh;
  };
  squeakFileOffsetType offset;
} win32FileOffset;

DWORD convertToSqueakTime(SYSTEMTIME st)
{ DWORD secs;
  DWORD dy;
  static DWORD nDaysPerMonth[14] = { 
    0,  0,  31,  59,  90, 120, 151,
      181, 212, 243, 273, 304, 334, 365 };
  /* Squeak epoch is Jan 1, 1901 */
  dy = st.wYear - 1901; /* compute delta year */
  secs = dy * 365 * 24 * 60 * 60       /* base seconds */
         + (dy >> 2) * 24 * 60 * 60;   /* seconds of leap years */
  /* check if month > 2 and current year is a leap year */
  if(st.wMonth > 2 && (dy & 0x0003) == 0x0003)
    secs += 24 * 60 * 60; /* add one day */
  /* add the days from the beginning of the year */
  secs += (nDaysPerMonth[st.wMonth] + st.wDay - 1) * 24 * 60 * 60;
  /* add the hours, minutes, and seconds */
  secs += st.wSecond + 60*(st.wMinute + 60*st.wHour);
  return secs;
}

int dir_Create(char *pathString, int pathLength)
{
  WCHAR win32Path[MAX_PATH];
  int sz;
  /* convert the file name into a null-terminated C string */
  sz = MultiByteToWideChar(CP_UTF8, 0, pathString, pathLength, NULL, 0);
  if(sz > MAX_PATH) return 0;
  MultiByteToWideChar(CP_UTF8, 0, pathString, pathLength, win32Path, sz);
  win32Path[sz] = 0;
  return CreateDirectoryW(win32Path,NULL);
}

int dir_Delimitor(void)
{
  return '\\';
}

int dir_Lookup(char *pathString, int pathLength, int index,
/* outputs: */ char *name, int *nameLength, int *creationDate, int *modificationDate,
	       int *isDirectory, squeakFileOffsetType *sizeIfFile)
{
  /* Lookup the index-th entry of the directory with the given path, starting
     at the root of the file system. Set the name, name length, creation date,
     creation time, directory flag, and file size (if the entry is a file).
     Return:
		0 	if a entry is found at the given index
		1	if the directory has fewer than index entries
		2	if the given path has bad syntax or does not reach a directory
  */
  static WIN32_FIND_DATAW findData; /* cached find data */
  static HANDLE findHandle = 0; /* cached find handle */
  static int lastIndex = 0; /* cached last index */
  static WCHAR lastString[MAX_PATH+1]; /* cached last path */
  static int lastStringLength = 0; /* cached length of last path */
  WCHAR win32Path[MAX_PATH];
  FILETIME fileTime;
  SYSTEMTIME sysTime;
  int i, sz;

  /* default return values */
  *name             = 0;
  *nameLength       = 0;
  *creationDate     = 0;
  *modificationDate = 0;
  *isDirectory      = false;
  *sizeIfFile       = 0;

  /* check for a dir cache hit (but NEVER on the top level) */
  if(pathLength && 
     lastStringLength == pathLength && 
     lastIndex + 1 == index) {
    for(i=0;i<pathLength; i++) {
      if(lastString[i] != pathString[i])
	break;
    }
    if(i == pathLength) {
      lastIndex = index;
      index = 2;
      goto dirCacheHit;
    }
  }

  if(findHandle) {
    FindClose(findHandle);
    findHandle = NULL;
  }
  lastIndex = index;

#if !defined(_WIN32_WCE)
  /* Like Unix, Windows CE does not have drive letters */
  if(pathLength == 0) { 
    /* we're at the top of the file system --- return possible drives */
    int mask;

    mask = GetLogicalDrives();
    for(i=0;i<26; i++)
      if(mask & (1 << i))
	if(--index == 0) {
	  /* found the drive ! */
          name[0]           = 'A'+i;
          name[1]	          = ':';
          *nameLength       = 2;
          *creationDate     = 0;
          *modificationDate = 0;
          *isDirectory      = true;
          *sizeIfFile       = 0;
          return ENTRY_FOUND;
        }
    return NO_MORE_ENTRIES;
  }
#endif /* !defined(_WIN32_WCE) */

  /* cache the path */
  for(i=0; i < pathLength;i++)
    lastString[i] = pathString[i];
  lastString[pathLength] = 0;
  lastStringLength = pathLength;

  /* convert the path to a win32 string */
  sz = MultiByteToWideChar(CP_UTF8, 0, pathString, pathLength, NULL, 0);
  if(sz > MAX_PATH) return BAD_PATH;
  MultiByteToWideChar(CP_UTF8, 0, pathString, pathLength, win32Path, sz);
  win32Path[sz] = 0;

  if(hasCaseSensitiveDuplicate(win32Path)) {
    lastStringLength = 0;
    return BAD_PATH;
  }
  if(win32Path[sz-1] != '\\') {
    win32Path[sz++] = '\\';
  }
  win32Path[sz++] = '*';
  win32Path[sz] = 0;

  /* and go looking for entries */
  findHandle = FindFirstFileW(win32Path,&findData);
  if(findHandle == INVALID_HANDLE_VALUE) {
    /* Directory could be empty, so we must check for that */
    DWORD dwErr = GetLastError();
    return (dwErr == ERROR_NO_MORE_FILES) ? NO_MORE_ENTRIES : BAD_PATH;
  }
  while(1) {
    /* check for '.' or '..' directories */
    if(findData.cFileName[0] == '.')
      if(findData.cFileName[1] == 0 ||
	 (findData.cFileName[1] == '.' &&
	  findData.cFileName[2] == 0))
	index = index + 1; /* hack us back to the last index */
    if(index <= 1) break;
  dirCacheHit: /* If we come to this label we've got a hit in the dir cache */
    if (!FindNextFileW(findHandle,&findData)) {
      FindClose(findHandle);
      findHandle = NULL;
      return NO_MORE_ENTRIES;
    }
    index = index - 1;
  }

  /* convert to UTF-8 */
  sz = WideCharToMultiByte(CP_UTF8, 0, findData.cFileName, -1, name, MAX_PATH, NULL, NULL);
  *nameLength = sz-1;

  FileTimeToLocalFileTime(&findData.ftCreationTime, &fileTime);
  FileTimeToSystemTime(&fileTime, &sysTime);
  *creationDate = convertToSqueakTime(sysTime);
  FileTimeToLocalFileTime(&findData.ftLastWriteTime, &fileTime);
  FileTimeToSystemTime(&fileTime, &sysTime);
  *modificationDate = convertToSqueakTime(sysTime);

  if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
    *isDirectory= true;
  else {
    win32FileOffset ofs;
    ofs.dwLow = findData.nFileSizeLow;
    ofs.dwHigh = findData.nFileSizeHigh;
    *sizeIfFile = ofs.offset;
  }
  return ENTRY_FOUND;
}

dir_SetMacFileTypeAndCreator(char *filename, int filenameSize,
			     char *fType, char *fCreator)
{
  /* Win32 files are untyped, and the creator is correct by default */
  return true;
}

dir_GetMacFileTypeAndCreator(char *filename, int filenameSize,
			     char *fType, char *fCreator)
{
  /* Win32 files are untyped, and the creator is correct by default */
  return interpreterProxy->primitiveFail();
}

int dir_Delete(char *pathString, int pathLength) {
  /* Delete the existing directory with the given path. */
  WCHAR win32Path[MAX_PATH];
  int sz;
  /* convert the file name into a null-terminated C string */
  sz = MultiByteToWideChar(CP_UTF8, 0, pathString, pathLength, NULL, 0);
  if(sz > MAX_PATH) return 0;
  MultiByteToWideChar(CP_UTF8, 0, pathString, pathLength, win32Path, sz);
  win32Path[sz] = 0;
  if(hasCaseSensitiveDuplicate(win32Path)) return false;
  return RemoveDirectoryW(win32Path) == 0 ? false : true;
}
