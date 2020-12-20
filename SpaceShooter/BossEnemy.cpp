#include "pch.h"
#include "BossEnemy.h"



BossEnemy::BossEnemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position) :
	Enemy(fileName, filePath, maxhp, windowBoundaries, position) {

	entitySprite.setTexture(AssetManager::GetTexture(fileName, filePath));
	entitySprite.setScale(2.f, 2.f);



	hpBarBG.setSize(sf::Vector2f(1000.f, 50.f));
	hpBarBG.setOrigin(hpBarBG.getSize() / 2.f);
	hpBarBG.setPosition(boundaries / 2.f);
	hpBarBG.setOutlineColor(sf::Color::White);
	hpBarBG.setFillColor(sf::Color::Black);
	hpBarBG.setOutlineThickness(2.f);

	


	hpBar.setSize(sf::Vector2f(1000.f, 50.f));
	hpBar.setOrigin(hpBarBG.getSize() / 2.f);
	hpBar.setPosition(boundaries / 2.f);
	hpBar.setFillColor(sf::Color::Green);
	




	initWeapons();





	srand(static_cast<unsigned int>(reinterpret_cast<int>(this)));

	attackSpeed = 50.f;
}

BossEnemy::~BossEnemy() {

}

void BossEnemy::update(const float& dt) {

	float percentage = hp / maxHp;

	if (hpBar.getSize().x < 700.f)
		hpBar.setFillColor(sf::Color::Yellow);
	if (hpBar.getSize().x < 200.f)
		hpBar.setFillColor(sf::Color::Red);


	hpBar.setSize(sf::Vector2f(percentage * 1000.f, 50.f));
	
	
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

	}

	for (auto& x : missiles) {
		x->setTargetPosition(currentPlayerPosition);
		x->update(dt);
	}
	
	updateAttack(dt);
	updateMovement(dt);
	updateProjectiles(dt);

	updateTurretsRotation(dt);
}


void BossEnemy::initWeapons() {


	for (int i = 0; i < 5; i++) {
		weapons.push_back(Weapon("turrettest.png", "../Resources/art/projectile/turrets/", 1, 
			(entitySprite.getPosition() - sf::Vector2f((i - 2) * 100.f, (i - 2) * 100.f)), 1));
	}
}

void BossEnemy::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;

	bool attack = rand()%10 == 1;

	if (attack) {

	}
}

void BossEnemy::updateMovement(const float& dt) {

}

void BossEnemy::updateProjectiles(const float& dt) {
	for (unsigned i = 0; i < projectiles.size(); i++) {
		projectiles[i]->update(dt);


		//CLEANING UP PROJECTILES
		if (projectiles[i]->getPosition().y - projectiles[i]->getSize().y > boundaries.y || projectiles[i]->getPosition().y < 0 || projectiles[i]->getPosition().x < 0 || projectiles[i]->getPosition().x > boundaries.x) {
			delete projectiles[i];

			//CHECK IF NECESSARY i--
			projectiles.erase(projectiles.begin() + i--);
		}
	}
}

void BossEnemy::updateTurretsRotation(const float& dt) {

}

void BossEnemy::render(sf::RenderWindow* window) {
	window->draw(entitySprite);
	window->draw(hpBarBG);
	window->draw(hpBar);



	for (auto& x : projectiles)
		x->render(window);

	for (auto& x : missiles)
		x->render(window);

	for (int i = 0; i < 5; i++) {
		weapons[i].render(window);
	}
}




void BossEnemy::sendPlayerPosition(const sf::Vector2f playerPosition) {
	currentPlayerPosition = playerPosition;
}
