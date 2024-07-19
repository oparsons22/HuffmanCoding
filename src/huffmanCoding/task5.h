/**
 * @file task5.h
 * @brief Create and merge binary tree nodes.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* Project Includes */

#include "huffmanCoding/task3.h"

/* Type Defintions */

/**
 * @brief Letter-frequency pair binary tree node data structure.
 *
 */
typedef struct sBinaryTreeNode {
  sLetterFrequencyPair_t* psLetterFrequencyPair;
  struct sBinaryTreeNode* psRightChild;
  struct sBinaryTreeNode* psLeftChild;
} sBinaryTreeNode_t;

/* Function Prototypes */

extern sBinaryTreeNode_t* mergeBinaryTreeNodes(
    sBinaryTreeNode_t* i_psLeftChild, sBinaryTreeNode_t* i_psRightChild);

extern void freeBinaryTree(sBinaryTreeNode_t* io_psRoot);
