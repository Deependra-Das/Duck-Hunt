#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace MainMenuUI
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const float game_logo_width = 750;
			const float game_logo_height = 375.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float game_logo_y_position = 200.f;
			const float play_button_y_position = 700.f;
			const float instructions_button_y_position = 800.f;
			const float quit_button_y_position = 900.f;

			const float background_image_alpha = 90.0f;

			UIElement::ImageView* background_image;
			UIElement::ImageView* game_logo_view;
			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();
			void initializeGameLogoImage();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}