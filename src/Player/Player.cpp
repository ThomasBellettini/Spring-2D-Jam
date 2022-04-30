/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Player.cpp
*/

#include "Player.hpp"

Garden::Player::Player() : _posX(0), _posY(0), _speed(1), _directionX(NONE_X), _directionY(NONE_Y)
{
    setPlayerTexture("../asset/pot.png");
    setPlayerSprite(_playerTexture);
}

Garden::Player::~Player() = default;

void Garden::Player::playerRender(sf::RenderWindow &window)
{
    _playerSprite.setPosition(_posY, _posX);
    window.draw(_playerSprite);
}

void Garden::Player::playerEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Z)
            playerDirectionX(UP);
        if (event.key.code == sf::Keyboard::Q)
            playerDirectionY(LEFT);
        if (event.key.code == sf::Keyboard::S)
            playerDirectionX(DOWN);
        if (event.key.code == sf::Keyboard::D)
            playerDirectionY(RIGHT);
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Z)
            playerDirectionX(NONE_X);
        if (event.key.code == sf::Keyboard::Q)
            playerDirectionY(NONE_Y);
        if (event.key.code == sf::Keyboard::S)
            playerDirectionX(NONE_X);
        if (event.key.code == sf::Keyboard::D)
            playerDirectionY(NONE_Y);
    }
}

void Garden::Player::playerDirectionX(directionX direction)
{
    if (direction == UP)
        _directionX = UP;
    if (direction == DOWN)
        _directionX = DOWN;
}

void Garden::Player::playerDirectionY(directionY direction)
{
    if (direction == LEFT)
        _directionY = LEFT;
    if (direction == RIGHT)
        _directionY = RIGHT;
}

void Garden::Player::movePlayer()
{
    int tmp = _speed;
    if (_directionX != NONE_X && _directionY != NONE_Y)
        tmp /= 2;
    if (_directionX == UP)
        _posX -= tmp;
    if (_directionX == DOWN)
        _posX += tmp;
    if (_directionY == LEFT)
        _posY -= tmp;
    if (_directionY == RIGHT)
        _posY += tmp;
}

void Garden::Player::setPlayerTexture(const sf::Texture& texture)
{
    _playerTexture = texture;
}

void Garden::Player::setPlayerTexture(const std::string& filename)
{
    _playerTexture.loadFromFile(filename);
}

void Garden::Player::setPlayerSprite(sf::Sprite sprite)
{
    _playerSprite = sprite;
}

void Garden::Player::setPlayerSprite(const sf::Texture& texture)
{
    _playerSprite.setTexture(texture);
}