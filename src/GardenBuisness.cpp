/*
** EPITECH PROJECT, 2022
** Hackaton_Jam
** File description:
** GardenBuisness.cpp
*/

#include "./Game/GameManagement.hpp"
#include "../include/libs.hpp"

#include "Map/GardenMap.hpp"

void enableDebug() {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
}

void debug(std::string msg)
{
    std::cout << "[GardenBusiness] (DEBUG) " << msg << std::endl;
}

void debug(double msg)
{
    std::cout << "[GardenBusiness] (DEBUG) " << msg << std::endl;
}

int main(int argSize, char **arg) {/**
    if (argSize > 1) {
        std::string s(arg[1]);
        if (s == "--debug") {
            enableDebug();
        } else {
            ShowWindow(GetConsoleWindow(), SW_HIDE);
        }
    } else {
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }**/
    enableDebug();
    Garden::GameManagement game ("GardenBusiness", sf::Color::White);
    std::cout << "Hello\n";

    game.mapContent[Garden::Scene::GARDEN] = new Garden::GardenMap("../asset/background_garden.png");

    while (game.gameLogic());

    return 0;
}