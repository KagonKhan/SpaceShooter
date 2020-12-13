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
	











}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::update(const float& dt) {
	std::cout << hpBar.getSize().x << std::endl;
	float percentage = hp / maxHp;

	if (hpBar.getSize().x < 700.f)
		hpBar.setFillColor(sf::Color::Yellow);
	if (hpBar.getSize().x < 200.f)
		hpBar.setFillColor(sf::Color::Red);


	hpBar.setSize(sf::Vector2f(percentage * 1000.f, 50.f));
	/*updateAttack(dt);
	updateMovement(dt);
	updateProjectiles(dt);*/
}

void BossEnemy::render(sf::RenderWindow* window) {
	window->draw(entitySprite);
	window->draw(hpBarBG);
	window->draw(hpBar);
}
