/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Player.cpp
*/

#include "Player.hpp"

Garden::Player::Player() : _posX(500), _posY(590), _speed(5), _directionX(NONE_X), _directionY(NONE_Y)
{
    setPlayerTexture("./asset/player.png");
    setPlayerSprite(_playerTexture);
    _playerSprite.setScale(2, 2);
    _playerSprite.setTextureRect(sf::IntRect(32,0, 32, 44));
}

Garden::Player::~Player() = default;

void Garden::Player::playerRender(sf::RenderWindow &window)
{
    _playerSprite.setPosition(_posY, _posX);
    window.draw(_playerSprite);
    if (inventory.isOpen()) {
        inventory.inventoryRender(window);
    }
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
            inventory.setOpen(true);
        if (event.key.code == sf::Keyboard::Escape && inventory.isOpen())
            inventory.setOpen(false);
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
    if (direction == UP && _directionX != UP) {
        _directionX = UP;
        if (_directionY == NONE_Y)
            _playerSprite.setTextureRect(sf::IntRect(0,44 * 3, rect.width, rect.height));
    }
    if (direction == DOWN && _directionX != DOWN) {
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
    if (direction == LEFT && _directionY != LEFT) {
        _directionY = LEFT;
        _playerSprite.setTextureRect(sf::IntRect(0,44 * 1, rect.width, rect.height));
    }
    if (direction == RIGHT && _directionY != RIGHT) {
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

void Garden::Player::moveHitWall()
{
    if (_posX > 550)
        _posX = 550;
    if (_posX < 100)
        _posX = 100;
    if (_posY > 1050)
        _posY = 1050;
    if (_posY < 200)
        _posY = 200;

    _playerSprite.getTextureRect().intersects(sf::Rect<INT>(0, 0, 100, 100));
}

void Garden::Player::setPlayerTexture(const std::string& filename)
{
    _playerTexture.loadFromFile(filename);
}

void Garden::Player::setPlayerSprite(const sf::Texture& texture)
{
    _playerSprite.setTexture(texture);
}

float Garden::Player::getPosX() const {
    return _posX;
}

float Garden::Player::getPosY() const {
    return _posY;
}

void Garden::Player::setPosX(float posX) {
    _posX = posX;
}

void Garden::Player::setPosY(float posY) {
    _posY = posY;
}


