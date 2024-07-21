#pragma once

#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		BULLET_FIRE,
		POWERUP_ENABLED,
		POWERUP_DISABLED,
	};

	class SoundService
	{
	private:
		const int background_music_volume = 30;

		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer buffer_button_click;
		sf::SoundBuffer buffer_bullet_fire;
		sf::SoundBuffer buffer_power_enabled;
		sf::SoundBuffer buffer_power_disabled;

		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();

	public:
		void initialize();

		void playSound(SoundType soundType);
		void playBackgroundMusic();
	};
}