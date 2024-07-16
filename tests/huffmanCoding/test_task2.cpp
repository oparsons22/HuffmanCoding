/**
 * @file test_task2.cpp
 * @brief Unit tests for task2.c.
 * @date 2024-07-16
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* External Includes */

#include <gtest/gtest.h>

/* Standard Library Includes */
#include <stdlib.h>

/* Project Includes */

extern "C" {
#include "huffmanCoding/task2.h"
}

/* Constants */

/**< The path to the simple text file for use in unit tests. */
static const char* FILE_PATH = "../../data/Example.txt";

/* Unit Tests */

/**
 * @brief Test successfully reading the contents of a text file.
 *
 */
TEST(Task2Test, test_readTextFile) {
  char fileContents[MAX_FILE_SIZE] = "";

  const int retcode = readTextFile(FILE_PATH, fileContents);

  ASSERT_EQ(retcode, EXIT_SUCCESS);
  ASSERT_STREQ(fileContents, "to be or not to be");
}

/**
 * @brief Test error reading a text file when fopen returns NULL.
 *
 */
TEST(Task2Test, test_readTextFile_NullFilePointer) {
  char fileContents[MAX_FILE_SIZE] = "";

  const int retcode = readTextFile("Example.txt", fileContents);

  ASSERT_EQ(retcode, EXIT_FAILURE);
  ASSERT_STREQ(fileContents, "");
}
