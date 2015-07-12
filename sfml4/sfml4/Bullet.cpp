#include "Bullet.h"


Bullet::Bullet(sf::Vector2f pos,bool playershot)
{
	shape.setPosition(pos);
	this->playershot = playershot;
	shape.setSize(size);
	shape.setFillColor(sf::Color::Black);
}
Bullet::Bullet(){
	this->playershot = true;
	shape.setSize(size);
	shape.setFillColor(sf::Color::Black);
}


Bullet::~Bullet()
{
}

bool Bullet::update(){
	if (playershot){
		shape.move(0,-bulletSpeed);
	}
	else{
		shape.move(0, bulletSpeed);
	}
	if (shape.getPosition().y < 0 || shape.getPosition().y + shape.getGlobalBounds().height > 600)
		return false;
	return true;
}
void Bullet::draw(sf::RenderWindow& window){
	window.draw(shape);
}