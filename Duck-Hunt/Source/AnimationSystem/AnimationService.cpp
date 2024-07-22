#include "../../Header/AnimationSystem/AnimationService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Duck/DuckConfig.h"

namespace Animation
{
	using namespace Duck;

	AnimationService::AnimationService()
	{
	}

	AnimationService::~AnimationService()
	{
		destroy();
	}

	void AnimationService::initialize() { }

	void AnimationService::update()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			animation_system->update();

		destroyFlaggedAnimationSystem();
	}

	void AnimationService::render()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			animation_system->render();
	}

	void AnimationService::spawnAnimationSystem(sf::Vector2f position, AnimationType animation_type, Duck::MovementDirection movement)
	{
		AnimationSystem* animation_system = new AnimationSystem(getAnimationSystemConfig(animation_type));
		animation_system->initialize(position, movement);
		animation_system_list.push_back(animation_system);
	}

	void AnimationService::destroyAnimationSystem(AnimationSystem* animation_system)
	{
		flagged_animation_system_list.push_back(animation_system);
		animation_system_list.erase(std::remove(animation_system_list.begin(), animation_system_list.end(), animation_system), animation_system_list.end());
	}

	AnimationSystemConfig AnimationService::getAnimationSystemConfig(AnimationType animation_type)
	{
		switch (animation_type)
		{
		case Animation::AnimationType::BLACK_DUCK_FALL:
		{
			const AnimationSystemConfig b_duckfall_animation_config(Global::Config::duck_texture_path, 632.f, 338.f, 73.f, 84.5f, 3, 0.2f, 0, 6);
			return b_duckfall_animation_config;
		}
		case Animation::AnimationType::RED_DUCK_FALL:
		{
			const AnimationSystemConfig r_duckfall_animation_config(Global::Config::duck_texture_path, 632.f, 338.f, 73.f, 84.5f, 3, 0.2f, 1, 6);
			return r_duckfall_animation_config;
		}

		}
	}

	void AnimationService::destroyFlaggedAnimationSystem()
	{
		for (AnimationSystem* particle_system : flagged_animation_system_list)
			delete (particle_system);

		flagged_animation_system_list.clear();
	}

	void AnimationService::reset() { destroy(); }

	void AnimationService::destroy()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			delete (animation_system);
	}

}