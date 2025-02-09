#include "../../Header/UI/UIElement/AnimatedImageView.h"
#include "../../Header/Duck/DuckConfig.h"

namespace UI
{
    namespace UIElement
    {
        using namespace Duck;

        AnimatedImageView::AnimatedImageView() = default;

        AnimatedImageView::~AnimatedImageView() = default;

        void AnimatedImageView::initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position)
        {
            reset();
            ImageView::initialize(texture_path, image_width, image_height, position);
            ImageView::setTextureRect(sf::IntRect(tile_width * current_frame, tile_height * row, tile_width, tile_height));
            ImageView::hide();
        }

        void AnimatedImageView::update()
        {
            if (clock.getElapsedTime() >= sf::seconds(default_animation_duration))
            {
                current_frame = (current_frame + 1) % number_of_frames;
                current_frame += col;
                clock.restart();

                ImageView::setTextureRect(sf::IntRect(tile_width * current_frame, tile_height* row, tile_width, tile_height));
            }

     
            ImageView::update();

        }

        void AnimatedImageView::render()
        {
            ImageView::render();
        }

        void AnimatedImageView::playDuckAnimation(AnimationType a_type, Duck::DuckType d_type)
        {
            setAnimationType(a_type);
            setAnimationConfig(d_type);
            ImageView::show();
        }


        void AnimatedImageView::setAnimationType(AnimationType type)
        {
            animation_type = type;
        }

        void AnimatedImageView::setAnimationConfig(Duck::DuckType d_type)
        {
            switch (d_type)
            {
            case DuckType::BLACK:
                row = 0;
                break;
            case DuckType::RED:
                row = 1;
            break;
          
            }

            switch (animation_type)
            {
            case AnimationType::FLYING:
            {
                current_frame = col = 0; tile_width = 72.f; tile_height = 84.5f; number_of_frames = 3;
                break;
            }

            case AnimationType::DUCKSHOT:
            {
                current_frame = col = 6; tile_width = 72.f; tile_height = 84.5f; number_of_frames = 1;
                break;
            }
                 
            }
        }

        void AnimatedImageView::playDogAnimation(AnimationType a_type)
        {
            setAnimationType(a_type);
            setDogAnimationConfig();
            ImageView::show();
        }

        void AnimatedImageView::setDogAnimationConfig()
        {
            switch (animation_type)
            {
            case AnimationType::DOG_WALKING:
            {
                row = 0; current_frame = col = 0; tile_width = 195.f; tile_height = 200.f; number_of_frames = 4;
                break;
            }
            case AnimationType::DOG_SNIFFING:
            {
                row = 1; current_frame = col = 0; tile_width = 190.f; tile_height = 200.f; number_of_frames = 2;
                break;
            }
            case AnimationType::DOG_EXCITED:
            {
                row = 2; current_frame = col = 0; tile_width = 190.f; tile_height = 200.f; number_of_frames = 1;
                break;
            }
            case AnimationType::DOG_JUMPING:
            {
                row = 3; current_frame = col = 0; tile_width = 130.f; tile_height = 200.f; number_of_frames = 2;
                break;
            }

            }
        }


        void AnimatedImageView::reset()
        {
            clock.restart();
            tile_width = 0;
            tile_height = 0; 
            row = 0;
            col = 0;
            current_frame = 0;
            number_of_frames = 0;

        }
    }
}