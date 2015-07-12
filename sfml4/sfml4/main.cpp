#include <SFML/Graphics.hpp>
#include "HUD.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
	window.setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());
	
	
	Ship player;
	Invaders invaders;
	HUD hud(&player,&invaders);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		hud.update(window);
		window.clear(sf::Color::White);
		hud.draw(window);
		window.display();
	}

	return 0;
}