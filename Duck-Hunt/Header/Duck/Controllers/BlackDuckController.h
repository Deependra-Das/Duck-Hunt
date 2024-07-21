#pragma once

#include "../../header/Duck/DuckController.h"

namespace Duck
{
    namespace Controller
    {
        class BlackDuckController : public DuckController
        {
        private:

            const float black_duck_horizontal_movement_speed = 250.0f;
            float red_duck_rate_of_fire = 2.0f;

            void move() override;
            void movelLeftDown();
            void moveRightDown();
            void moveLeftUp();
            void moveRightUp();

            MovementDirection getRandomDuckDirection();
            MovementDirection getInitialMovementDirection();

        public:
            BlackDuckController(DuckType type);
            ~BlackDuckController();

            void initialize() override;


        };
    }
}

