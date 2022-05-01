/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GardenMap.cpp
*/

#include "GardenMap.hpp"

Garden::GardenMap::~GardenMap() = default;

Garden::GardenMap::GardenMap(const std::string &background) : AMap(background) {
}

void Garden::GardenMap::renderGraphic(sf::RenderWindow &window, Garden::Player& player) {
    AMap::renderGraphic(window, player);
}

void Garden::GardenMap::handleEvent(sf::Event &event, Garden::Player& player) {
    AMap::handleEvent(event, player);
}
