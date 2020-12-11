#pragma once




class Beam {


	sf::RectangleShape shape, hitbox;
	void initShape();


	int a;
	bool isDone;



	sf::Sound sound;

	int damage;
	float counter;
	float damageCounter;


	sf::Vector2f boundary;
public:
	Beam(sf::Vector2f boundaries, sf::Vector2f position);
	~Beam();


	void setRotation(float rotation);
	void update(const float& dt);

	void render(sf::RenderWindow* window);
	void resetTimer();
	const float getDamage() const ;
	const sf::FloatRect getBounds() const ;

	bool getIsDone();
};

