// Copyright 2024 Kachalov Mikhail
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;

TEST(CircleTest, SetRadius) {
    Circle circle(10);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 10);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * PI * 10);
    EXPECT_DOUBLE_EQ(circle.getArea(), PI * 10 * 10);
}

TEST(CircleTest, SetFerence) {
    Circle circle(10);
    circle.setFerence(2 * PI * 15);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 15);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * PI * 15);
    EXPECT_DOUBLE_EQ(circle.getArea(), PI * 15 * 15);
}

TEST(CircleTest, SetArea) {
    Circle circle(10);
    circle.setArea(PI * 20 * 20);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 20);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * PI * 20);
    EXPECT_DOUBLE_EQ(circle.getArea(), PI * 20 * 20);
}

TEST(TasksTest, SolveEarthAndRope) {
    double earthRadius = 6378100;
    double gap = solveEarthAndRope(earthRadius);
    EXPECT_NEAR(gap, 0.159154943, 1e-9);
}

TEST(TasksTest, SolveEarthAndRopeSmallRadius) {
    double smallRadius = 1;
    double gap = solveEarthAndRope(smallRadius);
    EXPECT_NEAR(gap, 0.159154943, 1e-9);
}

TEST(TasksTest, SolveSwimmingPool) {
    double poolRadius = 3;
    double walkwayWidth = 1;
    double totalCost = solveSwimmingPool(poolRadius, walkwayWidth);
    EXPECT_NEAR(totalCost, 75424.77796, 1e-2);
}

TEST(TasksTest, SolveSwimmingPoolDifferentSizes) {
    double poolRadius = 5;
    double walkwayWidth = 2;
    double totalCost = solveSwimmingPool(poolRadius, walkwayWidth);
    EXPECT_NEAR(totalCost, 207345.1151, 1e-2);
}

TEST(CircleTest, ZeroRadius) {
    Circle circle(0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0);
}

TEST(CircleTest, FractionalRadius) {
    Circle circle(2.5);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 2.5);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * PI * 2.5);
    EXPECT_DOUBLE_EQ(circle.getArea(), PI * 2.5 * 2.5);
}

TEST(CircleTest, SmallFerence) {
    Circle circle(1);
    circle.setFerence(1);
    EXPECT_NEAR(circle.getRadius(), 1 / (2 * PI), 1e-9);
    EXPECT_NEAR(circle.getArea(), PI * std::pow(1 / (2 * PI), 2), 1e-9);
}
