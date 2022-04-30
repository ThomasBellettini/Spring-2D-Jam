/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.hpp
*/

#include "../Plant/APlant.hpp"
#include "../Plant/Plot.hpp"
#include "../../include/libs.hpp"
#include "../Player/Player.hpp"

#ifndef JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
#define JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP

namespace Garden {
    class GameManagement {
    public:
        GameManagement(std::string _gameName, sf::Color _clearColor);

        bool gameLogic ();
        void graphicDisplay();
        void handleEvent();

        const std::list<Plot> &get_plot_list() const;

        ~GameManagement();

        sf::RenderWindow window;
    private:
        Plot getPlantIndex(int index) {
            auto it = plotList.begin();
            for (int i = 0; i < index; i++, it++);
            return *it;
        };
        sf::Color clearColor;
        sf::Event event;
        std::list<Plot> plotList;

        bool isEnable;
        sf::Clock clock;
    };
}

#endif //JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
