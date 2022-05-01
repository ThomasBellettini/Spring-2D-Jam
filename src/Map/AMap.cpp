/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** AMap.cpp
*/

#include "AMap.hpp"

void Garden::AMap::renderGraphic(sf::RenderWindow &window, Garden::Player& player) {
    window.draw(sf::Sprite (this->background));
    player.playerRender(window);
}

void Garden::AMap::handleMovement(sf::RenderWindow &window, Garden::Player& player) {
    player.movePlayer();
}

void Garden::AMap::handleEvent(sf::Event &event, Garden::Player& player) {
    player.playerEvent(event);
}

sf::Texture &Garden::AMap::getBackground() {
    return this->background;
}

Garden::AMap::AMap(const std::string &background) {
    this->background.loadFromFile(background);
}

Garden::AMap::~AMap() = default;