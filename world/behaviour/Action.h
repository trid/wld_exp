//
// Created by dmitry.khovyakov on 12/6/2016.
//

#ifndef WLD_EXP_ACTION_H
#define WLD_EXP_ACTION_H

#include "../Agent.h"

namespace Behaviour {

class Action {
public:
    virtual void doAction(Agent& agent) = 0;
};

}

#endif //WLD_EXP_ACTION_H
