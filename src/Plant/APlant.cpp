/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** APlant.cpp
*/

#include "APlant.hpp"

Garden::APlant::APlant(std::string plantName, std::string plantDescription, double grow, bool isIllegal, std::map<int, std::string> &textures, int maxState) {
    this->plantName = plantName;
    this->plantDescription = plantDescription;
    this->chanceOfGrow = grow;
    this->isIllegal = isIllegal;
    this->state = 0;
    this->maxState = maxState;

    for (int i = 0; i < maxState && i > texture.size() ; i++) {
        sf::Texture sfTexture;
        sfTexture.loadFromFile(textures[i]);
        texture[i] = sfTexture;
    }

}

void Garden::APlant::updateTick() {
    double f = (double)rand() / RAND_MAX;
    double percent = f * (100.0- 0.0);

    if (percent <= this->chanceOfGrow && state < maxState) {
        this->addState();
    }
}

const std::string &Garden::APlant::get_plant_name() const {
    return this->plantName;
}

const std::string &Garden::APlant::get_plant_description() const {
    return this->plantDescription;
}

double Garden::APlant::get_chance_of_grow() const {
    return this->chanceOfGrow;
}

bool Garden::APlant::is_illegal() const {
    return this->isIllegal;
}

int Garden::APlant::get_water() const {
    return this->water;
}

void Garden::APlant::set_water(int water) {
    this->water = water;
}

int Garden::APlant::getState() const {
    return this->state;
}

int Garden::APlant::getMaxState() const {
    return this->maxState;
}

void Garden::APlant::addState() {
    this->state = this->state + 1;
}

void Garden::APlant::setState(int state) {
    this->state = state;
}

sf::Texture Garden::APlant::getStateTexture(int state) {
    return texture[state];
}

Garden::APlant::~APlant() = default;
