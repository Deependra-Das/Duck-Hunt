#pragma once

#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/UI/UIService.h"

namespace Global
{
    class ServiceLocator
    {
    private:

        ServiceLocator();
        ~ServiceLocator();

        Graphics::GraphicsService* graphics_service;
        Event::EventService* event_service;
        UI::UIService* ui_service;
        void createServices();
        void clearAllServices();

    public:

        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicsService* getGraphicsService();
        Event::EventService* getEventService();
        UI::UIService* getUIService();

        void deleteServiceLocator();
    };
}