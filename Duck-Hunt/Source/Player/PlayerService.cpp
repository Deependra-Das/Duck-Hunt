#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;

	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete (player_controller);
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
	
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}

	void PlayerService::increaseDucksShot(int val)
	{
		player_controller->increaseDucksShot(val);
	}

	void PlayerService::decreasePlayerHealth()
	{
		player_controller->decreasePlayerLive();
	}

}