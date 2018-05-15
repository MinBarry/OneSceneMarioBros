#include "Platform.h"



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


Platform::~Platform()
{
}

void Platform::_onCollision(GameObject & other) 
{
	other.setY(colliderPos.y);
}

void Platform::_updateCollider(float dt)
{
	// move towards distancetoMove or zero then change direction
	distanceMoved.x = direction.x * distanceMoved.x + speed.x * dt;
	if (distanceMoved.x >= distanceToMove.x || distanceMoved.x <= 0) {
		direction.x = -direction.x;
	}
	colliderPos.x += distanceMoved.x;

	distanceMoved.y = direction.y * distanceMoved.y + speed.y * dt;
	if (distanceMoved.y >= distanceToMove.y || distanceMoved.y <= 0) {
		direction.y = -direction.y;
	}
	colliderPos.y += distanceMoved.y;

}
