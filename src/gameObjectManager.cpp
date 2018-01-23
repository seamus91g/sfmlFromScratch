

#include "stdafx.hpp"
#include "gameObjectManager.hpp"

gameObjectManager::gameObjectManager(){

}

gameObjectManager::~gameObjectManager(){
	// Where to start, where to stop, and a function to apply to everything inbetween 
	std::for_each(_gameObjects.begin(),_gameObjects.end(),gameObjectDeallocator());
}


void gameObjectManager::add(std::string name, visibleGameObject* gameObject){
	_gameObjects.insert(std::pair<std::string, visibleGameObject*>(name, gameObject));
}

void gameObjectManager::remove(std::string name){
	std::map<std::string, visibleGameObject*>::iterator results = _gameObjects.find(name);
	if(results != _gameObjects.end()){
		delete results->second;
		_gameObjects.erase(results);
	}
}


// TODO: Use smart pointer 
visibleGameObject* gameObjectManager::get(std::string name) const{
	std::map<std::string, visibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if(results == _gameObjects.end()){
		return NULL;
	}
	return results->second;
}

int gameObjectManager::gameObjectCount() const{
	return _gameObjects.size();
}

void gameObjectManager::drawAll(sf::RenderWindow& renderWindow){
	std::map<std::string, visibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while(itr != _gameObjects.end()){
		itr->second->draw(renderWindow);
		++itr;
	}
}
void gameObjectManager::updateAll(){
	std::map<std::string, visibleGameObject*>::const_iterator itr = _gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();
	while(itr != _gameObjects.end()){
		itr->second->update(timeDelta);
		++itr;
	}
}

