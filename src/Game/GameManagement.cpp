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
    this->isPlacing = false;
    this->scene = GARDEN;
    this->clearColor = _clearColor;
    this->isEnable = true;

//    IPlant *plant = new APlant("Colza", "A beautiful yellow plant", 5.0, false, "../asset/colza.png",
//                  "../asset/colza.png", "../asset/colza.png");
//    Pot plot (10, 15, 0, 0);
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
    if (this->event.type == sf::Event::KeyPressed) {
        if (this->event.key.code == sf::Keyboard::F1)
            setScene(GARDEN);
        if (this->event.key.code == sf::Keyboard::F2)
            setScene(HOUSE);
        if (!this->isPlacing && this->event.key.code == sf::Keyboard::R) {
            window.setMouseCursorVisible(false);
            this->isPlacing = true;
        }
        if (this->isPlacing && this->event.key.code == sf::Keyboard::Escape) {
            window.setMouseCursorVisible(true);
            this->isPlacing = false;
        }
    }
    if (this->event.type == sf::Event::MouseButtonPressed) {
        window.setMouseCursorVisible(true);
        this->isPlacing = false;
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
    if (this->deltaTime > 1.00 / 60) {
        this->deltaClock.restart();
        while (this->deltaTime > 1.00 / 60) {
            mapContent[scene]->handleMovement(this->window, player);
            this->deltaTime -= 1.00 / 60;
        }
    }
    playerCollision();
    mapContent[scene]->renderGraphic(this->window, player);
    if (this->isPlacing)
        renderPlacingPot(sf::Mouse::getPosition());
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
            Pot plot = getPlantIndex(i);
            IPlant *tmp = plot.get_plant();
            if (tmp == nullptr) {
                continue;
            }
            window.draw(sf::Sprite (tmp->getStateTexture(tmp->getState())));
        }
    }
    if (!npcList.empty()) {
        for (int i = 0; i < npcList.size(); i++) {
            Npc npc = getNPCIndex(i);
            npc.renderNpc(window);
        }
    }
}

const std::list<Garden::Pot> &Garden::GameManagement::get_plot_list() const {
    return plotList;
}

const Garden::Player &Garden::GameManagement::get_player() const {
    return player;
}

void Garden::GameManagement::setScene(Garden::Scene scene) {
    this->scene = scene;
}

void Garden::GameManagement::playerCollision() {
    if (scene == GARDEN) {
        if (player.getPosX() > 550)
            player.setPosX(550);
        if (player.getPosX() < 100) {
            if (player.getPosY() > 500 && player.getPosY() < 700) {
                scene = HOUSE;
                player.setPosX(620);
                return;
            }
            player.setPosX(100);
        }
        if (player.getPosY() > 1050)
            player.setPosY(1050);
        if (player.getPosY() < 200)
            player.setPosY(200);
    }
    if (scene == HOUSE) {
        if (player.getPosX() > 620) {
            if (player.getPosY() > 500 && player.getPosY() < 700) {
                scene = GARDEN;
                player.setPosX(100);
                return;
            }
            player.setPosX(620);
        }
        if (player.getPosX() < 50)
            player.setPosX(50);
        if (player.getPosY() > 1120)
            player.setPosY(1120);
        if (player.getPosY() < 90)
            player.setPosY(90);
    }
}

void Garden::GameManagement::renderPlacingPot(sf::Vector2<INT> position) {
    sf::Texture texture;
    texture.loadFromFile("./asset/pot.png");
    sf::Sprite sprite (texture);
    sprite.setScale(0.1, 0.1);
    sprite.setPosition((float)position.x - 320, (float)position.y - 150);
    window.draw(sprite);
}

Garden::GameManagement::~GameManagement() = default;
