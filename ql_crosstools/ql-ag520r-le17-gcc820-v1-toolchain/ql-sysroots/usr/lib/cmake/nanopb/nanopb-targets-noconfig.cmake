#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nanopb::protobuf-nanopb" for configuration ""
set_property(TARGET nanopb::protobuf-nanopb APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(nanopb::protobuf-nanopb PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libprotobuf-nanopb.so"
  IMPORTED_SONAME_NOCONFIG "libprotobuf-nanopb.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS nanopb::protobuf-nanopb )
list(APPEND _IMPORT_CHECK_FILES_FOR_nanopb::protobuf-nanopb "${_IMPORT_PREFIX}/lib/libprotobuf-nanopb.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
