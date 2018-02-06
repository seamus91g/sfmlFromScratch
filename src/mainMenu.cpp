#include "stdafx.hpp"
#include "mainMenu.hpp"
#include "SFMLSoundProvider.hpp"
#include "serviceLocator.hpp"

mainMenu::menuResult mainMenu::show(sf::RenderWindow& window){

	// Load menu image
	sf::Texture image;
	image.loadFromFile("../media/mainmenu.png");
	sf::Sprite sprite(image);

	sf::Font font;
	if(!font.loadFromFile("../media/font/hun_din_1451/HunDIN1451.ttf")){
		exit;
	}
	sf::Text textStart;
	sf::Text textExit;
	textStart.setString("Start Game");
	textStart.setFont(font);
	textStart.setFillColor(sf::Color::Blue);
	textStart.setCharacterSize(120);
	sf::Rect<float> txBounds = textStart.getLocalBounds();
	textStart.setPosition(Game::SCREEN_WIDTH/2 - txBounds.width/2, (Game::SCREEN_HEIGHT)/4);

	textExit.setString("Exit");
	textExit.setFont(font);
	textExit.setFillColor(sf::Color::Blue);
	textExit.setCharacterSize(120);
	sf::Rect<float> tx2Bounds = textExit.getLocalBounds();
	textExit.setPosition(Game::SCREEN_WIDTH/2 - tx2Bounds.width/2, ((Game::SCREEN_HEIGHT)/4)*2);

	sf::Vertex line1[] = {
		sf::Vertex(sf::Vector2f(0,Game::SCREEN_HEIGHT/4)),
		sf::Vertex(sf::Vector2f(Game::SCREEN_WIDTH,Game::SCREEN_HEIGHT/4))
	};
	sf::Vertex line2[] = {
		sf::Vertex(sf::Vector2f(0,(Game::SCREEN_HEIGHT/4)*2)),
		sf::Vertex(sf::Vector2f(Game::SCREEN_WIDTH,(Game::SCREEN_HEIGHT/4)*2))
	};
	sf::Vertex line3[] = {
		sf::Vertex(sf::Vector2f(0,(Game::SCREEN_HEIGHT/4)*3)),
		sf::Vertex(sf::Vector2f(Game::SCREEN_WIDTH,(Game::SCREEN_HEIGHT/4)*3))
	};

	window.draw(line1, 2, sf::Lines);
	window.draw(line2, 2, sf::Lines);
	window.draw(line3, 2, sf::Lines);

	//// Declare clickable regions
	menuItem playButton;
	playButton.rect.top = (Game::SCREEN_HEIGHT)/4;
	playButton.rect.height = (Game::SCREEN_HEIGHT)/4;
	playButton.rect.left = 0;
	playButton.rect.width = Game::SCREEN_WIDTH;
	playButton.action = menuResult::Continue;

	menuItem exitButton;
	exitButton.rect.top = ((Game::SCREEN_HEIGHT)/4)*2;
	exitButton.rect.height = (Game::SCREEN_HEIGHT)/4;
	exitButton.rect.left = 0;
	exitButton.rect.width = Game::SCREEN_WIDTH;
	exitButton.action = menuResult::Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(textStart);
	window.draw(textExit);
	window.display();

	menuResult returnChoice = getMenuResponse(window);
	return returnChoice;

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
      	if(serviceLocator::getAudio()->isSongPlaying()){
      		serviceLocator::getAudio()->stopAllSounds();
      	}
        return handleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
      }
      if(menuEvent.type == sf::Event::Closed)
      {
        return menuResult::Exit;
      }
    }
  }
}



