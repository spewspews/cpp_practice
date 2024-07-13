file(GLOB LIB_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  CONFIGURE_DEPENDS
  *.cpp)

foreach(LIB_FILE ${LIB_FILES})
  string(REGEX REPLACE "\.cpp" "" LIB ${LIB_FILE})
  add_library(${LIB} ${LIB_FILE})
endforeach()
