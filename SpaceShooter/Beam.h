#pragma once




class Beam {


	sf::RectangleShape shape;
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

	void update(const float& dt);

	void render(sf::RenderWindow* window);
	void resetTimer();
	float getDamage();
	sf::FloatRect getBounds();

	bool getIsDone();
};

