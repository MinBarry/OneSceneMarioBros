#pragma once
#include "GameObject.h"
class AnimatedObject :
	public GameObject
{
public:
	AnimatedObject(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum, int numAnimationFrames);
	~AnimatedObject();
	AnimatedObject();
	void playAnimation();
	void update();
	void setAnimation(int index);

protected:
	int currentAnimation;
	float currentFrame;
	int numAnimationFrames;
};

