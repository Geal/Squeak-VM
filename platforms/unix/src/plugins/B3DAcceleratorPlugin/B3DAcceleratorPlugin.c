/* Automatically generated from Squeak on an Array(26 August 2009 10:01:37 pm)
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
#include "B3DAcceleratorPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static void* fetchLightSourceofObject(sqInt index, sqInt anArray);
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
EXPORT(sqInt) primitiveAllocateTexture(void);
EXPORT(sqInt) primitiveClearDepthBuffer(void);
EXPORT(sqInt) primitiveClearViewport(void);
EXPORT(sqInt) primitiveCompositeTexture(void);
EXPORT(sqInt) primitiveCreateRenderer(void);
EXPORT(sqInt) primitiveCreateRendererFlags(void);
EXPORT(sqInt) primitiveDestroyRenderer(void);
EXPORT(sqInt) primitiveDestroyTexture(void);
EXPORT(sqInt) primitiveFinishRenderer(void);
EXPORT(sqInt) primitiveFlushRenderer(void);
EXPORT(sqInt) primitiveGetIntProperty(void);
EXPORT(sqInt) primitiveGetRendererColorMasks(void);
EXPORT(sqInt) primitiveGetRendererSurfaceDepth(void);
EXPORT(sqInt) primitiveGetRendererSurfaceHandle(void);
EXPORT(sqInt) primitiveGetRendererSurfaceHeight(void);
EXPORT(sqInt) primitiveGetRendererSurfaceWidth(void);
EXPORT(sqInt) primitiveIsOverlayRenderer(void);
EXPORT(sqInt) primitiveRenderVertexBuffer(void);
EXPORT(sqInt) primitiveRendererVersion(void);
EXPORT(sqInt) primitiveSetBufferRect(void);
EXPORT(sqInt) primitiveSetFog(void);
EXPORT(sqInt) primitiveSetIntProperty(void);
EXPORT(sqInt) primitiveSetLights(void);
EXPORT(sqInt) primitiveSetMaterial(void);
EXPORT(sqInt) primitiveSetTransform(void);
EXPORT(sqInt) primitiveSetVerboseLevel(void);
EXPORT(sqInt) primitiveSetViewport(void);
EXPORT(sqInt) primitiveSwapRendererBuffers(void);
EXPORT(sqInt) primitiveTextureByteSex(void);
EXPORT(sqInt) primitiveTextureDepth(void);
EXPORT(sqInt) primitiveTextureGetColorMasks(void);
EXPORT(sqInt) primitiveTextureSurfaceHandle(void);
EXPORT(sqInt) primitiveTextureUpload(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt stackLightArrayValue(sqInt stackIndex);
static void * stackMaterialValue(sqInt stackIndex);
static void* stackMatrix(sqInt index);
static void* stackPrimitiveIndexArrayofSizevalidateforVertexSize(sqInt stackIndex, sqInt nItems, sqInt aBool, sqInt maxIndex);
static void* stackPrimitiveVertex(sqInt index);
static void* stackPrimitiveVertexArrayofSize(sqInt index, sqInt nItems);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"B3DAcceleratorPlugin 26 August 2009 (i)"
#else
	"B3DAcceleratorPlugin 26 August 2009 (e)"
#endif
;



/*	Fetch the primitive light source from the given array.
	Note: No checks are done within here - that happened in stackLightArrayValue: */

static void* fetchLightSourceofObject(sqInt index, sqInt anArray) {
    sqInt lightOop;

	lightOop = interpreterProxy->fetchPointerofObject(index, anArray);
	return interpreterProxy->firstIndexableField(lightOop);
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
	return b3dxInitialize();
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveAllocateTexture(void) {
    sqInt renderer;
    sqInt h;
    sqInt w;
    sqInt result;
    sqInt d;

	if (!((interpreterProxy->methodArgumentCount()) == 4)) {
		return interpreterProxy->primitiveFail();
	}
	h = interpreterProxy->stackIntegerValue(0);
	w = interpreterProxy->stackIntegerValue(1);
	d = interpreterProxy->stackIntegerValue(2);
	renderer = interpreterProxy->stackIntegerValue(3);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxAllocateTexture(renderer, w, h, d);
	if (result == -1) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(5);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveClearDepthBuffer(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxClearDepthBuffer(handle);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveClearViewport(void) {
    sqInt handle;
    sqInt rgba;
    sqInt pv;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 3)) {
		return interpreterProxy->primitiveFail();
	}
	pv = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	rgba = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(1));
	handle = interpreterProxy->stackIntegerValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxClearViewport(handle, rgba, pv);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(3);
}

