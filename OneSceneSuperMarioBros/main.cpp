#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
int main()
{
	float windowWidth = 2500, windowHeight = 1000;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sample Game", sf::Style::Close);
	sf::Texture bgtexture;
	if (!bgtexture.loadFromFile("res\\bg.png")) {
		std::cout << "Could not load image: bg.png \n";
	}
	sf::Sprite bgsprite;
	bgsprite.setTexture(bgtexture);
	window.setFramerateLimit(60);
	sf::Clock clock;
	GameManager gameManager;
	float fps = 60;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time dt = clock.restart();

		window.clear();
		//update and render objects
		window.draw(bgsprite);

		gameManager.updateObjects(window);
		window.display();
	}

	return 0;
}