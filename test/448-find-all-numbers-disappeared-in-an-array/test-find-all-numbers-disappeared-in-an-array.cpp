/**
 * @file test-find-all-numbers-disappeared-in-an-array.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/448-find-all-numbers-disappeared-in-an-array".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/448-find-all-numbers-disappeared-in-an-array/find-all-numbers-disappeared-in-an-array.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::vector<int> nums;
    // Expected Output
    std::vector<int> expected_findDisappearedNumbers;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 448-find-all-numbers-disappeared-in-an-array (src folder)
TEST_P(SolutionParameterizedTestFixture, T448) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_findDisappearedNumbers
  std::vector<int> actual_findDisappearedNumbers = solution.findDisappearedNumbers(test_param.nums);

  // 3- Assert: actual_findDisappearedNumbers vs expected_findDisappearedNumbers
  EXPECT_EQ(actual_findDisappearedNumbers, test_param.expected_findDisappearedNumbers);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    FindDisappearedNumbersTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{4,3,2,7,8,2,3,1}, {5,6}},
        TestInputParam{{1,1}, {2}}
    )
);
