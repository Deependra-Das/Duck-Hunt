#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Gameplay/GameplayView.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{
		gameplay_view = new GameplayView();
	}

	GameplayController::~GameplayController()
	{
		delete(gameplay_view);
		gameplay_view = nullptr;
	}

	void GameplayController::initialize()
	{
		gameplay_view->initialize();
	}

	void GameplayController::update()
	{
		gameplay_view->update();
	}

	void GameplayController::render()
	{
		gameplay_view->render();
	}
}