############################## Project Setup ###################################

cmake_minimum_required(VERSION 3.28) # CMake Latest Installed Version
project(dsa-cpp)

set(CMAKE_CXX_STANDARD 23) # GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Forced to use the C++ standard set before

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
add_gtest_target(test-valid-parentheses ./test/20-valid-parentheses/test-valid-parentheses.cpp)
#add_gtest_target(test-merge-two-sorted-lists ./test/21-merge-two-sorted-lists/test-merge-two-sorted-lists.cpp) # Linked Lists
add_gtest_target(test-merge-sorted-array ./test/88-merge-sorted-array/test-merge-sorted-array.cpp)
add_gtest_target(test-linked-list-cycle ./test/141-linked-list-cycle/test-linked-list-cycle.cpp) # Linked Lists
#add_gtest_target(test-intersection-of-two-linked-lists ./test/160-intersection-of-two-linked-lists/test-intersection-of-two-linked-lists.cpp) # Linked Lists
add_gtest_target(test-majority-element ./test/169-majority-element/test-majority-element.cpp)
add_gtest_target(test-happy-number ./test/202-happy-number/test-happy-number.cpp)
add_gtest_target(test-isomorphic-strings ./test/205-isomorphic-strings/test-isomorphic-strings.cpp)
#add_gtest_target(test-invert-binary-tree ./test/226-invert-binary-tree/test-invert-binary-tree.cpp) # Linked Lists
add_gtest_target(test-valid-anagram ./test/242-valid-anagram/test-valid-anagram.cpp)
add_gtest_target(test-find-all-numbers-disappeared-in-an-array ./test/448-find-all-numbers-disappeared-in-an-array/test-find-all-numbers-disappeared-in-an-array.cpp)
add_gtest_target(test-reverse-words-in-a-string-iii ./test/557-reverse-words-in-a-string-iii/test-reverse-words-in-a-string-iii.cpp)
#add_gtest_target(test-subtree-of-another-tree ./test/572-subtree-of-another-tree/test-subtree-of-another-tree.cpp) # Linked Lists
#add_gtest_target(test-n-ary-tree-preorder-traversal ./test/589-n-ary-tree-preorder-traversal/test-n-ary-tree-preorder-traversal.cpp) # Linked Lists
add_gtest_target(test-can-place-flowers ./test/605-can-place-flowers/test-can-place-flowers.cpp)
add_gtest_target(test-longest-continuous-increasing-subsequence ./test/674-longest-continuous-increasing-subsequence/test-longest-continuous-increasing-subsequence.cpp)

################################################################################
