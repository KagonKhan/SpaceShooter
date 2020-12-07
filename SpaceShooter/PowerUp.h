#pragma once


//Use something else than enums? Don't have other ideas for powerups for now - Having different classes for each upgrade seems inefficient
enum powerUpType { AttackSpeedUp = 0, HealthUp = 1, SpeedUp = 2, ProjectileType = 3 };

class PowerUp {
	int type;


	sf::Vector2f boundaries;
	sf::RectangleShape powerUpRect;

	void initSprites();



public:


	PowerUp(sf::Vector2f boundary, int type);
	~PowerUp();


	void update(const float& dt);
	void render(sf::RenderWindow* window);

	sf::FloatRect getBounds();
	int getUpgradeType();

};

