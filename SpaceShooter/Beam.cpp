#include "pch.h"
#include "Beam.h"


//CLEAN UP THE CODE 
// Need to change the principle - rn making a vector of beams. Doesnt seem good.
//as well as add proper sounds
Beam::Beam(std::string spriteFilename, std::string spriteFilepath,
	std::string soundFilename, std::string soundFilepath,
	sf::Vector2f position, float speed, float damage, float rotation) :

		Ammunition(spriteFilename, spriteFilepath, soundFilename, soundFilepath, position, speed, damage, rotation)
{

	std::cout << "beam";

	initVariables();
	initSprite();
	initSound(position);


}

Beam::~Beam() {

}


void Beam::initVariables() {

	beamColorVisibily = 10;
	beamVisibilityThreshold = 20.f;

	beamOnScreenTime = 2.f;
	beamDamageCounter = beamCounter = 0.f;
		
	ammoDamage = 2000.f;

	isBeamDone = false;
}

void Beam::initSprite() {
	initAnimation();
	this->ammoSprite.setOrigin(getSize().x / 2.f, getSize().y);
	ammoSprite.setScale(1.5f, 2.5f);
}

void Beam::initAnimation() {
	animator = new Animator(ammoSprite);

	auto& animationBeam = animator->CreateAnimation("BEAM", "../Resources/art/projectile/LaserTests/", "RedLaser.png", sf::seconds(0.5), true);
	
	//auto& animationBeam = animator->CreateAnimation("BEAM", "../Resources/art/projectile/LaserTests/", "BlueLaser.png", sf::seconds(0.73), true);
	

	animationBeam.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(128, 512), 11);

	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(512, 686), 4);
	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 1 * 686), sf::Vector2i(512, 686), 4);
	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 2 * 686), sf::Vector2i(512, 686), 4);


	animator->Update(0.1f);
}

void Beam::initSound(const sf::Vector2f& position) {
	ammoSound.setMinDistance(2000.f);
	ammoSound.setPosition(position.x, position.y, 0);
	ammoSound.setVolume(50);
	ammoSound.setAttenuation(20.f);
	ammoSound.play();
}







void Beam::update(const float& dt) {

	updateCounters(dt);

	updateAnimation(dt);

	updateBeamColor();

	updateIsDone();

}

void Beam::updateCounters(const float& dt) {
	beamCounter += dt;
	beamDamageCounter += dt;
}

void Beam::updateAnimation(const float& dt) {
	animator->Update(dt);
}

void Beam::updateBeamColor() {
	if (beamCounter > beamOnScreenTime) {
		sf::Color beamColor = ammoSprite.getColor();
		beamColor.a -= beamColorVisibily;
		ammoSprite.setColor(beamColor);
	}
}

void Beam::updateIsDone() {
	if (ammoSprite.getColor().a < beamVisibilityThreshold)
		isBeamDone = true;

}




void Beam::render(sf::RenderWindow* window) {
	window->draw(ammoSprite);
}



void Beam::resetTimer() {
	beamDamageCounter = 0.f;
	std::cout << "RESET\t";
}

const float Beam::getDamage() {
	if (beamDamageCounter > 0.1f) {
		beamDamageCounter = 0.f;
		return ammoDamage;
	}
	else {
		return 0.f;

	}
}

const sf::Vector2f& Beam::getPosition() const {
	return ammoSprite.getPosition();
}

bool Beam::getIsDone() {
	return isBeamDone;
}


