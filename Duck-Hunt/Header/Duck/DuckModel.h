#pragma once

#include <SFML/Graphics.hpp>

namespace Duck
{
	enum class DuckType;
	enum class DuckState;
	enum class MovementDirection;

	class DuckModel
	{
	private:
		sf::Vector2f duck_reference_position = sf::Vector2f(500.f, 500.f);
		sf::Vector2f duck_current_position;
		DuckType duck_type;
		DuckState duck_state;
		MovementDirection movement_direction;

	public:

		float horizontal_movement_speed = 400.0f;
		float vertical_movement_speed = 400.f;
		const sf::Vector2f top_left_position = sf::Vector2f(5.f, 10.f);
		const sf::Vector2f bottom_right_position = sf::Vector2f(1850.f, 720.f);

		DuckModel(DuckType type);
		~DuckModel();

		void initialize();

		sf::Vector2f getDuckReferencePostion();
		sf::Vector2f getDuckCurrentPostion();

		void setDuckReferencePostion(sf::Vector2f position);
		void setDuckCurrentPostion(sf::Vector2f position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		DuckType getDuckType();
		void setDuckType(DuckType type);

		DuckState getDuckState();
		void setDuckState(DuckState state);

	};
}
