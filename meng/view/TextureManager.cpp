//
// Created by dmitry.khovyakov on 11/28/2016.
//

#include "TextureManager.h"

sf::Texture &MEng::View::TextureManager::getTexture(const std::string &path) {
    textures.emplace_back();
    textures.back().loadFromFile(path);
    return textures.back();
}
