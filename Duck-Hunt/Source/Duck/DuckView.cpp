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
		Duck_image = new ImageView();
	}

	void DuckView::initialize(DuckController* controller)
	{
		Duck_controller = controller;
		initializeImage();
	}

	void DuckView::initializeImage()
	{
		Duck_image->initialize(getDuckTexturePath(), Duck_sprite_width, Duck_sprite_height, Duck_controller->getDuckPosition());
	}

	void DuckView::update()
	{
		Duck_image->setPosition(Duck_controller->getDuckPosition());
		Duck_image->update();
	}

	void DuckView::render()
	{
		Duck_image->render();
	}


	sf::String DuckView::getDuckTexturePath()
	{
		switch (Duck_controller->getDuckType())
		{
		case::Duck::DuckType::RED:
			return Config::duck_texture_path;

		}
	}

	void DuckView::destroy()
	{
		delete(Duck_image);
	}

	const sf::Sprite& DuckView::getDuckSprite()
	{
		return Duck_image->getSprite();
	}


}