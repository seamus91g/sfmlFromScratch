
#include "stdafx.hpp"
#include "game.hpp"
void Game::Start(void)
{
	if(_gameState != uninitialised){	// Ensure Game::Start is only called once 
	  return;		// Throw an error instead of quietly returning? 
	}

	SFMLSoundProvider soundProvider; 
	serviceLocator::registerServiceLocator(&soundProvider);

	serviceLocator::getAudio()->playSong("../media/audio/Soundtrack.ogg", true);

	_mainWindow.create(sf::VideoMode(Game::SCREEN_WIDTH,Game::SCREEN_HEIGHT,32),"Pang!");
	_gameState = Game::showingSplash;

	gameBall *ball = new gameBall();
	ball->setPosition((Game::SCREEN_WIDTH/2),(Game::SCREEN_HEIGHT/2)-15);
	
	playerPaddle *player1 = new playerPaddle();
	player1->setPosition((Game::SCREEN_WIDTH/2), Game::SCREEN_HEIGHT-30);
	AIPaddle *player2 = new AIPaddle();
	player2->setPosition((Game::SCREEN_WIDTH/2), 30);

	_gameObjectManager.add("Paddle1", player1);
	_gameObjectManager.add("Paddle2", player2);
	_gameObjectManager.add("Ball", ball);
	
	while(!IsExiting())
	{
	  GameLoop();
	}

	_mainWindow.close();
}
sf::RenderWindow& Game::getWindow()
{
	return _mainWindow;
}

const sf::Event& Game::getInput() 
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}

bool Game::IsExiting()
{
if(_gameState == Game::exiting) 
	return true;
else 
	return false;
}

const gameObjectManager& Game::getGameObjectManager(){
	return Game::_gameObjectManager;
}

void Game::GameLoop()
{
  	sf::Event currentEvent;
  	_mainWindow.pollEvent(currentEvent);
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
			// sf::Event currentEvent;
			_mainWindow.clear(sf::Color(40,0,0));
			_gameObjectManager.updateAll();
			_gameObjectManager.drawAll(_mainWindow);
			_mainWindow.display();

			while(_mainWindow.pollEvent(currentEvent)){
				if(currentEvent.type == sf::Event::Closed){
				  	_gameState = Game::exiting;
				}
				if(currentEvent.type == sf::Event::KeyPressed)				{
					if(currentEvent.key.code == sf::Keyboard::Escape){

						_gameState = Game::showingMenu;
						// showMenu();
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
	_mainWindow.clear(sf::Color(0,40,0));
	mainMenu myMainMenu;
	mainMenu::menuResult result = myMainMenu.show(_mainWindow);
	switch(result){
		case mainMenu::menuResult::Exit:
			_gameState = Game::exiting;
			break;
		case mainMenu::menuResult::Continue:
			_gameState = Game::playing;
			break;
	}
}
// void Game::showEnd(){
// 	_mainWindow.clear(sf::Color(0,0,40));
// 	mainMenu myMainMenu;
// 	mainMenu::menuResult result = myMainMenu.show(_mainWindow);
// 	switch(result){
// 		case mainMenu::Exit:
// 			_gameState = Game::exiting;
// 			break;
// 		case mainMenu::Play:
// 			_gameState = Game::playing;
// 			break;
// 	}
// }


Game::GameState Game::_gameState = uninitialised;
sf::RenderWindow Game::_mainWindow;
gameObjectManager Game::_gameObjectManager;
