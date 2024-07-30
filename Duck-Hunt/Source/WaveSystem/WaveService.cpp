#include "../../Header/WaveSystem/WaveService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Main/GameService.h"

namespace Wave
{
	using namespace Global;
	using namespace Player;
	using namespace Main;
	using namespace Duck;
	int WaveService::ducks_shot_in_current_wave;
	WaveType WaveService::current_wave_type;
	WaveStatus WaveService::current_wave_status;

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
		wave_start_delay = sf::seconds(10);
		display_status_duration = sf::seconds(1);
		display_level_duration = sf::seconds(1);
		display_status_delay = sf::seconds(3);
		display_level_delay = sf::seconds(5);
		start_new_wave = true;
		current_wave_type = WaveType::EASY;
		current_wave_status= WaveStatus::UNPLAYED;
	}

	void WaveService::update()
	{
		if (wave_clock.getElapsedTime() > display_status_delay && start_new_wave == true)
		{
			activateStatusHeader();
			activateDogAnimation();
		}

		if (wave_clock.getElapsedTime() > (display_status_delay + display_status_duration) && start_new_wave == true)
		{
			deactivateStatusHeader();
		}

		if (wave_clock.getElapsedTime() > display_level_delay && start_new_wave == true)
		{
			activateLevelHeader();
		}

		if (wave_clock.getElapsedTime() > (display_level_delay+display_level_duration) && start_new_wave == true)
		{
			deactivateLevelHeader();
		}

		if (start_new_wave==true && wave_clock.getElapsedTime() >= wave_start_delay)
		{
			ServiceLocator::getInstance()->getGameplayService()->changeBackgroundColor(Config::background_blue_texture_path);
			deactivateDogAnimation();
			spawnWaveSystem(current_wave_type);
		}

		for (WaveSystem* wave_system : wave_system_list)
			wave_system->update();

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
		ServiceLocator::getInstance()->getPlayerService()->resetPowerup();
		start_new_wave = false;
		current_wave_status = WaveStatus::UNPLAYED;
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
				current_wave_status = WaveStatus::LOST;
				ServiceLocator::getInstance()->getGameplayService()->changeBackgroundColor(Config::background_red_texture_path);
				ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(sf::Vector2f(880,830), Animation::AnimationType::DOG_MOCKING, MovementDirection::UPDOWN);
				ServiceLocator::getInstance()->getPlayerService()->decreasePlayerHealth();
				ducks_shot_in_current_wave = 0;
			}
			else
			{
				current_wave_status = WaveStatus::WON;

				if (static_cast<int>(current_wave_type) < 2)
				{
					
					ducks_shot_in_current_wave = 0;
					current_wave_type = static_cast<WaveType>(static_cast<int>(current_wave_type) + 1);
				
				}
				else 
				{
					start_new_wave = false;
					GameService::setGameState(GameState::GAMEWINNER);
				}
				
			}
			start_new_wave = true;
			wave_clock.restart();
		}
		else 
		{
			ServiceLocator::getInstance()->getPlayerService()->decreasePlayerHealth();
			current_wave_status = WaveStatus::LOST;
			start_new_wave = false;
			GameService::setGameState(GameState::GAMEOVER);
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

	void WaveService::activateStatusHeader()
	{
		UI::GameplayUI::GameplayUIController::status_header_active = true;
	}

	void WaveService::deactivateStatusHeader()
	{
		UI::GameplayUI::GameplayUIController::status_header_active = false;
	}

	sf::String WaveService::getWaveStatus()
	{
		sf::String message = "";
		if (current_wave_status == WaveStatus::WON)
		{
			return message = "Nice Shooting\nWell Done";
		}
		else if (current_wave_status == WaveStatus::LOST)
		{
			return message = "You failed\nTry Again";
		}
		else
		{
			return message = "";
		}
		
	}


	void WaveService::activateDogAnimation()
	{
		UI::GameplayUI::GameplayUIController::dog_animation_active = true;
	}

	void WaveService::deactivateDogAnimation()
	{
		UI::GameplayUI::GameplayUIController::dog_animation_active = false;
	}

}