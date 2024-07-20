/**
 * @file test_task6.cpp
 * @brief Unit tests for task 6.
 * @date 2024-07-20
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* External Includes */

#include <gtest/gtest.h>

/* Standard Library Includes */

#include <stdio.h>
#include <stdlib.h>

#include <cstddef>
#include <cstdlib>

/* Project Includes */

extern "C" {
#include "huffmanCoding/task3.h"
#include "huffmanCoding/task4.h"
#include "huffmanCoding/task5.h"
#include "huffmanCoding/task6.h"
}

/* Test Fixtures */

class Task6Test : public ::testing::Test {
 protected:
  sBinaryTreeListNode_t* psHead = NULL;
  sBinaryTreeNode_t* psLowestFrequencyBinaryTreeNode = NULL;
  sLetterFrequencyNode_t* psLetterFrequencyHead = NULL;

  /**
   * @brief Initialise the pointers to NULL.
   *
   */
  void SetUp() override {
    psHead = NULL;
    psLowestFrequencyBinaryTreeNode = NULL;
    psLetterFrequencyHead = NULL;
  }

  /**
   * @brief Free the binary tree memory.
   *
   */
  void TearDown() override {
    freeBinaryTree(psLowestFrequencyBinaryTreeNode);
    freeBinaryTreeList(&psHead);
  }
};

/* Unit Tests */

/**
 * @brief Test creating a linked list of binary tree nodes from a linked list of
 * letter-frequency pairs.
 *
 */
TEST_F(Task6Test, test_createBinaryTreeNodeListFromLetterFrequencyPairList) {
  (void)createLetterFrequencyListFromText(&psLetterFrequencyHead,
                                          "xxxxyyzzzzzwww");
  int retcode = createBinaryTreeNodeListFromLetterFrequencyPairList(
      &psHead, psLetterFrequencyHead);

  ASSERT_EQ(retcode, EXIT_SUCCESS);

  ASSERT_EQ(psHead->psBinaryTreeNode->psLetterFrequencyPair->character, 'x');
  ASSERT_EQ(psHead->psBinaryTreeNode->psLetterFrequencyPair->frequency, 4);

  sBinaryTreeListNode_t* psY = psHead->psNext;
  ASSERT_EQ(psY->psBinaryTreeNode->psLetterFrequencyPair->character, 'y');
  ASSERT_EQ(psY->psBinaryTreeNode->psLetterFrequencyPair->frequency, 2);

  sBinaryTreeListNode_t* psZ = psY->psNext;
  ASSERT_EQ(psZ->psBinaryTreeNode->psLetterFrequencyPair->character, 'z');
  ASSERT_EQ(psZ->psBinaryTreeNode->psLetterFrequencyPair->frequency, 5);

  sBinaryTreeListNode_t* psW = psZ->psNext;
  ASSERT_EQ(psW->psBinaryTreeNode->psLetterFrequencyPair->character, 'w');
  ASSERT_EQ(psW->psBinaryTreeNode->psLetterFrequencyPair->frequency, 3);
}

/**
 * @brief Test attempting to create a binary tree node linked list when the
 * letter-frequency pair pointer is NULL.
 *
 */
TEST_F(
    Task6Test,
    test_createBinaryTreeNodeListFromLetterFrequencyPairList_NullLetterFrequencyPairHead) {
  int retcode =
      createBinaryTreeNodeListFromLetterFrequencyPairList(&psHead, NULL);

  ASSERT_EQ(retcode, EXIT_FAILURE);
  ASSERT_EQ(psHead, nullptr);
}

/**
 * @brief Test popping the binary tree node with the lowest frequency from the
 * list.
 *
 */
TEST_F(Task6Test, test_popLowestFrequencyBinaryTreeNode) {
  (void)createLetterFrequencyListFromText(&psLetterFrequencyHead,
                                          "xxxxyyzzzzzwww");
  (void)createBinaryTreeNodeListFromLetterFrequencyPairList(
      &psHead, psLetterFrequencyHead);

  psLowestFrequencyBinaryTreeNode = popLowestFrequencyBinaryTreeNode(&psHead);

  /* Assert the lowest frequency node was returned. */
  ASSERT_EQ(psLowestFrequencyBinaryTreeNode->psLetterFrequencyPair->character,
            'y');
  ASSERT_EQ(psLowestFrequencyBinaryTreeNode->psLetterFrequencyPair->frequency,
            2);

  /* Assert the lowest frequency node is removed from the list. */
  sBinaryTreeListNode_t* psCurrent = psHead;
  sBinaryTreeListNode_t* psNext = NULL;
  while (psCurrent != NULL) {
    psNext = psCurrent->psNext;
    ASSERT_NE(psCurrent->psBinaryTreeNode, psLowestFrequencyBinaryTreeNode);
    psCurrent = psNext;
  }
}

/**
 * @brief Test attempting to pop the binary tree node with the lowest frequency
 * from an empty list list.
 *
 */
TEST_F(Task6Test, test_popLowestFrequencyBinaryTreeNode_EmptyList) {
  psLowestFrequencyBinaryTreeNode = popLowestFrequencyBinaryTreeNode(&psHead);

  ASSERT_EQ(psLetterFrequencyHead, nullptr);
}

/**
 * @brief Test popping the binary tree node with the lowest frequency from a
 * single item list.
 *
 */
TEST_F(Task6Test, test_popLowestFrequencyBinaryTreeNode_singleItemList) {
  (void)createLetterFrequencyListFromText(&psLetterFrequencyHead, "xxxx");
  (void)createBinaryTreeNodeListFromLetterFrequencyPairList(
      &psHead, psLetterFrequencyHead);

  psLowestFrequencyBinaryTreeNode = popLowestFrequencyBinaryTreeNode(&psHead);

  /* Assert the lowest frequency node was returned. */
  ASSERT_EQ(psLowestFrequencyBinaryTreeNode->psLetterFrequencyPair->character,
            'x');
  ASSERT_EQ(psLowestFrequencyBinaryTreeNode->psLetterFrequencyPair->frequency,
            4);

  /* Assert the list is now empty. */
  ASSERT_EQ(psHead, nullptr);
}
