#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();
	void updateObjects(float dt, sf::RenderWindow& window);
	void checkCollisions();
	void render();
	void playMusic();
};

