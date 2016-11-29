//
// Created by dmitry.khovyakov on 11/28/2016.
//

#include "TextureManager.h"

sf::Texture &MEng::View::TextureManager::getTexture(const std::string &path) {
    if (textures.find(path) == textures.end()) {
        textures.insert(std::make_pair(path, sf::Texture()));
        textures[path].loadFromFile(path);
    }

    return textures[path];
}
