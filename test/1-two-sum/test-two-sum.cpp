/**
 * @file test-two-sum.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/1-two-sum".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/1-two-sum/two-sum.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::vector<int> nums;
    int target;
    // Expected Output
    std::vector<int> expected_twoSum;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 1-two-sum (src folder)
TEST_P(SolutionParameterizedTestFixture, TwoSum) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_twoSum
  std::vector<int> actual_twoSum = solution.twoSum(test_param.nums, test_param.target);

  // 3- Assert: actual_twoSum vs expected_twoSum
  EXPECT_EQ(actual_twoSum, test_param.expected_twoSum);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    TwoSumTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{2,7,11,15}, 9, {0,1}},
        TestInputParam{{3,2,4}, 6, {1,2}},
        TestInputParam{{3,3}, 6, {0,1}}
    )
);
