/**
 * @file test-valid-anagram.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/242-valid-anagram".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/242-valid-anagram/valid-anagram.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::string s;
    std::string t;
    // Expected Output
    bool expected_isAnagram;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 242-valid-anagram (src folder)
TEST_P(SolutionParameterizedTestFixture, T242) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_isAnagram
  bool actual_isAnagram = solution.isAnagram(test_param.s, test_param.t);

  // 3- Assert: actual_isAnagram vs expected_isAnagram
  EXPECT_EQ(actual_isAnagram, test_param.expected_isAnagram);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    IsAnagramTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{"anagram", "nagaram", true},
        TestInputParam{"rat", "car", false}
    )
);
