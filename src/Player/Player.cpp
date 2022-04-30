/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Player.cpp
*/

#include "Player.hpp"

Garden::Player::Player() : _posX(0), _posY(0), _speed(5), _directionX(NONE_X), _directionY(NONE_Y), _rectTime(0)
{
    setPlayerTexture("../asset/player.png");
    setPlayerSprite(_playerTexture);
    _playerSprite.setScale(4, 4);
    _playerSprite.setTextureRect(sf::IntRect(32,0, 32, 44));
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
        if (event.key.code == sf::Keyboard::I)
            ;
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Z && _directionX == UP)
            playerDirectionX(NONE_X);
        if (event.key.code == sf::Keyboard::Q && _directionY == LEFT)
            playerDirectionY(NONE_Y);
        if (event.key.code == sf::Keyboard::S && _directionX == DOWN)
            playerDirectionX(NONE_X);
        if (event.key.code == sf::Keyboard::D && _directionY == RIGHT)
            playerDirectionY(NONE_Y);
    }
}

void Garden::Player::playerDirectionX(DirectionX direction)
{
    sf::IntRect rect = _playerSprite.getTextureRect();
    if (direction == UP) {
        _directionX = UP;
        if (_directionY == NONE_Y)
            _playerSprite.setTextureRect(sf::IntRect(0,44 * 3, rect.width, rect.height));
    }
    if (direction == DOWN) {
        _directionX = DOWN;
        if (_directionY == NONE_Y)
            _playerSprite.setTextureRect(sf::IntRect(0,0, rect.width, rect.height));
    }
    if (direction == NONE_X) {
        _directionX = NONE_X;
        if (_directionY == NONE_Y)
        _playerSprite.setTextureRect(sf::IntRect(32,rect.top, rect.width, rect.height));
    }
}

void Garden::Player::playerDirectionY(DirectionY direction)
{
    sf::IntRect rect = _playerSprite.getTextureRect();
    if (direction == LEFT) {
        _directionY = LEFT;
        _playerSprite.setTextureRect(sf::IntRect(0,44 * 1, rect.width, rect.height));
    }
    if (direction == RIGHT) {
        _directionY = RIGHT;
        _playerSprite.setTextureRect(sf::IntRect(0,44 * 2, rect.width, rect.height));
    }
    if (direction == NONE_Y) {
        _directionY = NONE_Y;
        if (_directionX == NONE_X)
        _playerSprite.setTextureRect(sf::IntRect(32,rect.top, rect.width, rect.height));
    }
}

void Garden::Player::movePlayer()
{
    float tmp = _speed;
    if (_directionX != NONE_X && _directionY != NONE_Y)
        tmp /= 1.5;
    if (_directionX == UP)
        _posX -= tmp;
    if (_directionX == DOWN)
        _posX += tmp;
    if (_directionY == LEFT)
        _posY -= tmp;
    if (_directionY == RIGHT)
        _posY += tmp;
    _rectTime = _rectClock.getElapsedTime().asSeconds();
    if (_rectTime > 0.15) {
        movePlayerRect();
        _rectClock.restart();
        _rectTime = 0;
    }
}

void Garden::Player::movePlayerRect()
{
    sf::IntRect rect = _playerSprite.getTextureRect();
    if (_directionX == DOWN && _directionY == NONE_Y)
        _playerSprite.setTextureRect(sf::IntRect(rect.left + 32,0, rect.width, rect.height));
    if (_directionX == UP && _directionY == NONE_Y)
        _playerSprite.setTextureRect(sf::IntRect(rect.left + 32,44 * 3, rect.width, rect.height));
    if (_directionY == LEFT)
        _playerSprite.setTextureRect(sf::IntRect(rect.left + 32,44 * 1, rect.width, rect.height));
    if (_directionY == RIGHT)
        _playerSprite.setTextureRect(sf::IntRect(rect.left + 32,44 * 2, rect.width, rect.height));
    if (_directionX == NONE_X && _directionY == NONE_Y)
        _playerSprite.setTextureRect(sf::IntRect(32,rect.top, rect.width, rect.height));
    if (rect.left > 32 * 2)
        _playerSprite.setTextureRect(sf::IntRect(0,rect.top, rect.width, rect.height));
}

void Garden::Player::setPlayerTexture(const std::string& filename)
{
    _playerTexture.loadFromFile(filename);
}

void Garden::Player::setPlayerSprite(const sf::Texture& texture)
{
    _playerSprite.setTexture(texture);
}


