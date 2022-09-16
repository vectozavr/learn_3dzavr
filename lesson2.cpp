//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"

class Lesson2 final : public Engine {
private:
    double rotationSpeed = 1;

    // add cube to the scene
    std::shared_ptr<RigidBody> cube = world->addBody(std::make_shared<RigidBody>(Mesh::Cube(ObjectNameTag("cube"), 3)));
public:
    Lesson2() = default;

    void start() override {
        // translate cube
        cube->translate(Vec3D(0,0,5));
    }

    void update() override {
        // rotate cube in every frame
        cube->rotate(Vec3D(0, rotationSpeed*Time::deltaTime(), 0));
    }
};

int main() {
    /*
     * EN:
     * TODO: implement objects transformations and projection on the screen
     * You should work with the following files:
     *
     * engine/Object.cpp
     * engine/math/Matrix4x4.cpp
     * engine/Camera.cpp
     *
     * If you do it right, you will observe rotating cube
     *
     * RU:
     * TODO: реализуйте преобразования объектов и проекции треугольников на экран
     * На этом уроке вам необходимо работать со следующими файлами:
     *
     * engine/Object.cpp
     * engine/math/Matrix4x4.cpp
     * engine/Camera.cpp
     *
     * Если вы всё сделали правильно, то на экране появится вращающийся куб
     */

    Lesson2 l;
    l.create();
}
