cmake_minimum_required (VERSION 2.8.11)
set(name DualContouringSample)
project(${name})

include(CTest)
include(EnvCompilationFlags)


# https://cmake.org/Wiki/CMake_RPATH_handling
if (APPLE)
   set(CMAKE_SKIP_BUILD_RPATH  FALSE)
   set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
   set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
   set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")  
   set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
   # http://www.kitware.com/blog/home/post/510
   # enable @rpath in the install name for any shared library being built
   # note: it is planned that a future version of CMake will enable this by default
   set(CMAKE_MACOSX_RPATH 1)
endif(APPLE)


find_package(GLM    REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GLM_INCLUDE_DIRS} 
)

add_definitions( 
   ${GLM_DEFINITIONS} 
)


set(SOURCES

    octree.cpp
    qef.cpp
    svd.cpp

)

set(_SOURCES
)


set(HEADERS

    DCS_API_EXPORT.hh
    FGLite.h
    octree.h
    octreedata.h
    qef.h
    svd.h
)


add_library(${name} SHARED ${SOURCES}  )
install(TARGETS ${name}  DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/${name})

#add_subdirectory(tests)
