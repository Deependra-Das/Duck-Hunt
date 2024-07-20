
#include <SFML/Graphics.hpp>

namespace Wave
{
    struct WaveSystemConfig
    {
        sf::String Wave_texture_path;
        
        int round_number;
        int round_duration;
        int birds_count;

        WaveSystemConfig() = default;

        WaveSystemConfig(int number, int duration, int count) :
            round_number(number),
            round_duration(duration),
            birds_count(count){}
    };
}