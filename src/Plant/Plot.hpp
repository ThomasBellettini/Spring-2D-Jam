/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Plot.hpp
*/

#include "../../include/libs.hpp"

#ifndef JAM_GARDENBUSINESS_PLOT_HPP
#define JAM_GARDENBUSINESS_PLOT_HPP

namespace Garden {
    class Plot {
    public:
        Plot(int plant_texture_x, int plant_texture_y, int plot_x, int plot_y,
             const std::string &plot_name);

        virtual ~Plot();

    private:
        int plant_texture_x;
        int plant_texture_y;

        int plot_x;
        int plot_y;

        std::string plot_name;
    };
}

#endif //JAM_GARDENBUSINESS_PLOT_HPP
