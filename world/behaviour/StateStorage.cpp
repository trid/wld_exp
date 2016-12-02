//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "StateStorage.h"

#include <boost/filesystem.hpp>
#include <ScriptManager.h>

using namespace boost::filesystem;

void Behaviour::StateStorage::addState(const std::string &name, Behaviour::StatePtr ptr) {
    states[name] = ptr;
}

Behaviour::StateStorage::StateStorage() {
    auto& scriptManager = MEng::ScriptManager::getInstance();

    path p("res/agents");
    for (directory_entry &x: directory_iterator(p)) {
        scriptManager.loadFile(x.path().string());
    }
}
