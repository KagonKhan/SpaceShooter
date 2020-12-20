#include "pch.h"
#include "Missile.h"
#include "Animator.h"

Missile::Missile(std::string spriteFilename, std::string spriteFilepath,
	std::string soundFilename, std::string soundFilepath,
	sf::Vector2f position, float speed, float damage, float rotation) :

	Ammunition(spriteFilename, spriteFilepath, soundFilename, soundFilepath, position, speed, damage, rotation)

{

	target = nullptr;
	angularVelocity = 350.f;

}

Missile::~Missile() {

}

void Missile::setTargetPosition(sf::Vector2f targetPosition) {
	this->targetPosition = targetPosition;
}

void Missile::setTargetEntity(Entity* target) {
	this->target = target;
}







void Missile::update(const float& dt) {
	updateMissileMovement(dt);
	updateMissileRotation(dt);
}

void Missile::render(sf::RenderWindow* window) {
	window->draw(ammoSprite);
}





void Missile::updateMissileMovement(const float& dt) {
	sf::Vector2f direction(sinf((ammoSprite.getRotation() * 3.1415926f / 180.f)), -cosf((ammoSprite.getRotation() * 3.1415926f / 180.f)));

	missileVelocity = direction * ammoSpeed * dt;

	ammoSprite.move(missileVelocity);
}



void Missile::updateMissileRotation(const float& dt) {

	sf::Vector2f A(missileVelocity);
	sf::Vector2f B(targetPosition - ammoSprite.getPosition());

	float perpDotValue = PerpendicularDotProduct(A, B);

	if (perpDotValue < 0) {
		ammoSprite.rotate(-angularVelocity * dt);
	}
	else if (perpDotValue > 0) {
		ammoSprite.rotate(angularVelocity * dt);
	}
	else {
		if (DotProduct(A, B) < 0)
			missileVelocity.y *= -1;
	}

	if(angularVelocity > 20)
		angularVelocity -= 2;
}

























float Missile::PerpendicularDotProduct(const sf::Vector2f A, const sf::Vector2f B) {
	return (A.x * B.y) - (A.y * B.x);
}

float Missile::DotProduct(const sf::Vector2f A, const sf::Vector2f B) {
	return (A.x * B.x) + (A.y * B.y);
}