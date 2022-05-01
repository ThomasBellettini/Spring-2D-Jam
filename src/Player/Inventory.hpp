/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Inventory.hpp
*/

#ifndef JAM_GARDENBUSINESS_INVENTORY_HPP
#define JAM_GARDENBUSINESS_INVENTORY_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Garden {
    class Inventory {
        protected:
        public:
            Inventory();
            ~Inventory();

            void inventoryRender(sf::RenderWindow &window);

            void setTexture(sf::Texture texture, const std::string& filename);
            void setSprite(sf::Sprite sprite, const sf::Texture& texture);

            void setOpen(bool open);

            bool isOpen();

        int getSeedSunflower() const;
        int getSeedHemp() const;
        int getSeedRose() const;
        int getSeedCactus() const;
        int getSeedRapeseed() const;
        int getSunflower() const;
        int getHemp() const;
        int getRose() const;
        int getCactus() const;
        int getRapeseed() const;

        void setSeedSunflower(int seedSunflower);
        void setSeedHemp(int seedHemp);
        void setSeedRose(int seedRose);
        void setSeedCactus(int seedCactus);
        void setSeedRapeseed(int seedRapeseed);
        void setSunflower(int sunflower);
        void setHemp(int hemp);
        void setRose(int rose);
        void setCactus(int cactus);
        void setRapeseed(int rapeseed);


    private:
            int _seedSunflower;
            int _seedHemp;
            int _seedRose;
            int _seedCactus;
            int _seedRapeseed;

            int _sunflower;
            int _hemp;
            int _rose;
            int _cactus;
            int _rapeseed;

            bool _open;

            sf::Texture _inventoryTexture;
            sf::Sprite _inventorySprite;

            sf::Texture _textureSeedSunflower;
            sf::Texture _textureSeedHemp;
            sf::Texture _textureSeedRose;
            sf::Texture _textureSeedCactus;
            sf::Texture _textureSeedRapeseed;
            sf::Texture _textureSunflower;
            sf::Texture _textureHemp;
            sf::Texture _textureRose;
            sf::Texture _textureCactus;
            sf::Texture _textureRapeseed;

            sf::Sprite _spriteSeedSunflower;
            sf::Sprite _spriteSeedHemp;
            sf::Sprite _spriteSeedRose;
            sf::Sprite _spriteSeedCactus;
            sf::Sprite _spriteSeedRapeseed;
            sf::Sprite _spriteSunflower;
            sf::Sprite _spriteHemp;
            sf::Sprite _spriteRose;
            sf::Sprite _spriteCactus;
            sf::Sprite _spriteRapeseed;
    };
};

#endif //JAM_GARDENBUSINESS_INVENTORY_HPP
