# -*- sh -*-

AC_ARG_WITH(x,
[  --without-x             disable X Window System support [default=enabled]],
  [have_x="$withval"],
  [have_x="yes"])

AC_ARG_WITH(gl,
[  --without-gl            disable OpenGL support [default=enabled]],
  [have_gl="$withval"],
  [have_gl="yes"])

###xxx FIXME (AGAIN): mandrake needs explicit -lpthread

VMLIBS=${LIBS}
VMCFLAGS=${CFLAGS}
VMCPPFLAGS=${CPPFLAGS}
VMINCLUDES=${INCLUDES}

if test "$have_x" = "yes"; then
  AC_PATH_XTRA
  LIBS="${X_PRE_LIBS} ${X_LIBS} ${X_EXTRA_LIBS} ${LIBS}"
#  if test "${x_libraries}" != ""; then
#    CFLAGS="${X_CFLAGS} ${CFLAGS} -L${x_libraries}"
#  fi
  if test "${x_includes}" != ""; then
    CPPFLAGS="${CPPFLAGS} -I${x_includes}"
    INCLUDES="${INCLUDES} -I${x_includes}"
    X_INCLUDES="-I${x_includes}"
  fi
  AC_CHECK_LIB(X11, XOpenDisplay, [
    AC_DEFINE(USE_X11, [1])
    AC_DEFINE_UNQUOTED(VM_X11DIR, "${x_libraries}")
    LIBS="${LIBS} -lX11"
    AC_CHECK_LIB(Xext, XShmAttach)
    if test "$have_gl" = "yes"; then 
      have_gl=no
      AC_CHECK_HEADERS(GL/gl.h, [
        AC_CHECK_HEADERS(GL/glx.h, [
          have_gl=yes
          AC_DEFINE(USE_X11_GLX, [1])
          AC_CHECK_LIB(GL,glIsEnabled)
        ])
      ])
    fi
    AC_CHECK_HEADERS(X11/extensions/Xrender.h, [
      AC_CHECK_LIB(Xrender, XRenderQueryVersion)
    ])
  ],[
    AC_PLUGIN_DISABLE
  ])
else
  AC_PLUGIN_DISABLE
fi

X_LIBS=${LIBS}
AC_SUBST(X_LIBS)
X_CFLAGS=${CFLAGS}
AC_SUBST(X_CFLAGS)
X_CPPFLAGS=${CPPFLAGS}
AC_SUBST(X_CPPFLAGS)
X_INCLUDES=${INCLUDES}
AC_SUBST(X_INCLUDES)

LIBS=${VMLIBS}
CFLAGS=${VMCFLAGS}
CPPFLAGS=${VMCPPFLAGS}
INCLUDES=${VMINCLUDES}
