#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Gameplay
{
	class GameplayView
	{
	private:
		const float background_sprite_width = 1920.0f;
		const float background_sprite_height = 1080.0f;

		UI::UIElement::ImageView* background_image;

		void createUIElements();
		void initializeImage();
		sf::String getBackgroundTexturePath();
		void destroy();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();

	};
}
