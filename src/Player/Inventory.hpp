/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Inventory.hpp
*/

#ifndef JAM_GARDENBUSINESS_INVENTORY_HPP
#define JAM_GARDENBUSINESS_INVENTORY_HPP

namespace Garden {
    class Inventory {
        protected:
        public:
            Inventory();
            ~Inventory();

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

    };
};

#endif //JAM_GARDENBUSINESS_INVENTORY_HPP
