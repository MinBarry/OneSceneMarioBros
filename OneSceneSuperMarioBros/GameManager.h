#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();
	void updateObjects(float dt);
	void checkCollisions();
	void playMusic();
};

