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
	





	for (int i = 0; i < 5; i++) {
		turretSprites.push_back(sf::Sprite());
		turretSprites.back().setTexture(AssetManager::GetTexture("turrettest.png", "../Resources/art/projectile/turrets/"));
		turretSprites.back().setOrigin(turretSprites.back().getGlobalBounds().width / 2.f, turretSprites.back().getGlobalBounds().height / 2.f);
		turretSprites.back().setPosition(entitySprite.getPosition() - sf::Vector2f((i - 2) * 100.f, (i - 2) * 100.f));
		turretSprites.back().setScale(2.f, 2.f);

	
	}









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
	
	
	
	
	updateAttack(dt);
	updateMovement(dt);
	updateProjectiles(dt);

	updateTurretsRotation(dt);
}


void BossEnemy::updateAttack(const float& dt) {
	attackTime += attackSpeed * dt;

	bool attack = rand()%10 == 1;

	if (attack) {
		for (int i = 0; i < 4; i++) {
			if (attackTime >= 1.f) {
				sf::Vector2f position(turretSprites[i].getPosition());

				projectiles.push_back(new Projectile(position - sf::Vector2f(20.f, -20.f), 500.f, 1));
				projectiles.back()->setRotation(turretSprites[i].getRotation());
				projectiles.push_back(new Projectile(position + sf::Vector2f(20.f, 20.f), 500.f, 1));
				projectiles.back()->setRotation(turretSprites[i].getRotation());

			}
		}
		attackTime = 0.f;
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


	for (int i = 0; i < 5; i++) {
		float x = turretSprites[i].getPosition().x - currentPlayerPosition.x  ;
		float y = turretSprites[i].getPosition().y - currentPlayerPosition.y  ;

		float alpha = 0.f;
	
			alpha = atan2f(y, x);


		alpha *= 180 / 3.14159;

		turretSprites[i].setRotation(alpha + 90.f);
	}
}

void BossEnemy::render(sf::RenderWindow* window) {
	window->draw(entitySprite);
	window->draw(hpBarBG);
	window->draw(hpBar);



	for (auto& x : projectiles)
		x->render(window);


	for (int i = 0; i < 5; i++) {
		window->draw(turretSprites[i]);
	}
}




void BossEnemy::sendPlayerPosition(const sf::Vector2f playerPosition) {
	currentPlayerPosition = playerPosition;
}
