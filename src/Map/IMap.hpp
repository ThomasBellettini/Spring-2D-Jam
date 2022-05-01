/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** IMap.hpp
*/

#include "../Plant/Pot.hpp"
#include "../Npc/Npc.hpp"
#include "../Player/Player.hpp"

#ifndef JAM_GARDENBUSINESS_IMAP_HPP
#define JAM_GARDENBUSINESS_IMAP_HPP

namespace Garden {
    enum Scene {
        GARDEN,
        HOUSE,
        SHOP
    };
    class IMap {
    public:
        IMap() = default;

        virtual void renderGraphic(sf::RenderWindow &window, Garden::Player& player) = 0;
        virtual void handleMovement(sf::RenderWindow &window, Garden::Player& player) = 0;
        virtual void handleEvent(sf::Event &event, Garden::Player& player) = 0;

        virtual sf::Texture &getBackground() = 0;

        ~IMap() = default;
    };
}


#endif //JAM_GARDENBUSINESS_IMAP_HPP
