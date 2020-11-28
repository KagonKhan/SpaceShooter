#include "Player.h"

Player::Player(std::string filePath, sf::Vector2u windowBoundaries) {
	playerTexture.loadFromFile(filePath);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition((windowBoundaries.x - playerSprite.getGlobalBounds().width) / 2.f, windowBoundaries.y - playerSprite.getGlobalBounds().height);


	sf::Keyboard::setVirtualKeyboardVisible(true);

	boundaries = windowBoundaries;

	movementSpeed = 50.f;
	attackSpeed = 5555.f; // aps
	attackTime = 0.f;
	projectileSpeed = 350.f;
}

void Player::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;


	if (attackTime >= 1.f)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			sf::Vector2f size(10.f, 50.f);
			sf::Vector2f position(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width / 2.f - size.x / 2.f,
				playerSprite.getPosition().y);

			playerProjectiles.push_back(new Projectile(size, position, sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));

			playerProjectiles.back()->setDirection(45);

			attackTime = 0.f;
		}
}

void Player::updateMovement(const float& dt) {
	movement *= 0.93f;

	//Normalize movement/????

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += movementSpeed;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += movementSpeed;


	//Change speed variable to a vector
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= movementSpeed / 1.5f; 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += movementSpeed / 1.5f;




	if (playerSprite.getPosition().x < 150 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 150 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.85f;

	if (playerSprite.getPosition().x < 100 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 100 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.65f;

	if (playerSprite.getPosition().x < 50 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 50 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.45f;

	if (playerSprite.getPosition().x < 10 && movement.x < 0 || playerSprite.getPosition().x > boundaries.x - 10 - playerSprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.0f;

	
	if (playerSprite.getPosition().y > boundaries.y - playerSprite.getGlobalBounds().height - 60 && movement.y > 0 || playerSprite.getPosition().y < 2.5f * boundaries.y / 4.f + 90.f && movement.y < 0)
		movement.y *= 0.85f;

	if (playerSprite.getPosition().y > boundaries.y - playerSprite.getGlobalBounds().height - 40 && movement.y > 0 || playerSprite.getPosition().y < 2.5f * boundaries.y / 4.f + 60.f && movement.y < 0)
		movement.y *= 0.65f;


	if (playerSprite.getPosition().y > boundaries.y - playerSprite.getGlobalBounds().height - 20 && movement.y > 0 || playerSprite.getPosition().y < 2.5f * boundaries.y / 4.f + 30.f && movement.y < 0)
		movement.y *= 0.45f;

	if (playerSprite.getPosition().y > boundaries.y - playerSprite.getGlobalBounds().height - 10 && movement.y > 0 || playerSprite.getPosition().y < 2.5f * boundaries.y / 4.f + 10.f && movement.y < 0)
		movement.y *= 0.f;



	playerSprite.move(movement * dt);
}

void Player::updateProjectiles(const float& dt) {
	for (unsigned i = 0; i < playerProjectiles.size(); i++) {
		playerProjectiles[i]->update(dt);


		//CLEANING UP PROJECTILES
		if (playerProjectiles[i]->getPosition().y + playerProjectiles[i]->getSize().y < 0.f) {
			delete playerProjectiles[i];

			//CHECK IF NECESSARY i--
			playerProjectiles.erase(playerProjectiles.begin() + i--);
		}
	}
}


void Player::update(const float& dt) {
	updateMovement(dt);
	updateAttack(dt);
	updateProjectiles(dt);
}

void Player::render(sf::RenderWindow* window) {
	for (auto x : playerProjectiles)
		x->render(window);

	window->draw(playerSprite);


}










std::ostream& operator<<(std::ostream& outstream, const sf::Vector2f& vector){
	outstream << vector.x << ", " << vector.y;
	return outstream;
}