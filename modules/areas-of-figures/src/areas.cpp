// Copyright 2023 Nikitin Aleksandr

#include "include/areas.h"

#include <stdbool.h>

#include <cmath>
#include <string>

Parallelepiped::Parallelepiped(double width_, double height_, double length_)
    : width(width_), height(height_), length(length_) {}

double Parallelepiped::area() {
  if (width <= 0 || height <= 0 || length <= 0)
    return 0;
  else
    return 2 * (length * width + length * height + width * height);
}

Cylinder::Cylinder(double radius_, double height_)
    : radius(radius_), height(height_) {}

double Cylinder::area() {
  if (radius <= 0 || height <= 0)
    return 0;
  else
    return 2 * 3.14 * radius * (height + radius);
}

Sphere::Sphere(double radius_) : radius(radius_) {}

double Sphere::area() {
  if (radius <= 0)
    return 0;
  else
    return 4 * 3.14 * radius * radius;
}
