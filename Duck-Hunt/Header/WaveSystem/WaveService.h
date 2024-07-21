#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/WaveSystem/WaveSystem.h"

namespace Wave
{
	enum class WaveType
	{
		EASY,
		MEDIUM,
		HARD,
	};

	class WaveService
	{
	private:
		std::vector<WaveSystem*> wave_system_list;
		std::vector<WaveSystem*> flagged_wave_system_list;
		static int ducks_shot_in_current_wave;
		static WaveType current_wave_type;
		bool start_new_wave;
		sf::Clock clock;
		sf::Clock level_clock;
		sf::Time start_delay;
		sf::Time level_delay;
		WaveSystemConfig getWaveSystemConfig(WaveType wave_type);
		void destroyFlaggedWaveSystem();
		void destroy();

	public:
		WaveService();
		virtual ~WaveService();

		void initialize();
		void update();
		void render();

		void reset();

		void spawnWaveSystem(WaveType wave_type);
		void destroyWaveSystem(WaveSystem* wave_system);
		void updateDucksShot(int shot);
		void processNextWave();
		int getTotalDuckCount();
		int getLevelNumber();
		void activateLevelHeader();
		void deactivateLevelHeader();
	};
}