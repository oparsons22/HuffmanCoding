/**
 * @file task3.h
 * @brief Linked List data structure to store a list of letters-frequency pairs.
 * @date 2024-07-16
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef TASK3_H
#define TASK3_H

/* Standard Library Includes */

#include <stddef.h>

/* Type Definitions */

/**
 * @brief Data structure that stores a letter-frequency pair
 *
 */
typedef struct sLetterFrequencyPair {
  char character;
  size_t frequency;
} sLetterFrequencyPair_t;

/**
 * @brief Linked List that stores a list of letters-frequency pairs.
 */
typedef struct sLetterFrequencyNode {
  sLetterFrequencyPair_t sLetterFrequencyPair;
  struct sLetterFrequencyNode* psNext;
} sLetterFrequencyNode_t;

/* Function Prototypes */

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
extern int appendLetterFrequencyPair(char i_character, size_t i_frequency,
                                     sLetterFrequencyNode_t** io_psHead);

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
extern void freeLetterFrequencyPairList(sLetterFrequencyNode_t** io_psHead);

#endif /* TASK3_H */
