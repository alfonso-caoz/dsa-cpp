/**
 * @file test-roman-to-integer.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/13-roman-to-integer".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/13-roman-to-integer/roman-to-integer.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::string s;
    // Expected Output
    int expected_romanToInt;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 13-roman-to-integer (src folder)
TEST_P(SolutionParameterizedTestFixture, RomanToInt) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_romanToInt
  int actual_romanToInt = solution.romanToInt(test_param.s);

  // 3- Assert: actual_romanToInt vs expected_romanToInt
  EXPECT_EQ(actual_romanToInt, test_param.expected_romanToInt);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    RomanToIntTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{"III", 3},
        TestInputParam{"LVIII", 58},
        TestInputParam{"MCMXCIV", 1994}
    )
);
