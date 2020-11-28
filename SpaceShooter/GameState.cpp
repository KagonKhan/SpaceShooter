#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {
	initBackground();

	initPlayer();
	initEnemies();


	backgroundTime = 0.f;

	bgIndex = 0;
}

void GameState::initBackground() {
	std::string path = "../Resources/art/Stars-Nebulae/Stars.png";

	backgroundTexture.loadFromFile(path);
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


void GameState::update(const float& dt) {
	updateSFMLEvents();

	backgroundSprite.move(0, 1.f);
	backgroundSpriteV2.move(0, 1.f);

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
	player->render(window);


	for (auto& enemy : enemies)
		enemy->render(window);

}
