#pragma once
#include "../../Header/Gameplay/GameplayView.h"

namespace Gameplay
{
	class GameplayView;

	class GameplayController
	{
	private:
		GameplayView* gameplay_view;

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

	};
}