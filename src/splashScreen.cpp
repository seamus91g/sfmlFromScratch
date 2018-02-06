#include "stdafx.hpp"
#include "splashScreen.hpp"
#include "game.hpp"

void splashScreen::show(sf::RenderWindow & renderWindow)
{
  sf::Texture image;
  if(image.loadFromFile("../media/splashScreen.png") != true)
  {
    throw std::invalid_argument("Media image not found!");
    return;
  }

  sf::Sprite sprite(image);

  // Scale the splash screen image to the size of the window 
  auto size = sprite.getTexture()->getSize();
  sprite.setScale(float(Game::SCREEN_WIDTH)/size.x, float(Game::SCREEN_HEIGHT)/size.y);
  renderWindow.draw(sprite);
  renderWindow.display();

  sf::Event event;
  while(true)
  {
    while(renderWindow.pollEvent(event))
    {
      if( event.type == sf::Event::MouseButtonPressed
        || event.type == sf::Event::Closed )
      {
        return;		// Return and move on to show splash screen next 
      }
    }
  }
}
