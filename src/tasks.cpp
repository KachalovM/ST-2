// Copyright 2024 Kachalov Mikhail
#include "circle.h"
#include "tasks.h"

double solveEarthAndRope(double earthRadius) {
    Circle earth(earthRadius);
    double newFerence = earth.getFerence() + 1;

    Circle ropeCircle(earthRadius);
    ropeCircle.setFerence(newFerence);

    double gap = ropeCircle.getRadius() - earth.getRadius();

    return gap;
}

double solveSwimmingPool(double poolRadius, double walkwayWidth) {
    Circle pool(poolRadius);
    Circle poolWithWalkway(poolRadius + walkwayWidth);

    double walkwayArea = poolWithWalkway.getArea() - pool.getArea();
    double concreteCost = walkwayArea * 1000;
    double fenceCost = poolWithWalkway.getFerence() * 2000;

    return fenceCost + concreteCost;
}
