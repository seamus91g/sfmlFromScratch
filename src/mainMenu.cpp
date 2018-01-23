#include "stdafx.hpp"
#include "mainMenu.hpp"

mainMenu::menuResult mainMenu::show(sf::RenderWindow& window){

	// Load menu image
	sf::Texture image;
	image.loadFromFile("../media/mainmenu.png");
	sf::Sprite sprite(image);

	//// Declare clickable regions

	// Play menu item coordinates	// TODO: Encapsulate the below functionality 
	menuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = (380 - 145);
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	menuItem exitButton;
	exitButton.rect.top = (383 - 145);
	exitButton.rect.height = (560 - (383 - 145));
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	menuResult returnChoice = getMenuResponse(window);
	return returnChoice;

}


mainMenu::menuResult mainMenu::handleClick(int x, int y){
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

	return Nothing;	// If not clicked on any menu item 
}

mainMenu::menuResult  mainMenu::getMenuResponse(sf::RenderWindow& window)
{
  sf::Event menuEvent;

  while(true)
  {

    while(window.pollEvent(menuEvent))
    {
      if(menuEvent.type == sf::Event::MouseButtonPressed)
      {
        return handleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
      }
      if(menuEvent.type == sf::Event::Closed)
      {
        return Exit;
      }
    }
  }
}



