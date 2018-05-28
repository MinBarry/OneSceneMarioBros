#include "AnimatedObject.h"



AnimatedObject::AnimatedObject(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum,  int numAnimationFrames)
	:GameObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum)
{
	this->numAnimationFrames = numAnimationFrames;
	currentAnimation = 0;
	currentFrame = 0;
}

AnimatedObject::~AnimatedObject()
{
}

AnimatedObject::AnimatedObject() {

}

void AnimatedObject::setAnimation(int index) {
	currentAnimation = index;
	currentFrame = 0;
}

void AnimatedObject::playAnimation() {
	int width = sprite.getTextureRect().width;
	int height = sprite.getTextureRect().height;
	if (currentFrame == numAnimationFrames) {
		currentFrame = 0;
	}
	sprite.setTextureRect(sf::IntRect(width * currentFrame, height * currentAnimation, width, height));
	currentFrame += 1;
}
