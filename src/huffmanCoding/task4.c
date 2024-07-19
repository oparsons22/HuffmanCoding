/**
 * @file task4.c
 * @brief Find the frequency of each letter in a supplied text.
 * @date 2024-07-19
 *
 * Copyright (c) 2024 Oliver Parsons
 *
 */

/* Standard Library Includes */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/* Project Includes */

#include "huffmanCoding/task3.h"
#include "huffmanCoding/task4.h"

/* Function Prototypes */

/**
 * @brief Count the frequency of a given character in the given text.
 *
 * This function iterates through each character in the given text and
 * increments a counter each time the character matches the given character in
 * the parameters.
 *
 * @param[in] i_character The character to count the frequency of.
 * @param[in] i_text The text to search for the character in.
 * @return size_t The frequency the character occurs in the text.
 */
static size_t countCharacterFrequency(char i_character, const char* i_text);

/**
 * @brief Check whether a letter-frequency pair node exists in a linked-list.
 *
 * This function iterates through the given linked list and checks if the
 * character of each node is the given character in the parameters.
 *
 * @param[in] i_character The character to search the linked list for.
 * @param[in] i_psHead The pointer to the head of the linked list.
 * @return true if the character has a node in the linked list.
 * @return false if the character does not have a node in the linked list.
 */
static bool characterFrequencyNodeExists(char i_character,
                                         sLetterFrequencyNode_t* i_psHead);

/* Function Defintions */

/**
 * @brief Count the frequency of a given character in the given text.
 *
 * This function iterates through each character in the given text and
 * increments a counter each time the character matches the given character in
 * the parameters.
 *
 * @param[in] i_character The character to count the frequency of.
 * @param[in] i_text The text to search for the character in.
 * @return size_t The frequency the character occurs in the text.
 */
size_t countCharacterFrequency(const char i_character, const char* i_text) {
  size_t frequency = 0;

  for (size_t i = 0; i_text[i] != '\0'; i++) {
    if (i_text[i] == i_character) {
      frequency++;
    }
  }

  return frequency;
}

/**
 * @brief Check whether a letter-frequency pair node exists in a linked-list.
 *
 * This function iterates through the given linked list and checks if the
 * character of each node is the given character in the parameters.
 *
 * @param[in] i_character The character to search the linked list for.
 * @param[in] i_psHead The pointer to the head of the linked list.
 * @return true if the character has a node in the linked list.
 * @return false if the character does not have a node in the linked list.
 */
bool characterFrequencyNodeExists(const char i_character,
                                  sLetterFrequencyNode_t* i_psHead) {
  sLetterFrequencyNode_t* psCurrent = i_psHead;

  while (psCurrent != NULL) {
    if (psCurrent->sLetterFrequencyPair.character == i_character) {
      return true;
    }
    psCurrent = psCurrent->psNext;
  }

  return false;
}

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
int createLetterFrequencyListFromText(sLetterFrequencyNode_t** io_psHead,
                                      const char* i_text) {
  for (size_t i = 0; i_text[i] != '\0'; i++) {
    char character = i_text[i];
    if (characterFrequencyNodeExists(character, *io_psHead)) {
      continue;
    }

    size_t frequency = countCharacterFrequency(character, i_text);
    if (appendLetterFrequencyPair(character, frequency, io_psHead) ==
        EXIT_FAILURE) {
      freeLetterFrequencyPairList(io_psHead);
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
