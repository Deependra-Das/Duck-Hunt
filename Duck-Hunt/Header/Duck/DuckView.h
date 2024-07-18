#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Duck
{
	class DuckController;
	enum class DuckType;

	class DuckView
	{
	private:
		const float Duck_sprite_width = 60.f;
		const float Duck_sprite_height = 60.f;

		DuckController* Duck_controller;
		UI::UIElement::ImageView* Duck_image;

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
	};

}

