/**
 * @file test-valid-parentheses.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/20-valid-parentheses".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/20-valid-parentheses/valid-parentheses.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::string s;
    // Expected Output
    bool expected_isValid;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 20-valid-parentheses (src folder)
TEST_P(SolutionParameterizedTestFixture, T20) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_isValid
  bool actual_isValid = solution.isValid(test_param.s);

  // 3- Assert: actual_isValid vs expected_isValid
  EXPECT_EQ(actual_isValid, test_param.expected_isValid);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    IsValidTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{"()", true},
        TestInputParam{"()[]{}", true},
        TestInputParam{"(]", false},
        TestInputParam{"([])", true},
        TestInputParam{"([)]", false}
    )
);
