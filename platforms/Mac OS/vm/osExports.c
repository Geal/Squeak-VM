/* note: this file is only a backward compatible wrapper

   for the old-style "platform.exports" definitions.

   If your platform has migrated to the new exports

   style you may as well insert the exports right here */

#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#include <stdio.h>
#include "sqMacUIEvents.h"
#include "SerialPlugin.h"

/* duh ... this is ugly */

#define XFN(export) {"", #export, (void*)export},

#define XFN2(plugin, export) {#plugin, #export, (void*)plugin##_##export}

WindowPtr getSTWindow(void);
void setMessageHook(eventMessageHook theHook);
void setPostMessageHook(eventMessageHook theHook);
char * GetAttributeString(int id);
int serialPortSetControl(int portNum,int control, char *data);
int serialPortIsOpen(int portNum);
int serialPortNames(int portNum, char *portName, char *inName, char *outName);
Boolean IsKeyDown(void);
int primitivePluginBrowserReady(void);
#ifdef ENABLE_URL_FETCH
int primitivePluginDestroyRequest(void);
int primitivePluginRequestFileHandle(void);
int primitivePluginRequestState(void);
int primitivePluginRequestURL(void);
int primitivePluginRequestURLStream(void);
int primitivePluginPostURL(void);
#endif

void *os_exports[][3] = {

	XFN(getSTWindow)
	XFN(setMessageHook)
	XFN(setPostMessageHook)
	XFN(GetAttributeString)
	XFN(recordDragDropEvent)
	XFN(serialPortClose)
	XFN(serialPortReadInto)
	XFN(serialPortWriteFrom)
	XFN(IsKeyDown)
	XFN(getUIToLock)
/* Plugin support primitives
   We should make these primitives a proper plugin
   but right now we just need the exports. */
XFN(primitivePluginBrowserReady)
#ifdef ENABLE_URL_FETCH
XFN(primitivePluginRequestURLStream)
XFN(primitivePluginRequestURL)
XFN(primitivePluginPostURL)
XFN(primitivePluginRequestFileHandle)
XFN(primitivePluginDestroyRequest)
XFN(primitivePluginRequestState)
#endif
	{NULL, NULL, NULL}

};

