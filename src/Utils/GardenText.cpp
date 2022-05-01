/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GardenText.cpp
*/

#include "GardenText.hpp"

GardenText::GardenText(const std::string &text, const sf::Color &color) : text(
    text), color(color) {
    this->font.loadFromFile("./asset/font.ttf");
}

sf::Text GardenText::build() {
    sf::Text text;
    text.setString(this->text);
    text.setFillColor(this->color);
    text.setFont(this->font);
    return text;
}

sf::Text GardenText::build(int x, int y) {
    sf::Text text = build();
    text.setPosition(x, y);
    return text;
}

GardenText::~GardenText() = default;

