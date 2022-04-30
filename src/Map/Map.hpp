/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Map.hpp
*/

#ifndef JAM_GARDENBUSINESS_MAP_HPP
#define JAM_GARDENBUSINESS_MAP_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Garden {
    enum Scene {GARDEN, HOUSE, SHOP};
    class Map {
        public:
            Map();
            ~Map();

            void handleEvent(Scene scene, sf::Event event);
            void handleMovement(Scene scene);
            void handleDisplay(Scene scene, sf::RenderWindow window);



            void setScene(Scene scene);

        private:
            Scene _scene;
    };
}

#endif //JAM_GARDENBUSINESS_MAP_HPP
