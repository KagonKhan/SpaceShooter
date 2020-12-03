#include "GameState.h"

// TODO
/*
	Enemies shoot randomly, not all at once
	Enemy bullets stay on the screen, move bullets vector into the game out of the enemy
	Player bullets get destroyed on hit
	Player HP bar, collision
	Enemy HP bar
	Add more projectile types. Maybe different classes depending on x? Or maybe all in one class?

	 LEARN ABOUT VIEWS


	 //Figure out a better way to position sprites

*/

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {
	initBackground();

	initPlayer();
	initEnemies();

	nebulisIndex = 0;


	view = sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

}

GameState::~GameState() {
	window->close();
	std::cout << "DELETING GAMESTATE\n";
	std::cout << "- deleting player\n";
	delete player;


	std::cout << "- deleting enemy\n";
	for (auto& it : enemies) {
		delete it;
	}
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

	



	backgroundSprite.setTextureRect({ 0, 0, 2000, 1024});
	backgroundSpriteV2.setTextureRect({ 0, 0, 2000, 1024});
	backgroundSpriteV2.setPosition(0, -1 * window->getSize().y);
	backgroundSpriteV2.setColor(sf::Color::White);
}

void GameState::initPlayer() {

	//FIX POSITION LATER
	player = new Player("13B.png","../Resources/art/Example_ships/",
		(sf::Vector2f)window->getSize(), sf::Vector2f(window->getSize().y - 200.f, window->getSize().x /2.f));
}

void GameState::initEnemies() {

	//64 textures, instead of 1 single
	for (int i = 0; i < 64; i++) {
		enemies.push_back(new Enemy("Alien-Scout.png", "../Resources/art/Alien-Ships/",
			100, (sf::Vector2f)window->getSize(),
			sf::Vector2f(120 * (i % 16), 100 * (i / 16)))
		);
	}
}



//Does not throw exceptions
void GameState::checkCollisions() {
	std::vector<Projectile*>& playerProjectiles = *player->getProjectiles();

	for(int i = 0; i < enemies.size(); i++)
		for (int j = 0; j < playerProjectiles.size(); j++) {
			if (enemies[i] && playerProjectiles[j])
			if (enemies[i]->checkHit(playerProjectiles[j]->getBounds())) {
				delete enemies[i];
				enemies.erase(enemies.begin() + i);

				delete playerProjectiles[j];
				playerProjectiles.erase(playerProjectiles.begin() + j);
				break;
			}
		}
}

void GameState::updateBackground() {
	backgroundSprite.move(0, 1.f);
	backgroundSpriteV2.move(0, 1.f);
	nebulaeSprites[nebulisIndex].move(0, 0.5f);

	if (nebulaeSprites[nebulisIndex].getPosition().y > 2000)
		spawnNebulis();


	if (backgroundSprite.getPosition().y > window->getSize().y)
		backgroundSprite.setPosition(0, -1024);

	if (backgroundSpriteV2.getPosition().y > window->getSize().y)
		backgroundSpriteV2.setPosition(0, -1024);
}

void GameState::update(const float& dt) {

	updateSFMLEvents();
	updateBackground();
	updateMousePosition();
	checkCollisions();

	for (auto x : enemies)
		x->update(dt);

	player->update(dt);
}


void GameState::spawnNebulis() {
	srand(time(NULL));
	nebulisIndex = rand() % 3;

	nebulaeSprites[nebulisIndex].setScale(rand() % 10 / 5.f, rand() % 10 / 5.f);

	nebulaeSprites[nebulisIndex].setPosition(200 + rand() % 1520, -700);
}



void GameState::render() {



	window->draw(backgroundSprite);
	window->draw(backgroundSpriteV2);
	window->draw(nebulaeSprites[nebulisIndex]);



	player->render(window);



	for (auto& enemy : enemies)
		enemy->render(window);



	window->setView(view);

}
