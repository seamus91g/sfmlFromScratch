
#pragma once
class visibleGameObject{
public:
	visibleGameObject();
	virtual ~visibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow & window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const; 
	virtual bool isLoaded() const; 

protected:
	sf::Sprite& getSprite();

private: 
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;

};

