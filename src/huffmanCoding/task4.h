/**
 * @file task4.h
 * @brief Find the frequency of each letter in a supplied text.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

#ifndef TASK4_H
#define TASK4_H

/* Project Includes */

#include "huffmanCoding/task3.h"

/* Function Prototypes */

/**
 * @brief Create a letter-frequency linked list from the given text.
 *
 * This functions iterates through each character in the given text, counts its
 * frequency and appends it to the list if it is not already present in the
 * list. If an error occurs allocating the memory for the new node, then the
 * list is freed and it returns EXIT_FAILURE.
 *
 * @param[inout] io_psHead The pointer to the pointer to the head of the list.
 * @param[in] i_text The text to create the linked list from.
 * @return int EXIT_SUCCESS if the list was created successfully, else
 * EXIT_FAILURE.
 */
extern int createLetterFrequencyListFromText(sLetterFrequencyNode_t** io_psHead,
                                             const char* i_text);

#endif  // TASK4_H
