#pragma once

#include "../../header/UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		enum class FontType
		{
			BUBBLE_BOBBLE,
			DS_DIGIB,
			Rajdhani,
		};

		class TextView : public UIView
		{
		private:
			static const int default_font_size = 55;
			static sf::Font font_bubble_bobble;
			static sf::Font font_DS_DIGIB;
			static sf::Font font_Rajdhani;

			sf::Text text;

			static void loadFont();
			void setFont(FontType font_type);
			void setFontSize(int font_size);
			void setTextPosition(sf::Vector2f position);
			void setTextColor(sf::Color color);

		public:

			TextView();
			virtual ~TextView();

			static void initializeTextView();

			void initialize(sf::String text_value, sf::Vector2f position, FontType font_type = FontType::Rajdhani, int font_size = default_font_size, sf::Color color = sf::Color::White);
			void update() override;
			void render() override;

			void setText(sf::String text_value);
			void setsetCentreAlingedText();

		};
	}
}