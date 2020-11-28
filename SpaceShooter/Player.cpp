#include "Player.h"

Player::Player(std::string filePath, sf::Vector2f windowBoundaries) : 
		Entity(filePath, windowBoundaries, 50.f, 2.f, 50.f, 100.f){

	entitySprite.setPosition(
		(windowBoundaries.x - entitySprite.getGlobalBounds().width) / 2.f,
		windowBoundaries.y - entitySprite.getGlobalBounds().height
	);

	engine.loadFromFile("../Resources/art/Engine_exhaust/Engine_exhaust1_frames.psd");
	engineSPrite.setTexture(engine);
}


void Player::update(const float& dt) {
	updateAttack(dt);

	updateMovement(dt);

	updateProjectiles(dt);
}

void Player::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;


	if (attackTime >= 1.f)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			sf::Vector2f size(10.f, 50.f);
			sf::Vector2f position(entitySprite.getPosition().x + entitySprite.getGlobalBounds().width / 2.f - size.x / 2.f,
				entitySprite.getPosition().y);

			playerProjectiles.push_back(new Projectile(size, position, sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));

			playerProjectiles.back()->setDirection(45);



			playerProjectiles.push_back(new Projectile(size, position, sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));

			playerProjectiles.back()->setDirection(-45);



			playerProjectiles.push_back(new Projectile(size, position + sf::Vector2f(-30.f, 40), sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));

			playerProjectiles.back()->setDirection(0);



			playerProjectiles.push_back(new Projectile(size, position + sf::Vector2f(30.f, 40), sf::Color::Magenta, 2.f, sf::Color::Yellow, 200.f));

			playerProjectiles.back()->setDirection(0);





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




	if (entitySprite.getPosition().x < 150 && movement.x < 0 || entitySprite.getPosition().x > boundaries.x - 150 - entitySprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.85f;

	if (entitySprite.getPosition().x < 100 && movement.x < 0 || entitySprite.getPosition().x > boundaries.x - 100 - entitySprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.65f;

	if (entitySprite.getPosition().x < 50 && movement.x < 0 || entitySprite.getPosition().x > boundaries.x - 50 - entitySprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.45f;

	if (entitySprite.getPosition().x < 10 && movement.x < 0 || entitySprite.getPosition().x > boundaries.x - 10 - entitySprite.getGlobalBounds().width && movement.x > 0)
		movement.x *= 0.0f;


	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height - 60 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 90.f && movement.y < 0)
		movement.y *= 0.85f;

	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height - 40 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 60.f && movement.y < 0)
		movement.y *= 0.65f;


	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height - 20 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 30.f && movement.y < 0)
		movement.y *= 0.45f;

	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height - 10 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 10.f && movement.y < 0)
		movement.y *= 0.f;



	entitySprite.move(movement * dt);
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

void Player::render(sf::RenderWindow* window) {
	for (auto x : playerProjectiles)
		x->render(window);

	window->draw(entitySprite);


}


std::ostream& operator<<(std::ostream& outstream, const sf::Vector2f& vector){
	outstream << vector.x << ", " << vector.y;
	return outstream;
}