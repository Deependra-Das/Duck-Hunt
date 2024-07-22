#include "../../Header/Duck/DuckView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Duck/DuckController.h"
#include"../../Header/Duck/DuckConfig.h"
#include "../../Header/Global/Config.h"

namespace Duck
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;

	DuckView::DuckView()
	{
		createUIElements();
	}

	DuckView::~DuckView()
	{
		destroy();
	}


	void DuckView::createUIElements()
	{
		duck_image = new AnimatedImageView();
	}

	void DuckView::initialize(DuckController* controller)
	{
		duck_controller = controller;
		initializeImage();
	}

	void DuckView::initializeImage()
	{
		duck_image->initialize(getDuckTexturePath(), duck_sprite_width, duck_sprite_height, duck_controller->getDuckPosition());
		updateDuckAnimation(AnimationType::FLYING, duck_controller->getDuckType());
	}

	void DuckView::update()
	{
		duck_image->setPosition(duck_controller->getDuckPosition());
		duck_image->update();
	}

	void DuckView::render()
	{
		duck_image->render();
	}


	sf::String DuckView::getDuckTexturePath()
	{
		switch (duck_controller->getDuckType())
		{
		case::Duck::DuckType::RED:
			return Config::black_duck_texture_path;

		case::Duck::DuckType::BLACK:
			return Config::black_duck_texture_path;
		}
	}

	void DuckView::destroy()
	{
		delete(duck_image);
	}

	const sf::Sprite& DuckView::getDuckSprite()
	{
		return duck_image->getSprite();
	}

	void DuckView::flipSpriteHorizontal()
	{
		duck_image->flipSpriteHorizontal();
	}

	void DuckView::unflipSpriteHorizontal()
	{
		duck_image->unflipSpriteHorizontal();
	}

	void DuckView::updateDuckAnimation(AnimationType a_type, DuckType d_type)
	{
		duck_image->playDuckAnimation(a_type, d_type);
	}
	

}