#pragma once 

#include "stdafx.hpp"
#include "IAudioProvider.hpp"
#include "soundFileCache.hpp"

class SFMLSoundProvider : public IAudioProvider{
public:

	SFMLSoundProvider();

	void playSound(std::string filename);
	void playSong(std::string filename, bool looping = false);
	void stopAllSounds();

	bool isSoundPlaying();
	bool isSongPlaying();

private: 
	static const int MAX_SOUND_CHANNELS = 5;

	soundFileCache _soundFileCache;
	sf::Sound _currentSounds[MAX_SOUND_CHANNELS];
	std::string _currentSongName;
};
