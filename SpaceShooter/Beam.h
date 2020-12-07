#pragma once




class Beam {


	sf::RectangleShape shape;
	void initShape();

	float counter;
	int a;
	bool isDone;
	sf::Vector2f boundary;
public:
	Beam(sf::Vector2f boundaries, sf::Vector2f position);
	~Beam();

	void update(const float& dt);

	void render(sf::RenderWindow* window);


	bool getIsDone();
};

