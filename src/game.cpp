
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

  _player1.load("../media/paddle.png");
  _player1.setPosition((1024/2)-45, 700-25);
  
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
				_player1.draw(_mainWindow);
				_mainWindow.display();

				if(currentEvent.type == sf::Event::Closed){
				  	_gameState = Game::exiting;
				}
			      if(currentEvent.type == sf::Event::KeyPressed)
			      {
			      	if(currentEvent.key.code == sf::Keyboard::Escape){
			      		showMenu();
			      	}


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
playerPaddle Game::_player1;
