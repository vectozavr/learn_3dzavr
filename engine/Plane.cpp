//
// Created by Иван Ильин on 19.01.2021.
//

#include "Plane.h"

Plane::Plane(const Triangle &tri) : _normal(tri.norm()), _point(tri[0]) {
}

Plane::Plane(const Vec3D &N, const Vec3D &P) : _normal(N.normalized()), _point(P) {
}

double Plane::distance(const Vec3D &point) const {
    // TODO: implement (lesson 4)
    return 0;
}

std::pair<Vec3D, double> Plane::intersection(const Vec3D &start, const Vec3D &end) const {
    double k;
    Vec3D res;

    // TODO: implement (lesson 4)

    return std::make_pair(res, k);
}

std::vector<Triangle> Plane::clip(const Triangle &tri) const {

    std::vector<Triangle> result;

    std::vector<Vec3D> insidePoints;
    std::vector<Vec3D> outsidePoints;

    double distances[3] = {distance(Vec3D(tri[0])),
                           distance(Vec3D(tri[1])),
                           distance(Vec3D(tri[2]))};

    for (int i = 0; i < 3; i++) {
        if (distances[i] >= 0) {
            insidePoints.emplace_back(tri[i]);
        } else {
            outsidePoints.emplace_back(tri[i]);
        }
    }

    if (insidePoints.size() == 1) {
        // TODO: implement (lesson 4)
    }

    if (insidePoints.size() == 2) {
        // TODO: implement (lesson 4)
    }

    if (insidePoints.size() == 3) {
        // TODO: implement (lesson 4)
    }

    return result;
}
