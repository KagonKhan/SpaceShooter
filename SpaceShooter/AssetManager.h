#pragma once

#include <map>
#include "SFML/Graphics.hpp"


class AssetManager {
	std::map <std::string, sf::Texture> m_Textures;


	//Asset Manager is a singleton so only this instance is allowed
	//
	static AssetManager* sInstance;


public:
	AssetManager();
	static sf::Texture& GetTexture(const std::string& filename, const std::string& filepath);
};

