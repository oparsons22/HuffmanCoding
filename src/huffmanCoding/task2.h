/**
 * @file task2.h
 * @brief Load the contents of a given text file into memory.
 * @date 2024-07-16
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef TASK2_H
#define TASK2_H

/* Constants */

/**< The maximum number of bytes to read from the file. */
const int MAX_FILE_SIZE = 1024;

/* Function Prototypes */

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
extern int readTextFile(const char* i_filePath, char* o_dest);

#endif /* TASK2_H */
