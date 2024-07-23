#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/AnimationSystem/AnimationService.h"
#include "../../Header/Duck/DuckConfig.h"

namespace Animation
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Duck;

	AnimationSystem::AnimationSystem(AnimationSystemConfig config)
	{
		animation_system_config = config;
		createUIElements();
	}

	AnimationSystem::~AnimationSystem()
	{
		
	}

	void AnimationSystem::initialize(sf::Vector2f position, MovementDirection movement)
	{
		animation_position = position;
		current_frame = animation_system_config.tile_col;
		frame_time = sf::seconds(animation_system_config.frame_duration);
		frame_counter = 0;
		direction = movement;
		initializeImage();
	}

	void AnimationSystem::createUIElements()
	{
		animation_image = new ImageView();
	}

	void AnimationSystem::initializeImage()
	{
		animation_image->initialize(animation_system_config.Animation_texture_path, animation_system_config.sprite_sheet_width, animation_system_config.sprite_sheet_height, animation_position);

		animation_image->setTextureRect(sf::IntRect(current_frame * animation_system_config.tile_width, animation_system_config.tile_row * animation_system_config.tile_height, animation_system_config.tile_width, animation_system_config.tile_height));

	}

	void AnimationSystem::update()
	{
		if (clock.getElapsedTime() >= frame_time)
		{
			if (frame_counter+1 >= animation_system_config.number_of_animation_frames)
			{
				destroy();
			}
			else 
			{
				current_frame = (current_frame + 1) % animation_system_config.number_of_animation_frames;
				current_frame += animation_system_config.tile_col;
				clock.restart();

				animation_image->setTextureRect(sf::IntRect(current_frame * animation_system_config.tile_width, animation_system_config.tile_row * animation_system_config.tile_height, animation_system_config.tile_width, animation_system_config.tile_height));
				frame_counter++;
			}
			
		}

		move();	

	}

	void AnimationSystem::render()
	{
		animation_image->render();
	}

	void AnimationSystem::destroy()
	{
		delete(animation_image);
		ServiceLocator::getInstance()->getAnimationService()->destroyAnimationSystem(this);
	}

	void AnimationSystem::move()
	{
		switch (direction)
		{
		case::Duck::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void AnimationSystem::moveDown()
	{
		sf::Vector2f currentPosition = animation_position;
		currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		animation_position=currentPosition;
		animation_image->setPosition(animation_position);
	}


}