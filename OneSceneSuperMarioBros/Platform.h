#pragma once
#include "GameObject.h"
#include "Ground.h"
class Platform :
	public Ground
{
public:
	Platform(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, sf::Vector2f distance, sf::Vector2f speed);
	~Platform();
	Platform();
	void update();


private:
	sf::Vector2f distanceToMove, distanceMoved, speed, direction;
};

