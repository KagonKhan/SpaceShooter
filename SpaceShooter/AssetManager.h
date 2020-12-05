#pragma once


class AssetManager {
	std::map <std::string, sf::Texture> m_Textures;
	std::map <std::string, sf::SoundBuffer> m_SoundBuffers;
	std::map <std::string, sf::Font> m_Fonts;


	// Maybe add sf::Music feature? If necessary

	//Asset Manager is a singleton so only this instance is allowed
	//
	static AssetManager* sInstance;


public:
	AssetManager();
	static sf::Texture& GetTexture(const std::string& filename, const std::string& filepath);
	static sf::Font& GetFont(const std::string& filename, const std::string& filepath);
	static sf::SoundBuffer& GetSoundBuffer(const std::string& filename, const std::string& filepath);
};

