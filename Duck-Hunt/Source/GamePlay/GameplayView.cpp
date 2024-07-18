#include "../../Header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicsService.h"
#include "../../header/Global/Config.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;

	GameplayView::GameplayView()
	{
		createUIElements();
	}

	GameplayView::~GameplayView()
	{
		destroy();
	}

	void GameplayView::createUIElements()
	{
		background_image = new ImageView();
	}

	void GameplayView::initialize()
	{
		initializeImage();
	}

	void GameplayView::initializeImage()
	{
		background_image->initialize(getBackgroundTexturePath(), background_sprite_width, background_sprite_height, sf::Vector2f(0, 0));
	}

	void GameplayView::update()
	{
	}

	void GameplayView::render()
	{
		background_image->render();
	}


	sf::String GameplayView::getBackgroundTexturePath()
	{
		return Config::background_texture_path;
	}

	void GameplayView::destroy()
	{
		delete(background_image);
	}

}