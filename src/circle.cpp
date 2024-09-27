// Copyright 2024 Kachalov Mikhail
#include "circle.h"
#include <cmath>
#include <cstdint>

const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = ference / (2 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    area = a;
    radius = std::sqrt(area / PI);
    ference = 2 * PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
