#pragma once 
#include "SFML/Audio.hpp"

class soundFileCache
{
public:
  soundFileCache(void);
  ~soundFileCache(void);

  sf::Sound getSound(std::string) const;
  sf::Music* getSong(std::string) const;

private:
  static std::map<std::string, sf::SoundBuffer*> _sounds;
  static std::map<std::string, sf::Music*> _music;

  /*struct SoundFileDeallocator
    {
      void operator()(const std::pair<std::string,sf::SoundBuffer*> & p) 
      {
        delete p.second;
      }
    };
  
  struct MusicFileDeallocator
    {
      void operator()(const std::pair<std::string,sf::Music*> & p) 
      {
        delete p.second;
      }
    };*/
  
  template <typename T>
    struct Deallocator{
      void operator()(const std::pair<std::string,T> &p) 
      {
        delete p.second;
      }
  };
};


class soundNotFoundExeception : public std::runtime_error
{
  public:
        soundNotFoundExeception(std::string const& msg):
            std::runtime_error(msg)
        {}
};
