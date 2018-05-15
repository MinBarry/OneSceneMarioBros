#pragma once
#include "GameObject.h"
class Platform :
	public GameObject
{
public:
	Platform(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, sf::Vector2f distance, sf::Vector2f speed);
	~Platform();
	Platform();



private:
	sf::Vector2f distanceToMove, distanceMoved, speed, direction;
	void _onCollision(GameObject & other);
	void _updateCollider(float time);
};

