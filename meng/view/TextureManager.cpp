//
// Created by dmitry.khovyakov on 11/28/2016.
//

#include <iostream>

#include "TextureManager.h"

sf::Texture &MEng::View::TextureManager::getTexture(const std::string &path) {
    if (textures.find(path) == textures.end()) {
        sf::Texture texture;
        texture.loadFromFile(path);
        textures[path] = texture;
    }

    return textures[path];
}
