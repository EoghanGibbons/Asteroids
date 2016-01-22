#include "gameObject.h"

gameObject::gameObject(float pXPos, float pYPos, float pXVel, float pYVel):
health(4), range(15) {
	position.x = pXPos;
	position.y = pYPos;
	velocity.x = pXVel;
	velocity.y = pYVel;
	direction = sf::Vector2f(0, 0);
}

gameObject::~gameObject() {

}

float gameObject::lenght(sf::Vector2f vec) {
	return ((vec.x * vec.x) + ((vec.y * vec.y)));
}

sf::Vector2f gameObject::normalise(sf::Vector2f vec){
	//if (lenght(vec))
	return (vec / lenght(vec));
}

void gameObject::update(sf::Vector2f maxExtends, float time) {
#pragma region Wrap Around World
	if (position.x > maxExtends.x){
		position.x = 0;
	}
	else if (position.x < 0){
		position.x = maxExtends.x;
	}

	if (position.y > maxExtends.y + 100){
		position.y = 0;
	}
	else if (position.y < 0){
		position.y = maxExtends.y - (sprite.getGlobalBounds().height);
	}
#pragma endregion
	//Drag

	//direction = sf::Vector2f((cos((sprite.getRotation() + 90)* PI / 180)*-1), (sin((sprite.getRotation() + 90)* PI / 180))*-1);
	//velocity = sf::Vector2f(direction * speed * time);

	position += sf::Vector2f(velocity.x, velocity.y) * (time * speed);
	//position += velocity;
	sprite.setPosition(position);
}

void gameObject::update(sf::Vector2f maxExtends, float time, bool controlable) { //controllable gameObject
	angularRotation += angularVelocity*time;
	if (angularVelocity > MAX_ANGULAR_VELOCTIY){
		angularVelocity = MAX_ANGULAR_VELOCTIY;
	}
	else if (angularVelocity < -1 * MAX_ANGULAR_VELOCTIY){
		angularVelocity = MAX_ANGULAR_VELOCTIY * -1;
	}

	//Drag
	angularVelocity *= .9;

	direction = sf::Vector2f((cos((sprite.getRotation() + 90)* PI / 180)*-1), (sin((sprite.getRotation() + 90)* PI / 180))*-1);
	velocity = sf::Vector2f(direction * speed * time);

#pragma region Wrap Around World
	if (position.x > maxExtends.x){
		position.x = -1 * width;
	}
	else if (position.x < -1 * width){
		position.x = maxExtends.x;
	}

	if (position.y > maxExtends.y){
		position.y = -1 * height;
	}
	else if (position.y < -1 * height){
		position.y = maxExtends.y;
	}
#pragma endregion

	position += velocity;
	sprite.setRotation(angularRotation);
	sprite.setPosition(position);
}

void gameObject::thrust() {
	if (speed < MAX_SPEED)
		speed += 10;
	else
		speed = MAX_SPEED;
}

void gameObject::reverse() {
	if (speed > -MAX_SPEED)
		speed -= 10;
	else
		speed = -MAX_SPEED;
}

float gameObject::angleBetween(sf::Vector2f vec1, sf::Vector2f vec2){
	if (vec1.x == 0 && vec1.y == 0) return 0.0f;
	if (vec2.x == 0 && vec2.y == 0) return 0.0f;
	
	vec1 = normalise(vec1);
	vec2 = normalise(vec2);

	if (dotProduct(vec1, vec2) <= -1) {
		return PI;
	}
	else if (dotProduct(vec1, vec2) >= 1) {
		return 0;
	}
	return acos(dotProduct(vec1, vec2));
}

float gameObject::dotProduct(sf::Vector2f vec1, sf::Vector2f vec2) {
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) );
}