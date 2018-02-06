#pragma once
#include <list>

class menu{
public:
	enum class menuResult { Nothing, Exit, Continue };

	struct menuItem{
	public:
		sf::Rect<int> rect;
		menuResult action;
	};

	virtual menuResult show(sf::RenderWindow& window) = 0;	// Return enum datatype
protected:
	std::list<menuItem> _menuItems;
	menuResult handleClick(int x, int y);
	virtual menuResult getMenuResponse(sf::RenderWindow& window) = 0;
private:
};
