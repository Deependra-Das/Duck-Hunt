#include "../../Header/WaveSystem/WaveService.h"
#include "../../Header/Global/ServiceLocator.h"
namespace Wave
{
	using namespace Global;

	int WaveService::ducks_shot_in_current_wave;
	WaveType WaveService::current_wave_type;

	WaveService::WaveService()
	{
	}

	WaveService::~WaveService()
	{
		destroy();
	}

	void WaveService::initialize() 
	{ 
		ducks_shot_in_current_wave = 0;
		start_delay = sf::seconds(3);
		start_new_wave = true;
		current_wave_type = WaveType::EASY;
		spawnWaveSystem(current_wave_type);
		
	}

	void WaveService::update()
	{
		for (WaveSystem* wave_system : wave_system_list)
			wave_system->update();
		processNextWave();
		destroyFlaggedWaveSystem();
	}

	void WaveService::render()
	{
		for (WaveSystem* wave_system : wave_system_list)
			wave_system->render();
	}

	void WaveService::spawnWaveSystem(WaveType Wave_type)
	{
		WaveSystem* wave_system = new WaveSystem(getWaveSystemConfig(Wave_type));
		wave_system->initialize();
		wave_system_list.push_back(wave_system);
		start_new_wave = false;
	}

	void WaveService::destroyWaveSystem(WaveSystem* Wave_system)
	{
		flagged_wave_system_list.push_back(Wave_system);
		wave_system_list.erase(std::remove(wave_system_list.begin(), wave_system_list.end(), Wave_system), wave_system_list.end());
		start_new_wave = true;
		clock.restart();
	}

	void WaveService::processNextWave()
	{
		if (start_new_wave && clock.getElapsedTime() >= start_delay)
		{
			ServiceLocator::getInstance()->getPlayerService()->decreasePlayerHealth();
			int playerHealth = ServiceLocator::getInstance()->getPlayerService()->getPlayerHealth();

			if (playerHealth > 0)
			{
				if (ducks_shot_in_current_wave < getWaveSystemConfig(current_wave_type).birds_count)
				{
					ducks_shot_in_current_wave = 0;
					spawnWaveSystem(current_wave_type);
				}
				else
				{
					ducks_shot_in_current_wave = 0;
					current_wave_type = static_cast<WaveType>(static_cast<int>(current_wave_type) + 1);
					spawnWaveSystem(current_wave_type);
				}
			}
		}
		
	}

	WaveSystemConfig WaveService::getWaveSystemConfig(WaveType Wave_type)
	{
		switch (Wave_type)
		{
		case Wave::WaveType::EASY:
		{
			const WaveSystemConfig easy_wave_config(1,10,3);
			return easy_wave_config;
		}
		case Wave::WaveType::MEDIUM:
		{
			const WaveSystemConfig medium_wave_config(2, 10, 5);
			return medium_wave_config;
		}
		case Wave::WaveType::HARD:
		{
			const WaveSystemConfig hard_wave_config(3, 10, 7);
			return hard_wave_config;
		}
		}
	}

	void WaveService::destroyFlaggedWaveSystem()
	{
		for (WaveSystem* particle_system : flagged_wave_system_list)
			delete (particle_system);

		flagged_wave_system_list.clear();
	}

	void WaveService::reset() { destroy(); }

	void WaveService::destroy()
	{
		for (WaveSystem* Wave_system : wave_system_list)
			delete (Wave_system);
	}

	void WaveService::updateDucksShot(int shot)
	{
		WaveService::ducks_shot_in_current_wave += shot;
	}


}