#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicsService.h"

namespace Event
{
    using namespace Global;

    EventService::EventService() { game_window = nullptr; }

    EventService::~EventService() = default;

    void EventService::initialize()
    {
        game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
    }

    void EventService::update()
    {
        updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
        updateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
    }

    void EventService::processEvents()
    {
        if (isGameWindowOpen()) 
        {
            while (game_window->pollEvent(game_event))
            {
                if (gameWindowWasClosed() || hasQuitGame())
                {
                    game_window->close();
                }
            }
        }
    }

    bool EventService::hasQuitGame()
    {
        return (isKeyboardEvent() && pressedEscapeKey());
    }

    bool EventService::isKeyboardEvent()
    {
        return game_event.type == sf::Event::KeyPressed;
    }

    bool EventService::pressedEscapeKey()
    {
        printf("Escape Key Pressed");
        return game_event.key.code == sf::Keyboard::Escape;
    }

    bool EventService::isGameWindowOpen()
    {
        return game_window != nullptr;
    }

    bool EventService::gameWindowWasClosed()
    {
        return game_event.type == sf::Event::Closed;
    }

    bool EventService::pressedLeftMouseButton()
    {
        return left_mouse_button_state == ButtonState::PRESSED;
    }
        
    bool EventService::pressedAKey() 
    { 
        return A_button_state == ButtonState::HELD; 
    }

    void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
    {
        if (sf::Mouse::isButtonPressed(mouse_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }

    void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
    {
        if (sf::Keyboard::isKeyPressed(keyboard_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }


}