#include <SFML/Graphics.hpp>
#include "Ground.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1000), "Sample Game");
	sf::Clock clock;
	sf::Vector2f vector(200, 100);
	std::string name = "C:\\Users\\minna\\Google Drive\\C++\\OneSceneSuperMarioBros\\x64\\Debug\\temptexture.png";
	std::string names[] = {"1"};
	Ground ground(vector, vector, 200.0f, 100.0f, name, names, 0);

	sf::Texture texture;
	texture.loadFromFile(name);
	sf::Sprite sp;
	sp.setTexture(texture);
	sp.setTextureRect(sf::IntRect(200, 200, 200, 200));
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
		ground.render(window);
		//window.draw(sp);
		window.display();
	}

	return 0;
}