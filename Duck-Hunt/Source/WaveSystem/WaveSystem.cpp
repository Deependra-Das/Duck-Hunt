#include "../../Header/WaveSystem/WaveSystem.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/WaveSystem/WaveService.h"
#include "../../Header/Player/PlayerModel.h"

namespace Wave
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Player;

	WaveSystem::WaveSystem(WaveSystemConfig config)
	{
		wave_system_config = config;
		wave_timer = sf::seconds(wave_system_config.round_duration);
	}

	WaveSystem::~WaveSystem()
	{

	}

	void WaveSystem::initialize()
	{
		setPlayerAmmoCount();

		for (int count = 0; count < wave_system_config.birds_count; count++)
		{
			ServiceLocator::getInstance()->getDuckService()->SpawnDuck();
		}
		
	}

	void WaveSystem::update()
	{
		if (clock.getElapsedTime() >= wave_timer)
		{
			destroy();
			clock.restart();
		}
	}

	void WaveSystem::render()
	{

	}

	void WaveSystem::destroy()
	{
		ServiceLocator::getInstance()->getDuckService()->reset();
		ServiceLocator::getInstance()->getWaveService()->destroyWaveSystem(this);
	}

	void WaveSystem::setPlayerAmmoCount()
	{
		PlayerModel::ammo_count = wave_system_config.birds_count;
	}

}