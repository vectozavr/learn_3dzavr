//
// Created by Иван Ильин on 12.01.2021.
//

#include <cmath>
#include <stdexcept>
#include <cassert>

#include "Vec4D.h"
#include "../Consts.h"

Vec4D::Vec4D(double x, double y, double z, double w) {
    _arr_point[0] = x;
    _arr_point[1] = y;
    _arr_point[2] = z;
    _arr_point[3] = w;
}

Vec4D::Vec4D(const Vec4D &point4D) {
    _arr_point[0] = point4D.x();
    _arr_point[1] = point4D.y();
    _arr_point[2] = point4D.z();
    _arr_point[3] = point4D.w();
}

[[nodiscard]] Vec4D Vec4D::operator-() const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

bool Vec4D::operator==(const Vec4D &point4D) const {
    // TODO: implement (lesson 1)
    return true;
}

bool Vec4D::operator!=(const Vec4D &point4D) const {
    // TODO: implement (lesson 1)
    return true;
}

// Operations with Vec4D
Vec4D Vec4D::operator+(const Vec4D &point4D) const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

Vec4D Vec4D::operator-(const Vec4D &point4D) const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

Vec4D Vec4D::operator*(double number) const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

Vec4D Vec4D::operator/(double number) const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

// Other useful methods
double Vec4D::sqrAbs() const {
    // TODO: implement (lesson 1)
    return 1;
}

double Vec4D::abs() const {
    // TODO: implement (lesson 1)
    return 1;
}

Vec4D Vec4D::normalized() const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

bool Vec4D::isNear(double a, double b) {
    return std::abs(a - b) < Consts::EPS;
}

void Vec4D::test() {
    Vec4D a(1, 2, 3, 4);
    Vec4D b(3, 4, 5, 6);

    // testing copy constructor:
    Vec4D c(a);
    assert(isNear(c.x(), 1) && isNear(c.y(), 2) && isNear(c.z(), 3) && isNear(c.w(), 4));

    // testing assigment operator (=):
    c = b;
    assert(isNear(c.x(), 3) && isNear(c.y(), 4) && isNear(c.z(), 5)  && isNear(c.w(), 6));

    // testing .x() & .y() & .z() & .w() methods:
    assert(isNear(a.x(), 1) && isNear(a.y(), 2) && isNear(a.z(), 3) && isNear(a.w(), 4));
    assert(isNear(b.x(), 3) && isNear(b.y(), 4) && isNear(b.z(), 5) && isNear(b.w(), 6));

    // testing operator -Vec:
    Vec4D neg = -a;
    assert(isNear(neg.x(), -a.x()) && isNear(neg.y(), -a.y()) && isNear(neg.z(), -a.z()) && isNear(neg.w(), -a.w()));

    // testing == & != operators:
    assert(c != a && c == b);

    // testing operators +, -:
    Vec4D summ = a + b;
    assert(isNear(summ.x(), 4) && isNear(summ.y(), 6) && isNear(summ.z(), 8) && isNear(summ.w(), 10));
    Vec4D diff = a - b;
    assert(isNear(diff.x(), -2) && isNear(diff.y(), -2)  && isNear(diff.z(), -2) && isNear(diff.w(), -2));

    // testing scaling operators:
    Vec4D scale1 = a * 2;
    assert(isNear(scale1.x(), 2) && isNear(scale1.y(), 4) && isNear(scale1.z(), 6) && isNear(scale1.w(), 8));
    Vec4D scale2 = a / 2;
    assert(isNear(scale2.x(), 0.5) && isNear(scale2.y(), 1) && isNear(scale2.z(), 1.5) && isNear(scale2.w(), 2));

    // testing .abs() & .normalized() methods:
    assert(isNear(b.abs(), std::sqrt(86)));
    assert(isNear(b.normalized().abs(), 1));
}

