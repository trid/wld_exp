//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_TEXTUREMANAGER_H
#define WLD_EXP_TEXTUREMANAGER_H

#include <string>
#include <unordered_map>

#include <sfml/Graphics/Texture.hpp>

#include "../utils/Singleton.h"

namespace MEng {
namespace View {

class TextureManager: public MEng::Utils::Singleton<TextureManager> {
private:
    std::unordered_map<std::string, sf::Texture> textures;
public:
    sf::Texture& getTexture(const std::string& path);
};


}}
#endif //WLD_EXP_TEXTUREMANAGER_H
