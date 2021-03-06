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

	std::vector<visibleGameObject*> gPaddles;
	playerPaddle* player1 = dynamic_cast<playerPaddle*>(Game::getGameObjectManager().get("Paddle1"));
	AIPaddle* player2 = dynamic_cast<AIPaddle*>(Game::getGameObjectManager().get("Paddle2"));
	gPaddles.push_back(player1);
	gPaddles.push_back(player2);
	for(std::vector<visibleGameObject*>::iterator it=gPaddles.begin(); it!=gPaddles.end(); ++it){
		if(*it != NULL)	{
			sf::Rect<float> p1RecBounds = (*it)->getBoundingRect();
			sf::Rect<float> ballRecBounds = getBoundingRect();
		
			if(p1RecBounds.intersects(ballRecBounds))       //(GetPosition().x + moveByX + (GetSprite().GetSize().x /2),GetPosition().y + (GetSprite().GetSize().y /2) + moveByY))
			{ 
				// std::cout << "Intersected! " << std::endl;
				// std::cout << "p1RecBounds = {" << p1RecBounds.left << ", " << p1RecBounds.top << "}" << std::endl << "ballRecBounds = {" << ballRecBounds.left << ", " << ballRecBounds.top << "}" << std::endl;
				_angle =  360.0f - (_angle - 180.0f);
				if(_angle > 360.0f) _angle -= 360.0f;
				
				// if top/bottom collision.  
				if (ballRecBounds.top < p1RecBounds.top || (ballRecBounds.top + ballRecBounds.height) > (p1RecBounds.top + ballRecBounds.height)){
					// -Y
					std::cout << "top/bottom collision! " << std::endl;
					moveByY = -moveByY;
				}
				// if side collision
					// -X
				if ((ballRecBounds.left + ballRecBounds.width/2) < p1RecBounds.left || (ballRecBounds.left + ballRecBounds.width/2) > (p1RecBounds.left + p1RecBounds.width)){
					// -Y
					_angle =  360.0f - (_angle);
					if(_angle > 360.0f) _angle -= 360.0f;
					std::cout << "side collision! " << std::endl;
					std::cout << "b.left, width: " << ballRecBounds.left << ", " << ballRecBounds.width << " | p.left, p.width: " << p1RecBounds.left << ", " << p1RecBounds.width << std::endl; 
					moveByX = -moveByX;
				}

				_velocity += 5.0f;
				serviceLocator::getAudio()->playSound("../media/audio/Bounce.wav");
			}
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
