//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "Application.h"

void MEng::Application::run() {
    while (true) {
        sf::Time time = clock.restart();

        if (!states.empty()) {
            states.back()->update(time.asMilliseconds());
        }
    }
}

void MEng::Application::pushState(MEng::StatePtr state) {
    states.push_back(state);
}
