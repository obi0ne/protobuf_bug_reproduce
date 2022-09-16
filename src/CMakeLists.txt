cmake_minimum_required (VERSION 3.20)
project (proto_bug_reproduce)

# conan install via CLI
SET(DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/")
if(NOT EXISTS "${DEPENDENCIES_DIR}")

	message(STATUS "Dependencies folder was not found, about to use conan & fetch it...")
	
	# conan install via CLI
	find_program(CONAN_EXE NAMES conan)
	if(NOT CONAN_EXE)
		message("conan.EXE not found.")
		message(FATAL_ERROR "Please install this executable, and run CMake again.")
	else()
		message(STATUS "CONAN.EXE found at ${CONAN_EXE}")	
		message(STATUS "Installing project dependnecies via conan, please wait...")
		
		exec_program(${CONAN_EXE} ${CMAKE_CURRENT_SOURCE_DIR} ARGS install . -s build_type=Debug OUTPUT_VARIABLE EXEC_RESULT)
		message(STATUS "${EXEC_RESULT}")	
	endif()

else()
	message(STATUS "Dependencies folder was found, not re-fetching via conan...")
endif()

# Conan's cmake generator creates a conanbuildinfo.cmake file, which we
# need to include, and then use:
include(conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS TARGETS)


add_subdirectory(cpp_sample)
add_subdirectory(csharp_sample)
