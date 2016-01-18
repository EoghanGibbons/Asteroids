#include "Player.h"

//Constructor
Player::Player(std::string name, float pXPos, float pYPos, float pXVel, float pYVel){
	texture.loadFromFile(name+".png");
	sprite.setTexture(texture);
	sprite.setScale(.5, .5);
	sprite.setOrigin(width / 2, height / 2);
	position.x = pXPos;
	position.y = pYPos;
	velocity.x = pXVel;
	velocity.y = pYVel;
}

void Player::update(sf::Vector2f maxExtends){
	//Wrap around world implementation
	#pragma region Wrap Around World
	if (position.x > maxExtends.x){
		position.x = -1 * width;
	}
	else if (position.x < -1*width){
		position.x = maxExtends.x;
	}

	if (position.y > maxExtends.y){
		position.y = -1 * height;
	}
	else if (position.y < -1 * height){
		position.y = maxExtends.y;
	}
	#pragma endregion 
	
	direction.x = (float)sin((M_PI / 180.0f) * (sprite.getRotation()));
	direction.y = (float)cos((M_PI / 180.0f) * (sprite.getRotation()));


	//Player roation and Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		sprite.rotate(-.10);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		sprite.rotate(.10);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		position = position + velocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		position = position - velocity;
	}

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