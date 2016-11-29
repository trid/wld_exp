//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_TEXTUREMANAGER_H
#define WLD_EXP_TEXTUREMANAGER_H

#include <map>
#include <string>
#include <unordered_map>

#include <sfml/Graphics/Texture.hpp>

#include "../utils/Singleton.h"

namespace MEng {
namespace View {

class TextureManager: public MEng::Utils::Singleton<TextureManager> {
private:
    // Strange behaviour of unordered_map on MinGW-W64 makes me to use default map
    // TODO: Check on different toolset
    std::map<std::string, sf::Texture> textures;
public:
    sf::Texture& getTexture(const std::string& path);
};


}}
#endif //WLD_EXP_TEXTUREMANAGER_H
