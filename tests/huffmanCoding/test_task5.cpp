/**
 * @file test_task5.cpp
 * @brief Unit tests for task5.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* External Includes */

#include <gtest/gtest.h>

/* Standard Library Includes */

#include <stdio.h>
#include <stdlib.h>

/* Project Includes */

extern "C" {
#include "huffmanCoding/task3.h"
#include "huffmanCoding/task5.h"
}

/* Helper Function Prototypes */

class Task5Test : public ::testing::Test {
 protected:
  sBinaryTreeNode* psParent = NULL;
  sBinaryTreeNode_t* psLeftChild = NULL;
  sBinaryTreeNode_t* psRightChild = NULL;

  /**
   * @brief Initialise the left and right child nodes.
   *
   */
  void SetUp() override {
    /* Initialise the left child node. */
    psLeftChild = (sBinaryTreeNode_t*)malloc(sizeof(sBinaryTreeNode_t));
    psLeftChild->psLeftChild = NULL;
    psLeftChild->psRightChild = NULL;
    psLeftChild->psLetterFrequencyPair =
        (sLetterFrequencyPair_t*)malloc(sizeof(sLetterFrequencyPair_t));
    psLeftChild->psLetterFrequencyPair->character = 'a';
    psLeftChild->psLetterFrequencyPair->frequency = 2;

    /* Initialise the right child node. */
    psRightChild = (sBinaryTreeNode_t*)malloc(sizeof(sBinaryTreeNode_t));
    psRightChild->psLeftChild = NULL;
    psRightChild->psRightChild = NULL;
    psRightChild->psLetterFrequencyPair =
        (sLetterFrequencyPair_t*)malloc(sizeof(sLetterFrequencyPair_t));
    psRightChild->psLetterFrequencyPair->character = 'b';
    psRightChild->psLetterFrequencyPair->frequency = 3;
  }

  /**
   * @brief Free the binary tree memory.
   *
   */
  void TearDown() override { freeBinaryTree(psParent); }
};

/* Unit Tests */

/**
 * @brief Test merging two binary tree nodes.
 *
 */
TEST_F(Task5Test, test_mergeBinaryTreeNodes) {
  psParent = mergeBinaryTreeNodes(psLeftChild, psRightChild);

  /* Assert that the merged node was created. */
  ASSERT_NE(psParent, nullptr);

  /* Assert the merged node values are assigned correctly. */
  ASSERT_EQ(psParent->psLetterFrequencyPair->character, '\0');
  ASSERT_EQ(psParent->psLetterFrequencyPair->frequency, 5);
  ASSERT_EQ(psParent->psLeftChild, psLeftChild);
  ASSERT_EQ(psParent->psRightChild, psRightChild);
}

/**
 * @brief Test freeing a binary tree when the root node is a NULL pointer.
 *
 */
TEST_F(Task5Test, test_freeBinaryTree_NullRoot) {
  freeBinaryTree(psParent);

  ASSERT_EQ(psParent, nullptr);
}
