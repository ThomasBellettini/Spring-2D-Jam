/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Player.hpp
*/

#include "../../include/libs.hpp"

#ifndef JAM_GARDENBUSINESS_PLAYER_HPP
#define JAM_GARDENBUSINESS_PLAYER_HPP

namespace Garden {
    class Player {
        protected:
            enum directionX {NONE_X, UP, DOWN};
            enum directionY {NONE_Y, LEFT, RIGHT};

        public:
            Player();
            ~Player();

            void playerRender(sf::RenderWindow& window);
            void playerEvent(sf::Event event);

            void playerDirectionX(directionX direction);
            void playerDirectionY(directionY direction);
            void movePlayer();

            void setPlayerTexture(const std::string& filename);
            void setPlayerSprite(const sf::Texture& texture);

        private:
            float _posX;
            float _posY;
            float _speed;
            directionX _directionX;
            directionY _directionY;
            sf::Texture _playerTexture;
            sf::Sprite _playerSprite;
    };
};

#endif //JAM_GARDENBUSINESS_PLAYER_HPP
