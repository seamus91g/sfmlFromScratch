
#pragma once
#include "visibleGameObject.hpp"

class gameObjectManager{
public:
	gameObjectManager();
	~gameObjectManager();

	void add(std::string name, visibleGameObject* gameObject);
	void remove(std::string name);
	int gameObjectCount() const;
	visibleGameObject* get(std::string name) const;

	void drawAll(sf::RenderWindow& renderWindow);
	void updateAll();

private:
	std::map<std::string, visibleGameObject*> _gameObjects;
	sf::Clock clock;

	// Use a functor for clean up 
	struct gameObjectDeallocator{
		void operator()(const std::pair<std::string, visibleGameObject*> & p) const{
			delete p.second;
		}
	};




};
