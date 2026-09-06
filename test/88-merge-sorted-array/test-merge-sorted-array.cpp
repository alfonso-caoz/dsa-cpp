/**
 * @file test-merge-sorted-array.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/88-merge-sorted-array".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/88-merge-sorted-array/merge-sorted-array.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    // Expected Output
    std::vector<int> expected_merge;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 88-merge-sorted-array (src folder)
TEST_P(SolutionParameterizedTestFixture, T88) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_merge
  solution.merge(test_param.nums1, test_param.m, test_param.nums2, test_param.n);
  std::vector<int> actual_merge = test_param.nums1;

  // 3- Assert: actual_merge vs expected_merge
  EXPECT_EQ(actual_merge, test_param.expected_merge);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    MergeTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{1,2,3,0,0,0}, 3, {2,5,6}, 3, {1,2,2,3,5,6}},
        TestInputParam{{1}, 1, {}, 0, {1}},
        TestInputParam{{0}, 0, {1}, 1, {1}}
    )
);
