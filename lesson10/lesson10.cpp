//
// Created by Иван Ильин on 06.09.2022.
//

#include "../engine/Engine.h"
#include "../engine/utils/ObjectController.h"

#include "Server.h"
#include "Client.h"

class Lesson10 : public Engine {
private:
    std::shared_ptr<RigidBody> player = world->loadBody(ObjectNameTag("Player"), "obj/cube.obj");
    ObjectController playerController;

    std::shared_ptr<Server> server = std::make_shared<Server>();
    std::shared_ptr<Client> client = std::make_shared<Client>(player);

    bool is_camera_controlling = false;

    void initNetwork() {
        // TODO: implement (lesson 10)

    }

public:
    Lesson10() : playerController(player, keyboard, mouse) {};

    void start() override {

        player->translate(Vec3D(0,0,5));

        setGlEnable(true);
        initNetwork();

        while (client->isWorking() && !client->connected()) {
            client->update();
            server->update();
            Time::update();
        }
    }

    void update() override {

        server->update();
        client->update();

        // Check all input after this condition please
        if (!screen->hasFocus()) {
            return;
        }

        if(keyboard->isKeyPressed(sf::Keyboard::Escape)) {
            exit();
        }

        if(keyboard->isKeyTapped(sf::Keyboard::C)) {
            is_camera_controlling = !is_camera_controlling;
        }

        if(is_camera_controlling) {
            playerController.update();
        }
    }
    void spawnPlayer(sf::Uint16 id) {
        // TODO: implement (lesson 10)


    }
    void removePlayer(sf::Uint16 id) {
        // TODO: implement (lesson 10)

    }
};

int main() {
    /*
     * EN:
     * TODO: implement simple multiplayer
     * You should work with the following files:
     *
     * lesson10/Server.cpp
     * lesson10/Client.cpp
     * lesson10/lesson10.cpp
     *
     * If you did everything correctly, then when you start two or more clients, cubes
     * should appear on the screen and changes in the coordinates of one of the cubes
     * should be displayed on all connected clients
     *
     * RU:
     * TODO: реализуйте простой мультиплеер
     * На этом уроке вам необходимо работать со следующими файлами:
     *
     * lesson10/Server.cpp
     * lesson10/Client.cpp
     * lesson10/lesson10.cpp
     *
     * Если вы всё сделали правильно, то при запуске двух и более клиентов на экране должны
     * появятся кубы и изменения координат одного из кубов должно отображаться на всех
     * подключённых клиентах
     */

    Lesson10 l;
    l.create(1280, 720);
}
