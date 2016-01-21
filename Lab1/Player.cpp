#include "Player.h"

//Constructor
Player::Player(std::string name, float pXPos, float pYPos, float pXVel, float pYVel):
gameObject(pXPos, pYPos, pXVel, pYVel){
	texture.loadFromFile(name+".png");
	gameObject::sprite.setTexture(texture);
	gameObject::sprite.setScale(.5, .5);
	gameObject::sprite.setOrigin((width / 2), (height / 2));
	gameObject::speed = 0.02f;
}

void Player::update(sf::Vector2f maxExtends, float time){
	//Player roation and Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		gameObject::angularVelocity++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		gameObject::angularVelocity--;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		gameObject::thrust();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		gameObject::reverse();
	}

	gameObject::update(maxExtends, time, true);
}

sf::Sprite Player::returnDrawable(){
	return sprite;
}

sf::Vector2f Player::getPosition() {
	return position;
}

sf::Vector2f Player::getVelocity() {
	return velocity;
}