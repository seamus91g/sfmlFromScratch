#include "stdafx.hpp"
#include "gameBall.hpp"
#include "game.hpp"
#include <cmath>
#include <iostream>

gameBall::gameBall() : _velocity(270.0f), _elapsedTimeSinceStart(0.0f){
	load("../media/ball.png");
	assert(isLoaded());
	getSprite().setOrigin(15,15);
	srand(time(NULL));
	float random_integer = std::rand() % 360 + 1;
	_angle = random_integer;
}

gameBall::~gameBall(){

}


void gameBall::update(float elapsedTime) //Parameter is the time since last frame in seconds. VERY small number.
{
	_elapsedTimeSinceStart += elapsedTime;

	// Delay game from starting until 3 seconds have passed
	if(_elapsedTimeSinceStart < 3.0f){
		return;
	}

	float moveAmount = _velocity  * elapsedTime;
	
	float moveByX = linearVelocityX(_angle) * moveAmount;
	float moveByY = linearVelocityY(_angle) * moveAmount;

	
	// Collisions with the left or right side of the screen
	if(getPosition().x + moveByX <= 0 + getWidth()/2 || getPosition().x + getHeight()/2 + moveByX >= Game::SCREEN_WIDTH)
	{
		//Ricochet!
		_angle = 360.0f - _angle;
		if(_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;
		if(_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;
		moveByX = -moveByX;
	}
		
	//if(GetPosition().y - GetSprite().GetSize().y/2 - moveByY <= 0 || GetPosition().y + GetSprite().GetSize().y/2 + moveByY >= Game::SCREEN_HEIGHT)
	if(getPosition().y + getHeight()/2 + moveByY >= Game::SCREEN_HEIGHT || getPosition().y - getHeight()/2 - moveByY <= 0)
	{

		// std::cout << "Y pos: " << getPosition().y << ", height/2: " << getHeight()/2 << std::endl;
		// move to middle of the screen for now and randomize angle
		getSprite().setPosition(Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2);
		_angle = (rand()%360)+1;
		_velocity = 270.0f;
		_elapsedTimeSinceStart = 0.0f;
	}

	playerPaddle* player1 = dynamic_cast<playerPaddle*>(Game::getGameObjectManager().get("Paddle1"));
	if(player1 != NULL)	{
		sf::Rect<float> p1RecBounds = player1->getBoundingRect();
		sf::Rect<float> ballRecBounds = getBoundingRect();
	
		if(p1RecBounds.intersects(ballRecBounds))       //(GetPosition().x + moveByX + (GetSprite().GetSize().x /2),GetPosition().y + (GetSprite().GetSize().y /2) + moveByY))
		{ 

			// std::cout << "Intersected! " << std::endl;
			// std::cout << "p1RecBounds = {" << p1RecBounds.left << ", " << p1RecBounds.top << "}" << std::endl << "ballRecBounds = {" << ballRecBounds.left << ", " << ballRecBounds.top << "}" << std::endl;
			_angle =  360.0f - (_angle - 180.0f);
			if(_angle > 360.0f) _angle -= 360.0f;
		
			moveByY = -moveByY;

			_velocity += 5.0f;
			serviceLocator::getAudio()->playSound("../media/audio/Bounce.wav");
		}
	}
		getSprite().move(moveByX,moveByY);
}

float gameBall::linearVelocityX(float angle)
{
	angle -= 90;
    if (angle < 0){
    	angle = 360 + angle;
    }
    float out_angle = (float)std::cos( angle * ( 3.1415926 / 180.0f ));
    // std::cout << "In angle: " << angle << ", out angle: " << out_angle << std::endl;
	return out_angle;
}

float gameBall::linearVelocityY(float angle)
{
	angle -= 90;
    if (angle < 0){
    	angle = 360 + angle;
    }
    float out_angle = (float)std::sin( angle * ( 3.1415926 / 180.0f ));
    // std::cout << "In angle: " << angle << ", out angle: " << out_angle << std::endl;
	return out_angle;
}
