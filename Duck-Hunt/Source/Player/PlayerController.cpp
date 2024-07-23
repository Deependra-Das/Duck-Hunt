#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"
#include<algorithm>


namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Main;
	using namespace Sound;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();;
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

		sf::Vector2i mouse_position = sf::Vector2i(sf::Mouse::getPosition(*game_window));
		sf::Vector2f mouseCoord { game_window->mapPixelToCoords(mouse_position) };


		if (event_service->pressedAKey() && PlayerModel::is_radial_shot_activated==true && PlayerModel::radial_shot>0)
		{
			PlayerModel::is_radial_shot_activated = false;
		}
		else if (event_service->pressedAKey() && PlayerModel::is_radial_shot_activated == false && PlayerModel::radial_shot > 0)
		{
			PlayerModel::is_radial_shot_activated = true;
		}

		if (PlayerModel::is_radial_shot_activated == true && PlayerModel::radial_shot > 0)
		{
			mouseCoord.x -= 125; mouseCoord.y -= 125;
			player_model->setPlayerPosition(mouseCoord);
		}

		if (event_service->pressedLeftMouseButton())
		{
			processBulletFire(mouseCoord);
		}

	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		switch (player_model->getPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			processPlayerInput();
			break;
		}

		player_view->update();
	}

	void PlayerController::render()
	{
		if (PlayerModel::is_radial_shot_activated == true)
		{
			player_view->render();
		}
	
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::processBulletFire(sf::Vector2f mouse_position)
	{
		if (PlayerModel::ammo_count > 0)
		{	
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BULLET_FIRE);

		if (PlayerModel::is_radial_shot_activated && PlayerModel::radial_shot > 0)
		{
			PlayerModel::player_score += ServiceLocator::getInstance()->getDuckService()->radialClickOnDuck(mouse_position);
			PlayerModel::is_radial_shot_activated = false;
			PlayerModel::radial_shot = 0;
		}
		else 
		{
			PlayerModel::player_score += ServiceLocator::getInstance()->getDuckService()->pointClickedOnDuck(mouse_position);

		}
	
	
			decreasePlayerAmmo();
		}	
	}

	void PlayerController::decreasePlayerLive()
	{
		if (PlayerModel::player_lives > 0)
		{
			PlayerModel::player_lives -= 1;
		}
	}

	void PlayerController::decreasePlayerAmmo()
	{
	
		if (PlayerModel::ammo_count > 0)
		{
			PlayerModel::ammo_count -= 1;
		}
	}

}