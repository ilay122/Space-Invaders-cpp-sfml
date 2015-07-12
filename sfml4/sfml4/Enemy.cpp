#include "Enemy.h"


Enemy::Enemy(sf::Texture& tex)
{
	shape.setTexture(tex);
	bulletsleft = 5;
}


Enemy::~Enemy()
{
}
