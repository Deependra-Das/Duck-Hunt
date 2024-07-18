#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace MainMenuUI
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;

        MainMenuUIController::MainMenuUIController()
        {
            createImage();
            createButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeGameLogoImage();
            initializeButtons();
            registerButtonCallback();
        }

        void MainMenuUIController::createImage()
        {
            background_image = new ImageView();
            game_logo_view = new ImageView();
        }

        void MainMenuUIController::createButtons()
        {
            play_button = new ButtonView();
            instructions_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

        /*    background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_image_alpha);*/
        }

        void MainMenuUIController::initializeGameLogoImage()
        {
            game_logo_view->initialize(Config::game_logo_texture_path, game_logo_width, game_logo_height, sf::Vector2f(0, game_logo_y_position));
            game_logo_view->setCentreAlinged();
        }

        void MainMenuUIController::initializeButtons()
        {
            play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
            instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

            play_button->setCentreAlinged();
            instructions_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void MainMenuUIController::registerButtonCallback()
        {
            play_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
            instructions_button->registerCallbackFuntion(std::bind(&MainMenuUIController::instructionsButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
        
            GameService::setGameState(GameState::GAMEPLAY);
       
        }

        void MainMenuUIController::instructionsButtonCallback()
        {
         //   GameService::setGameState(GameState::INSTRUCTIONS);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicsService()->getGameWindow()->close();
        }

        void MainMenuUIController::update()
        {
           // background_image->update();
            game_logo_view->update();
            play_button->update();
            instructions_button->update();
            quit_button->update();
        }

        void MainMenuUIController::render()
        {
           // background_image->render();
            game_logo_view->render();
            play_button->render();
            instructions_button->render();
            quit_button->render();
        }

        void MainMenuUIController::show()
        {
          //  background_image->show();
            game_logo_view->show();
            play_button->show();
            instructions_button->show();
            quit_button->show();

        }

        void MainMenuUIController::destroy()
        {
            delete (play_button);
            delete (instructions_button);
            delete (quit_button);
          //  delete (background_image);
            delete (game_logo_view);
        }
    }
}