
#pragma once 
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "playerPaddle.hpp"
#include "gameObjectManager.hpp"

class Game{

public:
	static void Start();

	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	static bool IsExiting();
	static void GameLoop();
	static void showSplashScreen();
	static void showMenu();
	enum GameState { uninitialised, showingSplash, paused, showingMenu, playing, exiting };

	static GameState _gameState; 
	static sf::RenderWindow _mainWindow;
	static gameObjectManager _gameObjectManager;

};

