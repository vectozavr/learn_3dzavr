//
// Created by Иван Ильин on 05.02.2021.
//

#include <cmath>
#include <utility>
#include <limits>

#include "RigidBody.h"
#include "../utils/Log.h"
#include "../utils/Time.h"
#include "../Consts.h"

RigidBody::RigidBody(ObjectNameTag nameTag, const std::string &filename, const Vec3D &scale, bool useSimpleBox) : Mesh(std::move(nameTag),
                                                                                                    filename, scale),
                                                                                               _hitBox(*this, useSimpleBox) {
}

RigidBody::RigidBody(const Mesh &mesh, bool useSimpleBox) : Mesh(mesh), _hitBox(mesh, useSimpleBox) {
}

void RigidBody::updatePhysicsState() {
    // TODO: implement (lesson 5)
}

void RigidBody::setVelocity(const Vec3D &velocity) {
    // TODO: implement (lesson 5)
}

void RigidBody::addVelocity(const Vec3D &velocity) {
    // TODO: implement (lesson 5)
}

void RigidBody::setAcceleration(const Vec3D &acceleration) {
    // TODO: implement (lesson 5)
}

Vec3D RigidBody::_findFurthestPoint(const Vec3D &direction) {
    Vec3D maxPoint{0, 0, 0};
    double maxDistance = -std::numeric_limits<double>::max();

    for(auto & it : _hitBox) {
        // TODO: implement (lesson 6)
    }

    return maxPoint;
}

Vec3D RigidBody::_support(std::shared_ptr<RigidBody> obj, const Vec3D &direction) {
    // TODO: implement (lesson 6)

    return Vec3D();
}

NextSimplex RigidBody::_nextSimplex(const Simplex &points) {
    switch (points.type()) {
        case SimplexType::Line:
            return _lineCase(points);
        case SimplexType::Triangle:
            return _triangleCase(points);
        case SimplexType::Tetrahedron:
            return _tetrahedronCase(points);

        default:
            throw std::logic_error{"RigidBody::_nextSimplex: simplex is not Line, Triangle or Tetrahedron"};
    }
}

NextSimplex RigidBody::_lineCase(const Simplex &points) {
    Simplex newPoints(points);
    Vec3D newDirection;

    Vec3D a = points[0];
    Vec3D b = points[1];

    Vec3D ab = b - a;
    Vec3D ao = -a;

    // TODO: implement (lesson 6)

    return NextSimplex{newPoints, newDirection, false};
}

NextSimplex RigidBody::_triangleCase(const Simplex &points) {
    Simplex newPoints(points);
    Vec3D newDirection;

    Vec3D a = points[0];
    Vec3D b = points[1];
    Vec3D c = points[2];

    Vec3D ab = b - a;
    Vec3D ac = c - a;
    Vec3D ao = -a;

    // TODO: implement (lesson 6)

    return NextSimplex{newPoints, newDirection, false};
}

NextSimplex RigidBody::_tetrahedronCase(const Simplex &points) {
    Vec3D a = points[0];
    Vec3D b = points[1];
    Vec3D c = points[2];
    Vec3D d = points[3];

    Vec3D ab = b - a;
    Vec3D ac = c - a;
    Vec3D ad = d - a;
    Vec3D ao = -a;

    // TODO: implement (lesson 6)

    return NextSimplex{points, Vec3D(), true};
}

std::pair<bool, Simplex> RigidBody::checkGJKCollision(std::shared_ptr<RigidBody> obj) {
    // This is implementation of GJK algorithm for collision detection.
    // It builds a simplex (a simplest shape that can select point in space) around
    // zero for Minkowski Difference. Collision happened when zero point is inside.

    // Get initial support point in any direction
    Vec3D support = _support(obj, Vec3D{1, 0, 0});

    // Simplex is an array of points, max count is 4
    Simplex points{};
    points.push_front(support);

    // New direction is towards the origin
    Vec3D direction = -support;

    size_t iters = 0;
    while (iters++ < size() + obj->size()) {
        // TODO: implement (lesson 6)

        break;
    }
    return std::make_pair(false, points);
}

CollisionInfo RigidBody::EPA(const Simplex &simplex, std::shared_ptr<RigidBody> obj) {
    // This is implementation of EPA algorithm for solving collision.
    // It uses a simplex from GJK around and expand it to the border.
    // The goal is to calculate the nearest normal and the intersection depth.

    std::vector<Vec3D> polytope(simplex.begin(), simplex.end());
    std::vector<size_t> faces = {
            0, 1, 2,
            0, 3, 1,
            0, 2, 3,
            1, 3, 2
    };

    auto faceNormals = _getFaceNormals(polytope, faces);
    std::vector<FaceNormal> normals = faceNormals.first;
    size_t minFace = faceNormals.second;

    Vec3D minNormal = normals[minFace].normal;
    double minDistance = std::numeric_limits<double>::max();

    size_t iters = 0;
    while (minDistance == std::numeric_limits<double>::max() && iters++ < size() + obj->size()) {
        // TODO: implement (lesson 7)

        break;
    }

    _collisionNormal = minNormal;
    if (std::abs(minDistance - std::numeric_limits<double>::max()) < Consts::EPS) {
        return CollisionInfo{minNormal, 0};
    }

    return CollisionInfo{minNormal, minDistance + Consts::EPA_EPS, obj};
}

std::pair<std::vector<FaceNormal>, size_t>
RigidBody::_getFaceNormals(const std::vector<Vec3D> &polytope, const std::vector<size_t> &faces) {
    std::vector<FaceNormal> normals;
    normals.reserve(faces.size() / 3);
    size_t nearestFaceIndex = 0;
    double minDistance = std::numeric_limits<double>::max();

    for (size_t i = 0; i < faces.size(); i += 3) {
        Vec3D a = polytope[faces[i + 0]];
        Vec3D b = polytope[faces[i + 1]];
        Vec3D c = polytope[faces[i + 2]];

        Vec3D normal = (b - a).cross(c - a).normalized();

        double distance = normal.dot(a);

        if (distance < -Consts::EPS) {
            normal = -normal;
            distance *= -1;
        }

        normals.emplace_back(FaceNormal{normal, distance});

        if (distance < minDistance) {
            nearestFaceIndex = i / 3;
            minDistance = distance;
        }
    }

    return {normals, nearestFaceIndex};
}

std::vector<std::pair<size_t, size_t>>
RigidBody::_addIfUniqueEdge(const std::vector<std::pair<size_t, size_t>> &edges, const std::vector<size_t> &faces,
                            size_t a, size_t b) {

    std::vector<std::pair<size_t, size_t>> newEdges = edges;

    // We are interested in reversed edge
    //      0--<--3
    //     / \ B /   A: 2-0
    //    / A \ /    B: 0-2
    //   1-->--2

    // TODO: implement (lesson 7)

    return newEdges;
}

void RigidBody::solveCollision(const CollisionInfo &collision) {
    // TODO: implement (lesson 7)

    collisionCallBack(collision);
}
