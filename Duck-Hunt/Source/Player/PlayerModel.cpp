#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::player_lives;
	int PlayerModel::ducks_shot;
	int PlayerModel::current_ammo_count;

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
		player_lives = max_player_lives;
		current_ammo_count = max_ammo_count;
		ducks_shot = 0;
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

	int PlayerModel::getPlayerLives()
	{
		return player_lives;
	}

	void PlayerModel::setPlayerLives(int lives)
	{
		player_lives += lives;
	}

	int PlayerModel::getPlayerAmmo()
	{
		return current_ammo_count;
	}

	void PlayerModel::setPlayerAmmo(int ammo)
	{
		current_ammo_count += ammo;
	}

}
