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

add_executable(test-two-sum ./test/1-two-sum/test-two-sum.cpp)
#add_executable(two-sum ./src/1-two-sum/two-sum.cpp)

target_link_libraries(
  test-two-sum
  #two-sum
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test-two-sum)

################################################################################
