/**
 * @file average.h
 * @brief Calculate the average of an array of floats.
 * @date 2024-07-13
 *
 * Copyright (c) 2024 Oliver Parsons
 */

#ifndef AVERAGE_H
#define AVERAGE_H

/* Standard Library Includes */

#include <stddef.h>

/* Function Prototypes */

/**
 * @brief Calculate the average of an array of floats.
 *
 * @param array The values to calculate the average of.
 * @param size The number of items in the array.
 * @return float The average value.
 */
extern float average(const float array[], size_t size);

#endif  // AVERAGE_H
