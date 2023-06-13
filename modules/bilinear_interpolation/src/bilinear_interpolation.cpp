// Copyright 2023 Rezchikov Dmitrii

#include "../include/bilinear_interpolation.h"

void BilinearInterpolator::findNearest(int newVecSize,
                                    int coord, int factor, int * l, int * r) {
    *l = floor(
        static_cast<double>(coord) / static_cast<double>(factor)) * factor;
    *r = ceil(
        static_cast<double>(coord) / static_cast<double>(factor)) * factor;
}

void BilinearInterpolator::linearInterpolationH(
    std::vector<std::vector<int>> * mtx, int yCoord, int l, int r, int point) {
    if ( r == l ) {
        return;
    }
    double denominator = (r - l);
    double lWeight = (r - point) / denominator,
            rWeight = (point - l) / denominator;
    (*mtx)[yCoord][point] =
    round((*mtx)[yCoord][l] * lWeight + ((*mtx)[yCoord][r] * rWeight));
}
void BilinearInterpolator::linearInterpolationV(
    std::vector<std::vector<int>> * mtx, int xCoord, int l, int r, int point) {
    double denominator = (r - l);
    double lWeight = (r - point) / denominator,
            rWeight = (point - l) / denominator;
    (*mtx)[point][xCoord] =
    round((*mtx)[l][xCoord] * lWeight + ((*mtx)[r][xCoord] * rWeight));
}

void BilinearInterpolator::bilinearInterpolation(
                            std::vector<std::vector<int>> * newMatrix,
                            int yCoord, int xCoord, int factor) {
    int l, r;
    findNearest(newMatrix->size(), yCoord, factor, &l, &r);
    int l1, r1;
    findNearest((*newMatrix)[l].size(),
                xCoord, factor, &l1, &r1);
    if ( l == r && l1 == r1 ) {
        return;
    }
    linearInterpolationH(newMatrix, l, l1, r1, xCoord);
    if (l != r) {
        findNearest((*newMatrix)[r].size(),
                    xCoord, factor, &l1, &r1);
        linearInterpolationH(newMatrix, r, l1, r1, xCoord);
        linearInterpolationV(newMatrix, xCoord, l, r, yCoord);
    }
}

void BilinearInterpolator::bilinearInterpolation(
                            std::vector<std::vector<int>> * newMatrix,
                            int factor) {
    for ( size_t i = 0; i < newMatrix->size(); ++i ) {
        for ( size_t j = 0; j < (*newMatrix)[i].size(); ++j ) {
            bilinearInterpolation(newMatrix, i, j, factor);
        }
    }
}
