//
// Created by Иван Ильин on 12.01.2021.
//

#include <cmath>
#include <cassert>

#include "Matrix4x4.h"
#include "../Consts.h"

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &matrix4X4) const {
    Matrix4x4 result = Matrix4x4::Zero();

    // TODO: implement  (lesson 1)

    return result;
}

Vec4D Matrix4x4::operator*(const Vec4D &point4D) const {
    // TODO: implement (lesson 1)
    return Vec4D();
}

Vec3D Matrix4x4::operator*(const Vec3D &vec) const {
    // TODO: implement (lesson 1)
    return Vec3D();
}

Matrix4x4 Matrix4x4::Identity() {
    Matrix4x4 result;

    // TODO: implement (lesson 1)

    return result;
}

Matrix4x4 Matrix4x4::Constant(double value) {
    Matrix4x4 result;

    // TODO: implement (lesson 1)

    return result;
}

Matrix4x4 Matrix4x4::Zero() {
    return Matrix4x4::Constant(0);
}

Matrix4x4 Matrix4x4::Scale(const Vec3D &factor) {
    Matrix4x4 s{};

    // TODO: implement (lesson 1)

    return s;
}

Matrix4x4 Matrix4x4::Translation(const Vec3D &v) {
    Matrix4x4 t{};

    // TODO: implement (lesson 1)

    return t;
}

Matrix4x4 Matrix4x4::RotationX(double rx) {
    Matrix4x4 Rx{};

    // TODO: implement (lesson 1)

    return Rx;
}

Matrix4x4 Matrix4x4::RotationY(double ry) {
    Matrix4x4 Ry{};

    // TODO: implement (lesson 1)

    return Ry;
}

Matrix4x4 Matrix4x4::RotationZ(double rz) {
    Matrix4x4 Rz{};

    // TODO: implement (lesson 1)

    return Rz;
}

Matrix4x4 Matrix4x4::Rotation(const Vec3D &r) {
    return RotationX(r.x()) * RotationY(r.y()) * RotationZ(r.z());
}

Matrix4x4 Matrix4x4::Rotation(const Vec3D &v, double rv) {
    Matrix4x4 Rv{};
    Vec3D nv(v.normalized());

    double c = cos(rv), s = sin(rv);

    Rv._arr[0][0] = c + (1.0 - c) * nv.x() * nv.x();
    Rv._arr[0][1] = (1.0 - c) * nv.x() * nv.y() - s * nv.z();
    Rv._arr[0][2] = (1.0 - c) * nv.x() * nv.z() + s * nv.y();

    Rv._arr[1][0] = (1.0 - c) * nv.x() * nv.y() + s * nv.z();
    Rv._arr[1][1] = c + (1.0 - c) * nv.y() * nv.y();
    Rv._arr[1][2] = (1.0 - c) * nv.y() * nv.z() - s * nv.x();

    Rv._arr[2][0] = (1.0 - c) * nv.z() * nv.x() - s * nv.y();
    Rv._arr[2][1] = (1.0 - c) * nv.z() * nv.y() + s * nv.x();
    Rv._arr[2][2] = c + (1.0 - c) * nv.z() * nv.z();

    Rv._arr[3][3] = 1.0;

    return Rv;
}

Matrix4x4 Matrix4x4::Projection(double fov, double aspect, double ZNear, double ZFar) {
    Matrix4x4 p{};

    // TODO: implement (lesson 2)

    return p;
}

Matrix4x4 Matrix4x4::ScreenSpace(int width, int height) {
    Matrix4x4 s{};

    // TODO: implement (lesson 2)

    return s;
}

Matrix4x4 Matrix4x4::View(const Vec3D &left, const Vec3D &up, const Vec3D &lookAt, const Vec3D &eye) {
    Matrix4x4 V = Zero();

    // TODO: implement (lesson 4)

    return V;
}

Vec3D Matrix4x4::x() const {
    return Vec3D(_arr[0][0], _arr[1][0], _arr[2][0]);
}

Vec3D Matrix4x4::y() const {
    return Vec3D(_arr[0][1], _arr[1][1], _arr[2][1]);
}

Vec3D Matrix4x4::z() const {
    return Vec3D(_arr[0][2], _arr[1][2], _arr[2][2]);
}

Vec3D Matrix4x4::w() const {
    return Vec3D(_arr[0][3], _arr[1][3], _arr[2][3]);
}

bool Matrix4x4::isNear(double a, double b) {
    return std::abs(a - b) < Consts::EPS;
}

void Matrix4x4::test() {
    // testing matrix-vector multiplication:
    Vec4D v(4, 2, 3, 1);

    Vec4D one = Matrix4x4::Identity()*v;
    assert(isNear(one.x(), 4) && isNear(one.y(), 2) && isNear(one.z(), 3) && isNear(one.w(), 1));

    Vec4D scale = Matrix4x4::Scale(Vec3D(1, 2, 3))*v;
    assert(isNear(scale.x(), 4) && isNear(scale.y(), 4) && isNear(scale.z(), 9) && isNear(scale.w(), 1));

    Vec4D zero = Matrix4x4::Zero()*v;
    assert(isNear(zero.x(), 0) && isNear(zero.y(), 0) && isNear(zero.z(), 0) && isNear(zero.w(), 0));

    Vec4D translated = Matrix4x4::Translation(Vec3D(5, 4, 3))*v;
    assert(isNear(translated.x(), 9) && isNear(translated.y(), 6) && isNear(translated.z(), 6) && isNear(translated.w(), 1));

    // testing matrix-matrix multiplication:
    Matrix4x4 c1 = Matrix4x4::Constant(5)*Matrix4x4::Identity();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            assert(isNear(c1._arr[i][j], 5));

    Matrix4x4 c2 = Matrix4x4::Zero()*Matrix4x4::Constant(1);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            assert(isNear(c2._arr[i][j], 0));

    Matrix4x4 c3 = Matrix4x4::Scale(Vec3D(3, 3, 3))*Matrix4x4::Identity();
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(i==j)
                if(i<3)
                    assert(isNear(c3._arr[i][j], 3));
                else
                    assert(isNear(c3._arr[i][j], 1));
            else
                assert(isNear(c3._arr[i][j], 0));

    // testing rotation matrices:
    Vec4D i(1, 0,0);
    Vec4D j(0, 1,0);
    Vec4D k(0, 0,1);

    // rotation X:
    Vec4D i_rx = Matrix4x4::RotationX(Consts::PI/2)*i;
    Vec4D j_rx = Matrix4x4::RotationX(Consts::PI/2)*j;
    Vec4D k_rx = Matrix4x4::RotationX(Consts::PI/2)*k;

    assert(i_rx == i);
    assert(j_rx == k);
    assert(k_rx == -j);

    // rotation Y:
    Vec4D i_ry = Matrix4x4::RotationY(Consts::PI/2)*i;
    Vec4D j_ry = Matrix4x4::RotationY(Consts::PI/2)*j;
    Vec4D k_ry = Matrix4x4::RotationY(Consts::PI/2)*k;

    assert(i_ry == -k);
    assert(j_ry == j);
    assert(k_ry == i);

    // rotation Z:
    Vec4D i_rz = Matrix4x4::RotationZ(Consts::PI/2)*i;
    Vec4D j_rz = Matrix4x4::RotationZ(Consts::PI/2)*j;
    Vec4D k_rz = Matrix4x4::RotationZ(Consts::PI/2)*k;

    assert(i_rz == j);
    assert(j_rz == -i);
    assert(k_rz == k);
}
