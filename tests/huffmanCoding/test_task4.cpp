/**
 * @file test_task4.cpp
 * @brief Unit tests for task4.cpp
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* External Includes */

#include <gtest/gtest.h>

/* Standard Library Includes */

#include <cstddef>
#include <cstdlib>

/* Project Includes */

extern "C" {
#include "huffmanCoding/task3.h"
#include "huffmanCoding/task4.h"
}

/* Test Fixtures */

/**
 * @brief Letter-frequency pair linked list test fixture.
 *
 */
class Task4Test : public ::testing::Test {
 protected:
  sLetterFrequencyNode_t* psHead;
  const char* text = "to be or not to be";

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
 * @brief Test creating a letter-frequency pair linked list from a supplied
 * text.
 *
 */
TEST_F(Task4Test, test_createLetterFrequencyListFromText) {
  int retcode = createLetterFrequencyListFromText(&psHead, text);

  ASSERT_EQ(retcode, EXIT_SUCCESS);

  /* Assign pointers to the expected list order. */
  sLetterFrequencyNode_t* psO = psHead->psNext;
  sLetterFrequencyNode_t* psSpace = psO->psNext;
  sLetterFrequencyNode_t* psB = psSpace->psNext;
  sLetterFrequencyNode_t* psE = psB->psNext;
  sLetterFrequencyNode_t* psR = psE->psNext;
  sLetterFrequencyNode_t* psN = psR->psNext;

  /* Assert 't' count is correct. */
  ASSERT_EQ(psHead->sLetterFrequencyPair.character, 't');
  ASSERT_EQ(psHead->sLetterFrequencyPair.frequency, 3);

  /* Assert 'o' count is correct. */
  ASSERT_EQ(psO->sLetterFrequencyPair.character, 'o');
  ASSERT_EQ(psO->sLetterFrequencyPair.frequency, 4);

  /* Assert ' ' count is correct. */
  ASSERT_EQ(psSpace->sLetterFrequencyPair.character, ' ');
  ASSERT_EQ(psSpace->sLetterFrequencyPair.frequency, 5);

  /* Assert 'b' count is correct. */
  ASSERT_EQ(psB->sLetterFrequencyPair.character, 'b');
  ASSERT_EQ(psB->sLetterFrequencyPair.frequency, 2);

  /* Assert 'e' count is correct. */
  ASSERT_EQ(psE->sLetterFrequencyPair.character, 'e');
  ASSERT_EQ(psE->sLetterFrequencyPair.frequency, 2);

  /* Assert 'r' count is correct. */
  ASSERT_EQ(psR->sLetterFrequencyPair.character, 'r');
  ASSERT_EQ(psR->sLetterFrequencyPair.frequency, 1);

  /* Assert 'n' count is correct. */
  ASSERT_EQ(psN->sLetterFrequencyPair.character, 'n');
  ASSERT_EQ(psN->sLetterFrequencyPair.frequency, 1);
  ASSERT_EQ(psN->psNext, nullptr);
}
