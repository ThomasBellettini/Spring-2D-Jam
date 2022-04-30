/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Plot.cpp
*/

#include "Plot.hpp"

Garden::Plot::Plot(int plant_texture_x, int plant_texture_y, int plot_x,
                   int plot_y, const std::string &plot_name) : plant_texture_x(
    plant_texture_x), plant_texture_y(plant_texture_y), plot_x(plot_x),
                                                               plot_y(plot_y),
                                                               plot_name(
                                                                   plot_name) {
}

Garden::Plot::~Plot() = default;
