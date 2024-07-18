#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckConfig.h"

namespace Duck
{
	DuckModel::DuckModel(DuckType type)
	{
		duck_type = type;
	}

	DuckModel::~DuckModel()
	{

	}

	void DuckModel::initialize()
	{
		duck_current_position = duck_reference_position;
		movement_direction = MovementDirection::LEFT_DOWN;
		duck_state = DuckState::FLYING;
	}


	sf::Vector2f DuckModel::getDuckReferencePostion()
	{
		return duck_reference_position;
	}

	sf::Vector2f DuckModel::getDuckCurrentPostion()
	{
		return duck_current_position;
	}

	void DuckModel::setDuckReferencePostion(sf::Vector2f position)
	{
		duck_reference_position = position;
	}

	void DuckModel::setDuckCurrentPostion(sf::Vector2f position)
	{
		duck_current_position = position;
	}

	MovementDirection DuckModel::getMovementDirection()
	{
		return movement_direction;
	}

	void DuckModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	DuckType DuckModel::getDuckType()
	{
		return duck_type;
	}

	void DuckModel::setDuckType(DuckType type)
	{
		duck_type = type;
	}

	DuckState DuckModel::getDuckState()
	{
		return duck_state;
	}

	void DuckModel::setDuckState(DuckState state)
	{
		duck_state = state;
	}

}