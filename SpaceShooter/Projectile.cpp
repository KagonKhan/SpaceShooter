#include "Projectile.h"
#include "AssetManager.h"
Projectile::Projectile(sf::Vector2f size, sf::Vector2f position, sf::Color color, float outlineThickness, sf::Color outlineColor, float speed) {

	projectileSpeed = speed;

	projectileSprite.setTexture(AssetManager::GetTexture("spr_bullet_strip02.png", "../Resources/art/projectile/"));
	projectileSprite.setPosition(position);
	projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getGlobalBounds().width, projectileSprite.getGlobalBounds().height) / 2.f);

	animator = new Animator(projectileSprite);
	auto& animation = animator->CreateAnimation("PROJECTILE", "../Resources/art/projectile/", "spr_bullet_strip02.png", sf::seconds(0.75), false);
	animation.AddFrames(sf::Vector2i(0,0),sf::Vector2i(95, 68), 3);



}


sf::Vector2f Projectile::getSize() {
	return sf::Vector2f(projectileSprite.getGlobalBounds().width, projectileSprite.getGlobalBounds().height);
}

sf::Vector2f Projectile::getPosition() {
	return projectileSprite.getPosition();
}


void Projectile::update(const float& dt) {
	move(dt);
	animator->Update(dt);
	projectileSprite.setRotation(270);


	

}

sf::FloatRect Projectile::getBounds() {
	return projectileSprite.getGlobalBounds();
}



void Projectile::move(const float& dt) {



	//not even sure why this exactly works - figure out later
	sf::Vector2f direction = sf::Vector2f(sin((projectileSprite.getRotation() * 3.1415926 / 180.f)), -cos((projectileSprite.getRotation() * 3.1415926 / 180.f)));
	projectileSprite.setRotation(direction.y);
	projectileSprite.move(0,- projectileSpeed * dt);

	/*

	//sf::Vector2f direction(sin((projectileRectangle.getRotation() * 3.1415926 / 180.f)), -cos((projectileRectangle.getRotation() * 3.1415926 / 180.f)));
//projectileRectangle.move(direction * projectileSpeed * dt);

	//SWARM PROJECTILES
	projectileRectangle.rotate(2*cos(rand() * 10));

	//if (projectileRectangle.getPosition().x >= 1890)
	//	rotate = true;

	//if(rotate)
	//	projectileRectangle.rotate(-1.f);

	//if (projectileRectangle.getRotation() > -90 || projectileRectangle.getRotation() < 270)
	//	rotate = false;

	*/
}

void Projectile::render(sf::RenderWindow* window) {
//	window->draw(projectileRectangle);
	window->draw(projectileSprite);

}
