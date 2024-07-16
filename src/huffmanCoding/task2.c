/**
 * @file task2.c
 * @brief Load the contents of a given text file into memory.
 * @date 2024-07-16
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* Standard Library Imports */
#include <stdio.h>
#include <stdlib.h>

/* Project Imports */

#include "huffmanCoding/task2.h"

/* Type Definitons */

/**< File pointer. */
typedef FILE *pFile_t;

/* Function Definitons */

/**
 * @brief Read a file's contents into a buffer.
 *
 * This function reads a file's contents into a string buffer. It returns
 * EXIT_FAILURE if unable to open or read from the file, otherwise it returns
 * EXIT_SUCCESS to indicate the file contents were successfully read into the
 * buffer. The function ensures the destination buffer is NULL terminated.
 *
 * @param[in] i_filePath The path to the file to read the contents of.
 * @param[out] o_dest The buffer to read the file contents into.
 * @return int EXIT_FAILURE if an error occurred reading the file contents, else
 * EXIT_SUCCESS
 */
int readTextFile(const char *i_filePath, char *o_dest) {
  // Check if the file could not be opened
  pFile_t pFile = fopen(i_filePath, "r");
  if (pFile == NULL) {
    perror("ERROR");
    return EXIT_FAILURE;
  }

  // Read the file and check if an error occurred during the operation
  size_t bytesRead = fread(o_dest, sizeof(char), MAX_FILE_SIZE - 1, pFile);
  if (ferror(pFile)) {
    perror("ERROR");
    (void)fclose(pFile);
    return EXIT_FAILURE;
  }

  // NULL terminate the string
  o_dest[bytesRead] = '\0';

  (void)fclose(pFile);

  return EXIT_SUCCESS;
}
