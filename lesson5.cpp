//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"

class Lesson5 final : public Engine {
public:
    Lesson5() = default;

    void start() override {
        camera->rotateLeft(M_PI/6);

        // add sphere
        auto sphere = world->loadBody(ObjectNameTag("sphere"), "obj/sphere.obj");
        sphere->translate(Vec3D(20,-20,20));

        // set initial velocity
        sphere->setVelocity(Vec3D(-10, 20, 0));

        // apply gravity
        sphere->setAcceleration(Vec3D(0, -10, 0));

        setGlEnable(true);
    }
};

int main() {
    /*
     * EN:
     * TODO: implement velocity and acceleration of objects
     * You should work with the following file:
     *
     * engine/physics/RigidBody.cpp
     *
     * If you do it right, you will see a ball moving in gravity field
     *
     * RU:
     * TODO: реализуйте скорость и ускорение объектов
     * На этом уроке вам необходимо работать со следующим файлом:
     *
     * engine/physics/RigidBody.cpp
     *
     * Если вы всё сделали правильно, то увидите шар, движущийся в поле тяжести
     */

    Lesson5 l;
    l.create();
}