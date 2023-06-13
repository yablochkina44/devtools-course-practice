// Copyright 2023 Rezchikov Dmitrii

#include <gtest/gtest.h>

#include "../include/bilinear_interpolation.h"


TEST(Bilinear_Interpolation, Can_do_practically_linear ) {
    std::vector<std::vector<int>> testOut = { {1, 0, 3, 0, 5 } };
    std::vector<std::vector<int>> expectedResult = { {1, 2, 3, 4, 5 } };
    /*=========================================================*/
    BilinearInterpolator bi;
    bi.bilinearInterpolation(&testOut, 2);
    /*=========================================================*/
    EXPECT_EQ(testOut, expectedResult);
}


TEST(Bilinear_Interpolation, Can_do_intended) {
    std::vector<std::vector<int>> testOut = {        {1,  0,  2,   0,   3 },
                                                     {0,  0,  0,   0,   0 },
                                                     {4,  0,  5,   0,   6 },
                                                     {0,  0,  0,   0,   0 },
                                                     {7,  0,  8,   0,   9 },
                                                     {0,  0,  0,   0,   0 },
                                                     {10, 0,  11,  0,   12} };
    std::vector<std::vector<int>> expectedResult = { {1,  2,  2,  3,  3 },
                                                     {3,  4,  4,  5,  5 },
                                                     {4,  5,  5,  6,  6 },
                                                     {6,  7,  7,  8,  8 },
                                                     {7,  8,  8,  9,  9 },
                                                     {9,  10, 10, 11, 11 },
                                                     {10, 11, 11, 12, 12} };
    /*=========================================================*/
    BilinearInterpolator bi;
    bi.bilinearInterpolation(&testOut, 2);
    /*=========================================================*/
    EXPECT_EQ(testOut, expectedResult);
}

TEST(Bilinear_Interpolation, Can_do_intended_2 ) {
    std::vector<std::vector<int>> testOut = {        {1,  0, 3,  0,  5 },
                                                     {0,  0, 0,  0,  0 },
                                                     {3,  0, 5,  0,  7 },
                                                     {0,  0, 0,  0,  0 },
                                                     {5,  0, 7,  0,  9 },
                                                     {0,  0, 0,  0,  0 },
                                                     {7,  0, 9,  0,  11} };

    std::vector<std::vector<int>> expectedResult = { {1,  2, 3,  4,  5 },
                                                     {2,  3, 4,  5,  6 },
                                                     {3,  4, 5,  6,  7 },
                                                     {4,  5, 6,  7,  8 },
                                                     {5,  6, 7,  8,  9 },
                                                     {6,  7, 8,  9,  10},
                                                     {7,  8, 9, 10,  11} };
    /*=========================================================*/
    BilinearInterpolator bi;
    bi.bilinearInterpolation(&testOut, 2);
    /*=========================================================*/
    EXPECT_EQ(testOut, expectedResult);
}
