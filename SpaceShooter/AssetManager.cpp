#include "AssetManager.h"
#include <assert.h>

//doesnt change much, just a practice
AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager() {

    //if false, aborts = aborts if instances > 1
    assert(sInstance == nullptr);
        sInstance = this;
}

//Returns a texture reference if filename found. If not, load file(filepath + filename)
sf::Texture& AssetManager::GetTexture(const std::string& filename, const std::string& filepath) {

    auto& textureMap = sInstance->m_Textures;

    auto pairFound = textureMap.find(filename);
    // found a texture
    if (pairFound != textureMap.end())
        return pairFound->second;
    else {
        auto& texture = textureMap[filename];
        textureMap[filename].loadFromFile(filepath + filename);
        return texture;
    }
}
