#include "stdafx.hpp"
#include "SFMLSoundProvider.hpp"


SFMLSoundProvider::SFMLSoundProvider()
{
  _sound.setVolume(100.0f);
}

void SFMLSoundProvider::playSound(std::string filename) 
{
  
  if(_soundBuffer.getDuration().asSeconds() == 0)
  {
    _soundBuffer.loadFromFile(filename);
  }
  if(_sound.getStatus() == sf::Sound::Playing)
  {
    _sound.stop();
  }
  _sound.setBuffer(_soundBuffer);
  _sound.play();
}
  
void SFMLSoundProvider::playSong(std::string filename, bool looping)
{
  _music.openFromFile(filename);
  _music.setLoop(looping);
  _music.play();
}

void SFMLSoundProvider::stopAllSounds() 
{
  if(_sound.getStatus() == sf::Sound::Playing)
    _sound.stop();
  if(_music.getStatus() == sf::Sound::Playing)
    _music.stop();
}
  
bool SFMLSoundProvider::isSoundPlaying()
{
  return _sound.getStatus() == sf::Sound::Playing;
}


bool SFMLSoundProvider::isSongPlaying()
{
  return _music.getStatus() == sf::Music::Playing;  
}
