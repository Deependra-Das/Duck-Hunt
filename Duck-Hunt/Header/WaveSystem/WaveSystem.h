#pragma once

#include "../../Header/WaveSystem/WaveSystemConfig.h"

namespace Wave
{
	class WaveSystem
	{
	private:
		WaveSystemConfig wave_system_config;
		sf::Clock clock;
		sf::Time wave_timer;

	public:
		WaveSystem(WaveSystemConfig config);
		~WaveSystem();

		void initialize();
		void update();
		void render();
		void destroy();
	};
}