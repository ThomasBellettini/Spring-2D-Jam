/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** IPlant.hpp
*/

#include "../../include/libs.hpp"

#ifndef JAM_GARDENBUSINESS_IPLANT_HPP
#define JAM_GARDENBUSINESS_IPLANT_HPP

namespace Garden {
    class IPlant {
    public:
        IPlant() = default;

        virtual void updateTick() = 0;

        virtual const std::string &get_plant_name() const = 0;
        virtual const std::string &get_plant_description() const = 0;

        virtual double get_chance_of_grow() const = 0;

        virtual bool is_illegal() const = 0;
        virtual int get_water() const = 0;
        virtual void set_water(int water) = 0;

        virtual int getState() const = 0;
        virtual int getMaxState() const = 0;

        virtual sf::Texture getStateTexture(int state) = 0;

        virtual void addState() = 0;
        virtual void setState(int state) = 0;

        ~IPlant() = default;

    protected:
        std::string plantName;
        std::string plantDescription;

        double chanceOfGrow;
        bool isIllegal;

        int state;
        int maxState;

        int water;
    };
}

#endif //JAM_GARDENBUSINESS_IPLANT_HPP
