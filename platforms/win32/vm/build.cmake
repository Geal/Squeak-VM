LINK_DIRECTORIES (${vm_link_directories} /home/geal/dev/squeak-vm/dx7sdk/lib)

ADD_EXECUTABLE (squeakvm
  ${bld}/${interp}.c
  ${platdir}/vm/sqWin32Alloc.c
  ${platdir}/vm/sqWin32Args.c
  ${platdir}/vm/sqWin32DirectInput.c
  ${platdir}/vm/sqWin32Directory.c
  ${platdir}/vm/sqWin32Exports.c
  ${platdir}/vm/sqWin32ExternalPrims.c
  ${platdir}/vm/sqWin32GUID.c
  ${platdir}/vm/sqWin32Intel.c
  ${platdir}/vm/sqWin32PluginSupport.c
  ${platdir}/vm/sqWin32Prefs.c
  ${platdir}/vm/sqWin32Service.c
  ${platdir}/vm/sqWin32Stubs.c
  ${platdir}/vm/sqWin32Utils.c
  ${platdir}/vm/sqWin32Window.c
  ${platdir}/vm/version.c
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
  COMMAND tr '\\015' '\\012' < ${src}/vm/interp.c > ${bld}/interp.c
)

#ADD_CUSTOM_COMMAND (
#  DEPENDS ${bld}/interp.c
#  OUTPUT  ${bld}/gnu-interp.c
#  COMMAND ${platdir}/misc/gnuify ${config}/gnuify.awk ${bld}/interp.c ${bld}/gnu-interp.c
#)

INCLUDE_DIRECTORIES (
  ${bld}
  ${src}/vm
  ${platdir}/vm
  ${cross}/vm
  ${cross}/plugins/FilePlugin
  ${cross}/plugins/SocketPlugin
  ${vm_include_directories}
)

SET_TARGET_PROPERTIES (squeakvm PROPERTIES LINK_FLAGS "${CMAKE_EXE_EXPORTS_C_FLAG}")

TARGET_LINK_LIBRARIES (squeakvm m ${squeak_libs} ${vm_link_libraries})

target_link_libraries(squeakvm version gdi32 winmm ole32 comdlg32 dinput)

#LINK_LIBRARIES(

INSTALL (PROGRAMS ${bld}/squeakvm DESTINATION ${plgdir})

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

#ADD_CUSTOM_TARGET (squeak.1
#  DEPENDS ${platdir}/doc/squeak.1
#  COMMAND sh ${bld}/config ${platdir}/doc/squeak.1 ${bld}/squeak.1
#)
#ADD_DEPENDENCIES (squeakvm squeak.1)
#INSTALL (FILES ${bld}/squeak.1 DESTINATION share/man/man1)
