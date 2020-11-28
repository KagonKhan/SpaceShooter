#include "Projectile.h"

Projectile::Projectile(sf::Vector2f size, sf::Vector2f position, sf::Color color, float outlineThickness, sf::Color outlineColor, float speed) {
	projectileRectangle.setSize(size);
	projectileRectangle.setPosition(position);
	projectileRectangle.setFillColor(color);
	projectileRectangle.setOutlineColor(outlineColor);
	projectileRectangle.setOutlineThickness(outlineThickness);
	projectileSpeed = speed;

}

Projectile::Projectile(std::string filePath) {
	projectileTexture.loadFromFile(filePath);
	projectileSprite.setTexture(projectileTexture);
	projectileSpeed = 200.f;
}

sf::Vector2f Projectile::getSize() {

	return projectileRectangle.getSize();
}

sf::Vector2f Projectile::getPosition()
{
	return projectileRectangle.getPosition();
}

void Projectile::setColor(sf::Color color) {
	projectileRectangle.setFillColor(color);
}

void Projectile::setDirection(float rotation) {
	projectileRectangle.setRotation(rotation);
}


void Projectile::update(const float& dt) {
	move(dt);
}



void Projectile::move(const float& dt) {

	sf::Vector2f direction(sin((projectileRectangle.getRotation() * 3.1415926 / 180.f)), -cos((projectileRectangle.getRotation() * 3.1415926 / 180.f)));
	projectileRectangle.move(direction * projectileSpeed * dt);

}

void Projectile::render(sf::RenderWindow* window) {
	window->draw(projectileRectangle);
}
