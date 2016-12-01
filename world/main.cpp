//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "../meng/Application.h"
#include "WorldState.h"
#include "../meng/view/Screen.h"

int main(int argc, char* argv[]) {
    MEng::Application& app = MEng::Application::getInstance();

    MEng::View::Screen::getInstance().init(1024, 768);

    app.pushState(std::make_shared<WorldState>());
    app.run();
}