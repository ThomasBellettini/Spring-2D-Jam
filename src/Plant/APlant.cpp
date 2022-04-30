/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** APlant.cpp
*/

#include "APlant.hpp"

Garden::APlant::APlant(std::string plantName, std::string plantDescription,
                       double grow, bool isIllegal, std::string seedTexture,
                       std::string levelOneTexture,
                       std::string fullyGrownTexture) {
    this->plantName = plantName;
    this->plantDescription = plantDescription;
    this->chanceOfGrow = grow;
    this->isIllegal = isIllegal;
    this->fullyGrown = false;

    this->_seedTexture.loadFromFile(seedTexture);
    this->_levelOneTexture.loadFromFile(levelOneTexture);
    this->_fullyGrownTexture.loadFromFile(fullyGrownTexture);
}

void Garden::APlant::updateTick() {
    double f = (double)rand() / RAND_MAX;
    double percent = f * (100.0- 0.0);

    if (percent <= this->chanceOfGrow) {
        this->fullyGrown = true;
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

bool Garden::APlant::is_fully_grown() const {
    return this->fullyGrown;
}

bool Garden::APlant::is_illegal() const {
    return this->isIllegal;
}

sf::Texture Garden::APlant::get_seed_texture() const {
    return this->_seedTexture;
}

sf::Texture Garden::APlant::get_level_one_texture() const {
    return this->_levelOneTexture;
}

sf::Texture Garden::APlant::get_fully_grown_texture() const {
    return this->_fullyGrownTexture;
}

int Garden::APlant::get_water() const {
    return this->water;
}

void Garden::APlant::set_water(int water) {
    this->water = water;
}

Garden::APlant::~APlant() = default;
