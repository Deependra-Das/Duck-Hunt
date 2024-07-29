#pragma once

namespace Duck
{
    enum class DuckType
    {
        RED,
        BLACK,
    };

    enum class DuckState
    {
        FLYING,
        DEAD,
        FALLING,
    };

    enum class MovementDirection
    {   LEFT_UP,
        RIGHT_UP,
        LEFT_DOWN,
        RIGHT_DOWN,
        RIGHT,
        LEFT,
        UP,
        DOWN,
        UPDOWN
    };
}