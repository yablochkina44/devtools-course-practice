// Copyright 2023 Lapin Dmitriy

#include<utility>
#include<iostream>
#include<vector>
#include <limits>
std::pair<int, std::vector<double>> isIntersection(std::vector<double> plane,
    std::vector<double> dot, std::vector<double> direction) {
    double A = plane[0]*dot[0]+plane[1]*dot[1]+plane[2]*dot[2]+plane[3];
    double B = plane[0]*direction[0]+plane[1]*direction[1]
        +plane[2]*direction[2];
    if (abs(B) >= std::numeric_limits<double>::epsilon()) {
        // a straight line intersects a plane
        double t = -A / B;
        double x = dot[0] + t * direction[0];
        double y = dot[1] + t * direction[1];
        double z = dot[2] + t * direction[2];
        std::vector<double> result = { x, y, z };
        return std::pair<int, std::vector<double>>(0, result);
    } else {
        if (abs(A) < std::numeric_limits<double>::epsilon()) {
            // a straight line belongs a plane
            return std::pair<int,
                std::vector<double>>(1, std::vector<double>(0));
        } else {
            // a straight line parallel a plane
            return std::pair<int,
                std::vector<double>>(2, std::vector<double>(0));
        }
    }
    return std::pair<int,
        std::vector<double>>(2, std::vector<double>(0));
}
