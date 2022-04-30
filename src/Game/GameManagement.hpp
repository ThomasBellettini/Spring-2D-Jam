/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.hpp
*/

#include "../Plant/APlant.hpp"
#include "../../include/libs.hpp"

#ifndef JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
#define JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP

namespace Garden {
    class GameManagement {
    public:
        GameManagement(std::string _gameName, sf::Color _clearColor);

        bool gameLogic ();
        void graphicDisplay();
        void handleEvent();

        ~GameManagement();

    private:
        APlant getPlantIndex(int index) {
            auto it = plantList.begin();
            for (int i = 0; i < index; i++, it++);
            return *it;
        };
        sf::Color clearColor;
        sf::RenderWindow window;
        sf::Event event;
        std::list<APlant> plantList;

        bool isEnable;
        sf::Clock clock;
    };
}

#endif //JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
