#include "pch.h"

#include "Projectile.h"

// Extend the projectile constructor functionality
Projectile::Projectile(sf::Vector2f position, float speed, int directionY )
			: projectileSpeed(speed), projectileDirection(directionY) {

	initVariables();
	initSprites(position);
	initAnimations();
	initSounds();

}




void Projectile::initVariables() {
	projectileDamage = 20.f;
}

void Projectile::initSprites(sf::Vector2f position) {

	projectileSprite.setTexture(AssetManager::GetTexture("spr_bullet_strip02.png", "../Resources/art/projectile/"));
	projectileSprite.setPosition(position);
	projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getGlobalBounds().width, projectileSprite.getGlobalBounds().height) / 2.f);
	projectileSprite.setRotation(static_cast<float>(projectileDirection) * -90.f);






}

void Projectile::initAnimations() {
	animator = new Animator(projectileSprite);
	auto& animation = animator->CreateAnimation("PROJECTILE", "../Resources/art/projectile/", "spr_bullet_strip02.png", sf::seconds(0.75), false);
	animation.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(95, 68), 3);
}

void Projectile::initSounds() {
	sound.setBuffer(AssetManager::GetSoundBuffer("Laser_09.wav", "../Resources/sounds/Sci-Fi Sound Library/Sci-Fi Sound Library/Wav/Laser/"));
	sound.setVolume(25);
	//sBuffer.loadFromFile("../Resources/sounds/Sci-Fi Sound Library/Sci-Fi Sound Library/Wav/Laser/Laser_09.wav");
	//sound.setRelativeToListener(true);
	//sound.setAttenuation(1);
	//sound.setMinDistance(600);
	//sound.setPosition(400, 500, 0);
	sound.setLoop(true);
	sound.play();
}




void Projectile::update(const float& dt) {
	updateMovement(dt);
	updateAnimation(dt);

	sound.setPosition(sf::Vector3f(projectileSprite.getPosition().x, projectileSprite.getPosition().y, 0));
}

void Projectile::updateMovement(const float& dt) {

	projectileSprite.move(0,projectileDirection * projectileSpeed * dt);

	hitbox.setPosition(projectileSprite.getPosition());

	hitbox.setSize(sf::Vector2f(projectileSprite.getGlobalBounds().width, projectileSprite.getGlobalBounds().height) / 2.f);

	hitbox.setOrigin(hitbox.getSize() / 2.f);


	hitbox.setFillColor(sf::Color::Red);
	// CIRCULAR PROJECTILES
	//projectileSprite.rotate(500* cos(rand() * 10));
	/*

	//sf::Vector2f direction(sin((projectileRectangle.getRotation() * 3.1415926 / 180.f)), -cos((projectileRectangle.getRotation() * 3.1415926 / 180.f)));
//projectileRectangle.move(direction * projectileSpeed * dt);

	//SWARM PROJECTILES
	

	//if (projectileRectangle.getPosition().x >= 1890)
	//	rotate = true;

	//if(rotate)
	//	projectileRectangle.rotate(-1.f);

	//if (projectileRectangle.getRotation() > -90 || projectileRectangle.getRotation() < 270)
	//	rotate = false;

	*/
}

void Projectile::updateAnimation(const float& dt) {
	animator->Update(dt);
}


void Projectile::render(sf::RenderWindow* window) {
//	window->draw(projectileRectangle);
	window->draw(projectileSprite);
	window->draw(hitbox);
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

const sf::FloatRect Projectile::getBounds() const {
	return projectileSprite.getGlobalBounds();
}

