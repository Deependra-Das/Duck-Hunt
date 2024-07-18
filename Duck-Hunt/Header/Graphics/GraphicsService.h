#pragma once

#include <SFML/Graphics.hpp>

namespace Graphics
{
	class GraphicsService
	{
	private:

		//private member variables
		const std::string game_window_title = "Duck Hunt";

		const int game_window_width = 1920;
		const int game_window_height = 1080;
		const int frame_rate = 60;
		const sf::Color window_color = sf::Color::Black;
		sf::VideoMode* video_mode;
		sf::RenderWindow* game_window;

		//private member functions
		void setVideoMode();
		void onDestroy();

	public:

		//public constructor & destructor
		GraphicsService();
		~GraphicsService();

		//public member functions
		void initialize();
		void update();
		void render();
		bool isGameWindowOpen();

		sf::RenderWindow* createGameWindow();
		sf::RenderWindow* getGameWindow();
		sf::Color getWindowColor();

	};
}