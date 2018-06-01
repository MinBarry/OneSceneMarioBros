#pragma once
#include "AnimatedObject.h"
class Flag :
	public GameObject
{
public:
	Flag(sf::Vector2f spriteDim, sf::Vector2f position, int width, int height, std::string textureFile, std::string audioFiles[], int audioFilesNum);
	~Flag();
	bool isGameWon() { return playerWon; }
private:
	void _onCollision(GameObject & other);
	void update();
	void render(sf::RenderWindow & window);
	enum Animation{waving};
	enum Sound{win};
	bool playerWon;
	AnimatedObject *flag;
};

