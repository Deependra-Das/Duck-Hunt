#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace Duck
{
	class DuckController;
	enum class DuckType;

	class DuckService
	{
	private:
		std::vector<DuckController*> duck_list;
		std::vector<DuckController*> flagged_duck_list;
		const float spawn_interval = 2.0f;
		float spawn_timer;

		DuckController* createDuck(DuckType enemy_type);

		void destroyFlaggedDucks();
		void destroy();

	public:
		DuckService();
		virtual ~DuckService();

		void initialize();
		void update();
		void render();
		void reset();

		DuckController* SpawnDuck(DuckType type);

		int clickedonBird(sf::Vector2f mouse_position);

		void destroyDuck(DuckController* duck_controller);

		bool inRangeDucks(sf::Vector2f enemy1pos, sf::Vector2f enemy2pos, int radius);

		int killNearbyDucks(sf::Vector2f position);
	};
}