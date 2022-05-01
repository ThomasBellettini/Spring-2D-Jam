/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Inventory.cpp
*/

#include <iostream>
#include "Inventory.hpp"

Garden::Inventory::Inventory() : _seedSunflower(10), _seedHemp(10), _seedRose(10), _seedCactus(10), _seedRapeseed(10),
                                _sunflower(10), _hemp(10), _rose(10), _cactus(10), _rapeseed(10)
{
    _inventoryTexture.loadFromFile("../asset/background_inventory.png");
    _textureSeedSunflower.loadFromFile("../asset/graine_de_tournesol.png");
    _textureSeedHemp.loadFromFile("../asset/graine_de_chanvre.png");
    _textureSeedRose.loadFromFile("../asset/graine_de_rose.png");
    _textureSeedCactus.loadFromFile("../asset/graine_de_cactus.png");
    _textureSeedRapeseed.loadFromFile("../asset/graine_de_colza.png");
    _textureSunflower.loadFromFile("../asset/tournesol_state_3.png");
    _textureHemp.loadFromFile("../asset/chanvre_state_3.png");
    _textureRose.loadFromFile("../asset/rose_state_3.png");
    _textureCactus.loadFromFile("../asset/cactus_state_3.png");
    _textureRapeseed.loadFromFile("../asset/colza_state_3.png");

    _inventorySprite.setTexture(_inventoryTexture);
    _spriteSeedSunflower.setTexture(_textureSeedSunflower);
    _spriteSeedHemp.setTexture(_textureSeedHemp);
    _spriteSeedRose.setTexture(_textureSeedRose);
    _spriteSeedCactus.setTexture(_textureSeedCactus);
    _spriteSeedRapeseed.setTexture(_textureSeedRapeseed);
    _spriteSunflower.setTexture(_textureSunflower);
    _spriteHemp.setTexture(_textureHemp);
    _spriteRose.setTexture(_textureRose);
    _spriteCactus.setTexture(_textureCactus);
    _spriteRapeseed.setTexture(_textureRapeseed);

    _inventorySprite.setPosition(880, 0);
    _spriteSeedSunflower.setScale(0.75, 0.75);
    _spriteSeedSunflower.setPosition(_inventorySprite.getPosition().x + 10, 20);
    _spriteSeedHemp.setScale(0.75, 0.75);
    _spriteSeedHemp.setPosition(_inventorySprite.getPosition().x + 15, 80);
    _spriteSeedRose.setScale(0.9, 0.9);
    _spriteSeedRose.setPosition(_inventorySprite.getPosition().x + 10, 140);
    _spriteSeedCactus.setScale(0.75, 0.75);
    _spriteSeedCactus.setPosition(_inventorySprite.getPosition().x + 10, 200);
    _spriteSeedRapeseed.setScale(1, 1);
    _spriteSeedRapeseed.setPosition(_inventorySprite.getPosition().x + 10, 260);
    _spriteSunflower.setScale(0.3, 0.3);
    _spriteSunflower.setPosition(_inventorySprite.getPosition().x + 10, 340);
    _spriteHemp.setScale(0.4, 0.4);
    _spriteHemp.setPosition(_inventorySprite.getPosition().x + 30, 420);
    _spriteRose.setScale(0.4, 0.4);
    _spriteRose.setPosition(_inventorySprite.getPosition().x + 40, 500);
    _spriteCactus.setScale(0.4, 0.4);
    _spriteCactus.setPosition(_inventorySprite.getPosition().x + 40, 560);
    _spriteRapeseed.setScale(0.4, 0.4);
    _spriteRapeseed.setPosition(_inventorySprite.getPosition().x + 40, 660);

}

Garden::Inventory::~Inventory() = default;

void Garden::Inventory::inventoryRender(sf::RenderWindow &window)
{
    window.draw(_inventorySprite);
    window.draw(_spriteSeedSunflower);
    window.draw(_spriteSeedHemp);
    window.draw(_spriteSeedCactus);
    window.draw(_spriteSeedRose);
    window.draw(_spriteSeedRapeseed);
    window.draw(_spriteSunflower);
    window.draw(_spriteHemp);
    window.draw(_spriteRose);
    window.draw(_spriteCactus);
    window.draw(_spriteRapeseed);
}

void Garden::Inventory::setTexture(sf::Texture texture, const std::string& filename)
{
    texture.loadFromFile(filename);
}

void Garden::Inventory::setSprite(sf::Sprite sprite, const sf::Texture& texture)
{
    sprite.setTexture(texture);
}

void Garden::Inventory::setOpen(bool open)
{
    _open = open;
}

bool Garden::Inventory::isOpen()
{
    return _open;
}

int Garden::Inventory::getSeedSunflower() const {
    return _seedSunflower;
}

int Garden::Inventory::getSeedHemp() const {
    return _seedHemp;
}

int Garden::Inventory::getSeedRose() const {
    return _seedRose;
}

int Garden::Inventory::getSeedCactus() const {
    return _seedCactus;
}

int Garden::Inventory::getSeedRapeseed() const {
    return _seedRapeseed;
}

int Garden::Inventory::getSunflower() const {
    return _sunflower;
}

int Garden::Inventory::getHemp() const {
    return _hemp;
}

int Garden::Inventory::getRose() const {
    return _rose;
}

int Garden::Inventory::getCactus() const {
    return _cactus;
}

int Garden::Inventory::getRapeseed() const {
    return _rapeseed;
}

void Garden::Inventory::setSeedSunflower(int seedSunflower) {
    _seedSunflower = seedSunflower;
}

void Garden::Inventory::setSeedHemp(int seedHemp) {
    _seedHemp = seedHemp;
}

void Garden::Inventory::setSeedRose(int seedRose) {
    _seedRose = seedRose;
}

void Garden::Inventory::setSeedCactus(int seedCactus) {
    _seedCactus = seedCactus;
}

void Garden::Inventory::setSeedRapeseed(int seedRapeseed) {
    _seedRapeseed = seedRapeseed;
}

void Garden::Inventory::setSunflower(int sunflower) {
    _sunflower = sunflower;
}

void Garden::Inventory::setHemp(int hemp) {
    _hemp = hemp;
}

void Garden::Inventory::setRose(int rose) {
    _rose = rose;
}

void Garden::Inventory::setCactus(int cactus) {
    _cactus = cactus;
}

void Garden::Inventory::setRapeseed(int rapeseed) {
    _rapeseed = rapeseed;
}
