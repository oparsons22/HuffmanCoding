/**
 * @file test_task3.cpp
 * @brief Unit tests for task3.c.
 * @date 2024-07-16
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* External Includes */

#include <gtest/gtest.h>

/* Standard Library Includes */

#include <cstddef>

/* Project Includes */

extern "C" {
#include "huffmanCoding/task3.h"
}

/* Test Fixtures. */

/**
 * @brief Letter-frequency pair linked list test fixture.
 *
 */
class Task3Test : public ::testing::Test {
 protected:
  sLetterFrequencyNode_t* psHead;

  /**
   * @brief Initialise the head to NULL.
   *
   */
  void SetUp() override { psHead = NULL; }

  /**
   * @brief Free the letter-frequency linked list.
   *
   */
  void TearDown() override { freeLetterFrequencyPairList(&psHead); }
};

/* Unit Tests */

/**
 * @brief Test appending a sLetterFrequencyNode_t to an empty list.
 *
 */
TEST_F(Task3Test, test_appendLetterFrequencyPair_emptyList) {
  int retcode = appendLetterFrequencyPair('A', 2, &psHead);

  ASSERT_EQ(retcode, EXIT_SUCCESS);
  ASSERT_EQ(psHead->sLetterFrequencyPair.character, 'A');
  ASSERT_EQ(psHead->sLetterFrequencyPair.frequency, 2);
  ASSERT_EQ(psHead->psNext, nullptr);
}

/**
 * @brief Test appending a sLetterFrequencyNode_t to a non-empty list.
 *
 */
TEST_F(Task3Test, test_appendLetterFrequencyPair_nonEmptyList) {
  (void)appendLetterFrequencyPair('A', 2, &psHead);
  int retcode = appendLetterFrequencyPair('a', 3, &psHead);

  sLetterFrequencyNode_t* psTail = psHead->psNext;

  ASSERT_EQ(retcode, EXIT_SUCCESS);

  /* Ensure the head remains as the first node appended to the list. */
  ASSERT_EQ(psHead->sLetterFrequencyPair.character, 'A');
  ASSERT_EQ(psHead->sLetterFrequencyPair.frequency, 2);
  ASSERT_EQ(psHead->psNext, psTail);

  /* Ensure the new is appended to the end of the list. */
  ASSERT_EQ(psTail->sLetterFrequencyPair.character, 'a');
  ASSERT_EQ(psTail->sLetterFrequencyPair.frequency, 3);
  ASSERT_EQ(psTail->psNext, nullptr);
}

/**
 * @brief Test appending a sLetterFrequencyNode_t to a multi-item list.
 *
 */
TEST_F(Task3Test, test_appendLetterFrequencyPair_multiItemList) {
  sLetterFrequencyNode_t* psHead = NULL;

  (void)appendLetterFrequencyPair('A', 2, &psHead);
  (void)appendLetterFrequencyPair('a', 3, &psHead);
  int retcode = appendLetterFrequencyPair(' ', 5, &psHead);

  sLetterFrequencyNode_t* psMiddle = psHead->psNext;
  sLetterFrequencyNode_t* psTail = psMiddle->psNext;

  ASSERT_EQ(retcode, EXIT_SUCCESS);

  /* Ensure the head remains as the first node appended to the list. */
  ASSERT_EQ(psHead->sLetterFrequencyPair.character, 'A');
  ASSERT_EQ(psHead->sLetterFrequencyPair.frequency, 2);
  ASSERT_EQ(psHead->psNext, psMiddle);

  /* Ensure the second added node is between the head and third added node. */
  ASSERT_EQ(psMiddle->sLetterFrequencyPair.character, 'a');
  ASSERT_EQ(psMiddle->sLetterFrequencyPair.frequency, 3);
  ASSERT_EQ(psMiddle->psNext, psTail);

  /* Ensure the new is appended to the end of the list. */
  ASSERT_EQ(psTail->sLetterFrequencyPair.character, ' ');
  ASSERT_EQ(psTail->sLetterFrequencyPair.frequency, 5);
  ASSERT_EQ(psTail->psNext, nullptr);
}

/**
 * @brief Test freeing a sLetterFrequencyNode_t linked list.
 *
 */
TEST_F(Task3Test, test_freeLetterFrequencyPairList) {
  (void)appendLetterFrequencyPair('A', 2, &psHead);
  ASSERT_NE(psHead, nullptr);

  freeLetterFrequencyPairList(&psHead);
  ASSERT_EQ(psHead, nullptr);
}
