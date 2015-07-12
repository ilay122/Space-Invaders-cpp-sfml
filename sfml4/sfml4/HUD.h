#pragma once
#include "Invaders.h"
#include "Ship.h"
#include <SFML/Graphics.hpp>
class HUD
{
public:
	int state;//0-menu 1-pause 2-playing 3-winning 4-losing
	int hover;
	Ship* ship;
	Invaders* invaders;
	HUD(Ship* ship, Invaders* invaders);
	~HUD();
	void update(sf::RenderWindow& a);
	void draw(sf::RenderWindow& a);
private:
	bool uppressed;
	bool deletepressed;
	bool downpressed;
	bool enterpressed;
	bool ppressed;
	bool rpressed;
	sf::Font font;
	sf::Text text;
	sf::Texture title;
	sf::Sprite titlespr;
};

