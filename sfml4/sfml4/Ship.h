#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "Invaders.h"
#include <SFML/Graphics.hpp>

const float shipSpeed = 10.f;
const sf::Vector2f startpos(800 / 2 - 100, 500);
struct Invaders;
class Ship
{
public:
	
	sf::Sprite shape;
	Bullet bult;
	bool isAlive;
	Ship();
	~Ship();
	void update(sf::Keyboard&, Invaders& inv);
	void draw(sf::RenderWindow& window);
	bool isShipShooting();
	bool isHit(Bullet& a);
	void reset();
	
private:
	sf::Texture shiptexture;
	bool isShooting;
};

