#include "../../Header/WaveSystem/WaveService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace Wave
{
	using namespace Global;
	using namespace Player;

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
		start_delay = sf::seconds(5);
		level_delay = sf::seconds(0.5);
		start_new_wave = true;
		activateLevelHeader();
		current_wave_type = WaveType::EASY;
	}

	void WaveService::update()
	{
		if (level_clock.getElapsedTime() >= level_delay && start_new_wave==false)
		{
			deactivateLevelHeader();
		}

		for (WaveSystem* wave_system : wave_system_list)
			wave_system->update();
		if (start_new_wave && clock.getElapsedTime() >= start_delay)
		{
			spawnWaveSystem(current_wave_type);
		}

		destroyFlaggedWaveSystem();
	}

	void WaveService::render()
	{
		for (WaveSystem* wave_system : wave_system_list)
			wave_system->render();
	}

	void WaveService::spawnWaveSystem(WaveType Wave_type)
	{
		level_clock.restart();
		ServiceLocator::getInstance()->getGameplayService()->changeBackgroundColor(Config::background_blue_texture_path);
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
		processNextWave();
	
	}


	void WaveService::processNextWave()
	{
		if (PlayerModel::player_lives > 1)
		{
			if (ducks_shot_in_current_wave < getWaveSystemConfig(current_wave_type).total_birds_count)
			{					
				ServiceLocator::getInstance()->getGameplayService()->changeBackgroundColor(Config::background_red_texture_path);
				ServiceLocator::getInstance()->getPlayerService()->decreasePlayerHealth();
				ducks_shot_in_current_wave = 0;
			}
			else
			{
				if (static_cast<int>(current_wave_type) < 2)
				{
					ducks_shot_in_current_wave = 0;
					current_wave_type = static_cast<WaveType>(static_cast<int>(current_wave_type) + 1);
					activateLevelHeader();
				}
				else 
				{
					start_new_wave = false;

				}
				
			}
			clock.restart();
		}
		else 
		{
			ServiceLocator::getInstance()->getPlayerService()->decreasePlayerHealth();
			start_new_wave = false;
		}
		
	}

	WaveSystemConfig WaveService::getWaveSystemConfig(WaveType Wave_type)
	{
		switch (Wave_type)
		{
		case Wave::WaveType::EASY:
		{
			const WaveSystemConfig easy_wave_config(1,10,3,2,1);
			return easy_wave_config;
		}
		case Wave::WaveType::MEDIUM:
		{
			const WaveSystemConfig medium_wave_config(2, 10, 5,4,1);
			return medium_wave_config;
		}
		case Wave::WaveType::HARD:
		{
			const WaveSystemConfig hard_wave_config(3, 10, 7,6,1);
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

	int WaveService::getTotalDuckCount()
	{
		return getWaveSystemConfig(current_wave_type).total_birds_count;
	}

	int WaveService::getLevelNumber()
	{
		return getWaveSystemConfig(current_wave_type).round_number;
	}

	void WaveService::activateLevelHeader()
	{
		UI::GameplayUI::GameplayUIController::level_header_active = true;
	}

	void WaveService::deactivateLevelHeader()
	{
		UI::GameplayUI::GameplayUIController::level_header_active = false;
	}

}