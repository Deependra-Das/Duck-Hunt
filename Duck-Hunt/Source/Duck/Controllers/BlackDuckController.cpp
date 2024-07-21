#include "../../Header/Duck/Controllers/BlackDuckController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Duck
{
	using namespace Global;

	namespace Controller
	{
		BlackDuckController::BlackDuckController(DuckType type) : DuckController(type) { }

		BlackDuckController::~BlackDuckController()
		{

		}

		void BlackDuckController::initialize()
		{
			DuckController::initialize();
			duck_model->setMovementDirection(getInitialMovementDirection());
			duck_model->horizontal_movement_speed = black_duck_horizontal_movement_speed;

		}

		MovementDirection BlackDuckController::getInitialMovementDirection()
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


		MovementDirection BlackDuckController::getRandomDuckDirection()
		{
			int randomType = std::rand() % 2;
			return static_cast<Duck::MovementDirection>(randomType);
		}

		void BlackDuckController::move()
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

		void BlackDuckController::movelLeftDown()
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

		void BlackDuckController::moveRightDown()
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

		void BlackDuckController::moveLeftUp()
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

		void BlackDuckController::moveRightUp()
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