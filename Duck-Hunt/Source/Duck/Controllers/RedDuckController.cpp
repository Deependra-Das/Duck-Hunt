#include "../../Header/Duck/Controllers/RedDuckController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Duck
{
	using namespace Global;

	namespace Controller
	{
		RedDuckController::RedDuckController(DuckType type) : DuckController(type) { }

		RedDuckController::~RedDuckController()
		{

		}

		void RedDuckController::initialize()
		{
			DuckController::initialize();
			duck_model->setMovementDirection(getInitialMovementDirection());
			duck_model->horizontal_movement_speed = red_duck_horizontal_movement_speed;
			
		}

		MovementDirection RedDuckController::getInitialMovementDirection()
		{
			static MovementDirection initial_direction = getRandomDuckDirection();

			switch (initial_direction)
			{
			case Duck::MovementDirection::LEFT_UP:
				initial_direction = MovementDirection::RIGHT_UP;
				return initial_direction;

			case Duck::MovementDirection::RIGHT_UP:
				initial_direction = MovementDirection::LEFT_UP;
				return initial_direction;
			}
		}


		MovementDirection RedDuckController::getRandomDuckDirection()
		{
			int randomType = std::rand() % 2;
			return static_cast<Duck::MovementDirection>(randomType);
		}

		void RedDuckController::move()
		{

			switch (duck_model->getMovementDirection())
			{
			case::Duck::MovementDirection::LEFT_DOWN:
				movelLeftDown();
				break;

			case::Duck::MovementDirection::RIGHT_DOWN:
				moveRightDown();
				break;

			case::Duck::MovementDirection::LEFT_UP:
				moveLeftUp();
				break;

			case::Duck::MovementDirection::RIGHT_UP:
				moveRightUp();
				break;
			}
		}

		void RedDuckController::movelLeftDown()
		{
			sf::Vector2f currentPosition = duck_model->getDuckCurrentPostion();
			currentPosition.y += duck_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= duck_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= duck_model->top_left_position.x)
			{
				duck_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else if (currentPosition.y >= duck_model->bottom_right_position.y)
			{
				duck_model->setMovementDirection(MovementDirection::LEFT_UP);
			}
			else duck_model->setDuckCurrentPostion(currentPosition);
		}

		void RedDuckController::moveRightDown()
		{
			sf::Vector2f currentPosition = duck_model->getDuckCurrentPostion();
			currentPosition.y += duck_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += duck_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= duck_model->bottom_right_position.x)
			{
				duck_model->setMovementDirection(MovementDirection::LEFT_DOWN);
			}
			else if (currentPosition.y >= duck_model->bottom_right_position.y)
			{
				duck_model->setMovementDirection(MovementDirection::RIGHT_UP);
			}
			else duck_model->setDuckCurrentPostion(currentPosition);
		}

		void RedDuckController::moveLeftUp()
		{
			sf::Vector2f currentPosition = duck_model->getDuckCurrentPostion();
			currentPosition.y -= duck_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= duck_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= duck_model->top_left_position.x)
			{
				duck_model->setMovementDirection(MovementDirection::RIGHT_UP);
			}
			else if (currentPosition.y <= duck_model->top_left_position.y)
			{
				duck_model->setMovementDirection(MovementDirection::LEFT_DOWN);
			}
			else duck_model->setDuckCurrentPostion(currentPosition);
		}

		void RedDuckController::moveRightUp()
		{
			sf::Vector2f currentPosition = duck_model->getDuckCurrentPostion();
			currentPosition.y -= duck_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += duck_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= duck_model->bottom_right_position.x)
			{
				duck_model->setMovementDirection(MovementDirection::LEFT_UP);
			}
			else if (currentPosition.y <= duck_model->top_left_position.y)
			{
				duck_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else duck_model->setDuckCurrentPostion(currentPosition);
		}


	}
}