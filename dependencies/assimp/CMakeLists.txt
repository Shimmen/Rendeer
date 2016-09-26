#------------------------------------------------------------------------
# Add Assimp
#------------------------------------------------------------------------
target_include_directories(${RENDEER} PRIVATE "include/")

if (RENDEER_PLATFORM STREQUAL "win32")
	set(ASSIMP_LIB "win32/assimp-vc120-mt.lib")
else ()
	message(FATAL_ERROR "Assimp is currently not set up to support this build platform.")
endif ()

#------------------------------------------------------------------------
