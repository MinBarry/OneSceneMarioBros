#include "Ground.h"
#include <iostream>


Ground::Ground()
{
}

Ground::Ground(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum)
	:GameObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum)
{
}

Ground::~Ground()
{
	std::cout << "Destroying Ground..";
}

void Ground::_onCollision(GameObject& other)
{
	other.setY(colliderPos.y);
}

void Ground::_updateCollider(float dt) 
{
}