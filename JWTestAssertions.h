#pragma once

#include "JWTestUtil.h"

/* Test Assertions */
#define EXPECT_EQUAL(A,B) checkResult((A)==(B), #A" == "#B, "Expected Equal", __FILE__, __LINE__)
#define EXPECT_STR_EQUAL(A,B) checkResult(std::string(A)==std::string(B), #A" == "#B, "Expected Equal", __FILE__, __LINE__)
#define EXPECT_TRUE(A) checkResult((A), #A, "Expected True", __FILE__, __LINE__)
#define EXPECT_FALSE(A) checkResult(!(A), #A, "Expected False", __FILE__, __LINE__)
#define TEST_INFO(A) testInfo((A), __FILE__, __LINE__)
#define TEST_FAIL(A) testFail((A), __FILE__, __LINE__)
