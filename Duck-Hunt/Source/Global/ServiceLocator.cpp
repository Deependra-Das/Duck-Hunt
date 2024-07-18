#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global
{
	using namespace Main;
	using namespace Graphics;
	using namespace Event;
	using namespace UI;

	ServiceLocator::ServiceLocator()
	{
		graphics_service = nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphics_service = new GraphicsService();
		event_service = new EventService();
		ui_service = new UIService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphics_service);
		delete(event_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphics_service->initialize();
		event_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphics_service->update();
		event_service->update();
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphics_service->render();
		ui_service->render();
	}

	GraphicsService* ServiceLocator::getGraphicsService()
	{
		return graphics_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}

	void ServiceLocator::deleteServiceLocator()
	{
		delete(this);
	}
}
