#include "Ship.h"


Ship::Ship()
{
	shiptexture.loadFromFile("ship.png");

	this->isShooting = false;
	this->shape.setTexture(shiptexture);
	shape.setPosition(startpos);
	shape.setScale(sf::Vector2f(0.30,0.55));
	isAlive = true;
}


Ship::~Ship()
{
	
}

void Ship::update(sf::Keyboard& keyb,Invaders& inv){
	
	if (keyb.isKeyPressed(keyb.Right)){
		shape.move(shipSpeed, 0);
	}
	if (keyb.isKeyPressed(keyb.Left)){
		shape.move(-shipSpeed, 0);
	}
	if (shape.getPosition().x < 0){
		shape.setPosition(0, shape.getPosition().y);
	}
	if (shape.getPosition().x > 800 - shape.getGlobalBounds().width){
		shape.setPosition(800 - shape.getGlobalBounds().width, shape.getPosition().y);
	}
	if (isShooting){
		bool alive=bult.update();
		isShooting = alive;
		if (isShooting){
			bool hit = inv.bulletHit(bult);
			if (hit){
				isShooting = false;
			}
		}
	}
	else{
		if (keyb.isKeyPressed(keyb.Space)){
			sf::Vector2f cp = shape.getPosition();
			cp.x += 38;
			cp.y -= 10;
			bult=Bullet(cp,true);
			isShooting = true;
		}
	}

}
void Ship::draw(sf::RenderWindow& window){
	window.draw(shape);

	if (isShooting){
		bult.draw(window);
	}
}
bool Ship::isShipShooting(){
	return isShooting;
}
bool Ship::isHit(Bullet& a){
	bool dead= shape.getGlobalBounds().intersects(a.shape.getGlobalBounds());
	if (dead)
		isAlive = false;
	return dead;
}
void Ship::reset(){
	this->isShooting = false;
	shape.setPosition(startpos);
	isAlive = true;
}