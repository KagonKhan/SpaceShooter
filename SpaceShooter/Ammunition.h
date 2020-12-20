#pragma once
#include "Animator.h"
class Ammunition {

	void initSprites(std::string filename, std::string filepath, sf::Vector2f position);
	void initSounds(std::string filename, std::string filepath, sf::Vector2f position);
	void initVariables(float speed, float damage, float rotation);


	sf::Vector2f size, position, direction;




protected:
	sf::Sprite ammoSprite;

	float ammoDamage, ammoSpeed, ammoRotation;

	sf::Sound ammoSound;

	//Return direction based on sprite rotation
	const sf::Vector2f& getDirection() const;

public:

	Ammunition(std::string spriteFilename, std::string spriteFilepath,
		std::string soundFilename, std::string soundFilepath,
		sf::Vector2f position, float speed, float damage, float rotation);

	~Ammunition();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderWindow* window) = 0;

	const sf::Sprite& getSprite() const;
	virtual const float& getDamage() const;
	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getSize() const;

	void setRotation(float rotation);
};

