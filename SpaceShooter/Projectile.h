#pragma once

#include "SFML/Graphics.hpp"

class Projectile {

	sf::RectangleShape projectileRectangle;
	sf::Texture projectileTexture;
	sf::Sprite projectileSprite;

	float rotation;

	float projectileSpeed;

	void move(const float& dt);


public:

	Projectile(sf::Vector2f size, sf::Vector2f position, sf::Color color = sf::Color::White, float outlineThickness = 0.f, sf::Color outlineColor = sf::Color::Black, float speed = 200.f);
	Projectile(std::string filePath);

	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	
	void setColor(sf::Color color);
	void setDirection(float rotation);

	void render(sf::RenderWindow* window);
	void update(const float& dt);

	~Projectile() {};
};

