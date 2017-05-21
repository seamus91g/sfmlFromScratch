
#include "stdafx.hpp"
#include "game.hpp"
#include "splashScreen.hpp"
#include "mainMenu.hpp"
#include <iostream>

void Game::Start(void)
{
  if(_gameState != uninitialised)	// Ensure Game::Start is only called once 
    return;

  _mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
  _gameState = Game::showingSplash;
  
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
  
    switch(_gameState)
    {

	    case Game::showingMenu:
	    {
	    	showMenu();
	      	break;
	    }
	    case Game::showingSplash:
	    {
	    	showSplashScreen();
	      	break;
	    }
		case Game::playing:
		{
			sf::Event currentEvent;
			while(_mainWindow.pollEvent(currentEvent)){
				_mainWindow.clear(sf::Color(40,0,0));
				_mainWindow.display();

				if(currentEvent.type == sf::Event::Closed){
				  	_gameState = Game::exiting;
				}
			      if(currentEvent.type == sf::Event::KeyPressed)
			      {

					//     	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
						_gameState = Game::showingMenu;

					// // }

					   	 }
			}
			break;
	    }
	}
}
void Game::showSplashScreen(){
	splashScreen mySplashScreen;
	mySplashScreen.show(_mainWindow);
	_gameState = Game::showingMenu;
}
void Game::showMenu(){
	mainMenu myMainMenu;
	mainMenu::menuResult result = myMainMenu.show(_mainWindow);
	switch(result){
		case mainMenu::Exit:
			_gameState = Game::exiting;
			break;
		case mainMenu::Play:
			_gameState = Game::playing;
			break;
	}
}


Game::GameState Game::_gameState = uninitialised;
sf::RenderWindow Game::_mainWindow;

