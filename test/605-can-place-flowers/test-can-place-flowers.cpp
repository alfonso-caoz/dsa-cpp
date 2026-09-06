/**
 * @file test-can-place-flowers.cpp
 * @author Alfonso Castillo Orozco
 * @brief Testing solution "src/605-can-place-flowers".
 * @version 0.1
 * @date May 2026
 */

#include <gtest/gtest.h>
#include "../../src/605-can-place-flowers/can-place-flowers.cpp"

// Input/Output Struct (Template)
struct TestInputParam {
    // Inputs
    std::vector<int> flowerbed;
    int n;
    // Expected Output
    bool expected_canPlaceFlowers;
};

// Fixture Class: Solution Object + Input/Output Template
class SolutionParameterizedTestFixture : public ::testing::TestWithParam<TestInputParam> {
protected:
    Solution solution;
};

// Test Parameterized: 605-can-place-flowers (src folder)
TEST_P(SolutionParameterizedTestFixture, T605) {
  // 1- Arrange: Retrieve Struct TestInputParam
  auto test_param = GetParam();
  
  // 2- Act: actual_canPlaceFlowers
  bool actual_canPlaceFlowers = solution.canPlaceFlowers(test_param.flowerbed, test_param.n);

  // 3- Assert: actual_canPlaceFlowers vs expected_canPlaceFlowers
  EXPECT_EQ(actual_canPlaceFlowers, test_param.expected_canPlaceFlowers);
}

// Test Instantiated: Values to be Injected
INSTANTIATE_TEST_SUITE_P(
    CanPlaceFlowersTest,
    SolutionParameterizedTestFixture,
    ::testing::Values(
        // Test Cases from respective src README.md
        TestInputParam{{1,0,0,0,1}, 1, true},
        TestInputParam{{1,0,0,0,1}, 2, false}
    )
);
