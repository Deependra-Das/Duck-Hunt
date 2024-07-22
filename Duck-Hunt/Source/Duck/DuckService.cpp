#include "../../Header/Duck/DuckService.h"
#include "../../Header/Duck/DuckController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Duck/Controllers/RedDuckController.h"
#include "../../Header/Duck/Controllers/BlackDuckController.h"

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

	}

	void DuckService::update()
	{
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

	DuckController* DuckService::SpawnDuck(DuckType type)
	{
		DuckController* Duck_controller = createDuck(type);
		Duck_controller->initialize();

		duck_list.push_back(Duck_controller);
		return Duck_controller;
	}

	DuckController* DuckService::createDuck(DuckType Duck_type)
	{
		switch (Duck_type)
		{
		case::Duck::DuckType::RED:
			return new RedDuckController(Duck::DuckType::RED);

		case::Duck::DuckType::BLACK:
			return new BlackDuckController(Duck::DuckType::BLACK);

		}
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


	int DuckService::pointClickedOnDuck(sf::Vector2f mouse_position)
	{
		int duck_shot = 0, b_duck_shot=0, r_duck_shot=0;
		int score = 0; sf::Vector2f red_duck_position= sf::Vector2f(- 1, -1);

		for (int i = 0; i < duck_list.size(); i++)
		{
			if (duck_list[i]->getDuckSprite().getGlobalBounds().contains(mouse_position))
			{
				if (duck_list[i]->getDuckType() == DuckType::RED)
				{
					r_duck_shot++;
					ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(duck_list[i]->getDuckPosition(), Animation::AnimationType::RED_DUCK_FALL, MovementDirection::DOWN);
					red_duck_position = duck_list[i]->getDuckPosition();
					destroyDuck(duck_list[i]);
				
				}
				else if (duck_list[i]->getDuckType() == DuckType::BLACK)
				{
					b_duck_shot++;
					ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(duck_list[i]->getDuckPosition(), Animation::AnimationType::BLACK_DUCK_FALL, MovementDirection::DOWN);
					destroyDuck(duck_list[i]);
				}
			}
			
		}

		if (r_duck_shot > 0)
		{
			b_duck_shot+=killNearbyDucks(red_duck_position);
		}

		duck_shot = r_duck_shot + b_duck_shot;
		score = (r_duck_shot * 200) + (b_duck_shot * 100);

		ServiceLocator::getInstance()->getPlayerService()->increaseDucksShot(duck_shot);
		ServiceLocator::getInstance()->getWaveService()->updateDucksShot(duck_shot);
		return score;

	}

	int DuckService::killNearbyDucks(sf::Vector2f position)
	{
		int duck_shot = 0;

		for (int i = 0; i < duck_list.size(); i++)
		{
			if (inRangeDucks(position, duck_list[i]->getDuckPosition(), 500))
			{
				if (duck_list[i]->getDuckType() == DuckType::BLACK)
				{
					duck_shot++;
					ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(duck_list[i]->getDuckPosition(), Animation::AnimationType::BLACK_DUCK_FALL, MovementDirection::DOWN);
					destroyDuck(duck_list[i]);
				}
					
			}
		}

		return duck_shot;

	}

	int DuckService::radialClickOnDuck(sf::Vector2f mouse_position)
	{
		int duck_shot = 0, b_duck_shot = 0, r_duck_shot = 0;
		int score = 0; sf::Vector2f red_duck_position = sf::Vector2f(-1, -1);

		for (int i = 0; i < duck_list.size(); i++)
		{
			if (inRangeDucks(mouse_position, duck_list[i]->getDuckPosition(),500))
			{
				if (duck_list[i]->getDuckType() == DuckType::RED)
				{
					r_duck_shot++;
					ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(duck_list[i]->getDuckPosition(), Animation::AnimationType::RED_DUCK_FALL, MovementDirection::DOWN);
					red_duck_position = duck_list[i]->getDuckPosition();
					destroyDuck(duck_list[i]);

				}
				else if (duck_list[i]->getDuckType() == DuckType::BLACK)
				{
					b_duck_shot++;
					ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(duck_list[i]->getDuckPosition(), Animation::AnimationType::BLACK_DUCK_FALL, MovementDirection::DOWN);
					destroyDuck(duck_list[i]);
				}
			}

		}

	/*	if (r_duck_shot > 0)
		{
			b_duck_shot += killNearbyDucks(red_duck_position);
		}*/

		duck_shot = r_duck_shot + b_duck_shot;
		score = (r_duck_shot * 200) + (b_duck_shot * 100);

		ServiceLocator::getInstance()->getPlayerService()->increaseDucksShot(duck_shot);
		ServiceLocator::getInstance()->getWaveService()->updateDucksShot(duck_shot);
		return score;

	}

	bool DuckService::inRangeDucks(sf::Vector2f pos1, sf::Vector2f pos2, int radius)
	{
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;

		bool x= (dx * dx + dy * dy) < (radius * radius);

		return x;
	}


}
