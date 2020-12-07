#include "pch.h"
#include "Beam.h"


Beam::Beam(sf::Vector2f boundaries, sf::Vector2f position) {
	boundary = boundaries;
	initShape();
	a = 255;
	counter = 0.f;
	isDone = false;
	shape.setPosition(position);
}

Beam::~Beam() {

}

void Beam::initShape() {

	shape.setSize(sf::Vector2f(50.f, 2.f));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);
	shape.setFillColor(sf::Color::Blue);
}

void Beam::update(const float& dt) {
	//MOVEMENT
	shape.setSize(shape.getSize() + sf::Vector2f(0, 1000.f * dt));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);

	//std::cout << -shape.getPosition().y + shape.getSize().y << std::endl;

	if (-shape.getPosition().y + shape.getSize().y > 0.f) {
		counter += dt;

	}

	if (counter > 1.f) {
		a -= 9.f;
		shape.setFillColor(sf::Color(0, 0, 255, a));

		std::cout << "YES\n";
	}

	if (shape.getFillColor().a < 50.f)
		isDone = true;
}

void Beam::render(sf::RenderWindow* window) {
	window->draw(shape);
}


bool Beam::getIsDone() {
	return isDone;
}


