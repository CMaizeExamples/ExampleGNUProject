include_guard()

#[[
# This function encapsulates the process of getting CMaize using CMake's
# FetchContent module. We have encapsulated it in a function so we can set
# the options for it's configure step without affecting the options for the
# parent project's configure step (namely we do not want to build CMaize's
# unit tests).
#]]
function(get_cmaize)
    include(FetchContent)
    set(build_testing_old "${BUILD_TESTING}")  # Store the old value
    set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(
         cmaize
         GIT_REPOSITORY https://github.com/CMakePP/CMaize
    )
    FetchContent_MakeAvailable(cmaize)
    set(BUILD_TESTING "${build_testing_old}" CACHE BOOL "" FORCE)  # Reset
endfunction()

# Call the function we just wrote to get CMaize
get_cmaize()

# Include CMaize
include(cpp/cpp)
