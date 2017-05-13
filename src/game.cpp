
#include "stdafx.hpp"
#include "game.hpp"

void Game::Start(void)
{
  if(_gameState != uninitialised)	// Ensure Game::Start is only called once 
    return;

  _mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
  _gameState = Game::playing;
  
  while(!IsExiting())
  {
    GameLoop();
  }

  _mainWindow.close();
}

bool Game::IsExiting()
{
  if(_gameState == Game::exiting) 
    return true;
  else 
    return false;
}

void Game::GameLoop()
{
  sf::Event currentEvent;
  while(_mainWindow.pollEvent(currentEvent))
  {
  
    switch(_gameState)
    {
      case Game::playing:
        {
          _mainWindow.clear(sf::Color(255,0,0));
          _mainWindow.display();
        
          if(currentEvent.type == sf::Event::Closed)
            {
              _gameState = Game::exiting;
            }
          break;
        }
    }
  }
}


Game::GameState Game::_gameState = uninitialised;
sf::RenderWindow Game::_mainWindow;

