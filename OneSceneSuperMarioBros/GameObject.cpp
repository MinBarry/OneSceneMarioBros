#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
}

GameObject::GameObject(sf::Vector2f spriteDim, sf::Vector2f position, float width, float height, std::string textureFile, std::string audioFiles[], int audioFilesNum)
{
	this->spriteDim.x = spriteDim.x;
	this->spriteDim.y = spriteDim.y;
	this->colliderPos.x = position.x;
	this->colliderPos.y = position.y;
	this->position.x = position.x;
	this->position.y = position.y;
	this->width = width;
	this->height = height;
	//Load texture and setup sprite
	if (!texture.loadFromFile(textureFile)) {
		std::cout << "Could not load image: " << textureFile << "\n";
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(spriteDim.x, spriteDim.x, spriteDim.y, spriteDim.y));
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
	sprite.setPosition(position);
	window.draw(sprite);
}

void GameObject::update(float dt) 
{
	_updateCollider(dt);
}

void GameObject::updatePosition()
{
	position.x = colliderPos.x;
	position.y = colliderPos.y;
}
void GameObject::playSound(int index)
{
	sound.setBuffer(*soundBuffers[index]);
	sound.play();
}

void GameObject::checkCollision(GameObject& other)
{
	if ((other.colliderPos.x > colliderPos.x && other.colliderPos.x + other.width < colliderPos.x + width)
		|| (other.colliderPos.y > colliderPos.y && other.colliderPos.y + other.height < colliderPos.y + height)) {
		_onCollision(other);
	}
}

