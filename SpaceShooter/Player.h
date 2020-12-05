#pragma once
#include "Entity.h"
#include "Animator.h"

class Player : public Entity {

	//Would be nice  to find an alternative
	sf::Sprite engineSprite, engineSprite2;

	Animator* animator;


	std::vector<Projectile*> projectiles;


	void initSprites();
	void initAnimation();
	void initListener();




	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);
	void updateAnimations(const float& dt);
	void updateSprites(const float& dt);




public:
	Player(std::string fileName, std::string filePath, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~Player();


	void update(const float& dt);
	
	void render(sf::RenderWindow* window);
	
	
	std::vector<Projectile*>* getProjectiles();

};

