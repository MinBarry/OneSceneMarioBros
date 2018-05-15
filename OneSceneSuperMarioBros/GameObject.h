#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class GameObject
{
protected:
	//spriteDim is the size of the sprite to cut from the spritesheet
	//colliderPos is the x y of collider which gets update before normal position
	//positioin is the current x y of the object in scene
	sf::Vector2f spriteDim, colliderPos, position;
	float width, height;
	//sprite variables
	sf::Sprite sprite;
	sf::Texture texture;
	//sound variables
	sf::Sound sound;
	std::vector<sf::SoundBuffer*> soundBuffers;
	//each derived full class will have an enum with sound names refering to sounds array

public:
	// Default Constructor that shouldn't be used..
	GameObject();
	// Constructor
	GameObject(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles [], int audioFilesNum);
	virtual ~GameObject();
	// render the sprite on screen based on position
	void render(sf::RenderWindow&);
	// updates the object position
	void update(float dt);
	// updates the object position. Can only be called after collider is updated and handled
	void updatePosition();
	// play the sound in index of soundbuffer
	void playSound(int index);
	void checkCollision(GameObject& other);
	void setY(float y) { colliderPos.y = y; }
	void setX(float x) { colliderPos.x = x; }

private:
	// updates the colllider position based on delta time
	virtual void _updateCollider(float dt)=0;
	// Handles collision of objects
	virtual void _onCollision(GameObject& other)=0;

};

