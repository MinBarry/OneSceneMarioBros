#include "Player.h"
#include <iostream>
Player::Player(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, int numAnimationFrames, sf::Vector2f speed, float weight)
	: AnimatedObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum, numAnimationFrames)
{
	this->speed.x = speed.x;
	this->speed.y = speed.y;
	this->weight = weight;
	sprite.setOrigin(width/2.0, 0);
	sprite.scale(5, 5);
	disableJump = true;
	isJumping = false;
	jumpHeight = 0;
	isGrounded = false;
	canMove = true;
	
}

Player::~Player()
{
}

void Player::update()
{
	if (canMove) {
		float currentX = sprite.getPosition().x;
		float currentY = sprite.getPosition().y;
		setAnimation(jump);
		if (isGrounded) {
			disableJump = false;
			isJumping = false;
			setAnimation(idle);
			jumpHeight = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			currentX = currentX + speed.x;
			if (isGrounded)
				setAnimation(walk);
			sprite.setScale(5, 5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			currentX = currentX - speed.x;
			if (isGrounded)
				setAnimation(walk);
			sprite.setScale(-5, 5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded) {
			isJumping = true;
			playSound(jumpSound);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !disableJump && isJumping) {
			currentY = currentY - speed.y;
			jumpHeight = jumpHeight + speed.y;
		}

		sprite.setPosition(sf::Vector2f(currentX, currentY + weight));

		if (jumpHeight >= MAX_JUMP) {
			disableJump = true;
			jumpHeight = 0;
		}
		isGrounded = false;
	}
	playAnimation();
}

void Player::_onCollision(GameObject& other) 
{

}