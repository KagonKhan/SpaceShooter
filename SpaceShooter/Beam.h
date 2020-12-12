#pragma once

#include "Animator.h"


class Beam {


	sf::RectangleShape shape;
	sf::Sound sound;
	sf::Vector2f boundary;
	sf::Sprite beamSprite;

	Animator* animator;



	int beamColorVisibily, beamVisibilityThreshold;
	int beamDamage;

	float beamCounter, beamOnScreenTime, beamDamageCounter;
	
	bool isBeamDone;


	

	void initVariables(const sf::Vector2f& boundaries);
	void initSprite(sf::Vector2f position);
	void initAnimation();
	void initSound(const sf::Vector2f& position);


	void updateCounters(const float& dt);
	void updateAnimation(const float& dt);
	void updateBeamColor();
	void updateIsDone();



public:
	Beam(sf::Vector2f boundaries, sf::Vector2f position);
	~Beam();

	void update(const float& dt);
	void render(sf::RenderWindow* window);

	void setRotation(float rotation);


	

	const int getDamage() const ;
	const sf::FloatRect getBounds() const ;
	const sf::Sprite& getBeamSprite() const ;
	bool getIsDone();

	void resetTimer();

	static void loadBeamTexture();

};

