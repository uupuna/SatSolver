cmake_minimum_required(VERSION 2.8)
##project(ece650-minisat)
project(pa2)

if (EXISTS "${CMAKE_SOURCE_DIR}/minisat")
  add_subdirectory(minisat)
else()
  message (FATAL_ERROR "MiniSat not found.\n"
		  "Use \n$ cd ${CMAKE_CURRENT_SOURCE_DIR}\n"
		  "$ git clone https://github.com/agurfinkel/minisat\n"
		  "to clone MiniSat into the source directory.")
endif()

## ECE650 Specific configuration start here
## Project specific configurations go here

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

# create the main executable
# expose minisat header files
include_directories(${CMAKE_SOURCE_DIR}/minisat)
## add additional .cpp files if needed
## add_executable(ece650-minisat ece650-minisat.cpp)
add_executable(pa2 pa2.cc parser.cc tokenizer.cc tseitinTransformer.cc)
# link minisat library with the main executable
## target_link_libraries(ece650-minisat minisat-lib-static)
target_link_libraries(pa2 minisat-lib-static)
