#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include "GameManager.h"
#include "Ground.h"
#include "Platform.h"
#include "Player.h"
#include "Flag.h"
#include "Enemy.h"

int windowWidth = 2500, windowHeight = 1000;
std::string name = "C:\\Users\\minna\\Google Drive\\C++\\OneSceneSuperMarioBros\\x64\\Debug\\temptexture.png";
std::string names[] = { "1" };
Player * player = new Player(sf::Vector2f(0, 0), sf::Vector2f(10, windowHeight - 200), 50, 50, name, names, 0, 1, sf::Vector2f(10, 20), 6);

Ground * grounds[] = { new Ground(sf::Vector2f(0,0), sf::Vector2f(0, windowHeight - 100), 700, 100, name, names, 0), 
					   new Ground(sf::Vector2f(0,0), sf::Vector2f(900, windowHeight - 100), 350, 100, name, names, 0),
	                   new Ground(sf::Vector2f(0,0), sf::Vector2f(windowWidth - 200, windowHeight - 100), 200, 100, name, names, 0) };
Platform * platforms[] = { new Platform(sf::Vector2f(0,0), sf::Vector2f(900+350+100, windowHeight - 50), 300, 50, name, names, 0, sf::Vector2f(0, 400), sf::Vector2f(0, 5)),
						   new Platform(sf::Vector2f(0,0), sf::Vector2f(900+350+100+ 300 + 100, windowHeight - 200), 300, 50, name, names, 0, sf::Vector2f(200,0), sf::Vector2f(3,0))};
//Enemy enemy();

std::array<GameObject*, 6> objects = {grounds[0], grounds[1], grounds[2], platforms[0], platforms[1], player};

sf::Music music;
std::string musicFile = "music.flac";

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::updateObjects(sf::RenderWindow& window)
{
	for (int i = 0; i < objects.size(); ++i) {
		objects[i]->update();
	}
	checkCollisions();
	
	for (int i = 0; i < objects.size(); ++i) {
		objects[i]->render(window);
	}
	

}

void GameManager::checkCollisions() 
{
	int size = objects.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j)
				continue;
			objects[i]->checkCollision(*objects[j]);
		}
	}
}

void GameManager::render()
{

}

void GameManager::playMusic()
{
	if (music.openFromFile(musicFile)) {
		music.play();
	}
}
