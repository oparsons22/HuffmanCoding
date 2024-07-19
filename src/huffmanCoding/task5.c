/**
 * @file task5.c
 * @brief Create and merge binary tree nodes.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* Standard Library Include */
#include <stdio.h>
#include <stdlib.h>

/* Project Includes */

#include "huffmanCoding/task3.h"
#include "huffmanCoding/task5.h"

/* Function Defintions */

sBinaryTreeNode_t *mergeBinaryTreeNodes(sBinaryTreeNode_t *i_psLeftChild,
                                        sBinaryTreeNode_t *i_psRightChild) {
  /* Allocate memory for the merged binary tree node. */
  sBinaryTreeNode_t *psParent =
      (sBinaryTreeNode_t *)malloc(sizeof(sBinaryTreeNode_t));
  if (psParent == NULL) {
    perror("ERROR");
    return NULL;
  }

  /* Allocate memory for merged binary tree node's letter-frequency pair. */
  psParent->psLetterFrequencyPair =
      (sLetterFrequencyPair_t *)malloc(sizeof(sLetterFrequencyPair_t));
  if (psParent->psLetterFrequencyPair == NULL) {
    perror("ERROR");
    free(psParent);
    return NULL;
  }

  psParent->psLetterFrequencyPair->frequency =
      i_psLeftChild->psLetterFrequencyPair->frequency +
      i_psRightChild->psLetterFrequencyPair->frequency;

  /* Assign the left and right child nodes. */
  psParent->psLeftChild = i_psLeftChild;
  psParent->psRightChild = i_psRightChild;

  return psParent;
}

void freeBinaryTree(sBinaryTreeNode_t *io_psRoot) {
  if (io_psRoot == NULL) {
    return;
  }

  /* Recursively free the left and right child nodes. */
  freeBinaryTree(io_psRoot->psLeftChild);
  freeBinaryTree(io_psRoot->psRightChild);

  if (io_psRoot->psLetterFrequencyPair != NULL) {
    free(io_psRoot->psLetterFrequencyPair);
  }

  /* Free the final root node. */
  free(io_psRoot);
}
