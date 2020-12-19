#include "pch.h"
#include "Missile.h"

Missile::Missile(sf::Vector2f targetPosition, sf::Vector2f position, float initialRotation) {

	missile.setSize(sf::Vector2f(20, 100));
	missile.setOrigin(missile.getSize()/2.f);
	missile.setRotation(initialRotation);
	missile.setPosition(position);



	angularVelocity = 150.f;

	std::cout << "Missile Spawned\n";
}

Missile::~Missile() {
}

void Missile::setTargetPosition(sf::Vector2f targetPosition) {
	this->targetPosition = targetPosition;
}














void Missile::update(const float& dt) {
	updateMissileMovement(dt);
	updateMissileRotation(dt);
}

void Missile::render(sf::RenderWindow* window) {
	window->draw(missile);
}



















void Missile::updateMissileMovement(const float& dt) {
	sf::Vector2f direction(sinf((missile.getRotation() * 3.1415926f / 180.f)), -cosf((missile.getRotation() * 3.1415926f / 180.f)));

	missileVelocity = direction * 800.f * dt;

	missile.move(missileVelocity);
}



void Missile::updateMissileRotation(const float& dt) {

	sf::Vector2f A(missileVelocity);
	sf::Vector2f B(targetPosition - missile.getPosition());

	float perpDotValue = PerpendicularDotProduct(A, B);

	if (perpDotValue < 0) {
		missile.rotate(-angularVelocity * dt);
	}
	else if (perpDotValue > 0) {
		missile.rotate(angularVelocity * dt);
	}
	else {
		if (DotProduct(A, B) < 0)
			missileVelocity.y *= -1;
	}


}

























float Missile::PerpendicularDotProduct(const sf::Vector2f A, const sf::Vector2f B) {
	return (A.x * B.y) - (A.y * B.x);
}

float Missile::DotProduct(const sf::Vector2f A, const sf::Vector2f B) {
	return (A.x * B.x) + (A.y * B.y);
}