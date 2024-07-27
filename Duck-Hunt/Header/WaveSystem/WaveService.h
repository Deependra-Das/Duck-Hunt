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

	enum class WaveStatus
	{
		UNPLAYED,
		WON,
		LOST,

	};

	class WaveService
	{
	private:
		std::vector<WaveSystem*> wave_system_list;
		std::vector<WaveSystem*> flagged_wave_system_list;
		static int ducks_shot_in_current_wave;
		static WaveType current_wave_type;
		static WaveStatus current_wave_status;
		bool start_new_wave;
		sf::Clock wave_clock;
		sf::Time wave_start_delay;
		sf::Time display_status_duration;
		sf::Time display_level_duration;
		sf::Time display_status_delay;
		sf::Time display_level_delay;
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
		void activateStatusHeader();
		void deactivateStatusHeader();
		sf::String getWaveStatus();
	};
}