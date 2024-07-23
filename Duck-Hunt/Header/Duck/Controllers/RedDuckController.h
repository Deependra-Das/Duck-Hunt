#pragma once

#include "../../header/Duck/DuckController.h"

namespace Duck
{
    namespace Controller
    {
        class RedDuckController : public DuckController
        {
        private:
            
            const float red_duck_horizontal_movement_speed = 500.0f;

            void move() override;
            void movelLeftDown();
            void moveRightDown();
            void moveLeftUp();
            void moveRightUp();
            void moveLeft();
            void moveRight();

            MovementDirection getRandomDuckDirection();
            MovementDirection getInitialMovementDirection();

        public:
            RedDuckController(DuckType type);
            ~RedDuckController();

            void initialize() override;


        };
    }
}

