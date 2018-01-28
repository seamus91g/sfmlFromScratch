#pragma once
#include "visibleGameObject.hpp"

class AIPaddle :
  public visibleGameObject
{
public:
  AIPaddle(void);
  ~AIPaddle(void);

  void update(float elapsedTime);
  void draw(sf::RenderWindow& rw);
  
  float getVelocity() const;

private:
  float _velocity;  // -- left ++ right
  float _maxVelocity;
};