//
// Created by Иван Ильин on 14.01.2021.
//

#include <cmath>

#include "Camera.h"
#include "utils/Log.h"
#include "Consts.h"

std::vector<Triangle> Camera::project(std::shared_ptr<Mesh> mesh) {

    if (!_ready) {
        Log::log("Camera::project(): cannot project _tris without camera initialization ( Camera::init() ) ");
        return _triangles;
    }

    if (!mesh->isVisible()) {
        return this->_triangles;
    }

    Matrix4x4 M = mesh->model();
    Matrix4x4 V = Matrix4x4::View(left(), up(), lookAt(), position());

    for (auto &t : mesh->triangles()) {
        Triangle projected;

        // TODO: implement (lessons 2, 3, 4)

        _triangles.emplace_back(projected);
    }

    return this->_triangles;
}

void Camera::init(int width, int height, double fov, double ZNear, double ZFar) {
    // We need to init camera only after creation or changing width, height, fov, ZNear or ZFar.
    // Because here we calculate matrix that does not change during the motion of _objects or camera
    _aspect = (double) width / (double) height;
    Matrix4x4 P = Matrix4x4::Projection(fov, _aspect, ZNear, ZFar);
    Matrix4x4 S = Matrix4x4::ScreenSpace(width, height);

    _SP = S * P; // screen-space-projections matrix

    // This is planes for clipping _tris.
    // Motivation: we are not interest in _tris that we cannot see.
    _clipPlanes.emplace_back(Plane(Vec3D{0, 0, 1}, Vec3D{0, 0, ZNear})); // near plane
    _clipPlanes.emplace_back(Plane(Vec3D{0, 0, -1}, Vec3D{0, 0, ZFar})); // far plane

    double thetta1 = Consts::PI * fov * 0.5 / 180.0;
    double thetta2 = atan(_aspect * tan(thetta1));
    _clipPlanes.emplace_back(Plane(Vec3D{-cos(thetta2), 0, sin(thetta2)}, Vec3D{0, 0, 0})); // left plane
    _clipPlanes.emplace_back(Plane(Vec3D{cos(thetta2), 0, sin(thetta2)}, Vec3D{0, 0, 0})); // right plane
    _clipPlanes.emplace_back(Plane(Vec3D{0, cos(thetta1), sin(thetta1)}, Vec3D{0, 0, 0})); // down plane
    _clipPlanes.emplace_back(Plane(Vec3D{0, -cos(thetta1), sin(thetta1)}, Vec3D{0, 0, 0})); // up plane

    _ready = true;
    Log::log("Camera::init(): camera successfully initialized.");
}

std::vector<Triangle> Camera::sorted() {

    // Sort _tris from back to front
    // This is some replacement for Z-buffer
    // TODO: implement (lesson 3)

    return _triangles;
}

void Camera::clear() {
    // Cleaning all _tris and recalculation of View matrix
    _triangles.clear();
}
