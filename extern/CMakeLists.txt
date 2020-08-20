##Following subdirectories are part of the project
add_subdirectory(include)
#add_subdirectory(lib)
# add_subdirectory(utility)

##All .h files in this directory are to be included
target_include_directories(cagr 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

##List here the source files in current directory (Good way to include sources)
# target_sources(cagr 
#     PRIVATE 
#         main.cpp
# )

##All .cpp files in this directory are source files (Quick and dirty way to include sources)
# file(GLOB SOURCES "*.cpp")
# target_sources(cagr PRIVATE ${SOURCES})
