cmake_minimum_required (VERSION 3.5)
set(name DualContouringSample)
project(${name} VERSION 0.1.0)

include(CTest)
include(EnvCompilationFlags)

include(GNUInstallDirs)
set(CMAKE_INSTALL_INCLUDEDIR "externals/include/${name}")
set(CMAKE_INSTALL_LIBDIR     "externals/lib")
set(CMAKE_INSTALL_BINDIR     "lib")
#set(CMAKE_INSTALL_RPATH      "${CMAKE_INSTALL_FULL_LIBDIR}")

find_package(BCM REQUIRED)
include(BCMDeploy)

find_package(GLM    REQUIRED)


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

add_library(${name} SHARED ${SOURCES})
target_link_libraries(${name} PUBLIC Opticks::GLM)

# needed for tests that use non-installed headers
target_include_directories(${name} PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(TARGETS ${name}  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

bcm_deploy(TARGETS ${name} NAMESPACE Opticks:: SKIP_HEADER_INSTALL)


