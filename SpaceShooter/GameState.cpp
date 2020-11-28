#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {
	initBackground();

	initPlayer();

	backgroundTime = 0.f;

	bgIndex = 0;
}

void GameState::initBackground() {
	std::string path = "../Resources/background/space";

	sf::Vector2f scale = (sf::Vector2f)window->getSize() / 200.f;

	for (int i = 0; i < 6; i++) {
		backgroundTextures[i].loadFromFile(path + std::to_string(i) + ".png");
		backgroundSprites[i].setTexture(backgroundTextures[i]);
		backgroundSprites[i].setScale(scale);
	}
}

void GameState::initPlayer() {
	player = new Player("../Resources/sprites/playerSprite.png", window->getSize());
}


void GameState::update(const float& dt) {
	updateSFMLEvents();

	updateMousePosition();
	
	updateBackground(dt);

	player->update(dt);
}

void GameState::updateBackground(const float& dt) {
	backgroundTime += dt;

	std::cout << 1 / dt << "\n";

	//change every second
	if (backgroundTime >1.f) {

		bgIndex >= 5 ? bgIndex = 0 : bgIndex++;
		backgroundTime = 0.f;
	}
}

void GameState::render() {
	window->draw(backgroundSprites[bgIndex]);
	player->render(window);
}
