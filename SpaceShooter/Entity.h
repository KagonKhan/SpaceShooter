#pragma once

class Entity {
private:
	void initSprite(std::string filename, std::string filepath, sf::Vector2f position);
	void initVariables();


protected:
	sf::Sprite entitySprite;
	sf::Vector2f movement, boundaries;

	float movementSpeed, hp, maxHp;

public:

	Entity(std::string fileName, std::string filePath, sf::Vector2f boundaries, 
		float movementSpeed, float attackSpeed,
		float maxHp, sf::Vector2f position);
	virtual ~Entity() {};

	void setPosition(sf::Vector2f position);


	void receiveDamage(float amount);


	virtual void render(sf::RenderWindow* window) = 0;
	virtual void update(const float& dt) = 0;

	const sf::Vector2f& getPosition() const;	
	const sf::Sprite& getSprite() const;
	const float& getHp() const;


};

