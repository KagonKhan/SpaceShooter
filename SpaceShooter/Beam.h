#pragma once




class Beam {


	sf::RectangleShape shape, hitbox;
	sf::Sound sound;
	sf::Vector2f boundary;


	int colorVisibily, damage;
	bool isDone;
	float counter, damageCounter;



	void initVariables(const sf::Vector2f& boundaries);
	void initSprite();
	void initShape(const sf::Vector2f& position);
	void initHitbox(const sf::Vector2f& position);
	void initAnimation();
	void initSound(const sf::Vector2f& position);





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

