//
// Created by dmitry.khovyakov on 12/1/2016.
//

#ifndef WLD_EXP_STATESTORAGE_H
#define WLD_EXP_STATESTORAGE_H

#include <string>
#include <unordered_map>

#include "utils/Singleton.h"
#include "State.h"

namespace Behaviour {

class StateStorage: public MEng::Utils::Singleton<StateStorage> {
private:
    std::unordered_map<std::string, StatePtr> states;
public:
    StateStorage();
    void addState(const std::string& name, StatePtr ptr);
};

}

#endif //WLD_EXP_STATESTORAGE_H
