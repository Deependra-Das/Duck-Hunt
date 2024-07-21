#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;

	class PlayerController
	{
	private:
		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;
		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		PlayerModel* player_model;
		PlayerView* player_view;

		void processPlayerInput();
		void moveLeft();
		void moveRight();

		void processBulletFire(sf::Vector2f position);
		bool clickedBird(sf::Sprite* button_sprite, sf::Vector2f mouse_position);;
		void fireBullet();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		void reset();

		sf::Vector2f getPlayerPosition();
		PlayerState getPlayerState();

		void decreasePlayerLive();
		void decreasePlayerAmmo();
		inline void increaseDucksShot(int val) { PlayerModel::ducks_shot += val; }

	};
}