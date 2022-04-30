/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.hpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
#define JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP

namespace Garden {
    class GameManagement {
    public:
        GameManagement(std::string _gameName, sf::Color _clearColor);

        bool gameLogic ();
        void handleEvent();

        ~GameManagement();

    private:
        sf::Color clearColor;
        sf::RenderWindow window;
        sf::Event event;

        bool isEnable;
    };
}

#endif //JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
