// Copyright 2023 Bochkarev Vladimir

#include "../include/num_integral.h"

double NumIntegral::integral1D(double a, double b, int n,
const std::function<double(double)>& fun) {
    if (n < 1) {
        throw std::invalid_argument(
        "The number of segments n must be a natural number (n > 0)");
    }

    if (fun == nullptr) {
        throw std::invalid_argument("Incorrect function");
    }

    double result = 0;
    const double width = (b - a) / n;

    for (int i = 0; i < n; i++) {
        double x1 = a + i * width;
        double x2 = a + (i + 1) * width;
        result += 0.5 * (x2 - x1) * (fun(x1) + fun(x2));
    }

    return result;
}

double NumIntegral::integral2D(double a, double b, double c, double d,
int n, const std::function<double(double, double)>& fun) {
    if (n < 1) {
        throw std::invalid_argument(
        "The number of segments n must be a natural number (n > 0)");
    }

    if (fun == nullptr) {
        throw std::invalid_argument("Incorrect function");
    }

    double result = 0;
    const double widthX = (b - a) / n;
    const double widthY = (d - c) / n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            double x1 = a + i * widthX;
            double x2 = a + (i + 1) * widthX;

            double y1 = c + j * widthY;
            double y2 = c + (j + 1) * widthY;

            result += 0.5 * (x2 - x1) * (y2 - y1) * (fun(x1, y1) + fun(x2, y2));
        }

    return result;
}

double NumIntegral::integral3D(double a, double b, double c, double d,
double e, double f, int n,
const std::function<double(double, double, double)>& fun) {
    if (n < 1) {
        throw std::invalid_argument(
        "The number of segments n must be a natural number (n > 0)");
    }

    if (fun == nullptr) {
        throw std::invalid_argument("Incorrect function");
    }

    double result = 0;
    const double widthX = (b - a) / n;
    const double widthY = (d - c) / n;
    const double widthZ = (f - e) / n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                double x1 = a + i * widthX;
                double x2 = a + (i + 1) * widthX;

                double y1 = c + j * widthY;
                double y2 = c + (j + 1) * widthY;

                double z1 = e + k * widthZ;
                double z2 = e + (k + 1) * widthZ;

                result += 0.5 * (x2 - x1) * (y2 - y1) * (z2 - z1) *
                (fun(x1, y1, z1) + fun(x2, y2, z2));
            }

    return result;
}
