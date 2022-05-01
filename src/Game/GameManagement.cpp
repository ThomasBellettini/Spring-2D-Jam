/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** GameManagement.cpp
*/

#include "GameManagement.hpp"

void str(Garden::Player player) {

}

Garden::GameManagement::GameManagement(std::string _gameName, sf::Color _clearColor) {
    window.create(sf::VideoMode(1280, 800), _gameName, sf::Style::Close);
    if (!window.isOpen()) {
        std::cerr << "[GardenBusiness] Internal Error, Game has crashed !" << std::endl;
        this->isEnable = false;
        std::exit(84);
    }
    this->scene = GARDEN;
    this->clearColor = _clearColor;
    this->isEnable = true;

//    IPlant *plant = new APlant("Colza", "A beautiful yellow plant", 5.0, false, "../asset/colza.png",
//                  "../asset/colza.png", "../asset/colza.png");
//    Plot plot (10, 15, 0, 0);
//    plot.set_plant(plant);
//    plotList.push_back(plot);
//
//    Garden::Npc npc (&str, 100, 100, 135, 192, "Shop Keeper", "../asset/player.png");
//    this->npcList.push_back(npc);
}

void Garden::GameManagement::handleEvent() {
    if (this->event.type == sf::Event::Closed) {
        this->window.close();
        this->isEnable = false;
    }
    player.playerEvent(this->event);
}

bool Garden::GameManagement::gameLogic() {
    this->deltaTime = deltaClock.getElapsedTime().asSeconds();
    window.clear(this->clearColor);
    while (window.pollEvent(this->event)) {
        handleEvent();
        mapContent[scene]->handleEvent(this->event, player);
    }
    mapContent[scene]->renderGraphic(this->window, player);
    if (this->deltaTime > 1.00 / 60) {
        this->deltaClock.restart();
        while (this->deltaTime > 1.00 / 60) {
            mapContent[scene]->handleMovement(this->window, player);
            this->deltaTime -= 1.00 / 60;
        }
    }
    window.display();
    return this->isEnable;
}

void Garden::GameManagement::graphicDisplay() {
    if (!plotList.empty()) {
        if (this->clock.getElapsedTime().asSeconds() >= 5) {
            for (int i = 0; i < this->plotList.size(); i++) {
                getPlantIndex(i).get_plant()->updateTick();
            }
            this->clock.restart();
        }
        for (int i = 0; i < plotList.size(); i++) {
            Plot plot = getPlantIndex(i);
            IPlant *tmp = plot.get_plant();
            if (tmp == nullptr) {
                continue;
            }
            if (tmp->is_fully_grown()) {
                sf::Sprite sprite(tmp->get_fully_grown_texture());
                this->window.draw(sf::Sprite(tmp->get_fully_grown_texture()));
            } else {
                sf::Sprite sprite(tmp->get_level_one_texture());
                this->window.draw(sf::Sprite(tmp->get_level_one_texture()));
            }
        }
    }
    if (!npcList.empty()) {
        for (int i = 0; i < npcList.size(); i++) {
            Npc npc = getNPCIndex(i);
            npc.renderNpc(window);
        }
    }
}

const std::list<Garden::Plot> &Garden::GameManagement::get_plot_list() const {
    return plotList;
}

const Garden::Player &Garden::GameManagement::get_player() const {
    return player;
}

Garden::GameManagement::~GameManagement() = default;
