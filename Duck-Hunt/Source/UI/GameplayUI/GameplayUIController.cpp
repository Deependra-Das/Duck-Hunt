#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Global;
        using namespace Player;
        using namespace UI::UIElement;

        bool GameplayUIController::level_header_active;

        GameplayUIController::GameplayUIController() { createUIElements(); }

        GameplayUIController::~GameplayUIController() { destroy(); }

        void GameplayUIController::initialize()
        {
            initializeForegroundImage();
            initializeImage();
            initializeText();
        }

        void GameplayUIController::createUIElements()
        {
            foreground_image = new ImageView();
            player_health_image = new ImageView();
            player_ammo_image = new ImageView();
            score_text = new TextView();
            level_text = new TextView();
        }

        void GameplayUIController::initializeImage()
        {
            player_health_image->initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0, 0));
            player_ammo_image->initialize(Config::ammo_texture_path, ammo_sprite_width, ammo_sprite_height, sf::Vector2f(0, 0));
        }

        void GameplayUIController::initializeForegroundImage()
        {
            foreground_image->initialize(Config::foreground_texture_path, foreground_image_width, foreground_image_height, sf::Vector2f(0, 0));
        }

        void GameplayUIController::initializeText()
        {
            sf::String enemies_killed_string = "SCORE  :  0";
            score_text->initialize(enemies_killed_string, sf::Vector2f(score_text_x_position, score_text_y_position), FontType::Rajdhani, font_size, text_color);

            
            sf::String level_header_string = "LEVEL " + std::to_string(ServiceLocator::getInstance()->getWaveService()->getLevelNumber());
            level_text->initialize(level_header_string, sf::Vector2f(level_text_x_position, level_text_y_position), FontType::Rajdhani, header_font_size, text_color);
        }

        void GameplayUIController::update()
        {
            updateScoreText();

            if (level_header_active == true)
            {
                updateLevelText();
            }
        }

        void GameplayUIController::render()
        {
            foreground_image->render();
            score_text->render();
            drawPlayerLivesImage();
            drawPlayerAmmoImage();

            if (level_header_active == true)
            {
                level_text->render();
            }
        }

        void GameplayUIController::show()
        {
        }


        void GameplayUIController::updateScoreText()
        {
            sf::String score_string = "SCORE  :  " + std::to_string(PlayerModel::ducks_shot);
            score_text->setText(score_string);
        }

        void GameplayUIController::updateLevelText()
        {
            sf::String level_header_string = "LEVEL " + std::to_string(ServiceLocator::getInstance()->getWaveService()->getLevelNumber());
            level_text->setText(level_header_string);
        }

        void GameplayUIController::drawPlayerLivesImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

            for (int i = 0; i < PlayerModel::player_lives; i++)
            {
                player_health_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                player_health_image->render();
            }
        }

        void GameplayUIController::drawPlayerAmmoImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

            for (int i = 0; i < PlayerModel::ammo_count; i++)
            {
                player_ammo_image->setPosition(sf::Vector2f(player_ammo_x_offset + (i * player_ammo_spacing), player_ammo_y_offset));
                player_ammo_image->render();
            }
        }

        void GameplayUIController::destroy()
        {
            delete(foreground_image);
            delete(player_health_image);
            delete(player_ammo_image);
            delete(score_text);
            delete(level_text);
        }

    }
}