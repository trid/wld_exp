//
// Created by dmitry.khovyakov on 11/28/2016.
//

#ifndef WLD_EXP_SCREEN_H
#define WLD_EXP_SCREEN_H

#include <SFML/Graphics.hpp>

#include "../utils/Singleton.h"

namespace MEng {
namespace View {

class Screen: public Utils::Singleton<Screen> {
private:
    sf::RenderWindow window;
public:
    void init(unsigned int width, unsigned int height);
    void draw(sf::Drawable& sprite);
    sf::RenderWindow& getRenderWindow() { return window; }
};

}}

#endif //WLD_EXP_SCREEN_H
