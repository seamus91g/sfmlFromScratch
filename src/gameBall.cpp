#include "stdafx.hpp"
#include "gameBall.hpp"

gameBall::gameBall(){
	load("../media/ball.png");
	assert(isLoaded());
	getSprite().setOrigin(15,15);
}

gameBall::~gameBall(){

}

