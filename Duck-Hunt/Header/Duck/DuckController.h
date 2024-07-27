#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Duck/DuckConfig.h"
#include "../../header/UI/UIElement/AnimatedImageView.h"

namespace Duck
{
	class DuckView;
	class DuckModel;

	enum class DuckType;
	enum class DuckState;

	class DuckController
	{
	protected:
		DuckModel* duck_model;
		DuckView* duck_view;

		void virtual move() = 0;

		sf::Vector2f getRandomInitialPosition();
		virtual void destroy();

	public:
		DuckController(DuckType type);
		virtual ~DuckController();

		void virtual initialize();
		void update();
		void render();

		sf::Vector2f getDuckPosition();
		void handleOutOfBounds();

		DuckType getDuckType();
		DuckState getDuckState();

		void setDuckState(DuckState state);

		const sf::Sprite& getDuckSprite();

		void updateDuckAnimation(UI::UIElement::AnimationType a_type, DuckType d_type);
	};
}