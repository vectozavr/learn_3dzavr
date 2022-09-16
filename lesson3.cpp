//
// Created by Иван Ильин on 24.02.2022.
//

#include "engine/Engine.h"

class Lesson3 final : public Engine {
private:
    double rotationSpeed = 1;

    // load monkey to the scene
    std::shared_ptr<RigidBody> monkey = world->loadBody(ObjectNameTag("monkey"), "obj/monkey.obj");
public:
    Lesson3() = default;

    void start() override {
        // translate monkey
        monkey->translate(Vec3D(0,0,3));
    }

    void update() override {
        // rotate monkey in every frame
        monkey->rotate(Vec3D(0, rotationSpeed*Time::deltaTime(), 0));
    }
};

int main() {
    /*
     * EN:
     * TODO: implement loading .obj files, simple lighting and painter algorithm
     * You should work with the following files:
     *
     * engine/utils/ResourceManager.cpp
     * engine/Camera.cpp
     *
     * If you do it right, you will observe rotating monkey
     *
     * RU:
     * TODO: реализуйте загрузку .obj файлов, простое освещение и алгоритм художника
     * На этом уроке вам необходимо работать со следующими файлами:
     *
     * engine/utils/ResourceManager.cpp
     * engine/Camera.cpp
     *
     * Если вы всё сделали правильно, то на экране должна появится вращающаяся обезьянка
     */

    Lesson3 l;
    l.create();
}
