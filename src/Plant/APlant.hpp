/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** APlant.hpp
*/

#include "IPlant.hpp"

#ifndef JAM_GARDENBUSINESS_APLANT_HPP
#define JAM_GARDENBUSINESS_APLANT_HPP

namespace Garden {
    class APlant : public IPlant{
    public:
        APlant(std::string plantName, std::string plantDescription, double grow, bool isIllegal, std::map<int, std::string> &textures, int maxState);

        void updateTick() override;

        const std::string &get_plant_name() const override;
        const std::string &get_plant_description() const override;
        double get_chance_of_grow() const override;
        bool is_illegal() const override;
        void set_water(int water) override;
        int get_water() const override;

        int getState() const override;
        int getMaxState() const override;
        void addState() override;
        void setState(int state) override;

        sf::Texture getStateTexture(int state) override;

        virtual ~APlant();

    protected:
        std::map<int, sf::Texture> texture;
    };
}

#endif //JAM_GARDENBUSINESS_APLANT_HPP
