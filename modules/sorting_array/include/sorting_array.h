// Copyright 2023 Pashina Alina

#ifndef MODULES_SORTING_ARRAY_INCLUDE_SORTING_ARRAY_H_
#define MODULES_SORTING_ARRAY_INCLUDE_SORTING_ARRAY_H_

#include <vector>

//! @addtogroup quadrical-equal
//! @{

/**
 * @brief the class solves the quadratic equation for 3 cases
 *
 * the quadratic equation is an expression of the form ax^2+bx+c=0
 */

void SortInsert(double* Array, int ElemCounter);
int partitionSortQuick(double* arrayPart, int start, int pivot);
void SortQuick(double* Array, int startInd, int endInd);
//! @}

#endif  // MODULES_SORTING_ARRAY_INCLUDE_SORTING_ARRAY_H_
