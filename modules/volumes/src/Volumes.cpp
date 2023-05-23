// Copyright 2023 Tarasova Anastasiya
#include "include/Volumes.h"
#include <string>
#include <cmath>

double TruncatedCone(const double& Height, const double& BigMajorSemiaxis,
 const double& BigSmallSemiaxis, const double& SmallMajorSemiaxis,
 const double& SmallSmallSemiaxis) {
    if (Height <= 0 || BigMajorSemiaxis <= 0
|| BigSmallSemiaxis <= 0 || SmallMajorSemiaxis <= 0
|| SmallSmallSemiaxis <= 0|| BigMajorSemiaxis < BigSmallSemiaxis
|| BigMajorSemiaxis < SmallMajorSemiaxis
|| BigMajorSemiaxis < SmallSmallSemiaxis
|| BigSmallSemiaxis < SmallSmallSemiaxis
|| SmallMajorSemiaxis < SmallSmallSemiaxis) {
        throw std::string("Incorrect data");
    }
    double V = EllipticalCone((BigMajorSemiaxis*Height)/(
BigMajorSemiaxis - SmallMajorSemiaxis), BigMajorSemiaxis,
BigSmallSemiaxis) - EllipticalCone((SmallMajorSemiaxis * Height
) / (BigMajorSemiaxis - SmallMajorSemiaxis),
 SmallMajorSemiaxis, SmallSmallSemiaxis);
    return V;
}

double BallSegment(const double& Radius, const double& Height) {
    if (Radius <= 0 || Height <= 0) {
        throw std::string("Incorrect data");
    }
    double V = (3.1415926535 *Height*(Height*Height+3*Radius*Radius))/6;
    return V;
}

double BallSector(const double& BallRadius, const double& SegmentHeight) {
    if (BallRadius <= 0 || SegmentHeight <= 0) {
        throw std::string("Incorrect data");
    }
    double V = (2*3.1415926535 * BallRadius * BallRadius*SegmentHeight)/3;
    return V;
}

double BallLayer(const double& Radius1, const double& Radius2,
 const double& Height) {
    if (Radius1 <= 0 || Height <= 0 || Radius2 <= 0) {
        throw std::string("Incorrect data");
    }
    double V = (3.1415926535 * Height * (
Radius1 * Radius1 + Radius2 * Radius2 + (Height * Height) / 3)) / 2;
    return V;
}

double EquilateralPyramid(const double& Height, const double& Side,
 const int& Edges) {
    if (Side <= 0 || Height <= 0 || Edges < 3) {
        throw std::string("Incorrect data");
    }
    double V = (Edges * Side * Side * Height) / (
12 * tan(3.1415926535 / Edges));
    return V;
}

double Tetrahedron(const double& Side) {
    if (Side <= 0) {
        throw std::string("Incorrect data");
    }
    double V = (Side * Side * Side * sqrt(2)) / 12;
    return V;
}

double Parallelepiped(const double& Side1, const double& Side2,
 const double& Side3) {
    if (Side1 <= 0 || Side2 <= 0 || Side3 <= 0) {
        throw std::string("Incorrect data");
    }
    double V = Side1 * Side2 * Side3;
    return V;
}

double TruncatedCylinder(const double& BigHeight, const double& SmallHeight,
 const double& MajorSemiaxis, const double& SmallSemiaxis) {
    if (MajorSemiaxis <= 0 || BigHeight <= 0
|| SmallSemiaxis <= 0 || SmallHeight <= 0
|| SmallSemiaxis > MajorSemiaxis || SmallHeight > BigHeight) {
        throw std::string("Incorrect data");
    }
    double V = (3.1415926535 * MajorSemiaxis * SmallSemiaxis * (
SmallHeight + BigHeight)) / 2;
    return V;
}

double EquilateralPrism(const double& Height, const double& Side,
 const int& Edges) {
    if (Side <= 0 || Height <= 0 || Edges < 3) {
        throw std::string("Incorrect data");
    }
    double V = (Edges * Side * Side * Height * (1 / tan(
3.1415926535 / Edges))) / 4;
    return V;
}

double Torus(const double& OuterRadius, const double& InnerRadius) {
    if (OuterRadius <= 0 || InnerRadius <= 0
|| OuterRadius < InnerRadius) {
        throw std::string("Incorrect data");
    }
    double V = (3.1415926535 * 3.1415926535 *(
OuterRadius+InnerRadius)*(OuterRadius - InnerRadius)*(
OuterRadius - InnerRadius))/4;
    return V;
}

double Barrel(const double& BallRadius, const double& BarrelRadius) {
    if (BallRadius <= 0 || BarrelRadius <=0
|| BallRadius < BarrelRadius) {
        throw std::string("Incorrect data");
    }
    double V = (2* 3.1415926535 *sqrt(
BallRadius*BallRadius - BarrelRadius*BarrelRadius)*(
2*BallRadius*BallRadius+BarrelRadius*BarrelRadius))/3;
    return V;
}

