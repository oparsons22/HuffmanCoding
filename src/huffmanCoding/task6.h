/**
 * @file task6.h
 * @brief Find the binary tree node with the lowest frequency.
 * @date 2024-07-20
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

#ifndef TASK6_H
#define TASK6_H

/* Project Includes */

#include "huffmanCoding/task3.h"
#include "huffmanCoding/task5.h"

/* Type Defintions */

/**
 * @brief Binary Tree Node linked list data structure.
 *
 */
typedef struct sBinaryTreeListNode {
  sBinaryTreeNode_t* psBinaryTreeNode;
  struct sBinaryTreeListNode* psNext;
} sBinaryTreeListNode_t;

/* Function Prototypes */

/**
 * @brief Create a binary tree node linked list from a letter-frequency pair
 * list.
 *
 * This function iterates through the provided letter-frequency pair linked
 * list, creates a new binary tree node with the pair, and appends the new
 * binary tree node list. If any errors occur, creating the new node or adding
 * it to the list, then it returns EXIT_FAILURE.
 *
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 * @param[in] i_psLetterFrequencyPairHead The pointer to the head of the
 * letter-frequency pair list.
 * @return int EXIT_SUCCESS if the list was created successfully, else
 * EXIT_FAILURE.
 */
extern int createBinaryTreeNodeListFromLetterFrequencyPairList(
    sBinaryTreeListNode_t** io_psHead,
    sLetterFrequencyNode_t* i_psLetterFrequencyPairHead);

extern sBinaryTreeNode_t* popLowestFrequencyBinaryTreeNode(
    sBinaryTreeListNode_t** io_psHead);
/**
 * @brief Pop the lowest frequency binary tree node from the list.
 *
 * This function iterates through the list of binary tree nodes and finds the
 * node with the lowest letter-frequency pair. This node is removed from the
 * list and returned as a pointer.
 *
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 * @return sBinaryTreeNode_t* The pointer to the binary tree node with the
 * lowest letter-frequency pair.
 */
extern void freeBinaryTreeList(sBinaryTreeListNode_t** io_psHead);

#endif  // TASK6_H
