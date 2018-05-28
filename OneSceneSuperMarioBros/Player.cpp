#include "Player.h"
#include <iostream>
Player::Player(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, int numAnimationFramse, sf::Vector2f speed, float weight)
	: AnimatedObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum, numAnimationFrames)
{
	this->speed.x = speed.x;
	this->speed.y = speed.y;
	this->weight = weight;
	disableJump = true;
	jumpHeight = 0;
	isGrounded = false;
}

Player::~Player()
{
}

void Player::update()
{
	float currentX = sprite.getPosition().x;
	float currentY = sprite.getPosition().y;
	//std::cout << "x : " << currentX << " Y : " << currentY<<"\n";
	std::cout << " jumpHeight : " << jumpHeight << "  disable jump : " << disableJump << "\n";
	setAnimation(idle);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		currentX = currentX + speed.x;
		if(isGrounded)
			setAnimation(right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		currentX = currentX - speed.x;
		if (isGrounded)
			setAnimation(left);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !disableJump) {
		if (isGrounded)
			playSound(jumpSound);
		isGrounded = false;
		currentY =  currentY - speed.y;
		jumpHeight = jumpHeight + speed.y;
	}
	
	sprite.setPosition(sf::Vector2f(currentX, currentY + weight));
	
	if (jumpHeight >= MAX_JUMP) {
		disableJump = true;
		jumpHeight = 0;
	}
	if (isGrounded) {
		disableJump = false;
	}

}

void Player::_onCollision(GameObject& other) 
{

}