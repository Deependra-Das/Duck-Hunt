#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		const float player_sprite_width = 500.f;
		const float player_sprite_height = 500.f;

		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		void createUIElements();
		void initializeImage();
		sf::String getPlayerTexturePath();
		void destroy();

	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();
	};
}