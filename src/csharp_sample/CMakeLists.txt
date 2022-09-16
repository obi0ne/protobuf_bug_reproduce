project(csharp_sample LANGUAGES CSharp )

set(SOURCES	
	main.cs
	)

add_executable(csharp_sample ${SOURCES})

set_property(TARGET csharp_sample PROPERTY DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")
set_property(TARGET csharp_sample PROPERTY WIN32_EXECUTABLE FALSE)

find_program(NUGET_EXE NAMES nuget)
if(NOT NUGET_EXE)
	message("NUGET.EXE not found.")
	message(FATAL_ERROR "Please install this executable, and run CMake again.")
else()
	message(STATUS "NUGET.EXE found at ${NUGET_EXE}")
	
	exec_program(${NUGET_EXE}
    ARGS install Google.Protobuf -Version 3.21.4 -OutputDirectory ${CMAKE_BINARY_DIR}/packages)
	
endif()

set_property(TARGET csharp_sample PROPERTY VS_DOTNET_REFERENCES
        "Microsoft.CSharp"
        "PresentationCore"
        "PresentationFramework"
        "System"
        "System.Core"
        "System.Data"
		"System.Memory"
        "System.Data.DataSetExtensions"
        "System.Windows.Forms"
        "System.Net.Http"
        "System.Xaml"
        "System.Xml"
        "System.Xml.Linq"
        "WindowsBase"
)

set_property(TARGET csharp_sample PROPERTY 
    VS_DOTNET_REFERENCE_Google.Protobuf 
    ${CMAKE_BINARY_DIR}/packages/Google.Protobuf.3.21.4/lib/net45/Google.Protobuf.dll
)