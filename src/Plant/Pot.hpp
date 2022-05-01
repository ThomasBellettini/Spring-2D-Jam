/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Pot.hpp
*/

#include "IPlant.hpp"

#ifndef JAM_GARDENBUSINESS_PLOT_HPP
#define JAM_GARDENBUSINESS_PLOT_HPP

namespace Garden {
    class Pot {
    public:
        Pot(int plant_texture_x, int plant_texture_y, int plot_x, int plot_y);

        int get_plant_texture_x() const;
        int get_plant_texture_y() const;
        int get_plot_x() const;
        int get_plot_y() const;

        IPlant *get_plant() const;
        void set_plant(IPlant *plant);

        virtual ~Pot();

    private:
        IPlant *plant;

        int plant_texture_x;
        int plant_texture_y;

        int plot_x;
        int plot_y;
    };
}

#endif //JAM_GARDENBUSINESS_PLOT_HPP
