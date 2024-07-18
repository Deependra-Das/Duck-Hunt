#include "../../Header/Duck/DuckService.h"
#include "../../Header/Duck/DuckController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Duck/Controllers/RedDuckController.h"

namespace Duck
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	DuckService::DuckService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	DuckService::~DuckService()
	{
		destroy();
	}

	void DuckService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void DuckService::update()
	{
		updateSpawnTimer();
		processDuckSpawn();

		for (int i = 0; i < duck_list.size(); i++)
		{
			duck_list[i]->update();
		}
		destroyFlaggedDucks();
	}

	void DuckService::render()
	{
		for (int i = 0; i < duck_list.size(); i++)
		{
			duck_list[i]->render();
		}
	}

	DuckController* DuckService::SpawnDuck()
	{
		DuckController* Duck_controller = createDuck(getRandomDuckType());
		Duck_controller->initialize();

		duck_list.push_back(Duck_controller);
		return Duck_controller;
	}

	void DuckService::processDuckSpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			SpawnDuck();
			spawn_timer = 0.0f;
		}
	}

	void DuckService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	DuckController* DuckService::createDuck(DuckType Duck_type)
	{
		switch (Duck_type)
		{
		case::Duck::DuckType::RED:
			return new RedDuckController(Duck::DuckType::RED);


		}
	}

	DuckType DuckService::getRandomDuckType()
	{
		int randomType = std::rand() % 1;
		return static_cast<Duck::DuckType>(randomType);
	}


	void DuckService::destroyFlaggedDucks()
	{
		for (int i = 0; i < flagged_duck_list.size(); i++)
		{
			delete (flagged_duck_list[i]);
		}
		flagged_duck_list.clear();
	}

	void DuckService::destroyDuck(DuckController* Duck_controller)
	{
		flagged_duck_list.push_back(Duck_controller);
		duck_list.erase(std::remove(duck_list.begin(), duck_list.end(), Duck_controller), duck_list.end());
	}

	void DuckService::destroy()
	{

		for (int i = 0; i < duck_list.size(); i++)
		{
			delete (duck_list[i]);
		}
		duck_list.clear();
	}

	void DuckService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	void DuckService::clickedonBird(sf::Vector2f mouse_position)
	{
		for (int i = 0; i < duck_list.size(); i++)
		{
			if (duck_list[i]->getDuckSprite().getGlobalBounds().contains(mouse_position))
			{
				destroyDuck(duck_list[i]);
			}
		}

	}



}
