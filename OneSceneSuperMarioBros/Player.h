#pragma once
#include "AnimatedObject.h"
class Player :
	public AnimatedObject
{
public:
	Player(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, int numAnimationFrames, sf::Vector2f speed, float weight);
	~Player();
	void update();
	void setIsGrounded() { isGrounded = true; }
	void setCanMove(bool canMove) { this->canMove = canMove; }
private:
	float const MAX_JUMP = 250;
	sf::Vector2f speed;
	float weight;
	bool disableJump;
	bool isGrounded;
	bool canMove;
	float jumpHeight;
	enum Animations {idle, left, right, jump };
	enum Sounds {jumpSound};
	void _onCollision(GameObject & other);
};

