//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "ScriptedState.h"

Behaviour::ScriptedState::ScriptedState(const std::string &tableName) : tableName(tableName) {}

void Behaviour::ScriptedState::act(Agent &agent) {

}

void Behaviour::ScriptedState::start(Agent& agent) {

}

bool Behaviour::ScriptedState::isFinished() {
    return false;
}
