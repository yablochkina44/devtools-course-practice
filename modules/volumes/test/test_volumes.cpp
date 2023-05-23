// Copyright 2023 Tarasova Anastasiya

#include <gtest/gtest.h>
#include "include/Volumes.h"

TEST(Tarasova_Anastasiya_VolumesTest, test_cube) {
    // Arrange & Act
    double cube = Parallelepiped(2, 2, 2);
    // Assert
    ASSERT_EQ(cube, 8);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_parallelepiped) {
    // Arrange & Act
    double parallelepiped = Parallelepiped(9, 6, 2.8);
    // Assert
    ASSERT_EQ(parallelepiped, 151.2);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_parallelepiped) {
    // Arrange & Act & Assert
    ASSERT_THROW(Parallelepiped(9, 6, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_cone) {
    // Arrange & Act
    double cone = EllipticalCone(5, 6, 6);
    // Assert
    ASSERT_NEAR(cone, 188.49555, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_cone) {
    // Arrange & Act & Assert
    ASSERT_THROW(EllipticalCone(-1, 0, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, cone_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(EllipticalCone(4, 5.78, 9.6), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_truncated_cone) {
    // Arrange & Act
    double truncated_cone = TruncatedCone(5, 8, 8, 4.9, 4.9);
    // Assert
    ASSERT_NEAR(truncated_cone, 666.07000, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_truncated_cone) {
    // Arrange & Act & Assert
    ASSERT_THROW(TruncatedCone(-1, 0, 0, 8, 9), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, truncated_cone_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(TruncatedCone(4, 5.78, 9.6, 7, 6), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_truncated_cylinder) {
    // Arrange & Act
    double truncated_cylinder = TruncatedCylinder(12, 8.67, 9.56, 9.56);
    // Assert
    ASSERT_NEAR(truncated_cylinder, 2967.40031, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_truncated_cylinder) {
    // Arrange & Act & AssertAssert
    ASSERT_THROW(TruncatedCylinder(-1, 0, 0, 8), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, truncated_cylinder_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(TruncatedCylinder(4, 5.78, 9.6, 7), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_paraboloid) {
    // Arrange & Act
    double paraboloid = EllipticalParaboloid(5, 6.8, 4);
    // Assert
    ASSERT_NEAR(paraboloid, 213.62830, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_paraboloid) {
    // Arrange & Act & Assert
    ASSERT_THROW(EllipticalParaboloid(-1, 0, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, paraboloid_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(EllipticalParaboloid(4, 5.78, 9.6), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_ball) {
    // Arrange & Act
    double ball = Ellipsoid(6, 6, 6);
    // Assert
    ASSERT_NEAR(ball, 904.77868, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_ellipsoid) {
    // Arrange & Act
    double ellipsoid = Ellipsoid(6, 4, 2.7);
    // Assert
    ASSERT_NEAR(ellipsoid, 271.43360, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_ellipsoid) {
    // Arrange & Act & Assert
    ASSERT_THROW(Ellipsoid(-1, 8, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, ellipsoid_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(Ellipsoid(4, 8, 3), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_torus) {
    // Arrange & Act
    double torus = Torus(10, 5.7);
    // Assert
    ASSERT_NEAR(torus, 716.26926, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_torus) {
    // Arrange & Act & Assert
    ASSERT_THROW(Torus(0, -1), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, torus_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(Torus(5.7, 10), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_tetrahedron_int) {
    // Arrange & Act
    double tetrahedron = Tetrahedron(6);
    // Assert
    ASSERT_NEAR(tetrahedron, 25.45584, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_tetrahedron) {
    // Arrange & Act & Assert
    ASSERT_THROW(Tetrahedron(-1), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_tetrahedron_double) {
    // Arrange & Act
    double tetrahedron = Tetrahedron(6.78);
    // Assert
    ASSERT_NEAR(tetrahedron, 36.73016, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_octahedron_int) {
    // Arrange & Act
    double octahedron = Octahedron(54);
    // Assert
    ASSERT_NEAR(octahedron, 74229.24146, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_octahedron) {
    // Arrange & Act & Assert
    ASSERT_THROW(Octahedron(0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_octahedron_double) {
    // Arrange & Act
    double octahedron = Octahedron(0.67);
    // Assert
    ASSERT_NEAR(octahedron, 0.14178, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_dodecahedron_int) {
    // Arrange & Act
    double dodecahedron = Dodecahedron(4);
    // Assert
    ASSERT_NEAR(dodecahedron, 490.43961, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_dodecahedron) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(Dodecahedron(-8.9));
}

TEST(Tarasova_Anastasiya_VolumesTest, test_dodecahedron_double) {
    // Arrange & Act
    double dodecahedron = Dodecahedron(6.34);
    // Assert
    ASSERT_NEAR(dodecahedron, 1952.87003, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_icosahedron_int) {
    // Arrange & Act
    double icosahedron = Icosahedron(56);
    // Assert
    ASSERT_NEAR(icosahedron, 383140.54747, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_icosahedron) {
    // Arrange & Act & Assert
    ASSERT_THROW(Icosahedron(0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_icosahedron_double) {
    // Arrange & Act
    double icosahedron = Icosahedron(87.65);
    // Assert
    ASSERT_NEAR(icosahedron, 1469094.71281, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_cylinder) {
    // Arrange & Act
    double cylinder = EllipticalCylinder(6, 10, 6.78);
    // Assert
    ASSERT_NEAR(cylinder, 1277.99989, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_cylinder) {
    // Arrange & Act & Assert
    ASSERT_THROW(EllipticalCylinder(-1, 8, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, cylinder_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(EllipticalCylinder(4, 5, 9), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_tube) {
    // Arrange & Act
    double tube = Tube(6.937, 3, 5.6);
    // Assert
    ASSERT_NEAR(tube, 688.26962, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_tube) {
    // Arrange & Act & Assert
    ASSERT_THROW(Tube(-1, 8.6, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, tube_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(Tube(4, 5, 9), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_ball_segment) {
    // Arrange & Act
    double ball_segment = BallSegment(10.67, 10);
    // Assert
    ASSERT_NEAR(ball_segment, 2311.93311, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_ball_segment) {
    // Arrange & Act & Assert
    ASSERT_THROW(BallSegment(8.6, 0), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_ball_sector) {
    // Arrange & Act
    double ball_sector = BallSector(6.7, 3);
    // Assert
    ASSERT_NEAR(ball_sector, 282.05219, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_ball_sector) {
    // Arrange & Act & Assert
    ASSERT_THROW(BallSector(-0.7665, 1), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_ball_layer) {
    // Arrange & Act
    double ball_layer = BallLayer(2, 6.7, 4.89);
    // Assert
    ASSERT_NEAR(ball_layer, 436.75807, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_ball_layer) {
    // Arrange & Act & Assert
    ASSERT_THROW(BallLayer(-0.7665, 1, 4), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_pyramid) {
    // Arrange & Act
    double pyramid = Pyramid(8, 54.67);
    // Assert
    ASSERT_NEAR(pyramid, 145.78667, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_pyramid) {
    // Arrange & Act & Assert
    ASSERT_THROW(Pyramid(0, 1), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_truncated_pyramid) {
    // Arrange & Act
    double truncated_pyramid = TruncatedPyramid(8, 3.24, 2);
    // Assert
    ASSERT_NEAR(truncated_pyramid, 20.76156, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 incorrect_data_truncated_pyramid) {
    // Arrange & Act & Assert
    ASSERT_THROW(TruncatedPyramid(0, 1, 6), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_prizm) {
    // Arrange & Act
    double prizm = Prizm(5.78, 67);
    // Assert
    ASSERT_NEAR(prizm, 387.26, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_prizm) {
    // Arrange & Act & Assert
    ASSERT_THROW(Prizm(-7.56, 67), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, test_barrel) {
    // Arrange & Act
    double barrel = Barrel(8, 6.5);
    // Assert
    ASSERT_NEAR(barrel, 1662.93535, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest, incorrect_data_barrel) {
    // Arrange & Act & Assert
    ASSERT_THROW(Barrel(-1, -6), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, barrel_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(Barrel(4, 5), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 test_equilateral_trucated_pyramid) {
    // Arrange & Act
    double equilateral_trucated_pyramid = EquilateralTruncatedPyramid(6,
 10, 5, 4);
    // Assert
    ASSERT_NEAR(equilateral_trucated_pyramid, 350, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 incorrect_data_equilateral_trucated_pyramid) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralTruncatedPyramid(-1, -6, 0, 4), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 equilateral_trucated_pyramid_big_small) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralTruncatedPyramid(6,
 5, 10, 4), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 test_equilateral_trucated_pyramid_incorrect_edges) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralTruncatedPyramid(5, 10, 6, 2), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, equilateral_polyhedron) {
    // Arrange & Act
    double equilateral_polyhedron = EquilateralPolyhedron(6,
 4, 5, 4.33012702);
    // Assert
    ASSERT_NEAR(EquilateralPolyhedron(6, 4, 5, 4.33012702),
 125, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 incorrect_data_equilateral_polyhedron) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPolyhedron(-1, -6, 0, 4), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 equilateral_polyhedron_incorrect_edges) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPolyhedron(2, 10, 6, 7), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 equilateral_polyhedron_incorrect_vertexes) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPolyhedron(5, 1, 6, 2), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, equilateral_prizm) {
    // Arrange & Act
    double equilateral_prizm = EquilateralPrism(6, 10, 4);
    // Assert
    ASSERT_NEAR(equilateral_prizm, 600, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 incorrect_data_equilateral_prizm) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPrism(-1, 4, 0), std::string);
}


TEST(Tarasova_Anastasiya_VolumesTest,
 equilateral_prizm_incorrect_edges) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPrism(5, 10, 2), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest, equilateral_pyramid) {
    // Arrange & Act
    double equilateral_pyramid = EquilateralPyramid(6, 10, 4);
    // Assert
    ASSERT_NEAR(equilateral_pyramid, 200, 0.00001);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 incorrect_data_equilateral_pyramid) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPyramid(-1, -6, 4), std::string);
}

TEST(Tarasova_Anastasiya_VolumesTest,
 equilateral_pyramid_incorrect_edges) {
    // Arrange & Act & Assert
    ASSERT_THROW(EquilateralPyramid(5, 10, 2), std::string);
}
