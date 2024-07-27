#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Duck/DuckConfig.h"

namespace Animation
{
	enum class AnimationType
	{
		BLACK_DUCK_FALL,
		RED_DUCK_FALL,
		DOG_MOCKING,
	};

	class AnimationService
	{
	private:
		std::vector<AnimationSystem*> animation_system_list;
		std::vector<AnimationSystem*> flagged_animation_system_list;
		float vertical_movement_speed = 400.f;
		AnimationSystemConfig getAnimationSystemConfig(AnimationType animation_type);
		void destroyFlaggedAnimationSystem();
		void destroy();

	public:
		AnimationService();
		virtual ~AnimationService();

		void initialize();
		void update();
		void render();

		void reset();

		void spawnAnimationSystem(sf::Vector2f position, AnimationType animation_type, Duck::MovementDirection movement);
		void destroyAnimationSystem(AnimationSystem* animation_system);

		void moveDown();
		void moveUpDown();
	};
}