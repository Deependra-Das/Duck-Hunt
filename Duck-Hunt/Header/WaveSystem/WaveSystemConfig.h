
#include <SFML/Graphics.hpp>

namespace Wave
{
    struct WaveSystemConfig
    {
        sf::String Wave_texture_path;
        
        int round_number;
        int round_duration;
        int total_birds_count;
        int black_birds_count;
        int red_birds_count;

        WaveSystemConfig() = default;

        WaveSystemConfig(int number, int duration, int total_count, int black_count, int red_count) :
            round_number(number),
            round_duration(duration),
            total_birds_count(total_count),
            black_birds_count(black_count) ,
            red_birds_count(red_count) {}
    };
}