cmake_minimum_required (VERSION 2.6)

project (window)
set (core_VERSION_MAJOR 0)
set (core_VERSION_MINOR 1)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

include_directories (include)

#TODO Make this dependent on the compiler used (MSVC vs clang)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
if (APPLE)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif ()

add_library (window 
	include/window/window.h
	include/window/opengl.h
	src/window/window.cc
	${PLATFORM_FILES}
	)

find_package (GLEW REQUIRED)
include_directories (${GLEW_INCLUDE_DIRS})
target_link_libraries (window ${GLEW_LIBRARIES})

find_package (GLFW REQUIRED)
include_directories (${GLFW_INCLUDE_DIR})
target_link_libraries (window ${GLFW_LIBRARIES})

find_package(OpenGL REQUIRED)
if (NOT APPLE)
	include_directories (${OPENGL_INCLUDE_DIR})
endif ()
target_link_libraries (window ${OPENGL_LIBRARIES})

add_executable (window_sample sample/window/window_sample.cc)
target_link_libraries (window_sample window)
