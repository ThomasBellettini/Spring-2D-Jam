/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GardenText.hpp
*/

#ifndef JAM_GARDENBUSINESS_GARDENTEXT_HPP
#define JAM_GARDENBUSINESS_GARDENTEXT_HPP

#include "../../include/libs.hpp"

class GardenText {
public:
    GardenText(const std::string &text, const sf::Color &color);

    sf::Text build();
    sf::Text build (int x, int y);

    virtual ~GardenText();

private:
    std::string text;
    sf::Color color;
    sf::Font font;
};

#endif //JAM_GARDENBUSINESS_GARDENTEXT_HPP
