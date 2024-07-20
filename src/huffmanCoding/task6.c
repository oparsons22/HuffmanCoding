/**
 * @file task6.c
 * @brief Find the binary tree node with the lowest frequency.
 * @date 2024-07-20
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* Standard Library Includes */

#include <stdio.h>
#include <stdlib.h>

/* Project Includes */

#include "huffmanCoding/task3.h"
#include "huffmanCoding/task5.h"
#include "huffmanCoding/task6.h"

/* Function Prototypes */

/**
 * @brief Append a binary tree node to a binary tree node linked list.
 *
 * This function appends a new binary tree node to a binary tree node linked
 * list. It assigns the provided letter-frequency pair to the newly created
 * node. If the list is empty, then the new node is set as the head, otherwise
 * it is added to the end of the list. If unable to allocate the memory for the
 * new node, the it returns EXIT_FAILURE.
 *
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 * @param[in] i_psLetterFrequencyNode The pointer to the letter-frequency pair
 * to assign to the new node.
 * @return int EXIT_SUCCESS if the node was added successfully, else
 * EXIT_FAILURE
 */
static int appendBinaryTreeNode(
    sBinaryTreeListNode_t** io_psHead,
    sLetterFrequencyNode_t* i_psLetterFrequencyNode);

/* Function Defintions */

/**
 * @brief Append a binary tree node to a binary tree node linked list.
 *
 * This function appends a new binary tree node to a binary tree node linked
 * list. It assigns the provided letter-frequency pair to the newly created
 * node. If the list is empty, then the new node is set as the head, otherwise
 * it is added to the end of the list. If unable to allocate the memory for the
 * new node, the it returns EXIT_FAILURE.
 *
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 * @param[in] i_psLetterFrequencyNode The pointer to the letter-frequency pair
 * to assign to the new node.
 * @return int EXIT_SUCCESS if the node was added successfully, else
 * EXIT_FAILURE
 */
static int appendBinaryTreeNode(
    sBinaryTreeListNode_t** io_psHead,
    sLetterFrequencyNode_t* i_psLetterFrequencyNode) {
  if (io_psHead == NULL) {
    perror("ERROR: Head pointer is NULL");
    return EXIT_FAILURE;
  }

  if (i_psLetterFrequencyNode == NULL) {
    perror("ERROR: letter-frequency node is NULL");
    return EXIT_FAILURE;
  }

  /* Allocate the memory for the binary tree list node */
  sBinaryTreeListNode_t* psBinaryTreeListNode =
      (sBinaryTreeListNode_t*)malloc(sizeof(sBinaryTreeListNode_t));
  if (psBinaryTreeListNode == NULL) {
    perror("ERROR: Failed to allocate memory for binary tree list node");
    return EXIT_FAILURE;
  }

  /* Assign the binary tree node letter-frequency pair. */
  psBinaryTreeListNode->psBinaryTreeNode =
      (sBinaryTreeNode_t*)malloc(sizeof(sBinaryTreeNode_t));
  if (psBinaryTreeListNode->psBinaryTreeNode == NULL) {
    perror("ERROR: Failed to allocate memory for binary tree node");
    free(psBinaryTreeListNode);
    return EXIT_FAILURE;
  }

  /* Assign the binary tree node values */
  psBinaryTreeListNode->psNext = NULL;
  psBinaryTreeListNode->psBinaryTreeNode->psLetterFrequencyPair =
      &i_psLetterFrequencyNode->sLetterFrequencyPair;

  if (*io_psHead == NULL) {
    /* Make the new binary tree node the head if the list is empty. */
    *io_psHead = psBinaryTreeListNode;
  } else {
    /* Append the new binary tree node to the end of the list. */
    sBinaryTreeListNode_t* psCurrent = *io_psHead;
    while (psCurrent->psNext != NULL) {
      psCurrent = psCurrent->psNext;
    }
    psCurrent->psNext = psBinaryTreeListNode;
  }

  return EXIT_SUCCESS;
}

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
    sLetterFrequencyNode_t* i_psLetterFrequencyPairHead) {
  if (i_psLetterFrequencyPairHead == NULL) {
    perror("ERROR: Letter-frequency list head is NULL");
    return EXIT_FAILURE;
  }

  sLetterFrequencyNode_t* psCurrent = i_psLetterFrequencyPairHead;
  sLetterFrequencyNode_t* psNext = NULL;

  while (psCurrent != NULL) {
    psNext = psCurrent->psNext;
    if (appendBinaryTreeNode(io_psHead, psCurrent) == EXIT_FAILURE) {
      perror("ERROR: Unable to add binary tree list node");
      freeBinaryTreeList(io_psHead);
      return EXIT_FAILURE;
    }
    psCurrent = psNext;
  }

  return EXIT_SUCCESS;
}

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
sBinaryTreeNode_t* popLowestFrequencyBinaryTreeNode(
    sBinaryTreeListNode_t** io_psHead) {
  if (io_psHead == NULL || *io_psHead == NULL) {
    perror("ERROR: Binary tree list head is NULL");
    return NULL;
  }

  sBinaryTreeListNode_t* psCurrent = *io_psHead;
  sBinaryTreeListNode_t* psLowest = psCurrent;
  sBinaryTreeListNode_t* psPrev = NULL;
  sBinaryTreeListNode_t* psLowestPrev = NULL;

  /* Find the lowest frequency binary tree node. */
  while (psCurrent != NULL) {
    if (psCurrent->psBinaryTreeNode->psLetterFrequencyPair->frequency <
        psLowest->psBinaryTreeNode->psLetterFrequencyPair->frequency) {
      psLowestPrev = psPrev;
      psLowest = psCurrent;
    }
    psPrev = psCurrent;
    psCurrent = psCurrent->psNext;
  }

  /* Remove the lowest frequency node from the list. */
  if (psLowest == *io_psHead) {
    *io_psHead = psLowest->psNext;
  } else {
    psLowestPrev->psNext = psLowest->psNext;
  }
  psLowest->psNext = NULL;

  sBinaryTreeNode_t* psReturnNode = psLowest->psBinaryTreeNode;
  free(psLowest);
  return psReturnNode;
}

extern void freeBinaryTreeList(sBinaryTreeListNode_t** io_psHead) {
  sBinaryTreeListNode_t* psCurrent = *io_psHead;
  sBinaryTreeListNode_t* psNext = NULL;

  while (psCurrent != NULL) {
    psNext = psCurrent->psNext;
    freeBinaryTree(psCurrent->psBinaryTreeNode);
    free(psCurrent);
    psCurrent = psNext;
  }

  /* Dereference the head. */
  *io_psHead = NULL;
}
