#include "../../Header/Graphics/GraphicsService.h"

namespace Graphics
{
	GraphicsService::GraphicsService()
	{
		video_mode = nullptr;
		game_window = nullptr;
	}

	GraphicsService::~GraphicsService()
	{
		onDestroy();
	}

	void GraphicsService::initialize()
	{
		game_window = createGameWindow();
		game_window->setFramerateLimit(frame_rate);
	}

	void GraphicsService::setVideoMode()
	{
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicsService::onDestroy()
	{
		delete(video_mode);
		delete(game_window);
	}

	void GraphicsService::update()
	{
	}

	void GraphicsService::render()
	{
	}

	bool GraphicsService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}

	sf::RenderWindow* GraphicsService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Fullscreen);
	}

	sf::RenderWindow* GraphicsService::getGameWindow()
	{
		return game_window;
	}

	sf::Color GraphicsService::getWindowColor()
	{
		return window_color;
	}
}