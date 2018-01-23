
#include "stdafx.hpp"
#include "playerPaddle.hpp"
#include "game.hpp"

playerPaddle::playerPaddle() : _velocity(0), _maxVelocity(600.0f){
	load("../media/paddle.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getLocalBounds().width /2, getSprite().getLocalBounds().height / 2);
}

playerPaddle::~playerPaddle(){

}

void playerPaddle::draw(sf::RenderWindow & rw){
	visibleGameObject::draw(rw);
}
float playerPaddle::getVelocity() const{
	return _velocity;
}
void playerPaddle::update(float elapsedTime){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		_velocity -= 3.0f;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		_velocity += 3.0f;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		_velocity = 0.0f;
	}

	if(_velocity > _maxVelocity){
		_velocity = _maxVelocity;
	}
	if(_velocity < -_maxVelocity){
		_velocity = -_maxVelocity;
	}

	sf::Vector2f position = this->getPosition();

	if(position.x < getSprite().getLocalBounds().width/2 
		|| position.x > (Game::SCREEN_WIDTH - getSprite().getLocalBounds().width/2)){
		_velocity = -_velocity;
	}

	getSprite().move(_velocity*elapsedTime, 0);
}