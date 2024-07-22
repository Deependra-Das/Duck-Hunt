#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/WaveSystem/WaveService.h"
#include "../../header/WaveSystem/WaveSystem.h"
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

        friend void UI::GameplayUI::GameplayUIController::updateScoreText();
        friend void UI::GameplayUI::GameplayUIController::drawPlayerLivesImage();
        friend void UI::GameplayUI::GameplayUIController::drawPlayerAmmoImage();
        friend void UI::GameplayUI::GameplayUIController::updatePowerupCountText();
        friend void UI::GameplayUI::GameplayUIController::drawPowerupImage();
        friend void Wave::WaveService::processNextWave();
        friend void Wave::WaveSystem::setPlayerAmmoCount();

        const int max_player_lives = 3;
        static int player_lives;
        static int player_score;
        static int ducks_shot;
        static int ammo_count;
        static int radial_shot;
        static bool is_radial_shot_activated;
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

        void setMaxAmmo();

    };
}
