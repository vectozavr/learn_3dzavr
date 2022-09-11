//
// Created by Иван Ильин on 06.09.2022.
//

#ifndef LEARN_3DZAVR_SERVER_H
#define LEARN_3DZAVR_SERVER_H

#include "../engine/network/ServerUDP.h"

class Server : public ServerUDP {
private:
    std::map<sf::Uint16, std::shared_ptr<Object>> _players{};
public:
    Server() = default;

    void broadcast() override;
    void processConnect(sf::Uint16 senderId) override;
    void processClientUpdate(sf::Uint16 senderId, sf::Packet &packet) override;
    void processDisconnect(sf::Uint16 senderId) override;
};


#endif //LEARN_3DZAVR_SERVER_H
