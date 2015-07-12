#include "Invaders.h"


Invaders::Invaders()
{
	tex.loadFromFile("invader.png");
	this->reset();
}


Invaders::~Invaders()
{
}

void Invaders::update(Ship& player){
	sf::Time a = clock.getElapsedTime();
	time = a.asMilliseconds();
	if (time >=1000 - level*60){
		time = 0;
		clock.restart();
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < monsters[i].size(); j++){
				if (movingright){
					monsters[i].at(j).shape.move(invSpeed, 0);
				}
				else{
					monsters[i].at(j).shape.move(-invSpeed, 0);
				}
			}
		}
		for (int i = 0; i < 10; i++){
			if (!monsters[i].empty()){
				if (movingright){
					if (monsters[i].at(monsters[i].size() - 1).shape.getPosition().x >= 800 - monsters[i].at(monsters[i].size() - 1).shape.getGlobalBounds().width){
						movingright = false;
						movedown();
						level++;
					}
				}
				else{
					if (monsters[i].at(monsters[i].size() - 1).shape.getPosition().x <=0){
						movingright = true;
						movedown();
						level++;
					}
				}
			}
		}

	}
	for (int i = 0; i < bullets.size(); i++){
		bullets[i].update();
		if (player.isHit(bullets[i])){
			bullets.erase(bullets.begin() + i);
		}
	}
	
	
	for (int i = 0; i < 10; i++){
		//std::srand(std::time(0));
		int rand = std::rand() % 1050-level*60;
		if (rand <= 2 && !monsters[i].empty() && monsters[i].at(monsters[i].size() - 1).bulletsleft>0){
			sf::Vector2f cp;
			cp = monsters[i].at(monsters[i].size() - 1).shape.getPosition();
			cp.x += 24;
			cp.y += 10;
			Bullet shot(cp, false);
			monsters[i].at(monsters[i].size() - 1).bulletsleft -= 1;
			bullets.push_back(shot);
			break;
		}
	}


}

void Invaders::draw(sf::RenderWindow& window){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < monsters[i].size(); j++){
			window.draw(monsters[i].at(j).shape);
		}
	}
	for (int i = 0; i < bullets.size(); i++){
		bullets[i].draw(window);
	}
}
void Invaders::movedown(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < monsters[i].size(); j++){
			monsters[i].at(j).shape.move(0,20);
		}
	}
}
bool Invaders::bulletHit(Bullet& bul){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < monsters[i].size(); j++){
			if (bul.shape.getGlobalBounds().intersects(monsters[i].at(j).shape.getGlobalBounds())){
				monsters[i].erase(monsters[i].begin() + j);
				return true;
			}
		}
	}
	return false;
}
bool Invaders::allDead(){
	for (int i = 0; i < 10; i++){
		if (!monsters[i].empty())
			return false;
	}
	return true;
}
void Invaders::reset(){
	
	this->movingright = true;
	Enemy a(tex);
	a.shape.setScale(0.2, 0.2);
	a.shape.setTexture(tex);
	for (int i = 0; i < 10; i++){
		monsters[i] = std::vector <Enemy>();
		for (int j = 0; j < 5; j++){
			a.shape.setPosition(i*(a.shape.getGlobalBounds().width + 10) + 50, j*(a.shape.getGlobalBounds().height + 5) + 50);
			monsters[i].push_back(a);
		}
	}
	level = 0;
	bullets.clear();
	
}