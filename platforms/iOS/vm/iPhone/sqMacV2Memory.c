/****************************************************************************
 *   PROJECT:  allocate memory from somewhere for the image
 *   FILE:    sqMacV2Memory.c
 *   CONTENT: 
 *
 *   AUTHOR:  John McIntosh.
 *   ADDRESS: 
 *   EMAIL:   johnmci@smalltalkconsulting.com
 *   RCSID:   
 *
 *   NOTES: 
 
 *****************************************************************************/
/*
 Some of this code was funded via a grant from the European Smalltalk User Group (ESUG)
 Copyright (c) 2008 Corporate Smalltalk Consulting Ltd. All rights reserved.
 MIT License
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 The end-user documentation included with the redistribution, if any, must include the following acknowledgment: 
 "This product includes software developed by Corporate Smalltalk Consulting Ltd (http://www.smalltalkconsulting.com) 
 and its contributors", in the same place and form as other third-party acknowledgments. 
 Alternately, this acknowledgment may appear in the software itself, in the same form and location as other 
 such third-party acknowledgments.
 */
//


 #include "sq.h" 
 #include "sqMacV2Memory.h"
 #include <sys/mman.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

 extern usqInt  gMaxHeapSize;
 extern int gSqueakUseFileMappedMMAP;
 static usqInt	gHeapSize;
 static  void *startOfmmapForANONMemory,*startOfmmapForImageFile;
 static 	 size_t fileRoundedUpToPageSize,freeSpaceRoundedUpToPageSize;
#if defined(SQ_HOST64) && defined(SQ_IMAGE32)
__attribute__ ((visibility("default"))) char * sqMemoryBase=0;
#endif

 /* compute the desired memory allocation */
 
 extern usqInt memory;
 
 usqInt	sqGetAvailableMemory() {
	 return gMaxHeapSize;
 }
 
 usqInt sqAllocateMemoryMac(sqInt minHeapSize, sqInt *desiredHeapSize, FILE * f,usqInt headersize) {
	 void  *possibleLocation,*startOfAnonymousMemory;
	 off_t fileSize;
	 struct stat sb;
	 size_t pageSize= getpagesize();
	 size_t pageMask= ~(pageSize - 1);
	 
	#define valign(x)	((x) & pageMask)
	#pragma unused(minHeapSize,desiredHeapSize)
	 
	 possibleLocation = (void*) (500*1024*1024);
	 gHeapSize = gMaxHeapSize;

	if (gSqueakUseFileMappedMMAP) {
		/* Lets see about mmap the image file into a chunk of memory at the 500MB boundary rounding up to the page size
	  Then we on the next page anonymously allocate the required free space for young space*/
	 
	 /* Thanks to David Pennell for suggesting this */
	 
	 fstat(fileno((FILE *)f), &sb);
	 fileSize = sb.st_size;
	 fileRoundedUpToPageSize = valign(fileSize+pageSize-1);	 
	 startOfmmapForImageFile = mmap(possibleLocation, fileRoundedUpToPageSize, PROT_READ|PROT_WRITE, MAP_FILE|MAP_PRIVATE,fileno((FILE *)f), (off_t)0);
	 
	 if (startOfmmapForImageFile != possibleLocation) {
		 /* This isn't a failure case, let's continue and see what happens */
		 /* Before we would bail, but on 4GB macs with 27 apps running it might not allow 500MB boundary, so let it suggest one and live with it */
		 
		 possibleLocation = startOfmmapForImageFile;
	 }
	 
	 startOfAnonymousMemory = (void *) ((size_t) fileRoundedUpToPageSize + (size_t) possibleLocation);
	 freeSpaceRoundedUpToPageSize = valign(gMaxHeapSize)-fileRoundedUpToPageSize+pageSize;
	 startOfmmapForANONMemory = mmap(startOfAnonymousMemory, freeSpaceRoundedUpToPageSize, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED,0,(off_t)0);
	 
	 if (startOfmmapForANONMemory != startOfAnonymousMemory) {
		 fprintf(stderr, "errno %d\n", errno);
		 perror("startOfmmapForANONMemory failed");
		 exit(42);
	 }
#if defined(SQ_HOST64) && defined(SQ_IMAGE32)
		sqMemoryBase= (char*)startOfmmapForImageFile+headersize;
		return 0;
#else
		return (usqInt) (char*)startOfmmapForImageFile+headersize; 
#endif
	} else {
		void * debug, *actually;
		debug = mmap( possibleLocation, gMaxHeapSize+pageSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED,-1,0);
		
		if(debug == MAP_FAILED) {
			fprintf(stderr, "errno %d\n", errno);
			perror("mmap failed");
			exit(42);
		}
		actually = (char*) debug+pageSize-1;
		actually = (void*) (((size_t) actually) & pageMask);
#if defined(SQ_HOST64) && defined(SQ_IMAGE32)
		sqMemoryBase= actually;
		return 0;
#else
		return (usqInt) actually;
#endif
	}
 }
 
sqInt sqGrowMemoryBy(sqInt memoryLimit, sqInt delta) {
	if ((usqInt) memoryLimit + (usqInt) delta - (usqInt) memory > gMaxHeapSize)
			return memoryLimit;

	gHeapSize += delta;
	return memoryLimit + delta;
 }
 
sqInt sqShrinkMemoryBy(sqInt memoryLimit, sqInt delta) {
	 return sqGrowMemoryBy(memoryLimit,0-delta);
}

sqInt sqMemoryExtraBytesLeft(sqInt includingSwap) {
	return gMaxHeapSize - gHeapSize;
}

void sqMacMemoryFree() {
	if (gSqueakUseFileMappedMMAP) {
		munmap(startOfmmapForImageFile,fileRoundedUpToPageSize);
		munmap(startOfmmapForANONMemory,freeSpaceRoundedUpToPageSize);
	}
}

#ifdef BUILD_FOR_OSX
size_t sqImageFileReadEntireImage(void *ptr, size_t elementSize, size_t count, sqImageFile f) {
	if (gSqueakUseFileMappedMMAP) 
		return count;
	return sqImageFileRead(ptr, elementSize, count, f); 
}
#endif