double Tube(const double& OuterRadius, const double& InnerRadius,
 const double& Height) {
    if (OuterRadius <= 0 || Height <= 0 || InnerRadius <=0
|| InnerRadius >= OuterRadius) {
        throw std::string("Incorrect data");
    }
    double V = EllipticalCylinder(Height, OuterRadius,
 OuterRadius) - EllipticalCylinder(Height, InnerRadius, InnerRadius);
    return V;
}

double Ellipsoid(const double& MajorSemiaxis,
 const double& MiddleSemiaxis, const double& SmallSemiaxis) {
    if (MajorSemiaxis <= 0 || MiddleSemiaxis <= 0
|| SmallSemiaxis <= 0 || MajorSemiaxis < MiddleSemiaxis
|| MajorSemiaxis < SmallSemiaxis || MiddleSemiaxis < SmallSemiaxis) {
        throw std::string("Incorrect data");
    }
  double V = (
4 * 3.1415926535 * MajorSemiaxis * MiddleSemiaxis * SmallSemiaxis) / 3;
    return V;
}

double EllipticalParaboloid(const double& Height,
 const double& MajorSemiaxis, const double& SmallSemiaxis) {
    if (MajorSemiaxis <= 0 || Height <= 0 || SmallSemiaxis <= 0
|| SmallSemiaxis > MajorSemiaxis) {
        throw std::string("Incorrect data");
    }
    double V = (3.1415926535 * MajorSemiaxis * SmallSemiaxis * Height) / 2;
    return V;
}

double EllipticalCone(const double& Height,
 const double& MajorSemiaxis, const double& SmallSemiaxis) {
    if (MajorSemiaxis <= 0 || Height <= 0 || SmallSemiaxis <=0
|| SmallSemiaxis > MajorSemiaxis) {
        throw std::string("Incorrect data");
    }
    double V = (3.1415926535 * MajorSemiaxis * SmallSemiaxis * Height) / 3;
    return V;
}

double EllipticalCylinder(const double& Height, const double& MajorSemiaxis,
 const double& SmallSemiaxis) {
    if (MajorSemiaxis <= 0 || Height <= 0 || SmallSemiaxis <= 0
|| SmallSemiaxis > MajorSemiaxis) {
        throw std::string("Incorrect data");
    }
    double V = 3.1415926535 * MajorSemiaxis * SmallSemiaxis * Height;
    return V;
}

double EquilateralTruncatedPyramid(const double& Height,
 const double& BigSide, const double& SmallSide,
 const int& Edges) {
    if (BigSide <= 0 || Height <= 0 || SmallSide <= 0
|| Edges < 3 || SmallSide > BigSide) {
        throw std::string("Incorrect data");
    }
    double V = EquilateralPyramid((BigSide*Height)/(
BigSide - SmallSide), BigSide, Edges) - EquilateralPyramid(
(SmallSide * Height) / (BigSide - SmallSide), SmallSide, Edges);
    return V;
}

double Octahedron(const double& Side) {
    if (Side <= 0) {
        throw std::string("Incorrect data");
    }
    double V = (sqrt(2) * Side * Side * Side) / 3;
    return V;
}

double Dodecahedron(const double& Side) {
    if (Side <= 0) {
        throw std::string("Incorrect data");
    }
    double V = ((15 + 7 * sqrt(5)) * Side * Side * Side) / 4;
    return V;
}

double Icosahedron(const double& Side) {
    if (Side <= 0) {
        throw std::string("Incorrect data");
    }
    double V = ((15 + 5 * sqrt(5)) * Side * Side * Side) / 12;
    return V;
}

double EquilateralPolyhedron(const int& Edges,
 const int& Vertexes, const double& Side,
 const double& DescribedSphereRadius) {
    if (Side <= 0 || DescribedSphereRadius <= 0
|| Vertexes < 3 || Edges < 4) {
        throw std::string("Incorrect data");
    }
    double V = (Edges * sqrt(DescribedSphereRadius * DescribedSphereRadius - (
(Side * (1 / sin(3.1415926535 / Vertexes))) * (Side * (
1 / sin(3.1415926535 / Vertexes)))) / 4) * Vertexes * Side * Side * (
1 / tan(3.1415926535 / Vertexes))) / 12;
    return V;
}

double Prizm(const double& Height, const double& Square) {
    if (Height <= 0 || Square <= 0) {
        throw std::string("Incorrect data");
    }
    double V = Height * Square;
    return V;
}

double Pyramid(const double& Height, const double& Square) {
    if (Height <= 0 || Square <= 0) {
        throw std::string("Incorrect data");
    }
    double V = (Height * Square) / 3;
    return V;
}

double TruncatedPyramid(const double& Height, const double& BigSquare,
 const double& SmallSquare) {
    if (Height <= 0 || BigSquare <= 0 || SmallSquare <= 0) {
        throw std::string("Incorrect data");
    }
    double V = Pyramid((Height * sqrt(BigSquare)) / (
sqrt(BigSquare) - sqrt(SmallSquare)), BigSquare) - Pyramid((Height * sqrt(
SmallSquare)) / (sqrt(BigSquare) - sqrt(SmallSquare)), SmallSquare);
    return V;
}
