#pragma once

#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Duck/DuckService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/WaveSystem/WaveService.h"
#include "../../Header/Sound/SoundService.h"

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
        Gameplay::GameplayService* gameplay_service;
        Time::TimeService* time_service;
        Duck::DuckService* duck_service;
        Player::PlayerService* player_service;
        Wave::WaveService* wave_service;
        Sound::SoundService* sound_service;

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
        Gameplay::GameplayService* getGameplayService();
        Time::TimeService* getTimeService();
        Duck::DuckService* getDuckService();
        Player::PlayerService* getPlayerService();
        Wave::WaveService* getWaveService();
        Sound::SoundService* getSoundService();

        void deleteServiceLocator();
    };
}