#include "pch.h"
#include "Beam.h"

//CLEAN UP THE CODE 
// Need to change the principle - rn making a vector of beams. Doesnt seem good.
//as well as add proper sounds
Beam::Beam(sf::Vector2f boundaries, sf::Vector2f position) {

	sound.setBuffer(AssetManager::GetSoundBuffer("playerLaser.wav", "../Resources/sounds/big_laser/"));
	sound.setPosition(position.x, position.y, 0);
	sound.setVolume(50);
	sound.setAttenuation(20.f);
	
	sound.play();


	boundary = boundaries;
	initShape();
	a = 255;
	counter = 0.f;
	isDone = false;
	shape.setPosition(position);

	damage = 110.f;
	damageCounter = 0.f;



	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setPosition(position);
	hitbox.setFillColor(sf::Color::Red);
	hitbox.setSize(shape.getSize());

}

Beam::~Beam() {

}

void Beam::initShape() {

	shape.setSize(sf::Vector2f(50.f, 2.f));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);
	shape.setFillColor(sf::Color::Blue);
}

void Beam::setRotation(float rotation) {
	shape.setRotation(rotation);
	hitbox.setRotation(rotation);
}

void Beam::update(const float& dt) {
	//MOVEMENT
	shape.setSize(shape.getSize() + sf::Vector2f(0, 1400.f * dt));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);

	hitbox.setSize(sf::Vector2f(shape.getGlobalBounds().width, shape.getGlobalBounds().height));
	hitbox.setOrigin(hitbox.getSize() / 2.f);


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
	//window->draw(hitbox);
}

void Beam::resetTimer() {
	damageCounter = 0.f;
}


const float Beam::getDamage() const {
	if (damageCounter > 1.f)
		return damage;
	else
		return 0.f;
}

const sf::FloatRect Beam::getBounds() const {
	return shape.getGlobalBounds();
}

bool Beam::getIsDone() {
	return isDone;
}


