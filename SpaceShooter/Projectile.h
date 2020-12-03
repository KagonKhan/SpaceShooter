#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Animator.h"
#include "AssetManager.h"

class Projectile {

	sf::Sprite projectileSprite;

	float rotation;
	float projectileSpeed;

	void move(const float& dt);


	sf::Sound sound;


	Animator* animator;



	float i = 0;
	bool rotate = false;

public:

	Projectile(sf::Vector2f size, sf::Vector2f position, sf::Color color = sf::Color::White, float outlineThickness = 0.f, sf::Color outlineColor = sf::Color::Black, float speed = 200.f);

	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	

	void render(sf::RenderWindow* window);
	void update(const float& dt);
	sf::FloatRect getBounds();

	~Projectile() {};
};

