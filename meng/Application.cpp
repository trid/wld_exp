//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "Application.h"
#include "view/Screen.h"

void MEng::Application::run() {
    while (true) {
        sf::Time time = clock.restart();

        if (!states.empty()) {
            states.back()->update(time.asMilliseconds());
            if (states.back()->hasView()) {
                states.back()->getView().draw();
                View::Screen::getInstance().getRenderWindow().display();
            }
        }
    }
}

void MEng::Application::pushState(MEng::StatePtr state) {
    states.push_back(state);
}
