/**
 * @file test-happy-number.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/202-happy-number".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/202-happy-number/happy-number.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    int n;
    // Expected Output
    bool expected_isHappy;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 202-happy-number (src folder)
TEST_P(SolutionParameterizedTestFixture, T202) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_isHappy
  bool actual_isHappy = solution.isHappy(test_param.n);

  // 3- Assert: actual_isHappy vs expected_isHappy
  EXPECT_EQ(actual_isHappy, test_param.expected_isHappy);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    IsHappyTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{19, true},
        TestInputParam{2, false}
    )
);
