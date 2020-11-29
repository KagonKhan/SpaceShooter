#include "Projectile.h"

Projectile::Projectile(sf::Vector2f size, sf::Vector2f position, sf::Color color, float outlineThickness, sf::Color outlineColor, float speed) {
	projectileRectangle.setSize(size);
	projectileRectangle.setPosition(position);
	projectileRectangle.setFillColor(color);
	projectileRectangle.setOutlineColor(outlineColor);
	projectileRectangle.setOutlineThickness(outlineThickness);
	projectileSpeed = speed;


		//projectileRectangle.move(15 * sin(rand()%2), 0);

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


//	projectileRectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));;
//	projectileRectangle.setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));;


}

sf::FloatRect Projectile::getBounds() {
	return projectileRectangle.getGlobalBounds();
}



void Projectile::move(const float& dt) {

	sf::Vector2f direction(sin((projectileRectangle.getRotation() * 3.1415926 / 180.f)), -cos((projectileRectangle.getRotation() * 3.1415926 / 180.f)));
	projectileRectangle.move(direction * projectileSpeed * dt);


	//SWARM PROJECTILES
//	projectileRectangle.rotate(2*cos(rand() * 10));

	//if (projectileRectangle.getPosition().x >= 1890)
	//	rotate = true;

	//if(rotate)
	//	projectileRectangle.rotate(-1.f);

	//if (projectileRectangle.getRotation() > -90 || projectileRectangle.getRotation() < 270)
	//	rotate = false;
}

void Projectile::render(sf::RenderWindow* window) {
	window->draw(projectileRectangle);
}
