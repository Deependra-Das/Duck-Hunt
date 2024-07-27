#pragma once

#include "../../Header/AnimationSystem/AnimationSystemConfig.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Duck/DuckConfig.h"

namespace Animation
{
	class AnimationSystem
	{
	private:
		AnimationSystemConfig animation_system_config;
		sf::Vector2f animation_position;
		UI::UIElement::ImageView* animation_image;
		sf::Clock anim_clock;
		sf::Clock frame_clock;
		sf::Clock movement_clock;
		sf::Time frame_time;
		int current_frame;
		sf::Time total_duration;
		float vertical_movement_speed = 800.f;
		Duck::MovementDirection direction;
		void createUIElements();
		void initializeImage();
		void move();
		void moveDown();
		void moveUp();

	public:
		AnimationSystem(AnimationSystemConfig config);
		~AnimationSystem();

		void initialize(sf::Vector2f position, Duck::MovementDirection movement);
		void update();
		void render();
		void destroy();

	};
}