EXPORT(sqInt) primitiveCompositeTexture(void) {
    sqInt rendererHandle;
    sqInt translucent;
    sqInt texHandle;
    sqInt y;
    sqInt result;
    sqInt x;
    sqInt h;
    sqInt w;

	if (!((interpreterProxy->methodArgumentCount()) == 7)) {
		return interpreterProxy->primitiveFail();
	}
	translucent = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	h = interpreterProxy->stackIntegerValue(1);
	w = interpreterProxy->stackIntegerValue(2);
	y = interpreterProxy->stackIntegerValue(3);
	x = interpreterProxy->stackIntegerValue(4);
	texHandle = interpreterProxy->stackIntegerValue(5);
	rendererHandle = interpreterProxy->stackIntegerValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxCompositeTexture(rendererHandle, texHandle, x, y, w, h, translucent);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(7);
}


/*	NOTE: This primitive is obsolete but should be supported for older images */

EXPORT(sqInt) primitiveCreateRenderer(void) {
    sqInt allowSoftware;
    sqInt y;
    sqInt result;
    sqInt x;
    sqInt allowHardware;
    sqInt h;
    sqInt w;

	if (!((interpreterProxy->methodArgumentCount()) == 6)) {
		return interpreterProxy->primitiveFail();
	}
	h = interpreterProxy->stackIntegerValue(0);
	w = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(2);
	x = interpreterProxy->stackIntegerValue(3);
	allowHardware = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(4));
	allowSoftware = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(5));
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxCreateRenderer(allowSoftware, allowHardware, x, y, w, h);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(7);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveCreateRendererFlags(void) {
    sqInt flags;
    sqInt x;
    sqInt h;
    sqInt w;
    sqInt y;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	h = interpreterProxy->stackIntegerValue(0);
	w = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(2);
	x = interpreterProxy->stackIntegerValue(3);
	flags = interpreterProxy->stackIntegerValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxCreateRendererFlags(x, y, w, h, flags);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(6);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveDestroyRenderer(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxDestroyRenderer(handle);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveDestroyTexture(void) {
    sqInt renderer;
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	renderer = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxDestroyTexture(renderer, handle);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(2);
}

EXPORT(sqInt) primitiveFinishRenderer(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxFinishRenderer(handle);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveFlushRenderer(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxFlushRenderer(handle);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveGetIntProperty(void) {
    sqInt handle;
    sqInt prop;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	prop = interpreterProxy->stackIntegerValue(0);
	handle = interpreterProxy->stackIntegerValue(1);
	result = b3dxGetIntProperty(handle, prop);
	interpreterProxy->pop(3);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveGetRendererColorMasks(void) {
    sqInt arrayOop;
    sqInt i;
    sqInt handle;
    int masks[4];
    sqInt result;
    sqInt array;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	array = interpreterProxy->stackObjectValue(0);
	handle = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->fetchClassOf(array)) == (interpreterProxy->classArray()))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->slotSizeOf(array)) == 4)) {
		return interpreterProxy->primitiveFail();
	}
	result = b3dxGetRendererColorMasks(handle, masks);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	arrayOop = array;
	for (i = 0; i <= 3; i += 1) {
		interpreterProxy->pushRemappableOop(arrayOop);
		result = interpreterProxy->positive32BitIntegerFor(masks[i]);
		arrayOop = interpreterProxy->popRemappableOop();
		interpreterProxy->storePointerofObjectwithValue(i, arrayOop, result);
	}
	return interpreterProxy->pop(2);
}

