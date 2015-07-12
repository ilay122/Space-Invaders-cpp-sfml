#include "HUD.h"


HUD::HUD(Ship* ship, Invaders* invaders)
{
	font.loadFromFile("Snowstorm.ttf");
	this->ship = ship;
	this->invaders = invaders;
	state = 0;
	hover = 0;
	text.setFont(font);
	text.setColor(sf::Color::Black);

	title.loadFromFile("title.jpg");
	titlespr.setTexture(title);
	titlespr.setPosition(230,70);
}


HUD::~HUD()
{
}
void HUD::update(sf::RenderWindow& window){
	
	//0-menu 1-pause 2-playing 3-winning  4-losing
	sf::Keyboard currentState = sf::Keyboard();
	switch (state){
	case 0:{
		if (!uppressed && currentState.isKeyPressed(currentState.Up)){
			hover--;
			if (hover < 0)
				hover = 1;
		}
		if (!downpressed && currentState.isKeyPressed(currentState.Down)){
			hover++;
			if (hover > 1)
				hover = 0;
		}
		if (!enterpressed && currentState.isKeyPressed(currentState.Space)){
			if (hover == 0)
				state = 2;
			else if (hover == 1)
				window.close();

		}
		break;
	}
	case 1:{
		if (!ppressed && currentState.isKeyPressed(currentState.P)){
			state = 2;
		}
		if (!enterpressed && currentState.isKeyPressed(currentState.BackSpace)){
			ship->reset();
			invaders->reset();
			state = 0;
		}
		break;
	}
	case 2:{
		if (!ppressed && currentState.isKeyPressed(currentState.P)){
			state = 1;
		}
		ship->update(currentState,(*invaders));
		invaders->update((*ship));
		if (!ship->isAlive)
			state = 4;
		if (invaders->allDead())
			state = 3;
		break;
	}
	case 3:{
		if (!rpressed && currentState.isKeyPressed(currentState.R)){
			ship->reset();
			invaders->reset();
			state = 2;
		}
		break;
	}
	case 4:{
		if (!rpressed && currentState.isKeyPressed(currentState.R)){
			ship->reset();
			invaders->reset();
			state = 2;
		}
		break;
	}
	}
	uppressed = currentState.isKeyPressed(currentState.Up);
	deletepressed = currentState.isKeyPressed(currentState.BackSpace);
	downpressed = currentState.isKeyPressed(currentState.Down);
	enterpressed = currentState.isKeyPressed(currentState.Space);
	ppressed = currentState.isKeyPressed(currentState.P);
	rpressed = currentState.isKeyPressed(currentState.R);
	
}
void HUD::draw(sf::RenderWindow& a){
	switch (state){
	case 0:{
		a.draw(titlespr);
		text.setCharacterSize(28);
		text.setStyle(text.Regular);
		text.setString("Play");
		text.setPosition(380, 350);
		if (hover == 0){
			text.setStyle(text.Underlined);
		}
		a.draw(text);

		text.setStyle(text.Regular);

		text.setString("Quit");
		if (hover == 1){
			text.setStyle(text.Underlined);
		}
		text.move(0, 100);
		a.draw(text);
		break;
	}
	case 1:{
		text.setString("press P to unpause and press \n backspace to return to menu");
		text.setPosition(250,400);
		a.draw(text);
		
	}
	case 2:{
		ship->draw(a);
		invaders->draw(a);
		break;
	}
	case 3:{
		text.setPosition(250,400);
		text.setString("GJ you won press R to restart");
		a.draw(text);
		break;
	}
	case 4:{
		text.setPosition(250, 400);
		text.setString("nice try press R to restart");
		a.draw(text);
		break;
	}
	}
}