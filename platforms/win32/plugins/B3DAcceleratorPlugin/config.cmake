CHECK_INCLUDE_FILE (ddraw.h HAVE_DDRAW_H)
CHECK_INCLUDE_FILE (d3d.h HAVE_D3D_H)


CONFIG_DEFINE (HAVE_DDRAW_H)
CONFIG_DEFINE (HAVE_D3D_H)


FIND_LIBRARY (DDRAW_LIBRARIES   DDRAW)
FIND_LIBRARY (D3DX_LIBRARIES   D3DX)

PLUGIN_REQUIRE_LIBRARY (D3DX d3dx)
PLUGIN_REQUIRE_LIBRARY (DDRAW ddraw)

