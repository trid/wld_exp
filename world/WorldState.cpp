//
// Created by dmitry.khovyakov on 11/25/2016.
//

#include <ScriptManager.h>
#include "WorldState.h"
#include "view/WorldView.h"
#include "script_utils/ScriptUtils.h"

class WorldProcess: public MEng::StateProcess {
    World& world;
public:
    explicit WorldProcess(World& world) : world(world) {}

    void update(int delta) override {
        world.update(delta);
    }

    bool isFinished() override {
        return false;
    }

    void stop() override {

    }

    void save(std::ofstream& out) override {

    }

    void load(std::ifstream& in) override {

    }
};


WorldState::WorldState() {
    setView(std::make_shared<View::WorldView>(*this));

    MEng::StateProcess::ProcessPtr worldProcess = std::make_shared<WorldProcess>(world);
    addProcess(worldProcess);

    registerScripts();
}

World &WorldState::getWorld() {
    return world;
}

void WorldState::registerScripts() {
    auto& scriptManager = MEng::ScriptManager::getInstance();
    scriptManager.registerFunction("print", ScriptUtils::print);
}
