//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"
#include "engine/animation/Timeline.h"
#include "engine/animation/Animations.h"

class Lesson8 final : public Engine {
public:
    Lesson8() = default;

    void start() override {
        // set camera orientation
        camera->translateToPoint(Vec3D(5, 4, 2));
        camera->rotate(Vec3D(0, -0.2*M_PI, 0));
        camera->rotateLeft(0.1*M_PI);

        // add sphere
        auto cube = world->loadBody(ObjectNameTag("cube"), "obj/cube.obj");
        cube->translate(Vec3D(0,0,20));

        // add animations
        Timeline::addAnimation<ATranslate>(cube, Vec3D(0, 0, -10), 5);
        Timeline::addAnimation<AWait>();
        Timeline::addAnimation<ARotate>(cube, Vec3D(M_PI/2, M_PI, 3*M_PI/2), 5);
        Timeline::addAnimation<AWait>();
        Timeline::addAnimation<AScale>(cube, Vec3D(3, 3, 3), 5);

        setGlEnable(true);
    }
};

int main() {
    /*
     * EN:
     * TODO: implement translate, rotate and scale animations
     * You should work with the following file:
     *
     * engine/animation/ATranslate.cpp
     * engine/animation/ARotate.cpp
     * engine/animation/AScale.cpp
     *
     * If you do it right, you will see sequence of 3 animation (translation, rotation and scaling)
     *
     * RU:
     * TODO: реализуйте анимации перемещения, вращения и масштабирования
     * На этом уроке вам необходимо работать со следующим файлом:
     *
     * engine/animation/ATranslate.h
     * engine/animation/ARotate.h
     * engine/animation/AScale.h
     *
     * Если вы всё сделали правильно, то увидите последовательность из 3 анимаций (перемещение, вращение и масштабирование)
     */

    Lesson8 l;
    l.create();
}