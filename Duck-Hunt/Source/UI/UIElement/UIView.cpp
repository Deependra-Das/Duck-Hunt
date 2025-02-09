#include "../../header/UI/UIElement/UIView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicsService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		using namespace Graphics;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
			ui_state = UIState::VISIBLE;
		}

		void UIView::update() { }

		void UIView::render() { }

		void UIView::show()
		{
			ui_state = UIState::VISIBLE;
		}

		void UIView::hide()
		{
			ui_state = UIState::HIDDEN;
		}
	}
}