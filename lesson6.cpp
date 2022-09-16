//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"
#include "engine/utils/ObjectController.h"

class Lesson6 final : public Engine {
private:
    std::shared_ptr<RigidBody> cube1 = world->loadBody(ObjectNameTag("cube1"), "obj/cube.obj");
    std::shared_ptr<RigidBody> cube2 = world->loadBody(ObjectNameTag("cube2"), "obj/cube.obj");

    ObjectController cubeController;
public:
    Lesson6() : cubeController(cube1, keyboard, mouse){}

    void start() override {
        // add cubes
        cube1->translate(Vec3D(0.8,0.8,3.5));
        cube2->translate(Vec3D(-1.3,-1.3,3.5));

        screen->setMouseCursorVisible(false);
        setGlEnable(true);
    }

    void update() override {

        auto gjk = cube1->checkGJKCollision(cube2);
        if(gjk.first) {
            cube1->setColor(sf::Color(255, 181, 181, 255));
        } else {
            cube1->setColor(sf::Color(255, 245, 194, 255));
        }

        if(keyboard->isKeyPressed(sf::Keyboard::Escape)) {
            exit();
        }

        cubeController.update();
    }
};

int main() {
    /*
     * EN:
     * TODO: implement GJK algorithm for collision detection
     * You should work with the following file:
     *
     * engine/physics/RigidBody.cpp
     *
     * If you do it right, you will see one cube changes color when it intersects with another cube
     *  (You can move first cube)
     *
     * RU:
     * TODO: реализуйте алгоритм GJK для обнаружения столкновений
     * На этом уроке вам необходимо работать со следующим файлом:
     *
     * engine/physics/RigidBody.cpp
     *
     * Если вы всё сделали правильно, то один из кубов должен менять цвет при пересечении с другим
     *  (Вы можете управлять первым кубом)
     */

    Lesson6 l;
    l.create();
}