//
// Created by Иван Ильин on 06.09.2022.
//

#include "Client.h"

void Client::updatePacket() {
    // TODO: implement (lesson 10)

}

void Client::processInit(sf::Packet &packet) {
    // TODO: implement (lesson 10)

}

void Client::processUpdate(sf::Packet &packet) {
    // TODO: implement (lesson 10)

}

void Client::processNewClient(sf::Packet &packet) {
    // TODO: implement (lesson 10)

}

void Client::processDisconnect(sf::Uint16 targetId) {
    // TODO: implement (lesson 10)

}

void Client::addPlayer(sf::Uint16 id, std::shared_ptr<RigidBody> player) {
    // TODO: implement (lesson 10)

}

void Client::setSpawnPlayerCallBack(std::function<void(sf::Uint16)> spawn) {
    _spawnPlayerCallBack = std::move(spawn);
}

void Client::setRemovePlayerCallBack(std::function<void(sf::Uint16)> remove) {
    _removePlayerCallBack = std::move(remove);
}