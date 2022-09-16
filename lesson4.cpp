//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"
#include "engine/utils/ObjectController.h"

class Lesson4 final : public Engine {
private:
    ObjectController cameraController;
public:
    Lesson4() : cameraController(camera, keyboard, mouse) {};

    void start() override {
        // load map
        auto mountains = world->loadBody(ObjectNameTag("mountains"), "obj/mountains.obj");
        mountains->translate(Vec3D(0,-10,0));

        // make mouse cursor invisible
        screen->setMouseCursorVisible(false);
    }

    void update() override {
        cameraController.update();

        if(keyboard->isKeyPressed(sf::Keyboard::Escape)) {
            exit();
        }
    }
};

int main() {
    /*
     * EN:
     * TODO: implement camera translation, rotation and clipping planes
     * You should work with the following files:
     *
     * engine/math/Matrix4x4.cpp
     * engine/Camera.cpp
     * engine/math/Plane.cpp
     *
     * If you do it right, you will be possible to control camera and see mountains
     *
     * RU:
     * TODO: реализуйте вращение, перемещение камеры и процедуру клиппинга
     * На этом уроке вам необходимо работать со следующими файлами:
     *
     * engine/math/Matrix4x4.cpp
     * engine/Camera.cpp
     * engine/math/Plane.cpp
     *
     * Если вы всё сделали правильно, то вы сможете управлять камерой и смотреть на горы
     */

    Lesson4 l;
    l.create();
}
