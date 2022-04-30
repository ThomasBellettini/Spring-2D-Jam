/*
** EPITECH PROJECT, 2022
** Hackaton_Jam
** File description:
** GardenBuisness.cpp
*/

#include "./Game/GameManagement.hpp"
#include <windows.h>

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    Garden::GameManagement game ("GardenBusiness", sf::Color::Black);
    while (game.gameLogic());

    return 0;
}