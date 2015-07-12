#pragma once
#include <SFML/Graphics.hpp>
const float bulletSpeed = 10.f;
const sf::Vector2f size(5,15);
class Bullet
{
public:
	
	sf::RectangleShape shape;

	Bullet(sf::Vector2f pos, bool playershot);
	Bullet();
	~Bullet();
	bool update();
	void draw(sf::RenderWindow& window);
private:
	bool playershot;
};