EXPORT(sqInt) primitiveGetRendererSurfaceDepth(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxGetRendererSurfaceDepth(handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveGetRendererSurfaceHandle(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxGetRendererSurfaceHandle(handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveGetRendererSurfaceHeight(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxGetRendererSurfaceHeight(handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveGetRendererSurfaceWidth(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxGetRendererSurfaceWidth(handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveIsOverlayRenderer(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxIsOverlayRenderer(handle);
	interpreterProxy->pop(2);
	return interpreterProxy->pushBool(result);
}

EXPORT(sqInt) primitiveRenderVertexBuffer(void) {
    sqInt primType;
    sqInt texHandle;
    sqInt result;
    sqInt idxCount;
    sqInt flags;
    sqInt handle;
    sqInt vtxCount;
    int * idxArray;
    float * vtxArray;

	if (!((interpreterProxy->methodArgumentCount()) == 8)) {
		return interpreterProxy->primitiveFail();
	}
	idxCount = interpreterProxy->stackIntegerValue(0);
	vtxCount = interpreterProxy->stackIntegerValue(2);
	texHandle = interpreterProxy->stackIntegerValue(4);
	flags = interpreterProxy->stackIntegerValue(5);
	primType = interpreterProxy->stackIntegerValue(6);
	handle = interpreterProxy->stackIntegerValue(7);
	if (interpreterProxy->failed()) {
		return null;
	}
	vtxArray = stackPrimitiveVertexArrayofSize(3, vtxCount);
	idxArray = stackPrimitiveIndexArrayofSizevalidateforVertexSize(1, idxCount, 1, vtxCount);
	if ((vtxArray == null) || ((idxArray == null) || ((primType < 1) || ((primType > 6) || (interpreterProxy->failed()))))) {
		return interpreterProxy->primitiveFail();
	}
	result = b3dxRenderVertexBuffer(handle, primType, flags, texHandle, vtxArray, vtxCount, idxArray, idxCount);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(8);
}

EXPORT(sqInt) primitiveRendererVersion(void) {
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	return interpreterProxy->pushInteger(1);
}


/*	Primitive. Set the buffer rectangle (e.g., the pixel area on screen) to use for this renderer.
	The viewport is positioned within the buffer rectangle. */

EXPORT(sqInt) primitiveSetBufferRect(void) {
    sqInt x;
    sqInt handle;
    sqInt h;
    sqInt w;
    sqInt y;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	h = interpreterProxy->stackIntegerValue(0);
	w = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(2);
	x = interpreterProxy->stackIntegerValue(3);
	handle = interpreterProxy->stackIntegerValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxSetBufferRect(handle, x, y, w, h);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(5);
}

EXPORT(sqInt) primitiveSetFog(void) {
    double start;
    double density;
    sqInt fogType;
    sqInt result;
    sqInt handle;
    sqInt rgba;
    double stop;

	if (!((interpreterProxy->methodArgumentCount()) == 6)) {
		return interpreterProxy->primitiveFail();
	}
	rgba = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	stop = interpreterProxy->floatValueOf(interpreterProxy->stackValue(1));
	start = interpreterProxy->floatValueOf(interpreterProxy->stackValue(2));
	density = interpreterProxy->floatValueOf(interpreterProxy->stackValue(3));
	fogType = interpreterProxy->stackIntegerValue(4);
	handle = interpreterProxy->stackIntegerValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxSetFog(handle, fogType, density, start, stop, rgba);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(6);
}

EXPORT(sqInt) primitiveSetIntProperty(void) {
    sqInt handle;
    sqInt prop;
    sqInt value;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 3)) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->stackIntegerValue(0);
	prop = interpreterProxy->stackIntegerValue(1);
	handle = interpreterProxy->stackIntegerValue(2);
	result = b3dxSetIntProperty(handle, prop, value);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(3);
}

EXPORT(sqInt) primitiveSetLights(void) {
    sqInt i;
    sqInt lightCount;
    sqInt handle;
    sqInt lightArray;
    void* light;
    sqInt lightOop;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	lightArray = stackLightArrayValue(0);
	handle = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(b3dxDisableLights(handle))) {
		return interpreterProxy->primitiveFail();
	}
	if (lightArray == null) {
		return null;
	}

	/* For each enabled light source */

	lightCount = interpreterProxy->slotSizeOf(lightArray);
	for (i = 0; i <= (lightCount - 1); i += 1) {
		/* begin fetchLightSource:ofObject: */
		lightOop = interpreterProxy->fetchPointerofObject(i, lightArray);
		light = interpreterProxy->firstIndexableField(lightOop);
		if (!(b3dxLoadLight(handle, i, light))) {
			return interpreterProxy->primitiveFail();
		}
	}
	return interpreterProxy->pop(2);
}

EXPORT(sqInt) primitiveSetMaterial(void) {
    sqInt handle;
    void* material;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	material = stackMaterialValue(0);
	handle = interpreterProxy->stackIntegerValue(1);
	if (!(b3dxLoadMaterial(handle, material))) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(2);
}


/*	Transform an entire vertex buffer using the supplied modelview and projection matrix. */

EXPORT(sqInt) primitiveSetTransform(void) {
    float *projectionMatrix;
    sqInt handle;
    float *modelViewMatrix;

	if (!((interpreterProxy->methodArgumentCount()) == 3)) {
		return interpreterProxy->primitiveFail();
	}
	projectionMatrix = stackMatrix(0);
	modelViewMatrix = stackMatrix(1);
	handle = interpreterProxy->stackIntegerValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	b3dxSetTransform(handle, modelViewMatrix, projectionMatrix);
	return interpreterProxy->pop(3);
}

EXPORT(sqInt) primitiveSetVerboseLevel(void) {
    sqInt level;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	level = interpreterProxy->stackIntegerValue(0);
	result = b3dxSetVerboseLevel(level);
	interpreterProxy->pop(2);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveSetViewport(void) {
    sqInt x;
    sqInt handle;
    sqInt h;
    sqInt w;
    sqInt y;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	h = interpreterProxy->stackIntegerValue(0);
	w = interpreterProxy->stackIntegerValue(1);
	y = interpreterProxy->stackIntegerValue(2);
	x = interpreterProxy->stackIntegerValue(3);
	handle = interpreterProxy->stackIntegerValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxSetViewport(handle, x, y, w, h);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(5);
}

EXPORT(sqInt) primitiveSwapRendererBuffers(void) {
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxSwapRendererBuffers(handle);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveTextureByteSex(void) {
    sqInt renderer;
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	renderer = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxTextureByteSex(renderer, handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(3);
	return interpreterProxy->pushBool(result);
}

EXPORT(sqInt) primitiveTextureDepth(void) {
    sqInt renderer;
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	renderer = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxActualTextureDepth(renderer, handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(3);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveTextureGetColorMasks(void) {
    int masks[4];
    sqInt result;
    sqInt array;
    sqInt arrayOop;
    sqInt renderer;
    sqInt handle;
    sqInt i;

	if (!((interpreterProxy->methodArgumentCount()) == 3)) {
		return interpreterProxy->primitiveFail();
	}
	array = interpreterProxy->stackObjectValue(0);
	handle = interpreterProxy->stackIntegerValue(1);
	renderer = interpreterProxy->stackIntegerValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((interpreterProxy->fetchClassOf(array)) == (interpreterProxy->classArray()))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->slotSizeOf(array)) == 4)) {
		return interpreterProxy->primitiveFail();
	}
	result = b3dxTextureColorMasks(renderer, handle, masks);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	arrayOop = array;
	for (i = 0; i <= 3; i += 1) {
		interpreterProxy->pushRemappableOop(arrayOop);
		result = interpreterProxy->positive32BitIntegerFor(masks[i]);
		arrayOop = interpreterProxy->popRemappableOop();
		interpreterProxy->storePointerofObjectwithValue(i, arrayOop, result);
	}
	return interpreterProxy->pop(3);
}

EXPORT(sqInt) primitiveTextureSurfaceHandle(void) {
    sqInt renderer;
    sqInt handle;
    sqInt result;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	handle = interpreterProxy->stackIntegerValue(0);
	renderer = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxTextureSurfaceHandle(renderer, handle);
	if (result < 0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(3);
	return interpreterProxy->pushInteger(result);
}

EXPORT(sqInt) primitiveTextureUpload(void) {
    sqInt ppw;
    sqInt bits;
    sqInt result;
    sqInt d;
    void* bitsPtr;
    sqInt renderer;
    sqInt handle;
    sqInt h;
    sqInt w;
    sqInt form;

	if (!((interpreterProxy->methodArgumentCount()) == 3)) {
		return interpreterProxy->primitiveFail();
	}
	form = interpreterProxy->stackValue(0);
	if (!((interpreterProxy->isPointers(form)) && ((interpreterProxy->slotSizeOf(form)) >= 4))) {
		return interpreterProxy->primitiveFail();
	}
	bits = interpreterProxy->fetchPointerofObject(0, form);
	w = interpreterProxy->fetchIntegerofObject(1, form);
	h = interpreterProxy->fetchIntegerofObject(2, form);
	d = interpreterProxy->fetchIntegerofObject(3, form);
	ppw = 32 / d;
	if (!(interpreterProxy->isWords(bits))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->slotSizeOf(bits)) == ((((w + ppw) - 1) / ppw) * h))) {
		return interpreterProxy->primitiveFail();
	}
	bitsPtr = interpreterProxy->firstIndexableField(bits);
	handle = interpreterProxy->stackIntegerValue(1);
	renderer = interpreterProxy->stackIntegerValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = b3dxUploadTexture(renderer, handle, w, h, d, bitsPtr);
	if (!(result)) {
		return interpreterProxy->primitiveFail();
	}
	return interpreterProxy->pop(3);
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
	return b3dxShutdown();
}


/*	Load an Array of B3DPrimitiveLights from the given stack index */

static sqInt stackLightArrayValue(sqInt stackIndex) {
    sqInt i;
    sqInt arraySize;
    sqInt oop;
    sqInt array;

	array = interpreterProxy->stackObjectValue(stackIndex);
	if (array == null) {
		return null;
	}
	if (array == (interpreterProxy->nilObject())) {
		return null;
	}
	if (!((interpreterProxy->fetchClassOf(array)) == (interpreterProxy->classArray()))) {
		return interpreterProxy->primitiveFail();
	}
	arraySize = interpreterProxy->slotSizeOf(array);
	for (i = 0; i <= (arraySize - 1); i += 1) {
		oop = interpreterProxy->fetchPointerofObject(i, array);
		if ((oop & 1)) {
			return interpreterProxy->primitiveFail();
		}
		if (!((interpreterProxy->isWords(oop)) && ((interpreterProxy->slotSizeOf(oop)) == 32))) {
			return interpreterProxy->primitiveFail();
		}
	}
	return array;
}


/*	Load a B3DMaterial from the given stack index */

static void * stackMaterialValue(sqInt stackIndex) {
    sqInt oop;

	oop = interpreterProxy->stackObjectValue(stackIndex);
	if (oop == null) {
		return null;
	}
	if (oop == (interpreterProxy->nilObject())) {
		return null;
	}
	if ((interpreterProxy->isWords(oop)) && ((interpreterProxy->slotSizeOf(oop)) == 17)) {
		return interpreterProxy->firstIndexableField(oop);
	}
	return null;
}


/*	Load a 4x4 transformation matrix from the interpreter stack.
	Return a pointer to the matrix data if successful, nil otherwise. */

static void* stackMatrix(sqInt index) {
    sqInt oop;

	oop = interpreterProxy->stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if (oop == (interpreterProxy->nilObject())) {
		return null;
	}
	if ((interpreterProxy->isWords(oop)) && ((interpreterProxy->slotSizeOf(oop)) == 16)) {
		return interpreterProxy->firstIndexableField(oop);
	}
	return null;
}


/*	Load a primitive index array from the interpreter stack.
	If aBool is true then check that all the indexes are in the range (1,maxIndex).
	Return a pointer to the index data if successful, nil otherwise. */

static void* stackPrimitiveIndexArrayofSizevalidateforVertexSize(sqInt stackIndex, sqInt nItems, sqInt aBool, sqInt maxIndex) {
    sqInt oop;
    int *idxPtr;
    sqInt i;
    sqInt index;
    sqInt oopSize;

	oop = interpreterProxy->stackObjectValue(stackIndex);
	if (oop == null) {
		return null;
	}
	if (!(interpreterProxy->isWords(oop))) {
		return null;
	}
	oopSize = interpreterProxy->slotSizeOf(oop);
	if (oopSize < nItems) {
		return null;
	}
	idxPtr = ((int *) (interpreterProxy->firstIndexableField(oop)));
	if (aBool) {
		for (i = 0; i <= (nItems - 1); i += 1) {
			index = idxPtr[i];
			if ((index < 0) || (index > maxIndex)) {
				return null;
			}
		}
	}
	return idxPtr;
}


/*	Load a primitive vertex from the interpreter stack.
	Return a pointer to the vertex data if successful, nil otherwise. */

static void* stackPrimitiveVertex(sqInt index) {
    sqInt oop;

	oop = interpreterProxy->stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if ((interpreterProxy->isWords(oop)) && ((interpreterProxy->slotSizeOf(oop)) == 16)) {
		return interpreterProxy->firstIndexableField(oop);
	}
	return null;
}


/*	Load a primitive vertex array from the interpreter stack.
	Return a pointer to the vertex data if successful, nil otherwise. */

static void* stackPrimitiveVertexArrayofSize(sqInt index, sqInt nItems) {
    sqInt oop;
    sqInt oopSize;

	oop = interpreterProxy->stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if (interpreterProxy->isWords(oop)) {
		oopSize = interpreterProxy->slotSizeOf(oop);
		if (((oopSize >= nItems) * 16) && ((oopSize % 16) == 0)) {
			return interpreterProxy->firstIndexableField(oop);
		}
	}
	return null;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* B3DAcceleratorPlugin_exports[][3] = {
	{"B3DAcceleratorPlugin", "primitiveTextureUpload", (void*)primitiveTextureUpload},
	{"B3DAcceleratorPlugin", "primitiveFinishRenderer", (void*)primitiveFinishRenderer},
	{"B3DAcceleratorPlugin", "shutdownModule", (void*)shutdownModule},
	{"B3DAcceleratorPlugin", "primitiveTextureSurfaceHandle", (void*)primitiveTextureSurfaceHandle},
	{"B3DAcceleratorPlugin", "primitiveGetRendererSurfaceHeight", (void*)primitiveGetRendererSurfaceHeight},
	{"B3DAcceleratorPlugin", "setInterpreter", (void*)setInterpreter},
	{"B3DAcceleratorPlugin", "primitiveClearViewport", (void*)primitiveClearViewport},
	{"B3DAcceleratorPlugin", "primitiveTextureByteSex", (void*)primitiveTextureByteSex},
	{"B3DAcceleratorPlugin", "primitiveSetVerboseLevel", (void*)primitiveSetVerboseLevel},
	{"B3DAcceleratorPlugin", "primitiveCreateRenderer", (void*)primitiveCreateRenderer},
	{"B3DAcceleratorPlugin", "primitiveSetIntProperty", (void*)primitiveSetIntProperty},
	{"B3DAcceleratorPlugin", "primitiveSetFog", (void*)primitiveSetFog},
	{"B3DAcceleratorPlugin", "primitiveSetBufferRect", (void*)primitiveSetBufferRect},
	{"B3DAcceleratorPlugin", "primitiveSetMaterial", (void*)primitiveSetMaterial},
	{"B3DAcceleratorPlugin", "primitiveSetViewport", (void*)primitiveSetViewport},
	{"B3DAcceleratorPlugin", "primitiveTextureGetColorMasks", (void*)primitiveTextureGetColorMasks},
	{"B3DAcceleratorPlugin", "initialiseModule", (void*)initialiseModule},
	{"B3DAcceleratorPlugin", "primitiveCreateRendererFlags", (void*)primitiveCreateRendererFlags},
	{"B3DAcceleratorPlugin", "primitiveRenderVertexBuffer", (void*)primitiveRenderVertexBuffer},
	{"B3DAcceleratorPlugin", "primitiveSetTransform", (void*)primitiveSetTransform},
	{"B3DAcceleratorPlugin", "primitiveSwapRendererBuffers", (void*)primitiveSwapRendererBuffers},
	{"B3DAcceleratorPlugin", "primitiveGetRendererColorMasks", (void*)primitiveGetRendererColorMasks},
	{"B3DAcceleratorPlugin", "primitiveSetLights", (void*)primitiveSetLights},
	{"B3DAcceleratorPlugin", "primitiveCompositeTexture", (void*)primitiveCompositeTexture},
	{"B3DAcceleratorPlugin", "primitiveRendererVersion", (void*)primitiveRendererVersion},
	{"B3DAcceleratorPlugin", "primitiveTextureDepth", (void*)primitiveTextureDepth},
	{"B3DAcceleratorPlugin", "primitiveGetIntProperty", (void*)primitiveGetIntProperty},
	{"B3DAcceleratorPlugin", "primitiveGetRendererSurfaceDepth", (void*)primitiveGetRendererSurfaceDepth},
	{"B3DAcceleratorPlugin", "primitiveAllocateTexture", (void*)primitiveAllocateTexture},
	{"B3DAcceleratorPlugin", "getModuleName", (void*)getModuleName},
	{"B3DAcceleratorPlugin", "primitiveDestroyTexture", (void*)primitiveDestroyTexture},
	{"B3DAcceleratorPlugin", "primitiveClearDepthBuffer", (void*)primitiveClearDepthBuffer},
	{"B3DAcceleratorPlugin", "primitiveGetRendererSurfaceWidth", (void*)primitiveGetRendererSurfaceWidth},
	{"B3DAcceleratorPlugin", "primitiveDestroyRenderer", (void*)primitiveDestroyRenderer},
	{"B3DAcceleratorPlugin", "primitiveIsOverlayRenderer", (void*)primitiveIsOverlayRenderer},
	{"B3DAcceleratorPlugin", "primitiveFlushRenderer", (void*)primitiveFlushRenderer},
	{"B3DAcceleratorPlugin", "primitiveGetRendererSurfaceHandle", (void*)primitiveGetRendererSurfaceHandle},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

