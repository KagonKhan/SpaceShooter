#include "Player.h"

Player::Player(std::string filePath, sf::Vector2u windowBoundaries) {
	playerTexture.loadFromFile(filePath);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition((windowBoundaries.x - playerSprite.getGlobalBounds().width) / 2.f, windowBoundaries.y - playerSprite.getGlobalBounds().height);

	boundaries = windowBoundaries;

	movementSpeed = 150.f;
	attackSpeed = 5000.f;
	attackTime = 0.f;
	projectileSpeed = 550.f;
}

void Player::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;


	if (attackTime >= 1.f)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			projectiles.push_back(new sf::RectangleShape());
			projectiles.back()->setSize(sf::Vector2f(10.f, 50.f));
			projectiles.back()->setPosition(playerSprite.getPosition());
			projectiles.back()->setFillColor(sf::Color::Magenta);
			projectiles.back()->setOutlineThickness(1.f);
			projectiles.back()->setOutlineColor(sf::Color::White);

			attackTime = 0.f;
		}
}

void Player::updateMovement(const float& dt) {
	movement *= 0.93f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += movementSpeed;

	if (playerSprite.getPosition().x < 150 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 150 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement *= 0.85f;

	if (playerSprite.getPosition().x < 100 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 100 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement *= 0.65f;

	if (playerSprite.getPosition().x < 50 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 50 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement *= 0.45f;

	if (playerSprite.getPosition().x < 20 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 20 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement *= 0.0f;

	playerSprite.move(movement * dt);
}

void Player::updateProjectiles(const float& dt) {
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles[i]->move(0, -projectileSpeed * dt);


		//CLEANING UP PROJECTILES
		if (projectiles[i]->getPosition().y + projectiles[i]->getSize().y < 0.f) {
			delete projectiles[i];

			//CHECK IF NECESSARY i--
			projectiles.erase(projectiles.begin() + i--);
		}
	}
}


void Player::update(const float& dt) {
	updateMovement(dt);
	updateAttack(dt);
	updateProjectiles(dt);
}

void Player::render(sf::RenderWindow* window) {
	window->draw(playerSprite);

	for (auto x : projectiles)
		window->draw(*x);
}
