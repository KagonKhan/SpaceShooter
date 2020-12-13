#include "pch.h"
#include "Beam.h"


//CLEAN UP THE CODE 
// Need to change the principle - rn making a vector of beams. Doesnt seem good.
//as well as add proper sounds
Beam::Beam(sf::Vector2f boundaries, sf::Vector2f position) {

	initVariables(boundaries);
	initSound(position);
	initSprite(position);

}

Beam::~Beam() {

}

void Beam::loadBeamTexture() {
	AssetManager::GetTexture("BlueLaser.png", "../Resources/art/projectile/LaserTests/");
}


void Beam::initVariables(const sf::Vector2f& boundaries) {

	boundary = boundaries;
	beamColorVisibily = 10;
	beamVisibilityThreshold = 20.f;

	beamOnScreenTime = 2.f;
	beamDamageCounter = beamCounter = 0.f;
		
	beamDamage = 2000.f;

	isBeamDone = false;
}

void Beam::initSprite(sf::Vector2f position) {
	//beamSprite.setTexture(AssetManager::GetTexture("laserTest.png", "../Resources/art/projectile/LaserTests/"));
	beamSprite.setTexture(AssetManager::GetTexture("BlueLaser.png", "../Resources/art/projectile/LaserTests/"));
	initAnimation();
	

	beamSprite.setPosition(position);
	beamSprite.setOrigin(sf::Vector2f(beamSprite.getGlobalBounds().width / 2.f, beamSprite.getGlobalBounds().height ));
	beamSprite.setScale(1.5f, 2.5f);

}

void Beam::initAnimation() {
	animator = new Animator(beamSprite);

	auto& animationBeam = animator->CreateAnimation("BEAM", "../Resources/art/projectile/LaserTests/", "RedLaser.png", sf::seconds(0.5), true);
	
	//auto& animationBeam = animator->CreateAnimation("BEAM", "../Resources/art/projectile/LaserTests/", "BlueLaser.png", sf::seconds(0.73), true);
	

	animationBeam.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(128, 512), 11);

	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(512, 686), 4);
	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 1 * 686), sf::Vector2i(512, 686), 4);
	//animationBeam.AddHorizontalFrames(sf::Vector2i(0, 2 * 686), sf::Vector2i(512, 686), 4);


	animator->Update(0.1f);
}

void Beam::initSound(const sf::Vector2f& position) {
	sound.setBuffer(AssetManager::GetSoundBuffer("playerLaser.wav", "../Resources/sounds/big_laser/"));
	sound.setMinDistance(2000.f);
	sound.setPosition(position.x, position.y, 0);
	sound.setVolume(50);
	sound.setAttenuation(20.f);

	sound.play();
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
		sf::Color beamColor = beamSprite.getColor();
		beamColor.a -= beamColorVisibily;
		beamSprite.setColor(beamColor);
	}
}

void Beam::updateIsDone() {
	if (beamSprite.getColor().a < beamVisibilityThreshold)
		isBeamDone = true;

}





void Beam::render(sf::RenderWindow* window) {
	window->draw(beamSprite);
}


















void Beam::setRotation(float rotation) {
	beamSprite.setRotation(rotation);
}




void Beam::resetTimer() {
	beamDamageCounter = 0.f;
	std::cout << "RESET\t";
}


const float Beam::getDamage() {
	if (beamDamageCounter > 0.1f) {
		beamDamageCounter = 0.f;
		return beamDamage;
	}
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
	return isBeamDone;
}


