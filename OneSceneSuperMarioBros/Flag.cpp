#include "Flag.h"
#include "Player.h"
#include <iostream>

Flag::Flag(sf::Vector2f spriteDim, sf::Vector2f position, int width, int height, std::string textureFile, std::string audioFiles[], int audioFilesNum)
	:GameObject(spriteDim, position, width, height, textureFile, audioFiles, audioFilesNum)
{
	flag = new AnimatedObject(sf::Vector2f(0, 0), sf::Vector2f(position.x-30, position.y), 30, 20, textureFile, audioFiles, 0, 1);
	flag->setAnimation(0);
	flag->playAnimation();
}

Flag::~Flag()
{
	delete flag;
}

void Flag::_onCollision(GameObject & other) {
	if (typeid(other) == typeid(Player)) {
		Player & player = (Player &)other;
		player.setCanMove(false);
		playerWon = true;
		playSound(win);
	}
}

void Flag::update() {
	flag->update();
}

void Flag::render(sf::RenderWindow& window) {
	window.draw(sprite);
	flag->render(window);
}

