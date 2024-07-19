/**
 * @file task3.c
 * @brief Linked List data structure to store a list of letters-frequency pairs.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* Standard Library Includes */

#include <stdio.h>
#include <stdlib.h>

/* Project Includes */

#include "huffmanCoding/task3.h"

/* Function Definitons */

/**
 * @brief Append a new letter-frequency pair to a linked list.
 *
 * This function takes a character and frequency pair value and appends it to
 * the end of linked list specified by the head parameter. If it is unable to
 * allocate the memory for the new node then it returns EXIT_FAILURE. If the
 * list is empty, then the new node is set to the head of the list, otherwise it
 * is appended to the end.
 *
 * @param[in] i_character The letter-frequency pair character value.
 * @param[in] i_frequency The letter-frequency pair frequency value.
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 * @return int EXIT_SUCCESS if the node was added successfully, else
 * EXIT_FAILURE.
 */
int appendLetterFrequencyPair(const char i_character, size_t i_frequency,
                              sLetterFrequencyNode_t** io_psHead) {
  /* Allocate memory for the new node. */
  sLetterFrequencyNode_t* psLetterFrequencyNode =
      (sLetterFrequencyNode_t*)malloc(sizeof(sLetterFrequencyNode_t));

  if (psLetterFrequencyNode == NULL) {
    perror("ERROR");
    free(psLetterFrequencyNode);
    return EXIT_FAILURE;
  }

  /* Assign the letter frequency pair values. */
  psLetterFrequencyNode->sLetterFrequencyPair.character = i_character;
  psLetterFrequencyNode->sLetterFrequencyPair.frequency = i_frequency;
  psLetterFrequencyNode->psNext = NULL;

  if (*io_psHead == NULL) {
    /* Make the new node the head if the list is empty. */
    *io_psHead = psLetterFrequencyNode;
  } else {
    /* Append the new node to the end of the list. */
    sLetterFrequencyNode_t* psCurrent = *io_psHead;
    while (psCurrent->psNext != NULL) {
      psCurrent = psCurrent->psNext;
    }
    psCurrent->psNext = psLetterFrequencyNode;
  }

  return EXIT_SUCCESS;
}

/**
 * @brief Free the allocated memory of a letter-frequency pair linked list.
 *
 * This function frees the memory that was dynamically allocated to a
 * letter-frequency pair linked list. It iterates through each item in the list,
 * freeing its memory. The head of the list is dereferenced to NULL before
 * returning.
 *
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 */
void freeLetterFrequencyPairList(sLetterFrequencyNode_t** io_psHead) {
  sLetterFrequencyNode_t* psCurrent = *io_psHead;
  sLetterFrequencyNode_t* psNext = NULL;

  while (psCurrent != NULL) {
    psNext = psCurrent->psNext;
    free(psCurrent);
    psCurrent = psNext;
  }

  /* Dereference the head. */
  *io_psHead = NULL;
}
