#pragma once 

#include "stdafx.hpp"
#include "IAudioProvider.hpp"

class SFMLSoundProvider : public IAudioProvider{
public:

	SFMLSoundProvider();

	void playSound(std::string filename);
	void playSong(std::string filename, bool looping = false);
	void stopAllSounds();

	bool isSoundPlaying();
	bool isSongPlaying();

private: 
	sf::SoundBuffer _soundBuffer;
	sf::Sound _sound;
	sf::Music _music; 
};
