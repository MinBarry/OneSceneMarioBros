#include <SFML/Audio.hpp>
#include <array>
#include "GameManager.h"
#include "Ground.h"
#include "Platform.h"
#include "Player.h"
#include "Flag.h"
#include "Enemy.h"

Player player();
Ground grounds[] = { Ground(), Ground(), Ground() };
Platform platforms[] = { Platform(), Platform() };
Enemy enemy();

std::array<GameObject&, 7> objects = {player, grounds[0], grounds[1], grounds[2], platforms[0], platforms[1], enemy};

sf::Music music;
std::string musicFile = "music.flac";

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::updateObjects(float dt)
{
	for (int i = 0; i < objects.size; ++i) {
		objects[i].update(dt);
	}
	checkCollisions();
	for (int i = 0; i < objects.size; ++i) {
		objects[i].updatePosition();
	}

}

void GameManager::checkCollisions() 
{
	int size = objects.size;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j)
				continue;
			objects[i].checkCollision(objects[j]);
		}
	}
}

void GameManager::playMusic()
{
	if (music.openFromFile(musicFile)) {
		music.play();
	}
}
