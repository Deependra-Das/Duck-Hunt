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

        int getPlayerScore();
        void setPlayerScore(int score);

    };
}
