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
			const AnimationSystemConfig b_duckfall_animation_config(Global::Config::duck_texture_path, 632.f, 338.f, 73.f, 84.5f, 2, 0.2f, 1.f, 0, 7);
			return b_duckfall_animation_config;
		}
		case Animation::AnimationType::RED_DUCK_FALL:
		{
			const AnimationSystemConfig r_duckfall_animation_config(Global::Config::duck_texture_path, 632.f, 338.f, 72.f, 84.5f, 2, 0.2f, 1.0f, 1, 7);
			return r_duckfall_animation_config;
		}
		case Animation::AnimationType::DOG_MOCKING:
		{
			const AnimationSystemConfig dock_mocking_animation_config(Global::Config::dog_texture_path, 1264.f, 1648.f, 116.f, 216.f, 2, 0.2f, 5.0f, 5, 0);
			return dock_mocking_animation_config;
		}
		case Animation::AnimationType::DOG_WALKING:
		{
			const AnimationSystemConfig dock_walking_animation_config(Global::Config::dog_texture_path, 1264.f, 1648.f, 200.f, 216.f, 4, 0.2f, 5.0f, 0, 0);
			return dock_walking_animation_config;
		}
		case Animation::AnimationType::DOG_CATCH_ONE:
		{
			const AnimationSystemConfig dock_catch_one_animation_config(Global::Config::dog_texture_path, 1264.f, 1648.f, 150.f, 208.f, 1, 0.2f, 5.0f, 4, 0);
			return dock_catch_one_animation_config;
		}
		case Animation::AnimationType::DOG_CATCH_TWO:
		{
			const AnimationSystemConfig dock_catch_two_animation_config(Global::Config::dog_texture_path, 1264.f, 1648.f, 185.f, 208.f, 1, 0.2f, 5.0f, 4, 1);
			return dock_catch_two_animation_config;
		}
		case Animation::AnimationType::DOG_CATCH_THREE:
		{
			const AnimationSystemConfig dock_catch_three_animation_config(Global::Config::dog_texture_path, 1264.f, 1648.f, 200.f, 208.f, 1, 0.2f, 5.0f, 4, 2);
			return dock_catch_three_animation_config;
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