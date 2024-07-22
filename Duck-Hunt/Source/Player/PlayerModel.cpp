#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;

	int PlayerModel::player_lives;
	int PlayerModel::player_score;
	int PlayerModel::ammo_count;
	int PlayerModel::ducks_shot;
	int PlayerModel::radial_shot;
	bool PlayerModel::is_radial_shot_activated;

	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		setMaxAmmo();
		player_lives = max_player_lives;
		player_score = 0;
		is_radial_shot_activated = false;
		radial_shot = 1;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	void PlayerModel::setMaxAmmo()
	{
		ammo_count=ServiceLocator::getInstance()->getWaveService()->getTotalDuckCount();
	}

}
