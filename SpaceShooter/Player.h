#pragma once
#include "Entity.h"
#include "Animator.h"
#include "Beam.h"

class Player : public Entity {

	//Would be nice  to find an alternative
	sf::Sprite engineSprite, engineSprite2;

	Animator* animator;

	float velocity;

	std::vector<Projectile*> projectiles;

	//No point in having this as a vector - only 1 beam allowed at a time.
	//or maybe can upgrade to multiple beams
	std::vector<Beam*> beams;

	bool blockAttack, blockMovement, beamStartCooldown;
	float beamCooldownTimer;



	// I don't like this - find better solutions later
	int projectileType;

	void initSprites();
	void initAnimation();
	void initListener();




	void updateAttack(const float& dt);
	void updateMovement(const float& dt);
	void updateProjectiles(const float& dt);
	void updateAnimations(const float& dt);
	void updateSprites(const float& dt);

	void renderPlayer(sf::RenderWindow* window);
	void renderPlayerAttacks(sf::RenderWindow* window);


public:
	Player(std::string fileName, std::string filePath, sf::Vector2f windowBoundaries, sf::Vector2f position);
	~Player();

	void update(const float& dt);	
	void render(sf::RenderWindow* window);
	
	void receiveUpgrade(int type);
	
	const sf::Vector2f getPosition() const ;

	std::vector<Projectile*>* getProjectiles();
	std::vector<Beam*>* getBeams();

	const sf::Sprite& getBeamSprite() const ;

};

