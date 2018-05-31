#include "Ground.h"
#include <iostream>
#include "Player.h"

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
	//if bottoms intersect 
	sf::FloatRect otherbounds = other.sprite.getGlobalBounds();
	sf::FloatRect bounds = sprite.getGlobalBounds();
	if(otherbounds.top <= bounds.top && 
		(otherbounds.left > bounds.left || otherbounds.left+otherbounds.width > bounds.left)&& 
		(otherbounds.left < bounds.left+bounds.width || otherbounds.left+otherbounds.width < bounds.left)){
		other.sprite.setPosition(sf::Vector2f(other.sprite.getPosition().x, sprite.getPosition().y - other.sprite.getGlobalBounds().height));
		if (typeid(other) == typeid(Player)) {
			std::cout << "Player is stepping on me!";
			Player & player = (Player &)other;
			player.setIsGrounded();
			playSound(playerSteps);
		}
	}
	if (otherbounds.top >= bounds.top &&
		(otherbounds.left < bounds.left && otherbounds.left + otherbounds.width > bounds.left)) {
		other.sprite.setPosition(sf::Vector2f(bounds.left-otherbounds.width, other.sprite.getPosition().y));
	}
	if (otherbounds.top >= bounds.top &&
		(otherbounds.left < bounds.left+bounds.width && otherbounds.left + otherbounds.width > bounds.left+bounds.width)) {
		other.sprite.setPosition(sf::Vector2f(bounds.left+bounds.width, other.sprite.getPosition().y));
	}
}

void Ground::update()
{
}

