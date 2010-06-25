/* Automatically generated from Squeak on 15 June 2010 5:06:20 pm 
   by VMMaker 4.2.4
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
#include "MacMenubarPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveAppendMenu(void);
EXPORT(sqInt) primitiveAppendMenuItemText(void);
EXPORT(sqInt) primitiveCheckMenuItem(void);
EXPORT(sqInt) primitiveClearMenuBar(void);
EXPORT(sqInt) primitiveCountMenuItems(void);
EXPORT(sqInt) primitiveCreateStandardWindowMenu(void);
EXPORT(sqInt) primitiveDeleteMenu(void);
EXPORT(sqInt) primitiveDeleteMenuItem(void);
EXPORT(sqInt) primitiveDisableMenuCommand(void);
EXPORT(sqInt) primitiveDisableMenuItem(void);
EXPORT(sqInt) primitiveDisableMenuItemIcon(void);
EXPORT(sqInt) primitiveDisposeMenu(void);
EXPORT(sqInt) primitiveDisposeMenuBar(void);
EXPORT(sqInt) primitiveDrawMenuBar(void);
EXPORT(sqInt) primitiveEnableMenuCommand(void);
EXPORT(sqInt) primitiveEnableMenuItem(void);
EXPORT(sqInt) primitiveEnableMenuItemIcon(void);
EXPORT(sqInt) primitiveGetIndMenuItemWithCommandID(void);
EXPORT(sqInt) primitiveGetIndMenuWithCommandID(void);
EXPORT(sqInt) primitiveGetItemCmd(void);
EXPORT(sqInt) primitiveGetItemIcon(void);
EXPORT(sqInt) primitiveGetItemMark(void);
EXPORT(sqInt) primitiveGetItemStyle(void);
EXPORT(sqInt) primitiveGetMenuBar(void);
EXPORT(sqInt) primitiveGetMenuHandle(void);
EXPORT(sqInt) primitiveGetMenuID(void);
EXPORT(sqInt) primitiveGetMenuItemCommandID(void);
EXPORT(sqInt) primitiveGetMenuItemFontID(void);
EXPORT(sqInt) primitiveGetMenuItemHierarchicalID(void);
EXPORT(sqInt) primitiveGetMenuItemKeyGlyph(void);
EXPORT(sqInt) primitiveGetMenuItemModifiers(void);
EXPORT(sqInt) primitiveGetMenuItemText(void);
EXPORT(sqInt) primitiveGetMenuItemTextEncoding(void);
EXPORT(sqInt) primitiveGetMenuTitle(void);
EXPORT(sqInt) primitiveHideMenuBar(void);
EXPORT(sqInt) primitiveHiliteMenu(void);
EXPORT(sqInt) primitiveInsertFontResMenu(void);
EXPORT(sqInt) primitiveInsertIntlResMenu(void);
EXPORT(sqInt) primitiveInsertMenu(void);
EXPORT(sqInt) primitiveInsertMenuItem(void);
EXPORT(sqInt) primitiveInvalMenuBar(void);
EXPORT(sqInt) primitiveIsMenuBarVisible(void);
EXPORT(sqInt) primitiveIsMenuItemEnabled(void);
EXPORT(sqInt) primitiveIsMenuItemIconEnabled(void);
EXPORT(sqInt) primitiveNewMenu(void);
EXPORT(sqInt) primitiveSetItemCmd(void);
EXPORT(sqInt) primitiveSetItemIcon(void);
EXPORT(sqInt) primitiveSetItemMark(void);
EXPORT(sqInt) primitiveSetItemStyle(void);
EXPORT(sqInt) primitiveSetMenuBar(void);
EXPORT(sqInt) primitiveSetMenuItemCommandID(void);
EXPORT(sqInt) primitiveSetMenuItemFontID(void);
EXPORT(sqInt) primitiveSetMenuItemHierarchicalID(void);
EXPORT(sqInt) primitiveSetMenuItemKeyGlyph(void);
EXPORT(sqInt) primitiveSetMenuItemModifiers(void);
EXPORT(sqInt) primitiveSetMenuItemText(void);
EXPORT(sqInt) primitiveSetMenuItemTextEncoding(void);
EXPORT(sqInt) primitiveSetMenuTitle(void);
EXPORT(sqInt) primitiveShowMenuBar(void);
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
	"MacMenubarPlugin 15 June 2010 (i)"
#else
	"MacMenubarPlugin 15 June 2010 (e)"
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

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveAppendMenu(void) {
	ConstStr255Param constStr255;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	char *str255;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	str255 = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	constStr255 = ((ConstStr255Param) str255);
	AppendMenu(menuHandle,constStr255);
	return null;
}

EXPORT(sqInt) primitiveAppendMenuItemText(void) {
	ConstStr255Param constStr255;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	char *str255;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	str255 = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	constStr255 = ((ConstStr255Param) str255);
	AppendMenuItemText(menuHandle,constStr255);
	return null;
}

EXPORT(sqInt) primitiveCheckMenuItem(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aBoolean;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aBoolean = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	CheckMenuItem(menuHandle,anInteger,aBoolean);
	return null;
}

EXPORT(sqInt) primitiveClearMenuBar(void) {
	ClearMenuBar();
	return null;
}

EXPORT(sqInt) primitiveCountMenuItems(void) {
	sqInt returnValue;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
	returnValue = CountMenuItems(menuHandle);
	_return_value = interpreterProxy->integerObjectOf(returnValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveCreateStandardWindowMenu(void) {
	sqInt result;
	MenuHandle menuHandle;
	sqInt inOptions;
	sqInt _return_value;

	inOptions = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	#if TARGET_API_MAC_CARBON
;
	result = CreateStandardWindowMenu(inOptions,&menuHandle);
#endif;
	_return_value = interpreterProxy->positive32BitIntegerFor(((long) menuHandle));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveDeleteMenu(void) {
	sqInt menuID;

	menuID = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	DeleteMenu(menuID);
	return null;
}

EXPORT(sqInt) primitiveDeleteMenuItem(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	DeleteMenuItem(menuHandle,anInteger);
	return null;
}

EXPORT(sqInt) primitiveDisableMenuCommand(void) {
	MenuCommand commandID;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	commandID = ((MenuCommand) (interpreterProxy->positive32BitValueOf(anInteger)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	#if TARGET_API_MAC_CARBON
DisableMenuCommand(menuHandle,commandID);
#endif;
	return null;
}

EXPORT(sqInt) primitiveDisableMenuItem(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	DisableMenuItem(menuHandle,anInteger);
	return null;
}

EXPORT(sqInt) primitiveDisableMenuItemIcon(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	DisableMenuItemIcon(menuHandle,anInteger);
	return null;
}

EXPORT(sqInt) primitiveDisposeMenu(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
	DisposeMenu(menuHandle);
	return null;
}

EXPORT(sqInt) primitiveDisposeMenuBar(void) {
	Handle menuBarHandle;
	sqInt menuHandleOop;

	menuHandleOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuBarHandle = ((Handle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	#if TARGET_API_MAC_CARBON
	DisposeMenuBar(menuBarHandle);
	#else
	DisposeHandle(menuBarHandle);
	#endif
	;
	return null;
}

EXPORT(sqInt) primitiveDrawMenuBar(void) {
	DrawMenuBar();
	return null;
}

EXPORT(sqInt) primitiveEnableMenuCommand(void) {
	MenuCommand commandID;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	commandID = ((MenuCommand) (interpreterProxy->positive32BitValueOf(anInteger)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	#if TARGET_API_MAC_CARBON
EnableMenuCommand(menuHandle,commandID);
#endif;
	return null;
}

EXPORT(sqInt) primitiveEnableMenuItem(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	EnableMenuItem(menuHandle,anInteger);
	return null;
}

EXPORT(sqInt) primitiveEnableMenuItemIcon(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	EnableMenuItemIcon(menuHandle,anInteger);
	return null;
}

EXPORT(sqInt) primitiveGetIndMenuItemWithCommandID(void) {
	MenuCommand commandID;
	MenuHandle applicationMenu;
	MenuItemIndex outIndex;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt aCommandID;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	aCommandID = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	commandID = ((MenuCommand) (interpreterProxy->positive32BitValueOf(aCommandID)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	#if TARGET_API_MAC_CARBON
GetIndMenuItemWithCommandID(menuHandle, kHICommandHide, 1,
                   &applicationMenu, &outIndex);
#endif;
	_return_value = interpreterProxy->integerObjectOf(outIndex);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetIndMenuWithCommandID(void) {
	MenuCommand commandID;
	MenuHandle applicationMenu;
	MenuItemIndex outIndex;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt aCommandID;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	aCommandID = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	commandID = ((MenuCommand) (interpreterProxy->positive32BitValueOf(aCommandID)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	#if TARGET_API_MAC_CARBON
GetIndMenuItemWithCommandID(menuHandle, kHICommandHide, 1,
                   &applicationMenu, &outIndex);
#endif ;
	_return_value = interpreterProxy->positive32BitIntegerFor(((long) applicationMenu));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetItemCmd(void) {
	CharParameter  aCharacter;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	aCharacter = 0;
	GetItemCmd(menuHandle,anInteger,&aCharacter);
	_return_value = interpreterProxy->integerObjectOf(aCharacter);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetItemIcon(void) {
	MenuHandle menuHandle;
	short iconIndex;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	iconIndex = 0;
	GetItemIcon(menuHandle,anInteger,&iconIndex);
	_return_value = interpreterProxy->integerObjectOf(iconIndex);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetItemMark(void) {
	CharParameter  aCharacter;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	aCharacter = 0;
	GetItemMark(menuHandle,anInteger,&aCharacter);
	_return_value = interpreterProxy->integerObjectOf(aCharacter);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetItemStyle(void) {
	MenuHandle menuHandle;
	Style chStyle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	chStyle = 0;
	GetItemStyle(menuHandle,anInteger,&chStyle);
	_return_value = interpreterProxy->integerObjectOf(chStyle);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuBar(void) {
	Handle menuHandle;
	sqInt _return_value;

	menuHandle = GetMenuBar();
	_return_value = interpreterProxy->positive32BitIntegerFor(((long) menuHandle));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuHandle(void) {
	MenuHandle menuHandle;
	sqInt menuID;
	sqInt _return_value;

	menuID = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = GetMenuHandle(menuID);
	_return_value = interpreterProxy->positive32BitIntegerFor(((long) menuHandle));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuID(void) {
	MenuHandle menuHandle;
	MenuID menuID;
	sqInt menuHandleOop;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
	menuID = GetMenuID(menuHandle);
	_return_value = interpreterProxy->integerObjectOf(menuID);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemCommandID(void) {
	MenuHandle menuHandle;
	MenuCommand outCommandID;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	outCommandID = 0;
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	GetMenuItemCommandID(menuHandle,anInteger,&outCommandID);
	_return_value = interpreterProxy->positive32BitIntegerFor(outCommandID);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemFontID(void) {
	SInt16 outFontID;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	outFontID = 0;
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	GetMenuItemFontID(menuHandle,anInteger,&outFontID);
	_return_value = interpreterProxy->integerObjectOf(outFontID);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemHierarchicalID(void) {
	MenuHandle menuHandle;
	MenuID outHierID;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	outHierID = 0;
	GetMenuItemHierarchicalID(menuHandle,anInteger,&outHierID);
	_return_value = interpreterProxy->integerObjectOf(outHierID);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemKeyGlyph(void) {
	SInt16 outGlyph;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	outGlyph = 0;
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	GetMenuItemKeyGlyph(menuHandle,anInteger,&outGlyph);
	_return_value = interpreterProxy->positive32BitIntegerFor(outGlyph);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemModifiers(void) {
	Style outModifers;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	outModifers = 0;
	GetMenuItemModifiers(menuHandle,anInteger,&outModifers);
	_return_value = interpreterProxy->integerObjectOf(outModifers);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemText(void) {
	Str255  aString;
	sqInt oop;
	char * ptr;
	sqInt size;
	MenuHandle menuHandle;
	sqInt i;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	aString[0] = 0;
	GetMenuItemText(menuHandle,anInteger,aString);
	size = aString[0];
	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), size);
	ptr = interpreterProxy->firstIndexableField(oop);
	for (i = 0; i <= (size - 1); i += 1) {
		ptr[i] = (aString[i + 1]);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, oop);
	return null;
}

EXPORT(sqInt) primitiveGetMenuItemTextEncoding(void) {
	TextEncoding outScriptID;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	GetMenuItemTextEncoding(menuHandle,anInteger,&outScriptID);
	_return_value = interpreterProxy->positive32BitIntegerFor(outScriptID);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveGetMenuTitle(void) {
	Str255  aString;
	sqInt oop;
	char * ptr;
	sqInt size;
	MenuHandle menuHandle;
	sqInt i;
	sqInt menuHandleOop;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(2, _return_value);
		return null;
	}
	aString[0] = 0;
	GetMenuTitle(menuHandle,aString);
	size = aString[0];
	oop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), size);
	ptr = interpreterProxy->firstIndexableField(oop);
	for (i = 0; i <= (size - 1); i += 1) {
		ptr[i] = (aString[i + 1]);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, oop);
	return null;
}

EXPORT(sqInt) primitiveHideMenuBar(void) {
	HideMenuBar();
	return null;
}

EXPORT(sqInt) primitiveHiliteMenu(void) {
	sqInt menuID;

	menuID = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	HiliteMenu(menuID);
	return null;
}

EXPORT(sqInt) primitiveInsertFontResMenu(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt afterItemInteger;
	sqInt scriptFilterInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	afterItemInteger = interpreterProxy->stackIntegerValue(1);
	scriptFilterInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	InsertFontResMenu(menuHandle,afterItemInteger,scriptFilterInteger);
	return null;
}

EXPORT(sqInt) primitiveInsertIntlResMenu(void) {
	ResType resType;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt aResType;
	sqInt afterItemInteger;
	sqInt scriptFilterInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(3);
	aResType = interpreterProxy->stackIntegerValue(2);
	afterItemInteger = interpreterProxy->stackIntegerValue(1);
	scriptFilterInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(5, _return_value);
		return null;
	}
	resType = ((ResType) (interpreterProxy->positive32BitValueOf(aResType)));
	InsertIntlResMenu(menuHandle,resType,afterItemInteger,scriptFilterInteger);
	return null;
}

EXPORT(sqInt) primitiveInsertMenu(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	InsertMenu(menuHandle,anInteger);
	return null;
}

EXPORT(sqInt) primitiveInsertMenuItem(void) {
	ConstStr255Param constStr255;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	char *str255;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	str255 = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	constStr255 = ((ConstStr255Param) str255);
	InsertMenuItem(menuHandle,constStr255,anInteger);
	return null;
}

EXPORT(sqInt) primitiveInvalMenuBar(void) {
	InvalMenuBar();
	return null;
}

EXPORT(sqInt) primitiveIsMenuBarVisible(void) {
	sqInt result;
	sqInt _return_value;

	result = IsMenuBarVisible();
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveIsMenuItemEnabled(void) {
	sqInt result;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	result = IsMenuItemEnabled(menuHandle,anInteger);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveIsMenuItemIconEnabled(void) {
	sqInt result;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	anInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	result = IsMenuItemIconEnabled(menuHandle,anInteger);
	_return_value = (result? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveNewMenu(void) {
	ConstStr255Param constStr255;
	MenuHandle menuHandle;
	sqInt menuID;
	char *menuTitle;
	sqInt _return_value;

	menuID = interpreterProxy->stackIntegerValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	menuTitle = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	constStr255 = ((ConstStr255Param) menuTitle);
	menuHandle = NewMenu(menuID,constStr255);
	_return_value = interpreterProxy->positive32BitIntegerFor(((long) menuHandle));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSetItemCmd(void) {
	CharParameter  aCharacter;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt anIntegerCmdChar;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	anIntegerCmdChar = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	aCharacter = anIntegerCmdChar;
	SetItemCmd(menuHandle,anInteger,aCharacter);
	return null;
}

EXPORT(sqInt) primitiveSetItemIcon(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aIconIndexInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aIconIndexInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetItemIcon(menuHandle,anInteger,aIconIndexInteger);
	return null;
}

EXPORT(sqInt) primitiveSetItemMark(void) {
	CharParameter  aCharacter;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aMarkChar;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aMarkChar = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	aCharacter = aMarkChar;
	SetItemMark(menuHandle,anInteger,aCharacter);
	return null;
}

EXPORT(sqInt) primitiveSetItemStyle(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt chStyleInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	chStyleInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetItemStyle(menuHandle,anInteger,chStyleInteger);
	return null;
}

EXPORT(sqInt) primitiveSetMenuBar(void) {
	MenuBarHandle menuBarHandle;
	sqInt menuHandleOop;

	menuHandleOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuBarHandle = ((MenuBarHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	SetMenuBar(menuBarHandle);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemCommandID(void) {
	MenuCommand commandID;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt inCommandID;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	inCommandID = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	commandID = ((MenuCommand) (interpreterProxy->positive32BitValueOf(inCommandID)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetMenuItemCommandID(menuHandle,anInteger,commandID);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemFontID(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aFontIDInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aFontIDInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetMenuItemFontID(menuHandle,anInteger,aFontIDInteger);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemHierarchicalID(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aMenuID;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aMenuID = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetMenuItemHierarchicalID(menuHandle,anInteger,aMenuID);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemKeyGlyph(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt inGlyphInteger;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	inGlyphInteger = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetMenuItemKeyGlyph(menuHandle,anInteger,inGlyphInteger);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemModifiers(void) {
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aUInt8;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aUInt8 = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	SetMenuItemModifiers(menuHandle,anInteger,aUInt8);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemText(void) {
	ConstStr255Param constStr255;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	sqInt anInteger;
	char *str255;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	str255 = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	constStr255 = ((ConstStr255Param) str255);
	SetMenuItemText(menuHandle,anInteger,constStr255);
	return null;
}

EXPORT(sqInt) primitiveSetMenuItemTextEncoding(void) {
	MenuHandle menuHandle;
	TextEncoding inScriptID;
	sqInt menuHandleOop;
	sqInt anInteger;
	sqInt aTextEncodingOop;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(2);
	anInteger = interpreterProxy->stackIntegerValue(1);
	aTextEncodingOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(4, _return_value);
		return null;
	}
	inScriptID = ((TextEncoding) (interpreterProxy->positive32BitValueOf(aTextEncodingOop)));
	SetMenuItemTextEncoding(menuHandle,anInteger,inScriptID);
	return null;
}

EXPORT(sqInt) primitiveSetMenuTitle(void) {
	ConstStr255Param constStr255;
	MenuHandle menuHandle;
	sqInt menuHandleOop;
	char *str255;
	sqInt _return_value;

	menuHandleOop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	str255 = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	menuHandle = ((MenuHandle) (interpreterProxy->positive32BitValueOf(menuHandleOop)));
	if (!(ioCheckMenuHandle(menuHandle))) {
		_return_value = interpreterProxy->success(0);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(3, _return_value);
		return null;
	}
	constStr255 = ((ConstStr255Param) str255);
	SetMenuTitle(menuHandle,constStr255);
	return null;
}

EXPORT(sqInt) primitiveShowMenuBar(void) {
	ShowMenuBar();
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


void* MacMenubarPlugin_exports[][3] = {
	{"MacMenubarPlugin", "primitiveGetMenuItemKeyGlyph", (void*)primitiveGetMenuItemKeyGlyph},
	{"MacMenubarPlugin", "primitiveAppendMenu", (void*)primitiveAppendMenu},
	{"MacMenubarPlugin", "getModuleName", (void*)getModuleName},
	{"MacMenubarPlugin", "primitiveGetIndMenuWithCommandID", (void*)primitiveGetIndMenuWithCommandID},
	{"MacMenubarPlugin", "primitiveEnableMenuItem", (void*)primitiveEnableMenuItem},
	{"MacMenubarPlugin", "primitiveIsMenuItemIconEnabled", (void*)primitiveIsMenuItemIconEnabled},
	{"MacMenubarPlugin", "primitiveDisposeMenu", (void*)primitiveDisposeMenu},
	{"MacMenubarPlugin", "primitiveInsertIntlResMenu", (void*)primitiveInsertIntlResMenu},
	{"MacMenubarPlugin", "primitiveNewMenu", (void*)primitiveNewMenu},
	{"MacMenubarPlugin", "primitiveSetItemStyle", (void*)primitiveSetItemStyle},
	{"MacMenubarPlugin", "primitiveGetMenuItemCommandID", (void*)primitiveGetMenuItemCommandID},
	{"MacMenubarPlugin", "primitiveIsMenuItemEnabled", (void*)primitiveIsMenuItemEnabled},
	{"MacMenubarPlugin", "primitiveDrawMenuBar", (void*)primitiveDrawMenuBar},
	{"MacMenubarPlugin", "primitiveGetItemStyle", (void*)primitiveGetItemStyle},
	{"MacMenubarPlugin", "primitiveSetItemIcon", (void*)primitiveSetItemIcon},
	{"MacMenubarPlugin", "primitiveSetItemMark", (void*)primitiveSetItemMark},
	{"MacMenubarPlugin", "primitiveSetMenuItemCommandID", (void*)primitiveSetMenuItemCommandID},
	{"MacMenubarPlugin", "primitiveEnableMenuItemIcon", (void*)primitiveEnableMenuItemIcon},
	{"MacMenubarPlugin", "primitiveShowMenuBar", (void*)primitiveShowMenuBar},
	{"MacMenubarPlugin", "primitiveGetItemCmd", (void*)primitiveGetItemCmd},
	{"MacMenubarPlugin", "primitiveDisableMenuItemIcon", (void*)primitiveDisableMenuItemIcon},
	{"MacMenubarPlugin", "primitiveGetItemMark", (void*)primitiveGetItemMark},
	{"MacMenubarPlugin", "primitiveSetMenuItemHierarchicalID", (void*)primitiveSetMenuItemHierarchicalID},
	{"MacMenubarPlugin", "primitiveIsMenuBarVisible", (void*)primitiveIsMenuBarVisible},
	{"MacMenubarPlugin", "primitiveGetMenuItemText", (void*)primitiveGetMenuItemText},
	{"MacMenubarPlugin", "primitiveGetMenuHandle", (void*)primitiveGetMenuHandle},
	{"MacMenubarPlugin", "primitiveClearMenuBar", (void*)primitiveClearMenuBar},
	{"MacMenubarPlugin", "primitiveSetMenuItemText", (void*)primitiveSetMenuItemText},
	{"MacMenubarPlugin", "primitiveSetItemCmd", (void*)primitiveSetItemCmd},
	{"MacMenubarPlugin", "primitiveSetMenuItemTextEncoding", (void*)primitiveSetMenuItemTextEncoding},
	{"MacMenubarPlugin", "primitiveHideMenuBar", (void*)primitiveHideMenuBar},
	{"MacMenubarPlugin", "primitiveAppendMenuItemText", (void*)primitiveAppendMenuItemText},
	{"MacMenubarPlugin", "primitiveDeleteMenu", (void*)primitiveDeleteMenu},
	{"MacMenubarPlugin", "setInterpreter", (void*)setInterpreter},
	{"MacMenubarPlugin", "primitiveGetMenuItemModifiers", (void*)primitiveGetMenuItemModifiers},
	{"MacMenubarPlugin", "primitiveGetItemIcon", (void*)primitiveGetItemIcon},
	{"MacMenubarPlugin", "primitiveDisableMenuCommand", (void*)primitiveDisableMenuCommand},
	{"MacMenubarPlugin", "primitiveInsertMenuItem", (void*)primitiveInsertMenuItem},
	{"MacMenubarPlugin", "primitiveDisableMenuItem", (void*)primitiveDisableMenuItem},
	{"MacMenubarPlugin", "primitiveInvalMenuBar", (void*)primitiveInvalMenuBar},
	{"MacMenubarPlugin", "primitiveGetMenuID", (void*)primitiveGetMenuID},
	{"MacMenubarPlugin", "primitiveCreateStandardWindowMenu", (void*)primitiveCreateStandardWindowMenu},
	{"MacMenubarPlugin", "primitiveGetMenuItemTextEncoding", (void*)primitiveGetMenuItemTextEncoding},
	{"MacMenubarPlugin", "primitiveGetIndMenuItemWithCommandID", (void*)primitiveGetIndMenuItemWithCommandID},
	{"MacMenubarPlugin", "primitiveHiliteMenu", (void*)primitiveHiliteMenu},
	{"MacMenubarPlugin", "primitiveGetMenuItemFontID", (void*)primitiveGetMenuItemFontID},
	{"MacMenubarPlugin", "primitiveInsertFontResMenu", (void*)primitiveInsertFontResMenu},
	{"MacMenubarPlugin", "primitiveSetMenuItemKeyGlyph", (void*)primitiveSetMenuItemKeyGlyph},
	{"MacMenubarPlugin", "primitiveEnableMenuCommand", (void*)primitiveEnableMenuCommand},
	{"MacMenubarPlugin", "primitiveInsertMenu", (void*)primitiveInsertMenu},
	{"MacMenubarPlugin", "primitiveSetMenuItemModifiers", (void*)primitiveSetMenuItemModifiers},
	{"MacMenubarPlugin", "primitiveGetMenuBar", (void*)primitiveGetMenuBar},
	{"MacMenubarPlugin", "primitiveCheckMenuItem", (void*)primitiveCheckMenuItem},
	{"MacMenubarPlugin", "primitiveGetMenuTitle", (void*)primitiveGetMenuTitle},
	{"MacMenubarPlugin", "primitiveDeleteMenuItem", (void*)primitiveDeleteMenuItem},
	{"MacMenubarPlugin", "primitiveDisposeMenuBar", (void*)primitiveDisposeMenuBar},
	{"MacMenubarPlugin", "primitiveSetMenuTitle", (void*)primitiveSetMenuTitle},
	{"MacMenubarPlugin", "primitiveCountMenuItems", (void*)primitiveCountMenuItems},
	{"MacMenubarPlugin", "primitiveGetMenuItemHierarchicalID", (void*)primitiveGetMenuItemHierarchicalID},
	{"MacMenubarPlugin", "primitiveSetMenuBar", (void*)primitiveSetMenuBar},
	{"MacMenubarPlugin", "primitiveSetMenuItemFontID", (void*)primitiveSetMenuItemFontID},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

