#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();
	void updateObjects(sf::RenderWindow& window);
	void checkCollisions();
	void render();
	void playMusic();
};

