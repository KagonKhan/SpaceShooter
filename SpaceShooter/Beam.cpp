#include "pch.h"
#include "Beam.h"


//CLEAN UP THE CODE 
// Need to change the principle - rn making a vector of beams. Doesnt seem good.
//as well as add proper sounds
Beam::Beam(sf::Vector2f boundaries, sf::Vector2f position) {


	initVariables(boundaries);
	initSound(position);
	initShape(position);
	initSprite(position);
	initHitbox(position);
//	initAnimation();
}

Beam::~Beam() {

}

void Beam::initVariables(const sf::Vector2f& boundaries) {

	boundary = boundaries;
	colorVisibily = 255;
	counter = 0.f;
	damage = 20;
	damageCounter = 0.f;

	isDone = false;

}


void Beam::initShape(const sf::Vector2f& position) {

	shape.setSize(sf::Vector2f(50.f, 2.f));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(position);

}

void Beam::initHitbox(const sf::Vector2f& position) {

	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setPosition(position);
	hitbox.setFillColor(sf::Color::Red);

	hitbox.setSize(sf::Vector2f(beamSprite.getGlobalBounds().width * 0.75f, beamSprite.getGlobalBounds().height));



}

void Beam::initSprite(sf::Vector2f position) {
	//beamSprite.setTexture(AssetManager::GetTexture("laserTest.png", "../Resources/art/projectile/LaserTests/"));
	beamSprite.setTexture(AssetManager::GetTexture("RedLaser.png", "../Resources/art/projectile/LaserTests/"));
	initAnimation();
	
	

	beamSprite.setPosition(position - sf::Vector2f(7.5f, -50.f));
	beamSprite.setOrigin(sf::Vector2f(beamSprite.getGlobalBounds().width / 2.f, beamSprite.getGlobalBounds().height ));
	beamSprite.setScale(2.f, 3.f);



}


void Beam::initAnimation() {
	animator = new Animator(beamSprite);
	//auto& animationBeam = animator->CreateAnimation("BEAM", "../Resources/art/projectile/LaserTests/", "laserTest.png", sf::seconds(2.75), true);
	auto& animationBeam = animator->CreateAnimation("BEAM", "../Resources/art/projectile/LaserTests/", "RedLaser.png", sf::seconds(3.3), true);
	
	
	
	
	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(63, 198), 2);
	animationBeam.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(128, 512), 11);
	
	
	
	
	
	
	
	animator->Update(0.1f);

}

void Beam::initSound(const sf::Vector2f& position) {
	sound.setBuffer(AssetManager::GetSoundBuffer("playerLaser.wav", "../Resources/sounds/big_laser/"));
	sound.setPosition(position.x, position.y, 0);
	sound.setVolume(50);
	sound.setAttenuation(20.f);

	sound.play();
}



void Beam::update(const float& dt) {
	////MOVEMENT
	//shape.setSize(shape.getSize() + sf::Vector2f(0, 1400.f * dt));
	//shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y);
	//

	//std::cout << -shape.getPosition().y + shape.getSize().y << std::endl;

	if (-shape.getPosition().y + shape.getSize().y > 0.f) {
		counter += dt;

	}

	if (counter > 1.f) {
		colorVisibily -= 9;
		sf::Color beamColor = beamSprite.getColor();
		beamColor.a -= 9;
		beamSprite.setColor(beamColor);
	}

	if (beamSprite.getColor().a < 50.f)
		isDone = true;


	counter += dt;
	damageCounter += dt;
}

void Beam::render(sf::RenderWindow* window) {
	//window->draw(shape);
	window->draw(beamSprite);
	window->draw(hitbox);
}


















void Beam::setRotation(float rotation) {
	//beamSprite.setRotation(rotation);
	//hitbox.setRotation(rotation);
}




void Beam::resetTimer() {
	damageCounter = 0.f;
}


const int Beam::getDamage() const {
	if (damageCounter > 1.f)
		return damage;
	else
		return 0.f;
}

const sf::FloatRect Beam::getBounds() const {
	return beamSprite.getGlobalBounds();
}

const sf::Sprite& Beam::getBeamSprite() const {
	return beamSprite;
}

bool Beam::getIsDone() {
	return isDone;
}


