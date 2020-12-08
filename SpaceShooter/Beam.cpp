#include "pch.h"
#include "Beam.h"


Beam::Beam(sf::Vector2f boundaries, sf::Vector2f position) {
	boundary = boundaries;
	initShape();
	a = 255;
	counter = 0.f;
	isDone = false;
	shape.setPosition(position);

	damage = 110.f;
	damageCounter = 0.f;


	sound.setBuffer(AssetManager::GetSoundBuffer("playerLaser.wav", "../Resources/sounds/big_laser/"));
	sound.setVolume(25);
	sound.play();
	sound.setPosition(position.x,position.y, 0);


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
	shape.setSize(shape.getSize() + sf::Vector2f(0, 1400.f * dt));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);

	//std::cout << -shape.getPosition().y + shape.getSize().y << std::endl;

	if (-shape.getPosition().y + shape.getSize().y > 0.f) {
		counter += dt;

	}

	if (counter > 1.f) {
		a -= 9.f;
		shape.setFillColor(sf::Color(0, 0, 255, a));
	}

	if (shape.getFillColor().a < 50.f)
		isDone = true;


	counter += dt;
	damageCounter += dt;
}

void Beam::render(sf::RenderWindow* window) {
	window->draw(shape);
}

void Beam::resetTimer() {
	damageCounter = 0.f;
}


float Beam::getDamage() {
	if (damageCounter > 1.f)
		return damage;
	else
		return 0.f;
}

sf::FloatRect Beam::getBounds() {
	return shape.getGlobalBounds();
}

bool Beam::getIsDone() {
	return isDone;
}


