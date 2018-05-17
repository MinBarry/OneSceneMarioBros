#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class GameObject
{
protected:
	sf::Texture texture;
	sf::Sound sound;
	std::vector<sf::SoundBuffer*> soundBuffers;
	//each derived full class will have an enum with sound names refering to sounds array

public:
	sf::Sprite sprite;
	// Default Constructor that shouldn't be used..
	GameObject();
	// Constructor
	GameObject(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles [], int audioFilesNum);
	virtual ~GameObject();
	// render the sprite on screen based on position
	void render(sf::RenderWindow&);
	// updates the object position
	virtual void update(float dt)=0;
	// play the sound in index of soundbuffer
	void playSound(int index);
	void checkCollision(GameObject& other);

private:
	// Handles collision of objects
	virtual void _onCollision(GameObject& other)=0;

};

