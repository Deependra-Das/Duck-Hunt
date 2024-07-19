#pragma once

#include <SFML/Graphics.hpp>

namespace Player
{
    enum class PlayerState
    {
        ALIVE,
        DEAD,
    };

    class PlayerModel
    {
    private:

        friend class PlayerController;

        const int max_player_lives = 3;
        static int player_lives;
        static int ducks_shot;
        const int max_ammo_count = 5;
        static int current_ammo_count;
        sf::Vector2f player_position;
        PlayerState player_state;

    public:

        PlayerModel();
        ~PlayerModel();

        void initialize();

        void reset();

        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

        PlayerState getPlayerState();
        void setPlayerState(PlayerState state);

        int getPlayerLives();
        void setPlayerLives(int lives);

        int getPlayerAmmo();
        void setPlayerAmmo(int ammo);

    };
}
