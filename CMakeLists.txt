#========================================================================
# Rendeer
#========================================================================
cmake_minimum_required(VERSION 3.2)
project("Rendeer")

# Set build target variable
set(RENDEER "Rendeer")

#------------------------------------------------------------------------
# Detect system name / platform
#------------------------------------------------------------------------
#if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
#
#	# TODO: Windows specifics!
#	set(RENDEER_PLATFORM "win32")
#
#elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#
#	message(FATAL_ERROR "Mac is not yet supported!")
#	set(RENDEER_PLATFORM "macOS")
#
#elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
#
#	message(FATAL_ERROR "Linux is not yet supported!")
#	set(RENDEER_PLATFORM "linux")
#
#else ()
#
#    message(FATAL_ERROR "No supported platform was detected (current \
#                         platform is ${CMAKE_SYSTEM_NAME}).")
#
#endif ()

#------------------------------------------------------------------------
# Detect debug build
#------------------------------------------------------------------------
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in debug mode")
else ()
	#message(FATAL_ERROR "Non-debug build not yet supported (GLFW and assimp are built in debug)!")
endif ()

#------------------------------------------------------------------------
# Collect all relevant source files
#------------------------------------------------------------------------
file(GLOB RENDEER_SOURCES "src/*.h" "src/*.c" "src/*.cpp")

#------------------------------------------------------------------------
# Add executable & set options
#------------------------------------------------------------------------
add_executable(${RENDEER} ${RENDEER_SOURCES})
target_include_directories(${RENDEER} PRIVATE "src/")

target_compile_options(${RENDEER} PRIVATE -std=c++11)

#------------------------------------------------------------------------
# Include dependencies
#------------------------------------------------------------------------

#
# Header only libraries
#
add_subdirectory("dependencies/glad")
add_subdirectory("dependencies/glm")
add_subdirectory("dependencies/stb")

#
# Libraries that requires building
#
include(ExternalProject)

# glfw
include(dependencies/ExternalGLFW.cmake)
target_include_directories(${RENDEER} PRIVATE ${GLFW_INCLUDE_DIR})
target_link_libraries(${RENDEER} PRIVATE ${GLFW_LIBRARIES})

if (APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    target_link_libraries(${RENDEER} PRIVATE ${COCOA_LIBRARY})

    find_library(IOKIT_LIBRARY IOKit)
    target_link_libraries(${RENDEER} PRIVATE ${IOKIT_LIBRARY})

    find_library(COREVIDEO_LIBRARY CoreVideo)
    target_link_libraries(${RENDEER} PRIVATE ${COREVIDEO_LIBRARY})
endif ()

# assimp
include(dependencies/ExternalAssimp.cmake)
target_include_directories(${RENDEER} PRIVATE ${ASSIMP_INCLUDE_DIR})
target_link_libraries(${RENDEER} PRIVATE ${ASSIMP_LIBRARIES})

include(FindZLIB)
target_link_libraries(${RENDEER} PRIVATE ${ZLIB_LIBRARIES})

#------------------------------------------------------------------------
