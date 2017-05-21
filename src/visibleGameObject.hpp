
#pragma once
class visibleGameObject{
public:
	visibleGameObject();
	virtual ~visibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow & window);

	virtual void setPosition(float x, float y);

private: 
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;

};

