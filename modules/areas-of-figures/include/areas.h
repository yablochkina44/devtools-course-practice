// Copyright 2023 Nikitin Aleksandr

#ifndef MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_H_
#define MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_H_

class Parallelepiped {
 public:
  Parallelepiped(double width_, double height_, double length_);
  double area();

 private:
  double width, height, length;
};

class Cylinder {
 public:
  Cylinder(double radius_, double height_);
  double area();

 private:
  double radius, height;
};

class Sphere {
 public:
  explicit Sphere(double radius_);
  double area();

 private:
  double radius;
};

#endif  // MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_H_
