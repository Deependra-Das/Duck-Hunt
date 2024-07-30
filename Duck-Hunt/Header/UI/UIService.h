#pragma once

#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/UI/GameOverUI/GameOverUIController.h"
#include "../../Header/UI/GameWinnerUI/GameWinnerUIController.h"
#include "../../Header/UI/InstructionsUI/InstructionsUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenuUI::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		GameOverUI::GameOverUIController* game_over_ui_controller;
		GameWinnerUI::GameWinnerUIController* game_winner_ui_controller;
		InstructionsUI::InstructionsUIController* instructions_ui_controller;

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

		void updateDogAnimation(UI::UIElement::AnimationType a_type);
	};
}