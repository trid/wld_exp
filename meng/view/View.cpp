//
// Created by dmitry.khovyakov on 11/28/2016.
//

#include "View.h"
#include "Screen.h"

void MEng::View::View::draw() {
    Screen& screen = Screen::getInstance();

    for (auto& item: sprites) {
        screen.draw(item);
    }
}
