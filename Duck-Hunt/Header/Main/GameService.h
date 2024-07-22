#pragma once

#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
		GAMEOVER,
		GAMEWINNER,
	};

	class GameService
	{
	private:
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;
		static GameState current_state;

		void initialize();
		void initializeVariables();
		void showMainMenu();
		void destroy();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}
