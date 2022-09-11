//
// Created by Иван Ильин on 06.09.2022.
//

#ifndef LEARN_3DZAVR_CLIENT_H
#define LEARN_3DZAVR_CLIENT_H

#include "../engine/network/ClientUDP.h"
#include "../engine/physics/RigidBody.h"

class Client : public ClientUDP {
private:
    std::map<sf::Uint16, std::shared_ptr<RigidBody>> _players{};
    std::shared_ptr<RigidBody> _player;

    std::function<void(sf::Uint16)> _spawnPlayerCallBack;
    std::function<void(sf::Uint16)> _removePlayerCallBack;
public:
    explicit Client(std::shared_ptr<RigidBody> player) : _player(player) {};

    void updatePacket() override;
    void processInit(sf::Packet &packet) override;
    void processUpdate(sf::Packet &packet) override;
    void processNewClient(sf::Packet &packet) override;
    void processDisconnect(sf::Uint16 targetId) override;
    void setSpawnPlayerCallBack(std::function<void(sf::Uint16)> spawn);
    void setRemovePlayerCallBack(std::function<void(sf::Uint16)> remove);
    void addPlayer(sf::Uint16 id, std::shared_ptr<RigidBody> player);
};


#endif //LEARN_3DZAVR_CLIENT_H
