#include "AnimatedObject.h"



AnimatedObject::AnimatedObject(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum,  int numAnimationFrames)
	:GameObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum)
{
	this->numAnimationFrames = numAnimationFrames;
	currentAnimation = 0;
	currentFrame = 0;
	std::cout << "num frames: " << numAnimationFrames << " current frame: " << currentFrame << " current animation: " << currentAnimation << "\n";

}

AnimatedObject::~AnimatedObject()
{
}

AnimatedObject::AnimatedObject() {

}

void AnimatedObject::setAnimation(int index) {
	currentAnimation = index;
}

void AnimatedObject::playAnimation() {
	int width = sprite.getTextureRect().width;
	int height = sprite.getTextureRect().height;
	if (currentFrame > numAnimationFrames) {
		currentFrame = 0;
	}
	sprite.setTextureRect(sf::IntRect(width * floor(currentFrame), height * currentAnimation, width, height));
	currentFrame += 0.3;
}

void AnimatedObject::update() {
	playAnimation();
}
