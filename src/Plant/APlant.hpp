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
        APlant(std::string plantName, std::string plantDescription, double grow, bool isIllegal, std::string seedTexture, std::string levelOneTexture, std::string fullyGrownTexture);

        void updateTick() override;

        const std::string &get_plant_name() const override;
        const std::string &get_plant_description() const override;
        double get_chance_of_grow() const override;
        bool is_fully_grown() const override;
        bool is_illegal() const override;
        sf::Texture get_seed_texture() const override;
        sf::Texture get_level_one_texture() const override;
        sf::Texture get_fully_grown_texture() const override;
        void set_water(int water) override;
        int get_water() const override;

        virtual ~APlant();

    protected:
        sf::Texture _seedTexture;
        sf::Texture _levelOneTexture;
        sf::Texture _fullyGrownTexture;
    };
}

#endif //JAM_GARDENBUSINESS_APLANT_HPP
