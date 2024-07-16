/**
 * @file test_average.cpp
 * @brief Unit tests for average.c.
 * @date 2024-07-13
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* External Includes */

#include <gtest/gtest.h>

/* Project Includes */

extern "C" {
#include "average/average.h"
}

/* Unit Tests */

/**
 * @brief Test calculating the average value of a float array.
 *
 */
TEST(AverageTest, testArrayAverage) {
  float array[] = {-1.0, 0.0, 1.0, 2.0, 3.0};
  float avg = average(array, sizeof(array) / sizeof(array[0]));

  ASSERT_FLOAT_EQ(avg, 1.0);
}

/**
 * @brief Test calculating the average value of an empty float array.
 *
 */
TEST(AverageTest, testEmptyArrayAverage) {
  float array[1];
  float avg = average(array, 0);

  ASSERT_FLOAT_EQ(avg, 0.0);
}
