/**
 * @file main.c
 * @author Oliver Parsons (oparsons22@gmail.com)
 * @brief Calculate the average of a float of arrays.
 * @date 2024-06-23
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* Standard Library Includes */

#include <stdio.h>
#include <stdlib.h>

/* Project Includes */

#include "average/average.h"

/*************************** Function Definitions  ****************************/

/**
 * @brief Program entry function.
 *
 * Calculate the average of a float of arrays and print it to the standard
 * output.
 *
 * @return EXIT_SUCCESS if successful, else EXIT_FAILURE.
 */
int main(void) {
  float array[] = {-1, 0, 1, 2, 3};
  float avg = average(array, sizeof(array) / sizeof(array[0]));
  printf("Average: %f\n", avg);
  return EXIT_SUCCESS;
}
