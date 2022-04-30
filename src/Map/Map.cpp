/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Map.cpp
*/

#include "Map.hpp"


Garden::Map::Map() : _scene(GARDEN)
{

}

Garden::Map::~Map() = default;

void Garden::Map::setScene(Scene scene)
{
    _scene = scene;
}

void Garden::Map::handleEvent(Scene scene, sf::Event event)
{

}

void Garden::Map::handleMovement(Scene scene)
{

}

void Garden::Map::handleDisplay(Scene scene, sf::RenderWindow window)
{

}
