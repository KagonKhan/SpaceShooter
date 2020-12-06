#include "pch.h"

#include "Player.h"
#include "Animator.h"

// CTRL M O  /  CTRL M P - collapse open all
// CTRL K S WITH HIGHLIGHTED CODE - SURROUND A BLOCK OF CODE WITH

Player::Player(std::string fileName, std::string filePath, sf::Vector2f windowBoundaries, sf::Vector2f position)
	:	Entity(fileName, filePath, windowBoundaries, 80.f, 50.f, 900.f, 100.f, position){

	entitySprite.setPosition(position - sf::Vector2f(0, 50));

	initSprites();
	initAnimation();
	initListener();
	
}

Player::~Player() {
	for (auto& it : projectiles)
		delete it;
}

void Player::initSprites() {
	//Test a bit with origins 
	entitySprite.setOrigin(sf::Vector2f(entitySprite.getGlobalBounds().width, entitySprite.getGlobalBounds().height) / 2.f);

	engineSprite.setTexture(AssetManager::GetTexture("Exhaust_all.png", "../Resources/art/Engine_exhaust/Exhaust/"));

//	engineSprite.setScale(2.f, 1.5f);


	engineSprite.setOrigin(sf::Vector2f(34.f, 0.f) / 2.f); // ugly, but rn don't know a better solution
	engineSprite.setPosition(entitySprite.getPosition());
	engineSprite.move(-23.f, 32.f);






	hitbox.setFillColor(sf::Color::Red);
}

void Player::initAnimation() {

	animator = new Animator(engineSprite);


	auto& engineAnimationBACKWARD = animator->CreateAnimation("BACKWARD", "../Resources/art/Engine_exhaust/Exhaust/", "Exhaust_all.png", sf::seconds(0.25), false);
	engineAnimationBACKWARD.AddFrames(sf::Vector2i(170, 0), sf::Vector2i(34, 64), 3);


	auto& engineAnimationFORWARD = animator->CreateAnimation("FORWARD", "../Resources/art/Engine_exhaust/Exhaust/", "Exhaust_all.png", sf::seconds(0.75), false);
	engineAnimationFORWARD.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(34, 64), 5);


}

void Player::initListener() {
	//sf::Listener::setPosition(sf::Vector3f(entitySprite.getPosition().x, entitySprite.getPosition().y, 0));
	//sf::Listener::setGlobalVolume(15);

	//sf::Listener::setDirection(0, 1, -1);
}




void Player::update(const float& dt) {

	updateAttack(dt);

	updateMovement(dt);

	updateSprites(dt);

	updateProjectiles(dt);

	updateAnimations(dt);


	sf::Listener::setPosition(sf::Vector3f(entitySprite.getPosition().x, entitySprite.getPosition().y, 0));

}

void Player::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;

	if (attackTime >= 1.f)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			sf::Vector2f size(10.f, 50.f);

			//Figure out a better way to position sprites
			projectiles.push_back(new Projectile(entitySprite.getPosition() + sf::Vector2f(-15.f, 40.f), projectileSpeed, -1));

			projectiles.push_back(new Projectile(entitySprite.getPosition() + sf::Vector2f(+15.f, 40.f), projectileSpeed, -1));

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


	//Change speed variable to a vector
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= movementSpeed / 1.5f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += movementSpeed / 1.5f;




	if (entitySprite.getPosition().x < 150 && movement.x < 0 || entitySprite.getPosition().x + 150 > boundaries.x && movement.x > 0)
		movement.x *= 0.85f;

	if (entitySprite.getPosition().x < 100 && movement.x < 0 || entitySprite.getPosition().x + 100 > boundaries.x && movement.x > 0)
		movement.x *= 0.65f;

	if (entitySprite.getPosition().x < 50 && movement.x < 0 || entitySprite.getPosition().x + 50 > boundaries.x && movement.x > 0)
		movement.x *= 0.45f;

	if (entitySprite.getPosition().x < 10 && movement.x < 0 || entitySprite.getPosition().x + 10 > boundaries.x && movement.x > 0)
		movement.x *= 0.0f;



	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height - 10 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 90.f && movement.y < 0)
		movement.y *= 0.85f;

	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height + 0 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 60.f && movement.y < 0)
		movement.y *= 0.65f;

	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height + 20 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 30.f && movement.y < 0)
		movement.y *= 0.45f;

	if (entitySprite.getPosition().y > boundaries.y - entitySprite.getGlobalBounds().height + 40 && movement.y > 0 || entitySprite.getPosition().y < 2.5f * boundaries.y / 4.f + 10.f && movement.y < 0)
		movement.y *= 0.f;

}

void Player::updateSprites(const float& dt) {
	entitySprite.move(movement * dt);
	hitbox.setPosition(entitySprite.getPosition());

	engineSprite2 = engineSprite;
	engineSprite2.move(46.f, 0.f);

	engineSprite.move(movement * dt);
	engineSprite2.move(movement * dt);


}

void Player::updateProjectiles(const float& dt) {
	for (unsigned i = 0; i < projectiles.size(); i++) {
		projectiles[i]->update(dt);

		//CLEANING UP PROJECTILES
		float position = projectiles[i]->getPosition().y;
		float size = projectiles[i]->getSize().y;
		if (position + size < 0.f || position - size > boundaries.y) {
			delete projectiles[i];

			//CHECK IF NECESSARY i--
			projectiles.erase(projectiles.begin() + i--);
		}
	}
}

void Player::updateAnimations(const float& dt) {

	animator->Update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && animator->GetCurrentAnimationName() == "FORWARD")
		animator->SwitchAnimation("BACKWARD");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && animator->GetCurrentAnimationName() == "BACKWARD")
		animator->SwitchAnimation("FORWARD");
}







void Player::render(sf::RenderWindow* window) {
	for (auto x : projectiles)
		x->render(window);

	window->draw(entitySprite);


	entitySprite.setPosition(window->mapPixelToCoords( sf::Mouse::getPosition(*window)));

	window->draw(engineSprite);
	window->draw(engineSprite2);
	window->draw(hitbox);

}






std::vector<Projectile*>* Player::getProjectiles() {
	return &projectiles;
}


