#pragma once

#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/WaveSystem/WaveService.h"

namespace UI
{
    namespace GameplayUI
    {
        class GameplayUIController : public Interface::IUIController
        {
        private:

            friend void Wave::WaveService::activateLevelHeader();
            friend void Wave::WaveService::deactivateLevelHeader();
            friend void Wave::WaveService::activateStatusHeader();
            friend void Wave::WaveService::deactivateStatusHeader();

            const int small_font_size = 20;
            const int font_size = 24;
            const int header_font_size = 56;
            const float score_text_y_position = 1000.f;
            const float score_text_x_position = 880.f;

            const float level_text_y_position = 500.f;
            const float level_text_x_position = 880.f;

            const float player_lives_y_offset = 1000.f;
            const float player_lives_x_offset = 1850.f;
            const float player_lives_spacing = 40.f;

            const float player_ammo_y_offset = 1000.f;
            const float player_ammo_x_offset = 10.f;
            const float player_ammo_spacing = 20.f;

            const float player_sprite_width = 32.f;
            const float player_sprite_height = 24.f;

            const float ammo_sprite_width = 32.f;
            const float ammo_sprite_height = 32.f;

            const float powerup_text_y_position = 1002.f;
            const float powerup_text_x_position = 250.f;
            const float powerup_x_offset = 200.f;

            static bool level_header_active;
            static bool status_header_active;
            const sf::Color text_color = sf::Color::White;

            const float foreground_image_width = 1920.0f;
            const float foreground_image_height = 1080.0f;

            UI::UIElement::ImageView* foreground_image;
            UI::UIElement::ImageView* player_health_image;
            UI::UIElement::ImageView* player_ammo_image;
            UI::UIElement::ImageView* powerup_aimed_shot_image;
            UI::UIElement::TextView* score_text;
            UI::UIElement::TextView* level_text;
            UI::UIElement::TextView* status_text;
            UI::UIElement::TextView* powerup_count_text;

            UI::UIElement::ImageView* dog_image;

            float spacing;

            void createUIElements();
            void initializeImage();
            void initializeForegroundImage();
            void initializeText();
            void destroy();

        public:
            GameplayUIController();
            ~GameplayUIController();

            void initialize() override;
            void update() override;
            void render() override;
            void show() override;

            void updateScoreText();
            void updateLevelText();
            void updateStatusText();
            void drawPlayerLivesImage();
            void drawPlayerAmmoImage();
            void drawPowerupImage();
            void updatePowerupCountText();
        };
    }
}

