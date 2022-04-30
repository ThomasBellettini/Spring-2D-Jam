/*
** EPITECH PROJECT, 2022
** Hackaton_Jam
** File description:
** GardenBuisness.cpp
*/

#include "./Game/GameManagement.hpp"
#include "../include/libs.hpp"

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
    Garden::GameManagement game ("GardenBusiness", sf::Color::Black);
    std::cout << "Hello\n";
    while (game.gameLogic());

    return 0;
}