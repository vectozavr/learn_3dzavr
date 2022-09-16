//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"
#include "engine/utils/ObjectController.h"

class Lesson7 final : public Engine {
private:
    std::shared_ptr<RigidBody> cube1 = world->loadBody(ObjectNameTag("cube1"), "obj/cube.obj");
    std::shared_ptr<RigidBody> cube2 = world->loadBody(ObjectNameTag("cube2"), "obj/cube.obj");

    ObjectController cubeController;
public:
    Lesson7() : cubeController(cube1, keyboard, mouse){}

    void start() override {
        // add cubes
        cube1->translate(Vec3D(0.5,0.5,3.5));
        cube2->translate(Vec3D(-1.3,-1.3,3.5));

        // turn on collision detection & solve for the first cube
        cube1->setCollision(true);

        screen->setMouseCursorVisible(false);
        setGlEnable(true);
    }

    void update() override {
        if(keyboard->isKeyPressed(sf::Keyboard::Escape)) {
            exit();
        }

        cubeController.update();
    }
};

int main() {
    /*
     * EN:
     * TODO: implement EPA algorithm for solving collision
     * You should work with the following file:
     *
     * engine/physics/RigidBody.cpp
     *
     * If you do it right, cubes should not intersect with each other
     *  (You can move first cube)
     *
     * RU:
     * TODO: реализуйте алгоритм EPA для разрешения столкновений
     * На этом уроке вам необходимо работать со следующим файлом:
     *
     * engine/physics/RigidBody.cpp
     *
     * Если вы всё сделали правильно, то один куб не должен пересекаться с другим
     *  (Вы можете управлять первым кубом)
     */

    Lesson7 l;
    l.create();
}