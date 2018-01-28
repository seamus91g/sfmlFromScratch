#pragma once 
#include "visibleGameObject.hpp"

class gameBall : public visibleGameObject{
public:
	gameBall();
	virtual ~gameBall();
	void update(float);

private:
	float _velocity;
	float _angle;
	float _elapsedTimeSinceStart;

	float linearVelocityX(float angle);
	float linearVelocityY(float angle);
};
