#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace InstructionsUI
	{

		class InstructionsUIController : public Interface::IUIController
		{
		private:

			const float instructions_image_width = 1720.f;
			const float instructions_image_height = 786.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float instructions_image_y_position = 100.f;
			const float menu_button_y_position = 925.f;

			UIElement::ImageView* instructions_image_view;
			UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeInstructionsImage();
			void initializeButtons();
			void registerButtonCallback();
			void MenuButtonCallback();
			void destroy();

		public:
			InstructionsUIController();
			~InstructionsUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}