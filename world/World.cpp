//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "World.h"

void World::update(int timeDelta) {

}

bool World::doAction(Agent &actor, const std::string &action) {

    return false;
}

World::World() {
    Location forest;
    forest.addActions({"hunt", "cut_wood"});
    locations["forest"] = std::move(forest);
    Location home;
    home.addActions({"eat"});
    locations["home"] = std::move(home);
    Location well;
    well.addActions({"drink"});
    locations["well"] = std::move(well);
}
