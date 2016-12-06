//
// Created by dmitry.khovyakov on 12/6/2016.
//

#ifndef WLD_EXP_ACTION_H
#define WLD_EXP_ACTION_H

#include "../Agent.h"

#include <memory>

class World;

namespace Behaviour {

class Action {
public:
    virtual void doAction(Agent &agent, World &world) = 0;
};

using ActionPtr = std::unique_ptr<Action>;

}

#endif //WLD_EXP_ACTION_H
