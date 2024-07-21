#pragma once

#include "../../Header/Gameplay/GameplayController.h"

namespace Gameplay
{
	class GameplayService
	{
	private:
		GameplayController* gameplay_Controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void restart();

		void changeBackgroundColor(sf::String texture_path);
	};
}