#pragma once

#include "../../Header/Graphics/GraphicsService.h"


namespace Global
{
    class ServiceLocator
    {
    private:

        ServiceLocator();
        ~ServiceLocator();

        Graphics::GraphicsService* graphics_service;

        void createServices();
        void clearAllServices();

    public:

        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicsService* getGraphicsService();
  
        void deleteServiceLocator();
    };
}