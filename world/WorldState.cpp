//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include <ScriptManager.h>
#include "WorldState.h"
#include "view/WorldView.h"
#include "script_utils/ScreeptUtils.h"

void WorldState::update(int timeDelta) {

}

WorldState::WorldState() {
    viewPtr = std::make_shared<View::WorldView>(*this);
    registerScripts();
}

World &WorldState::getWorld() {
    return world;
}

void WorldState::registerScripts() {
    auto& scriptManager = MEng::ScriptManager::getInstance();
    scriptManager.registerFunction("print", ScriptUtils::print);
}
