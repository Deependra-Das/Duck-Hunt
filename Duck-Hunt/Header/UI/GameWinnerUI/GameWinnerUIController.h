#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace GameWinnerUI
	{

		class GameWinnerUIController : public Interface::IUIController
		{
		private:

			const float gameWinner_image_width = 750.f;
			const float gameWinner_image_height = 375.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float gameWinner_image_y_position = 400.f;
			const float restart_button_y_position = 700.f;
			const float menu_button_y_position = 800.f;

			const float background_image_alpha = 90.0f;

			UIElement::ImageView* background_image;
			UIElement::ImageView* gameWinner_image_view;
			UIElement::ButtonView* restart_button;
			UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeGameWinnerImage();
			void initializeButtons();
			void processPlayerInput();
			void restartGameplay();
			void registerButtonCallback();

			void RestartButtonCallback();
			void MenuButtonCallback();
			void destroy();

		public:
			GameWinnerUIController();
			~GameWinnerUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}