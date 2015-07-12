#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
public:
	sf::Sprite shape;
	int bulletsleft;
	Enemy(sf::Texture& tex);
	~Enemy();
};

