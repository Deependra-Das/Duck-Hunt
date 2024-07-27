#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/UI/UIElement/AnimatedImageView.h"

namespace Duck
{
	using namespace Global;
	using namespace Time;
	using namespace UI::UIElement;

	DuckController::DuckController(DuckType type)
	{
		duck_view = new DuckView();
		duck_model = new DuckModel(type);
	}

	DuckController::~DuckController()
	{
		delete(duck_view);
		delete(duck_model);
	}

	void DuckController::initialize()
	{
		duck_model->initialize();
		duck_view->initialize(this);
		duck_model->setDuckCurrentPostion(getRandomInitialPosition());
	}

	void DuckController::update()
	{
		move();
		duck_view->update();
		//handleOutOfBounds();
	}

	void DuckController::render()
	{
		duck_view->render();
	}

	sf::Vector2f DuckController::getDuckPosition()
	{
		return duck_model->getDuckCurrentPostion();
	}

	sf::Vector2f DuckController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(duck_model->bottom_right_position.x - duck_model->top_left_position.x));
		float x_position = duck_model->top_left_position.x + x_offset_distance;
		float y_position = duck_model->bottom_right_position.y;
		return sf::Vector2f(x_position, y_position);
	}

	void DuckController::handleOutOfBounds()
	{
		sf::Vector2f DuckPosition = getDuckPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow()->getSize();

		if (DuckPosition.x < 0 || DuckPosition.x > windowSize.x ||
			DuckPosition.y < 0 || DuckPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getDuckService()->destroyDuck(this);
		}
	}

	DuckType DuckController::getDuckType()
	{
		return duck_model->getDuckType();
	}

	DuckState DuckController::getDuckState()
	{
		return duck_model->getDuckState();
	}

	const sf::Sprite& DuckController::getDuckSprite()
	{
		return duck_view->getDuckSprite();
	}

	void DuckController::destroy()
	{
		ServiceLocator::getInstance()->getDuckService()->destroyDuck(this);
	}

	void DuckController::setDuckState(DuckState state)
	{
		duck_model->setDuckState(state);
	}

	void DuckController::updateDuckAnimation(AnimationType a_type, DuckType d_type)
	{
		duck_view->updateDuckAnimation(a_type, d_type);
	}
}