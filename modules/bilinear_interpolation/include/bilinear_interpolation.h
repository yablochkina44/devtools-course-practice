// Copyright 2023 Rezchikov Dmitrii

#ifndef MODULES_BILINEAR_INTERPOLATION_INCLUDE_BILINEAR_INTERPOLATION_H_
#define MODULES_BILINEAR_INTERPOLATION_INCLUDE_BILINEAR_INTERPOLATION_H_

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>

class BilinearInterpolator{
 private:
// void printMtx( std::vector<std::vector<int>> * src );
void findNearest(int newVecSize,
                int coord, int factor,
                int * l, int * r);
void linearInterpolationH(std::vector<std::vector<int>> * mtx, int yCoord,
                            int l, int r, int point);
void linearInterpolationV(std::vector<std::vector<int>> * mtx, int xCoord,
                            int l, int r, int point);
void bilinearInterpolation(std::vector<std::vector<int>> * newMatrix,
                            int yCoord, int xCoord, int factor);
 public:
void bilinearInterpolation(std::vector<std::vector<int>> * newMatrix,
                            int factor);
};

#endif  // MODULES_BILINEAR_INTERPOLATION_INCLUDE_BILINEAR_INTERPOLATION_H_
