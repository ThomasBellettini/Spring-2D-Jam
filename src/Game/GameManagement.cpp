/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.cpp
*/

#include "GameManagement.hpp"

Garden::GameManagement::GameManagement(std::string _gameName, sf::Color _clearColor) {
    window.create(sf::VideoMode(1920/2, 1080/2), _gameName, sf::Style::Close);
    if (!window.isOpen()) {
        std::cerr << "[GardenBusiness] Internal Error, Game has crashed !" << std::endl;
        this->isEnable = false;
        std::exit(84);
    }
    this->clearColor = _clearColor;
    this->isEnable = true;

    APlant plant ("Colza", "A beautiful yellow plant", 5.0, false, "../asset/colza.png",
                  "../asset/colza.png", "../asset/colza.png");
    this->plantList.push_back(plant);
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
    graphicDisplay();
    window.display();
    return this->isEnable;
}

void Garden::GameManagement::graphicDisplay() {
    if (this->clock.getElapsedTime().asSeconds() >= 5) {
        for (int i = 0; i < this->plantList.size(); i++) {
            getPlantIndex(i).updateTick();
        }
        this->clock.restart();
    }
    this->window.draw(sf::Sprite (this->plantList.front().get_seed_texture()));
}

Garden::GameManagement::~GameManagement() = default;
