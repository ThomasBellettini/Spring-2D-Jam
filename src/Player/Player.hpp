/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Player.hpp
*/

#include "../../include/libs.hpp"
#include "Inventory.hpp"

#ifndef JAM_GARDENBUSINESS_PLAYER_HPP
#define JAM_GARDENBUSINESS_PLAYER_HPP

namespace Garden {
    class Player {
        protected:
            enum DirectionX {NONE_X, UP, DOWN};
            enum DirectionY {NONE_Y, LEFT, RIGHT};

        public:
            Player();
            ~Player();

            void playerRender(sf::RenderWindow& window);
            void playerEvent(sf::Event event);

            void playerDirectionX(DirectionX direction);
            void playerDirectionY(DirectionY direction);
            void movePlayer();
            void movePlayerRect();
            void moveHitWall();

            void setPlayerTexture(const std::string& filename);
            void setPlayerSprite(const sf::Texture& texture);

            float getPosX() const;
            float getPosY() const;
            void setPosX(float posX);
            void setPosY(float posY);

    private:
            Inventory inventory;
            float _posX;
            float _posY;
            float _speed;
            DirectionX _directionX;
            DirectionY _directionY;
            sf::Clock _rectClock;
            float _rectTime;
            sf::Texture _playerTexture;
            sf::Sprite _playerSprite;
    };
};

#endif //JAM_GARDENBUSINESS_PLAYER_HPP
