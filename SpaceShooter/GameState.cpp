#include "pch.h"

#include "GameState.h"

// ===================================================================  TO DO  ===================================================================
/*
	- DONE - Enemy bullets stay on the screen, move bullets vector into the game out of the enemy? 
	Player HP bar,
	- DONE - Collision 
	Enemy HP bar / OR JUST SHOW DAMAGE - DAMAGE OVERLAY? BURNING?
	Add more projectile types. Maybe different classes depending on x? Or maybe all in one class?
	Add planets, different backgrounds, different galaxies

	Enemies in a list instead of a vector? Compare the performance
	


	//Figure out a better way to position sprites


	Fix sound, listener, attenuation - mostly 3D issues





	Enemies shoot randomly, not all at once - DONE
	Player bullets get destroyed on hit - DONE





	====================================================== TO DO:  CLEAN-UP ==================================================
	Cleanup projectile class - obsolete functions
	Clean up Entity class - is a bit confusing

*/

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states) {
	initBackground();

	initPlayer();
	initEnemies();

	nebulisIndex = 0;


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

// ================================================================  INITIALIZERS  ================================================================

void GameState::initBackground() {
	std::string starsPath = "../Resources/art/Stars-Nebulae/Stars.png";
	std::string nebulis = "../Resources/art/Stars-Nebulae/Nebula";

	for (int i = 0; i < 2; i++) {
		nebulaeSprites[i].setTexture(AssetManager::GetTexture("Nebula" + std::to_string(i+1) + ".png", "../Resources/art/backgrounds/"));
		nebulaeSprites[i].setPosition(0, -700);
	}


	//backgroundTexture.loadFromFile(starsPath);
	//backgroundTexture.setRepeated(true);

	AssetManager::GetTexture("Stars.png", "../Resources/art/backgrounds/").setRepeated(true);
	backgroundSprite.setTexture(AssetManager::GetTexture("Stars.png", "../Resources/art/backgrounds/"));
	backgroundSpriteV2.setTexture(AssetManager::GetTexture("Stars.png", "../Resources/art/backgrounds/"));

	
	backgroundSprite.setTextureRect({ 0, 0, 2000, 1024});
	backgroundSpriteV2.setTextureRect({ 0, 0, 2000, 1024});

	backgroundSpriteV2.setPosition(0.f, static_cast<float>(-1 * window->getSize().y));
	backgroundSpriteV2.setColor(sf::Color::White);
}

void GameState::initPlayer() {

	//FIX POSITION LATER
	player = new Player("13B.png","../Resources/art/Example_ships/",
		(sf::Vector2f)window->getSize(), sf::Vector2f(window->getSize().y - 200.f, window->getSize().x /2.f));
}

void GameState::initEnemies() {

	for (int i = 0; i < 64; i++) {
		enemies.push_back(new Enemy("Alien-Scout.png", "../Resources/art/Alien-Ships/",
			100, (sf::Vector2f)window->getSize(),
			sf::Vector2f(static_cast<float>(50 + 120 * (i % 16)), static_cast<float>(60 + 100 * (i / 16))))
		);
	}
}

void GameState::initPowerUps() {
	powerUps.push_back(new PowerUp(static_cast<sf::Vector2f>(window->getSize()), rand() % 4));

	std::cout << powerUps.back()->getUpgradeType() << std::endl;
}

// ==================================================================  UPDATES  ==================================================================


void GameState::update(const float& dt) {

	updateSFMLEvents();
	updateMousePosition();

	updateBackground();
	updatePlayer(dt);
	updateEnemies(dt);
	updateLogic(dt);
	updatePowerUps(dt);

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

void GameState::updatePlayer(const float& dt) {
	player->update(dt);
}

void GameState::updateEnemies(const float& dt) {

	for (auto& x : enemies)
		x->update(dt);

	for (auto& x : enemiesForDeletion)
		x->update(dt);


	updateEnemiesForDeletion(dt);
}

// Enemies live untill the projectiles disappear, as i dont want to have projectile vectors in gamestate
// Might not be a good idea, will research later.
void GameState::updateEnemiesForDeletion(const float& dt) {

	for (unsigned int i = 0; i < enemiesForDeletion.size(); i++)
		if (enemiesForDeletion[i]->areThereProjectilesOnScreen() == false) {

			delete enemiesForDeletion[i];
			enemiesForDeletion.erase(enemiesForDeletion.begin() + i);
		}		
	
}

void GameState::spawnNewEnemies() {
	if(enemies.empty())
		initEnemies();
	
}

void GameState::updateLogic(const float& dt) {
	checkCollisions();

	spawnNewEnemies();

	spawnNewEnemies();
}

void GameState::updatePowerUps(const float& dt) {
	if (rand() % 200 == rand() % 200) {
		initPowerUps();

	}
	for (auto& x : powerUps)
		x->update(dt);
}

// ==================================================================  RENDERS  ==================================================================


void GameState::render() {
	renderBackgrounds();
	renderPlayer();
	renderEnemies();
	renderPowerUps();
}



void GameState::renderBackgrounds() {
	window->draw(backgroundSprite);
	window->draw(backgroundSpriteV2);
	window->draw(nebulaeSprites[nebulisIndex]);
}

void GameState::renderPlayer() {
	player->render(window);
}

void GameState::renderEnemies() {
	for (auto& enemy : enemies)
		enemy->render(window);

	for (auto& enemy : enemiesForDeletion)
		enemy->render(window);
}

void GameState::renderPowerUps() {
	for (auto& x : powerUps)
		x->render(window);
}


// ===================================================================  LOGIC  ===================================================================


// Try to find a cleaner solution
void GameState::spawnNebulis() {
	srand(static_cast<long int>(time(NULL)));
	nebulisIndex = rand() % 3;

	nebulaeSprites[nebulisIndex].setScale(rand() % 10 / 5.f, rand() % 10 / 5.f);

	nebulaeSprites[nebulisIndex].setPosition(200.f + static_cast<float>(rand() % 1520), -700.f);
}

//Does not throw exceptions
// find a way to check player collisions
void GameState::checkCollisions() {

	//CHANGE CHECKHIT TO CHECK COLLISSION
	checkPlayerCollisions();
	checkEnemyCollisions();
	checkPowerUpsCollisions();

}

void GameState::checkPlayerCollisions() {

	//CHECKING FOR PLAYER COLLISION
	for (unsigned int i = 0; i < enemies.size(); i++) {

		std::vector<Projectile*>& enemyProjectiles = *enemies[i]->getProjectiles();
		for (unsigned int j = 0; j < enemyProjectiles.size(); j++) {

			if (player->checkHit(*enemyProjectiles[j])) {
				std::cout << "Player hit\n";

				delete enemyProjectiles[j];
				enemyProjectiles.erase(enemyProjectiles.begin() + j);
				break;
			}
		}
	}

}

void GameState::checkEnemyCollisions() {
	std::vector<Projectile*>& playerProjectiles = *player->getProjectiles();
	std::vector<Beam>& playerBeams = *player->getBeams();


	//CHECKING FOR ENEMY COLLISION
	for (unsigned int i = 0; i < enemies.size(); i++) {
		for (unsigned int j = 0; j < playerProjectiles.size(); j++) {
			if (enemies[i] && playerProjectiles[j])
				if (enemies[i]->checkHit(*playerProjectiles[j])) {

					if (enemies[i]->getHP() <= 0) {
						enemiesForDeletion.push_back(enemies[i]);


						//ENEMIES ERASE CAUSES PROJECTILES TO DISAPPEAR
						enemies[i]->setPosition(sf::Vector2f(-9999, -99999.f));
						enemies.erase(enemies.begin() + i);
					}

					delete playerProjectiles[j];
					playerProjectiles.erase(playerProjectiles.begin() + j);
					break;
				}
		}
	}


	// BEAM DAMAGE
	for (unsigned int j = 0; j < playerBeams.size(); j++) {
		if (!playerBeams[j].getIsDone()) {
			for (unsigned int i = 0; i < enemies.size(); i++) {
				if (enemies[i]->checkHit(playerBeams[j])) {


					if (enemies[i]->getHP() <= 0) {
						enemiesForDeletion.push_back(enemies[i]);


						//ENEMIES ERASE CAUSES PROJECTILES TO DISAPPEAR
						enemies[i]->setPosition(sf::Vector2f(-9999, -99999.f));
						enemies.erase(enemies.begin() + i);
					}

				}

			}
		}
		else
			playerBeams[j].resetTimer();
	}

}

void GameState::checkPowerUpsCollisions() {

	//CHECKING FOR POWERUPS COLLISION
	for (int i = 0; i < powerUps.size(); i++)
		if (player->checkHit(powerUps[i]->getBounds())) {

			player->receiveUpgrade(powerUps[i]->getUpgradeType());
			delete powerUps[i];
			powerUps.erase(powerUps.begin() + i);
		}


}

