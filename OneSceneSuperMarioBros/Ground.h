#pragma once
#include "GameObject.h"

class Ground :
	public GameObject
{
public:
	Ground();
	Ground(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum);
	~Ground();
	void update();
private:
	void _onCollision(GameObject & other);
	enum sounds {playerSteps};
};

