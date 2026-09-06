/**
 * @file test-majority-element.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/169-majority-element".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/169-majority-element/majority-element.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::vector<int> nums;
    // Expected Output
    int expected_majorityElement;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 169-majority-element (src folder)
TEST_P(SolutionParameterizedTestFixture, T169) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_majorityElement
  int actual_majorityElement = solution.majorityElement(test_param.nums);

  // 3- Assert: actual_majorityElement vs expected_majorityElement
  EXPECT_EQ(actual_majorityElement, test_param.expected_majorityElement);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    MajorityElementTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{3,2,3}, 3},
        TestInputParam{{2,2,1,1,1,2,2}, 2}
    )
);
