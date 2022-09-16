cmake_minimum_required (VERSION 3.20)
project (cpp_sample)


# generate PROTO files via CMD
find_program(CMD_EXE NAMES cmd)
if(NOT CMD_EXE)
	message("cmd.EXE not found.")
	message(FATAL_ERROR "Please locate CMD executable, and run CMake again.")
else()
	message(STATUS "about to generate proto source from schema, hold on...")
	
	execute_process(
		COMMAND cmd /C "${CMAKE_CURRENT_SOURCE_DIR}/../../Scripts/generate_proto_files.bat"
	)
endif()


set (SOURCE_FILES
	main.cpp
	proto_gen_files/test.pb.h
	proto_gen_files/test.pb.cc
)

add_executable (cpp_sample ${SOURCE_FILES})

target_link_libraries (cpp_sample PUBLIC
 CONAN_PKG::protobuf)