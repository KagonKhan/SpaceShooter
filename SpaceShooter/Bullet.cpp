#include "pch.h"
#include "Animator.h"
#include "Bullet.h"

//use simple enums or maybe have separate classes...
enum  ProjectileType {straight = 0, swarm = 1};

// Extend the projectile constructor functionality
Bullet::Bullet(std::string spriteFilename, std::string spriteFilepath,
	std::string soundFilename, std::string soundFilepath,
	sf::Vector2f position, float speed, float damage, float rotation, int type) :

	Ammunition(spriteFilename, spriteFilepath, soundFilename, soundFilepath, position, speed, damage, rotation)
{




	initAnimations();
	initSounds();

	projectileType = type;
	std::cout << " : " << position.x << ", " << position.y << std::endl;

	this->ammoSprite.setOrigin(getSize().x / 2.f, getSize().y);
	this->ammoSprite.setPosition(position);
	srand(reinterpret_cast<long>(this));
}

Bullet::~Bullet() {
	delete animator;
}

void Bullet::initAnimations() {
	animator = new Animator(ammoSprite);
	auto& animationShot = animator->CreateAnimation("PROJECTILE", "../Resources/art/projectile/", "spr_bullet_strip02.png", sf::seconds(0.75), false);
	animationShot.AddVerticalFrames(sf::Vector2i(0, 0), sf::Vector2i(68, 95), 3);

	animator->Update(0.1f);

	//Lightning
	//auto& animationLight = animator->CreateAnimation("PROJECTILE", "../Resources/art/projectile/", "light.png", sf::seconds(0.75), false);
	//animationLight.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(400, 300), 16);
}

void Bullet::initSounds() {
	ammoSound.setVolume(35);
	//sBuffer.loadFromFile("../Resources/sounds/Sci-Fi Sound Library/Sci-Fi Sound Library/Wav/Laser/Laser_09.wav");
	//sound.setRelativeToListener(true);
	//sound.setAttenuation(1);
	//sound.setMinDistance(600);
	//sound.setPosition(400, 500, 0);
	ammoSound.play();
}




void Bullet::update(const float& dt) {
	updateMovement(dt);
	updateAnimation(dt);

	ammoSound.setPosition(sf::Vector3f(ammoSprite.getPosition().x, ammoSprite.getPosition().y, 0));

}


void Bullet::updateMovement(const float& dt) {
	

	sf::Vector2f direction = getDirection();


	switch (projectileType) {

	case ProjectileType::straight:
		ammoSprite.move(-direction * ammoSpeed * dt);
		
		break;

	case ProjectileType::swarm:
		//ammoSprite.rotate(static_cast<float>(rand()%13 - 6));

		ammoSprite.move(direction * ammoSpeed * dt);
		break;

	default:
		ammoSprite.move(direction * ammoSpeed * dt);
	}
	
	

	// CIRCULAR PROJECTILES
	//projectileSprite.rotate(500* cos(rand() * 10));
	/*


	*/
}

void Bullet::updateAnimation(const float& dt) {
	animator->Update(dt);
}


void Bullet::render(sf::RenderWindow* window) {

	window->draw(ammoSprite);
}

