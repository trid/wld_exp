//
// Created by dmitry.khovyakov on 11/28/2016.
//

#include "Screen.h"

using namespace MEng::View;

void Screen::init(unsigned int width, unsigned int height) {
    window.create(sf::VideoMode(width, height), "MEng Window");
}

void Screen::draw(sf::Drawable &sprite) {
    window.draw(sprite);
}
