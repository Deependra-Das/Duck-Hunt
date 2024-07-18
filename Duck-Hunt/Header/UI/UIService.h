#pragma once

#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenuUI::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroyControllers();

		Interface::IUIController* getCurrentUIController();


	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}