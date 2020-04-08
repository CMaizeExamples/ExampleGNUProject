# Declare minimum version required
cmake_minimum_required(VERSION 3.13.4)

# Declare project name and version
project(example_gnu_project VERSION 1.0)

# Set the project language
set(LANGUAGE CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include CMake automatically (fetch from GitHub)
include("${PROJECT_SOURCE_DIR}/cmake/get_cmaize.cmake")

# Add our TravelCostUtils library
cpp_add_library(
    travel_cost_utils
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/travel_cost_utils"
    INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include/example_gnu_project/travel_cost_utils"
)

# Add the executable
cpp_add_executable(
    travel_cost_calc
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/travel_cost_calc"
    DEPENDS travel_cost_utils
)

# Build tests if build testing is enabled
if("${BUILD_TESTING}")
    # Get the Catch2 unit testing framework
    cpp_find_or_build_dependency(
        Catch2
        URL github.com/catchorg/Catch2
        BUILD_TARGET Catch2
        FIND_TARGET Catch2::Catch2
        CMAKE_ARGS BUILD_TESTING=OFF
    )

    # Add the tests
    cpp_add_tests(
        travel_cost_utils_test
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/test"
        DEPENDS travel_cost_utils Catch2::Catch2
    )
endif()
