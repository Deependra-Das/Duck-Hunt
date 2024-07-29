#pragma once

#include <functional>
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Duck/DuckConfig.h"

namespace UI
{
	namespace UIElement
	{
		enum class AnimationType
		{
			FLYING,
			GLIDING,
			DUCKSHOT,
			DOG_WALKING,
			DOG_SNIFFING,
			DOG_EXCITED,
			DOG_JUMPING,
		};

		class AnimatedImageView :public ImageView
		{
		private:
			using CallbackFunction = std::function<void()>;
			CallbackFunction callback_function = nullptr;

		protected:
			const float default_animation_duration = 0.2f;
			AnimationType animation_type;
			float tile_width;
			float tile_height;
			int row;
			int col;
			int current_frame;
			int number_of_frames;
			float animation_duration;
			float elapsed_duration;
			sf::Clock clock;

			void reset();
			void setAnimationType(AnimationType type);
			void setAnimationConfig(Duck::DuckType d_type);

		public:
			AnimatedImageView();
			~AnimatedImageView();

			void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position) override;
			void update() override;
			void render() override;

			void playDuckAnimation(AnimationType a_type, Duck::DuckType d_type);

			void playDogAnimation(AnimationType a_type);
			void setDogAnimationConfig();

		};
	}
}