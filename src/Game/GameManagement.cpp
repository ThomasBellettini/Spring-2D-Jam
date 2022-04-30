/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.cpp
*/

#include "GameManagement.hpp"

Garden::GameManagement::GameManagement(std::string _gameName, sf::Color _clearColor) {
    window.create(sf::VideoMode(1920, 1080), _gameName, sf::Style::Close);
    if (!window.isOpen()) {
        std::cerr << "[GardenBusiness] Internal Error, Game has crashed !" << std::endl;
        this->isEnable = false;
        std::exit(84);
    }
    this->clearColor = _clearColor;
    this->isEnable = true;
}

void Garden::GameManagement::handleEvent() {
    if (this->event.type == sf::Event::Closed) {
        this->window.close();
        this->isEnable = false;
    }
}

bool Garden::GameManagement::gameLogic() {
    window.clear(this->clearColor);
    while (window.pollEvent(this->event)) {
        handleEvent();
    }
    window.display();
    return this->isEnable;
}

Garden::GameManagement::~GameManagement() {
}
