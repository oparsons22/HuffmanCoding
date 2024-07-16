/**
 * @file average.c
 * @brief Calculate the average of an array of floats.
 * @date 2024-07-13
 *
 * Copyright (c) 2024 Oliver Parsons
 */

/* Standard Library Includes */

#include <stddef.h>

/* Project Includes */

#include "average/average.h"

/* Function Definitions */

/**
 * @brief Calculate the average of an array of floats.
 *
 * @param array The values to calculate the average of.
 * @param size The number of items in the array.
 * @return float The average value.
 */
float average(const float array[], const size_t size) {
  float total = 0;

  if (size == 0) {
    return total;
  }

  for (size_t i = 0; i < size; i++) {
    total += array[i];
  }

  return total / (float)size;
}
