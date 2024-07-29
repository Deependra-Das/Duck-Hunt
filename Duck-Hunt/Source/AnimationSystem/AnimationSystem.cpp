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
		current_frame = 0;
		frame_time = sf::seconds(animation_system_config.frame_switch_duration);
		total_duration = sf::seconds(animation_system_config.total_animation_duration);
		anim_clock.restart();
		frame_clock.restart();
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

		animation_image->setTextureRect(sf::IntRect((current_frame + animation_system_config.tile_col) * animation_system_config.tile_width, animation_system_config.tile_row * animation_system_config.tile_height, animation_system_config.tile_width, animation_system_config.tile_height));

	}

	void AnimationSystem::update()
	{
		if (anim_clock.getElapsedTime() >= total_duration)
		{
			destroy();
		}
		else 
		{
			if (frame_clock.getElapsedTime() >= frame_time)
			{
				current_frame = (current_frame + 1) % animation_system_config.number_of_animation_frames;
				animation_image->setTextureRect(sf::IntRect((current_frame + animation_system_config.tile_col) * animation_system_config.tile_width, animation_system_config.tile_row * animation_system_config.tile_height, animation_system_config.tile_width, animation_system_config.tile_height));
				frame_clock.restart();
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
		case::Duck::MovementDirection::UP:
			moveUp();
				break;
		case::Duck::MovementDirection::UPDOWN:
			moveUp();
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


	void AnimationSystem::moveUp()
	{
		sf::Vector2f currentPosition = animation_position;
		currentPosition.y -= vertical_movement_speed/4 * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y <= 650.f && movement_clock.getElapsedTime()>= sf::seconds(animation_system_config.total_animation_duration/3))
		{
			direction = MovementDirection::DOWN;
		}
		else
		{
			animation_position = currentPosition;
			animation_image->setPosition(animation_position);
		}
	}


}