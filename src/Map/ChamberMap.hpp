/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** ChamberMap.hpp
*/

#include "AMap.hpp"

#ifndef JAM_GARDENBUSINESS_CHAMBERMAP_HPP
#define JAM_GARDENBUSINESS_CHAMBERMAP_HPP

namespace Garden {
    class ChamberMap : public Garden::AMap {
    public:
        ChamberMap(const std::string &background);
        ~ChamberMap();

        void renderGraphic(sf::RenderWindow &window, Player &player) override;
        void handleEvent(sf::Event &event, Player &player) override;
    };
}

#endif //JAM_GARDENBUSINESS_CHAMBERMAP_HPP
