#include "stdAfx.hpp"
#include "AIPaddle.hpp"
#include "Game.hpp"
#include "gameBall.hpp"

AIPaddle::AIPaddle() :
_velocity(0),
_maxVelocity(600.0f)
{
	load("../media/paddle.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getLocalBounds().width /2, getSprite().getLocalBounds().height / 2);
}


AIPaddle::~AIPaddle()
{
}

void AIPaddle::draw(sf::RenderWindow & rw)
{
	visibleGameObject::draw(rw);
}

float AIPaddle::getVelocity() const
{
	return _velocity;
}

void AIPaddle::update(float elapsedTime)
{
	const gameBall* gBall = static_cast<gameBall*>(Game::getGameObjectManager().get("Ball")); // TODO: Store this instead of fetching repeatedly
	sf::Vector2f ballPosition = gBall->getPosition();

	if(getPosition().x -20 < ballPosition.x){
		_velocity += 15.0f;
	}else if(getPosition().x +20 > ballPosition.x){
		_velocity -= 10.0f;
	}else{
		_velocity = 0.0f;
	}

	if(_velocity > _maxVelocity){
		_velocity = _maxVelocity;
	}

	if(_velocity < -_maxVelocity){
		_velocity = -_maxVelocity;
	}

	sf::Vector2f pos = this->getPosition();

	if((pos.x  < getSprite().getLocalBounds().width/2 && _velocity < 0)
	|| (pos.x > (Game::SCREEN_WIDTH - getSprite().getLocalBounds().width/2) && _velocity > 0)){
		_velocity = -_velocity; // Bounce by current velocity in opposite direction
	}

	getSprite().move(_velocity * elapsedTime, 0);
}
