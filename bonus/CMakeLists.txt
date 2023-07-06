cmake_minimum_required(VERSION 2.8)
project(bonus)

## ECE650 Specific configuration start here
## Project specific configurations go here

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

add_executable(bonus bonus.cc dpll.cc parser.cc tokenizer.cc tseitinTransformer.cc)
