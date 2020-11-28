#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {
	initBackground();

	initPlayer();
	initEnemies();

	nebulisIndex = 0;
}

void GameState::initBackground() {
	std::string starsPath = "../Resources/art/Stars-Nebulae/Stars.png";
	std::string nebulis = "../Resources/art/Stars-Nebulae/Nebula";

	for (int i = 0; i < 2; i++) {
		nebulaeTextures[i].loadFromFile(nebulis + std::to_string(i + 1) + ".png");
		nebulaeSprites[i].setTexture(nebulaeTextures[i]);
		nebulaeSprites[i].setPosition(0, -700);
	}


	backgroundTexture.loadFromFile(starsPath);
	backgroundTexture.setRepeated(true);

	backgroundSprite.setTexture(backgroundTexture);
	backgroundSpriteV2.setTexture(backgroundTexture);

	
	
	// LEARN ABOUT VIEWS


	backgroundSprite.setTextureRect({ 0, 0, 2000, 1024});
	backgroundSpriteV2.setTextureRect({ 0, 0, 2000, 1024});
	backgroundSpriteV2.setPosition(0, -1 * window->getSize().y);
	backgroundSpriteV2.setColor(sf::Color::White);
}

void GameState::initPlayer() {
	player = new Player("../Resources/art/Example_ships/13B.png", (sf::Vector2f)window->getSize());
}

void GameState::initEnemies() {
	for (int i = 0; i < 64; i++) {
		enemies.push_back(new Enemy("../Resources/art/Alien-Ships/Alien-Scout.png", 100, (sf::Vector2f)window->getSize()));
		enemies[i]->setPosition(sf::Vector2f(120 * (i % 16), 100 * ( i / 16)));
	}
}

void GameState::spawnNebulis() {
	srand(time(NULL));
	nebulisIndex = rand() % 3;

	nebulaeSprites[nebulisIndex].setScale(rand() % 10 / 5.f, rand() % 10 / 5.f);

	nebulaeSprites[nebulisIndex].setPosition(200+rand() % 1520, -700);
}


void GameState::update(const float& dt) {
	updateSFMLEvents();

	backgroundSprite.move(0, 1.f);
	backgroundSpriteV2.move(0, 1.f);
	nebulaeSprites[nebulisIndex].move(0, 0.5f);
	if (nebulaeSprites[nebulisIndex].getPosition().y > 2000)
		spawnNebulis();


	if (backgroundSprite.getPosition().y > window->getSize().y)
		backgroundSprite.setPosition(0, -1024);

	if (backgroundSpriteV2.getPosition().y > window->getSize().y)
		backgroundSpriteV2.setPosition(0, -1024);


	updateMousePosition();
	
	player->update(dt);
}


void GameState::render() {



	window->draw(backgroundSprite);
	window->draw(backgroundSpriteV2);
	window->draw(nebulaeSprites[nebulisIndex]);



	player->render(window);



	for (auto& enemy : enemies)
		enemy->render(window);

}
