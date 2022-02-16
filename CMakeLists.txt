cmake_minimum_required(VERSION 3.1)

project(examples LANGUAGES CXX)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${examples_SOURCE_DIR}/examples)

# if (UNIX)
#   set (CMAKE_CXX_FLAGS "-g3 -Wall -O3")
# endif ()

# ===== EXAMPLES FOR ROOT FINDING ALGORITHMS IF 1D FUNCTIONS =====
set (roots_examples_SOURCE_DIR ${examples_SOURCE_DIR}/src/roots-1d)
set (roots_examples_SOURCES
  ${roots_examples_SOURCE_DIR}/examples.cpp
  ${roots_examples_SOURCE_DIR}/solution.cpp
  ${roots_examples_SOURCE_DIR}/bisection.cpp
  ${roots_examples_SOURCE_DIR}/iterative.cpp
  ${roots_examples_SOURCE_DIR}/newton-raphson.cpp
  )

add_executable(root-example ${roots_examples_SOURCES})

