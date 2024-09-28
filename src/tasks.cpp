// Copyright 2024 Kachalov Mikhail
#include "tasks.h"
#include <limits>
#include "circle.h"

double solveEarthAndRope(double earthRadius, double addLength) {
    Circle earth(earthRadius);
    double newFerence = earth.getFerence() + addLength;

    Circle ropeCircle(earthRadius);
    ropeCircle.setFerence(newFerence);

    double gap = ropeCircle.getRadius() - earth.getRadius();

    return gap > 0 ? gap : 0;
}

double solveSwimmingPool(double poolRadius, double walkwayWidth) {
    if (poolRadius < 0 || walkwayWidth < 0) {
        return std::numeric_limits<double>::quiet_NaN();
    }

    Circle pool(poolRadius);
    Circle poolWithWalkway(poolRadius + walkwayWidth);

    double walkwayArea = poolWithWalkway.getArea() - pool.getArea();
    double concreteCost = walkwayArea * 1000;
    double fenceCost = poolWithWalkway.getFerence() * 2000;

    return fenceCost + concreteCost;
}
