#------------------------------------------------------------------------
# Add glfw
#------------------------------------------------------------------------
target_include_directories(${RENDEER} PRIVATE "include/")

if (RENDEER_PLATFORM STREQUAL "win32")
	set(GLFW_LIB "win32/glfw3.lib")
else ()
	message(FATAL_ERROR "glfw is currently not set up to support this build platform.")
endif ()

#------------------------------------------------------------------------
