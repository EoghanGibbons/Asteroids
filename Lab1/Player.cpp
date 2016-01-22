#include "Player.h"

//Constructor
Player::Player(std::string name, sf::Vector2f pPos, sf::Vector2f pVel) :
gameObject(pPos, pVel){
	texture.loadFromFile(name+".png");
	gameObject::sprite.setTexture(texture);
	gameObject::sprite.setScale(.5, .5);
	gameObject::sprite.setOrigin((width / 2), (height / 2));
}

void Player::update(sf::Vector2f maxExtends, float time){
	//Player roation and Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		gameObject::angularVelocity -= 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		gameObject::angularVelocity += 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		gameObject::thrust();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		gameObject::reverse();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		bullets.push_back(Bullet(gameObject::position, gameObject::sprite.getRotation(), 600));
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update(time);
	}
	gameObject::update(maxExtends, time, true);
}

sf::Vector2f Player::getPosition() {
	return gameObject::position;
}

sf::Vector2f Player::getVelocity() {
	return gameObject::velocity;
}