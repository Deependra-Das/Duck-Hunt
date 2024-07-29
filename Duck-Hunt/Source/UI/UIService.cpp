#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenuUI;
	using namespace Interface;
	using namespace UIElement;
	using namespace GameplayUI;
	using namespace GameOverUI;
	using namespace GameWinnerUI;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		game_over_ui_controller = nullptr;
		createControllers();
	}

	UIService::~UIService()
	{
		destroyControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
		game_over_ui_controller = new GameOverUIController();
		game_winner_ui_controller = new GameWinnerUIController();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
		game_over_ui_controller->initialize();
		game_winner_ui_controller->initialize();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->update();
		}

	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->render();
		}
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->show();
		}
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::GAMEOVER:
			return game_over_ui_controller;

		case GameState::GAMEWINNER:
			return game_winner_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroyControllers()
	{
		delete(main_menu_controller);
		delete(gameplay_ui_controller);
		delete(game_over_ui_controller);
	}

	void UIService::updateDogAnimation(UI::UIElement::AnimationType a_type)
	{
		gameplay_ui_controller->updateDogAnimation(a_type);
	}
}