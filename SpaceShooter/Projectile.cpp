#include "pch.h"

#include "Projectile.h"

//use simple enums or maybe have separate classes...
enum  ProjectileType {straight = 0, swarm = 1};

// Extend the projectile constructor functionality
Projectile::Projectile(sf::Vector2f position, float speed, int directionY, int type)
	: projectileSpeed(speed), projectileDirection(directionY) {

	initVariables();
	initSprites(position);
	initAnimations();
	initSounds();


	projectileType = type;

	srand(reinterpret_cast<long>(this));
}




void Projectile::initVariables() {
	projectileDamage = 20.f;
}

void Projectile::initSprites(sf::Vector2f position) {


	//Light attack - seems to difficult for now 
	projectileSprite.setTexture(AssetManager::GetTexture("spr_bullet_strip02.png", "../Resources/art/projectile/"));
	projectileSprite.setPosition(position);
	projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getGlobalBounds().width, projectileSprite.getGlobalBounds().height) / 2.f);

	
}

void Projectile::initAnimations() {
	animator = new Animator(projectileSprite);
	auto& animationShot = animator->CreateAnimation("PROJECTILE", "../Resources/art/projectile/", "spr_bullet_strip02.png", sf::seconds(0.75), false);
	animationShot.AddVerticalFrames(sf::Vector2i(0, 0), sf::Vector2i(68, 95), 3);

	animator->Update(0.1f);

	//Lightning
	//auto& animationLight = animator->CreateAnimation("PROJECTILE", "../Resources/art/projectile/", "light.png", sf::seconds(0.75), false);
	//animationLight.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(400, 300), 16);
}

void Projectile::initSounds() {
	sound.setBuffer(AssetManager::GetSoundBuffer("Laser_09.wav", "../Resources/sounds/Sci-Fi Sound Library/Sci-Fi Sound Library/Wav/Laser/"));
	sound.setVolume(55);
	//sBuffer.loadFromFile("../Resources/sounds/Sci-Fi Sound Library/Sci-Fi Sound Library/Wav/Laser/Laser_09.wav");
	//sound.setRelativeToListener(true);
	//sound.setAttenuation(1);
	//sound.setMinDistance(600);
	//sound.setPosition(400, 500, 0);
	sound.play();
}




void Projectile::update(const float& dt) {
	updateMovement(dt);
	updateAnimation(dt);

	sound.setPosition(sf::Vector3f(projectileSprite.getPosition().x, projectileSprite.getPosition().y, 0));


}

void Projectile::updateMovement(const float& dt) {
	

	sf::Vector2f direction;


	switch (projectileType) {

	case ProjectileType::straight:
		direction = sf::Vector2f(sinf((projectileSprite.getRotation() * 3.1415926f / 180.f)), -cosf((projectileSprite.getRotation() * 3.1415926f / 180.f)));
		projectileSprite.move(-direction * static_cast<float>(projectileDirection) * projectileSpeed * dt);
		
		break;

	case ProjectileType::swarm:
			projectileSprite.rotate(static_cast<float>(rand()%13 - 6));
			direction = sf::Vector2f(sinf((projectileSprite.getRotation() * 3.1415926f / 180.f)), -cosf((projectileSprite.getRotation() * 3.1415926f / 180.f)));
			projectileSprite.move( direction* projectileSpeed * dt);
		break;

	default:
		projectileSprite.move(0.f, static_cast<float>(projectileDirection) * projectileSpeed * dt);
	}
	
	

	// CIRCULAR PROJECTILES
	//projectileSprite.rotate(500* cos(rand() * 10));
	/*


	*/
}

void Projectile::updateAnimation(const float& dt) {
	animator->Update(dt);
}


void Projectile::render(sf::RenderWindow* window) {

//	window->draw(projectileRectangle);


	window->draw(projectileSprite);
}







const sf::Vector2f Projectile::getSize() const {
	return sf::Vector2f(projectileSprite.getGlobalBounds().width, projectileSprite.getGlobalBounds().height);
}

const sf::Vector2f Projectile::getPosition() const {
	return projectileSprite.getPosition();
}

const float Projectile::getDamage() const {
	return projectileDamage;
}

const sf::Sprite& Projectile::getSprite() const {
	return projectileSprite;
}

void Projectile::setRotation(float rotation) {
	projectileSprite.setRotation(rotation);
}



const sf::FloatRect Projectile::getBounds() const {
	return projectileSprite.getGlobalBounds();
}

