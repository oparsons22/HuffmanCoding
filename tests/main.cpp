/**
 * @file main.cpp
 * @brief Entry point for the Google Test framework.
 * @date 2024-07-13
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* External Includes */

#include <gtest/gtest.h>

/* Function Definitons. */

/**
 * @brief Runs all unit tests.
 *
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @return int 0 if all tests are successful, or 1 otherwise.
 */
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
