#include "Player.h"

Player::Player(std::string filePath) {
	playerTexture.loadFromFile(filePath);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(550.f, 600.f);

	movementSpeed = 150.f;

}

void Player::updateMovement(const float& dt) {
	movement *= 0.93f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += movementSpeed;

	if (playerSprite.getPosition().x < 150 && movement.x < 0 || playerSprite.getPosition().x > 730 && movement.x > 0)
		movement *= 0.85f;

	if (playerSprite.getPosition().x < 100 && movement.x < 0 || playerSprite.getPosition().x > 780 && movement.x > 0)
		movement *= 0.65f;

	if (playerSprite.getPosition().x < 50 && movement.x < 0 || playerSprite.getPosition().x > 890 && movement.x > 0)
		movement *= 0.45f;

	if (playerSprite.getPosition().x < 20 && movement.x < 0 || playerSprite.getPosition().x > 920 && movement.x > 0)
		movement *= 0.0f;

	playerSprite.move(movement * dt);
}


void Player::update(const float& dt) {
	updateMovement(dt);

}

void Player::render(sf::RenderWindow* window) {
	window->draw(playerSprite);
}
