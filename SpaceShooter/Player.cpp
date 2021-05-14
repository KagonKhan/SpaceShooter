#include "pch.h"
#include "Player.h"


// CTRL M O  /  CTRL M P - collapse open all
// CTRL K S WITH HIGHLIGHTED CODE - SURROUND A BLOCK OF CODE WITH

Player::Player(std::string fileName, std::string filePath, sf::Vector2f windowBoundaries, sf::Vector2f position)
	:	Entity(fileName, filePath, windowBoundaries, 80.f, 50.f, 100.f, position) {

	entitySprite.setPosition(position - sf::Vector2f(0, 50));

	initVariables();
	initSprites();
	initAnimation();
	initListener();
	initWeapons();


}

Player::~Player() {

}



void Player::initVariables() {

	velocity = 0.93f;

	blockMovement = blockAttack = false;
	beamStartCooldown = false;
	beamCooldownTimer = 50.f;

}

void Player::initSprites() {

	engineSprite.setTexture(AssetManager::GetTexture("Exhaust_all.png", "../Resources/art/Engine_exhaust/Exhaust/"));

//	engineSprite.setScale(2.f, 1.5f);


	engineSprite.setOrigin(sf::Vector2f(34.f, 0.f) / 2.f); // ugly, but rn don't know a better solution
	engineSprite.setPosition(entitySprite.getPosition());
	engineSprite.move(-23.f, 32.f);

}

void Player::initAnimation() {

	animator = new Animator(engineSprite);


	auto& engineAnimationBACKWARD = animator->CreateAnimation("BACKWARD", "../Resources/art/Engine_exhaust/Exhaust/", "Exhaust_all.png", sf::seconds(0.55f), false);
	engineAnimationBACKWARD.AddHorizontalFrames(sf::Vector2i(170, 0), sf::Vector2i(34, 64), 3);


	auto& engineAnimationFORWARD = animator->CreateAnimation("FORWARD", "../Resources/art/Engine_exhaust/Exhaust/", "Exhaust_all.png", sf::seconds(0.75f), false);
	engineAnimationFORWARD.AddHorizontalFrames(sf::Vector2i(0, 0), sf::Vector2i(34, 64), 5);

	animator->Update(0.0f);
}

void Player::initListener() {
	//sf::Listener::setPosition(sf::Vector3f(entitySprite.getPosition().x, entitySprite.getPosition().y, 0));
	//sf::Listener::setGlobalVolume(15);

	//sf::Listener::setDirection(0, 1, -1);
}

void Player::initWeapons() {

	bulletWeapons.push_back(Weapon("turrettest.png", "../Resources/art/projectile/turrets/", 1, entitySprite.getPosition(), 1));
	bulletWeapons.push_back(Weapon("turrettest.png", "../Resources/art/projectile/turrets/", 1, entitySprite.getPosition(), 1));
	bulletWeapons[0].scaleSprite(2, 2);
	bulletWeapons[1].scaleSprite(2, 2);

	beamWeapon = Weapon("Cannon3.png", "../Resources/art/projectile/turrets/towers/PNG/", 3, entitySprite.getPosition() , 1);
	
	beamWeapon.scaleSprite(0.2f, 0.5f);

}




void Player::update(const float& dt) {

	updateAttack(dt);

	updateMovement(dt);

	updateSprites(dt);

	updateAmmunition(dt);

	updateAnimations(dt);

	updateWeapons(dt);

	sf::Listener::setPosition(sf::Vector3f(entitySprite.getPosition().x, entitySprite.getPosition().y, 0));

}

void Player::updateAttack(const float& dt) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
		projectileType = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
		projectileType = 2;

	if (!blockAttack) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			for (unsigned int i = 0; i < bulletWeapons.size(); i++) {
				if (bulletWeapons[i].isWeaponReadyToShoot()) {
					Ammunition* temp = bulletWeapons[i].shoot();
					bullets.push_back(temp);
				}
			}


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && beamCooldownTimer > 0.f) {

			beam = dynamic_cast<Beam*>(beamWeapon.shoot());
			beamCooldownTimer = 0.f;
			blockAttack = true;
			blockMovement = true;

		}

	}
}

void Player::updateWeapons(const float& dt) {
	for (unsigned int i = 0; i < bulletWeapons.size(); i++)
		bulletWeapons[i].update(dt);

	if(beam)
		beamWeapon.update(dt);
}

void Player::updateMovement(const float& dt) {
	movement *= velocity;

	//Normalize movement/?

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += movementSpeed;


	//Change speed variable to a vector
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= movementSpeed / 1.5f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += movementSpeed / 1.5f;


#pragma region Movement

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

#pragma endregion
}

void Player::updateSprites(const float& dt) {
	if (!blockMovement) {
		entitySprite.move(movement * dt);



		// TODO most likely bad solution, unoptimized
		engineSprite2 = engineSprite;
		engineSprite2.move(46.f, 0.f);

		engineSprite.move(movement * dt);
		engineSprite2.move(movement * dt);

		// TODO make this more intuitive - remembering how much tio shift sucks
		bulletWeapons[0].setPosition(entitySprite.getPosition() + sf::Vector2f(50,0));
		bulletWeapons[1].setPosition(entitySprite.getPosition() + sf::Vector2f(-50, 0));

		beamWeapon.setPosition(entitySprite.getPosition());
	}
}

void Player::updateAmmunition(const float& dt) {

	for (unsigned i = 0; i < bullets.size(); i++) {
		bullets[i]->update(dt);


		sf::Vector2f position = bullets[i]->getPosition();
		float size = bullets[i]->getSize().y;

		if (position.y + size < 0.f || position.y - size > boundaries.y || position.x < 0 || position.x > boundaries.x) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}

	if (beamStartCooldown)
		beamCooldownTimer += dt;

	if (beam) {
		beam->update(dt);

		if (beam->getIsDone()) {
			beamStartCooldown = true;
			delete beam;
			beam = nullptr;
			blockAttack = blockMovement = false;
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
	renderPlayerAttacks(window);
	renderPlayer(window);
}

void Player::renderPlayerAttacks(sf::RenderWindow* window) {
	for (auto x : bullets)
		x->render(window);

	if (beam)
		beam->render(window);
}

void Player::renderPlayer(sf::RenderWindow* window) {

	if (beam) {
		
	}


	window->draw(engineSprite);
	window->draw(engineSprite2);
	window->draw(entitySprite);
	window->draw(beamWeapon.getSprite());

	for (const auto& x : bulletWeapons)
		window->draw(x.getSprite());
}



