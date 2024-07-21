#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global
{
	using namespace Main;
	using namespace Graphics;
	using namespace Event;
	using namespace UI;
	using namespace Gameplay;
	using namespace Time;
	using namespace Duck;
	using namespace Player;
	using namespace Wave;
	using namespace Sound;

	ServiceLocator::ServiceLocator()
	{
		graphics_service = nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		gameplay_service = nullptr;
		time_service = nullptr;
		duck_service = nullptr;
		player_service = nullptr;
		wave_service = nullptr;
		sound_service = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphics_service = new GraphicsService();
		event_service = new EventService();
		ui_service = new UIService();
		gameplay_service = new GameplayService();
		time_service = new TimeService();
		duck_service = new DuckService();
		player_service = new PlayerService();
		wave_service = new WaveService();
		sound_service = new SoundService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphics_service);
		delete(event_service);
		delete(ui_service);
		delete(gameplay_service);
		delete(time_service);
		delete(duck_service);
		delete(player_service);
		delete(wave_service);
		delete(sound_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphics_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		gameplay_service->initialize();
		time_service->initialize();
		duck_service->initialize();
		player_service->initialize();
		wave_service->initialize();
		sound_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphics_service->update();
		event_service->update();
		time_service->update();

		if (Main::GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			duck_service->update();
			player_service->update();
			wave_service->update();
		}

		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphics_service->render();
	
		if (Main::GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			duck_service->render();
			player_service->render();
			wave_service->render();
		}
		ui_service->render();
	}

	GraphicsService* ServiceLocator::getGraphicsService()
	{
		return graphics_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}

	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	DuckService* ServiceLocator::getDuckService()
	{
		return duck_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	WaveService* ServiceLocator::getWaveService()
	{
		return wave_service;
	}

	SoundService* ServiceLocator::getSoundService()
	{
		return sound_service;
	}


	void ServiceLocator::deleteServiceLocator()
	{
		delete(this);
	}
}
