#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "game.hpp"
#include "IMenu.hpp"
#include <list>

class mainMenu : public menu {
public:
	menuResult show(sf::RenderWindow& window);	// Return enum datatype

private:
	menuResult getMenuResponse(sf::RenderWindow& window);
};
