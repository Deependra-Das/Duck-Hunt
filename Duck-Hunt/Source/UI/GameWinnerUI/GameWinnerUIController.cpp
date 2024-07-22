#include "../../Header/UI/GameWinnerUI/GameWinnerUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace GameWinnerUI
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;

        GameWinnerUIController::GameWinnerUIController()
        {
            createImage();
            createButtons();
        }

        GameWinnerUIController::~GameWinnerUIController()
        {
            destroy();
        }

        void GameWinnerUIController::initialize()
        {
            initializeBackgroundImage();
            initializeGameWinnerImage();
            //  initializeButtons();
            //  registerButtonCallback();
        }

        void GameWinnerUIController::createImage()
        {
            background_image = new ImageView();
            gameWinner_image_view = new ImageView();
        }

        void GameWinnerUIController::createButtons()
        {
            restart_button = new ButtonView();
            menu_button = new ButtonView();

        }

        void GameWinnerUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

            background_image->initialize(Config::background_white_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_image_alpha);
        }

        void GameWinnerUIController::initializeGameWinnerImage()
        {
            gameWinner_image_view->initialize(Config::winner_texture_path, gameWinner_image_width, gameWinner_image_height, sf::Vector2f(0, gameWinner_image_y_position));
            gameWinner_image_view->setCentreAlinged();
        }


        void GameWinnerUIController::initializeButtons()
        {
            //  restart_button->initialize("Restart Button", Config::restart_button_texture_path, button_width, button_height, sf::Vector2f(0, restart_button_y_position));
          //    menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

            restart_button->setCentreAlinged();
            menu_button->setCentreAlinged();
        }

        void GameWinnerUIController::registerButtonCallback()
        {
            restart_button->registerCallbackFuntion(std::bind(&GameWinnerUIController::RestartButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&GameWinnerUIController::MenuButtonCallback, this));

        }

        void GameWinnerUIController::RestartButtonCallback()
        {
            // ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getGameplayService()->restart();
            GameService::setGameState(GameState::GAMEPLAY);
            // ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
        }

        void GameWinnerUIController::MenuButtonCallback()
        {
            //  ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getPlayerService()->reset();
            ServiceLocator::getInstance()->getGameplayService()->restart();
            GameService::setGameState(GameState::MAIN_MENU);
            //   ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();

        }


        void GameWinnerUIController::restartGameplay()
        {
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void GameWinnerUIController::update()
        {
            background_image->update();
            gameWinner_image_view->update();
            //  restart_button->update();
            //  menu_button->update();
        }

        void GameWinnerUIController::render()
        {
            background_image->render();
            gameWinner_image_view->render();
            //   restart_button->render();
            //   menu_button->render();
        }

        void GameWinnerUIController::show()
        {
            background_image->show();
            gameWinner_image_view->show();
            //  restart_button->show();
           //   menu_button->show();

        }

        void GameWinnerUIController::destroy()
        {
            // delete (restart_button);
           //  delete (menu_button);
            delete (background_image);
            delete (gameWinner_image_view);
        }
    }
}