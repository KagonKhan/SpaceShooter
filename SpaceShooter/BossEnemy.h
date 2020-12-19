#pragma once
#include "Enemy.h"
class BossEnemy : public Enemy {

	sf::RectangleShape hpBar, hpBarBG;
	sf::Vector2f currentPlayerPosition;

	void updateTurretsRotation(const float& dt);






	std::vector<sf::Sprite> turretSprites;




	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);



public:
	BossEnemy(std::string fileName, std::string filePath, float maxhp, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~BossEnemy();


	// enemy needs to know the player's position to allow aiming - might need to researc hbetter ideas
	void sendPlayerPosition(const sf::Vector2f playerPosition);
	
	
	void update(const float& dt);
	void render(sf::RenderWindow* window);
};

