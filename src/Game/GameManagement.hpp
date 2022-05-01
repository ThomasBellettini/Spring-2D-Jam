/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.hpp
*/

#include "../Plant/APlant.hpp"
#include "../Plant/Pot.hpp"
#include "../../include/libs.hpp"
#include "../Npc/Npc.hpp"

#include "../Map/IMap.hpp"

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

        void playerCollision();
        void setScene(Garden::Scene scene);

        const Player &get_player() const;

        const std::list<Pot> &get_plot_list() const;
        void renderPlacingPot(sf::Vector2<INT> position);

        ~GameManagement();

        std::map<Garden::Scene, Garden::IMap*> mapContent;
    private:
        Pot getPlantIndex(int index) {
            auto it = plotList.begin();
            for (int i = 0; i < index; i++, it++);
            return *it;
        }
        Npc getNPCIndex(int index) {
            auto it = npcList.begin();
            for (int i = 0; i < index; i++, it++);
            return *it;
        }
        sf::Color clearColor;
        sf::Event event;
        std::list<Pot> plotList;
        std::list<Npc> npcList;

        Garden::Player player;

        bool isEnable;
        sf::Clock clock;

        sf::Clock deltaClock;
        float deltaTime;
        sf::RenderWindow window;

        Garden::Scene scene;
        bool isPlacing;
    };
}

#endif //JAM_GARDENBUSINESS_GAMEMANAGEMENT_HPP
