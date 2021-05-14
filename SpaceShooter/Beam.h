#pragma once

#include "Ammunition.h"

class Beam : public Ammunition {

	sf::Vector2f boundary;

	Animator* animator;


	int beamColorVisibily, beamVisibilityThreshold;

	float beamCounter, beamOnScreenTime, beamDamageCounter;
	
	bool isBeamDone;


	

	void initVariables();
	void initSprite();
	void initAnimation();
	void initSound(const sf::Vector2f& position);


	void updateCounters(const float& dt);
	void updateAnimation(const float& dt);
	void updateBeamColor();
	void updateIsDone();



public:
	Beam(std::string spriteFilename, std::string spriteFilepath,
		std::string soundFilename, std::string soundFilepath,
		sf::Vector2f position, float speed, float damage, float rotation);
	~Beam();

	void update(const float& dt);
	void render(sf::RenderWindow* window);
	

	const float getDamage();
	const sf::Vector2f& getPosition() const;



	bool getIsDone();

	void resetTimer();


};

