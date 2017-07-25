//
// Created by TriD on 24.05.2015.
//

#include "Screen.h"

#include <iostream>

#include "View.h"
#include "../Application.h"

using std::cout;
using std::endl;

using namespace MEng::View;

Screen::Screen() {

}

void Screen::draw() {
    Application &application = Application::getInstance();
    if (application.hasState()) {
        application.getCurrentState().getView().draw(window);
    }
    window.display();
}

void Screen::close() {
    window.close();
}

void Screen::init(unsigned int width, unsigned int height) {
    window.create(sf::VideoMode(width, height), "meng Window");
}
