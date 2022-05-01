/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** AMap.hpp
*/

#include "IMap.hpp"


#ifndef JAM_GARDENBUSINESS_MAP_HPP
#define JAM_GARDENBUSINESS_MAP_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Garden {
    class AMap : public IMap {
    public:
        AMap(std::string background);

        void renderGraphic(sf::RenderWindow &window, Garden::Player& player) override;
        void handleMovement(sf::RenderWindow &window, Garden::Player& player) override;
        void handleEvent(sf::Event &event, Garden::Player& player) override;

        sf::Texture &getBackground() override;

        ~AMap();
    protected:
        Pot getPlantIndex(int index) {
            auto it = potList.begin();
            for (int i = 0; i < index; i++, it++);
            return *it;
        }
        Npc getNPCIndex(int index) {
            auto it = npcList.begin();
            for (int i = 0; i < index; i++, it++);
            return *it;
        }
        sf::Texture background;
    };
}

#endif //JAM_GARDENBUSINESS_MAP_HPP
