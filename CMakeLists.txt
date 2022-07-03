cmake_minimum_required(VERSION 3.13)

##Project name and type
project(cagr)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

##Define executables, libraries here with relative path
# add_library(my_library STATIC src/cagr.cpp)
add_executable(cagr src/main.cpp)

##Subdirectories which are part of the project
add_subdirectory(src)
add_subdirectory(extern)

##Compiler defines, options and features
target_compile_features(cagr 
    PRIVATE 
        cxx_std_17
)
target_compile_options(cagr 
    PRIVATE 
        # -fprofile-arcs 
        # -ftest-coverage
)
# target_compile_definitions(cagr 
#      PRIVATE 
#          foo
#  )

##Linker options, external libraries/objects to link against
target_link_libraries(cagr 
     PRIVATE 
        ${CMAKE_SOURCE_DIR}/extern/lib/libutility.a
 )
target_link_options(cagr 
     PRIVATE 
        # -fprofile-arcs 
        # -ftest-coverage
 )

##Set target properties
set_target_properties(cagr
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
