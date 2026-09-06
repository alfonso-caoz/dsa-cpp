/**
 * @file test-reverse-words-in-a-string-iii.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/557-reverse-words-in-a-string-iii".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/557-reverse-words-in-a-string-iii/reverse-words-in-a-string-iii.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Input
    std::string s;
    // Expected Output
    std::string expected_reverseWords;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 557-reverse-words-in-a-string-iii (src folder)
TEST_P(SolutionParameterizedTestFixture, T557) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_reverseWords
  std::string actual_reverseWords = solution.reverseWords(test_param.s);

  // 3- Assert: actual_reverseWords vs expected_reverseWords
  EXPECT_EQ(actual_reverseWords, test_param.expected_reverseWords);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    ReverseWordsTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{"Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"},
        TestInputParam{"Mr Ding", "rM gniD"}
    )
);
