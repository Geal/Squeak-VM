# Figure out which plugins to build and create a configuration for each.
# 
# Last edited: 2009-09-17 09:34:24 by piumarta on ubuntu.piumarta.com

FILE (STRINGS ${src}/plugins.int plugins_int)
STRING (REGEX REPLACE ".*= (.*)" "\\1" plugins_int ${plugins_int})
STRING (REPLACE " " ";" plugins_int ${plugins_int})

FILE (STRINGS ${src}/plugins.ext plugins_ext)
STRING (REGEX REPLACE ".*= (.*)" "\\1" plugins_ext ${plugins_ext})
STRING (REPLACE " " ";" plugins_ext ${plugins_ext})

FILE (GLOB plugins_vm RELATIVE ${unix} ${unix}/vm-*)

FILE_COPY (${bld}/disabledPlugins.c ${config}/disabledPlugins.c)

MACRO (DISABLED_PLUGIN plugin)
  FILE (APPEND ${bld}/disabledPlugins.c "disabled(${plugin})\n")
ENDMACRO (DISABLED_PLUGIN)

MACRO (INTERNAL_PLUGIN plugin)
  SET (plugin_sources "")
  IF (DEFINED ${plugin}_sources)
    SET (plugin_sources ${${plugin}_sources})
  ELSE (DEFINED ${plugin}_sources)
    FOREACH (dir ${src}/vm/intplugins ${cross}/plugins ${unix}/plugins)
      SET (tmp "")
      AUX_SOURCE_DIRECTORY (${dir}/${plugin} tmp)
      STRING_APPEND (plugin_sources "${tmp}")
    ENDFOREACH (dir)
  ENDIF (DEFINED ${plugin}_sources)
  FILE (WRITE ${bld}/${plugin}/CMakeLists.in "")
  FOREACH (dir ${unix}/plugins ${unix})
    FILE_APPEND (${bld}/${plugin}/CMakeLists.in ${dir}/${plugin}/build.cmake)
  ENDFOREACH (dir)
  FILE_APPEND (${bld}/${plugin}/CMakeLists.in ${config}/PluginInternal.cmake)
  CONFIGURE_FILE (${bld}/${plugin}/CMakeLists.in ${bld}/${plugin}/CMakeLists.txt @ONLY)
  ADD_SUBDIRECTORY (${bld}/${plugin} ${bld}/${plugin})
ENDMACRO (INTERNAL_PLUGIN)

MACRO (EXTERNAL_PLUGIN plugin)
  SET (plugin_sources)
  IF (DEFINED ${plugin}_sources)
    SET (plugin_sources ${${plugin}_sources})
  ELSE (DEFINED ${plugin}_sources)
    FOREACH (dir ${src}/plugins ${cross}/plugins ${unix}/plugins ${unix})
      SET (tmp "")
      AUX_SOURCE_DIRECTORY (${dir}/${plugin} tmp)
      STRING_APPEND (plugin_sources "${tmp}")
    ENDFOREACH (dir)
  ENDIF (DEFINED ${plugin}_sources)
  FILE (WRITE ${bld}/${plugin}/CMakeLists.in "")
  FOREACH (dir ${unix}/plugins ${unix})
    FILE_APPEND (${bld}/${plugin}/CMakeLists.in ${dir}/${plugin}/build.cmake)
  ENDFOREACH (dir)
  FILE_APPEND (${bld}/${plugin}/CMakeLists.in ${config}/PluginExternal.cmake)
  CONFIGURE_FILE (${bld}/${plugin}/CMakeLists.in ${bld}/${plugin}/CMakeLists.txt @ONLY)
  ADD_SUBDIRECTORY (${bld}/${plugin} ${bld}/${plugin})
ENDMACRO (EXTERNAL_PLUGIN)

MACRO (PLUGIN_DISABLE)
  SET (plugin_disabled 1)
ENDMACRO (PLUGIN_DISABLE)

MACRO (PLUGIN_SOURCES)
  SET (${plugin}_sources ${ARGV})
ENDMACRO (PLUGIN_SOURCES)

MACRO (PLUGIN_DEFINITIONS)
  LIST_APPEND (${plugin}_definitions ${ARGV})
ENDMACRO (PLUGIN_DEFINITIONS)

MACRO (PLUGIN_INCLUDE_DIRECTORIES)
  LIST_APPEND (${plugin}_include_directories ${ARGV})
ENDMACRO (PLUGIN_INCLUDE_DIRECTORIES)

MACRO (PLUGIN_LINK_DIRECTORIES)
  LIST_APPEND (${plugin_target}_link_directories ${ARGV})
ENDMACRO (PLUGIN_LINK_DIRECTORIES)

MACRO (PLUGIN_LINK_LIBRARIES)
  LIST_APPEND (${plugin_target}_link_libraries ${ARGV})
ENDMACRO (PLUGIN_LINK_LIBRARIES)

