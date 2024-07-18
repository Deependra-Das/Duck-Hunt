#pragma once

namespace Player
{
	class PlayerController;

	class PlayerService
	{
	private:
		PlayerController* player_controller;

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void reset();
		void increaseEnemiesKilled(int val);
	};
}