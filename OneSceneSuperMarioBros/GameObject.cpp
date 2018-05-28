#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
}

GameObject::GameObject(sf::Vector2f spriteDim, sf::Vector2f position, int width, int height, std::string textureFile, std::string audioFiles[], int audioFilesNum)
{
	//Load texture and setup sprite
	if (!texture.loadFromFile(textureFile)) {
		std::cout << "Could not load image: " << textureFile << "\n";
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteDim.x, spriteDim.y, width, height));
	sprite.setPosition(position);

	// Load and setup audio
	for (int i = 0; i < audioFilesNum; ++i) {
		sf::SoundBuffer* buffer = new sf::SoundBuffer();
		if (buffer->loadFromFile(audioFiles[i])) {
			soundBuffers.push_back(buffer);
		}
	}

}

GameObject::~GameObject()
{
	std::cout << "Destroying Base..\n";
	for (int i = 0; i < soundBuffers.size(); ++i) {
		delete soundBuffers[i];
	}
}

void GameObject::render(sf::RenderWindow& window) 
{
	//sprite.setPosition(position);
	window.draw(sprite);
}

void GameObject::playSound(int index)
{
	//sound.setBuffer(*soundBuffers[index]);
	//sound.play();
}

void GameObject::checkCollision(GameObject& other)
{
	sf::FloatRect otherbounds = other.sprite.getGlobalBounds();
	sf::FloatRect bounds = sprite.getGlobalBounds();
	//if ((otherbounds.left > bounds.left && otherbounds.left+ otherbounds.width < bounds.left + bounds.width)
	//	|| (otherbounds.top > bounds.top && otherbounds.top + otherbounds.height < bounds.top + bounds.height)) {
	if(otherbounds.intersects(bounds)){
		_onCollision(other);
	}
}

