# generator for cmake users. Given a .proto file generates .pb.h and .pb.c
# in the same directory as the .proto file.
#
#  Usage:
#   find_package(Nanopb REQUIRED)
#   nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS proto/sap-api.proto)
#  this will produce a proto/sap-api.pb.h and proto/sap-api.pb.c files.
#
#
function(NANOPB_GENERATE_CPP SRCS HDRS)
  if(NOT ARGN)
    return()
  endif()

  set(_nanobp_include_path -I ${CMAKE_CURRENT_SOURCE_DIR})

  set(${SRCS})
  set(${HDRS})

  foreach(FIL ${ARGN})
    get_filename_component(ABS_FIL ${FIL} ABSOLUTE)
    get_filename_component(FIL_WE ${ABS_FIL} NAME_WE)
    get_filename_component(FIL_DIR ${ABS_FIL} PATH)
    set(NANOPB_OPTIONS_FILE ${FIL_DIR}/${FIL_WE}.options)
    set(NANOPB_OPTIONS)
    if(EXISTS ${NANOPB_OPTIONS_FILE})
        set(NANOPB_OPTIONS -f ${NANOPB_OPTIONS_FILE})
    endif()

    list(APPEND ${SRCS} "${FIL_DIR}/${FIL_WE}.pb.c")
    list(APPEND ${HDRS} "${FIL_DIR}/${FIL_WE}.pb.h")

    add_custom_command(
      OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${FIL_WE}.pb"
      COMMAND  ${PROTOBUF_PROTOC_EXECUTABLE}
      ARGS -I${CMAKE_CURRENT_BINARY_DIR} ${_nanobp_include_path}
        -o${FIL_WE}.pb ${ABS_FIL}
      COMMENT "Running C++ protocol buffer compiler on ${FIL}"
      VERBATIM )

    add_custom_command(
      OUTPUT "${FIL_DIR}/${FIL_WE}.pb.c"
             "${FIL_DIR}/${FIL_WE}.pb.h"
      COMMAND ${PYTHON_EXECUTABLE}
      ARGS ${NANOPB_GENERATOR_EXECUTABLE} ${FIL_WE}.pb ${NANOPB_OPTIONS} --output=${FIL_DIR}
      DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${FIL_WE}.pb"
      COMMENT "Running nanopb generator on ${FIL_WE}.pb"
      VERBATIM )
  endforeach()

  set_source_files_properties(${${SRCS}} ${${HDRS}} PROPERTIES GENERATED TRUE)
  set(${SRCS} ${${SRCS}} ${NANOPB_SRCS} PARENT_SCOPE)
  set(${HDRS} ${${HDRS}} ${NANOPB_HDRS} PARENT_SCOPE)

endfunction()

set(NANOPB_GENERATOR_EXECUTABLE ${CMAKE_CURRENT_LIST_DIR}/nanopb_generator.py)
find_package(PythonInterp REQUIRED)
find_package(Protobuf REQUIRED)
