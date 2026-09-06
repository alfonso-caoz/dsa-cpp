/**
 * @file isomorphic-strings.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/205-isomorphic-strings".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/205-isomorphic-strings/isomorphic-strings.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::string s;
    std::string t;
    // Expected Output
   bool expected_isIsomorphic;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 205-isomorphic-strings (src folder)
TEST_P(SolutionParameterizedTestFixture, T205) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_isIsomorphic
  bool actual_isIsomorphic = solution.isIsomorphic(test_param.s, test_param.t);

  // 3- Assert: actual_isIsomorphic vs expected_isIsomorphic
  EXPECT_EQ(actual_isIsomorphic, test_param.expected_isIsomorphic);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    IsIsomorphicTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{"egg", "add", true},
        TestInputParam{"f11", "b23", false},
        TestInputParam{"paper", "title", true}
    )
);
