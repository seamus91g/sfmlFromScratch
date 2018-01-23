
#include "stdafx.hpp"
#include "visibleGameObject.hpp"

visibleGameObject::visibleGameObject(){
	_isLoaded = false;
}

visibleGameObject::~visibleGameObject(){

}


void visibleGameObject::load(std::string filename){
	if((_image.loadFromFile(filename)) == false){
		_filename = "";
		_isLoaded = false;

	}else{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void visibleGameObject::draw(sf::RenderWindow & renderWindow){
	if(_isLoaded){
		renderWindow.draw(_sprite);
	}
}
void visibleGameObject::update(float elapsedTime){

}

void visibleGameObject::setPosition(float x, float y){
	if(_isLoaded){
		_sprite.setPosition(x,y);
	}
}
sf::Vector2f visibleGameObject::getPosition() const {
	if(isLoaded()){
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}
bool visibleGameObject::isLoaded() const{
	return _isLoaded;
}
sf::Sprite& visibleGameObject::getSprite(){
	return _sprite;
}
