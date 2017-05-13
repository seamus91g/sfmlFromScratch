
#pragma once 
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game{

public:
	static void Start();

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { uninitialised, showingSplash, paused, showingMenu, playing, exiting };

	static GameState _gameState; 
	static sf::RenderWindow _mainWindow;

};

