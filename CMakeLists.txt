############################## Project Setup ###################################

cmake_minimum_required(VERSION 3.28) # CMake Latest Installed Version
project(dsa-cpp)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Latest GoogleTest version: 1.17.0 (Apr 30, 2025)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

############################## Adding GTest Files ##############################
enable_testing()

# CMake Helper functions to use GoogleTest
include(GoogleTest)

# Function to build each module separately: a binary for each module/file
function(add_gtest_target test_name test_file)
  add_executable(${test_name} ${test_file})
  target_link_libraries(${test_name} GTest::gtest_main)
  gtest_discover_tests(${test_name}
    EXTRA_ARGS "--gtest_color=yes" "--gtest_print_time") # List the binaries to be executed individually with "ctest"
endfunction()

# Add new test files here
add_gtest_target(test-two-sum ./test/1-two-sum/test-two-sum.cpp)
add_gtest_target(test-roman-to-integer ./test/13-roman-to-integer/test-roman-to-integer.cpp)

################################################################################
