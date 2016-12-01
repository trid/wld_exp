//
// Created by dmitry.khovyakov on 12/1/2016.
//

#include "StateStorage.h"

void Behaviour::StateStorage::addState(const std::string &name, Behaviour::StatePtr ptr) {
    states[name] = ptr;
}
