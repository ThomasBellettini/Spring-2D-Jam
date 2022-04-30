/*
** EPITECH PROJECT, 2022
** Jam_GardenBusiness
** File description:
** Npc.hpp
*/

#include "../Player/Player.hpp"

#ifndef JAM_GARDENBUSINESS_NPC_HPP
#define JAM_GARDENBUSINESS_NPC_HPP

namespace Garden {
    class Npc {
    public:
        Npc(void (*action_performed)(Player), int x, int y, int width,
            int height, const std::string &npc_name,
            const std::string &npc_texture);

        void set_name_tag(const std::string &name_tag);
        void set_hide_name_tag(bool hide_name_tag);
        void set_sound_open(const std::string &sound_open);

        const std::string &get_name_tag() const;
        const std::string &get_npc_name() const;
        bool is_hide_name_tag() const;
        const std::string &get_sound_open() const;
        const std::string &get_npc_texture() const;

        void buildNameTag(sf::RenderWindow &window) const;
        void renderNpc(sf::RenderWindow &window) const;

        void (*actionPerformed) (Garden::Player player);

        virtual ~Npc();

    private:
        int x;
        int y;
        int width;
        int height;

        sf::Texture texture;

        std::string nameTag;
        std::string npcName;
        bool hideNameTag;

        std::string soundOpen;
        std::string npc_texture;

        sf::Text text;
    };
}

#endif //JAM_GARDENBUSINESS_NPC_HPP
