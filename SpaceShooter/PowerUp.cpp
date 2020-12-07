#include "pch.h"
#include "PowerUp.h"


PowerUp::PowerUp(sf::Vector2f boundary,int type) {
	boundaries = boundary;
	this->type = type;


	initSprites();
}

PowerUp::~PowerUp() {

}

void PowerUp::initSprites() {
	srand(reinterpret_cast<long>(this));

	powerUpRect.setSize(sf::Vector2f(75, 75));
	powerUpRect.setPosition(sf::Vector2f(rand() % static_cast<int>(boundaries.x - 100) + 100, -100.f));
	powerUpRect.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));

}


void PowerUp::update(const float& dt) {
	powerUpRect.move(sf::Vector2f(0, 5.f));

	powerUpRect.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));

}

void PowerUp::render(sf::RenderWindow* window) {
	window->draw(powerUpRect);
}






sf::FloatRect PowerUp::getBounds() {
	return powerUpRect.getGlobalBounds();
}

int PowerUp::getUpgradeType() {
	return type;
}
