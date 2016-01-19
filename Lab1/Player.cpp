#include "Player.h"

//Constructor
Player::Player(std::string name, float pXPos, float pYPos, float pXVel, float pYVel):
gameObject(pXPos, pYPos, pXVel, pYVel){
	texture.loadFromFile(name+".png");
	sprite.setTexture(texture);
	sprite.setScale(.5, .5);
	sprite.setOrigin(width / 2, height / 2);
}

void Player::update(sf::Vector2f maxExtends, float time){
	
	//Player roation and Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		sprite.rotate(-.10);;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		sprite.rotate(.10);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		accel.x = /* accel.x  + */ .0001;
		accel.y = /* accel.y+  */ .0001;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		accel.x = /* accel.x- */ .00001;
		accel.y = /* accel.y- */ .00001;
	}

	//velocity.x = accel.x;
	//velocity.y = accel.y;
	velocity.x = cos(sprite.getRotation()* ((3.14159265 / 180)*3.f))/10;
	velocity.y = sin(sprite.getRotation()* ((3.14159265 / 180)*-3.f))/10;

	gameObject::update(maxExtends, time*100, sprite.getRotation());

	sprite.setPosition(position);
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