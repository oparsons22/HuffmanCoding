/**
 * @file task5.h
 * @brief Create and merge binary tree nodes.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

#ifndef TASK5_H
#define TASK5_H

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

/**
 * @brief Merge two binary tree nodes together.
 *
 * This function takes two binary tree nodes and merges them, as per the Huffman
 * algorithm. The merged node frequency is set the the sum of the two child
 * nodes and points to the paramater nodes as it child nodes. The function
 * returns a NULL pointer if there were any errors allocating the memory for the
 * merged node.
 *
 * @param[in] i_psLeftChild Pointer to the merged node left child.
 * @param[in] i_psRightChild Pointer to the merged node right child.
 * @return sBinaryTreeNode_t* Pointer to the merged parent node.
 */
extern sBinaryTreeNode_t* mergeBinaryTreeNodes(
    sBinaryTreeNode_t* i_psLeftChild, sBinaryTreeNode_t* i_psRightChild);

/**
 * @brief Free the memory of a binary tree.
 *
 * This function recursively frees the allocated memory of each binary tree node
 * and its letter-frequency pair.
 *
 * @param[inout] io_psRoot The pointer to the binary tree root node.
 */
extern void freeBinaryTree(sBinaryTreeNode_t* io_psRoot);

#endif  // TASK5_H
