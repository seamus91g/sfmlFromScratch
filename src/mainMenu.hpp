#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "game.hpp"
#include <list>

class mainMenu{
public:
	enum menuResult { Nothing, Exit, Play };

	struct menuItem{
	public:
		sf::Rect<int> rect;
		menuResult action;
	};

	menuResult show(sf::RenderWindow& window);	// Return enum datatype

private:
	menuResult getMenuResponse(sf::RenderWindow& window);
	menuResult handleClick(int x, int y);
	std::list<menuItem> _menuItems;
};
