#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "vector"
#include "Enemy.h"
#include "Bullet.h"
#include "Ship.h"
const float invSpeed = 5.5;
struct Ship;
class Invaders
{
public:
	std::vector<Enemy> monsters[10];
	std::vector<Bullet> bullets;

	std::vector<int> bulletsleft[10];
	Invaders();
	~Invaders();
	void update(Ship& player);
	void draw(sf::RenderWindow& window);
	bool bulletHit(Bullet& a);
	bool allDead();
	void reset();
private:
	void movedown();
	sf::Clock clock;
	int time=0;
	int level=0;
	sf::Texture tex;
	bool movingright;
};

