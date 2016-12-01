//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include "WorldState.h"
#include "view/WorldView.h"

void WorldState::update(int timeDelta) {

}

WorldState::WorldState() {
    viewPtr = std::make_shared<View::WorldView>(*this);
}

World &WorldState::getWorld() {
    return world;
}
