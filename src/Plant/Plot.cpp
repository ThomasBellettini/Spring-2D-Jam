/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Plot.cpp
*/

#include "Plot.hpp"

int Garden::Plot::get_plant_texture_x() const {
    return plant_texture_x;
}

int Garden::Plot::get_plant_texture_y() const {
    return plant_texture_y;
}

int Garden::Plot::get_plot_x() const {
    return plot_x;
}

int Garden::Plot::get_plot_y() const {
    return plot_y;
}

Garden::IPlant *Garden::Plot::get_plant() const {
    return plant;
}

void Garden::Plot::set_plant(Garden::IPlant *plant) {
    Plot::plant = plant;
}

Garden::Plot::Plot(int plant_texture_x, int plant_texture_y, int plot_x,
                   int plot_y) : plant_texture_x(plant_texture_x),
                                 plant_texture_y(plant_texture_y),
                                 plot_x(plot_x), plot_y(plot_y) {
}

Garden::Plot::~Plot() = default;
