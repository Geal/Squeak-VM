LINK_DIRECTORIES (${vm_link_directories})

ADD_EXECUTABLE (squeakvm
  ${bld}/${interp}.c
  ${unix}/vm/aio.c
  ${unix}/vm/debug.c
  ${unix}/vm/osExports.c
  ${unix}/vm/sqUnixCharConv.c
  ${unix}/vm/sqUnixExternalPrims.c
  ${unix}/vm/sqUnixMain.c
  ${unix}/vm/sqUnixMemory.c
  ${cross}/vm/sqNamedPrims.c
  ${cross}/vm/sqVirtualMachine.c
  ${bld}/version.c
  ${bld}/disabledPlugins.c
)

ADD_CUSTOM_COMMAND (
  OUTPUT  version.c
  COMMAND ${config}/verstamp ${bld}/version.c ${CMAKE_C_COMPILER}
)

ADD_CUSTOM_COMMAND (
  DEPENDS ${src}/vm/interp.c
  OUTPUT  ${bld}/interp.c
  COMMAND ${CMAKE_COMMAND} -E copy ${src}/vm/interp.c ${bld}/interp.c}
)

ADD_CUSTOM_COMMAND (
  DEPENDS ${src}/vm/interp.c
  OUTPUT  ${bld}/gnu-interp.c
  COMMAND ${config}/gnuify ${config}/gnuify.awk ${src}/vm/interp.c ${bld}/gnu-interp.c
)

INCLUDE_DIRECTORIES (
  ${bld}
  ${src}/vm
  ${unix}/vm
  ${cross}/vm
  ${unix}/plugins/B3DAcceleratorPlugin	# for sqUnixOpenGL.h
  ${X11_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${vm_include_directories}
)

SET_TARGET_PROPERTIES (squeakvm PROPERTIES LINK_FLAGS "${CMAKE_EXE_EXPORTS_C_FLAG}")

TARGET_LINK_LIBRARIES (squeakvm m ${squeak_libs} ${vm_link_libraries})

INSTALL (PROGRAMS ${bld}/squeakvm DESTINATION ${plgdir})

IF (vm-sound-OSS_disabled)
  SET (useoss "false")
ELSE ()
  SET (useoss "true")
ENDIF ()

CONFIGURE_FILE (${config}/config.in ${bld}/config @ONLY)

# launcher scripts

ADD_CUSTOM_TARGET (squeak
  DEPENDS ${config}/squeak.in
  COMMAND sh ${bld}/config ${config}/squeak.in ${bld}/squeak
  COMMAND chmod +x ${bld}/squeak
)

ADD_CUSTOM_TARGET (squeak.sh
  DEPENDS ${config}/squeak.sh.in
  COMMAND sh ${bld}/config ${config}/squeak.sh.in ${bld}/squeak.sh
  COMMAND chmod +x ${bld}/squeak.sh
)

ADD_DEPENDENCIES (squeakvm squeak squeak.sh)

INSTALL (PROGRAMS ${bld}/squeak DESTINATION bin)
INSTALL (PROGRAMS ${bld}/squeak.sh DESTINATION bin)

# manual page

ADD_CUSTOM_TARGET (squeak.1
  DEPENDS ${unix}/doc/squeak.1
  COMMAND sh ${bld}/config ${unix}/doc/squeak.1 ${bld}/squeak.1
)
ADD_DEPENDENCIES (squeakvm squeak.1)
INSTALL (FILES ${bld}/squeak.1 DESTINATION share/man/man1)
