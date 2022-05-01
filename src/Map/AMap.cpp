/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** AMap.cpp
*/

#include "AMap.hpp"

Garden::AMap::AMap(std::string background) {
    this->background.loadFromFile(background);
}

void Garden::AMap::renderGraphic(sf::RenderWindow &window, Garden::Player& player) {
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

Garden::AMap::~AMap() = default;