/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** ChamberMap.cpp
*/

#include "ChamberMap.hpp"

Garden::ChamberMap::ChamberMap(const std::string &background) : AMap(
    background) {
}

void Garden::ChamberMap::renderGraphic(sf::RenderWindow &window,
                                       Garden::Player &player) {
    AMap::renderGraphic(window, player);
}

void Garden::ChamberMap::handleEvent(sf::Event &event, Garden::Player &player) {
    AMap::handleEvent(event, player);
}

Garden::ChamberMap::~ChamberMap() = default;
