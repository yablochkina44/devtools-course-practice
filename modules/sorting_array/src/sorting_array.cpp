// Copyright 2023 Pashina Alina

#include "../include/sorting_array.h"

void SortInsert(double* Array, int ElemCounter) {
  double min;
  int resInd;
  if (ElemCounter != 0) {
    for (int currentIndex = 0; currentIndex < ElemCounter; currentIndex++) {
      min = Array[currentIndex];
      resInd = currentIndex;
      for (int otherIndex = currentIndex + 1; otherIndex < ElemCounter;
           otherIndex++) {
        if (Array[otherIndex] < min) {
          resInd = otherIndex;
          min = Array[otherIndex];
        }
      }
      Array[resInd] = Array[currentIndex];
      Array[currentIndex] = min;
    }
  }
}

int partitionSortQuick(double* arrayPart, int start, int pivot) {
  int startInd = start;
    int swapTemp;
    while (startInd < pivot) {
      if (arrayPart[startInd] > arrayPart[pivot] && startInd == pivot - 1) {
        swapTemp = arrayPart[startInd];
        arrayPart[startInd] = arrayPart[pivot];
        arrayPart[pivot] = swapTemp;
        pivot--;
      } else {
        if (arrayPart[startInd] > arrayPart[pivot]) {
          swapTemp = arrayPart[pivot - 1];
          arrayPart[pivot - 1] = arrayPart[pivot];
          arrayPart[pivot] = swapTemp;
          swapTemp = arrayPart[startInd];
          arrayPart[startInd] = arrayPart[pivot];
          arrayPart[pivot] = swapTemp;
        } else {
          startInd++;
        }
      }
    }
    return pivot;
}

void SortQuick(double* arr, int startInd, int endInd) {
  if (startInd < endInd) {
    int pivot = partitionSortQuick(arr, startInd, endInd);
    SortQuick(arr, startInd, pivot - 1);
    SortQuick(arr, pivot + 1, endInd);
  }
}