MACRO (CONFIGURE_PLUGIN_LIST plugins_list)
  SET (plugins ${${plugins_list}})
  FOREACH (plugin ${plugins})
    FILE (MAKE_DIRECTORY ${bld}/${plugin})
    FILE (WRITE ${bld}/${plugin}/config.cmake "")
    FOREACH (dir ${unix}/plugins ${unix})
      FILE_APPEND (${bld}/${plugin}/config.cmake ${dir}/${plugin}/config.cmake)
    ENDFOREACH (dir)
    #MESSAGE ("-- plugin ${plugin}")
    IF (${plugins_list} STREQUAL "plugins_int")
      SET (plugin_target "vm")
    ELSE ()
      SET (plugin_target "${plugin}")
    ENDIF (${plugins_list} STREQUAL "plugins_int")
    SET (plugin_disabled)
    INCLUDE (${bld}/${plugin}/config.cmake)
    IF (without-${plugin})
      SET (plugin_disabled 1)
    ENDIF ()
    IF (DEFINED plugin_disabled)
      LIST (REMOVE_ITEM ${plugins_list} ${plugin})
      IF (${plugins_list} STREQUAL "plugins_int")
        LIST (APPEND plugins_dis ${plugin})
      ENDIF (${plugins_list} STREQUAL "plugins_int")
      MESSAGE ("!! ${plugin} disabled")
      SET (${plugin}_disabled 1)
    ELSE (DEFINED plugin_disabled)
      IF (${plugins_list} STREQUAL "plugins_int")
        USE_LIBRARY (${plugin})
      ENDIF (${plugins_list} STREQUAL "plugins_int")
      SET (${plugin}_disabled)
    ENDIF (DEFINED plugin_disabled)
  ENDFOREACH (plugin)
ENDMACRO (CONFIGURE_PLUGIN_LIST)

MACRO (CONFIGURE_PLUGINS)
  CONFIGURE_PLUGIN_LIST (plugins_int)
  CONFIGURE_PLUGIN_LIST (plugins_ext)
  CONFIGURE_PLUGIN_LIST (plugins_vm)
ENDMACRO (CONFIGURE_PLUGINS)

MACRO (BUILD_PLUGINS)
  FOREACH (plugin ${plugins_dis})
    DISABLED_PLUGIN (${plugin})
  ENDFOREACH (plugin)
  FOREACH (plugin ${plugins_int})
    INTERNAL_PLUGIN (${plugin})
  ENDFOREACH (plugin)
  FOREACH (plugin ${plugins_ext})
    EXTERNAL_PLUGIN (${plugin})
  ENDFOREACH (plugin)
  FOREACH (plugin ${plugins_vm})
    EXTERNAL_PLUGIN (${plugin})
  ENDFOREACH (plugin)
ENDMACRO (BUILD_PLUGINS)

MACRO (PLUGIN_MESSAGE msg)
  MESSAGE (STATUS "${plugin}: ${msg}")
ENDMACRO (PLUGIN_MESSAGE)

MACRO (PLUGIN_FIND_INCLUDE VAR NAME)
  FIND_PATH (${VAR}_H ${NAME} ${${plugin_target}_include_directories} ${ARGN})
  IF (${VAR}_H)
    PLUGIN_MESSAGE ("${${VAR}_H}/${NAME}")
    SET (HAVE_${VAR}_H 1)
    PLUGIN_INCLUDE_DIRECTORIES (${${VAR}_H})
  ELSE ()
    PLUGIN_MESSAGE ("${NAME} not found")
  ENDIF ()
ENDMACRO ()

MACRO (PLUGIN_REQUIRE_INCLUDE VAR NAME)
  PLUGIN_FIND_INCLUDE(${VAR} ${NAME} ${ARGN})
  IF (NOT ${VAR}_H)
    PLUGIN_DISABLE ()
  ENDIF ()
ENDMACRO ()

MACRO (PLUGIN_FIND_LIBRARY VAR NAME)
  FIND_LIBRARY (LIB${VAR} ${NAME})
  IF (LIB${VAR})
    PLUGIN_MESSAGE ("${LIB${VAR}}")
    SET (HAVE_LIB${VAR} 1)
    PLUGIN_LINK_LIBRARIES (${LIB${VAR}})
  ELSE ()
    PLUGIN_MESSAGE ("lib${NAME} not found")
  ENDIF ()
ENDMACRO ()

MACRO (PLUGIN_REQUIRE_LIBRARY VAR NAME)
  PLUGIN_FIND_LIBRARY(${VAR} ${NAME})
  if (NOT LIB${VAR})
    PLUGIN_DISABLE ()
  ENDIF ()
ENDMACRO ()

MACRO (PLUGIN_FIND_PACKAGE VAR NAME)
  IF (PKG_CONFIG_FOUND)
    PKG_CHECK_MODULES (${VAR} ${NAME})
    IF (${VAR}_FOUND)
      PLUGIN_MESSAGE ("${NAME} found")
      SET (HAVE_${VAR} 1)
      PLUGIN_INCLUDE_DIRECTORIES (${${VAR}_INCLUDE_DIRS})
      PLUGIN_LINK_DIRECTORIES (${${VAR}_LIBRARY_DIRS})
      PLUGIN_LINK_LIBRARIES (${${VAR}_LIBRARIES})
    ENDIF ()
  ENDIF ()
ENDMACRO ()

MACRO (PLUGIN_REQUIRE_PACKAGE VAR NAME)
  PLUGIN_FIND_PACKAGE(${VAR} ${NAME})
  IF (NOT ${VAR}_FOUND)
    PLUGIN_DISABLE ()
  ENDIF ()
ENDMACRO ()

MACRO (EXPECT_UNDEFINED_SYMBOLS)
  IF (APPLE)
    SET (CMAKE_SHARED_MODULE_CREATE_C_FLAGS "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -flat_namespace -undefined suppress")
    SET (CMAKE_SHARED_MODULE_CREATE_CXX_FLAGS "${CMAKE_SHARED_MODULE_CREATE_CXX_FLAGS} -flat_namespace -undefined suppress")
  ENDIF (APPLE)
ENDMACRO (EXPECT_UNDEFINED_SYMBOLS)
