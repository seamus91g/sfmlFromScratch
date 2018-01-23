
#pragma once
#include "visibleGameObject.hpp"

class playerPaddle: public visibleGameObject{
public:
	playerPaddle();
	~playerPaddle();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);

	float getVelocity() const;
private:
	float _velocity;
	float _maxVelocity;
};
