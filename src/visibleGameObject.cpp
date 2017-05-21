
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

void visibleGameObject::setPosition(float x, float y){
	if(_isLoaded){
		_sprite.setPosition(x,y);
	}
}


