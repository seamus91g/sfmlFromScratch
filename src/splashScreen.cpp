#include "stdafx.hpp"
#include "splashScreen.hpp"

void splashScreen::show(sf::RenderWindow & renderWindow)
{
  sf::Texture image;
  if(image.loadFromFile("../media/splashScreen.png") != true)
  {
    throw std::invalid_argument("Media image not found!");
    return;
  }

  sf::Sprite sprite(image);
  
  renderWindow.draw(sprite);
  renderWindow.display();

  sf::Event event;
  while(true)
  {
    while(renderWindow.pollEvent(event))
    {
      if(event.type == sf::Event::KeyPressed 
        || event.type == sf::Event::MouseButtonPressed
        || event.type == sf::Event::Closed )
      {
        return;		// Return and move on to show splash screen next 
      }
    }
  }
}
