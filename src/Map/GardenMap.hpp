/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GardenMap.hpp
*/

#include "./AMap.hpp"

#ifndef JAM_GARDENBUSINESS_GARDENMAP_HPP
#define JAM_GARDENBUSINESS_GARDENMAP_HPP

namespace Garden {
    class GardenMap : public AMap {
    public:
        GardenMap(const std::string &background);
        ~GardenMap();

        void renderGraphic(sf::RenderWindow &window, Garden::Player& player) override;
        void handleEvent(sf::Event &event, Garden::Player& player) override;
    };
}

#endif //JAM_GARDENBUSINESS_GARDENMAP_HPP
