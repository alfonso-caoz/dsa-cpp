/**
 * @file test-longest-continuous-increasing-subsequence.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/674-longest-continuous-increasing-subsequence".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/674-longest-continuous-increasing-subsequence/longest-continuous-increasing-subsequence.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::vector<int> nums;
    // Expected Output
    int expected_findLengthOfLCIS;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 674-longest-continuous-increasing-subsequence (src folder)
TEST_P(SolutionParameterizedTestFixture, T674) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_findLengthOfLCIS
  int actual_findLengthOfLCIS = solution.findLengthOfLCIS(test_param.nums);

  // 3- Assert: actual_findLengthOfLCIS vs expected_findLengthOfLCIS
  EXPECT_EQ(actual_findLengthOfLCIS, test_param.expected_findLengthOfLCIS);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    FindLengthOfLCISTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{1,3,5,4,7}, 3},
        TestInputParam{{2,2,2,2,2}, 1}
    )
);
