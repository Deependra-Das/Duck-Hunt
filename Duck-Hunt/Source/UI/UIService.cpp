#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenuUI;
	using namespace Interface;
	using namespace UIElement;

	UIService::UIService()
	{
		main_menu_controller = nullptr;

		createControllers();
	}

	UIService::~UIService()
	{
		destroyControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();

	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::initializeControllers()
	{

		main_menu_controller->initialize();

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

		default:
			return nullptr;
		}
	}

	void UIService::destroyControllers()
	{
		delete(main_menu_controller);
	}

}