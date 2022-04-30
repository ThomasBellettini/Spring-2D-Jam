/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Player.hpp
*/

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Game/GameManagement.hpp"

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

            void playerRender(sf::RenderWindow window);
            void playerEvent(sf::Event event);

            void playerDirectionX(directionX direction);
            void playerDirectionY(directionY direction);
            void movePlayer();

            void setPlayerTexture(const sf::Texture& texture);
            void setPlayerTexture(const std::string& filename);
            void setPlayerSprite(sf::Sprite sprite);
            void setPlayerSprite(const sf::Texture& texture);

        private:


            int _posX;
            int _posY;
            int _speed;
            directionX _directionX;
            directionY _directionY;
            sf::Texture _playerTexture;
            sf::Sprite _playerSprite;
    };
};

#endif //JAM_GARDENBUSINESS_PLAYER_HPP
