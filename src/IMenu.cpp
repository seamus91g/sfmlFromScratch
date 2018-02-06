#include "stdafx.hpp"
#include "IMenu.hpp"

menu::menuResult menu::handleClick(int x, int y){
	std::list<menuItem>::iterator it;

	// Loop through all menu items to detect which was clicked 
	for ( it = _menuItems.begin(); it != _menuItems.end(); it++){	
		sf::Rect<int> menuItemRect = (*it).rect;
		if(menuItemRect.height + menuItemRect.top > y 
			&& menuItemRect.top < y 
			&& menuItemRect.left < x 
			&& menuItemRect.width + menuItemRect.left > x)
		{
			return ((*it).action);
		}

	}

	return static_cast<menuResult>(0);	// If not clicked on any menu item 
}
