#include "Platform.h"
#include <iostream>


Platform::Platform(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, sf::Vector2f distance, sf::Vector2f speed)
	:GameObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum)
{
	distanceToMove.x = distance.x;
	distanceToMove.y = distance.y;
	distanceMoved.x = distanceMoved.y = 0;
	direction.x = direction.y = 1;
	this->speed.x = speed.x;
	this->speed.y = speed.y;
}

Platform::Platform()
{
}
Platform::~Platform()
{
}

void Platform::_onCollision(GameObject & other) 
{
	other.sprite.setPosition(sf::Vector2f(other.sprite.getPosition().x, sprite.getPosition().y));
}

void Platform::update(float dt)
{
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;
	// move towards distancetoMove or zero then change direction
	distanceMoved.x = distanceMoved.x + speed.x * direction.x;
	if (distanceMoved.x >= distanceToMove.x || distanceMoved.x <= 0) {
		direction.x = -direction.x;
	}
	sprite.setPosition(sf::Vector2f(x + speed.x * direction.x, y));

	distanceMoved.y = distanceMoved.y + speed.y * direction.y;
	if (distanceMoved.y >= distanceToMove.y || distanceMoved.y <= 0) {
		direction.y = -direction.y;
	}
	std::cout << distanceMoved.x<<"\n";
	sprite.setPosition(sf::Vector2f(sprite.getPosition().x, y - speed.y *  direction.y));

}
