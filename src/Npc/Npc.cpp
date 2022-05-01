/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Npc.cpp
*/

#include "Npc.hpp"

Garden::Npc::Npc(void (*action_performed)(Garden::Player), int x, int y,
                 int width, int height, const std::string &npc_name,
                 const std::string &npc_texture) : actionPerformed(
    action_performed), x(x), y(y), width(width), height(height),
                                                   npcName(npc_name),
                                                   npc_texture(npc_texture) {
    texture.loadFromFile(npc_texture);
}

void Garden::Npc::set_name_tag(const std::string &name_tag) {
    nameTag = name_tag;
}

void Garden::Npc::set_hide_name_tag(bool hide_name_tag) {
    hideNameTag = hide_name_tag;
}

void Garden::Npc::set_sound_open(const std::string &sound_open) {
    soundOpen = sound_open;
}

const std::string &Garden::Npc::get_name_tag() const {
    return nameTag;
}

const std::string &Garden::Npc::get_npc_name() const {
    return npcName;
}

bool Garden::Npc::is_hide_name_tag() const {
    return hideNameTag;
}

const std::string &Garden::Npc::get_sound_open() const {
    return soundOpen;
}

const std::string &Garden::Npc::get_npc_texture() const {
    return npc_texture;
}

void Garden::Npc::buildNameTag(sf::RenderWindow &window) const {
    GardenText garden_text (this->npcName, sf::Color::White);
    sf::Text text = garden_text.build();

    float base = text.getString().getSize() * 20;

    sf::RectangleShape rectangle_shape (sf::Vector2f (base, 50));
    rectangle_shape.setPosition(x - ((base / 2) - (width / 2)), (y - 50));
    rectangle_shape.setFillColor(sf::Color (0, 0, 0, 100));
    window.draw(rectangle_shape);

    text.setPosition(x - ((base / 2) - (width / 2)) + 20, (y - 50));
    window.draw(text);
}

void Garden::Npc::renderNpc(sf::RenderWindow &window) const {
    sf::Sprite sprite (this->texture);
    sprite.setPosition(x, y);
    window.draw(sprite);
    buildNameTag(window);
}

Garden::Npc::~Npc() = default;
