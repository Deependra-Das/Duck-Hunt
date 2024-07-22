#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/AnimatedImageView.h"

namespace Duck
{
	class DuckController;
	enum class DuckType;

	class DuckView
	{
	private:
		const float duck_sprite_width = 632.f;
		const float duck_sprite_height = 338.f;

		DuckController* duck_controller;
		UI::UIElement::AnimatedImageView* duck_image;

		void createUIElements();
		void initializeImage();
		sf::String getDuckTexturePath();
		void destroy();

	public:
		DuckView();
		~DuckView();

		void initialize(DuckController* controller);
		void update();
		void render();

		const sf::Sprite& getDuckSprite();

		void flipSpriteHorizontal();
		void unflipSpriteHorizontal();

		void updateDuckAnimation(UI::UIElement::AnimationType a_type, DuckType d_type);
	};

}

